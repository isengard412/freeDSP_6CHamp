/*******************************************************************************
* File Name: Input_1_SW.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Input_1_SW_H) /* Pins Input_1_SW_H */
#define CY_PINS_Input_1_SW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Input_1_SW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Input_1_SW__PORT == 15 && ((Input_1_SW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Input_1_SW_Write(uint8 value);
void    Input_1_SW_SetDriveMode(uint8 mode);
uint8   Input_1_SW_ReadDataReg(void);
uint8   Input_1_SW_Read(void);
void    Input_1_SW_SetInterruptMode(uint16 position, uint16 mode);
uint8   Input_1_SW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Input_1_SW_SetDriveMode() function.
     *  @{
     */
        #define Input_1_SW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Input_1_SW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Input_1_SW_DM_RES_UP          PIN_DM_RES_UP
        #define Input_1_SW_DM_RES_DWN         PIN_DM_RES_DWN
        #define Input_1_SW_DM_OD_LO           PIN_DM_OD_LO
        #define Input_1_SW_DM_OD_HI           PIN_DM_OD_HI
        #define Input_1_SW_DM_STRONG          PIN_DM_STRONG
        #define Input_1_SW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Input_1_SW_MASK               Input_1_SW__MASK
#define Input_1_SW_SHIFT              Input_1_SW__SHIFT
#define Input_1_SW_WIDTH              1u

/* Interrupt constants */
#if defined(Input_1_SW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Input_1_SW_SetInterruptMode() function.
     *  @{
     */
        #define Input_1_SW_INTR_NONE      (uint16)(0x0000u)
        #define Input_1_SW_INTR_RISING    (uint16)(0x0001u)
        #define Input_1_SW_INTR_FALLING   (uint16)(0x0002u)
        #define Input_1_SW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Input_1_SW_INTR_MASK      (0x01u) 
#endif /* (Input_1_SW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Input_1_SW_PS                     (* (reg8 *) Input_1_SW__PS)
/* Data Register */
#define Input_1_SW_DR                     (* (reg8 *) Input_1_SW__DR)
/* Port Number */
#define Input_1_SW_PRT_NUM                (* (reg8 *) Input_1_SW__PRT) 
/* Connect to Analog Globals */                                                  
#define Input_1_SW_AG                     (* (reg8 *) Input_1_SW__AG)                       
/* Analog MUX bux enable */
#define Input_1_SW_AMUX                   (* (reg8 *) Input_1_SW__AMUX) 
/* Bidirectional Enable */                                                        
#define Input_1_SW_BIE                    (* (reg8 *) Input_1_SW__BIE)
/* Bit-mask for Aliased Register Access */
#define Input_1_SW_BIT_MASK               (* (reg8 *) Input_1_SW__BIT_MASK)
/* Bypass Enable */
#define Input_1_SW_BYP                    (* (reg8 *) Input_1_SW__BYP)
/* Port wide control signals */                                                   
#define Input_1_SW_CTL                    (* (reg8 *) Input_1_SW__CTL)
/* Drive Modes */
#define Input_1_SW_DM0                    (* (reg8 *) Input_1_SW__DM0) 
#define Input_1_SW_DM1                    (* (reg8 *) Input_1_SW__DM1)
#define Input_1_SW_DM2                    (* (reg8 *) Input_1_SW__DM2) 
/* Input Buffer Disable Override */
#define Input_1_SW_INP_DIS                (* (reg8 *) Input_1_SW__INP_DIS)
/* LCD Common or Segment Drive */
#define Input_1_SW_LCD_COM_SEG            (* (reg8 *) Input_1_SW__LCD_COM_SEG)
/* Enable Segment LCD */
#define Input_1_SW_LCD_EN                 (* (reg8 *) Input_1_SW__LCD_EN)
/* Slew Rate Control */
#define Input_1_SW_SLW                    (* (reg8 *) Input_1_SW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Input_1_SW_PRTDSI__CAPS_SEL       (* (reg8 *) Input_1_SW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Input_1_SW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Input_1_SW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Input_1_SW_PRTDSI__OE_SEL0        (* (reg8 *) Input_1_SW__PRTDSI__OE_SEL0) 
#define Input_1_SW_PRTDSI__OE_SEL1        (* (reg8 *) Input_1_SW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Input_1_SW_PRTDSI__OUT_SEL0       (* (reg8 *) Input_1_SW__PRTDSI__OUT_SEL0) 
#define Input_1_SW_PRTDSI__OUT_SEL1       (* (reg8 *) Input_1_SW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Input_1_SW_PRTDSI__SYNC_OUT       (* (reg8 *) Input_1_SW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Input_1_SW__SIO_CFG)
    #define Input_1_SW_SIO_HYST_EN        (* (reg8 *) Input_1_SW__SIO_HYST_EN)
    #define Input_1_SW_SIO_REG_HIFREQ     (* (reg8 *) Input_1_SW__SIO_REG_HIFREQ)
    #define Input_1_SW_SIO_CFG            (* (reg8 *) Input_1_SW__SIO_CFG)
    #define Input_1_SW_SIO_DIFF           (* (reg8 *) Input_1_SW__SIO_DIFF)
#endif /* (Input_1_SW__SIO_CFG) */

/* Interrupt Registers */
#if defined(Input_1_SW__INTSTAT)
    #define Input_1_SW_INTSTAT            (* (reg8 *) Input_1_SW__INTSTAT)
    #define Input_1_SW_SNAP               (* (reg8 *) Input_1_SW__SNAP)
    
	#define Input_1_SW_0_INTTYPE_REG 		(* (reg8 *) Input_1_SW__0__INTTYPE)
#endif /* (Input_1_SW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Input_1_SW_H */


/* [] END OF FILE */
