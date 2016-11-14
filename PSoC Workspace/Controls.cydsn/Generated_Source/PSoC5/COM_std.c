/***************************************************************************//**
* \file COM_std.c
* \version 3.0
*
* \brief
*  This file contains the USB Standard request handler.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_pvt.h"

/***************************************
*   Static data allocation
***************************************/

#if defined(COM_ENABLE_FWSN_STRING)
    static volatile uint8* COM_fwSerialNumberStringDescriptor;
    static volatile uint8  COM_snStringConfirm = COM_FALSE;
#endif  /* (COM_ENABLE_FWSN_STRING) */

#if defined(COM_ENABLE_FWSN_STRING)
    /***************************************************************************
    * Function Name: COM_SerialNumString
    ************************************************************************//**
    *
    *  This function is available only when the User Call Back option in the 
    *  Serial Number String descriptor properties is selected. Application 
    *  firmware can provide the source of the USB device serial number string 
    *  descriptor during run time. The default string is used if the application 
    *  firmware does not use this function or sets the wrong string descriptor.
    *
    *  \param snString:  Pointer to the user-defined string descriptor. The 
    *  string descriptor should meet the Universal Serial Bus Specification 
    *  revision 2.0 chapter 9.6.7
    *  Offset|Size|Value|Description
    *  ------|----|------|---------------------------------
    *  0     |1   |N     |Size of this descriptor in bytes
    *  1     |1   |0x03  |STRING Descriptor Type
    *  2     |N-2 |Number|UNICODE encoded string
    *  
    * *For example:* uint8 snString[16]={0x0E,0x03,'F',0,'W',0,'S',0,'N',0,'0',0,'1',0};
    *
    * \reentrant
    *  No.
    *
    ***************************************************************************/
    void  COM_SerialNumString(uint8 snString[]) 
    {
        COM_snStringConfirm = COM_FALSE;
        
        if (snString != NULL)
        {
            /* Check descriptor validation */
            if ((snString[0u] > 1u) && (snString[1u] == COM_DESCR_STRING))
            {
                COM_fwSerialNumberStringDescriptor = snString;
                COM_snStringConfirm = COM_TRUE;
            }
        }
    }
#endif  /* COM_ENABLE_FWSN_STRING */


/*******************************************************************************
* Function Name: COM_HandleStandardRqst
****************************************************************************//**
*
*  This Routine dispatches standard requests
*
*
* \return
*  TRUE if request handled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_HandleStandardRqst(void) 
{
    uint8 requestHandled = COM_FALSE;
    uint8 interfaceNumber;
    uint8 configurationN;
    uint8 bmRequestType = COM_bmRequestTypeReg;

#if defined(COM_ENABLE_STRINGS)
    volatile uint8 *pStr = 0u;
    #if defined(COM_ENABLE_DESCRIPTOR_STRINGS)
        uint8 nStr;
        uint8 descrLength;
    #endif /* (COM_ENABLE_DESCRIPTOR_STRINGS) */
