/***************************************************************************//**
* \file  COM.h
* \version 3.0
*
* \brief
*  This file provides function prototypes and constants for the USBFS component. 
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_USBFS_COM_H)
#define CY_USBFS_COM_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"
#include "CyLib.h"
#include "cyapicallbacks.h"

/*  User supplied definitions. */
/* `#START USER_DEFINITIONS` Place your declaration here */

/* `#END` */

/***************************************
* Enumerated Types and Parameters
***************************************/

/* USB IP memory management options. */
#define COM__EP_MANUAL    (0u)
#define COM__EP_DMAMANUAL (1u)
#define COM__EP_DMAAUTO   (2u)

/* USB IP memory allocation options. */
#define COM__MA_STATIC    (0u)
#define COM__MA_DYNAMIC   (1u)


/***************************************
*    Initial Parameter Constants
***************************************/

#define COM_NUM_DEVICES                        (1u)
#define COM_ENABLE_CDC_CLASS                   
#define COM_ENABLE_MIDI_CLASS                  (0u)
#define COM_ENABLE_MSC_CLASS                   (0u)
#define COM_BOS_ENABLE                         (0u)
#define COM_ENABLE_DESCRIPTOR_STRINGS          
#define COM_ENABLE_SN_STRING                   
#define COM_ENABLE_IDSN_STRING                 
#define COM_ENABLE_STRINGS                     
#define COM_MAX_REPORTID_NUMBER                (0u)

#define COM_MON_VBUS               (0u)
#define COM_EXTERN_VBUS            (1u)
#define COM_POWER_PAD_VBUS         (0u)
#define COM_EXTERN_VND             (0u)
#define COM_EXTERN_CLS             (0u)
#define COM_MAX_INTERFACES_NUMBER  (4u)
#define COM_EP_MM                  (0u)
#define COM_EP_MA                  (0u)
#define COM_ENABLE_BATT_CHARG_DET  (0u)
#define COM_GEN_16BITS_EP_ACCESS   (0u)

/* Enable Class APIs: MIDI, CDC, MSC. */         
#define COM_ENABLE_CDC_CLASS_API   (0u != (1u))

/* General parameters */
#define COM_EP_ALLOC_STATIC            (COM_EP_MA == COM__MA_STATIC)
#define COM_EP_ALLOC_DYNAMIC           (COM_EP_MA == COM__MA_DYNAMIC)
#define COM_EP_MANAGEMENT_MANUAL       (COM_EP_MM == COM__EP_MANUAL)
#define COM_EP_MANAGEMENT_DMA          (COM_EP_MM != COM__EP_MANUAL)
#define COM_EP_MANAGEMENT_DMA_MANUAL   (COM_EP_MM == COM__EP_DMAMANUAL)
#define COM_EP_MANAGEMENT_DMA_AUTO     (COM_EP_MM == COM__EP_DMAAUTO)
#define COM_BATT_CHARG_DET_ENABLE      (CY_PSOC4 && (0u != COM_ENABLE_BATT_CHARG_DET))
#define COM_16BITS_EP_ACCESS_ENABLE    (CY_PSOC4 && (0u != COM_GEN_16BITS_EP_ACCESS))
#define COM_VBUS_MONITORING_ENABLE     (0u != COM_MON_VBUS)
#define COM_VBUS_MONITORING_INTERNAL   (0u == COM_EXTERN_VBUS)
#define COM_VBUS_POWER_PAD_ENABLE      (0u != COM_POWER_PAD_VBUS)

/* Control endpoints availability */
#define COM_SOF_ISR_REMOVE       (1u)
#define COM_BUS_RESET_ISR_REMOVE (0u)
#define COM_EP0_ISR_REMOVE       (0u)
#define COM_ARB_ISR_REMOVE       (0u)
#define COM_DP_ISR_REMOVE        (0u)
#define COM_LPM_REMOVE           (1u)
#define COM_SOF_ISR_ACTIVE       ((0u == COM_SOF_ISR_REMOVE) ? 1u: 0u)
#define COM_BUS_RESET_ISR_ACTIVE ((0u == COM_BUS_RESET_ISR_REMOVE) ? 1u: 0u)
#define COM_EP0_ISR_ACTIVE       ((0u == COM_EP0_ISR_REMOVE) ? 1u: 0u)
#define COM_ARB_ISR_ACTIVE       ((0u == COM_ARB_ISR_REMOVE) ? 1u: 0u)
#define COM_DP_ISR_ACTIVE        ((0u == COM_DP_ISR_REMOVE) ? 1u: 0u)
#define COM_LPM_ACTIVE           ((CY_PSOC4 && (0u == COM_LPM_REMOVE)) ? 1u: 0u)

/* Data endpoints availability */
#define COM_EP1_ISR_REMOVE     (0u)
#define COM_EP2_ISR_REMOVE     (0u)
#define COM_EP3_ISR_REMOVE     (0u)
#define COM_EP4_ISR_REMOVE     (0u)
#define COM_EP5_ISR_REMOVE     (0u)
#define COM_EP6_ISR_REMOVE     (0u)
#define COM_EP7_ISR_REMOVE     (1u)
#define COM_EP8_ISR_REMOVE     (1u)
#define COM_EP1_ISR_ACTIVE     ((0u == COM_EP1_ISR_REMOVE) ? 1u: 0u)
#define COM_EP2_ISR_ACTIVE     ((0u == COM_EP2_ISR_REMOVE) ? 1u: 0u)
#define COM_EP3_ISR_ACTIVE     ((0u == COM_EP3_ISR_REMOVE) ? 1u: 0u)
#define COM_EP4_ISR_ACTIVE     ((0u == COM_EP4_ISR_REMOVE) ? 1u: 0u)
#define COM_EP5_ISR_ACTIVE     ((0u == COM_EP5_ISR_REMOVE) ? 1u: 0u)
#define COM_EP6_ISR_ACTIVE     ((0u == COM_EP6_ISR_REMOVE) ? 1u: 0u)
#define COM_EP7_ISR_ACTIVE     ((0u == COM_EP7_ISR_REMOVE) ? 1u: 0u)
#define COM_EP8_ISR_ACTIVE     ((0u == COM_EP8_ISR_REMOVE) ? 1u: 0u)

#define COM_EP_DMA_AUTO_OPT    ((CY_PSOC4) ? (1u) : (0u))
#define COM_DMA1_REMOVE        (1u)
#define COM_DMA2_REMOVE        (1u)
#define COM_DMA3_REMOVE        (1u)
#define COM_DMA4_REMOVE        (1u)
#define COM_DMA5_REMOVE        (1u)
#define COM_DMA6_REMOVE        (1u)
#define COM_DMA7_REMOVE        (1u)
#define COM_DMA8_REMOVE        (1u)
#define COM_DMA1_ACTIVE        ((0u == COM_DMA1_REMOVE) ? 1u: 0u)
#define COM_DMA2_ACTIVE        ((0u == COM_DMA2_REMOVE) ? 1u: 0u)
#define COM_DMA3_ACTIVE        ((0u == COM_DMA3_REMOVE) ? 1u: 0u)
#define COM_DMA4_ACTIVE        ((0u == COM_DMA4_REMOVE) ? 1u: 0u)
#define COM_DMA5_ACTIVE        ((0u == COM_DMA5_REMOVE) ? 1u: 0u)
#define COM_DMA6_ACTIVE        ((0u == COM_DMA6_REMOVE) ? 1u: 0u)
#define COM_DMA7_ACTIVE        ((0u == COM_DMA7_REMOVE) ? 1u: 0u)
#define COM_DMA8_ACTIVE        ((0u == COM_DMA8_REMOVE) ? 1u: 0u)


/***************************************
*    Data Structures Definition
***************************************/

typedef struct
{
    uint8  attrib;
    uint8  apiEpState;
    uint8  hwEpState;
    uint8  epToggle;
    uint8  addr;
    uint8  epMode;
    uint16 buffOffset;
    uint16 bufferSize;
    uint8  interface;
} T_COM_EP_CTL_BLOCK;

typedef struct
{
    uint8  interface;
    uint8  altSetting;
    uint8  addr;
    uint8  attributes;
    uint16 bufferSize;
    uint8  bMisc;
} T_COM_EP_SETTINGS_BLOCK;

typedef struct
{
    uint8  status;
    uint16 length;
} T_COM_XFER_STATUS_BLOCK;

typedef struct
{
    uint16  count;
    volatile uint8 *pData;
    T_COM_XFER_STATUS_BLOCK *pStatusBlock;
} T_COM_TD;

typedef struct
{
    uint8   c;
    const void *p_list;
} T_COM_LUT;

/* Resume/Suspend API Support */
typedef struct
{
    uint8 enableState;
    uint8 mode;
#if (CY_PSOC4)
    uint8 intrSeiMask;
#endif /* (CY_PSOC4) */
} COM_BACKUP_STRUCT;

/* Number of endpoint 0 data registers. */
#define COM_EP0_DR_MAPPED_REG_CNT  (8u)

/* Structure to access data registers for EP0. */
typedef struct
{
    uint8 epData[COM_EP0_DR_MAPPED_REG_CNT];
} COM_ep0_data_struct;

/* Number of SIE endpoint registers group. */
#define COM_SIE_EP_REG_SIZE   (COM_USB__SIE_EP1_CR0 - \
                                            COM_USB__SIE_EP1_CNT0)

/* Size of gap between SIE endpoint registers groups. */
#define COM_SIE_GAP_CNT        (((COM_USB__SIE_EP2_CNT0 - \
                                             (COM_USB__SIE_EP1_CNT0 + \
                                              COM_SIE_EP_REG_SIZE)) / sizeof(reg8)) - 1u)

/* Structure to access to SIE registers for endpoint. */
typedef struct
{
    uint8 epCnt0;
    uint8 epCnt1;
    uint8 epCr0;
    uint8 gap[COM_SIE_GAP_CNT];
} COM_sie_ep_struct;

/* Number of ARB endpoint registers group. */
#define COM_ARB_EP_REG_SIZE    (COM_USB__ARB_RW1_DR - \
                                             COM_USB__ARB_EP1_CFG)

/* Size of gap between ARB endpoint registers groups. */
#define COM_ARB_GAP_CNT        (((COM_USB__ARB_EP2_CFG - \
                                             (COM_USB__ARB_EP1_CFG + \
                                              COM_ARB_EP_REG_SIZE)) / sizeof(reg8)) - 1u)

/* Structure to access to ARB registers for endpoint. */
typedef struct
{
    uint8 epCfg;
    uint8 epIntEn;
    uint8 epSr;
    uint8 reserved;
    uint8 rwWa;
    uint8 rwWaMsb;
    uint8 rwRa;
    uint8 rwRaMsb;
    uint8 rwDr;
    uint8 gap[COM_ARB_GAP_CNT];
} COM_arb_ep_struct;

#if (CY_PSOC4)
    /* Number of ARB endpoint registers group (16-bits access). */
    #define COM_ARB_EP_REG16_SIZE      (COM_USB__ARB_RW1_DR16 - \
                                                     COM_USB__ARB_RW1_WA16)

    /* Size of gap between ARB endpoint registers groups (16-bits access). */
    #define COM_ARB_EP_REG16_GAP_CNT   (((COM_USB__ARB_RW2_WA16 - \
                                                     (COM_USB__ARB_RW1_WA16 + \
                                                      COM_ARB_EP_REG16_SIZE)) / sizeof(reg8)) - 1u)

    /* Structure to access to ARB registers for endpoint (16-bits access). */
    typedef struct
    {
        uint8 rwWa16;
        uint8 reserved0;
        uint8 rwRa16;
        uint8 reserved1;
        uint8 rwDr16;
        uint8 gap[COM_ARB_EP_REG16_GAP_CNT];
    } COM_arb_ep_reg16_struct;
#endif /* (CY_PSOC4) */

/* Number of endpoint (takes to account that endpoints numbers are 1-8). */
#define COM_NUMBER_EP  (9u)

/* Consoled SIE register groups for endpoints 1-8. */
typedef struct
{
    COM_sie_ep_struct sieEp[COM_NUMBER_EP];
} COM_sie_eps_struct;

/* Consolidate ARB register groups for endpoints 1-8.*/
typedef struct
{
    COM_arb_ep_struct arbEp[COM_NUMBER_EP];
} COM_arb_eps_struct;

#if (CY_PSOC4)
    /* Consolidate ARB register groups for endpoints 1-8 (16-bits access). */
    typedef struct
    {
        COM_arb_ep_reg16_struct arbEp[COM_NUMBER_EP];
    } COM_arb_eps_reg16_struct;
#endif /* (CY_PSOC4) */


/***************************************
*       Function Prototypes
***************************************/
/**
* \addtogroup group_general
* @{
*/
void   COM_InitComponent(uint8 device, uint8 mode) ;
void   COM_Start(uint8 device, uint8 mode)         ;
void   COM_Init(void)                              ;
void   COM_Stop(void)                              ;
uint8  COM_GetConfiguration(void)                  ;
uint8  COM_IsConfigurationChanged(void)            ;
uint8  COM_GetInterfaceSetting(uint8 interfaceNumber) ;
uint8  COM_GetEPState(uint8 epNumber)              ;
uint16 COM_GetEPCount(uint8 epNumber)              ;
void   COM_LoadInEP(uint8 epNumber, const uint8 pData[], uint16 length)
                                                                ;
uint16 COM_ReadOutEP(uint8 epNumber, uint8 pData[], uint16 length)
                                                                ;
void   COM_EnableOutEP(uint8 epNumber)             ;
void   COM_DisableOutEP(uint8 epNumber)            ;
void   COM_Force(uint8 bState)                     ;
uint8  COM_GetEPAckState(uint8 epNumber)           ;
void   COM_SetPowerStatus(uint8 powerStatus)       ;
void   COM_TerminateEP(uint8 epNumber)             ;

uint8 COM_GetDeviceAddress(void) ;

void COM_EnableSofInt(void)  ;
void COM_DisableSofInt(void) ;


#if defined(COM_ENABLE_FWSN_STRING)
    void   COM_SerialNumString(uint8 snString[]) ;
#endif  /* COM_ENABLE_FWSN_STRING */

#if (COM_VBUS_MONITORING_ENABLE)
    uint8  COM_VBusPresent(void) ;
#endif /*  (COM_VBUS_MONITORING_ENABLE) */

#if (COM_16BITS_EP_ACCESS_ENABLE)
    /* PSoC4 specific functions for 16-bit data register access. */
    void   COM_LoadInEP16 (uint8 epNumber, const uint8 pData[], uint16 length);
    uint16 COM_ReadOutEP16(uint8 epNumber,       uint8 pData[], uint16 length);
#endif /* (COM_16BITS_EP_ACCESS_ENABLE) */

#if (COM_BATT_CHARG_DET_ENABLE)
        uint8 COM_Bcd_DetectPortType(void);
#endif /* (COM_BATT_CHARG_DET_ENABLE) */

#if (COM_EP_MANAGEMENT_DMA)
    void COM_InitEP_DMA(uint8 epNumber, const uint8 *pData) ;   
    void COM_Stop_DMA(uint8 epNumber) ;
/** @} general */ 
#endif /* (COM_EP_MANAGEMENT_DMA) */

/**
* \addtogroup group_power
* @{
*/
uint8  COM_CheckActivity(void) ;
void   COM_Suspend(void)       ;
void   COM_Resume(void)        ;
uint8  COM_RWUEnabled(void)    ;

#if (COM_LPM_ACTIVE)
    uint32 COM_Lpm_GetBeslValue(void);
    uint32 COM_Lpm_RemoteWakeUpAllowed(void);
    void   COM_Lpm_SetResponse(uint32 response);
    uint32 COM_Lpm_GetResponse(void);
#endif /* (COM_LPM_ACTIVE) */

/** @} power */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_COM) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))
/**
* \addtogroup group_bootloader
* @{
*/
    void COM_CyBtldrCommStart(void)        ;
    void COM_CyBtldrCommStop(void)         ;
    void COM_CyBtldrCommReset(void)        ;
    cystatus COM_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 *count, uint8 timeOut) CYSMALL
                                                        ;
    cystatus COM_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 *count, uint8 timeOut) CYSMALL
                                                        ;
