/***************************************************************************//**
* \file COM_vnd.c
* \version 3.0
*
* \brief
*  This file contains the  USB vendor request handler.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_pvt.h"
#include "cyapicallbacks.h"

#if(COM_EXTERN_VND == COM_FALSE)

/***************************************
* Vendor Specific Declarations
***************************************/

/* `#START VENDOR_SPECIFIC_DECLARATIONS` Place your declaration here */

/* `#END` */


/*******************************************************************************
* Function Name: COM_HandleVendorRqst
****************************************************************************//**
*
*  This routine provide users with a method to implement vendor specific
*  requests.
*
*  To implement vendor specific requests, add your code in this function to
*  decode and disposition the request.  If the request is handled, your code
*  must set the variable "requestHandled" to TRUE, indicating that the
*  request has been handled.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_HandleVendorRqst(void) 
{
    uint8 requestHandled = COM_FALSE;

    /* Check request direction: D2H or H2D. */
    if (0u != (COM_bmRequestTypeReg & COM_RQST_DIR_D2H))
    {
        /* Handle direction from device to host. */
        
        switch (COM_bRequestReg)
        {
            case COM_GET_EXTENDED_CONFIG_DESCRIPTOR:
            #if defined(COM_ENABLE_MSOS_STRING)
                COM_currentTD.pData = (volatile uint8 *) &COM_MSOS_CONFIGURATION_DESCR[0u];
                COM_currentTD.count = COM_MSOS_CONFIGURATION_DESCR[0u];
                requestHandled  = COM_InitControlRead();
            #endif /* (COM_ENABLE_MSOS_STRING) */
                break;
            
            default:
                break;
        }
    }

    /* `#START VENDOR_SPECIFIC_CODE` Place your vendor specific request here */

    /* `#END` */

#ifdef COM_HANDLE_VENDOR_RQST_CALLBACK
    if (COM_FALSE == requestHandled)
    {
        requestHandled = COM_HandleVendorRqst_Callback();
    }
#endif /* (COM_HANDLE_VENDOR_RQST_CALLBACK) */

    return (requestHandled);
}


/*******************************************************************************
* Additional user functions supporting Vendor Specific Requests
********************************************************************************/

/* `#START VENDOR_SPECIFIC_FUNCTIONS` Place any additional functions here */

/* `#END` */


#endif /* COM_EXTERN_VND */


/* [] END OF FILE */