#endif /* (COM_ENABLE_STRINGS) */
    
    static volatile uint8 COM_tBuffer[COM_STATUS_LENGTH_MAX];
    const T_COM_LUT CYCODE *pTmp;

    COM_currentTD.count = 0u;

    if (COM_RQST_DIR_D2H == (bmRequestType & COM_RQST_DIR_MASK))
    {
        /* Control Read */
        switch (COM_bRequestReg)
        {
            case COM_GET_DESCRIPTOR:
                if (COM_DESCR_DEVICE ==COM_wValueHiReg)
                {
                    pTmp = COM_GetDeviceTablePtr();
                    COM_currentTD.pData = (volatile uint8 *)pTmp->p_list;
                    COM_currentTD.count = COM_DEVICE_DESCR_LENGTH;
                    
                    requestHandled  = COM_InitControlRead();
                }
                else if (COM_DESCR_CONFIG == COM_wValueHiReg)
                {
                    pTmp = COM_GetConfigTablePtr((uint8) COM_wValueLoReg);
                    
                    /* Verify that requested descriptor exists */
                    if (pTmp != NULL)
                    {
                        COM_currentTD.pData = (volatile uint8 *)pTmp->p_list;
                        COM_currentTD.count = (uint16)((uint16)(COM_currentTD.pData)[COM_CONFIG_DESCR_TOTAL_LENGTH_HI] << 8u) | \
                                                                            (COM_currentTD.pData)[COM_CONFIG_DESCR_TOTAL_LENGTH_LOW];
                        requestHandled  = COM_InitControlRead();
                    }
                }
                
            #if(COM_BOS_ENABLE)
                else if (COM_DESCR_BOS == COM_wValueHiReg)
                {
                    pTmp = COM_GetBOSPtr();
                    
                    /* Verify that requested descriptor exists */
                    if (pTmp != NULL)
                    {
                        COM_currentTD.pData = (volatile uint8 *)pTmp;
                        COM_currentTD.count = ((uint16)((uint16)(COM_currentTD.pData)[COM_BOS_DESCR_TOTAL_LENGTH_HI] << 8u)) | \
                                                                             (COM_currentTD.pData)[COM_BOS_DESCR_TOTAL_LENGTH_LOW];
                        requestHandled  = COM_InitControlRead();
                    }
                }
            #endif /*(COM_BOS_ENABLE)*/
            
            #if defined(COM_ENABLE_STRINGS)
                else if (COM_DESCR_STRING == COM_wValueHiReg)
                {
                /* Descriptor Strings */
                #if defined(COM_ENABLE_DESCRIPTOR_STRINGS)
                    nStr = 0u;
                    pStr = (volatile uint8 *) &COM_STRING_DESCRIPTORS[0u];
                    
                    while ((COM_wValueLoReg > nStr) && (*pStr != 0u))
                    {
                        /* Read descriptor length from 1st byte */
                        descrLength = *pStr;
                        /* Move to next string descriptor */
                        pStr = &pStr[descrLength];
                        nStr++;
                    }
                #endif /* (COM_ENABLE_DESCRIPTOR_STRINGS) */
                
                /* Microsoft OS String */
                #if defined(COM_ENABLE_MSOS_STRING)
                    if (COM_STRING_MSOS == COM_wValueLoReg)
                    {
                        pStr = (volatile uint8 *)& COM_MSOS_DESCRIPTOR[0u];
                    }
                #endif /* (COM_ENABLE_MSOS_STRING) */
                
                /* SN string */
                #if defined(COM_ENABLE_SN_STRING)
                    if ((COM_wValueLoReg != 0u) && 
                        (COM_wValueLoReg == COM_DEVICE0_DESCR[COM_DEVICE_DESCR_SN_SHIFT]))
                    {
                    #if defined(COM_ENABLE_IDSN_STRING)
                        /* Read DIE ID and generate string descriptor in RAM */
                        COM_ReadDieID(COM_idSerialNumberStringDescriptor);
                        pStr = COM_idSerialNumberStringDescriptor;
                    #elif defined(COM_ENABLE_FWSN_STRING)
                        
                        if(COM_snStringConfirm != COM_FALSE)
                        {
                            pStr = COM_fwSerialNumberStringDescriptor;
                        }
                        else
                        {
                            pStr = (volatile uint8 *)&COM_SN_STRING_DESCRIPTOR[0u];
                        }
                    #else
                        pStr = (volatile uint8 *)&COM_SN_STRING_DESCRIPTOR[0u];
                    #endif  /* (COM_ENABLE_IDSN_STRING) */
                    }
                #endif /* (COM_ENABLE_SN_STRING) */
                
                    if (*pStr != 0u)
                    {
                        COM_currentTD.count = *pStr;
                        COM_currentTD.pData = pStr;
                        requestHandled  = COM_InitControlRead();
                    }
                }
            #endif /*  COM_ENABLE_STRINGS */
                else
                {
                    requestHandled = COM_DispatchClassRqst();
                }
                break;
                
            case COM_GET_STATUS:
                switch (bmRequestType & COM_RQST_RCPT_MASK)
                {
                    case COM_RQST_RCPT_EP:
                        COM_currentTD.count = COM_EP_STATUS_LENGTH;
                        COM_tBuffer[0u]     = COM_EP[COM_wIndexLoReg & COM_DIR_UNUSED].hwEpState;
                        COM_tBuffer[1u]     = 0u;
                        COM_currentTD.pData = &COM_tBuffer[0u];
                        
                        requestHandled  = COM_InitControlRead();
                        break;
                    case COM_RQST_RCPT_DEV:
                        COM_currentTD.count = COM_DEVICE_STATUS_LENGTH;
                        COM_tBuffer[0u]     = COM_deviceStatus;
                        COM_tBuffer[1u]     = 0u;
                        COM_currentTD.pData = &COM_tBuffer[0u];
                        
                        requestHandled  = COM_InitControlRead();
                        break;
                    default:    /* requestHandled is initialized as FALSE by default */
                        break;
                }
                break;
                
            case COM_GET_CONFIGURATION:
                COM_currentTD.count = 1u;
                COM_currentTD.pData = (volatile uint8 *) &COM_configuration;
                requestHandled  = COM_InitControlRead();
                break;
                
            case COM_GET_INTERFACE:
                COM_currentTD.count = 1u;
                COM_currentTD.pData = (volatile uint8 *) &COM_interfaceSetting[COM_wIndexLoReg];
                requestHandled  = COM_InitControlRead();
                break;
                
            default: /* requestHandled is initialized as FALSE by default */
                break;
        }
    }
    else
    {
        /* Control Write */
        switch (COM_bRequestReg)
        {
            case COM_SET_ADDRESS:
                /* Store address to be set in COM_NoDataControlStatusStage(). */
                COM_deviceAddress = (uint8) COM_wValueLoReg;
                requestHandled = COM_InitNoDataControlTransfer();
                break;
                
            case COM_SET_CONFIGURATION:
                configurationN = COM_wValueLoReg;
                
                /* Verify that configuration descriptor exists */
                if(configurationN > 0u)
                {
                    pTmp = COM_GetConfigTablePtr((uint8) configurationN - 1u);
                }
                
                /* Responds with a Request Error when configuration number is invalid */
                if (((configurationN > 0u) && (pTmp != NULL)) || (configurationN == 0u))
                {
                    /* Set new configuration if it has been changed */
                    if(configurationN != COM_configuration)
                    {
                        COM_configuration = (uint8) configurationN;
                        COM_configurationChanged = COM_TRUE;
                        COM_Config(COM_TRUE);
                    }
                    requestHandled = COM_InitNoDataControlTransfer();
                }
                break;
                
            case COM_SET_INTERFACE:
                if (0u != COM_ValidateAlternateSetting())
                {
                    /* Get interface number from the request. */
                    interfaceNumber = COM_wIndexLoReg;
                    COM_interfaceNumber = (uint8) COM_wIndexLoReg;
                     
                    /* Check if alternate settings is changed for interface. */
                    if (COM_interfaceSettingLast[interfaceNumber] != COM_interfaceSetting[interfaceNumber])
                    {
                        COM_configurationChanged = COM_TRUE;
                    
                        /* Change alternate setting for the endpoints. */
                    #if (COM_EP_MANAGEMENT_MANUAL && COM_EP_ALLOC_DYNAMIC)
                        COM_Config(COM_FALSE);
                    #else
                        COM_ConfigAltChanged();
                    #endif /* (COM_EP_MANAGEMENT_MANUAL && COM_EP_ALLOC_DYNAMIC) */
                    }
                    
                    requestHandled = COM_InitNoDataControlTransfer();
                }
                break;
                
            case COM_CLEAR_FEATURE:
                switch (bmRequestType & COM_RQST_RCPT_MASK)
                {
                    case COM_RQST_RCPT_EP:
                        if (COM_wValueLoReg == COM_ENDPOINT_HALT)
                        {
                            requestHandled = COM_ClearEndpointHalt();
                        }
                        break;
                    case COM_RQST_RCPT_DEV:
                        /* Clear device REMOTE_WAKEUP */
                        if (COM_wValueLoReg == COM_DEVICE_REMOTE_WAKEUP)
                        {
                            COM_deviceStatus &= (uint8)~COM_DEVICE_STATUS_REMOTE_WAKEUP;
                            requestHandled = COM_InitNoDataControlTransfer();
                        }
                        break;
                    case COM_RQST_RCPT_IFC:
                        /* Validate interfaceNumber */
                        if (COM_wIndexLoReg < COM_MAX_INTERFACES_NUMBER)
                        {
                            COM_interfaceStatus[COM_wIndexLoReg] &= (uint8) ~COM_wValueLoReg;
                            requestHandled = COM_InitNoDataControlTransfer();
                        }
                        break;
                    default:    /* requestHandled is initialized as FALSE by default */
                        break;
                }
                break;
                
            case COM_SET_FEATURE:
                switch (bmRequestType & COM_RQST_RCPT_MASK)
                {
                    case COM_RQST_RCPT_EP:
                        if (COM_wValueLoReg == COM_ENDPOINT_HALT)
                        {
                            requestHandled = COM_SetEndpointHalt();
                        }
                        break;
                        
                    case COM_RQST_RCPT_DEV:
                        /* Set device REMOTE_WAKEUP */
                        if (COM_wValueLoReg == COM_DEVICE_REMOTE_WAKEUP)
                        {
                            COM_deviceStatus |= COM_DEVICE_STATUS_REMOTE_WAKEUP;
                            requestHandled = COM_InitNoDataControlTransfer();
                        }
                        break;
                        
                    case COM_RQST_RCPT_IFC:
                        /* Validate interfaceNumber */
                        if (COM_wIndexLoReg < COM_MAX_INTERFACES_NUMBER)
                        {
                            COM_interfaceStatus[COM_wIndexLoReg] &= (uint8) ~COM_wValueLoReg;
                            requestHandled = COM_InitNoDataControlTransfer();
                        }
                        break;
                    
                    default:    /* requestHandled is initialized as FALSE by default */
                        break;
                }
                break;
                
            default:    /* requestHandled is initialized as FALSE by default */
                break;
        }
    }
    
    return (requestHandled);
}