/** @} bootloader */

    #define COM_BTLDR_OUT_EP   (0x01u)
    #define COM_BTLDR_IN_EP    (0x02u)

    #define COM_BTLDR_SIZEOF_WRITE_BUFFER  (64u)   /* Endpoint 1 (OUT) buffer size. */
    #define COM_BTLDR_SIZEOF_READ_BUFFER   (64u)   /* Endpoint 2 (IN)  buffer size. */
    #define COM_BTLDR_MAX_PACKET_SIZE      COM_BTLDR_SIZEOF_WRITE_BUFFER

    #define COM_BTLDR_WAIT_1_MS            (1u)    /* Time Out quantity equal 1mS */

    /* Map-specific USB bootloader communication functions to common bootloader functions */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_COM)
        #define CyBtldrCommStart        COM_CyBtldrCommStart
        #define CyBtldrCommStop         COM_CyBtldrCommStop
        #define CyBtldrCommReset        COM_CyBtldrCommReset
        #define CyBtldrCommWrite        COM_CyBtldrCommWrite
        #define CyBtldrCommRead         COM_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_COM) */
#endif /* CYDEV_BOOTLOADER_IO_COMP */


/***************************************
*          API Constants
***************************************/

#define COM_EP0                        (0u)
#define COM_EP1                        (1u)
#define COM_EP2                        (2u)
#define COM_EP3                        (3u)
#define COM_EP4                        (4u)
#define COM_EP5                        (5u)
#define COM_EP6                        (6u)
#define COM_EP7                        (7u)
#define COM_EP8                        (8u)
#define COM_MAX_EP                     (9u)

#define COM_TRUE                       (1u)
#define COM_FALSE                      (0u)

#define COM_NO_EVENT_ALLOWED           (2u)
#define COM_EVENT_PENDING              (1u)
#define COM_NO_EVENT_PENDING           (0u)

#define COM_IN_BUFFER_FULL             COM_NO_EVENT_PENDING
#define COM_IN_BUFFER_EMPTY            COM_EVENT_PENDING
#define COM_OUT_BUFFER_FULL            COM_EVENT_PENDING
#define COM_OUT_BUFFER_EMPTY           COM_NO_EVENT_PENDING

#define COM_FORCE_J                    (0xA0u)
#define COM_FORCE_K                    (0x80u)
#define COM_FORCE_SE0                  (0xC0u)
#define COM_FORCE_NONE                 (0x00u)

#define COM_IDLE_TIMER_RUNNING         (0x02u)
#define COM_IDLE_TIMER_EXPIRED         (0x01u)
#define COM_IDLE_TIMER_INDEFINITE      (0x00u)

#define COM_DEVICE_STATUS_BUS_POWERED  (0x00u)
#define COM_DEVICE_STATUS_SELF_POWERED (0x01u)

#define COM_3V_OPERATION               (0x00u)
#define COM_5V_OPERATION               (0x01u)
#define COM_DWR_POWER_OPERATION        (0x02u)

#define COM_MODE_DISABLE               (0x00u)
#define COM_MODE_NAK_IN_OUT            (0x01u)
#define COM_MODE_STATUS_OUT_ONLY       (0x02u)
#define COM_MODE_STALL_IN_OUT          (0x03u)
#define COM_MODE_RESERVED_0100         (0x04u)
#define COM_MODE_ISO_OUT               (0x05u)
#define COM_MODE_STATUS_IN_ONLY        (0x06u)
#define COM_MODE_ISO_IN                (0x07u)
#define COM_MODE_NAK_OUT               (0x08u)
#define COM_MODE_ACK_OUT               (0x09u)
#define COM_MODE_RESERVED_1010         (0x0Au)
#define COM_MODE_ACK_OUT_STATUS_IN     (0x0Bu)
#define COM_MODE_NAK_IN                (0x0Cu)
#define COM_MODE_ACK_IN                (0x0Du)
#define COM_MODE_RESERVED_1110         (0x0Eu)
#define COM_MODE_ACK_IN_STATUS_OUT     (0x0Fu)
#define COM_MODE_MASK                  (0x0Fu)
#define COM_MODE_STALL_DATA_EP         (0x80u)

#define COM_MODE_ACKD                  (0x10u)
#define COM_MODE_OUT_RCVD              (0x20u)
#define COM_MODE_IN_RCVD               (0x40u)
#define COM_MODE_SETUP_RCVD            (0x80u)

#define COM_RQST_TYPE_MASK             (0x60u)
#define COM_RQST_TYPE_STD              (0x00u)
#define COM_RQST_TYPE_CLS              (0x20u)
#define COM_RQST_TYPE_VND              (0x40u)
#define COM_RQST_DIR_MASK              (0x80u)
#define COM_RQST_DIR_D2H               (0x80u)
#define COM_RQST_DIR_H2D               (0x00u)
#define COM_RQST_RCPT_MASK             (0x03u)
#define COM_RQST_RCPT_DEV              (0x00u)
#define COM_RQST_RCPT_IFC              (0x01u)
#define COM_RQST_RCPT_EP               (0x02u)
#define COM_RQST_RCPT_OTHER            (0x03u)

#if (COM_LPM_ACTIVE)
    #define COM_LPM_REQ_ACK            (0x01u << COM_LPM_CTRL_LPM_ACK_RESP_POS)
    #define COM_LPM_REQ_NACK           (0x00u)
    #define COM_LPM_REQ_NYET           (0x01u << COM_LPM_CTRL_NYET_EN_POS)
#endif /*(COM_LPM_ACTIVE)*/

/* USB Class Codes */
#define COM_CLASS_DEVICE               (0x00u)     /* Use class code info from Interface Descriptors */
#define COM_CLASS_AUDIO                (0x01u)     /* Audio device */
#define COM_CLASS_CDC                  (0x02u)     /* Communication device class */
#define COM_CLASS_HID                  (0x03u)     /* Human Interface Device */
#define COM_CLASS_PDC                  (0x05u)     /* Physical device class */
#define COM_CLASS_IMAGE                (0x06u)     /* Still Imaging device */
#define COM_CLASS_PRINTER              (0x07u)     /* Printer device  */
#define COM_CLASS_MSD                  (0x08u)     /* Mass Storage device  */
#define COM_CLASS_HUB                  (0x09u)     /* Full/Hi speed Hub */
#define COM_CLASS_CDC_DATA             (0x0Au)     /* CDC data device */
#define COM_CLASS_SMART_CARD           (0x0Bu)     /* Smart Card device */
#define COM_CLASS_CSD                  (0x0Du)     /* Content Security device */
#define COM_CLASS_VIDEO                (0x0Eu)     /* Video device */
#define COM_CLASS_PHD                  (0x0Fu)     /* Personal Health care device */
#define COM_CLASS_WIRELESSD            (0xDCu)     /* Wireless Controller */
#define COM_CLASS_MIS                  (0xE0u)     /* Miscellaneous */
#define COM_CLASS_APP                  (0xEFu)     /* Application Specific */
#define COM_CLASS_VENDOR               (0xFFu)     /* Vendor specific */

/* Standard Request Types (Table 9-4) */
#define COM_GET_STATUS                 (0x00u)
#define COM_CLEAR_FEATURE              (0x01u)
#define COM_SET_FEATURE                (0x03u)
#define COM_SET_ADDRESS                (0x05u)
#define COM_GET_DESCRIPTOR             (0x06u)
#define COM_SET_DESCRIPTOR             (0x07u)
#define COM_GET_CONFIGURATION          (0x08u)
#define COM_SET_CONFIGURATION          (0x09u)
#define COM_GET_INTERFACE              (0x0Au)
#define COM_SET_INTERFACE              (0x0Bu)
#define COM_SYNCH_FRAME                (0x0Cu)

/* Vendor Specific Request Types */
/* Request for Microsoft OS String Descriptor */
#define COM_GET_EXTENDED_CONFIG_DESCRIPTOR (0x01u)

/* Descriptor Types (Table 9-5) */
#define COM_DESCR_DEVICE                   (1u)
#define COM_DESCR_CONFIG                   (2u)
#define COM_DESCR_STRING                   (3u)
#define COM_DESCR_INTERFACE                (4u)
#define COM_DESCR_ENDPOINT                 (5u)
#define COM_DESCR_DEVICE_QUALIFIER         (6u)
#define COM_DESCR_OTHER_SPEED              (7u)
#define COM_DESCR_INTERFACE_POWER          (8u)
#if (COM_BOS_ENABLE)
    #define COM_DESCR_BOS                  (15u)
#endif /* (COM_BOS_ENABLE) */
/* Device Descriptor Defines */
#define COM_DEVICE_DESCR_LENGTH            (18u)
#define COM_DEVICE_DESCR_SN_SHIFT          (16u)

/* Config Descriptor Shifts and Masks */
#define COM_CONFIG_DESCR_LENGTH                (0u)
#define COM_CONFIG_DESCR_TYPE                  (1u)
#define COM_CONFIG_DESCR_TOTAL_LENGTH_LOW      (2u)
#define COM_CONFIG_DESCR_TOTAL_LENGTH_HI       (3u)
#define COM_CONFIG_DESCR_NUM_INTERFACES        (4u)
#define COM_CONFIG_DESCR_CONFIG_VALUE          (5u)
#define COM_CONFIG_DESCR_CONFIGURATION         (6u)
#define COM_CONFIG_DESCR_ATTRIB                (7u)
#define COM_CONFIG_DESCR_ATTRIB_SELF_POWERED   (0x40u)
#define COM_CONFIG_DESCR_ATTRIB_RWU_EN         (0x20u)

#if (COM_BOS_ENABLE)
    /* Config Descriptor BOS */
    #define COM_BOS_DESCR_LENGTH               (0u)
    #define COM_BOS_DESCR_TYPE                 (1u)
    #define COM_BOS_DESCR_TOTAL_LENGTH_LOW     (2u)
    #define COM_BOS_DESCR_TOTAL_LENGTH_HI      (3u)
    #define COM_BOS_DESCR_NUM_DEV_CAPS         (4u)
#endif /* (COM_BOS_ENABLE) */

/* Feature Selectors (Table 9-6) */
#define COM_DEVICE_REMOTE_WAKEUP           (0x01u)
#define COM_ENDPOINT_HALT                  (0x00u)
#define COM_TEST_MODE                      (0x02u)

/* USB Device Status (Figure 9-4) */
#define COM_DEVICE_STATUS_BUS_POWERED      (0x00u)
#define COM_DEVICE_STATUS_SELF_POWERED     (0x01u)
#define COM_DEVICE_STATUS_REMOTE_WAKEUP    (0x02u)

/* USB Endpoint Status (Figure 9-4) */
#define COM_ENDPOINT_STATUS_HALT           (0x01u)

/* USB Endpoint Directions */
#define COM_DIR_IN                         (0x80u)
#define COM_DIR_OUT                        (0x00u)
#define COM_DIR_UNUSED                     (0x7Fu)

/* USB Endpoint Attributes */
#define COM_EP_TYPE_CTRL                   (0x00u)
#define COM_EP_TYPE_ISOC                   (0x01u)
#define COM_EP_TYPE_BULK                   (0x02u)
#define COM_EP_TYPE_INT                    (0x03u)
#define COM_EP_TYPE_MASK                   (0x03u)

#define COM_EP_SYNC_TYPE_NO_SYNC           (0x00u)
#define COM_EP_SYNC_TYPE_ASYNC             (0x04u)
#define COM_EP_SYNC_TYPE_ADAPTIVE          (0x08u)
#define COM_EP_SYNC_TYPE_SYNCHRONOUS       (0x0Cu)
#define COM_EP_SYNC_TYPE_MASK              (0x0Cu)

#define COM_EP_USAGE_TYPE_DATA             (0x00u)
#define COM_EP_USAGE_TYPE_FEEDBACK         (0x10u)
#define COM_EP_USAGE_TYPE_IMPLICIT         (0x20u)
#define COM_EP_USAGE_TYPE_RESERVED         (0x30u)
#define COM_EP_USAGE_TYPE_MASK             (0x30u)

/* Point Status defines */
#define COM_EP_STATUS_LENGTH               (0x02u)

/* Point Device defines */
#define COM_DEVICE_STATUS_LENGTH           (0x02u)

#define COM_STATUS_LENGTH_MAX \
                 ((COM_EP_STATUS_LENGTH > COM_DEVICE_STATUS_LENGTH) ? \
                        COM_EP_STATUS_LENGTH : COM_DEVICE_STATUS_LENGTH)

/* Transfer Completion Notification */
#define COM_XFER_IDLE                      (0x00u)
#define COM_XFER_STATUS_ACK                (0x01u)
#define COM_XFER_PREMATURE                 (0x02u)
#define COM_XFER_ERROR                     (0x03u)

/* Driver State defines */
#define COM_TRANS_STATE_IDLE               (0x00u)
#define COM_TRANS_STATE_CONTROL_READ       (0x02u)
#define COM_TRANS_STATE_CONTROL_WRITE      (0x04u)
#define COM_TRANS_STATE_NO_DATA_CONTROL    (0x06u)

/* String Descriptor defines */
#define COM_STRING_MSOS                    (0xEEu)
#define COM_MSOS_DESCRIPTOR_LENGTH         (18u)
#define COM_MSOS_CONF_DESCR_LENGTH         (40u)

/* Return values */
#define COM_BCD_PORT_SDP       (1u) /* Standard downstream port detected */
#define COM_BCD_PORT_CDP       (2u) /* Charging downstream port detected */
#define COM_BCD_PORT_DCP       (3u) /* Dedicated charging port detected */
#define COM_BCD_PORT_UNKNOWN   (0u) /* Unable to detect charging port */
#define COM_BCD_PORT_ERR       (4u) /* Error condition in detection process*/


/* Timeouts for BCD */
#define COM_BCD_TIMEOUT                (400u)  /* Copied from PBK#163 TIMEOUT (300 ms) */
#define COM_BCD_TDCD_DBNC              (10u)  /*BCD v1.2: DCD debounce time 10 ms*/
#define COM_BCD_PRIMARY_WAIT           (40u)   /* Copied from PBK#163 TIMEOUT (40 ms)  */
#define COM_BCD_SECONDARY_WAIT         (47u)   /* Copied from PBK#163 TIMEOUT (40 ms)  */
#define COM_BCD_SUSPEND_DISABLE_WAIT   (2u)    /* Copied from PBK#163 TIMEOUT (2 us)   */

/* Wait cycles required before clearing SUSPEND_DEL in POWER_CTRL: 2us */
#define COM_WAIT_SUSPEND_DEL_DISABLE   (2u)

/* Wait cycles required for USB regulator stabilization after it is enabled : 50ns */
#define COM_WAIT_VREF_STABILITY        (0u)

#if (CY_PSOC3 || CY_PSOC5LP)
/* Wait cycles required for USB reference restore: 40us */
#define COM_WAIT_VREF_RESTORE          (40u)

/* Wait cycles required for stabilization after register is written : 50ns */
#define COM_WAIT_REG_STABILITY_50NS    (0u)
#define COM_WAIT_REG_STABILITY_1US     (1u)

/* Wait cycles required after CR0 register write: 1 cycle */
#define COM_WAIT_CR0_REG_STABILITY     (1u)

/* Wait cycles required after PD_PULLUP_N bit is set in PM_USB_CR0: 2us */
#define COM_WAIT_PD_PULLUP_N_ENABLE    (2u)
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

