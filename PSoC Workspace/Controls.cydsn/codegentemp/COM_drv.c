/***************************************************************************//**
* \file COM_drv.c
* \version 3.10
*
* \brief
*  This file contains the Endpoint 0 Driver for the USBFS Component.  
*
********************************************************************************
* \copyright
* Copyright 2008-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_pvt.h"
#include "cyapicallbacks.h"


/***************************************
* Global data allocation
***************************************/

volatile T_COM_EP_CTL_BLOCK COM_EP[COM_MAX_EP];

/** Contains the current configuration number, which is set by the host using a 
 * SET_CONFIGURATION request. This variable is initialized to zero in 
 * USBFS_InitComponent() API and can be read by the USBFS_GetConfiguration() 
 * API.*/
volatile uint8 COM_configuration;

/** Contains the current interface number.*/
volatile uint8 COM_interfaceNumber;

/** This variable is set to one after SET_CONFIGURATION and SET_INTERFACE 
 *requests. It can be read by the USBFS_IsConfigurationChanged() API */
volatile uint8 COM_configurationChanged;

/** Contains the current device address.*/
volatile uint8 COM_deviceAddress;

/** This is a two-bit variable that contains power status in the bit 0 
 * (DEVICE_STATUS_BUS_POWERED or DEVICE_STATUS_SELF_POWERED) and remote wakeup 
 * status (DEVICE_STATUS_REMOTE_WAKEUP) in the bit 1. This variable is 
 * initialized to zero in USBFS_InitComponent() API, configured by the 
 * USBFS_SetPowerStatus() API. The remote wakeup status cannot be set using the 
 * API SetPowerStatus(). */
volatile uint8 COM_deviceStatus;

volatile uint8 COM_interfaceSetting[COM_MAX_INTERFACES_NUMBER];
volatile uint8 COM_interfaceSetting_last[COM_MAX_INTERFACES_NUMBER];
volatile uint8 COM_interfaceStatus[COM_MAX_INTERFACES_NUMBER];

/** Contains the started device number. This variable is set by the 
 * USBFS_Start() or USBFS_InitComponent() APIs.*/
volatile uint8 COM_device;

/** Initialized class array for each interface. It is used for handling Class 
 * specific requests depend on interface class. Different classes in multiple 
 * alternate settings are not supported.*/
const uint8 CYCODE *COM_interfaceClass;


/***************************************
* Local data allocation
***************************************/

volatile uint8  COM_ep0Toggle;
volatile uint8  COM_lastPacketSize;

/** This variable is used by the communication functions to handle the current 
* transfer state.
* Initialized to TRANS_STATE_IDLE in the USBFS_InitComponent() API and after a 
* complete transfer in the status stage.
* Changed to the TRANS_STATE_CONTROL_READ or TRANS_STATE_CONTROL_WRITE in setup 
* transaction depending on the request type.
*/
volatile uint8  COM_transferState;
volatile T_COM_TD COM_currentTD;
volatile uint8  COM_ep0Mode;
volatile uint8  COM_ep0Count;
volatile uint16 COM_transferByteCount;