#if defined(COM_ENABLE_IDSN_STRING)
    /***************************************************************************
    * Function Name: COM_ReadDieID
    ************************************************************************//**
    *
    *  This routine read Die ID and generate Serial Number string descriptor.
    *
    *  \param descr:  pointer on string descriptor. This string size has to be equal or
    *          greater than COM_IDSN_DESCR_LENGTH.
    *
    *
    * \reentrant
    *  No.
    *
    ***************************************************************************/
    void COM_ReadDieID(uint8 descr[]) 
    {
        const char8 CYCODE hex[] = "0123456789ABCDEF";
        uint8 i;
        uint8 j = 0u;
        uint8 uniqueId[8u];

        if (NULL != descr)
        {
            /* Initialize descriptor header. */
            descr[0u] = COM_IDSN_DESCR_LENGTH;
            descr[1u] = COM_DESCR_STRING;
            
            /* Unique ID size is 8 bytes. */
            CyGetUniqueId((uint32 *) uniqueId);

            /* Fill descriptor with unique device ID. */
            for (i = 2u; i < COM_IDSN_DESCR_LENGTH; i += 4u)
            {
                descr[i]      = (uint8) hex[(uniqueId[j] >> 4u)];
                descr[i + 1u] = 0u;
                descr[i + 2u] = (uint8) hex[(uniqueId[j] & 0x0Fu)];
                descr[i + 3u] = 0u;
                ++j;
            }
        }
    }
#endif /* (COM_ENABLE_IDSN_STRING) */