#if (CY_PSOC4)
    #if (COM_EP_MANAGEMENT_DMA)
        #define COM_DMA_DESCR0         (0u)
        #define COM_DMA_DESCR1         (1u)
    #endif /* (COM_EP_MANAGEMENT_DMA) */

    #if (COM_EP_MANAGEMENT_DMA_AUTO)
        /* BUF_SIZE-BYTES_PER_BURST examples: 0x55 - 32 bytes, 0x44 - 16 bytes, 0x33 - 8 bytes, etc. */
        #define COM_DMA_BUF_SIZE             (0x55u)
        #define COM_DMA_BYTES_PER_BURST      (32u)
        #define COM_DMA_HALFWORDS_PER_BURST  (16u)
        #define COM_DMA_BURST_BYTES_MASK     (COM_DMA_BYTES_PER_BURST - 1u)

        #define COM_DMA_DESCR0_MASK        (0x00u)
        #define COM_DMA_DESCR1_MASK        (0x80u)
        #define COM_DMA_DESCR_REVERT       (0x40u)
        #define COM_DMA_DESCR_16BITS       (0x20u)
        #define COM_DMA_DESCR_SHIFT        (7u)

        #define COM_DMA_GET_DESCR_NUM(desrc)
        #define COM_DMA_GET_BURST_CNT(dmaBurstCnt) \
                    (((((dmaBurstCnt) - 2u) >> 1u) + ((dmaBurstCnt) & 0x1u)) - 1u)

        #define COM_DMA_GET_MAX_ELEM_PER_BURST(dmaLastBurstEl) \
                    ((0u != ((dmaLastBurstEl) & COM_DMA_DESCR_16BITS)) ? \
                                (COM_DMA_HALFWORDS_PER_BURST - 1u) : (COM_DMA_BYTES_PER_BURST - 1u))
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
#else
    #if (COM_EP_MANAGEMENT_DMA_MANUAL)
        #define COM_DMA_BYTES_PER_BURST    (0u)
        #define COM_DMA_REQUEST_PER_BURST  (0u)
    #endif /* (COM_EP_MANAGEMENT_DMA_MANUAL) */

    #if (COM_EP_MANAGEMENT_DMA_AUTO)
        #define COM_DMA_BYTES_PER_BURST    (32u)
        #define COM_DMA_BYTES_REPEAT       (2u)

        /* BUF_SIZE-BYTES_PER_BURST examples: 0x55 - 32 bytes, 0x44 - 16 bytes, 0x33 - 8 bytes, etc. */
        #define COM_DMA_BUF_SIZE           (0x55u)
        #define COM_DMA_REQUEST_PER_BURST  (1u)

        #define COM_EP17_SR_MASK           (0x7Fu)
        #define COM_EP8_SR_MASK            (0x03u)
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
#endif /* (CY_PSOC4) */

/* DIE ID string descriptor defines */
#if defined(COM_ENABLE_IDSN_STRING)
    #define COM_IDSN_DESCR_LENGTH      (0x22u)
#endif /* (COM_ENABLE_IDSN_STRING) */


/***************************************
*     Vars with External Linkage
***************************************/

/**
* \addtogroup group_globals
* @{
*/
extern uint8 COM_initVar;
extern volatile uint8 COM_device;
extern volatile uint8 COM_transferState;
extern volatile uint8 COM_configuration;
extern volatile uint8 COM_configurationChanged;
extern volatile uint8 COM_deviceStatus;
/** @} globals */

/**
* \addtogroup group_hid
* @{
*/
/* HID Variables */
#if defined(COM_ENABLE_HID_CLASS)
    extern volatile uint8 COM_hidProtocol [COM_MAX_INTERFACES_NUMBER]; 
    extern volatile uint8 COM_hidIdleRate [COM_MAX_INTERFACES_NUMBER];
    extern volatile uint8 COM_hidIdleTimer[COM_MAX_INTERFACES_NUMBER];
#endif /* (COM_ENABLE_HID_CLASS) */
/** @} hid */


/***************************************
*              Registers
***************************************/

/* Common registers for all PSoCs: 3/4/5LP */
#define COM_ARB_CFG_PTR        ( (reg8 *) COM_USB__ARB_CFG)
#define COM_ARB_CFG_REG        (*(reg8 *) COM_USB__ARB_CFG)

#define COM_ARB_EP1_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP1_CFG)
#define COM_ARB_EP1_CFG_REG    (*(reg8 *) COM_USB__ARB_EP1_CFG)
#define COM_ARB_EP1_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP1_INT_EN)
#define COM_ARB_EP1_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP1_INT_EN)
#define COM_ARB_EP1_SR_PTR     ( (reg8 *) COM_USB__ARB_EP1_SR)
#define COM_ARB_EP1_SR_REG     (*(reg8 *) COM_USB__ARB_EP1_SR)
#define COM_ARB_EP1_CFG_IND    COM_USB__ARB_EP1_CFG
#define COM_ARB_EP1_INT_EN_IND COM_USB__ARB_EP1_INT_EN
#define COM_ARB_EP1_SR_IND     COM_USB__ARB_EP1_SR
#define COM_ARB_EP_BASE        (*(volatile COM_arb_eps_struct CYXDATA *) \
                                            (COM_USB__ARB_EP1_CFG - sizeof(COM_arb_ep_struct)))

#define COM_ARB_EP2_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP2_CFG)
#define COM_ARB_EP2_CFG_REG    (*(reg8 *) COM_USB__ARB_EP2_CFG)
#define COM_ARB_EP2_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP2_INT_EN)
#define COM_ARB_EP2_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP2_INT_EN)
#define COM_ARB_EP2_SR_PTR     ( (reg8 *) COM_USB__ARB_EP2_SR)
#define COM_ARB_EP2_SR_REG     (*(reg8 *) COM_USB__ARB_EP2_SR)

#define COM_ARB_EP3_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP3_CFG)
#define COM_ARB_EP3_CFG_REG    (*(reg8 *) COM_USB__ARB_EP3_CFG)
#define COM_ARB_EP3_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP3_INT_EN)
#define COM_ARB_EP3_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP3_INT_EN)
#define COM_ARB_EP3_SR_PTR     ( (reg8 *) COM_USB__ARB_EP3_SR)
#define COM_ARB_EP3_SR_REG     (*(reg8 *) COM_USB__ARB_EP3_SR)

#define COM_ARB_EP4_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP4_CFG)
#define COM_ARB_EP4_CFG_REG    (*(reg8 *) COM_USB__ARB_EP4_CFG)
#define COM_ARB_EP4_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP4_INT_EN)
#define COM_ARB_EP4_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP4_INT_EN)
#define COM_ARB_EP4_SR_PTR     ( (reg8 *) COM_USB__ARB_EP4_SR)
#define COM_ARB_EP4_SR_REG     (*(reg8 *) COM_USB__ARB_EP4_SR)

#define COM_ARB_EP5_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP5_CFG)
#define COM_ARB_EP5_CFG_REG    (*(reg8 *) COM_USB__ARB_EP5_CFG)
#define COM_ARB_EP5_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP5_INT_EN)
#define COM_ARB_EP5_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP5_INT_EN)
#define COM_ARB_EP5_SR_PTR     ( (reg8 *) COM_USB__ARB_EP5_SR)
#define COM_ARB_EP5_SR_REG     (*(reg8 *) COM_USB__ARB_EP5_SR)

#define COM_ARB_EP6_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP6_CFG)
#define COM_ARB_EP6_CFG_REG    (*(reg8 *) COM_USB__ARB_EP6_CFG)
#define COM_ARB_EP6_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP6_INT_EN)
#define COM_ARB_EP6_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP6_INT_EN)
#define COM_ARB_EP6_SR_PTR     ( (reg8 *) COM_USB__ARB_EP6_SR)
#define COM_ARB_EP6_SR_REG     (*(reg8 *) COM_USB__ARB_EP6_SR)

#define COM_ARB_EP7_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP7_CFG)
#define COM_ARB_EP7_CFG_REG    (*(reg8 *) COM_USB__ARB_EP7_CFG)
#define COM_ARB_EP7_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP7_INT_EN)
#define COM_ARB_EP7_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP7_INT_EN)
#define COM_ARB_EP7_SR_PTR     ( (reg8 *) COM_USB__ARB_EP7_SR)
#define COM_ARB_EP7_SR_REG     (*(reg8 *) COM_USB__ARB_EP7_SR)

#define COM_ARB_EP8_CFG_PTR    ( (reg8 *) COM_USB__ARB_EP8_CFG)
#define COM_ARB_EP8_CFG_REG    (*(reg8 *) COM_USB__ARB_EP8_CFG)
#define COM_ARB_EP8_INT_EN_PTR ( (reg8 *) COM_USB__ARB_EP8_INT_EN)
#define COM_ARB_EP8_INT_EN_REG (*(reg8 *) COM_USB__ARB_EP8_INT_EN)
#define COM_ARB_EP8_SR_PTR     ( (reg8 *) COM_USB__ARB_EP8_SR)
#define COM_ARB_EP8_SR_REG     (*(reg8 *) COM_USB__ARB_EP8_SR)

#define COM_ARB_INT_EN_PTR     ( (reg8 *) COM_USB__ARB_INT_EN)
#define COM_ARB_INT_EN_REG     (*(reg8 *) COM_USB__ARB_INT_EN)
#define COM_ARB_INT_SR_PTR     ( (reg8 *) COM_USB__ARB_INT_SR)
#define COM_ARB_INT_SR_REG     (*(reg8 *) COM_USB__ARB_INT_SR)

#define COM_ARB_RW1_DR_PTR     ( (reg8 *) COM_USB__ARB_RW1_DR)
#define COM_ARB_RW1_RA_PTR     ( (reg8 *) COM_USB__ARB_RW1_RA)

#define COM_ARB_RW1_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW1_RA_MSB)
#define COM_ARB_RW1_WA_PTR     ( (reg8 *) COM_USB__ARB_RW1_WA)
#define COM_ARB_RW1_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW1_WA_MSB)
#define COM_ARB_RW1_DR_IND     COM_USB__ARB_RW1_DR
#define COM_ARB_RW1_RA_IND     COM_USB__ARB_RW1_RA
#define COM_ARB_RW1_RA_MSB_IND COM_USB__ARB_RW1_RA_MSB
#define COM_ARB_RW1_WA_IND     COM_USB__ARB_RW1_WA
#define COM_ARB_RW1_WA_MSB_IND COM_USB__ARB_RW1_WA_MSB

#define COM_ARB_RW2_DR_PTR     ( (reg8 *) COM_USB__ARB_RW2_DR)
#define COM_ARB_RW2_RA_PTR     ( (reg8 *) COM_USB__ARB_RW2_RA)
#define COM_ARB_RW2_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW2_RA_MSB)
#define COM_ARB_RW2_WA_PTR     ( (reg8 *) COM_USB__ARB_RW2_WA)
#define COM_ARB_RW2_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW2_WA_MSB)

#define COM_ARB_RW3_DR_PTR     ( (reg8 *) COM_USB__ARB_RW3_DR)
#define COM_ARB_RW3_RA_PTR     ( (reg8 *) COM_USB__ARB_RW3_RA)
#define COM_ARB_RW3_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW3_RA_MSB)
#define COM_ARB_RW3_WA_PTR     ( (reg8 *) COM_USB__ARB_RW3_WA)
#define COM_ARB_RW3_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW3_WA_MSB)

#define COM_ARB_RW4_DR_PTR     ( (reg8 *) COM_USB__ARB_RW4_DR)
#define COM_ARB_RW4_RA_PTR     ( (reg8 *) COM_USB__ARB_RW4_RA)
#define COM_ARB_RW4_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW4_RA_MSB)
#define COM_ARB_RW4_WA_PTR     ( (reg8 *) COM_USB__ARB_RW4_WA)
#define COM_ARB_RW4_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW4_WA_MSB)

#define COM_ARB_RW5_DR_PTR     ( (reg8 *) COM_USB__ARB_RW5_DR)
#define COM_ARB_RW5_RA_PTR     ( (reg8 *) COM_USB__ARB_RW5_RA)
#define COM_ARB_RW5_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW5_RA_MSB)
#define COM_ARB_RW5_WA_PTR     ( (reg8 *) COM_USB__ARB_RW5_WA)
#define COM_ARB_RW5_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW5_WA_MSB)

#define COM_ARB_RW6_DR_PTR     ( (reg8 *) COM_USB__ARB_RW6_DR)
#define COM_ARB_RW6_RA_PTR     ( (reg8 *) COM_USB__ARB_RW6_RA)
#define COM_ARB_RW6_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW6_RA_MSB)
#define COM_ARB_RW6_WA_PTR     ( (reg8 *) COM_USB__ARB_RW6_WA)
#define COM_ARB_RW6_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW6_WA_MSB)

#define COM_ARB_RW7_DR_PTR     ( (reg8 *) COM_USB__ARB_RW7_DR)
#define COM_ARB_RW7_RA_PTR     ( (reg8 *) COM_USB__ARB_RW7_RA)
#define COM_ARB_RW7_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW7_RA_MSB)
#define COM_ARB_RW7_WA_PTR     ( (reg8 *) COM_USB__ARB_RW7_WA)
#define COM_ARB_RW7_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW7_WA_MSB)

#define COM_ARB_RW8_DR_PTR     ( (reg8 *) COM_USB__ARB_RW8_DR)
#define COM_ARB_RW8_RA_PTR     ( (reg8 *) COM_USB__ARB_RW8_RA)
#define COM_ARB_RW8_RA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW8_RA_MSB)
#define COM_ARB_RW8_WA_PTR     ( (reg8 *) COM_USB__ARB_RW8_WA)
#define COM_ARB_RW8_WA_MSB_PTR ( (reg8 *) COM_USB__ARB_RW8_WA_MSB)

#define COM_BUF_SIZE_PTR       ( (reg8 *) COM_USB__BUF_SIZE)
#define COM_BUF_SIZE_REG       (*(reg8 *) COM_USB__BUF_SIZE)
#define COM_BUS_RST_CNT_PTR    ( (reg8 *) COM_USB__BUS_RST_CNT)
#define COM_BUS_RST_CNT_REG    (*(reg8 *) COM_USB__BUS_RST_CNT)
#define COM_CWA_PTR            ( (reg8 *) COM_USB__CWA)
#define COM_CWA_REG            (*(reg8 *) COM_USB__CWA)
#define COM_CWA_MSB_PTR        ( (reg8 *) COM_USB__CWA_MSB)
#define COM_CWA_MSB_REG        (*(reg8 *) COM_USB__CWA_MSB)
#define COM_CR0_PTR            ( (reg8 *) COM_USB__CR0)
#define COM_CR0_REG            (*(reg8 *) COM_USB__CR0)
#define COM_CR1_PTR            ( (reg8 *) COM_USB__CR1)
#define COM_CR1_REG            (*(reg8 *) COM_USB__CR1)

#define COM_DMA_THRES_PTR      ( (reg8 *) COM_USB__DMA_THRES)
#define COM_DMA_THRES_REG      (*(reg8 *) COM_USB__DMA_THRES)
#define COM_DMA_THRES_MSB_PTR  ( (reg8 *) COM_USB__DMA_THRES_MSB)
#define COM_DMA_THRES_MSB_REG  (*(reg8 *) COM_USB__DMA_THRES_MSB)

#define COM_EP_ACTIVE_PTR      ( (reg8 *) COM_USB__EP_ACTIVE)
#define COM_EP_ACTIVE_REG      (*(reg8 *) COM_USB__EP_ACTIVE)
#define COM_EP_TYPE_PTR        ( (reg8 *) COM_USB__EP_TYPE)
#define COM_EP_TYPE_REG        (*(reg8 *) COM_USB__EP_TYPE)

#define COM_EP0_CNT_PTR        ( (reg8 *) COM_USB__EP0_CNT)
#define COM_EP0_CNT_REG        (*(reg8 *) COM_USB__EP0_CNT)
#define COM_EP0_CR_PTR         ( (reg8 *) COM_USB__EP0_CR)
#define COM_EP0_CR_REG         (*(reg8 *) COM_USB__EP0_CR)
#define COM_EP0_DR0_PTR        ( (reg8 *) COM_USB__EP0_DR0)
#define COM_EP0_DR0_REG        (*(reg8 *) COM_USB__EP0_DR0)
#define COM_EP0_DR1_PTR        ( (reg8 *) COM_USB__EP0_DR1)
#define COM_EP0_DR1_REG        (*(reg8 *) COM_USB__EP0_DR1)
#define COM_EP0_DR2_PTR        ( (reg8 *) COM_USB__EP0_DR2)
#define COM_EP0_DR2_REG        (*(reg8 *) COM_USB__EP0_DR2)
#define COM_EP0_DR3_PTR        ( (reg8 *) COM_USB__EP0_DR3)
#define COM_EP0_DR3_REG        (*(reg8 *) COM_USB__EP0_DR3)
#define COM_EP0_DR4_PTR        ( (reg8 *) COM_USB__EP0_DR4)
#define COM_EP0_DR4_REG        (*(reg8 *) COM_USB__EP0_DR4)
#define COM_EP0_DR5_PTR        ( (reg8 *) COM_USB__EP0_DR5)
#define COM_EP0_DR5_REG        (*(reg8 *) COM_USB__EP0_DR5)
#define COM_EP0_DR6_PTR        ( (reg8 *) COM_USB__EP0_DR6)
#define COM_EP0_DR6_REG        (*(reg8 *) COM_USB__EP0_DR6)
#define COM_EP0_DR7_PTR        ( (reg8 *) COM_USB__EP0_DR7)
#define COM_EP0_DR7_REG        (*(reg8 *) COM_USB__EP0_DR7)
#define COM_EP0_DR0_IND        COM_USB__EP0_DR0
#define COM_EP0_DR_BASE        (*(volatile COM_ep0_data_struct CYXDATA *) COM_USB__EP0_DR0)

