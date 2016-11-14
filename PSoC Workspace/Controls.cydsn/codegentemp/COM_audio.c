/***************************************************************************//**
* \file COM_audio.c
* \version 3.0
*
* \brief
*  This file contains the USB AUDIO Class request handler.
*
* Related Document:
*  Universal Serial Bus Device Class Definition for Audio Devices Release 1.0
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_audio.h"
#include "COM_pvt.h"
#include "cyapicallbacks.h"

#if defined(COM_ENABLE_AUDIO_CLASS)

/***************************************
* Custom Declarations
***************************************/

/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */


#if !defined(USER_SUPPLIED_AUDIO_HANDLER)

/***************************************
*    AUDIO Variables
***************************************/

#if defined(COM_ENABLE_AUDIO_STREAMING)
    /** Contains the current audio sample frequency. It is set by the host using a SET_CUR request to the endpoint.*/
    volatile uint8 COM_currentSampleFrequency[COM_MAX_EP][COM_SAMPLE_FREQ_LEN];
    /** Used as a flag for the user code, to inform it that the host has been sent a request 
     * to change the sample frequency. The sample frequency will be sent on the next OUT transaction. 
     * It contains the endpoint address when set. The following code is recommended for 
     * detecting new sample frequency in main code:
     * \snippet  /USBFS_sut_02.cydsn/main.c Detecting new Sample Frequency
     *     
     * The USBFS_transferState variable is checked to make sure that the transfer completes. */
    volatile uint8 COM_frequencyChanged;
    /** Contains the mute configuration set by the host.*/
    volatile uint8 COM_currentMute;
    /** Contains the volume level set by the host.*/
    volatile uint8 COM_currentVolume[COM_VOLUME_LEN];
    volatile uint8 COM_minimumVolume[COM_VOLUME_LEN] = {COM_VOL_MIN_LSB,
                                                                                  COM_VOL_MIN_MSB};
    volatile uint8 COM_maximumVolume[COM_VOLUME_LEN] = {COM_VOL_MAX_LSB,
                                                                                  COM_VOL_MAX_MSB};
    volatile uint8 COM_resolutionVolume[COM_VOLUME_LEN] = {COM_VOL_RES_LSB,
                                                                                     COM_VOL_RES_MSB};
#endif /*  COM_ENABLE_AUDIO_STREAMING */