/*******************************************************************************
* Function Name: COM_ConfigReg
****************************************************************************//**
*
*  This routine configures hardware registers from the variables.
*  It is called from COM_Config() function and from RestoreConfig
*  after Wakeup.
*
*******************************************************************************/
void COM_ConfigReg(void) 
{
    uint8 ep;

#if (COM_EP_MANAGEMENT_DMA_AUTO)
    uint8 epType = 0u;
#endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */

    /* Go thought all endpoints and set hardware configuration */
    for (ep = COM_EP1; ep < COM_MAX_EP; ++ep)
    {
        COM_ARB_EP_BASE.arbEp[ep].epCfg = COM_ARB_EPX_CFG_DEFAULT;
        
    #if (COM_EP_MANAGEMENT_DMA)
        /* Enable arbiter endpoint interrupt sources */
        COM_ARB_EP_BASE.arbEp[ep].epIntEn = COM_ARB_EPX_INT_MASK;
    #endif /* (COM_EP_MANAGEMENT_DMA) */
    
        if (COM_EP[ep].epMode != COM_MODE_DISABLE)
        {
            if (0u != (COM_EP[ep].addr & COM_DIR_IN))
            {
                COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_MODE_NAK_IN;
                
            #if (COM_EP_MANAGEMENT_DMA_AUTO && CY_PSOC4)
                /* Clear DMA_TERMIN for IN endpoint. */
                COM_ARB_EP_BASE.arbEp[ep].epIntEn &= (uint32) ~COM_ARB_EPX_INT_DMA_TERMIN;
            #endif /* (COM_EP_MANAGEMENT_DMA_AUTO && CY_PSOC4) */
            }
            else
            {
                COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_MODE_NAK_OUT;

            #if (COM_EP_MANAGEMENT_DMA_AUTO)
                /* (CY_PSOC4): DMA_TERMIN for OUT endpoint is set above. */
                
                /* Prepare endpoint type mask. */
                epType |= (uint8) (0x01u << (ep - COM_EP1));
            #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
            }
        }
        else
        {
            COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_MODE_STALL_DATA_EP;
        }
        
    #if (!COM_EP_MANAGEMENT_DMA_AUTO)
        #if (CY_PSOC4)
            COM_ARB_EP16_BASE.arbEp[ep].rwRa16  = (uint32) COM_EP[ep].buffOffset;
            COM_ARB_EP16_BASE.arbEp[ep].rwWa16  = (uint32) COM_EP[ep].buffOffset;
        #else
            COM_ARB_EP_BASE.arbEp[ep].rwRa    = LO8(COM_EP[ep].buffOffset);
            COM_ARB_EP_BASE.arbEp[ep].rwRaMsb = HI8(COM_EP[ep].buffOffset);
            COM_ARB_EP_BASE.arbEp[ep].rwWa    = LO8(COM_EP[ep].buffOffset);
            COM_ARB_EP_BASE.arbEp[ep].rwWaMsb = HI8(COM_EP[ep].buffOffset);
        #endif /* (CY_PSOC4) */
    #endif /* (!COM_EP_MANAGEMENT_DMA_AUTO) */
    }

#if (COM_EP_MANAGEMENT_DMA_AUTO)
     /* BUF_SIZE depend on DMA_THRESS value:0x55-32 bytes  0x44-16 bytes 0x33-8 bytes 0x22-4 bytes 0x11-2 bytes */
    COM_BUF_SIZE_REG = COM_DMA_BUF_SIZE;

    /* Configure DMA burst threshold */
#if (CY_PSOC4)
    COM_DMA_THRES16_REG   = COM_DMA_BYTES_PER_BURST;
#else
    COM_DMA_THRES_REG     = COM_DMA_BYTES_PER_BURST;
    COM_DMA_THRES_MSB_REG = 0u;
#endif /* (CY_PSOC4) */
    COM_EP_ACTIVE_REG = COM_DEFAULT_ARB_INT_EN;
    COM_EP_TYPE_REG   = epType;
    
    /* Cfg_cmp bit set to 1 once configuration is complete. */
    /* Lock arbiter configtuation */
    COM_ARB_CFG_REG |= (uint8)  COM_ARB_CFG_CFG_CMP;
    /* Cfg_cmp bit set to 0 during configuration of PFSUSB Registers. */
    COM_ARB_CFG_REG &= (uint8) ~COM_ARB_CFG_CFG_CMP;

#endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */

    /* Enable interrupt SIE interurpt source from EP0-EP1 */
    COM_SIE_EP_INT_EN_REG = (uint8) COM_DEFAULT_SIE_EP_INT_EN;
}


/*******************************************************************************
* Function Name: COM_EpStateInit
****************************************************************************//**
*
*  This routine initialize state of Data end points based of its type: 
*   IN  - COM_IN_BUFFER_EMPTY (COM_EVENT_PENDING)
*   OUT - COM_OUT_BUFFER_EMPTY (COM_NO_EVENT_PENDING)
*
*******************************************************************************/
void COM_EpStateInit(void) 
{
    uint8 i;

    for (i = COM_EP1; i < COM_MAX_EP; i++)
    { 
        if (0u != (COM_EP[i].addr & COM_DIR_IN))
        {
            /* IN Endpoint */
            COM_EP[i].apiEpState = COM_EVENT_PENDING;
        }
        else
        {
            /* OUT Endpoint */
            COM_EP[i].apiEpState = COM_NO_EVENT_PENDING;
        }
    }
                    
}


