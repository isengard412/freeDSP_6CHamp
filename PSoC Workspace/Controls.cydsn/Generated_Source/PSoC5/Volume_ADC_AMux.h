/*******************************************************************************
* File Name: Volume_ADC_AMux.h
* Version 1.80
*
*  Description:
*    This file contains the constants and function prototypes for the Analog
*    Multiplexer User Module AMux.
*
*   Note:
*
********************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#if !defined(CY_AMUX_Volume_ADC_AMux_H)
#define CY_AMUX_Volume_ADC_AMux_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cyfitter_cfg.h"


/***************************************
*        Function Prototypes
***************************************/

void Volume_ADC_AMux_Start(void) ;
#define Volume_ADC_AMux_Init() Volume_ADC_AMux_Start()
void Volume_ADC_AMux_FastSelect(uint8 channel) ;
/* The Stop, Select, Connect, Disconnect and DisconnectAll functions are declared elsewhere */
/* void Volume_ADC_AMux_Stop(void); */
/* void Volume_ADC_AMux_Select(uint8 channel); */
/* void Volume_ADC_AMux_Connect(uint8 channel); */
/* void Volume_ADC_AMux_Disconnect(uint8 channel); */
/* void Volume_ADC_AMux_DisconnectAll(void) */


/***************************************
*         Parameter Constants
***************************************/

#define Volume_ADC_AMux_CHANNELS  2u
#define Volume_ADC_AMux_MUXTYPE   1
#define Volume_ADC_AMux_ATMOSTONE 0

/***************************************
*             API Constants
***************************************/

#define Volume_ADC_AMux_NULL_CHANNEL 0xFFu
#define Volume_ADC_AMux_MUX_SINGLE   1
#define Volume_ADC_AMux_MUX_DIFF     2


/***************************************
*        Conditional Functions
***************************************/

#if Volume_ADC_AMux_MUXTYPE == Volume_ADC_AMux_MUX_SINGLE
# if !Volume_ADC_AMux_ATMOSTONE
#  define Volume_ADC_AMux_Connect(channel) Volume_ADC_AMux_Set(channel)
# endif
# define Volume_ADC_AMux_Disconnect(channel) Volume_ADC_AMux_Unset(channel)
#else
# if !Volume_ADC_AMux_ATMOSTONE
void Volume_ADC_AMux_Connect(uint8 channel) ;
# endif
void Volume_ADC_AMux_Disconnect(uint8 channel) ;
#endif

#if Volume_ADC_AMux_ATMOSTONE
# define Volume_ADC_AMux_Stop() Volume_ADC_AMux_DisconnectAll()
# define Volume_ADC_AMux_Select(channel) Volume_ADC_AMux_FastSelect(channel)
void Volume_ADC_AMux_DisconnectAll(void) ;
#else
# define Volume_ADC_AMux_Stop() Volume_ADC_AMux_Start()
void Volume_ADC_AMux_Select(uint8 channel) ;
# define Volume_ADC_AMux_DisconnectAll() Volume_ADC_AMux_Start()
#endif

#endif /* CY_AMUX_Volume_ADC_AMux_H */


/* [] END OF FILE */