/*******************************************************************************
* Function Name: COM_DispatchAUDIOClassRqst
****************************************************************************//**
*
*  This routine dispatches class requests
*
* \return
*  Results of Audio Class request handling: 
*  - COM_TRUE  - request was handled without errors
*  - COM_FALSE - error occurs during handling of request     
*
* \globalvars
*   COM_currentSampleFrequency: Contains the current audio Sample
*       Frequency. It is set by the Host using SET_CUR request to the endpoint.
*   COM_frequencyChanged: This variable is used as a flag for the
*       user code, to be aware that Host has been sent request for changing
*       Sample Frequency. Sample frequency will be sent on the next OUT
*       transaction. It is contains endpoint address when set. The following
*       code is recommended for detecting new Sample Frequency in main code:
*       
*  \snippet  /USBFS_sut_02.cydsn/main.c Detecting new Sample Frequency
*      
*   COM_transferState variable is checked to be sure that transfer
*              completes.
*   COM_currentMute: Contains mute configuration set by Host.
*   COM_currentVolume: Contains volume level set by Host.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_DispatchAUDIOClassRqst(void) 
{
    uint8 requestHandled = COM_FALSE;
    
    uint8 RqstRcpt = (uint8)(COM_bmRequestTypeReg & COM_RQST_RCPT_MASK);
#if defined(COM_ENABLE_AUDIO_STREAMING)
    uint8 wValueHi = (uint8) COM_wValueHiReg;
    uint8 epNumber = (uint8) COM_wIndexLoReg & COM_DIR_UNUSED;
#endif /* (COM_ENABLE_AUDIO_STREAMING) */
    
    /* Check request direction: D2H or H2D. */
    if (0u != (COM_bmRequestTypeReg & COM_RQST_DIR_D2H))
    {
        /* Handle direction from device to host. */
        
        if (COM_RQST_RCPT_EP == RqstRcpt)
        {
            /* Request recipient is to endpoint. */
            switch (COM_bRequestReg)
            {
                case COM_GET_CUR:
                #if defined(COM_ENABLE_AUDIO_STREAMING)
                    if (wValueHi == COM_SAMPLING_FREQ_CONTROL)
                    {
                         /* point Control Selector is Sampling Frequency */
                        COM_currentTD.wCount = COM_SAMPLE_FREQ_LEN;
                        COM_currentTD.pData  = COM_currentSampleFrequency[epNumber];
                        
                        requestHandled   = COM_InitControlRead();
                    }
                #endif /* (COM_ENABLE_AUDIO_STREAMING) */
                
                    /* `#START AUDIO_READ_REQUESTS` Place other request handler here */

                    /* `#END` */
                
                #ifdef COM_DISPATCH_AUDIO_CLASS_AUDIO_READ_REQUESTS_CALLBACK    
                    COM_DispatchAUDIOClass_AUDIO_READ_REQUESTS_Callback();
                #endif /* (COM_DISPATCH_AUDIO_CLASS_AUDIO_READ_REQUESTS_CALLBACK) */                   
                break;
                
                default:
                    /* Do not handle this request unless callback is defined. */
                    break;
            }
        
        }
        else if (COM_RQST_RCPT_IFC == RqstRcpt)
        {
            /* Request recipient is interface or entity ID. */
            switch (COM_bRequestReg)
            {
                case COM_GET_CUR:
                #if defined(COM_ENABLE_AUDIO_STREAMING)
                    if (wValueHi == COM_MUTE_CONTROL)
                    {
                        /* `#START MUTE_CONTROL_GET_REQUEST` Place multi-channel handler here */

                        /* `#END` */

                    #ifdef COM_DISPATCH_AUDIO_CLASS_MUTE_CONTROL_GET_REQUEST_CALLBACK
                        COM_DispatchAUDIOClass_MUTE_CONTROL_GET_REQUEST_Callback();
                    #endif /* (COM_DISPATCH_AUDIO_CLASS_MUTE_CONTROL_GET_REQUEST_CALLBACK) */

                        /* Entity ID Control Selector is MUTE */
                        COM_currentTD.wCount = 1u;
                        COM_currentTD.pData  = &COM_currentMute;
                        
                        requestHandled = COM_InitControlRead();
                    }
                    else if (wValueHi == COM_VOLUME_CONTROL)
                    {
                        /* `#START VOLUME_CONTROL_GET_REQUEST` Place multi-channel handler here */

                        /* `#END` */

                    #ifdef COM_DISPATCH_AUDIO_CLASS_VOLUME_CONTROL_GET_REQUEST_CALLBACK
                        COM_DispatchAUDIOClass_VOLUME_CONTROL_GET_REQUEST_Callback();
                    #endif /* (COM_DISPATCH_AUDIO_CLASS_VOLUME_CONTROL_GET_REQUEST_CALLBACK) */

                        /* Entity ID Control Selector is VOLUME, */
                        COM_currentTD.wCount = COM_VOLUME_LEN;
                        COM_currentTD.pData  = COM_currentVolume;
                        
                        requestHandled = COM_InitControlRead();
                    }
                    else
                    {
                        /* `#START OTHER_GET_CUR_REQUESTS` Place other request handler here */

                        /* `#END` */

                    #ifdef COM_DISPATCH_AUDIO_CLASS_OTHER_GET_CUR_REQUESTS_CALLBACK
                        COM_DispatchAUDIOClass_OTHER_GET_CUR_REQUESTS_Callback();
                    #endif /* (COM_DISPATCH_AUDIO_CLASS_OTHER_GET_CUR_REQUESTS_CALLBACK) */
                    }
                    break;
                    
                case COM_GET_MIN:
                    if (wValueHi == COM_VOLUME_CONTROL)
                    {
                        /* Entity ID Control Selector is VOLUME, */
                        COM_currentTD.wCount = COM_VOLUME_LEN;
                        COM_currentTD.pData  = &COM_minimumVolume[0];
                        
                        requestHandled = COM_InitControlRead();
                    }
                    break;
                    
                case COM_GET_MAX:
                    if (wValueHi == COM_VOLUME_CONTROL)
                    {
                        /* Entity ID Control Selector is VOLUME, */
                        COM_currentTD.wCount = COM_VOLUME_LEN;
                        COM_currentTD.pData  = &COM_maximumVolume[0];
                        
                        requestHandled = COM_InitControlRead();
                    }
                    break;
                    
                case COM_GET_RES:
                    if (wValueHi == COM_VOLUME_CONTROL)
                    {
                         /* Entity ID Control Selector is VOLUME, */
                        COM_currentTD.wCount = COM_VOLUME_LEN;
                        COM_currentTD.pData  = &COM_resolutionVolume[0];
                        
                        requestHandled   = COM_InitControlRead();
                    }
                    break;
                    
                /* The contents of the status message is reserved for future use.
                * For the time being, a null packet should be returned in the data stage of the
                * control transfer, and the received null packet should be ACKed.
                */
                case COM_GET_STAT:
                    COM_currentTD.wCount = 0u;    
                    
                    requestHandled = COM_InitControlWrite();

                #endif /* (COM_ENABLE_AUDIO_STREAMING) */
                
                    /* `#START AUDIO_WRITE_REQUESTS` Place other request handler here */

                    /* `#END` */
                
                #ifdef COM_DISPATCH_AUDIO_CLASS_AUDIO_WRITE_REQUESTS_CALLBACK
                    COM_DispatchAUDIOClass_AUDIO_WRITE_REQUESTS_Callback();
                #endif /* (COM_DISPATCH_AUDIO_CLASS_AUDIO_WRITE_REQUESTS_CALLBACK) */
                    break;
                
                default:
                    /* Do not handle this request. */
                    break;
            }
        }
        else
        {   
            /* Do not handle other requests recipients. */
        }
    }
    else
    {
        /* Handle direction from host to device. */
        
        if (COM_RQST_RCPT_EP == RqstRcpt)
        {
            /* Request recipient is endpoint. */
            switch (COM_bRequestReg)
            {
                case COM_SET_CUR:
                #if defined(COM_ENABLE_AUDIO_STREAMING)
                    if (wValueHi == COM_SAMPLING_FREQ_CONTROL)
                    {
                         /* point Control Selector is Sampling Frequency */
                        COM_currentTD.wCount = COM_SAMPLE_FREQ_LEN;
                        COM_currentTD.pData  = COM_currentSampleFrequency[epNumber];
                        COM_frequencyChanged = (uint8) epNumber;
                        
                        requestHandled   = COM_InitControlWrite();
                    }
                #endif /* (COM_ENABLE_AUDIO_STREAMING) */

                    /* `#START AUDIO_SAMPLING_FREQ_REQUESTS` Place other request handler here */

                    /* `#END` */

                #ifdef COM_DISPATCH_AUDIO_CLASS_AUDIO_SAMPLING_FREQ_REQUESTS_CALLBACK
                    COM_DispatchAUDIOClass_AUDIO_SAMPLING_FREQ_REQUESTS_Callback();
                #endif /* (COM_DISPATCH_AUDIO_CLASS_AUDIO_SAMPLING_FREQ_REQUESTS_CALLBACK) */
                    break;
                
                default:
                    /* Do not handle this request. */
                    break;
            }
        }
        else if(COM_RQST_RCPT_IFC == RqstRcpt)
        {
            /* Request recipient is interface or entity ID. */
            switch (COM_bRequestReg)
            {
                case COM_SET_CUR:
                #if defined(COM_ENABLE_AUDIO_STREAMING)
                    if (wValueHi == COM_MUTE_CONTROL)
                    {
                        /* `#START MUTE_SET_REQUEST` Place multi-channel handler here */

                        /* `#END` */

                    #ifdef COM_DISPATCH_AUDIO_CLASS_MUTE_SET_REQUEST_CALLBACK
                        COM_DispatchAUDIOClass_MUTE_SET_REQUEST_Callback();
                    #endif /* (COM_DISPATCH_AUDIO_CLASS_MUTE_SET_REQUEST_CALLBACK) */

                        /* Entity ID Control Selector is MUTE */
                        COM_currentTD.wCount = 1u;
                        COM_currentTD.pData  = &COM_currentMute;
                        
                        requestHandled = COM_InitControlWrite();
                    }
                    else if (wValueHi == COM_VOLUME_CONTROL)
                    {
                        /* `#START VOLUME_CONTROL_SET_REQUEST` Place multi-channel handler here */

                        /* `#END` */

                    #ifdef COM_DISPATCH_AUDIO_CLASS_VOLUME_CONTROL_SET_REQUEST_CALLBACK
                        COM_DispatchAUDIOClass_VOLUME_CONTROL_SET_REQUEST_Callback();
                    #endif /* (COM_DISPATCH_AUDIO_CLASS_VOLUME_CONTROL_SET_REQUEST_CALLBACK) */

                        /* Entity ID Control Selector is VOLUME */
                        COM_currentTD.wCount = COM_VOLUME_LEN;
                        COM_currentTD.pData  = COM_currentVolume;
                        
                        requestHandled = COM_InitControlWrite();
                    }
                    else
                    {
                        /* `#START OTHER_SET_CUR_REQUESTS` Place other request handler here */

                        /* `#END` */

                    #ifdef COM_DISPATCH_AUDIO_CLASS_OTHER_SET_CUR_REQUESTS_CALLBACK
                        COM_DispatchAUDIOClass_OTHER_SET_CUR_REQUESTS_Callback();
                    #endif /* (COM_DISPATCH_AUDIO_CLASS_OTHER_SET_CUR_REQUESTS_CALLBACK) */
                    }
                #endif /*  COM_ENABLE_AUDIO_STREAMING */
                
                
                    /* `#START AUDIO_CONTROL_SEL_REQUESTS` Place other request handler here */

                    /* `#END` */
                    
                #ifdef COM_DISPATCH_AUDIO_CLASS_AUDIO_CONTROL_SEL_REQUESTS_CALLBACK
                    COM_DispatchAUDIOClass_AUDIO_CONTROL_SEL_REQUESTS_Callback();
                #endif /* (COM_DISPATCH_AUDIO_CLASS_AUDIO_CONTROL_SEL_REQUESTS_CALLBACK) */
                break;

                default:
                    /* Do not handle this request. */
                break;
            }
        }
        else
        {
            /* Do not handle other requests recipients. */
        }
    }

    return (requestHandled);
}
#endif /* (USER_SUPPLIED_AUDIO_HANDLER) */


/*******************************************************************************
* Additional user functions supporting AUDIO Requests
********************************************************************************/

/* `#START AUDIO_FUNCTIONS` Place any additional functions here */

/* `#END` */

#endif  /* (COM_ENABLE_AUDIO_CLASS) */


/* [] END OF FILE */