/*******************************************************************************
* Function Name: COM_Config
****************************************************************************//**
*
*  This routine configures endpoints for the entire configuration by scanning
*  the configuration descriptor.
*
*  \param clearAltSetting: It configures the bAlternateSetting 0 for each interface.
*
* COM_interfaceClass - Initialized class array for each interface.
*   It is used for handling Class specific requests depend on interface class.
*   Different classes in multiple Alternate settings does not supported.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_Config(uint8 clearAltSetting) 
{
    uint8 ep;
    uint8 curEp;
    uint8 i;
    uint8 epType;
    const uint8 *pDescr;
    
    #if (!COM_EP_MANAGEMENT_DMA_AUTO)
        uint16 buffCount = 0u;
    #endif /* (!COM_EP_MANAGEMENT_DMA_AUTO) */

    const T_COM_LUT CYCODE *pTmp;
    const T_COM_EP_SETTINGS_BLOCK CYCODE *pEP;

    /* Clear endpoints settings */
    for (ep = 0u; ep < COM_MAX_EP; ++ep)
    {
        COM_EP[ep].attrib     = 0u;
        COM_EP[ep].hwEpState  = 0u;
        COM_EP[ep].epToggle   = 0u;
        COM_EP[ep].bufferSize = 0u;
        COM_EP[ep].interface  = 0u;
        COM_EP[ep].apiEpState = COM_NO_EVENT_PENDING;
        COM_EP[ep].epMode     = COM_MODE_DISABLE;   
    }

    /* Clear Alternate settings for all interfaces. */
    if (0u != clearAltSetting)
    {
        for (i = 0u; i < COM_MAX_INTERFACES_NUMBER; ++i)
        {
            COM_interfaceSetting[i]     = 0u;
            COM_interfaceSettingLast[i] = 0u;
        }
    }

    /* Init Endpoints and Device Status if configured */
    if (COM_configuration > 0u)
    {
        #if defined(COM_ENABLE_CDC_CLASS)
            uint8 cdcComNums = 0u;
        #endif  /* (COM_ENABLE_CDC_CLASS) */  

        pTmp = COM_GetConfigTablePtr(COM_configuration - 1u);
        
        /* Set Power status for current configuration */
        pDescr = (const uint8 *)pTmp->p_list;
        if ((pDescr[COM_CONFIG_DESCR_ATTRIB] & COM_CONFIG_DESCR_ATTRIB_SELF_POWERED) != 0u)
        {
            COM_deviceStatus |= (uint8)  COM_DEVICE_STATUS_SELF_POWERED;
        }
        else
        {
            COM_deviceStatus &= (uint8) ~COM_DEVICE_STATUS_SELF_POWERED;
        }
        
        /* Move to next element */
        pTmp = &pTmp[1u];
        ep = pTmp->c;  /* For this table, c is the number of endpoints configurations  */

        #if (COM_EP_MANAGEMENT_MANUAL && COM_EP_ALLOC_DYNAMIC)
            /* Configure for dynamic EP memory allocation */
            /* p_list points the endpoint setting table. */
            pEP = (T_COM_EP_SETTINGS_BLOCK *) pTmp->p_list;
            
            for (i = 0u; i < ep; i++)
            {     
                /* Compare current Alternate setting with EP Alt */
                if (COM_interfaceSetting[pEP->interface] == pEP->altSetting)
                {                                                          
                    curEp  = pEP->addr & COM_DIR_UNUSED;
                    epType = pEP->attributes & COM_EP_TYPE_MASK;
                    
                    COM_EP[curEp].addr       = pEP->addr;
                    COM_EP[curEp].attrib     = pEP->attributes;
                    COM_EP[curEp].bufferSize = pEP->bufferSize;

                    if (0u != (pEP->addr & COM_DIR_IN))
                    {
                        /* IN Endpoint */
                        COM_EP[curEp].epMode     = COM_GET_ACTIVE_IN_EP_CR0_MODE(epType);
                        COM_EP[curEp].apiEpState = COM_EVENT_PENDING;
                    
                    #if (defined(COM_ENABLE_MIDI_STREAMING) && (COM_MIDI_IN_BUFF_SIZE > 0))
                        if ((pEP->bMisc == COM_CLASS_AUDIO) && (epType == COM_EP_TYPE_BULK))
                        {
                            COM_midi_in_ep = curEp;
                        }
                    #endif  /* (COM_ENABLE_MIDI_STREAMING) */
                    }
                    else
                    {
                        /* OUT Endpoint */
                        COM_EP[curEp].epMode     = COM_GET_ACTIVE_OUT_EP_CR0_MODE(epType);
                        COM_EP[curEp].apiEpState = COM_NO_EVENT_PENDING;
                        
                    #if (defined(COM_ENABLE_MIDI_STREAMING) && (COM_MIDI_OUT_BUFF_SIZE > 0))
                        if ((pEP->bMisc == COM_CLASS_AUDIO) && (epType == COM_EP_TYPE_BULK))
                        {
                            COM_midi_out_ep = curEp;
                        }
                    #endif  /* (COM_ENABLE_MIDI_STREAMING) */
                    }

                #if(defined (COM_ENABLE_CDC_CLASS))
                    if((pEP->bMisc == COM_CLASS_CDC_DATA) ||(pEP->bMisc == COM_CLASS_CDC))
                    {
                        cdcComNums = COM_Cdc_EpInit(pEP, curEp, cdcComNums);
                    }
                #endif  /* (COM_ENABLE_CDC_CLASS) */
                }
                
                pEP = &pEP[1u];
            }
            
        #else
            for (i = COM_EP1; i < COM_MAX_EP; ++i)
            {
                /* p_list points the endpoint setting table. */
                pEP = (const T_COM_EP_SETTINGS_BLOCK CYCODE *) pTmp->p_list;
                /* Find max length for each EP and select it (length could be different in different Alt settings) */
                /* but other settings should be correct with regards to Interface alt Setting */
                
                for (curEp = 0u; curEp < ep; ++curEp)
                {
                    if (i == (pEP->addr & COM_DIR_UNUSED))
                    {
                        /* Compare endpoint buffers size with current size to find greater. */
                        if (COM_EP[i].bufferSize < pEP->bufferSize)
                        {
                            COM_EP[i].bufferSize = pEP->bufferSize;
                        }
                        
                        /* Compare current Alternate setting with EP Alt */
                        if (COM_interfaceSetting[pEP->interface] == pEP->altSetting)
                        {                            
                            COM_EP[i].addr = pEP->addr;
                            COM_EP[i].attrib = pEP->attributes;
                            
                            epType = pEP->attributes & COM_EP_TYPE_MASK;
                            
                            if (0u != (pEP->addr & COM_DIR_IN))
                            {
                                /* IN Endpoint */
                                COM_EP[i].epMode     = COM_GET_ACTIVE_IN_EP_CR0_MODE(epType);
                                COM_EP[i].apiEpState = COM_EVENT_PENDING;
                                
                            #if (defined(COM_ENABLE_MIDI_STREAMING) && (COM_MIDI_IN_BUFF_SIZE > 0))
                                if ((pEP->bMisc == COM_CLASS_AUDIO) && (epType == COM_EP_TYPE_BULK))
                                {
                                    COM_midi_in_ep = i;
                                }
                            #endif  /* (COM_ENABLE_MIDI_STREAMING) */
                            }
                            else
                            {
                                /* OUT Endpoint */
                                COM_EP[i].epMode     = COM_GET_ACTIVE_OUT_EP_CR0_MODE(epType);
                                COM_EP[i].apiEpState = COM_NO_EVENT_PENDING;
                                
                            #if (defined(COM_ENABLE_MIDI_STREAMING) && (COM_MIDI_OUT_BUFF_SIZE > 0))
                                if ((pEP->bMisc == COM_CLASS_AUDIO) && (epType == COM_EP_TYPE_BULK))
                                {
                                    COM_midi_out_ep = i;
                                }
                            #endif  /* (COM_ENABLE_MIDI_STREAMING) */
                            }

                        #if (defined(COM_ENABLE_CDC_CLASS))
                            if((pEP->bMisc == COM_CLASS_CDC_DATA) ||(pEP->bMisc == COM_CLASS_CDC))
                            {
                                cdcComNums = COM_Cdc_EpInit(pEP, i, cdcComNums);
                            }
                        #endif  /* (COM_ENABLE_CDC_CLASS) */

                            #if (COM_EP_MANAGEMENT_DMA_AUTO)
                                break;  /* Use first EP setting in Auto memory management */
                            #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
                        }
                    }
                    
                    pEP = &pEP[1u];
                }
            }
        #endif /*  (COM_EP_MANAGEMENT_MANUAL && COM_EP_ALLOC_DYNAMIC) */

        /* Init class array for each interface and interface number for each EP.
        *  It is used for handling Class specific requests directed to either an
        *  interface or the endpoint.
        */
        /* p_list points the endpoint setting table. */
        pEP = (const T_COM_EP_SETTINGS_BLOCK CYCODE *) pTmp->p_list;
        for (i = 0u; i < ep; i++)
        {
            /* Configure interface number for each EP */
            COM_EP[pEP->addr & COM_DIR_UNUSED].interface = pEP->interface;
            pEP = &pEP[1u];
        }
        
        /* Init pointer on interface class table */
        COM_interfaceClass = COM_GetInterfaceClassTablePtr();
        
    /* Set the endpoint buffer addresses */
    #if (!COM_EP_MANAGEMENT_DMA_AUTO)
        buffCount = 0u;
        for (ep = COM_EP1; ep < COM_MAX_EP; ++ep)
        {
            COM_EP[ep].buffOffset = buffCount;        
            buffCount += COM_EP[ep].bufferSize;
            
        #if (COM_GEN_16BITS_EP_ACCESS)
            /* Align EP buffers to be event size to access 16-bits DR register. */
            buffCount += (0u != (buffCount & 0x01u)) ? 1u : 0u;
        #endif /* (COM_GEN_16BITS_EP_ACCESS) */            
        }
    #endif /* (!COM_EP_MANAGEMENT_DMA_AUTO) */

        /* Configure hardware registers */
        COM_ConfigReg();
    }
}


