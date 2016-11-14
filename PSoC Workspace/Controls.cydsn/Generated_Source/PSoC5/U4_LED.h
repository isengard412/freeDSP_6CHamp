/*******************************************************************************
* File Name: U4_LED.h  
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

#if !defined(CY_PINS_U4_LED_H) /* Pins U4_LED_H */
#define CY_PINS_U4_LED_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "U4_LED_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 U4_LED__PORT == 15 && ((U4_LED__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    U4_LED_Write(uint8 value);
void    U4_LED_SetDriveMode(uint8 mode);
uint8   U4_LED_ReadDataReg(void);
uint8   U4_LED_Read(void);
void    U4_LED_SetInterruptMode(uint16 position, uint16 mode);
uint8   U4_LED_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the U4_LED_SetDriveMode() function.
     *  @{
     */
        #define U4_LED_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define U4_LED_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define U4_LED_DM_RES_UP          PIN_DM_RES_UP
        #define U4_LED_DM_RES_DWN         PIN_DM_RES_DWN
        #define U4_LED_DM_OD_LO           PIN_DM_OD_LO
        #define U4_LED_DM_OD_HI           PIN_DM_OD_HI
        #define U4_LED_DM_STRONG          PIN_DM_STRONG
        #define U4_LED_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define U4_LED_MASK               U4_LED__MASK
#define U4_LED_SHIFT              U4_LED__SHIFT
#define U4_LED_WIDTH              1u

/* Interrupt constants */
#if defined(U4_LED__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in U4_LED_SetInterruptMode() function.
     *  @{
     */
        #define U4_LED_INTR_NONE      (uint16)(0x0000u)
        #define U4_LED_INTR_RISING    (uint16)(0x0001u)
        #define U4_LED_INTR_FALLING   (uint16)(0x0002u)
        #define U4_LED_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define U4_LED_INTR_MASK      (0x01u) 
#endif /* (U4_LED__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define U4_LED_PS                     (* (reg8 *) U4_LED__PS)
/* Data Register */
#define U4_LED_DR                     (* (reg8 *) U4_LED__DR)
/* Port Number */
#define U4_LED_PRT_NUM                (* (reg8 *) U4_LED__PRT) 
/* Connect to Analog Globals */                                                  
#define U4_LED_AG                     (* (reg8 *) U4_LED__AG)                       
/* Analog MUX bux enable */
#define U4_LED_AMUX                   (* (reg8 *) U4_LED__AMUX) 
/* Bidirectional Enable */                                                        
#define U4_LED_BIE                    (* (reg8 *) U4_LED__BIE)
/* Bit-mask for Aliased Register Access */
#define U4_LED_BIT_MASK               (* (reg8 *) U4_LED__BIT_MASK)
/* Bypass Enable */
#define U4_LED_BYP                    (* (reg8 *) U4_LED__BYP)
/* Port wide control signals */                                                   
#define U4_LED_CTL                    (* (reg8 *) U4_LED__CTL)
/* Drive Modes */
#define U4_LED_DM0                    (* (reg8 *) U4_LED__DM0) 
#define U4_LED_DM1                    (* (reg8 *) U4_LED__DM1)
#define U4_LED_DM2                    (* (reg8 *) U4_LED__DM2) 
/* Input Buffer Disable Override */
#define U4_LED_INP_DIS                (* (reg8 *) U4_LED__INP_DIS)
/* LCD Common or Segment Drive */
#define U4_LED_LCD_COM_SEG            (* (reg8 *) U4_LED__LCD_COM_SEG)
/* Enable Segment LCD */
#define U4_LED_LCD_EN                 (* (reg8 *) U4_LED__LCD_EN)
/* Slew Rate Control */
#define U4_LED_SLW                    (* (reg8 *) U4_LED__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define U4_LED_PRTDSI__CAPS_SEL       (* (reg8 *) U4_LED__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define U4_LED_PRTDSI__DBL_SYNC_IN    (* (reg8 *) U4_LED__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define U4_LED_PRTDSI__OE_SEL0        (* (reg8 *) U4_LED__PRTDSI__OE_SEL0) 
#define U4_LED_PRTDSI__OE_SEL1        (* (reg8 *) U4_LED__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define U4_LED_PRTDSI__OUT_SEL0       (* (reg8 *) U4_LED__PRTDSI__OUT_SEL0) 
#define U4_LED_PRTDSI__OUT_SEL1       (* (reg8 *) U4_LED__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define U4_LED_PRTDSI__SYNC_OUT       (* (reg8 *) U4_LED__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(U4_LED__SIO_CFG)
    #define U4_LED_SIO_HYST_EN        (* (reg8 *) U4_LED__SIO_HYST_EN)
    #define U4_LED_SIO_REG_HIFREQ     (* (reg8 *) U4_LED__SIO_REG_HIFREQ)
    #define U4_LED_SIO_CFG            (* (reg8 *) U4_LED__SIO_CFG)
    #define U4_LED_SIO_DIFF           (* (reg8 *) U4_LED__SIO_DIFF)
#endif /* (U4_LED__SIO_CFG) */

/* Interrupt Registers */
#if defined(U4_LED__INTSTAT)
    #define U4_LED_INTSTAT            (* (reg8 *) U4_LED__INTSTAT)
    #define U4_LED_SNAP               (* (reg8 *) U4_LED__SNAP)
    
	#define U4_LED_0_INTTYPE_REG 		(* (reg8 *) U4_LED__0__INTTYPE)
#endif /* (U4_LED__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_U4_LED_H */


/* [] END OF FILE */
