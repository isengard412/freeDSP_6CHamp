/***************************************************************************//**
* \file COM_cls.c
* \version 3.10
*
* \brief
*  This file contains the USB Class request handler.
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

#if(COM_EXTERN_CLS == COM_FALSE)

/***************************************
* User Implemented Class Driver Declarations.
***************************************/
/* `#START USER_DEFINED_CLASS_DECLARATIONS` Place your declaration here */

/* `#END` */


/*******************************************************************************
* Function Name: COM_DispatchClassRqst
****************************************************************************//**
*  This routine dispatches class specific requests depend on interface class.
*
* \return
*  requestHandled.
*
* \reentrant
*  No.
*
*******************************************************************************/
uint8 COM_DispatchClassRqst(void) 
{
    uint8 requestHandled;
    uint8 interfaceNumber;

    /* Get interface to which request is intended. */
    switch (COM_bmRequestTypeReg & COM_RQST_RCPT_MASK)
    {
        case COM_RQST_RCPT_IFC:
            /* Class-specific request directed to interface: wIndexLoReg 
            * contains interface number.
            */
            interfaceNumber = (uint8) COM_wIndexLoReg;
            break;
        
        case COM_RQST_RCPT_EP:
            /* Class-specific request directed to endpoint: wIndexLoReg contains 
            * endpoint number. Find interface related to endpoint, 
            */
            interfaceNumber = COM_EP[COM_wIndexLoReg & COM_DIR_UNUSED].interface;
            break;
            
        default:
            /* Default interface is zero. */
            interfaceNumber = 0u;
            break;
    }

#if (defined(COM_ENABLE_HID_CLASS) ||\
            defined(COM_ENABLE_AUDIO_CLASS) ||\
            defined(COM_ENABLE_CDC_CLASS) ||\
            COM_ENABLE_MSC_CLASS)

    /* Handle class request depends on interface type. */
    switch (COM_interfaceClass[interfaceNumber])
    {
    #if defined(COM_ENABLE_HID_CLASS)
        case COM_CLASS_HID:
            requestHandled = COM_DispatchHIDClassRqst();
            break;
    #endif /* (COM_ENABLE_HID_CLASS) */
            
    #if defined(COM_ENABLE_AUDIO_CLASS)
        case COM_CLASS_AUDIO:
            requestHandled = COM_DispatchAUDIOClassRqst();
            break;
    #endif /* (COM_CLASS_AUDIO) */
            
    #if defined(COM_ENABLE_CDC_CLASS)
        case COM_CLASS_CDC:
            requestHandled = COM_DispatchCDCClassRqst();
            break;
    #endif /* (COM_ENABLE_CDC_CLASS) */
        
    #if (COM_ENABLE_MSC_CLASS)
        case COM_CLASS_MSD:
        #if (COM_HANDLE_MSC_REQUESTS)
            /* MSC requests are handled by the component. */
            requestHandled = COM_DispatchMSCClassRqst();
        #elif defined(COM_DISPATCH_MSC_CLASS_RQST_CALLBACK)
            /* MSC requests are handled by user defined callbcak. */
            requestHandled = COM_DispatchMSCClassRqst_Callback();
        #else
            /* MSC requests are not handled. */
            requestHandled = COM_FALSE;
        #endif /* (COM_HANDLE_MSC_REQUESTS) */
            break;
    #endif /* (COM_ENABLE_MSC_CLASS) */
        
        default:
            /* Request is not handled: unknown class request type. */
            requestHandled = COM_FALSE;
            break;
    }
#else /*No class is defined*/
    if (0u != interfaceNumber)
    {
        /* Suppress warning message */
    }
    requestHandled = COM_FALSE;
#endif /*HID or AUDIO or MSC or CDC class enabled*/

    /* `#START USER_DEFINED_CLASS_CODE` Place your Class request here */

    /* `#END` */

#ifdef COM_DISPATCH_CLASS_RQST_CALLBACK
    if (COM_FALSE == requestHandled)
    {
        requestHandled = COM_DispatchClassRqst_Callback(interfaceNumber);
    }
#endif /* (COM_DISPATCH_CLASS_RQST_CALLBACK) */

    return (requestHandled);
}


/*******************************************************************************
* Additional user functions supporting Class Specific Requests
********************************************************************************/

/* `#START CLASS_SPECIFIC_FUNCTIONS` Place any additional functions here */

/* `#END` */

#endif /* COM_EXTERN_CLS */


/* [] END OF FILE */