/*******************************************************************************
* Function Name: COM_ConfigAltChanged
****************************************************************************//**
*
*  This routine update configuration for the required endpoints only.
*  It is called after SET_INTERFACE request when Static memory allocation used.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_ConfigAltChanged(void) 
{
    uint8 ep;
    uint8 curEp;
    uint8 epType;
    uint8 i;
    uint8 interfaceNum;

    const T_COM_LUT CYCODE *pTmp;
    const T_COM_EP_SETTINGS_BLOCK CYCODE *pEP;

    /* Init Endpoints and Device Status if configured */
    if (COM_configuration > 0u)
    {
        /* Get number of endpoints configurations (ep). */
        pTmp = COM_GetConfigTablePtr(COM_configuration - 1u);
        pTmp = &pTmp[1u];
        ep = pTmp->c;

        /* Get pointer to endpoints setting table (pEP). */
        pEP = (const T_COM_EP_SETTINGS_BLOCK CYCODE *) pTmp->p_list;
        
        /* Look through all possible endpoint configurations. Find endpoints 
        * which belong to current interface and alternate settings for 
        * re-configuration.
        */
        interfaceNum = COM_interfaceNumber;
        for (i = 0u; i < ep; i++)
        {
            /* Find endpoints which belong to current interface and alternate settings. */
            if ((interfaceNum == pEP->interface) && 
                (COM_interfaceSetting[interfaceNum] == pEP->altSetting))
            {
                curEp  = ((uint8) pEP->addr & COM_DIR_UNUSED);
                epType = ((uint8) pEP->attributes & COM_EP_TYPE_MASK);
                
                /* Change the SIE mode for the selected EP to NAK ALL */
                COM_EP[curEp].epToggle   = 0u;
                COM_EP[curEp].addr       = pEP->addr;
                COM_EP[curEp].attrib     = pEP->attributes;
                COM_EP[curEp].bufferSize = pEP->bufferSize;

                if (0u != (pEP->addr & COM_DIR_IN))
                {
                    /* IN Endpoint */
                    COM_EP[curEp].epMode     = COM_GET_ACTIVE_IN_EP_CR0_MODE(epType);
                    COM_EP[curEp].apiEpState = COM_EVENT_PENDING;
                }
                else
                {
                    /* OUT Endpoint */
                    COM_EP[curEp].epMode     = COM_GET_ACTIVE_OUT_EP_CR0_MODE(epType);
                    COM_EP[curEp].apiEpState = COM_NO_EVENT_PENDING;
                }
                
                /* Make SIE to NAK any endpoint requests */
                COM_SIE_EP_BASE.sieEp[curEp].epCr0 = COM_MODE_NAK_IN_OUT;

            #if (COM_EP_MANAGEMENT_DMA_AUTO)
                /* Clear IN data ready. */
                COM_ARB_EP_BASE.arbEp[curEp].epCfg &= (uint8) ~COM_ARB_EPX_CFG_IN_DATA_RDY;

                /* Select endpoint number of reconfiguration */
                COM_DYN_RECONFIG_REG = (uint8) ((curEp - 1u) << COM_DYN_RECONFIG_EP_SHIFT);
                
                /* Request for dynamic re-configuration of endpoint. */
                COM_DYN_RECONFIG_REG |= COM_DYN_RECONFIG_ENABLE;
                
                /* Wait until block is ready for re-configuration */
                while (0u == (COM_DYN_RECONFIG_REG & COM_DYN_RECONFIG_RDY_STS))
                {
                }
                
                /* Once DYN_RECONFIG_RDY_STS bit is set, FW can change the EP configuration. */
                /* Change EP Type with new direction */
                if (0u != (pEP->addr & COM_DIR_IN))
                {
                    /* Set endpoint type: 0 - IN and 1 - OUT. */
                    COM_EP_TYPE_REG &= (uint8) ~(uint8)((uint8) 0x01u << (curEp - 1u));
                    
                #if (CY_PSOC4)
                    /* Clear DMA_TERMIN for IN endpoint */
                    COM_ARB_EP_BASE.arbEp[curEp].epIntEn &= (uint32) ~COM_ARB_EPX_INT_DMA_TERMIN;
                #endif /* (CY_PSOC4) */
                }
                else
                {
                    /* Set endpoint type: 0 - IN and 1- OUT. */
                    COM_EP_TYPE_REG |= (uint8) ((uint8) 0x01u << (curEp - 1u));
                    
                #if (CY_PSOC4)
                    /* Set DMA_TERMIN for OUT endpoint */
                    COM_ARB_EP_BASE.arbEp[curEp].epIntEn |= (uint32) COM_ARB_EPX_INT_DMA_TERMIN;
                #endif /* (CY_PSOC4) */
                }
                
                /* Complete dynamic re-configuration: all endpoint related status and signals 
                * are set into the default state.
                */
                COM_DYN_RECONFIG_REG &= (uint8) ~COM_DYN_RECONFIG_ENABLE;

            #else
                COM_SIE_EP_BASE.sieEp[curEp].epCnt0 = HI8(COM_EP[curEp].bufferSize);
                COM_SIE_EP_BASE.sieEp[curEp].epCnt1 = LO8(COM_EP[curEp].bufferSize);
                
                #if (CY_PSOC4)
                    COM_ARB_EP16_BASE.arbEp[curEp].rwRa16  = (uint32) COM_EP[curEp].buffOffset;
                    COM_ARB_EP16_BASE.arbEp[curEp].rwWa16  = (uint32) COM_EP[curEp].buffOffset;
                #else
                    COM_ARB_EP_BASE.arbEp[curEp].rwRa    = LO8(COM_EP[curEp].buffOffset);
                    COM_ARB_EP_BASE.arbEp[curEp].rwRaMsb = HI8(COM_EP[curEp].buffOffset);
                    COM_ARB_EP_BASE.arbEp[curEp].rwWa    = LO8(COM_EP[curEp].buffOffset);
                    COM_ARB_EP_BASE.arbEp[curEp].rwWaMsb = HI8(COM_EP[curEp].buffOffset);
                #endif /* (CY_PSOC4) */                
            #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
            }
            
            pEP = &pEP[1u]; /* Get next EP element */
        }
        
        /* The main loop has to re-enable DMA and OUT endpoint */
    }
}


