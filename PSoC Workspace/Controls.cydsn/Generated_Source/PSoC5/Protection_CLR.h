/*******************************************************************************
* File Name: Protection_CLR.h  
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

#if !defined(CY_PINS_Protection_CLR_H) /* Pins Protection_CLR_H */
#define CY_PINS_Protection_CLR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Protection_CLR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Protection_CLR__PORT == 15 && ((Protection_CLR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Protection_CLR_Write(uint8 value);
void    Protection_CLR_SetDriveMode(uint8 mode);
uint8   Protection_CLR_ReadDataReg(void);
uint8   Protection_CLR_Read(void);
void    Protection_CLR_SetInterruptMode(uint16 position, uint16 mode);
uint8   Protection_CLR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Protection_CLR_SetDriveMode() function.
     *  @{
     */
        #define Protection_CLR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Protection_CLR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Protection_CLR_DM_RES_UP          PIN_DM_RES_UP
        #define Protection_CLR_DM_RES_DWN         PIN_DM_RES_DWN
        #define Protection_CLR_DM_OD_LO           PIN_DM_OD_LO
        #define Protection_CLR_DM_OD_HI           PIN_DM_OD_HI
        #define Protection_CLR_DM_STRONG          PIN_DM_STRONG
        #define Protection_CLR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Protection_CLR_MASK               Protection_CLR__MASK
#define Protection_CLR_SHIFT              Protection_CLR__SHIFT
#define Protection_CLR_WIDTH              1u

/* Interrupt constants */
#if defined(Protection_CLR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Protection_CLR_SetInterruptMode() function.
     *  @{
     */
        #define Protection_CLR_INTR_NONE      (uint16)(0x0000u)
        #define Protection_CLR_INTR_RISING    (uint16)(0x0001u)
        #define Protection_CLR_INTR_FALLING   (uint16)(0x0002u)
        #define Protection_CLR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Protection_CLR_INTR_MASK      (0x01u) 
#endif /* (Protection_CLR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Protection_CLR_PS                     (* (reg8 *) Protection_CLR__PS)
/* Data Register */
#define Protection_CLR_DR                     (* (reg8 *) Protection_CLR__DR)
/* Port Number */
#define Protection_CLR_PRT_NUM                (* (reg8 *) Protection_CLR__PRT) 
/* Connect to Analog Globals */                                                  
#define Protection_CLR_AG                     (* (reg8 *) Protection_CLR__AG)                       
/* Analog MUX bux enable */
#define Protection_CLR_AMUX                   (* (reg8 *) Protection_CLR__AMUX) 
/* Bidirectional Enable */                                                        
#define Protection_CLR_BIE                    (* (reg8 *) Protection_CLR__BIE)
/* Bit-mask for Aliased Register Access */
#define Protection_CLR_BIT_MASK               (* (reg8 *) Protection_CLR__BIT_MASK)
/* Bypass Enable */
#define Protection_CLR_BYP                    (* (reg8 *) Protection_CLR__BYP)
/* Port wide control signals */                                                   
#define Protection_CLR_CTL                    (* (reg8 *) Protection_CLR__CTL)
/* Drive Modes */
#define Protection_CLR_DM0                    (* (reg8 *) Protection_CLR__DM0) 
#define Protection_CLR_DM1                    (* (reg8 *) Protection_CLR__DM1)
#define Protection_CLR_DM2                    (* (reg8 *) Protection_CLR__DM2) 
/* Input Buffer Disable Override */
#define Protection_CLR_INP_DIS                (* (reg8 *) Protection_CLR__INP_DIS)
/* LCD Common or Segment Drive */
#define Protection_CLR_LCD_COM_SEG            (* (reg8 *) Protection_CLR__LCD_COM_SEG)
/* Enable Segment LCD */
#define Protection_CLR_LCD_EN                 (* (reg8 *) Protection_CLR__LCD_EN)
/* Slew Rate Control */
#define Protection_CLR_SLW                    (* (reg8 *) Protection_CLR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Protection_CLR_PRTDSI__CAPS_SEL       (* (reg8 *) Protection_CLR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Protection_CLR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Protection_CLR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Protection_CLR_PRTDSI__OE_SEL0        (* (reg8 *) Protection_CLR__PRTDSI__OE_SEL0) 
#define Protection_CLR_PRTDSI__OE_SEL1        (* (reg8 *) Protection_CLR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Protection_CLR_PRTDSI__OUT_SEL0       (* (reg8 *) Protection_CLR__PRTDSI__OUT_SEL0) 
#define Protection_CLR_PRTDSI__OUT_SEL1       (* (reg8 *) Protection_CLR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Protection_CLR_PRTDSI__SYNC_OUT       (* (reg8 *) Protection_CLR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Protection_CLR__SIO_CFG)
    #define Protection_CLR_SIO_HYST_EN        (* (reg8 *) Protection_CLR__SIO_HYST_EN)
    #define Protection_CLR_SIO_REG_HIFREQ     (* (reg8 *) Protection_CLR__SIO_REG_HIFREQ)
    #define Protection_CLR_SIO_CFG            (* (reg8 *) Protection_CLR__SIO_CFG)
    #define Protection_CLR_SIO_DIFF           (* (reg8 *) Protection_CLR__SIO_DIFF)
#endif /* (Protection_CLR__SIO_CFG) */

/* Interrupt Registers */
#if defined(Protection_CLR__INTSTAT)
    #define Protection_CLR_INTSTAT            (* (reg8 *) Protection_CLR__INTSTAT)
    #define Protection_CLR_SNAP               (* (reg8 *) Protection_CLR__SNAP)
    
	#define Protection_CLR_0_INTTYPE_REG 		(* (reg8 *) Protection_CLR__0__INTTYPE)
#endif /* (Protection_CLR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Protection_CLR_H */


/* [] END OF FILE */