#define COM_OSCLK_DR0_PTR      ( (reg8 *) COM_USB__OSCLK_DR0)
#define COM_OSCLK_DR0_REG      (*(reg8 *) COM_USB__OSCLK_DR0)
#define COM_OSCLK_DR1_PTR      ( (reg8 *) COM_USB__OSCLK_DR1)
#define COM_OSCLK_DR1_REG      (*(reg8 *) COM_USB__OSCLK_DR1)

#define COM_SIE_EP_INT_EN_PTR  ( (reg8 *) COM_USB__SIE_EP_INT_EN)
#define COM_SIE_EP_INT_EN_REG  (*(reg8 *) COM_USB__SIE_EP_INT_EN)
#define COM_SIE_EP_INT_SR_PTR  ( (reg8 *) COM_USB__SIE_EP_INT_SR)
#define COM_SIE_EP_INT_SR_REG  (*(reg8 *) COM_USB__SIE_EP_INT_SR)

#define COM_SIE_EP1_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP1_CNT0)
#define COM_SIE_EP1_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP1_CNT0)
#define COM_SIE_EP1_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP1_CNT1)
#define COM_SIE_EP1_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP1_CNT1)
#define COM_SIE_EP1_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP1_CR0)
#define COM_SIE_EP1_CR0_REG    (*(reg8 *) COM_USB__SIE_EP1_CR0)
#define COM_SIE_EP1_CNT1_IND   COM_USB__SIE_EP1_CNT1
#define COM_SIE_EP1_CNT0_IND   COM_USB__SIE_EP1_CNT0
#define COM_SIE_EP1_CR0_IND    COM_USB__SIE_EP1_CR0
#define COM_SIE_EP_BASE        (*(volatile COM_sie_eps_struct CYXDATA *) \
                                            (COM_USB__SIE_EP1_CNT0 - sizeof(COM_sie_ep_struct)))

#define COM_SIE_EP2_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP2_CNT0)
#define COM_SIE_EP2_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP2_CNT0)
#define COM_SIE_EP2_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP2_CNT1)
#define COM_SIE_EP2_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP2_CNT1)
#define COM_SIE_EP2_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP2_CR0)
#define COM_SIE_EP2_CR0_REG    (*(reg8 *) COM_USB__SIE_EP2_CR0)

#define COM_SIE_EP3_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP3_CNT0)
#define COM_SIE_EP3_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP3_CNT0)
#define COM_SIE_EP3_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP3_CNT1)
#define COM_SIE_EP3_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP3_CNT1)
#define COM_SIE_EP3_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP3_CR0)
#define COM_SIE_EP3_CR0_REG    (*(reg8 *) COM_USB__SIE_EP3_CR0)

#define COM_SIE_EP4_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP4_CNT0)
#define COM_SIE_EP4_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP4_CNT0)
#define COM_SIE_EP4_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP4_CNT1)
#define COM_SIE_EP4_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP4_CNT1)
#define COM_SIE_EP4_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP4_CR0)
#define COM_SIE_EP4_CR0_REG    (*(reg8 *) COM_USB__SIE_EP4_CR0)

#define COM_SIE_EP5_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP5_CNT0)
#define COM_SIE_EP5_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP5_CNT0)
#define COM_SIE_EP5_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP5_CNT1)
#define COM_SIE_EP5_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP5_CNT1)
#define COM_SIE_EP5_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP5_CR0)
#define COM_SIE_EP5_CR0_REG    (*(reg8 *) COM_USB__SIE_EP5_CR0)

#define COM_SIE_EP6_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP6_CNT0)
#define COM_SIE_EP6_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP6_CNT0)
#define COM_SIE_EP6_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP6_CNT1)
#define COM_SIE_EP6_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP6_CNT1)
#define COM_SIE_EP6_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP6_CR0)
#define COM_SIE_EP6_CR0_REG    (*(reg8 *) COM_USB__SIE_EP6_CR0)

#define COM_SIE_EP7_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP7_CNT0)
#define COM_SIE_EP7_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP7_CNT0)
#define COM_SIE_EP7_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP7_CNT1)
#define COM_SIE_EP7_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP7_CNT1)
#define COM_SIE_EP7_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP7_CR0)
#define COM_SIE_EP7_CR0_REG    (*(reg8 *) COM_USB__SIE_EP7_CR0)

#define COM_SIE_EP8_CNT0_PTR   ( (reg8 *) COM_USB__SIE_EP8_CNT0)
#define COM_SIE_EP8_CNT0_REG   (*(reg8 *) COM_USB__SIE_EP8_CNT0)
#define COM_SIE_EP8_CNT1_PTR   ( (reg8 *) COM_USB__SIE_EP8_CNT1)
#define COM_SIE_EP8_CNT1_REG   (*(reg8 *) COM_USB__SIE_EP8_CNT1)
#define COM_SIE_EP8_CR0_PTR    ( (reg8 *) COM_USB__SIE_EP8_CR0)
#define COM_SIE_EP8_CR0_REG    (*(reg8 *) COM_USB__SIE_EP8_CR0)

#define COM_SOF0_PTR           ( (reg8 *) COM_USB__SOF0)
#define COM_SOF0_REG           (*(reg8 *) COM_USB__SOF0)
#define COM_SOF1_PTR           ( (reg8 *) COM_USB__SOF1)
#define COM_SOF1_REG           (*(reg8 *) COM_USB__SOF1)

#define COM_USB_CLK_EN_PTR     ( (reg8 *) COM_USB__USB_CLK_EN)
#define COM_USB_CLK_EN_REG     (*(reg8 *) COM_USB__USB_CLK_EN)

#define COM_USBIO_CR0_PTR      ( (reg8 *) COM_USB__USBIO_CR0)
#define COM_USBIO_CR0_REG      (*(reg8 *) COM_USB__USBIO_CR0)
#define COM_USBIO_CR1_PTR      ( (reg8 *) COM_USB__USBIO_CR1)
#define COM_USBIO_CR1_REG      (*(reg8 *) COM_USB__USBIO_CR1)

#define COM_DYN_RECONFIG_PTR   ( (reg8 *) COM_USB__DYN_RECONFIG)
#define COM_DYN_RECONFIG_REG   (*(reg8 *) COM_USB__DYN_RECONFIG)

#if (CY_PSOC4)
    #define COM_ARB_RW1_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW1_RA16)
    #define COM_ARB_RW1_RA16_REG   (*(reg32 *) COM_cy_m0s8_usb__ARB_RW1_RA16)
    #define COM_ARB_RW1_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW1_WA16)
    #define COM_ARB_RW1_WA16_REG   (*(reg32 *) COM_cy_m0s8_usb__ARB_RW1_WA16)
    #define COM_ARB_RW1_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW1_DR16)
    #define COM_ARB_RW1_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW1_DR16)
    #define COM_ARB_EP16_BASE      (*(volatile COM_arb_eps_reg16_struct CYXDATA *) \
                                                (COM_USB__ARB_RW1_WA16 - sizeof(COM_arb_ep_reg16_struct)))

    #define COM_ARB_RW2_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW2_DR16)
    #define COM_ARB_RW2_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW2_RA16)
    #define COM_ARB_RW2_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW2_WA16)

    #define COM_ARB_RW3_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW3_DR16)
    #define COM_ARB_RW3_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW3_RA16)
    #define COM_ARB_RW3_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW3_WA16)

    #define COM_ARB_RW4_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW4_DR16)
    #define COM_ARB_RW4_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW4_RA16)
    #define COM_ARB_RW4_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW4_WA16)

    #define COM_ARB_RW5_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW5_DR16)
    #define COM_ARB_RW5_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW5_RA16)
    #define COM_ARB_RW5_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW5_WA16)

    #define COM_ARB_RW6_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW6_DR16)
    #define COM_ARB_RW6_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW6_RA16)
    #define COM_ARB_RW6_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW6_WA16)

    #define COM_ARB_RW7_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW7_DR16)
    #define COM_ARB_RW7_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW7_RA16)
    #define COM_ARB_RW7_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW7_WA16)

    #define COM_ARB_RW8_DR16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW8_DR16)
    #define COM_ARB_RW8_RA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW8_RA16)
    #define COM_ARB_RW8_WA16_PTR   ( (reg32 *) COM_cy_m0s8_usb__ARB_RW8_WA16)

    #define COM_OSCLK_DR16_PTR     ( (reg32 *) COM_cy_m0s8_usb__OSCLK_DR16)
    #define COM_OSCLK_DR16_REG     (*(reg32 *) COM_cy_m0s8_usb__OSCLK_DR16)

    #define COM_SOF16_PTR          ( (reg32 *) COM_cy_m0s8_usb__SOF16)
    #define COM_SOF16_REG          (*(reg32 *) COM_cy_m0s8_usb__SOF16)
    
    #define COM_CWA16_PTR          ( (reg32 *) COM_cy_m0s8_usb__CWA16)
    #define COM_CWA16_REG          (*(reg32 *) COM_cy_m0s8_usb__CWA16)

    #define COM_DMA_THRES16_PTR    ( (reg32 *) COM_cy_m0s8_usb__DMA_THRES16)
    #define COM_DMA_THRES16_REG    (*(reg32 *) COM_cy_m0s8_usb__DMA_THRES16)

    #define COM_USB_CLK_EN_PTR     ( (reg32 *) COM_cy_m0s8_usb__USB_CLK_EN)
    #define COM_USB_CLK_EN_REG     (*(reg32 *) COM_cy_m0s8_usb__USB_CLK_EN)

    #define COM_USBIO_CR2_PTR      ( (reg32 *) COM_cy_m0s8_usb__USBIO_CR2)
    #define COM_USBIO_CR2_REG      (*(reg32 *) COM_cy_m0s8_usb__USBIO_CR2)

    #define COM_USB_MEM            ( (reg32 *) COM_cy_m0s8_usb__MEM_DATA0)

    #define COM_POWER_CTRL_REG      (*(reg32 *) COM_cy_m0s8_usb__USB_POWER_CTRL)
    #define COM_POWER_CTRL_PTR      ( (reg32 *) COM_cy_m0s8_usb__USB_POWER_CTRL)

    #define COM_CHGDET_CTRL_REG     (*(reg32 *) COM_cy_m0s8_usb__USB_CHGDET_CTRL)
    #define COM_CHGDET_CTRL_PTR     ( (reg32 *) COM_cy_m0s8_usb__USB_CHGDET_CTRL)

    #define COM_USBIO_CTRL_REG      (*(reg32 *) COM_cy_m0s8_usb__USB_USBIO_CTRL)
    #define COM_USBIO_CTRL_PTR      ( (reg32 *) COM_cy_m0s8_usb__USB_USBIO_CTRL)

    #define COM_FLOW_CTRL_REG       (*(reg32 *) COM_cy_m0s8_usb__USB_FLOW_CTRL)
    #define COM_FLOW_CTRL_PTR       ( (reg32 *) COM_cy_m0s8_usb__USB_FLOW_CTRL)

    #define COM_LPM_CTRL_REG        (*(reg32 *) COM_cy_m0s8_usb__USB_LPM_CTRL)
    #define COM_LPM_CTRL_PTR        ( (reg32 *) COM_cy_m0s8_usb__USB_LPM_CTRL)

    #define COM_LPM_STAT_REG        (*(reg32 *) COM_cy_m0s8_usb__USB_LPM_STAT)
    #define COM_LPM_STAT_PTR        ( (reg32 *) COM_cy_m0s8_usb__USB_LPM_STAT)

    #define COM_PHY_CONTROL_REG     (*(reg32 *) COM_cy_m0s8_usb__USB_PHY_CONTROL)
    #define COM_PHY_CONTROL_PTR     ( (reg32 *) COM_cy_m0s8_usb__USB_PHY_CONTROL)

    #define COM_INTR_SIE_REG        (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE)
    #define COM_INTR_SIE_PTR        ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE)

    #define COM_INTR_SIE_SET_REG    (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE_SET)
    #define COM_INTR_SIE_SET_PTR    ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE_SET)

    #define COM_INTR_SIE_MASK_REG   (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE_MASK)
    #define COM_INTR_SIE_MASK_PTR   ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE_MASK)

    #define COM_INTR_SIE_MASKED_REG (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE_MASKED)
    #define COM_INTR_SIE_MASKED_PTR ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_SIE_MASKED)

    #define COM_INTR_LVL_SEL_REG    (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_LVL_SEL)
    #define COM_INTR_LVL_SEL_PTR    ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_LVL_SEL)

    #define COM_INTR_CAUSE_HI_REG   (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_CAUSE_HI)
    #define COM_INTR_CAUSE_HI_PTR   ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_CAUSE_HI)

    #define COM_INTR_CAUSE_LO_REG   (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_CAUSE_LO)
    #define COM_INTR_CAUSE_LO_PTR   ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_CAUSE_LO)

    #define COM_INTR_CAUSE_MED_REG  (*(reg32 *) COM_cy_m0s8_usb__USB_INTR_CAUSE_MED)
    #define COM_INTR_CAUSE_MED_PTR  ( (reg32 *) COM_cy_m0s8_usb__USB_INTR_CAUSE_MED)

    #define COM_DFT_CTRL_REG        (*(reg32 *) COM_cy_m0s8_usb__USB_DFT_CTRL)
    #define COM_DFT_CTRL_PTR        ( (reg32 *) COM_cy_m0s8_usb__USB_DFT_CTRL)

    #if (COM_VBUS_MONITORING_ENABLE)
        #if (COM_VBUS_POWER_PAD_ENABLE)
            /* Vbus power pad pin is hard wired to P13[2] */
            #define COM_VBUS_STATUS_REG    (*(reg32 *) CYREG_GPIO_PRT13_PS)
            #define COM_VBUS_STATUS_PTR    ( (reg32 *) CYREG_GPIO_PRT13_PS)
            #define COM_VBUS_VALID         (0x04u)
        #else
            /* Vbus valid pin is hard wired to P0[0] */
            #define COM_VBUS_STATUS_REG    (*(reg32 *) CYREG_GPIO_PRT0_PS)
            #define COM_VBUS_STATUS_PTR    ( (reg32 *) CYREG_GPIO_PRT0_PS)
            #define COM_VBUS_VALID         (0x01u)
        #endif
    #endif /*(COM_VBUS_MONITORING_ENABLE) */

    #define COM_BURSTEND_0_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND0_TR_OUTPUT)
    #define COM_BURSTEND_1_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND1_TR_OUTPUT)
    #define COM_BURSTEND_2_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND2_TR_OUTPUT)
    #define COM_BURSTEND_3_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND3_TR_OUTPUT)
    #define COM_BURSTEND_4_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND4_TR_OUTPUT)
    #define COM_BURSTEND_5_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND5_TR_OUTPUT)
    #define COM_BURSTEND_6_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND6_TR_OUTPUT)
    #define COM_BURSTEND_7_TR_OUTPUT    (COM_cy_m0s8_usb__BURSTEND7_TR_OUTPUT)
    