/*******************************************************************************
* Function Name: COM_GetConfigTablePtr
****************************************************************************//**
*
*  This routine returns a pointer a configuration table entry
*
*  \param confIndex:  Configuration Index
*
* \return
*  Device Descriptor pointer or NULL when descriptor does not exist.
*
*******************************************************************************/
const T_COM_LUT CYCODE *COM_GetConfigTablePtr(uint8 confIndex)
                                                        
{
    /* Device Table */
    const T_COM_LUT CYCODE *pTmp;

    pTmp = (const T_COM_LUT CYCODE *) COM_TABLE[COM_device].p_list;

    /* The first entry points to the Device Descriptor,
    *  the second entry point to the BOS Descriptor
    *  the rest configuration entries.
    *  Set pointer to the first Configuration Descriptor
    */
    pTmp = &pTmp[2u];
    /* For this table, c is the number of configuration descriptors  */
    if(confIndex >= pTmp->c)   /* Verify that required configuration descriptor exists */
    {
        pTmp = (const T_COM_LUT CYCODE *) NULL;
    }
    else
    {
        pTmp = (const T_COM_LUT CYCODE *) pTmp[confIndex].p_list;
    }

    return (pTmp);
}


#if (COM_BOS_ENABLE)
    /*******************************************************************************
    * Function Name: COM_GetBOSPtr
    ****************************************************************************//**
    *
    *  This routine returns a pointer a BOS table entry
    *
    *  
    *
    * \return
    *  BOS Descriptor pointer or NULL when descriptor does not exist.
    *
    *******************************************************************************/
    const T_COM_LUT CYCODE *COM_GetBOSPtr(void)
                                                            
    {
        /* Device Table */
        const T_COM_LUT CYCODE *pTmp;

        pTmp = (const T_COM_LUT CYCODE *) COM_TABLE[COM_device].p_list;

        /* The first entry points to the Device Descriptor,
        *  the second entry points to the BOS Descriptor
        */
        pTmp = &pTmp[1u];
        pTmp = (const T_COM_LUT CYCODE *) pTmp->p_list;
        return (pTmp);
    }
#endif /* (COM_BOS_ENABLE) */


/*******************************************************************************
* Function Name: COM_GetDeviceTablePtr
****************************************************************************//**
*
*  This routine returns a pointer to the Device table
*
* \return
*  Device Table pointer
*
*******************************************************************************/
const T_COM_LUT CYCODE *COM_GetDeviceTablePtr(void)
                                                            
{
    /* Device Table */
    return( (const T_COM_LUT CYCODE *) COM_TABLE[COM_device].p_list );
}


/*******************************************************************************
* Function Name: USB_GetInterfaceClassTablePtr
****************************************************************************//**
*
*  This routine returns Interface Class table pointer, which contains
*  the relation between interface number and interface class.
*
* \return
*  Interface Class table pointer.
*
*******************************************************************************/
const uint8 CYCODE *COM_GetInterfaceClassTablePtr(void)
                                                        
{
    const T_COM_LUT CYCODE *pTmp;
    const uint8 CYCODE *pInterfaceClass;
    uint8 currentInterfacesNum;

    pTmp = COM_GetConfigTablePtr(COM_configuration - 1u);
    if (pTmp != NULL)
    {
        currentInterfacesNum  = ((const uint8 *) pTmp->p_list)[COM_CONFIG_DESCR_NUM_INTERFACES];
        /* Third entry in the LUT starts the Interface Table pointers */
        /* The INTERFACE_CLASS table is located after all interfaces */
        pTmp = &pTmp[currentInterfacesNum + 2u];
        pInterfaceClass = (const uint8 CYCODE *) pTmp->p_list;
    }
    else
    {
        pInterfaceClass = (const uint8 CYCODE *) NULL;
    }

    return (pInterfaceClass);
}


