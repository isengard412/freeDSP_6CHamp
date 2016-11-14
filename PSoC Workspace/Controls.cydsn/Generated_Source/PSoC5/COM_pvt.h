/***************************************************************************//**
* \file .h
* \version 3.0
*
* \brief
*  This file provides private function prototypes and constants for the 
*  USBFS component. It is not intended to be used in the user project.
*
********************************************************************************
* \copyright
* Copyright 2013-2015, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_COM_pvt_H)
#define CY_USBFS_COM_pvt_H

#include "COM.h"
   
#ifdef COM_ENABLE_AUDIO_CLASS
    #include "COM_audio.h"
#endif /* COM_ENABLE_AUDIO_CLASS */

#ifdef COM_ENABLE_CDC_CLASS
    #include "COM_cdc.h"
#endif /* COM_ENABLE_CDC_CLASS */

#if (COM_ENABLE_MIDI_CLASS)
    #include "COM_midi.h"
#endif /* (COM_ENABLE_MIDI_CLASS) */

#if (COM_ENABLE_MSC_CLASS)
    #include "COM_msc.h"
#endif /* (COM_ENABLE_MSC_CLASS) */

#if (COM_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        #include <CyDMA.h>
    #else
        #include <CyDmac.h>
        #if ((COM_EP_MANAGEMENT_DMA_AUTO) && (COM_EP_DMA_AUTO_OPT == 0u))
            #include "COM_EP_DMA_Done_isr.h"
            #include "COM_EP8_DMA_Done_SR.h"
            #include "COM_EP17_DMA_Done_SR.h"
        #endif /* ((COM_EP_MANAGEMENT_DMA_AUTO) && (COM_EP_DMA_AUTO_OPT == 0u)) */
    #endif /* (CY_PSOC4) */
#endif /* (COM_EP_MANAGEMENT_DMA) */

#if (COM_DMA1_ACTIVE)
    #include "COM_ep1_dma.h"
    #define COM_EP1_DMA_CH     (COM_ep1_dma_CHANNEL)
#endif /* (COM_DMA1_ACTIVE) */

#if (COM_DMA2_ACTIVE)
    #include "COM_ep2_dma.h"
    #define COM_EP2_DMA_CH     (COM_ep2_dma_CHANNEL)
#endif /* (COM_DMA2_ACTIVE) */

#if (COM_DMA3_ACTIVE)
    #include "COM_ep3_dma.h"
    #define COM_EP3_DMA_CH     (COM_ep3_dma_CHANNEL)
#endif /* (COM_DMA3_ACTIVE) */

#if (COM_DMA4_ACTIVE)
    #include "COM_ep4_dma.h"
    #define COM_EP4_DMA_CH     (COM_ep4_dma_CHANNEL)
#endif /* (COM_DMA4_ACTIVE) */

#if (COM_DMA5_ACTIVE)
    #include "COM_ep5_dma.h"
    #define COM_EP5_DMA_CH     (COM_ep5_dma_CHANNEL)
#endif /* (COM_DMA5_ACTIVE) */

#if (COM_DMA6_ACTIVE)
    #include "COM_ep6_dma.h"
    #define COM_EP6_DMA_CH     (COM_ep6_dma_CHANNEL)
#endif /* (COM_DMA6_ACTIVE) */

#if (COM_DMA7_ACTIVE)
    #include "COM_ep7_dma.h"
    #define COM_EP7_DMA_CH     (COM_ep7_dma_CHANNEL)
#endif /* (COM_DMA7_ACTIVE) */

#if (COM_DMA8_ACTIVE)
    #include "COM_ep8_dma.h"
    #define COM_EP8_DMA_CH     (COM_ep8_dma_CHANNEL)
#endif /* (COM_DMA8_ACTIVE) */


/***************************************
*     Private Variables
***************************************/

/* Generated external references for descriptors. */
extern const uint8 CYCODE COM_DEVICE0_DESCR[18u];
extern const uint8 CYCODE COM_DEVICE0_CONFIGURATION0_DESCR[141u];
extern const T_COM_EP_SETTINGS_BLOCK CYCODE COM_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[6u];
extern const uint8 CYCODE COM_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[4u];
extern const T_COM_LUT CYCODE COM_DEVICE0_CONFIGURATION0_TABLE[7u];
extern const T_COM_LUT CYCODE COM_DEVICE0_TABLE[3u];
extern const T_COM_LUT CYCODE COM_TABLE[1u];
extern const uint8 CYCODE COM_SN_STRING_DESCRIPTOR[2];
extern const uint8 CYCODE COM_STRING_DESCRIPTORS[349u];