/*******************************************************************************
* Function Name: COM_ep_0_Interrupt
****************************************************************************//**
*
*  This Interrupt Service Routine handles Endpoint 0 (Control Pipe) traffic.
*  It dispatches setup requests and handles the data and status stages.
*
*
*******************************************************************************/
CY_ISR(COM_EP_0_ISR)
{
    uint8 tempReg;
    uint8 modifyReg;

#ifdef COM_EP_0_ISR_ENTRY_CALLBACK
    COM_EP_0_ISR_EntryCallback();
#endif /* (COM_EP_0_ISR_ENTRY_CALLBACK) */
    
    tempReg = COM_EP0_CR_REG;
    if ((tempReg & COM_MODE_ACKD) != 0u)
    {
        modifyReg = 1u;
        if ((tempReg & COM_MODE_SETUP_RCVD) != 0u)
        {
            if ((tempReg & COM_MODE_MASK) != COM_MODE_NAK_IN_OUT)
            {
                /* Mode not equal to NAK_IN_OUT: invalid setup */
                modifyReg = 0u;
            }
            else
            {
                COM_HandleSetup();
                
                if ((COM_ep0Mode & COM_MODE_SETUP_RCVD) != 0u)
                {
                    /* SETUP bit set: exit without mode modificaiton */
                    modifyReg = 0u;
                }
            }
        }
        else if ((tempReg & COM_MODE_IN_RCVD) != 0u)
        {
            COM_HandleIN();
        }
        else if ((tempReg & COM_MODE_OUT_RCVD) != 0u)
        {
            COM_HandleOUT();
        }
        else
        {
            modifyReg = 0u;
        }
        
        /* Modify the EP0_CR register */
        if (modifyReg != 0u)
        {
            
            tempReg = COM_EP0_CR_REG;
            
            /* Make sure that SETUP bit is cleared before modification */
            if ((tempReg & COM_MODE_SETUP_RCVD) == 0u)
            {
                /* Update count register */
                tempReg = (uint8) COM_ep0Toggle | COM_ep0Count;
                COM_EP0_CNT_REG = tempReg;
               
                /* Make sure that previous write operaiton was successful */
                if (tempReg == COM_EP0_CNT_REG)
                {
                    /* Repeat until next successful write operation */
                    do
                    {
                        /* Init temporary variable */
                        modifyReg = COM_ep0Mode;
                        
                        /* Unlock register */
                        tempReg = (uint8) (COM_EP0_CR_REG & COM_MODE_SETUP_RCVD);
                        
                        /* Check if SETUP bit is not set */
                        if (0u == tempReg)
                        {
                            /* Set the Mode Register  */
                            COM_EP0_CR_REG = COM_ep0Mode;
                            
                            /* Writing check */
                            modifyReg = COM_EP0_CR_REG & COM_MODE_MASK;
                        }
                    }
                    while (modifyReg != COM_ep0Mode);
                }
            }
        }
    }

    COM_ClearSieInterruptSource(COM_INTR_SIE_EP0_INTR);
	
#ifdef COM_EP_0_ISR_EXIT_CALLBACK
    COM_EP_0_ISR_ExitCallback();
#endif /* (COM_EP_0_ISR_EXIT_CALLBACK) */
}


/*******************************************************************************
* Function Name: COM_HandleSetup
****************************************************************************//**
*
*  This Routine dispatches requests for the four USB request types
*
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_HandleSetup(void) 
{
    uint8 requestHandled;
    
    /* Clear register lock by SIE (read register) and clear setup bit 
    * (write any value in register).
    */
    requestHandled = (uint8) COM_EP0_CR_REG;
    COM_EP0_CR_REG = (uint8) requestHandled;
    requestHandled = (uint8) COM_EP0_CR_REG;

    if ((requestHandled & COM_MODE_SETUP_RCVD) != 0u)
    {
        /* SETUP bit is set: exit without mode modification. */
        COM_ep0Mode = requestHandled;
    }
    else
    {
        /* In case the previous transfer did not complete, close it out */
        COM_UpdateStatusBlock(COM_XFER_PREMATURE);

        /* Check request type. */
        switch (COM_bmRequestTypeReg & COM_RQST_TYPE_MASK)
        {
            case COM_RQST_TYPE_STD:
                requestHandled = COM_HandleStandardRqst();
                break;
                
            case COM_RQST_TYPE_CLS:
                requestHandled = COM_DispatchClassRqst();
                break;
                
            case COM_RQST_TYPE_VND:
                requestHandled = COM_HandleVendorRqst();
                break;
                
            default:
                requestHandled = COM_FALSE;
                break;
        }
        
        /* If request is not recognized. Stall endpoint 0 IN and OUT. */
        if (requestHandled == COM_FALSE)
        {
            COM_ep0Mode = COM_MODE_STALL_IN_OUT;
        }
    }
}


/*******************************************************************************
* Function Name: COM_HandleIN
****************************************************************************//**
*
*  This routine handles EP0 IN transfers.
*
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_HandleIN(void) 
{
    switch (COM_transferState)
    {
        case COM_TRANS_STATE_IDLE:
            break;
        
        case COM_TRANS_STATE_CONTROL_READ:
            COM_ControlReadDataStage();
            break;
            
        case COM_TRANS_STATE_CONTROL_WRITE:
            COM_ControlWriteStatusStage();
            break;
            
        case COM_TRANS_STATE_NO_DATA_CONTROL:
            COM_NoDataControlStatusStage();
            break;
            
        default:    /* there are no more states */
            break;
    }
}


/*******************************************************************************
* Function Name: COM_HandleOUT
****************************************************************************//**
*
*  This routine handles EP0 OUT transfers.
*
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_HandleOUT(void) 
{
    switch (COM_transferState)
    {
        case COM_TRANS_STATE_IDLE:
            break;
        
        case COM_TRANS_STATE_CONTROL_READ:
            COM_ControlReadStatusStage();
            break;
            
        case COM_TRANS_STATE_CONTROL_WRITE:
            COM_ControlWriteDataStage();
            break;
            
        case COM_TRANS_STATE_NO_DATA_CONTROL:
            /* Update the completion block */
            COM_UpdateStatusBlock(COM_XFER_ERROR);
            
            /* We expect no more data, so stall INs and OUTs */
            COM_ep0Mode = COM_MODE_STALL_IN_OUT;
            break;
            
        default:    
            /* There are no more states */
            break;
    }
}


