/***************************************************************************//**
* \file COM_cdc.h
* \version 3.0
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  CDC class.
*
* Related Document:
*  Universal Serial Bus Class Definitions for Communication Devices Version 1.1
*
********************************************************************************
* \copyright
* Copyright 2012-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_COM_cdc_H)
#define CY_USBFS_COM_cdc_H

#include "COM.h"


/*******************************************************************************
* Prototypes of the COM_cdc API.
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
#if (COM_ENABLE_CDC_CLASS_API != 0u)
    uint8 COM_CDC_Init(void)            ;
    void COM_PutData(const uint8* pData, uint16 length) ;
    void COM_PutString(const char8 string[])            ;
    void COM_PutChar(char8 txDataByte) ;
    void COM_PutCRLF(void)             ;
    uint16 COM_GetCount(void)          ;
    uint8  COM_CDCIsReady(void)        ;
    uint8  COM_DataIsReady(void)       ;
    uint16 COM_GetData(uint8* pData, uint16 length)     ;
    uint16 COM_GetAll(uint8* pData)    ;
    uint8  COM_GetChar(void)           ;
    uint8  COM_IsLineChanged(void)     ;
    uint32 COM_GetDTERate(void)        ;
    uint8  COM_GetCharFormat(void)     ;
    uint8  COM_GetParityType(void)     ;
    uint8  COM_GetDataBits(void)       ;
    uint16 COM_GetLineControl(void)    ;
    void COM_SendSerialState (uint16 serialState) ;
    uint16 COM_GetSerialState (void)   ;
    void COM_SetComPort (uint8 comNumber) ;
    uint8 COM_GetComPort (void)        ;
    uint8 COM_NotificationIsReady(void) ;

#endif  /* (COM_ENABLE_CDC_CLASS_API) */
/** @} cdc */

/*******************************************************************************
*  Constants for COM_cdc API.
*******************************************************************************/

/* CDC Class-Specific Request Codes (CDC ver 1.2 Table 19) */
#define COM_CDC_SET_LINE_CODING        (0x20u)
#define COM_CDC_GET_LINE_CODING        (0x21u)
#define COM_CDC_SET_CONTROL_LINE_STATE (0x22u)

/*PSTN Subclass Specific Notifications (CDC ver 1.2 Table 30)*/
#define COM_SERIAL_STATE               (0x20u)

#define COM_LINE_CODING_CHANGED        (0x01u)
#define COM_LINE_CONTROL_CHANGED       (0x02u)

#define COM_1_STOPBIT                  (0x00u)
#define COM_1_5_STOPBITS               (0x01u)
#define COM_2_STOPBITS                 (0x02u)

#define COM_PARITY_NONE                (0x00u)
#define COM_PARITY_ODD                 (0x01u)
#define COM_PARITY_EVEN                (0x02u)
#define COM_PARITY_MARK                (0x03u)
#define COM_PARITY_SPACE               (0x04u)

#define COM_LINE_CODING_SIZE           (0x07u)
#define COM_LINE_CODING_RATE           (0x00u)
#define COM_LINE_CODING_STOP_BITS      (0x04u)
#define COM_LINE_CODING_PARITY         (0x05u)
#define COM_LINE_CODING_DATA_BITS      (0x06u)

#define COM_LINE_CONTROL_DTR           (0x01u)
#define COM_LINE_CONTROL_RTS           (0x02u)

#define COM_MAX_MULTI_COM_NUM          (2u) 

#define COM_COM_PORT1                  (0u) 
#define COM_COM_PORT2                  (1u) 

#define COM_SUCCESS                    (0u)
#define COM_FAILURE                    (1u)

#define COM_SERIAL_STATE_SIZE          (10u)

/* SerialState constants*/
#define COM_SERIAL_STATE_REQUEST_TYPE  (0xA1u)
#define COM_SERIAL_STATE_LENGTH        (0x2u)

/*******************************************************************************
* External data references
*******************************************************************************/
/**
* \addtogroup group_cdc
* @{
*/
extern volatile uint8  COM_linesCoding[COM_MAX_MULTI_COM_NUM][COM_LINE_CODING_SIZE];
extern volatile uint8  COM_linesChanged[COM_MAX_MULTI_COM_NUM];
extern volatile uint16 COM_linesControlBitmap[COM_MAX_MULTI_COM_NUM];
extern volatile uint16 COM_serialStateBitmap[COM_MAX_MULTI_COM_NUM];
extern volatile uint8  COM_cdcDataInEp[COM_MAX_MULTI_COM_NUM];
extern volatile uint8  COM_cdcDataOutEp[COM_MAX_MULTI_COM_NUM];
extern volatile uint8  COM_cdcCommInInterruptEp[COM_MAX_MULTI_COM_NUM];
/** @} cdc */

/*******************************************************************************
* The following code is DEPRECATED and
* must not be used.
*******************************************************************************/


#define COM_lineCoding             COM_linesCoding[0]
#define COM_lineChanged            COM_linesChanged[0]
#define COM_lineControlBitmap      COM_linesControlBitmap[0]
#define COM_cdc_data_in_ep         COM_cdcDataInEp[0]
#define COM_cdc_data_out_ep        COM_cdcDataOutEp[0]

#endif /* (CY_USBFS_COM_cdc_H) */


/* [] END OF FILE */