extern const uint8 CYCODE COM_MSOS_DESCRIPTOR[COM_MSOS_DESCRIPTOR_LENGTH];
extern const uint8 CYCODE COM_MSOS_CONFIGURATION_DESCR[COM_MSOS_CONF_DESCR_LENGTH];
#if defined(COM_ENABLE_IDSN_STRING)
    extern uint8 COM_idSerialNumberStringDescriptor[COM_IDSN_DESCR_LENGTH];
#endif /* (COM_ENABLE_IDSN_STRING) */

extern volatile uint8 COM_interfaceNumber;
extern volatile uint8 COM_interfaceSetting[COM_MAX_INTERFACES_NUMBER];
extern volatile uint8 COM_interfaceSettingLast[COM_MAX_INTERFACES_NUMBER];
extern volatile uint8 COM_deviceAddress;
extern volatile uint8 COM_interfaceStatus[COM_MAX_INTERFACES_NUMBER];
extern const uint8 CYCODE *COM_interfaceClass;

extern volatile T_COM_EP_CTL_BLOCK COM_EP[COM_MAX_EP];
extern volatile T_COM_TD COM_currentTD;

#if (COM_EP_MANAGEMENT_DMA)
    #if (CY_PSOC4)
        extern const uint8 COM_DmaChan[COM_MAX_EP];
    #else
        extern uint8 COM_DmaChan[COM_MAX_EP];
        extern uint8 COM_DmaTd  [COM_MAX_EP];
    #endif /* (CY_PSOC4) */
#endif /* (COM_EP_MANAGEMENT_DMA) */

#if (COM_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    extern uint8  COM_DmaEpBurstCnt   [COM_MAX_EP];
    extern uint8  COM_DmaEpLastBurstEl[COM_MAX_EP];

    extern uint8  COM_DmaEpBurstCntBackup  [COM_MAX_EP];
    extern uint32 COM_DmaEpBufferAddrBackup[COM_MAX_EP];
    
    extern const uint8 COM_DmaReqOut     [COM_MAX_EP];    
    extern const uint8 COM_DmaBurstEndOut[COM_MAX_EP];
#else
    #if (COM_EP_DMA_AUTO_OPT == 0u)
        extern uint8 COM_DmaNextTd[COM_MAX_EP];
        extern volatile uint16 COM_inLength [COM_MAX_EP];
        extern volatile uint8  COM_inBufFull[COM_MAX_EP];
        extern const uint8 COM_epX_TD_TERMOUT_EN[COM_MAX_EP];
        extern const uint8 *COM_inDataPointer[COM_MAX_EP];
    #endif /* (COM_EP_DMA_AUTO_OPT == 0u) */
#endif /* CY_PSOC4 */
#endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */

extern volatile uint8 COM_ep0Toggle;
extern volatile uint8 COM_lastPacketSize;
extern volatile uint8 COM_ep0Mode;
extern volatile uint8 COM_ep0Count;
extern volatile uint16 COM_transferByteCount;


/***************************************
*     Private Function Prototypes
***************************************/
void  COM_ReInitComponent(void)            ;
void  COM_HandleSetup(void)                ;
void  COM_HandleIN(void)                   ;
void  COM_HandleOUT(void)                  ;
void  COM_LoadEP0(void)                    ;
uint8 COM_InitControlRead(void)            ;
uint8 COM_InitControlWrite(void)           ;
void  COM_ControlReadDataStage(void)       ;
void  COM_ControlReadStatusStage(void)     ;
void  COM_ControlReadPrematureStatus(void) ;
uint8 COM_InitControlWrite(void)           ;
uint8 COM_InitZeroLengthControlTransfer(void) ;
void  COM_ControlWriteDataStage(void)      ;
void  COM_ControlWriteStatusStage(void)    ;
void  COM_ControlWritePrematureStatus(void);
uint8 COM_InitNoDataControlTransfer(void)  ;
void  COM_NoDataControlStatusStage(void)   ;
void  COM_InitializeStatusBlock(void)      ;
void  COM_UpdateStatusBlock(uint8 completionCode) ;
uint8 COM_DispatchClassRqst(void)          ;