/*******************************************************************************
* Function Name: COM_LoadEP0
****************************************************************************//**
*
*  This routine loads the EP0 data registers for OUT transfers. It uses the
*  currentTD (previously initialized by the _InitControlWrite function and
*  updated for each OUT transfer, and the bLastPacketSize) to determine how
*  many uint8s to transfer on the current OUT.
*
*  If the number of uint8s remaining is zero and the last transfer was full,
*  we need to send a zero length packet.  Otherwise we send the minimum
*  of the control endpoint size (8) or remaining number of uint8s for the
*  transaction.
*
*
* \globalvars
*  COM_transferByteCount - Update the transfer byte count from the
*     last transaction.
*  COM_ep0Count - counts the data loaded to the SIE memory in
*     current packet.
*  COM_lastPacketSize - remembers the USBFS_ep0Count value for the
*     next packet.
*  COM_transferByteCount - sum of the previous bytes transferred
*     on previous packets(sum of USBFS_lastPacketSize)
*  COM_ep0Toggle - inverted
*  COM_ep0Mode  - prepare for mode register content.
*  COM_transferState - set to TRANS_STATE_CONTROL_READ
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_LoadEP0(void) 
{
    uint8 ep0Count = 0u;

    /* Update the transfer byte count from the last transaction */
    COM_transferByteCount += COM_lastPacketSize;

    /* Now load the next transaction */
    while ((COM_currentTD.count > 0u) && (ep0Count < 8u))
    {
        COM_EP0_DR_BASE.epData[ep0Count] = (uint8) *COM_currentTD.pData;
        COM_currentTD.pData = &COM_currentTD.pData[1u];
        ep0Count++;
        COM_currentTD.count--;
    }

    /* Support zero-length packet */
    if ((COM_lastPacketSize == 8u) || (ep0Count > 0u))
    {
        /* Update the data toggle */
        COM_ep0Toggle ^= COM_EP0_CNT_DATA_TOGGLE;
        /* Set the Mode Register  */
        COM_ep0Mode = COM_MODE_ACK_IN_STATUS_OUT;
        /* Update the state (or stay the same) */
        COM_transferState = COM_TRANS_STATE_CONTROL_READ;
    }
    else
    {
        /* Expect Status Stage Out */
        COM_ep0Mode = COM_MODE_STATUS_OUT_ONLY;
        /* Update the state (or stay the same) */
        COM_transferState = COM_TRANS_STATE_CONTROL_READ;
    }

    /* Save the packet size for next time */
    COM_ep0Count =       (uint8) ep0Count;
    COM_lastPacketSize = (uint8) ep0Count;
}


/*******************************************************************************
* Function Name: COM_InitControlRead
****************************************************************************//**
*
*  Initialize a control read transaction. It is used to send data to the host.
*  The following global variables should be initialized before this function
*  called. To send zero length packet use InitZeroLengthControlTransfer
*  function.
*
*
* \return
*  requestHandled state.
*
* \globalvars
*  COM_currentTD.count - counts of data to be sent.
*  COM_currentTD.pData - data pointer.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_InitControlRead(void) 
{
    uint16 xferCount;

    if (COM_currentTD.count == 0u)
    {
        (void) COM_InitZeroLengthControlTransfer();
    }
    else
    {
        /* Set up the state machine */
        COM_transferState = COM_TRANS_STATE_CONTROL_READ;
        
        /* Set the toggle, it gets updated in LoadEP */
        COM_ep0Toggle = 0u;
        
        /* Initialize the Status Block */
        COM_InitializeStatusBlock();
        
        xferCount = ((uint16)((uint16) COM_lengthHiReg << 8u) | ((uint16) COM_lengthLoReg));

        if (COM_currentTD.count > xferCount)
        {
            COM_currentTD.count = xferCount;
        }
        
        COM_LoadEP0();
    }

    return (COM_TRUE);
}


