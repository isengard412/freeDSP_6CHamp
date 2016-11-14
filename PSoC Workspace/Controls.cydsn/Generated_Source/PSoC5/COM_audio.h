/***************************************************************************//**
* \file COM_audio.h
* \version 3.0
*
* \brief
*  This file provides function prototypes and constants for the USBFS component 
*  Audio class.
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

#if !defined(CY_USBFS_COM_audio_H)
#define CY_USBFS_COM_audio_H

#include "COM.h"


/***************************************
* Custom Declarations
***************************************/

/* `#START CUSTOM_CONSTANTS` Place your declaration here */

/* `#END` */


/***************************************
*  Constants for COM_audio API.
***************************************/

/* Audio Class-Specific Request Codes (AUDIO Table A-9) */
#define COM_REQUEST_CODE_UNDEFINED     (0x00u)
#define COM_SET_CUR                    (0x01u)
#define COM_GET_CUR                    (0x81u)
#define COM_SET_MIN                    (0x02u)
#define COM_GET_MIN                    (0x82u)
#define COM_SET_MAX                    (0x03u)
#define COM_GET_MAX                    (0x83u)
#define COM_SET_RES                    (0x04u)
#define COM_GET_RES                    (0x84u)
#define COM_SET_MEM                    (0x05u)
#define COM_GET_MEM                    (0x85u)
#define COM_GET_STAT                   (0xFFu)

/* point Control Selectors (AUDIO Table A-19) */
#define COM_EP_CONTROL_UNDEFINED       (0x00u)
#define COM_SAMPLING_FREQ_CONTROL      (0x01u)
#define COM_PITCH_CONTROL              (0x02u)

/* Feature Unit Control Selectors (AUDIO Table A-11) */
#define COM_FU_CONTROL_UNDEFINED       (0x00u)
#define COM_MUTE_CONTROL               (0x01u)
#define COM_VOLUME_CONTROL             (0x02u)
#define COM_BASS_CONTROL               (0x03u)
#define COM_MID_CONTROL                (0x04u)
#define COM_TREBLE_CONTROL             (0x05u)
#define COM_GRAPHIC_EQUALIZER_CONTROL  (0x06u)
#define COM_AUTOMATIC_GAIN_CONTROL     (0x07u)
#define COM_DELAY_CONTROL              (0x08u)
#define COM_BASS_BOOST_CONTROL         (0x09u)
#define COM_LOUDNESS_CONTROL           (0x0Au)

#define COM_SAMPLE_FREQ_LEN            (3u)
#define COM_VOLUME_LEN                 (2u)

#if !defined(USER_SUPPLIED_DEFAULT_VOLUME_VALUE)
    #define COM_VOL_MIN_MSB            (0x80u)
    #define COM_VOL_MIN_LSB            (0x01u)
    #define COM_VOL_MAX_MSB            (0x7Fu)
    #define COM_VOL_MAX_LSB            (0xFFu)
    #define COM_VOL_RES_MSB            (0x00u)
    #define COM_VOL_RES_LSB            (0x01u)
#endif /* USER_SUPPLIED_DEFAULT_VOLUME_VALUE */


/***************************************
* External data references
***************************************/
/**
* \addtogroup group_audio
* @{
*/
extern volatile uint8 COM_currentSampleFrequency[COM_MAX_EP][COM_SAMPLE_FREQ_LEN];
extern volatile uint8 COM_frequencyChanged;
extern volatile uint8 COM_currentMute;
extern volatile uint8 COM_currentVolume[COM_VOLUME_LEN];
/** @} audio */

extern volatile uint8 COM_minimumVolume[COM_VOLUME_LEN];
extern volatile uint8 COM_maximumVolume[COM_VOLUME_LEN];
extern volatile uint8 COM_resolutionVolume[COM_VOLUME_LEN];

#endif /*  CY_USBFS_COM_audio_H */


/* [] END OF FILE */