void COM_Config(uint8 clearAltSetting) ;
void COM_ConfigAltChanged(void)        ;
void COM_ConfigReg(void)               ;
void COM_EpStateInit(void)             ;


const T_COM_LUT CYCODE *COM_GetConfigTablePtr(uint8 confIndex);
const T_COM_LUT CYCODE *COM_GetDeviceTablePtr(void)           ;
#if (COM_BOS_ENABLE)
    const T_COM_LUT CYCODE *COM_GetBOSPtr(void)               ;
#endif /* (COM_BOS_ENABLE) */
const uint8 CYCODE *COM_GetInterfaceClassTablePtr(void)                    ;uint8 COM_ClearEndpointHalt(void)                                          ;
uint8 COM_SetEndpointHalt(void)                                            ;
uint8 COM_ValidateAlternateSetting(void)                                   ;

void COM_SaveConfig(void)      ;
void COM_RestoreConfig(void)   ;

#if (CY_PSOC3 || CY_PSOC5LP)
    #if (COM_EP_MANAGEMENT_DMA_AUTO && (COM_EP_DMA_AUTO_OPT == 0u))
        void COM_LoadNextInEP(uint8 epNumber, uint8 mode)  ;
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO && (COM_EP_DMA_AUTO_OPT == 0u)) */
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

#if defined(COM_ENABLE_IDSN_STRING)
    void COM_ReadDieID(uint8 descr[])  ;
#endif /* COM_ENABLE_IDSN_STRING */

#if defined(COM_ENABLE_HID_CLASS)
    uint8 COM_DispatchHIDClassRqst(void) ;
#endif /* (COM_ENABLE_HID_CLASS) */

#if defined(COM_ENABLE_AUDIO_CLASS)
    uint8 COM_DispatchAUDIOClassRqst(void) ;
#endif /* (COM_ENABLE_AUDIO_CLASS) */

#if defined(COM_ENABLE_CDC_CLASS)
    uint8 COM_DispatchCDCClassRqst(void) ;
#endif /* (COM_ENABLE_CDC_CLASS) */

#if (COM_ENABLE_MSC_CLASS)
    #if (COM_HANDLE_MSC_REQUESTS)
        uint8 COM_DispatchMSCClassRqst(void) ;
    #endif /* (COM_HANDLE_MSC_REQUESTS) */
#endif /* (COM_ENABLE_MSC_CLASS */

CY_ISR_PROTO(COM_EP_0_ISR);
CY_ISR_PROTO(COM_BUS_RESET_ISR);

#if (COM_SOF_ISR_ACTIVE)
    CY_ISR_PROTO(COM_SOF_ISR);
#endif /* (COM_SOF_ISR_ACTIVE) */

#if (COM_EP1_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_1_ISR);
#endif /* (COM_EP1_ISR_ACTIVE) */

#if (COM_EP2_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_2_ISR);
#endif /* (COM_EP2_ISR_ACTIVE) */

#if (COM_EP3_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_3_ISR);
#endif /* (COM_EP3_ISR_ACTIVE) */

#if (COM_EP4_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_4_ISR);
#endif /* (COM_EP4_ISR_ACTIVE) */

#if (COM_EP5_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_5_ISR);
#endif /* (COM_EP5_ISR_ACTIVE) */

#if (COM_EP6_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_6_ISR);
#endif /* (COM_EP6_ISR_ACTIVE) */

#if (COM_EP7_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_7_ISR);
#endif /* (COM_EP7_ISR_ACTIVE) */

#if (COM_EP8_ISR_ACTIVE)
    CY_ISR_PROTO(COM_EP_8_ISR);
#endif /* (COM_EP8_ISR_ACTIVE) */

#if (COM_EP_MANAGEMENT_DMA)
    CY_ISR_PROTO(COM_ARB_ISR);
#endif /* (COM_EP_MANAGEMENT_DMA) */