/*******************************************************************************
* Function Name: COM_InitZeroLengthControlTransfer
****************************************************************************//**
*
*  Initialize a zero length data IN transfer.
*
* \return
*  requestHandled state.
*
* \globalvars
*  COM_ep0Toggle - set to EP0_CNT_DATA_TOGGLE
*  COM_ep0Mode  - prepare for mode register content.
*  COM_transferState - set to TRANS_STATE_CONTROL_READ
*  COM_ep0Count - cleared, means the zero-length packet.
*  COM_lastPacketSize - cleared.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_InitZeroLengthControlTransfer(void)
                                                
{
    /* Update the state */
    COM_transferState = COM_TRANS_STATE_CONTROL_READ;
    
    /* Set the data toggle */
    COM_ep0Toggle = COM_EP0_CNT_DATA_TOGGLE;
    
    /* Set the Mode Register  */
    COM_ep0Mode = COM_MODE_ACK_IN_STATUS_OUT;
    
    /* Save the packet size for next time */
    COM_lastPacketSize = 0u;
    
    COM_ep0Count = 0u;

    return (COM_TRUE);
}


/*******************************************************************************
* Function Name: COM_ControlReadDataStage
****************************************************************************//**
*
*  Handle the Data Stage of a control read transfer.
*
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_ControlReadDataStage(void) 

{
    COM_LoadEP0();
}


/*******************************************************************************
* Function Name: COM_ControlReadStatusStage
****************************************************************************//**
*
*  Handle the Status Stage of a control read transfer.
*
*
* \globalvars
*  COM_USBFS_transferByteCount - updated with last packet size.
*  COM_transferState - set to TRANS_STATE_IDLE.
*  COM_ep0Mode  - set to MODE_STALL_IN_OUT.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_ControlReadStatusStage(void) 
{
    /* Update the transfer byte count */
    COM_transferByteCount += COM_lastPacketSize;
    
    /* Go Idle */
    COM_transferState = COM_TRANS_STATE_IDLE;
    
    /* Update the completion block */
    COM_UpdateStatusBlock(COM_XFER_STATUS_ACK);
    
    /* We expect no more data, so stall INs and OUTs */
    COM_ep0Mode = COM_MODE_STALL_IN_OUT;
}


/*******************************************************************************
* Function Name: COM_InitControlWrite
****************************************************************************//**
*
*  Initialize a control write transaction
*
* \return
*  requestHandled state.
*
* \globalvars
*  COM_USBFS_transferState - set to TRANS_STATE_CONTROL_WRITE
*  COM_ep0Toggle - set to EP0_CNT_DATA_TOGGLE
*  COM_ep0Mode  - set to MODE_ACK_OUT_STATUS_IN
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_InitControlWrite(void) 
{
    uint16 xferCount;

    /* Set up the state machine */
    COM_transferState = COM_TRANS_STATE_CONTROL_WRITE;
    
    /* This might not be necessary */
    COM_ep0Toggle = COM_EP0_CNT_DATA_TOGGLE;
    
    /* Initialize the Status Block */
    COM_InitializeStatusBlock();

    xferCount = ((uint16)((uint16) COM_lengthHiReg << 8u) | ((uint16) COM_lengthLoReg));

    if (COM_currentTD.count > xferCount)
    {
        COM_currentTD.count = xferCount;
    }

    /* Expect Data or Status Stage */
    COM_ep0Mode = COM_MODE_ACK_OUT_STATUS_IN;

    return(COM_TRUE);
}


/*******************************************************************************
* Function Name: COM_ControlWriteDataStage
****************************************************************************//**
*
*  Handle the Data Stage of a control write transfer
*       1. Get the data (We assume the destination was validated previously)
*       2. Update the count and data toggle
*       3. Update the mode register for the next transaction
*
*
* \globalvars
*  COM_transferByteCount - Update the transfer byte count from the
*    last transaction.
*  COM_ep0Count - counts the data loaded from the SIE memory
*    in current packet.
*  COM_transferByteCount - sum of the previous bytes transferred
*    on previous packets(sum of USBFS_lastPacketSize)
*  COM_ep0Toggle - inverted
*  COM_ep0Mode  - set to MODE_ACK_OUT_STATUS_IN.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_ControlWriteDataStage(void) 
{
    uint8 ep0Count;
    uint8 regIndex = 0u;

    ep0Count = (COM_EP0_CNT_REG & COM_EPX_CNT0_MASK) - COM_EPX_CNTX_CRC_COUNT;

    COM_transferByteCount += (uint8)ep0Count;

    while ((COM_currentTD.count > 0u) && (ep0Count > 0u))
    {
        *COM_currentTD.pData = (uint8) COM_EP0_DR_BASE.epData[regIndex];
        COM_currentTD.pData = &COM_currentTD.pData[1u];
        regIndex++;
        ep0Count--;
        COM_currentTD.count--;
    }
    
    COM_ep0Count = (uint8)ep0Count;
    
    /* Update the data toggle */
    COM_ep0Toggle ^= COM_EP0_CNT_DATA_TOGGLE;
    
    /* Expect Data or Status Stage */
    COM_ep0Mode = COM_MODE_ACK_OUT_STATUS_IN;
}