/*******************************************************************************
* Function Name: COM_TerminateEP
****************************************************************************//**
*
*  This function terminates the specified USBFS endpoint.
*  This function should be used before endpoint reconfiguration.
*
*  \param ep Contains the data endpoint number.
*
*  \reentrant
*  No.
*
* \sideeffect
* 
* The device responds with a NAK for any transactions on the selected endpoint.
*   
*******************************************************************************/
void COM_TerminateEP(uint8 epNumber) 
{
    /* Get endpoint number */
    epNumber &= COM_DIR_UNUSED;

    if ((epNumber > COM_EP0) && (epNumber < COM_MAX_EP))
    {
        /* Set the endpoint Halt */
        COM_EP[epNumber].hwEpState |= COM_ENDPOINT_STATUS_HALT;

        /* Clear the data toggle */
        COM_EP[epNumber].epToggle = 0u;
        COM_EP[epNumber].apiEpState = COM_NO_EVENT_ALLOWED;

        if ((COM_EP[epNumber].addr & COM_DIR_IN) != 0u)
        {   
            /* IN Endpoint */
            COM_SIE_EP_BASE.sieEp[epNumber].epCr0 = COM_MODE_NAK_IN;
        }
        else
        {
            /* OUT Endpoint */
            COM_SIE_EP_BASE.sieEp[epNumber].epCr0 = COM_MODE_NAK_OUT;
        }
    }
}


/*******************************************************************************
* Function Name: COM_SetEndpointHalt
****************************************************************************//**
*
*  This routine handles set endpoint halt.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_SetEndpointHalt(void) 
{
    uint8 requestHandled = COM_FALSE;
    uint8 ep;
    
    /* Set endpoint halt */
    ep = COM_wIndexLoReg & COM_DIR_UNUSED;

    if ((ep > COM_EP0) && (ep < COM_MAX_EP))
    {
        /* Set the endpoint Halt */
        COM_EP[ep].hwEpState |= (COM_ENDPOINT_STATUS_HALT);

        /* Clear the data toggle */
        COM_EP[ep].epToggle = 0u;
        COM_EP[ep].apiEpState |= COM_NO_EVENT_ALLOWED;

        if ((COM_EP[ep].addr & COM_DIR_IN) != 0u)
        {
            /* IN Endpoint */
            COM_SIE_EP_BASE.sieEp[ep].epCr0 = (COM_MODE_STALL_DATA_EP | 
                                                            COM_MODE_ACK_IN);
        }
        else
        {
            /* OUT Endpoint */
            COM_SIE_EP_BASE.sieEp[ep].epCr0 = (COM_MODE_STALL_DATA_EP | 
                                                            COM_MODE_ACK_OUT);
        }
        requestHandled = COM_InitNoDataControlTransfer();
    }

    return (requestHandled);
}


/*******************************************************************************
* Function Name: COM_ClearEndpointHalt
****************************************************************************//**
*
*  This routine handles clear endpoint halt.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_ClearEndpointHalt(void) 
{
    uint8 requestHandled = COM_FALSE;
    uint8 ep;

    /* Clear endpoint halt */
    ep = COM_wIndexLoReg & COM_DIR_UNUSED;

    if ((ep > COM_EP0) && (ep < COM_MAX_EP))
    {
        /* Clear the endpoint Halt */
        COM_EP[ep].hwEpState &= (uint8) ~COM_ENDPOINT_STATUS_HALT;

        /* Clear the data toggle */
        COM_EP[ep].epToggle = 0u;
        
        /* Clear toggle bit for already armed packet */
        COM_SIE_EP_BASE.sieEp[ep].epCnt0 = (uint8) ~(uint8)COM_EPX_CNT_DATA_TOGGLE;
        
        /* Return API State as it was defined before */
        COM_EP[ep].apiEpState &= (uint8) ~COM_NO_EVENT_ALLOWED;

        if ((COM_EP[ep].addr & COM_DIR_IN) != 0u)
        {
            /* IN Endpoint */
            if(COM_EP[ep].apiEpState == COM_IN_BUFFER_EMPTY)
            {       
                /* Wait for next packet from application */
                COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_MODE_NAK_IN;
            }
            else    /* Continue armed transfer */
            {
                COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_MODE_ACK_IN;
            }
        }
        else
        {
            /* OUT Endpoint */
            if (COM_EP[ep].apiEpState == COM_OUT_BUFFER_FULL)
            {       
                /* Allow application to read full buffer */
                COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_MODE_NAK_OUT;
            }
            else    /* Mark endpoint as empty, so it will be reloaded */
            {
                COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_MODE_ACK_OUT;
            }
        }
        
        requestHandled = COM_InitNoDataControlTransfer();
    }

    return(requestHandled);
}


/*******************************************************************************
* Function Name: COM_ValidateAlternateSetting
****************************************************************************//**
*
*  Validates (and records) a SET INTERFACE request.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_ValidateAlternateSetting(void) 
{
    uint8 requestHandled = COM_FALSE;
    
    uint8 interfaceNum;
    uint8 curInterfacesNum;
    const T_COM_LUT CYCODE *pTmp;
    
    /* Get interface number from the request. */
    interfaceNum = (uint8) COM_wIndexLoReg;
    
    /* Get number of interfaces for current configuration. */
    pTmp = COM_GetConfigTablePtr(COM_configuration - 1u);
    curInterfacesNum  = ((const uint8 *) pTmp->p_list)[COM_CONFIG_DESCR_NUM_INTERFACES];

    /* Validate that interface number is within range. */
    if ((interfaceNum <= curInterfacesNum) || (interfaceNum <= COM_MAX_INTERFACES_NUMBER))
    {
        /* Save current and new alternate settings (come with request) to make 
        * desicion about following endpoint re-configuration.
        */
        COM_interfaceSettingLast[interfaceNum] = COM_interfaceSetting[interfaceNum];
        COM_interfaceSetting[interfaceNum]     = (uint8) COM_wValueLoReg;
        
        requestHandled = COM_TRUE;
    }

    return (requestHandled);
}


/* [] END OF FILE */