#if (COM_DP_ISR_ACTIVE)
    CY_ISR_PROTO(COM_DP_ISR);
#endif /* (COM_DP_ISR_ACTIVE) */

#if (CY_PSOC4)
    CY_ISR_PROTO(COM_INTR_HI_ISR);
    CY_ISR_PROTO(COM_INTR_MED_ISR);
    CY_ISR_PROTO(COM_INTR_LO_ISR);
    #if (COM_LPM_ACTIVE)
        CY_ISR_PROTO(COM_LPM_ISR);
    #endif /* (COM_LPM_ACTIVE) */
#endif /* (CY_PSOC4) */

#if (COM_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    #if (COM_DMA1_ACTIVE)
        void COM_EP1_DMA_DONE_ISR(void);
    #endif /* (COM_DMA1_ACTIVE) */

    #if (COM_DMA2_ACTIVE)
        void COM_EP2_DMA_DONE_ISR(void);
    #endif /* (COM_DMA2_ACTIVE) */

    #if (COM_DMA3_ACTIVE)
        void COM_EP3_DMA_DONE_ISR(void);
    #endif /* (COM_DMA3_ACTIVE) */

    #if (COM_DMA4_ACTIVE)
        void COM_EP4_DMA_DONE_ISR(void);
    #endif /* (COM_DMA4_ACTIVE) */

    #if (COM_DMA5_ACTIVE)
        void COM_EP5_DMA_DONE_ISR(void);
    #endif /* (COM_DMA5_ACTIVE) */

    #if (COM_DMA6_ACTIVE)
        void COM_EP6_DMA_DONE_ISR(void);
    #endif /* (COM_DMA6_ACTIVE) */

    #if (COM_DMA7_ACTIVE)
        void COM_EP7_DMA_DONE_ISR(void);
    #endif /* (COM_DMA7_ACTIVE) */

    #if (COM_DMA8_ACTIVE)
        void COM_EP8_DMA_DONE_ISR(void);
    #endif /* (COM_DMA8_ACTIVE) */

#else
    #if (COM_EP_DMA_AUTO_OPT == 0u)
        CY_ISR_PROTO(COM_EP_DMA_DONE_ISR);
    #endif /* (COM_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */


/***************************************
*         Request Handlers
***************************************/

uint8 COM_HandleStandardRqst(void) ;
uint8 COM_DispatchClassRqst(void)  ;
uint8 COM_HandleVendorRqst(void)   ;


/***************************************
*    HID Internal references
***************************************/

#if defined(COM_ENABLE_HID_CLASS)
    void COM_FindReport(void)            ;
    void COM_FindReportDescriptor(void)  ;
    void COM_FindHidClassDecriptor(void) ;
#endif /* COM_ENABLE_HID_CLASS */


/***************************************
*    MIDI Internal references
***************************************/

#if defined(COM_ENABLE_MIDI_STREAMING)
    void COM_MIDI_IN_EP_Service(void)  ;
#endif /* (COM_ENABLE_MIDI_STREAMING) */


/***************************************
*    CDC Internal references
***************************************/

#if defined(COM_ENABLE_CDC_CLASS)

    typedef struct
    {
        uint8  bRequestType;
        uint8  bNotification;
        uint8  wValue;
        uint8  wValueMSB;
        uint8  wIndex;
        uint8  wIndexMSB;
        uint8  wLength;
        uint8  wLengthMSB;
        uint8  wSerialState;
        uint8  wSerialStateMSB;
    } t_COM_cdc_notification;

    uint8 COM_GetInterfaceComPort(uint8 interface) ;
    uint8 COM_Cdc_EpInit( const T_COM_EP_SETTINGS_BLOCK CYCODE *pEP, uint8 epNum, uint8 cdcComNums) ;

    extern volatile uint8  COM_cdc_dataInEpList[COM_MAX_MULTI_COM_NUM];
    extern volatile uint8  COM_cdc_dataOutEpList[COM_MAX_MULTI_COM_NUM];
    extern volatile uint8  COM_cdc_commInEpList[COM_MAX_MULTI_COM_NUM];
#endif /* (COM_ENABLE_CDC_CLASS) */


#endif /* CY_USBFS_COM_pvt_H */


/* [] END OF FILE */