/*******************************************************************************
* Function Name: COM_ControlWriteStatusStage
****************************************************************************//**
*
*  Handle the Status Stage of a control write transfer
*
* \globalvars
*  COM_transferState - set to TRANS_STATE_IDLE.
*  COM_USBFS_ep0Mode  - set to MODE_STALL_IN_OUT.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_ControlWriteStatusStage(void) 
{
    /* Go Idle */
    COM_transferState = COM_TRANS_STATE_IDLE;
    
    /* Update the completion block */    
    COM_UpdateStatusBlock(COM_XFER_STATUS_ACK);
    
    /* We expect no more data, so stall INs and OUTs */
    COM_ep0Mode = COM_MODE_STALL_IN_OUT;
}


/*******************************************************************************
* Function Name: COM_InitNoDataControlTransfer
****************************************************************************//**
*
*  Initialize a no data control transfer
*
* \return
*  requestHandled state.
*
* \globalvars
*  COM_transferState - set to TRANS_STATE_NO_DATA_CONTROL.
*  COM_ep0Mode  - set to MODE_STATUS_IN_ONLY.
*  COM_ep0Count - cleared.
*  COM_ep0Toggle - set to EP0_CNT_DATA_TOGGLE
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_InitNoDataControlTransfer(void) 
{
    COM_transferState = COM_TRANS_STATE_NO_DATA_CONTROL;
    COM_ep0Mode       = COM_MODE_STATUS_IN_ONLY;
    COM_ep0Toggle     = COM_EP0_CNT_DATA_TOGGLE;
    COM_ep0Count      = 0u;

    return (COM_TRUE);
}


/*******************************************************************************
* Function Name: COM_NoDataControlStatusStage
****************************************************************************//**
*  Handle the Status Stage of a no data control transfer.
*
*  SET_ADDRESS is special, since we need to receive the status stage with
*  the old address.
*
* \globalvars
*  COM_transferState - set to TRANS_STATE_IDLE.
*  COM_ep0Mode  - set to MODE_STALL_IN_OUT.
*  COM_ep0Toggle - set to EP0_CNT_DATA_TOGGLE
*  COM_deviceAddress - used to set new address and cleared
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_NoDataControlStatusStage(void) 
{
    if (0u != COM_deviceAddress)
    {
        /* Update device address if we got new address. */
        COM_CR0_REG = (uint8) COM_deviceAddress | COM_CR0_ENABLE;
        COM_deviceAddress = 0u;
    }

    COM_transferState = COM_TRANS_STATE_IDLE;
    
    /* Update the completion block. */
    COM_UpdateStatusBlock(COM_XFER_STATUS_ACK);
    
    /* Stall IN and OUT, no more data is expected. */
    COM_ep0Mode = COM_MODE_STALL_IN_OUT;
}


/*******************************************************************************
* Function Name: COM_UpdateStatusBlock
****************************************************************************//**
*
*  Update the Completion Status Block for a Request.  The block is updated
*  with the completion code the COM_transferByteCount.  The
*  StatusBlock Pointer is set to NULL.
*
*  completionCode - status.
*
*
* \globalvars
*  COM_currentTD.pStatusBlock->status - updated by the
*    completionCode parameter.
*  COM_currentTD.pStatusBlock->length - updated.
*  COM_currentTD.pStatusBlock - cleared.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_UpdateStatusBlock(uint8 completionCode) 
{
    if (COM_currentTD.pStatusBlock != NULL)
    {
        COM_currentTD.pStatusBlock->status = completionCode;
        COM_currentTD.pStatusBlock->length = COM_transferByteCount;
        COM_currentTD.pStatusBlock = NULL;
    }
}


/*******************************************************************************
* Function Name: COM_InitializeStatusBlock
****************************************************************************//**
*
*  Initialize the Completion Status Block for a Request.  The completion
*  code is set to USB_XFER_IDLE.
*
*  Also, initializes COM_transferByteCount.  Save some space,
*  this is the only consumer.
*
* \globalvars
*  COM_currentTD.pStatusBlock->status - set to XFER_IDLE.
*  COM_currentTD.pStatusBlock->length - cleared.
*  COM_transferByteCount - cleared.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_InitializeStatusBlock(void) 
{
    COM_transferByteCount = 0u;
    
    if (COM_currentTD.pStatusBlock != NULL)
    {
        COM_currentTD.pStatusBlock->status = COM_XFER_IDLE;
        COM_currentTD.pStatusBlock->length = 0u;
    }
}


/* [] END OF FILE */
