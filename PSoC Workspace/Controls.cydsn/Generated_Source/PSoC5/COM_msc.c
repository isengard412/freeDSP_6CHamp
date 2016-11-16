/***************************************************************************//**
* \file COM_cdc.c
* \version 3.10
*
* \brief
*  This file contains the USB MSC Class request handler and global API for MSC 
*  class.
*
* Related Document:
*  Universal Serial Bus Class Definitions for Communication Devices Version 1.1
*
********************************************************************************
* \copyright
* Copyright 2012-2016, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_msc.h"
#include "COM_pvt.h"
#include "cyapicallbacks.h"

#if (COM_HANDLE_MSC_REQUESTS)

/***************************************
*          Internal variables
***************************************/

static uint8 COM_lunCount = COM_MSC_LUN_NUMBER;


/*******************************************************************************
* Function Name: COM_DispatchMSCClassRqst
****************************************************************************//**
*   
*  \internal 
*  This routine dispatches MSC class requests.
*
* \return
*  Status of request processing: handled or not handled.
*
* \globalvars
*  COM_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_DispatchMSCClassRqst(void) 
{
    uint8 requestHandled = COM_FALSE;
    
    /* Get request data. */
    uint16 value  = COM_GET_UINT16(COM_wValueHiReg,  COM_wValueLoReg);
    uint16 dataLength = COM_GET_UINT16(COM_wLengthHiReg, COM_wLengthLoReg);
       
    /* Check request direction: D2H or H2D. */
    if (0u != (COM_bmRequestTypeReg & COM_RQST_DIR_D2H))
    {
        /* Handle direction from device to host. */
        
        if (COM_MSC_GET_MAX_LUN == COM_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == COM_MSC_GET_MAX_LUN_WVALUE) &&
                (dataLength == COM_MSC_GET_MAX_LUN_WLENGTH))
            {
                /* Reply to Get Max LUN request: setup control read. */
                COM_currentTD.pData = &COM_lunCount;
                COM_currentTD.count =  COM_MSC_GET_MAX_LUN_WLENGTH;
                
                requestHandled  = COM_InitControlRead();
            }
        }
    }
    else
    {
        /* Handle direction from host to device. */
        
        if (COM_MSC_RESET == COM_bRequestReg)
        {
            /* Check request fields. */
            if ((value  == COM_MSC_RESET_WVALUE) &&
                (dataLength == COM_MSC_RESET_WLENGTH))
            {
                /* Handle to Bulk-Only Reset request: no data control transfer. */
                COM_currentTD.count = COM_MSC_RESET_WLENGTH;
                
            #ifdef COM_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK
                COM_DispatchMSCClass_MSC_RESET_RQST_Callback();
            #endif /* (COM_DISPATCH_MSC_CLASS_MSC_RESET_RQST_CALLBACK) */
                
                requestHandled = COM_InitNoDataControlTransfer();
            }
        }
    }
    
    return (requestHandled);
}


/*******************************************************************************
* Function Name: COM_MSC_SetLunCount
****************************************************************************//**
*
*  This function sets the number of logical units supported in the application. 
*  The default number of logical units is set in the component customizer.
*
*  \param lunCount: Count of the logical units. Valid range is between 1 and 16.
*
*
* \globalvars
*  COM_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_MSC_SetLunCount(uint8 lunCount) 
{
    COM_lunCount = (lunCount - 1u);
}


/*******************************************************************************
* Function Name: COM_MSC_GetLunCount
****************************************************************************//**
*
*  This function returns the number of logical units.
*
* \return
*   Number of the logical units.
*
* \globalvars
*  COM_lunCount - stores number of LUN (logical units).
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_MSC_GetLunCount(void) 
{
    return (COM_lunCount + 1u);
}   

#endif /* (COM_HANDLE_MSC_REQUESTS) */


/* [] END OF FILE */