#else /* (CY_PSOC3 || CY_PSOC5LP) */

    /* COM_PM_USB_CR0 */
    #define COM_PM_USB_CR0_PTR     ( (reg8 *) CYREG_PM_USB_CR0)
    #define COM_PM_USB_CR0_REG     (*(reg8 *) CYREG_PM_USB_CR0)

    /* COM_PM_ACT/STBY_CFG */
    #define COM_PM_ACT_CFG_PTR     ( (reg8 *) COM_USB__PM_ACT_CFG)
    #define COM_PM_ACT_CFG_REG     (*(reg8 *) COM_USB__PM_ACT_CFG)
    #define COM_PM_STBY_CFG_PTR    ( (reg8 *) COM_USB__PM_STBY_CFG)
    #define COM_PM_STBY_CFG_REG    (*(reg8 *) COM_USB__PM_STBY_CFG)

    #if (!CY_PSOC5LP)
        #define COM_USBIO_CR2_PTR  (  (reg8 *) COM_USB__USBIO_CR2)
        #define COM_USBIO_CR2_REG  (* (reg8 *) COM_USB__USBIO_CR2)
    #endif /* (!CY_PSOC5LP) */

    /* COM_USB_MEM - USB IP memory buffer */
    #define COM_USB_MEM            ((reg8 *) CYDEV_USB_MEM_BASE)

    #if (COM_VBUS_MONITORING_ENABLE)
        #if (COM_VBUS_MONITORING_INTERNAL)
            #define COM_VBUS_STATUS_REG    (*(reg8 *) COM_VBUS__PS)
            #define COM_VBUS_STATUS_PTR    ( (reg8 *) COM_VBUS__PS)
            #define COM_VBUS_VALID         (COM_VBUS__MASK)
        #else
            #define COM_VBUS_STATUS_REG    (*(reg8 *) COM_Vbus_ps_sts_sts_reg__STATUS_REG)
            #define COM_VBUS_STATUS_PTR    ( (reg8 *) COM_Vbus_ps_sts_sts_reg__STATUS_REG)
            #define COM_VBUS_VALID         (COM_Vbus_ps_sts_sts_reg__MASK)
        #endif /* (COM_VBUS_MONITORING_INTERNAL) */
    #endif /*(COM_VBUS_MONITORING_ENABLE) */
#endif /* (CY_PSOC4) */


/***************************************
*       Interrupt source constants
***************************************/

#define COM_DP_INTC_PRIORITY       COM_dp_int__INTC_PRIOR_NUM
#define COM_DP_INTC_VECT_NUM       COM_dp_int__INTC_NUMBER

#if (CY_PSOC4)
    #define COM_DMA_AUTO_INTR_PRIO (0u)
    
    #define COM_INTR_HI_PRIORITY   COM_high_int__INTC_PRIOR_NUM
    #define COM_INTR_HI_VECT_NUM   COM_high_int__INTC_NUMBER

    #define COM_INTR_MED_PRIORITY  COM_med_int__INTC_PRIOR_NUM
    #define COM_INTR_MED_VECT_NUM  COM_med_int__INTC_NUMBER

    #define COM_INTR_LO_PRIORITY   COM_lo_int__INTC_PRIOR_NUM
    #define COM_INTR_LO_VECT_NUM   COM_lo_int__INTC_NUMBER

    /* Interrupt sources in COM_isrCallbacks[] table */
    #define COM_SOF_INTR_NUM       (0u)
    #define COM_BUS_RESET_INT_NUM  (1u)
    #define COM_EP0_INTR_NUM       (2u)
    #define COM_LPM_INTR_NUM       (3u)
    #define COM_ARB_EP_INTR_NUM    (4u)
    #define COM_EP1_INTR_NUM       (5u)
    #define COM_EP2_INTR_NUM       (6u)
    #define COM_EP3_INTR_NUM       (7u)
    #define COM_EP4_INTR_NUM       (8u)
    #define COM_EP5_INTR_NUM       (9u)
    #define COM_EP6_INTR_NUM       (10u)
    #define COM_EP7_INTR_NUM       (11u)
    #define COM_EP8_INTR_NUM       (12u)

#else
    #define COM_BUS_RESET_PRIOR    COM_bus_reset__INTC_PRIOR_NUM
    #define COM_BUS_RESET_MASK     COM_bus_reset__INTC_MASK
    #define COM_BUS_RESET_VECT_NUM COM_bus_reset__INTC_NUMBER

    #define COM_SOF_PRIOR          COM_sof_int__INTC_PRIOR_NUM
    #define COM_SOF_MASK           COM_sof_int__INTC_MASK
    #define COM_SOF_VECT_NUM       COM_sof_int__INTC_NUMBER

    #define COM_EP_0_PRIOR         COM_ep_0__INTC_PRIOR_NUM
    #define COM_EP_0_MASK          COM_ep_0__INTC_MASK
    #define COM_EP_0_VECT_NUM      COM_ep_0__INTC_NUMBER

    #define COM_EP_1_PRIOR         COM_ep_1__INTC_PRIOR_NUM
    #define COM_EP_1_MASK          COM_ep_1__INTC_MASK
    #define COM_EP_1_VECT_NUM      COM_ep_1__INTC_NUMBER

    #define COM_EP_2_PRIOR         COM_ep_2__INTC_PRIOR_NUM
    #define COM_EP_2_MASK          COM_ep_2__INTC_MASK
    #define COM_EP_2_VECT_NUM      COM_ep_2__INTC_NUMBER

    #define COM_EP_3_PRIOR         COM_ep_3__INTC_PRIOR_NUM
    #define COM_EP_3_MASK          COM_ep_3__INTC_MASK
    #define COM_EP_3_VECT_NUM      COM_ep_3__INTC_NUMBER

    #define COM_EP_4_PRIOR         COM_ep_4__INTC_PRIOR_NUM
    #define COM_EP_4_MASK          COM_ep_4__INTC_MASK
    #define COM_EP_4_VECT_NUM      COM_ep_4__INTC_NUMBER

    #define COM_EP_5_PRIOR         COM_ep_5__INTC_PRIOR_NUM
    #define COM_EP_5_MASK          COM_ep_5__INTC_MASK
    #define COM_EP_5_VECT_NUM      COM_ep_5__INTC_NUMBER

    #define COM_EP_6_PRIOR         COM_ep_6__INTC_PRIOR_NUM
    #define COM_EP_6_MASK          COM_ep_6__INTC_MASK
    #define COM_EP_6_VECT_NUM      COM_ep_6__INTC_NUMBER

    #define COM_EP_7_PRIOR         COM_ep_7__INTC_PRIOR_NUM
    #define COM_EP_7_MASK          COM_ep_7__INTC_MASK
    #define COM_EP_7_VECT_NUM      COM_ep_7__INTC_NUMBER

    #define COM_EP_8_PRIOR         COM_ep_8__INTC_PRIOR_NUM
    #define COM_EP_8_MASK          COM_ep_8__INTC_MASK
    #define COM_EP_8_VECT_NUM      COM_ep_8__INTC_NUMBER

    /* Set ARB ISR priority 0 to be highest for all EPX ISRs. */
    #define COM_ARB_PRIOR          (0u)
    #define COM_ARB_MASK           COM_arb_int__INTC_MASK
    #define COM_ARB_VECT_NUM       COM_arb_int__INTC_NUMBER
#endif /* (CY_PSOC4) */


/***************************************
*       Endpoint 0 offsets (Table 9-2)
***************************************/
#define COM_bmRequestTypeReg      COM_EP0_DR_BASE.epData[0u]
#define COM_bRequestReg           COM_EP0_DR_BASE.epData[1u]
#define COM_wValueLoReg           COM_EP0_DR_BASE.epData[2u]
#define COM_wValueHiReg           COM_EP0_DR_BASE.epData[3u]
#define COM_wIndexLoReg           COM_EP0_DR_BASE.epData[4u]
#define COM_wIndexHiReg           COM_EP0_DR_BASE.epData[5u]
#define COM_wLengthLoReg          COM_EP0_DR_BASE.epData[6u]
#define COM_wLengthHiReg          COM_EP0_DR_BASE.epData[7u]

/* Compatibility defines */
#define COM_lengthLoReg           COM_EP0_DR_BASE.epData[6u]
#define COM_lengthHiReg           COM_EP0_DR_BASE.epData[7u]


/***************************************
*       Register Constants
***************************************/

#define COM_3500MV     (3500u)
#if (CY_PSOC4)
    #define COM_VDDD_MV    (CYDEV_VBUS_MV)
#else
    #define COM_VDDD_MV    (CYDEV_VDDD_MV)
#endif /* (CY_PSOC4) */


/* COM_USB_CLK */
#define COM_USB_CLK_CSR_CLK_EN_POS (0u)
#define COM_USB_CLK_CSR_CLK_EN     ((uint8) ((uint8) 0x1u << COM_USB_CLK_CSR_CLK_EN_POS))
#define COM_USB_CLK_ENABLE         (COM_USB_CLK_CSR_CLK_EN)

/* COM_CR0 */
#define COM_CR0_DEVICE_ADDRESS_POS     (0u)
#define COM_CR0_ENABLE_POS             (7u)
#define COM_CR0_DEVICE_ADDRESS_MASK    ((uint8) ((uint8) 0x7Fu << COM_CR0_DEVICE_ADDRESS_POS))
#define COM_CR0_ENABLE                 ((uint8) ((uint8) 0x01u << COM_CR0_ENABLE_POS))


/* COM_CR1 */
#define COM_CR1_REG_ENABLE_POS         (0u)
#define COM_CR1_ENABLE_LOCK_POS        (1u)
#define COM_CR1_BUS_ACTIVITY_POS       (2u)
#define COM_CR1_TRIM_OFFSET_MSB_POS    (3u)
#define COM_CR1_REG_ENABLE             ((uint8) ((uint8) 0x1u << COM_CR1_REG_ENABLE_POS))
#define COM_CR1_ENABLE_LOCK            ((uint8) ((uint8) 0x1u << COM_CR1_ENABLE_LOCK_POS))
#define COM_CR1_BUS_ACTIVITY           ((uint8) ((uint8) 0x1u << COM_CR1_BUS_ACTIVITY_POS))
#define COM_CR1_TRIM_OFFSET_MSB        ((uint8) ((uint8) 0x1u << COM_CR1_TRIM_OFFSET_MSB_POS))

/* COM_EPX_CNT */
#define COM_EP0_CNT_DATA_TOGGLE        (0x80u)
#define COM_EPX_CNT_DATA_TOGGLE        (0x80u)
#define COM_EPX_CNT0_MASK              (0x0Fu)
#define COM_EPX_CNTX_MSB_MASK          (0x07u)
#define COM_EPX_CNTX_ADDR_SHIFT        (0x04u)
#define COM_EPX_CNTX_ADDR_OFFSET       (0x10u)
#define COM_EPX_CNTX_CRC_COUNT         (0x02u)
#define COM_EPX_DATA_BUF_MAX           (512u)

/* COM_USBIO_CR0 */

#define COM_USBIO_CR0_TEN              (0x80u)
#define COM_USBIO_CR0_TSE0             (0x40u)
#define COM_USBIO_CR0_TD               (0x20u)
#define COM_USBIO_CR0_RD               (0x01u)

/* COM_USBIO_CR1 */
#define COM_USBIO_CR1_DM0_POS      (0u)
#define COM_USBIO_CR1_DP0_POS      (1u)
#define COM_USBIO_CR1_USBPUEN_POS  (2u)
#define COM_USBIO_CR1_IOMODE_POS   (5u)
#define COM_USBIO_CR1_DM0          ((uint8) ((uint8) 0x1u << COM_USBIO_CR1_DM0_POS))
#define COM_USBIO_CR1_DP0          ((uint8) ((uint8) 0x1u << COM_USBIO_CR1_DP0_POS))
#define COM_USBIO_CR1_USBPUEN      ((uint8) ((uint8) 0x1u << COM_USBIO_CR1_USBPUEN_POS))
#define COM_USBIO_CR1_IOMODE       ((uint8) ((uint8) 0x1u << COM_USBIO_CR1_IOMODE_POS))

/* COM_FASTCLK_IMO_CR */
#define COM_FASTCLK_IMO_CR_USBCLK_ON   (0x40u)
#define COM_FASTCLK_IMO_CR_XCLKEN      (0x20u)
#define COM_FASTCLK_IMO_CR_FX2ON       (0x10u)

/* COM_ARB_EPX_CFG */
#define COM_ARB_EPX_CFG_IN_DATA_RDY_POS    (0u)
#define COM_ARB_EPX_CFG_DMA_REQ_POS        (1u)
#define COM_ARB_EPX_CFG_CRC_BYPASS_POS     (2u)
#define COM_ARB_EPX_CFG_RESET_POS          (3u)
#define COM_ARB_EPX_CFG_IN_DATA_RDY        ((uint8) ((uint8) 0x1u << COM_ARB_EPX_CFG_IN_DATA_RDY_POS))
#define COM_ARB_EPX_CFG_DMA_REQ            ((uint8) ((uint8) 0x1u << COM_ARB_EPX_CFG_DMA_REQ_POS))
#define COM_ARB_EPX_CFG_CRC_BYPASS         ((uint8) ((uint8) 0x1u << COM_ARB_EPX_CFG_CRC_BYPASS_POS))
#define COM_ARB_EPX_CFG_RESET              ((uint8) ((uint8) 0x1u << COM_ARB_EPX_CFG_RESET_POS))

/* COM_ARB_EPX_INT / SR */
#define COM_ARB_EPX_INT_IN_BUF_FULL_POS    (0u)
#define COM_ARB_EPX_INT_DMA_GNT_POS        (1u)
#define COM_ARB_EPX_INT_BUF_OVER_POS       (2u)
#define COM_ARB_EPX_INT_BUF_UNDER_POS      (3u)
#define COM_ARB_EPX_INT_ERR_INT_POS        (4u)
#define COM_ARB_EPX_INT_IN_BUF_FULL        ((uint8) ((uint8) 0x1u << COM_ARB_EPX_INT_IN_BUF_FULL_POS))
#define COM_ARB_EPX_INT_DMA_GNT            ((uint8) ((uint8) 0x1u << COM_ARB_EPX_INT_DMA_GNT_POS))
#define COM_ARB_EPX_INT_BUF_OVER           ((uint8) ((uint8) 0x1u << COM_ARB_EPX_INT_BUF_OVER_POS))
#define COM_ARB_EPX_INT_BUF_UNDER          ((uint8) ((uint8) 0x1u << COM_ARB_EPX_INT_BUF_UNDER_POS))
#define COM_ARB_EPX_INT_ERR_INT            ((uint8) ((uint8) 0x1u << COM_ARB_EPX_INT_ERR_INT_POS))

#if (CY_PSOC4)
#define COM_ARB_EPX_INT_DMA_TERMIN_POS     (5u)
#define COM_ARB_EPX_INT_DMA_TERMIN         ((uint8) ((uint8) 0x1u << COM_ARB_EPX_INT_DMA_TERMIN_POS))
#endif /* (CY_PSOC4) */

/* Common arbiter interrupt sources for all PSoC devices. */
#define COM_ARB_EPX_INT_COMMON    (COM_ARB_EPX_INT_IN_BUF_FULL | \
                                                COM_ARB_EPX_INT_DMA_GNT     | \
                                                COM_ARB_EPX_INT_BUF_OVER    | \
                                                COM_ARB_EPX_INT_BUF_UNDER   | \
                                                COM_ARB_EPX_INT_ERR_INT)

#if (CY_PSOC4)
    #define COM_ARB_EPX_INT_ALL    (COM_ARB_EPX_INT_COMMON | COM_ARB_EPX_INT_DMA_TERMIN)
#else
    #define COM_ARB_EPX_INT_ALL    (COM_ARB_EPX_INT_COMMON)
#endif /* (CY_PSOC4) */

