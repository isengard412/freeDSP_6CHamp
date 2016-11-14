/*******************************************************************************
* File Name: Mode_SW.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Mode_SW_ALIASES_H) /* Pins Mode_SW_ALIASES_H */
#define CY_PINS_Mode_SW_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Mode_SW_0			(Mode_SW__0__PC)
#define Mode_SW_0_INTR	((uint16)((uint16)0x0001u << Mode_SW__0__SHIFT))

#define Mode_SW_INTR_ALL	 ((uint16)(Mode_SW_0_INTR))

#endif /* End Pins Mode_SW_ALIASES_H */


/* [] END OF FILE */