/* COM_ARB_CFG */
#define COM_ARB_CFG_AUTO_MEM_POS   (4u)
#define COM_ARB_CFG_DMA_CFG_POS    (5u)
#define COM_ARB_CFG_CFG_CMP_POS    (7u)
#define COM_ARB_CFG_AUTO_MEM       ((uint8) ((uint8) 0x1u << COM_ARB_CFG_AUTO_MEM_POS))
#define COM_ARB_CFG_DMA_CFG_MASK   ((uint8) ((uint8) 0x3u << COM_ARB_CFG_DMA_CFG_POS))
#define COM_ARB_CFG_DMA_CFG_NONE   ((uint8) ((uint8) 0x0u << COM_ARB_CFG_DMA_CFG_POS))
#define COM_ARB_CFG_DMA_CFG_MANUAL ((uint8) ((uint8) 0x1u << COM_ARB_CFG_DMA_CFG_POS))
#define COM_ARB_CFG_DMA_CFG_AUTO   ((uint8) ((uint8) 0x2u << COM_ARB_CFG_DMA_CFG_POS))
#define COM_ARB_CFG_CFG_CMP        ((uint8) ((uint8) 0x1u << COM_ARB_CFG_CFG_CMP_POS))

/* COM_DYN_RECONFIG */
#define COM_DYN_RECONFIG_EP_SHIFT      (1u)
#define COM_DYN_RECONFIG_ENABLE_POS    (0u)
#define COM_DYN_RECONFIG_EPNO_POS      (1u)
#define COM_DYN_RECONFIG_RDY_STS_POS   (4u)
#define COM_DYN_RECONFIG_ENABLE        ((uint8) ((uint8) 0x1u << COM_DYN_RECONFIG_ENABLE_POS))
#define COM_DYN_RECONFIG_EPNO_MASK     ((uint8) ((uint8) 0x7u << COM_DYN_RECONFIG_EPNO_POS))
#define COM_DYN_RECONFIG_RDY_STS       ((uint8) ((uint8) 0x1u << COM_DYN_RECONFIG_RDY_STS_POS))

/* COM_ARB_INT */
#define COM_ARB_INT_EP1_INTR_POS          (0u) /* [0] Interrupt for USB EP1 */
#define COM_ARB_INT_EP2_INTR_POS          (1u) /* [1] Interrupt for USB EP2 */
#define COM_ARB_INT_EP3_INTR_POS          (2u) /* [2] Interrupt for USB EP3 */
#define COM_ARB_INT_EP4_INTR_POS          (3u) /* [3] Interrupt for USB EP4 */
#define COM_ARB_INT_EP5_INTR_POS          (4u) /* [4] Interrupt for USB EP5 */
#define COM_ARB_INT_EP6_INTR_POS          (5u) /* [5] Interrupt for USB EP6 */
#define COM_ARB_INT_EP7_INTR_POS          (6u) /* [6] Interrupt for USB EP7 */
#define COM_ARB_INT_EP8_INTR_POS          (7u) /* [7] Interrupt for USB EP8 */
#define COM_ARB_INT_EP1_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP1_INTR_POS))
#define COM_ARB_INT_EP2_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP2_INTR_POS))
#define COM_ARB_INT_EP3_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP3_INTR_POS))
#define COM_ARB_INT_EP4_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP4_INTR_POS))
#define COM_ARB_INT_EP5_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP5_INTR_POS))
#define COM_ARB_INT_EP6_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP6_INTR_POS))
#define COM_ARB_INT_EP7_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP7_INTR_POS))
#define COM_ARB_INT_EP8_INTR              ((uint8) ((uint8) 0x1u << COM_ARB_INT_EP8_INTR_POS))

/* COM_SIE_INT */
#define COM_SIE_INT_EP1_INTR_POS          (0u) /* [0] Interrupt for USB EP1 */
#define COM_SIE_INT_EP2_INTR_POS          (1u) /* [1] Interrupt for USB EP2 */
#define COM_SIE_INT_EP3_INTR_POS          (2u) /* [2] Interrupt for USB EP3 */
#define COM_SIE_INT_EP4_INTR_POS          (3u) /* [3] Interrupt for USB EP4 */
#define COM_SIE_INT_EP5_INTR_POS          (4u) /* [4] Interrupt for USB EP5 */
#define COM_SIE_INT_EP6_INTR_POS          (5u) /* [5] Interrupt for USB EP6 */
#define COM_SIE_INT_EP7_INTR_POS          (6u) /* [6] Interrupt for USB EP7 */
#define COM_SIE_INT_EP8_INTR_POS          (7u) /* [7] Interrupt for USB EP8 */
#define COM_SIE_INT_EP1_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP1_INTR_POS))
#define COM_SIE_INT_EP2_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP2_INTR_POS))
#define COM_SIE_INT_EP3_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP3_INTR_POS))
#define COM_SIE_INT_EP4_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP4_INTR_POS))
#define COM_SIE_INT_EP5_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP5_INTR_POS))
#define COM_SIE_INT_EP6_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP6_INTR_POS))
#define COM_SIE_INT_EP7_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP7_INTR_POS))
#define COM_SIE_INT_EP8_INTR              ((uint8) ((uint8) 0x01u << COM_SIE_INT_EP8_INTR_POS))

#if (CY_PSOC4)
    /* COM_POWER_CTRL_REG */
    #define COM_POWER_CTRL_VBUS_VALID_OVR_POS       (0u)  /* [0] */
    #define COM_POWER_CTRL_SUSPEND_POS              (2u)  /* [1] */
    #define COM_POWER_CTRL_SUSPEND_DEL_POS          (3u)  /* [3] */
    #define COM_POWER_CTRL_ISOLATE_POS              (4u)  /* [4] */
    #define COM_POWER_CTRL_CHDET_PWR_CTL_POS        (5u)  /* [5] */
    #define COM_POWER_CTRL_ENABLE_DM_PULLDOWN_POS   (25u) /* [25] */
    #define COM_POWER_CTRL_ENABLE_VBUS_PULLDOWN_POS (26u) /* [26] */
    #define COM_POWER_CTRL_ENABLE_RCVR_POS          (27u) /* [27] */
    #define COM_POWER_CTRL_ENABLE_DPO_POS           (28u) /* [28] */
    #define COM_POWER_CTRL_ENABLE_DMO_POS           (29u) /* [29] */
    #define COM_POWER_CTRL_ENABLE_CHGDET_POS        (30u) /* [30] */
    #define COM_POWER_CTRL_ENABLE_POS               (31u) /* [31] */
    #define COM_POWER_CTRL_VBUS_VALID_OVR_MASK      ((uint32) 0x03u << COM_POWER_CTRL_VBUS_VALID_OVR_POS)
    #define COM_POWER_CTRL_VBUS_VALID_OVR_0         ((uint32) 0x00u << COM_POWER_CTRL_VBUS_VALID_OVR_POS)
    #define COM_POWER_CTRL_VBUS_VALID_OVR_1         ((uint32) 0x01u << COM_POWER_CTRL_VBUS_VALID_OVR_POS)
    #define COM_POWER_CTRL_VBUS_VALID_OVR_GPIO      ((uint32) 0x02u << COM_POWER_CTRL_VBUS_VALID_OVR_POS)
    #define COM_POWER_CTRL_VBUS_VALID_OVR_PHY       ((uint32) 0x03u << COM_POWER_CTRL_VBUS_VALID_OVR_POS)
    #define COM_POWER_CTRL_SUSPEND                  ((uint32) 0x01u << COM_POWER_CTRL_SUSPEND_POS)
    #define COM_POWER_CTRL_SUSPEND_DEL              ((uint32) 0x01u << COM_POWER_CTRL_SUSPEND_DEL_POS)
    #define COM_POWER_CTRL_ISOLATE                  ((uint32) 0x01u << COM_POWER_CTRL_ISOLATE_POS)
    #define COM_POWER_CTRL_CHDET_PWR_CTL_MASK       ((uint32) 0x03u << COM_POWER_CTRL_CHDET_PWR_CTL_POS)
    #define COM_POWER_CTRL_ENABLE_DM_PULLDOWN       ((uint32) 0x01u << COM_POWER_CTRL_ENABLE_DM_PULLDOWN_POS)
    #define COM_POWER_CTRL_ENABLE_VBUS_PULLDOWN     ((uint32) 0x01u << COM_POWER_CTRL_ENABLE_VBUS_PULLDOWN_POS)
    #define COM_POWER_CTRL_ENABLE_RCVR              ((uint32) 0x01u << COM_POWER_CTRL_ENABLE_RCVR_POS)
    #define COM_POWER_CTRL_ENABLE_DPO               ((uint32) 0x01u << COM_POWER_CTRL_ENABLE_DPO_POS)
    #define COM_POWER_CTRL_ENABLE_DMO               ((uint32) 0x01u << COM_POWER_CTRL_ENABLE_DMO_POS)
    #define COM_POWER_CTRL_ENABLE_CHGDET            ((uint32) 0x01u << COM_POWER_CTRL_ENABLE_CHGDET_POS)
    #define COM_POWER_CTRL_ENABLE                   ((uint32) 0x01u << COM_POWER_CTRL_ENABLE_POS)

    /* COM_CHGDET_CTRL_REG */
    #define COM_CHGDET_CTRL_COMP_DP_POS        (0u)  /* [0] */
    #define COM_CHGDET_CTRL_COMP_DM_POS        (1u)  /* [1] */
    #define COM_CHGDET_CTRL_COMP_EN_POS        (2u)  /* [2] */
    #define COM_CHGDET_CTRL_REF_DP_POS         (3u)  /* [3] */
    #define COM_CHGDET_CTRL_REF_DM_POS         (4u)  /* [4] */
    #define COM_CHGDET_CTRL_REF_EN_POS         (5u)  /* [5] */
    #define COM_CHGDET_CTRL_DCD_SRC_EN_POS     (6u)  /* [6] */
    #define COM_CHGDET_CTRL_ADFT_CTRL_POS      (12u) /* [12] */
    #define COM_CHGDET_CTRL_COMP_OUT_POS       (31u) /* [31] */
    #define COM_CHGDET_CTRL_COMP_DP            ((uint32) 0x01u << COM_CHGDET_CTRL_COMP_DP_POS)
    #define COM_CHGDET_CTRL_COMP_DM            ((uint32) 0x01u << COM_CHGDET_CTRL_COMP_DM_POS)
    #define COM_CHGDET_CTRL_COMP_EN            ((uint32) 0x01u << COM_CHGDET_CTRL_COMP_EN_POS)
    #define COM_CHGDET_CTRL_REF_DP             ((uint32) 0x01u << COM_CHGDET_CTRL_REF_DP_POS)
    #define COM_CHGDET_CTRL_REF_DM             ((uint32) 0x01u << COM_CHGDET_CTRL_REF_DM_POS)
    #define COM_CHGDET_CTRL_REF_EN             ((uint32) 0x01u << COM_CHGDET_CTRL_REF_EN_POS)
    #define COM_CHGDET_CTRL_DCD_SRC_EN         ((uint32) 0x01u << COM_CHGDET_CTRL_DCD_SRC_EN_POS)
    #define COM_CHGDET_CTRL_ADFT_CTRL_MASK     ((uint32) 0x03u << COM_CHGDET_CTRL_ADFT_CTRL_POS)
    #define COM_CHGDET_CTRL_ADFT_CTRL_NORMAL   ((uint32) 0x00u << COM_CHGDET_CTRL_ADFT_CTRL_POS)
    #define COM_CHGDET_CTRL_ADFT_CTRL_VBG      ((uint32) 0x01u << COM_CHGDET_CTRL_ADFT_CTRL_POS)
    #define COM_CHGDET_CTRL_ADFT_CTRL_DONTUSE  ((uint32) 0x02u << COM_CHGDET_CTRL_ADFT_CTRL_POS)
    #define COM_CHGDET_CTRL_ADFT_CTRL_ADFTIN   ((uint32) 0x03u << COM_CHGDET_CTRL_ADFT_CTRL_POS)
    #define COM_CHGDET_CTRL_COMP_OUT           ((uint32) 0x01u << COM_CHGDET_CTRL_COMP_OUT_POS)

    /* COM_LPM_CTRL */
    #define COM_LPM_CTRL_LPM_EN_POS        (0u)
    #define COM_LPM_CTRL_LPM_ACK_RESP_POS  (1u)
    #define COM_LPM_CTRL_NYET_EN_POS       (2u)
    #define COM_LPM_CTRL_SUB_RESP_POS      (4u)
    #define COM_LPM_CTRL_LPM_EN            ((uint32) 0x01u << COM_LPM_CTRL_LPM_EN_POS)
    #define COM_LPM_CTRL_LPM_ACK_RESP      ((uint32) 0x01u << COM_LPM_CTRL_LPM_ACK_RESP_POS)
    #define COM_LPM_CTRL_NYET_EN           ((uint32) 0x01u << COM_LPM_CTRL_NYET_EN_POS)
    #define COM_LPM_CTRL_ACK_NYET_MASK     ((uint32) 0x03u << COM_LPM_CTRL_LPM_ACK_RESP_POS)
    #define COM_LPM_CTRL_SUB_RESP          ((uint32) 0x01u << COM_LPM_CTRL_SUB_RESP_POS)

    #define COM_LPM_STAT_LPM_BESL_POS          (0u)
    #define COM_LPM_STAT_LPM_REMOTE_WAKE_POS   (4u)
    #define COM_LPM_STAT_LPM_BESL_MASK         ((uint32) 0x0Fu << COM_LPM_STAT_LPM_BESL_POS)
    #define COM_LPM_STAT_LPM_REMOTE_WAKE       ((uint32) 0x01u << COM_LPM_STAT_LPM_REMOTE_WAKE_POS)

    /* COM_INTR_SIE */
    #define COM_INTR_SIE_SOF_INTR_POS          (0u) /* [0] Interrupt for USB SOF   */
    #define COM_INTR_SIE_BUS_RESET_INTR_POS    (1u) /* [1] Interrupt for BUS RESET */
    #define COM_INTR_SIE_EP0_INTR_POS          (2u) /* [2] Interrupt for EP0       */
    #define COM_INTR_SIE_LPM_INTR_POS          (3u) /* [3] Interrupt for LPM       */
    #define COM_INTR_SIE_RESUME_INTR_POS       (4u) /* [4] Interrupt for RESUME (not used by component) */
    #define COM_INTR_SIE_SOF_INTR              ((uint32) 0x01u << COM_INTR_SIE_SOF_INTR_POS)
    #define COM_INTR_SIE_BUS_RESET_INTR        ((uint32) 0x01u << COM_INTR_SIE_BUS_RESET_INTR_POS)
    #define COM_INTR_SIE_EP0_INTR              ((uint32) 0x01u << COM_INTR_SIE_EP0_INTR_POS)
    #define COM_INTR_SIE_LPM_INTR              ((uint32) 0x01u << COM_INTR_SIE_LPM_INTR_POS)
    #define COM_INTR_SIE_RESUME_INTR           ((uint32) 0x01u << COM_INTR_SIE_RESUME_INTR_POS)

    /* COM_INTR_CAUSE_LO, MED and HI */
    #define COM_INTR_CAUSE_SOF_INTR_POS       (0u)  /* [0] Interrupt status for USB SOF    */
    #define COM_INTR_CAUSE_BUS_RESET_INTR_POS (1u)  /* [1] Interrupt status for USB BUS RSET */
    #define COM_INTR_CAUSE_EP0_INTR_POS       (2u)  /* [2] Interrupt status for USB EP0    */
    #define COM_INTR_CAUSE_LPM_INTR_POS       (3u)  /* [3] Interrupt status for USB LPM    */
    #define COM_INTR_CAUSE_RESUME_INTR_POS    (4u)  /* [4] Interrupt status for USB RESUME */
    #define COM_INTR_CAUSE_ARB_INTR_POS       (7u)  /* [7] Interrupt status for USB ARB    */
    #define COM_INTR_CAUSE_EP1_INTR_POS       (8u)  /* [8] Interrupt status for USB EP1    */
    #define COM_INTR_CAUSE_EP2_INTR_POS       (9u)  /* [9] Interrupt status for USB EP2    */
    #define COM_INTR_CAUSE_EP3_INTR_POS       (10u) /* [10] Interrupt status for USB EP3   */
    #define COM_INTR_CAUSE_EP4_INTR_POS       (11u) /* [11] Interrupt status for USB EP4   */
    #define COM_INTR_CAUSE_EP5_INTR_POS       (12u) /* [12] Interrupt status for USB EP5   */
    #define COM_INTR_CAUSE_EP6_INTR_POS       (13u) /* [13] Interrupt status for USB EP6   */
    #define COM_INTR_CAUSE_EP7_INTR_POS       (14u) /* [14] Interrupt status for USB EP7   */
    #define COM_INTR_CAUSE_EP8_INTR_POS       (15u) /* [15] Interrupt status for USB EP8   */
    #define COM_INTR_CAUSE_SOF_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_SOF_INTR_POS)
    #define COM_INTR_CAUSE_BUS_RESET_INTR     ((uint32) 0x01u << COM_INTR_CAUSE_BUS_RESET_INTR_POS)
    #define COM_INTR_CAUSE_EP0_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP0_INTR_POS)
    #define COM_INTR_CAUSE_LPM_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_LPM_INTR_POS)
    #define COM_INTR_CAUSE_RESUME_INTR        ((uint32) 0x01u << COM_INTR_CAUSE_RESUME_INTR_POS)
    #define COM_INTR_CAUSE_ARB_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_ARB_INTR_POS)
    #define COM_INTR_CAUSE_EP1_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP1_INTR_POS)
    #define COM_INTR_CAUSE_EP2_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP2_INTR_POS)
    #define COM_INTR_CAUSE_EP3_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP3_INTR_POS)
    #define COM_INTR_CAUSE_EP4_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP4_INTR_POS)
    #define COM_INTR_CAUSE_EP5_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP5_INTR_POS)
    #define COM_INTR_CAUSE_EP6_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP6_INTR_POS)
    #define COM_INTR_CAUSE_EP7_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP7_INTR_POS)
    #define COM_INTR_CAUSE_EP8_INTR           ((uint32) 0x01u << COM_INTR_CAUSE_EP8_INTR_POS)

    #define COM_INTR_CAUSE_CTRL_INTR_MASK     (COM_INTR_CAUSE_SOF_INTR       | \
                                                            COM_INTR_CAUSE_BUS_RESET_INTR | \
                                                            COM_INTR_CAUSE_EP0_INTR       | \
                                                            COM_INTR_CAUSE_LPM_INTR)

    #define COM_INTR_CAUSE_EP1_8_INTR_MASK    (COM_INTR_CAUSE_EP1_INTR       | \
                                                            COM_INTR_CAUSE_EP2_INTR       | \
                                                            COM_INTR_CAUSE_EP3_INTR       | \
                                                            COM_INTR_CAUSE_EP4_INTR       | \
                                                            COM_INTR_CAUSE_EP5_INTR       | \
                                                            COM_INTR_CAUSE_EP6_INTR       | \
                                                            COM_INTR_CAUSE_EP7_INTR       | \
                                                            COM_INTR_CAUSE_EP8_INTR)

    #define COM_INTR_CAUSE_EP_INTR_SHIFT      (COM_INTR_CAUSE_ARB_INTR_POS - \
                                                           (COM_INTR_CAUSE_LPM_INTR_POS + 1u))
    #define COM_INTR_CAUSE_SRC_COUNT          (13u)

    #define COM_CHGDET_CTRL_PRIMARY    (COM_CHGDET_CTRL_COMP_EN | \
                                                     COM_CHGDET_CTRL_COMP_DM | \
                                                     COM_CHGDET_CTRL_REF_EN  | \
                                                     COM_CHGDET_CTRL_REF_DP)

    #define COM_CHGDET_CTRL_SECONDARY  (COM_CHGDET_CTRL_COMP_EN | \
                                                     COM_CHGDET_CTRL_COMP_DP | \
                                                     COM_CHGDET_CTRL_REF_EN  | \
                                                     COM_CHGDET_CTRL_REF_DM)

    #define COM_CHGDET_CTRL_DEFAULT    (0x00000900u)


#else /* (CY_PSOC3 || CY_PSOC5LP) */
    #define COM_PM_ACT_EN_FSUSB            COM_USB__PM_ACT_MSK
    #define COM_PM_STBY_EN_FSUSB           COM_USB__PM_STBY_MSK
    #define COM_PM_AVAIL_EN_FSUSBIO        (0x10u)

    #define COM_PM_USB_CR0_REF_EN          (0x01u)
    #define COM_PM_USB_CR0_PD_N            (0x02u)
    #define COM_PM_USB_CR0_PD_PULLUP_N     (0x04u)
#endif /* (CY_PSOC4) */


/***************************************
*       Macros Definitions
***************************************/

#if (CY_PSOC4)
    #define COM_ClearSieEpInterruptSource(intMask) \
                do{ \
                    COM_SIE_EP_INT_SR_REG = (uint32) (intMask); \
                }while(0)

    #define COM_ClearSieInterruptSource(intMask) \
                do{ \
                    COM_INTR_SIE_REG = (uint32) (intMask); \
                }while(0)
#else
    #define COM_ClearSieEpInterruptSource(intMask) \
                do{ \
                    COM_SIE_EP_INT_SR_REG &= (uint8) ~(intMask); \
                }while(0)

    #define COM_ClearSieInterruptSource(intMask) \
                do{ /* Does nohitng. */ }while(0)
#endif /* (CY_PSOC4) */

#define COM_GET_ACTIVE_IN_EP_CR0_MODE(epType)  (((epType) == COM_EP_TYPE_ISOC) ? \
                                                                (COM_MODE_ISO_IN) : (COM_MODE_ACK_IN))

#define COM_GET_ACTIVE_OUT_EP_CR0_MODE(epType) (((epType) == COM_EP_TYPE_ISOC) ? \
                                                                (COM_MODE_ISO_OUT) : (COM_MODE_ACK_OUT))

#define COM_GET_EP_TYPE(epNumber)  (COM_EP[epNumber].attrib & COM_EP_TYPE_MASK)

#define COM_GET_UINT16(hi, low)    (((uint16) ((uint16) (hi) << 8u)) | ((uint16) (low) & 0xFFu))


/***************************************
*    Initialization Register Settings
***************************************/

/* Clear device address and enable USB IP respond to USB traffic. */
#define COM_DEFUALT_CR0    (COM_CR0_ENABLE)

/* Arbiter configuration depends on memory management mode. */
#define COM_DEFAULT_ARB_CFG    ((COM_EP_MANAGEMENT_MANUAL) ? (COM_ARB_CFG_DMA_CFG_NONE) : \
                                                ((COM_EP_MANAGEMENT_DMA_MANUAL) ? \
                                                    (COM_ARB_CFG_DMA_CFG_MANUAL) : \
                                                        (COM_ARB_CFG_AUTO_MEM | COM_ARB_CFG_DMA_CFG_AUTO)))

/* Enable arbiter interrupt for active endpoints only */
#define COM_DEFAULT_ARB_INT_EN \
        ((uint8) ((uint8) COM_DMA1_ACTIVE << COM_ARB_INT_EP1_INTR_POS) | \
         (uint8) ((uint8) COM_DMA2_ACTIVE << COM_ARB_INT_EP2_INTR_POS) | \
         (uint8) ((uint8) COM_DMA3_ACTIVE << COM_ARB_INT_EP3_INTR_POS) | \
         (uint8) ((uint8) COM_DMA4_ACTIVE << COM_ARB_INT_EP4_INTR_POS) | \
         (uint8) ((uint8) COM_DMA5_ACTIVE << COM_ARB_INT_EP5_INTR_POS) | \
         (uint8) ((uint8) COM_DMA6_ACTIVE << COM_ARB_INT_EP6_INTR_POS) | \
         (uint8) ((uint8) COM_DMA7_ACTIVE << COM_ARB_INT_EP7_INTR_POS) | \
         (uint8) ((uint8) COM_DMA8_ACTIVE << COM_ARB_INT_EP8_INTR_POS))

/* Enable all SIE endpoints interrupts */
#define COM_DEFAULT_SIE_EP_INT_EN  (COM_SIE_INT_EP1_INTR | \
                                                 COM_SIE_INT_EP2_INTR | \
                                                 COM_SIE_INT_EP3_INTR | \
                                                 COM_SIE_INT_EP4_INTR | \
                                                 COM_SIE_INT_EP5_INTR | \
                                                 COM_SIE_INT_EP6_INTR | \
                                                 COM_SIE_INT_EP7_INTR | \
                                                 COM_SIE_INT_EP8_INTR)

#define COM_ARB_EPX_CFG_DEFAULT    (COM_ARB_EPX_CFG_RESET | \
                                                 COM_ARB_EPX_CFG_CRC_BYPASS)

/* Default EP arbiter interrupt source register */
#define COM_ARB_EPX_INT_COMMON_MASK   (COM_ARB_EPX_INT_IN_BUF_FULL | \
                                                    COM_ARB_EPX_INT_BUF_OVER    | \
                                                    COM_ARB_EPX_INT_BUF_UNDER   | \
                                                    COM_ARB_EPX_INT_ERR_INT     | \
                                                    (COM_EP_MANAGEMENT_DMA_MANUAL ? COM_ARB_EPX_INT_DMA_GNT : 0u))

#define COM_CLEAR_REG      (0u)

#if (CY_PSOC4)
    /* Set USB lock option when IMO is locked to USB traffic. */
    #define COM_DEFUALT_CR1    ((0u != CySysClkImoGetUsbLock()) ? (COM_CR1_ENABLE_LOCK) : (0u))

    /* Recommended value is increased from 3 to 10 due to suppress glitch on  
     * RSE0 with USB2.0 hubs (LF CLK = 32kHz equal to 350us). */
    #define COM_DEFUALT_BUS_RST_CNT  (10u)

    /* Select VBUS sources as: valid, PHY of GPIO, and clears isolate bit. */
    /* Application level must ensure that VBUS is valid valid to use. */
    #define COM_DEFAULT_POWER_CTRL_VBUS    (COM_POWER_CTRL_ENABLE_VBUS_PULLDOWN | \
                                                         ((!COM_VBUS_MONITORING_ENABLE) ? \
                                                            (COM_POWER_CTRL_VBUS_VALID_OVR_1) : \
                                                                (COM_VBUS_POWER_PAD_ENABLE ? \
                                                                    (COM_POWER_CTRL_VBUS_VALID_OVR_PHY) : \
                                                                    (COM_POWER_CTRL_VBUS_VALID_OVR_GPIO))))
    /* Enable USB IP. */
    #define COM_DEFAULT_POWER_CTRL_PHY (COM_POWER_CTRL_SUSPEND     | \
                                                     COM_POWER_CTRL_SUSPEND_DEL | \
                                                     COM_POWER_CTRL_ENABLE_RCVR | \
                                                     COM_POWER_CTRL_ENABLE_DPO  | \
                                                     COM_POWER_CTRL_ENABLE_DMO  | \
                                                     COM_POWER_CTRL_ENABLE)

    /* Assign interrupt between levels lo, med, hi. */
    #define COM_DEFAULT_INTR_LVL_SEL   ((uint32) (COM_INTR_LVL_SEL))

    /* Enable interrupt source in the INTR_SIE. The SOF is always disabled and EP0 is enabled. */
    #define COM_DEFAULT_INTR_SIE_MASK \
                ((uint32) ((uint32) COM_BUS_RESET_ISR_ACTIVE << COM_INTR_SIE_BUS_RESET_INTR_POS) | \
                 (uint32) ((uint32) COM_SOF_ISR_ACTIVE       << COM_INTR_SIE_SOF_INTR_POS)       | \
                 (uint32) ((uint32) COM_LPM_ACTIVE           << COM_INTR_SIE_LPM_INTR_POS)       | \
                 (uint32) ((uint32) COM_INTR_SIE_EP0_INTR))

    /* Arbiter interrupt sources */
    #define COM_ARB_EPX_INT_MASK   (COM_ARB_EPX_INT_COMMON_MASK | \
                                                (COM_EP_MANAGEMENT_DMA_AUTO ? COM_ARB_EPX_INT_DMA_TERMIN : 0u))

    /* Common DMA configuration */
    #define COM_DMA_COMMON_CFG     (CYDMA_PULSE | CYDMA_ENTIRE_DESCRIPTOR | \
                                                 CYDMA_NON_PREEMPTABLE)


#else
    #define COM_ARB_EPX_INT_MASK   (COM_ARB_EPX_INT_COMMON_MASK)

    #define COM_DEFUALT_CR1        (COM_CR1_ENABLE_LOCK)

    /* Recommended value is 3 for LF CLK = 100kHz equal to 100us. */
    #define COM_DEFUALT_BUS_RST_CNT    (10u)
#endif /* (CY_PSOC4) */

/*
* \addtogroup group_deprecated
* @{
*/

/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Renamed type definitions */
#define COM_CODE CYCODE
#define COM_FAR CYFAR
#if defined(__C51__) || defined(__CX51__)
    #define COM_DATA data
    #define COM_XDATA xdata
#else
    #define COM_DATA
    #define COM_XDATA
#endif /*  __C51__ */
#define COM_NULL       NULL
/** @} deprecated */
/* Renamed structure fields */
#define wBuffOffset         buffOffset
#define wBufferSize         bufferSize
#define bStatus             status
#define wLength             length
#define wCount              count

/* Renamed global variable */
#define CurrentTD           COM_currentTD
#define COM_interfaceSetting_last       COM_interfaceSettingLast

/* Renamed global constants */
#define COM_DWR_VDDD_OPERATION         (COM_DWR_POWER_OPERATION)

/* Renamed functions */
#define COM_bCheckActivity             COM_CheckActivity
#define COM_bGetConfiguration          COM_GetConfiguration
#define COM_bGetInterfaceSetting       COM_GetInterfaceSetting
#define COM_bGetEPState                COM_GetEPState
#define COM_wGetEPCount                COM_GetEPCount
#define COM_bGetEPAckState             COM_GetEPAckState
#define COM_bRWUEnabled                COM_RWUEnabled
#define COM_bVBusPresent               COM_VBusPresent

#define COM_bConfiguration             COM_configuration
#define COM_bInterfaceSetting          COM_interfaceSetting
#define COM_bDeviceAddress             COM_deviceAddress
#define COM_bDeviceStatus              COM_deviceStatus
#define COM_bDevice                    COM_device
#define COM_bTransferState             COM_transferState
#define COM_bLastPacketSize            COM_lastPacketSize

#define COM_LoadEP                     COM_LoadInEP
#define COM_LoadInISOCEP               COM_LoadInEP
#define COM_EnableOutISOCEP            COM_EnableOutEP

#define COM_SetVector                  CyIntSetVector
#define COM_SetPriority                CyIntSetPriority
#define COM_EnableInt                  CyIntEnable

/* Replace with register access. */
#define COM_bmRequestType      COM_EP0_DR0_PTR
#define COM_bRequest           COM_EP0_DR1_PTR
#define COM_wValue             COM_EP0_DR2_PTR
#define COM_wValueHi           COM_EP0_DR3_PTR
#define COM_wValueLo           COM_EP0_DR2_PTR
#define COM_wIndex             COM_EP0_DR4_PTR
#define COM_wIndexHi           COM_EP0_DR5_PTR
#define COM_wIndexLo           COM_EP0_DR4_PTR
#define COM_length             COM_EP0_DR6_PTR
#define COM_lengthHi           COM_EP0_DR7_PTR
#define COM_lengthLo           COM_EP0_DR6_PTR

/* Rename VBUS monitoring registers. */
#if (CY_PSOC3 || CY_PSOC5LP)
    #if (COM_VBUS_MONITORING_ENABLE)
        #if (COM_VBUS_MONITORING_INTERNAL)
            #define COM_VBUS_DR_PTR    ( (reg8 *) COM_VBUS__DR)
            #define COM_VBUS_DR_REG    (*(reg8 *) COM_VBUS__DR)
            #define COM_VBUS_PS_PTR    ( (reg8 *) COM_VBUS__PS)
            #define COM_VBUS_PS_REG    (*(reg8 *) COM_VBUS__PS)
            #define COM_VBUS_MASK          COM_VBUS__MASK
        #else
            #define COM_VBUS_PS_PTR    ( (reg8 *) COM_Vbus_ps_sts_sts_reg__STATUS_REG)
            #define COM_VBUS_MASK      (0x01u)
        #endif /* (COM_VBUS_MONITORING_INTERNAL) */
    #endif /*(COM_VBUS_MONITORING_ENABLE) */
        
    /* Pointer DIE structure in flash (8 bytes): Y and X location, wafer, lot msb, lot lsb, 
    *  work week, fab/year, minor. */
    #define COM_DIE_ID             CYDEV_FLSHID_CUST_TABLES_BASE

     #if (COM_EP_MANAGEMENT_DMA_AUTO)
        #if (COM_DMA1_ACTIVE)
            #define COM_ep1_TD_TERMOUT_EN  (COM_ep1__TD_TERMOUT_EN)
        #else
            #define COM_ep1_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA1_ACTIVE) */

        #if (COM_DMA2_ACTIVE)
            #define COM_ep2_TD_TERMOUT_EN  (COM_ep2__TD_TERMOUT_EN)
        #else
            #define COM_ep2_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA2_ACTIVE) */

        #if (COM_DMA3_ACTIVE)
            #define COM_ep3_TD_TERMOUT_EN  (COM_ep3__TD_TERMOUT_EN)
        #else
            #define COM_ep3_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA3_ACTIVE) */

        #if (COM_DMA4_ACTIVE)
            #define COM_ep4_TD_TERMOUT_EN  (COM_ep4__TD_TERMOUT_EN)
        #else
            #define COM_ep4_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA4_ACTIVE) */

        #if (COM_DMA5_ACTIVE)
            #define COM_ep5_TD_TERMOUT_EN  (COM_ep5__TD_TERMOUT_EN)
        #else
            #define COM_ep5_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA5_ACTIVE) */

        #if (COM_DMA6_ACTIVE)
            #define COM_ep6_TD_TERMOUT_EN  (COM_ep6__TD_TERMOUT_EN)
        #else
            #define COM_ep6_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA6_ACTIVE) */

        #if (COM_DMA7_ACTIVE)
            #define COM_ep7_TD_TERMOUT_EN  (COM_ep7__TD_TERMOUT_EN)
        #else
            #define COM_ep7_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA7_ACTIVE) */

        #if (COM_DMA8_ACTIVE)
            #define COM_ep8_TD_TERMOUT_EN  (COM_ep8__TD_TERMOUT_EN)
        #else
            #define COM_ep8_TD_TERMOUT_EN  (0u)
        #endif /* (COM_DMA8_ACTIVE) */
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */   
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

/* Rename USB IP registers. */
#define COM_ARB_CFG        COM_ARB_CFG_PTR

#define COM_ARB_EP1_CFG    COM_ARB_EP1_CFG_PTR
#define COM_ARB_EP1_INT_EN COM_ARB_EP1_INT_EN_PTR
#define COM_ARB_EP1_SR     COM_ARB_EP1_SR_PTR

#define COM_ARB_EP2_CFG    COM_ARB_EP2_CFG_PTR
#define COM_ARB_EP2_INT_EN COM_ARB_EP2_INT_EN_PTR
#define COM_ARB_EP2_SR     COM_ARB_EP2_SR_PTR

#define COM_ARB_EP3_CFG    COM_ARB_EP3_CFG_PTR
#define COM_ARB_EP3_INT_EN COM_ARB_EP3_INT_EN_PTR
#define COM_ARB_EP3_SR     COM_ARB_EP3_SR_PTR

#define COM_ARB_EP4_CFG    COM_ARB_EP4_CFG_PTR
#define COM_ARB_EP4_INT_EN COM_ARB_EP4_INT_EN_PTR
#define COM_ARB_EP4_SR     COM_ARB_EP4_SR_PTR

#define COM_ARB_EP5_CFG    COM_ARB_EP5_CFG_PTR
#define COM_ARB_EP5_INT_EN COM_ARB_EP5_INT_EN_PTR
#define COM_ARB_EP5_SR     COM_ARB_EP5_SR_PTR

#define COM_ARB_EP6_CFG    COM_ARB_EP6_CFG_PTR
#define COM_ARB_EP6_INT_EN COM_ARB_EP6_INT_EN_PTR
#define COM_ARB_EP6_SR     COM_ARB_EP6_SR_PTR

#define COM_ARB_EP7_CFG    COM_ARB_EP7_CFG_PTR
#define COM_ARB_EP7_INT_EN COM_ARB_EP7_INT_EN_PTR
#define COM_ARB_EP7_SR     COM_ARB_EP7_SR_PTR

#define COM_ARB_EP8_CFG    COM_ARB_EP8_CFG_PTR
#define COM_ARB_EP8_INT_EN COM_ARB_EP8_INT_EN_PTR
#define COM_ARB_EP8_SR     COM_ARB_EP8_SR_PTR

#define COM_ARB_INT_EN     COM_ARB_INT_EN_PTR
#define COM_ARB_INT_SR     COM_ARB_INT_SR_PTR

#define COM_ARB_RW1_DR     COM_ARB_RW1_DR_PTR
#define COM_ARB_RW1_RA     COM_ARB_RW1_RA_PTR
#define COM_ARB_RW1_RA_MSB COM_ARB_RW1_RA_MSB_PTR
#define COM_ARB_RW1_WA     COM_ARB_RW1_WA_PTR
#define COM_ARB_RW1_WA_MSB COM_ARB_RW1_WA_MSB_PTR

#define COM_ARB_RW2_DR     COM_ARB_RW2_DR_PTR
#define COM_ARB_RW2_RA     COM_ARB_RW2_RA_PTR
#define COM_ARB_RW2_RA_MSB COM_ARB_RW2_RA_MSB_PTR
#define COM_ARB_RW2_WA     COM_ARB_RW2_WA_PTR
#define COM_ARB_RW2_WA_MSB COM_ARB_RW2_WA_MSB_PTR

#define COM_ARB_RW3_DR     COM_ARB_RW3_DR_PTR
#define COM_ARB_RW3_RA     COM_ARB_RW3_RA_PTR
#define COM_ARB_RW3_RA_MSB COM_ARB_RW3_RA_MSB_PTR
#define COM_ARB_RW3_WA     COM_ARB_RW3_WA_PTR
#define COM_ARB_RW3_WA_MSB COM_ARB_RW3_WA_MSB_PTR

#define COM_ARB_RW4_DR     COM_ARB_RW4_DR_PTR
#define COM_ARB_RW4_RA     COM_ARB_RW4_RA_PTR
#define COM_ARB_RW4_RA_MSB COM_ARB_RW4_RA_MSB_PTR
#define COM_ARB_RW4_WA     COM_ARB_RW4_WA_PTR
#define COM_ARB_RW4_WA_MSB COM_ARB_RW4_WA_MSB_PTR

#define COM_ARB_RW5_DR     COM_ARB_RW5_DR_PTR
#define COM_ARB_RW5_RA     COM_ARB_RW5_RA_PTR
#define COM_ARB_RW5_RA_MSB COM_ARB_RW5_RA_MSB_PTR
#define COM_ARB_RW5_WA     COM_ARB_RW5_WA_PTR
#define COM_ARB_RW5_WA_MSB COM_ARB_RW5_WA_MSB_PTR

#define COM_ARB_RW6_DR     COM_ARB_RW6_DR_PTR
#define COM_ARB_RW6_RA     COM_ARB_RW6_RA_PTR
#define COM_ARB_RW6_RA_MSB COM_ARB_RW6_RA_MSB_PTR
#define COM_ARB_RW6_WA     COM_ARB_RW6_WA_PTR
#define COM_ARB_RW6_WA_MSB COM_ARB_RW6_WA_MSB_PTR

#define COM_ARB_RW7_DR     COM_ARB_RW7_DR_PTR
#define COM_ARB_RW7_RA     COM_ARB_RW7_RA_PTR
#define COM_ARB_RW7_RA_MSB COM_ARB_RW7_RA_MSB_PTR
#define COM_ARB_RW7_WA     COM_ARB_RW7_WA_PTR
#define COM_ARB_RW7_WA_MSB COM_ARB_RW7_WA_MSB_PTR

#define COM_ARB_RW8_DR     COM_ARB_RW8_DR_PTR
#define COM_ARB_RW8_RA     COM_ARB_RW8_RA_PTR
#define COM_ARB_RW8_RA_MSB COM_ARB_RW8_RA_MSB_PTR
#define COM_ARB_RW8_WA     COM_ARB_RW8_WA_PTR
#define COM_ARB_RW8_WA_MSB COM_ARB_RW8_WA_MSB_PTR

#define COM_BUF_SIZE       COM_BUF_SIZE_PTR
#define COM_BUS_RST_CNT    COM_BUS_RST_CNT_PTR
#define COM_CR0            COM_CR0_PTR
#define COM_CR1            COM_CR1_PTR
#define COM_CWA            COM_CWA_PTR
#define COM_CWA_MSB        COM_CWA_MSB_PTR

#define COM_DMA_THRES      COM_DMA_THRES_PTR
#define COM_DMA_THRES_MSB  COM_DMA_THRES_MSB_PTR

#define COM_EP_ACTIVE      COM_EP_ACTIVE_PTR
#define COM_EP_TYPE        COM_EP_TYPE_PTR

#define COM_EP0_CNT        COM_EP0_CNT_PTR
#define COM_EP0_CR         COM_EP0_CR_PTR
#define COM_EP0_DR0        COM_EP0_DR0_PTR
#define COM_EP0_DR1        COM_EP0_DR1_PTR
#define COM_EP0_DR2        COM_EP0_DR2_PTR
#define COM_EP0_DR3        COM_EP0_DR3_PTR
#define COM_EP0_DR4        COM_EP0_DR4_PTR
#define COM_EP0_DR5        COM_EP0_DR5_PTR
#define COM_EP0_DR6        COM_EP0_DR6_PTR
#define COM_EP0_DR7        COM_EP0_DR7_PTR

#define COM_OSCLK_DR0      COM_OSCLK_DR0_PTR
#define COM_OSCLK_DR1      COM_OSCLK_DR1_PTR

#define COM_PM_ACT_CFG     COM_PM_ACT_CFG_PTR
#define COM_PM_STBY_CFG    COM_PM_STBY_CFG_PTR

#define COM_SIE_EP_INT_EN  COM_SIE_EP_INT_EN_PTR
#define COM_SIE_EP_INT_SR  COM_SIE_EP_INT_SR_PTR

#define COM_SIE_EP1_CNT0   COM_SIE_EP1_CNT0_PTR
#define COM_SIE_EP1_CNT1   COM_SIE_EP1_CNT1_PTR
#define COM_SIE_EP1_CR0    COM_SIE_EP1_CR0_PTR

#define COM_SIE_EP2_CNT0   COM_SIE_EP2_CNT0_PTR
#define COM_SIE_EP2_CNT1   COM_SIE_EP2_CNT1_PTR
#define COM_SIE_EP2_CR0    COM_SIE_EP2_CR0_PTR

#define COM_SIE_EP3_CNT0   COM_SIE_EP3_CNT0_PTR
#define COM_SIE_EP3_CNT1   COM_SIE_EP3_CNT1_PTR
#define COM_SIE_EP3_CR0    COM_SIE_EP3_CR0_PTR

#define COM_SIE_EP4_CNT0   COM_SIE_EP4_CNT0_PTR
#define COM_SIE_EP4_CNT1   COM_SIE_EP4_CNT1_PTR
#define COM_SIE_EP4_CR0    COM_SIE_EP4_CR0_PTR

#define COM_SIE_EP5_CNT0   COM_SIE_EP5_CNT0_PTR
#define COM_SIE_EP5_CNT1   COM_SIE_EP5_CNT1_PTR
#define COM_SIE_EP5_CR0    COM_SIE_EP5_CR0_PTR

#define COM_SIE_EP6_CNT0   COM_SIE_EP6_CNT0_PTR
#define COM_SIE_EP6_CNT1   COM_SIE_EP6_CNT1_PTR
#define COM_SIE_EP6_CR0    COM_SIE_EP6_CR0_PTR

#define COM_SIE_EP7_CNT0   COM_SIE_EP7_CNT0_PTR
#define COM_SIE_EP7_CNT1   COM_SIE_EP7_CNT1_PTR
#define COM_SIE_EP7_CR0    COM_SIE_EP7_CR0_PTR

#define COM_SIE_EP8_CNT0   COM_SIE_EP8_CNT0_PTR
#define COM_SIE_EP8_CNT1   COM_SIE_EP8_CNT1_PTR
#define COM_SIE_EP8_CR0    COM_SIE_EP8_CR0_PTR

#define COM_SOF0           COM_SOF0_PTR
#define COM_SOF1           COM_SOF1_PTR

#define COM_USB_CLK_EN     COM_USB_CLK_EN_PTR

#define COM_USBIO_CR0      COM_USBIO_CR0_PTR
#define COM_USBIO_CR1      COM_USBIO_CR1_PTR
#define COM_USBIO_CR2      COM_USBIO_CR2_PTR

#define COM_DM_INP_DIS_PTR     ( (reg8 *) COM_Dm__INP_DIS)
#define COM_DM_INP_DIS_REG     (*(reg8 *) COM_Dm__INP_DIS)
#define COM_DP_INP_DIS_PTR     ( (reg8 *) COM_Dp__INP_DIS)
#define COM_DP_INP_DIS_REG     (*(reg8 *) COM_Dp__INP_DIS)
#define COM_DP_INTSTAT_PTR     ( (reg8 *) COM_Dp__INTSTAT)
#define COM_DP_INTSTAT_REG     (*(reg8 *) COM_Dp__INTSTAT)
#define COM_DM_MASK            COM_Dm__0__MASK
#define COM_DP_MASK            COM_Dp__0__MASK

#define USBFS_SIE_EP_INT_EP1_MASK        (0x01u)
#define USBFS_SIE_EP_INT_EP2_MASK        (0x02u)
#define USBFS_SIE_EP_INT_EP3_MASK        (0x04u)
#define USBFS_SIE_EP_INT_EP4_MASK        (0x08u)
#define USBFS_SIE_EP_INT_EP5_MASK        (0x10u)
#define USBFS_SIE_EP_INT_EP6_MASK        (0x20u)
#define USBFS_SIE_EP_INT_EP7_MASK        (0x40u)
#define USBFS_SIE_EP_INT_EP8_MASK        (0x80u)

#define COM_ARB_EPX_SR_IN_BUF_FULL     (0x01u)
#define COM_ARB_EPX_SR_DMA_GNT         (0x02u)
#define COM_ARB_EPX_SR_BUF_OVER        (0x04u)
#define COM_ARB_EPX_SR_BUF_UNDER       (0x08u)

#define COM_ARB_EPX_INT_EN_ALL COM_ARB_EPX_INT_ALL

#define COM_CR1_BUS_ACTIVITY_SHIFT     (0x02u)

#define COM_BUS_RST_COUNT      COM_DEFUALT_BUS_RST_CNT

#define COM_ARB_INT_MASK       COM_DEFAULT_ARB_INT_EN

#if (CYDEV_CHIP_DIE_EXPECT == CYDEV_CHIP_DIE_LEOPARD)
    /* CY_PSOC3 interrupt registers */
    #define COM_USB_ISR_PRIOR  ((reg8 *) CYDEV_INTC_PRIOR0)
    #define COM_USB_ISR_SET_EN ((reg8 *) CYDEV_INTC_SET_EN0)
    #define COM_USB_ISR_CLR_EN ((reg8 *) CYDEV_INTC_CLR_EN0)
    #define COM_USB_ISR_VECT   ((cyisraddress *) CYDEV_INTC_VECT_MBASE)
#elif (CYDEV_CHIP_DIE_EXPECT == CYDEV_CHIP_DIE_PANTHER)
    /* CY_PSOC5LP interrupt registers */
    #define COM_USB_ISR_PRIOR  ((reg8 *) CYDEV_NVIC_PRI_0)
    #define COM_USB_ISR_SET_EN ((reg8 *) CYDEV_NVIC_SETENA0)
    #define COM_USB_ISR_CLR_EN ((reg8 *) CYDEV_NVIC_CLRENA0)
    #define COM_USB_ISR_VECT   ((cyisraddress *) CYDEV_NVIC_VECT_OFFSET)
#endif /*  CYDEV_CHIP_DIE_EXPECT */


#endif /* (CY_USBFS_COM_H) */


/* [] END OF FILE */
