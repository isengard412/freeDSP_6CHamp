/*******************************************************************************
* File Name: Protection_CLK.h  
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

#if !defined(CY_PINS_Protection_CLK_H) /* Pins Protection_CLK_H */
#define CY_PINS_Protection_CLK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Protection_CLK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Protection_CLK__PORT == 15 && ((Protection_CLK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Protection_CLK_Write(uint8 value);
void    Protection_CLK_SetDriveMode(uint8 mode);
uint8   Protection_CLK_ReadDataReg(void);
uint8   Protection_CLK_Read(void);
void    Protection_CLK_SetInterruptMode(uint16 position, uint16 mode);
uint8   Protection_CLK_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Protection_CLK_SetDriveMode() function.
     *  @{
     */
        #define Protection_CLK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Protection_CLK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Protection_CLK_DM_RES_UP          PIN_DM_RES_UP
        #define Protection_CLK_DM_RES_DWN         PIN_DM_RES_DWN
        #define Protection_CLK_DM_OD_LO           PIN_DM_OD_LO
        #define Protection_CLK_DM_OD_HI           PIN_DM_OD_HI
        #define Protection_CLK_DM_STRONG          PIN_DM_STRONG
        #define Protection_CLK_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Protection_CLK_MASK               Protection_CLK__MASK
#define Protection_CLK_SHIFT              Protection_CLK__SHIFT
#define Protection_CLK_WIDTH              1u

/* Interrupt constants */
#if defined(Protection_CLK__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Protection_CLK_SetInterruptMode() function.
     *  @{
     */
        #define Protection_CLK_INTR_NONE      (uint16)(0x0000u)
        #define Protection_CLK_INTR_RISING    (uint16)(0x0001u)
        #define Protection_CLK_INTR_FALLING   (uint16)(0x0002u)
        #define Protection_CLK_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Protection_CLK_INTR_MASK      (0x01u) 
#endif /* (Protection_CLK__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Protection_CLK_PS                     (* (reg8 *) Protection_CLK__PS)
/* Data Register */
#define Protection_CLK_DR                     (* (reg8 *) Protection_CLK__DR)
/* Port Number */
#define Protection_CLK_PRT_NUM                (* (reg8 *) Protection_CLK__PRT) 
/* Connect to Analog Globals */                                                  
#define Protection_CLK_AG                     (* (reg8 *) Protection_CLK__AG)                       
/* Analog MUX bux enable */
#define Protection_CLK_AMUX                   (* (reg8 *) Protection_CLK__AMUX) 
/* Bidirectional Enable */                                                        
#define Protection_CLK_BIE                    (* (reg8 *) Protection_CLK__BIE)
/* Bit-mask for Aliased Register Access */
#define Protection_CLK_BIT_MASK               (* (reg8 *) Protection_CLK__BIT_MASK)
/* Bypass Enable */
#define Protection_CLK_BYP                    (* (reg8 *) Protection_CLK__BYP)
/* Port wide control signals */                                                   
#define Protection_CLK_CTL                    (* (reg8 *) Protection_CLK__CTL)
/* Drive Modes */
#define Protection_CLK_DM0                    (* (reg8 *) Protection_CLK__DM0) 
#define Protection_CLK_DM1                    (* (reg8 *) Protection_CLK__DM1)
#define Protection_CLK_DM2                    (* (reg8 *) Protection_CLK__DM2) 
/* Input Buffer Disable Override */
#define Protection_CLK_INP_DIS                (* (reg8 *) Protection_CLK__INP_DIS)
/* LCD Common or Segment Drive */
#define Protection_CLK_LCD_COM_SEG            (* (reg8 *) Protection_CLK__LCD_COM_SEG)
/* Enable Segment LCD */
#define Protection_CLK_LCD_EN                 (* (reg8 *) Protection_CLK__LCD_EN)
/* Slew Rate Control */
#define Protection_CLK_SLW                    (* (reg8 *) Protection_CLK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Protection_CLK_PRTDSI__CAPS_SEL       (* (reg8 *) Protection_CLK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Protection_CLK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Protection_CLK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Protection_CLK_PRTDSI__OE_SEL0        (* (reg8 *) Protection_CLK__PRTDSI__OE_SEL0) 
#define Protection_CLK_PRTDSI__OE_SEL1        (* (reg8 *) Protection_CLK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Protection_CLK_PRTDSI__OUT_SEL0       (* (reg8 *) Protection_CLK__PRTDSI__OUT_SEL0) 
#define Protection_CLK_PRTDSI__OUT_SEL1       (* (reg8 *) Protection_CLK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Protection_CLK_PRTDSI__SYNC_OUT       (* (reg8 *) Protection_CLK__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Protection_CLK__SIO_CFG)
    #define Protection_CLK_SIO_HYST_EN        (* (reg8 *) Protection_CLK__SIO_HYST_EN)
    #define Protection_CLK_SIO_REG_HIFREQ     (* (reg8 *) Protection_CLK__SIO_REG_HIFREQ)
    #define Protection_CLK_SIO_CFG            (* (reg8 *) Protection_CLK__SIO_CFG)
    #define Protection_CLK_SIO_DIFF           (* (reg8 *) Protection_CLK__SIO_DIFF)
#endif /* (Protection_CLK__SIO_CFG) */

/* Interrupt Registers */
#if defined(Protection_CLK__INTSTAT)
    #define Protection_CLK_INTSTAT            (* (reg8 *) Protection_CLK__INTSTAT)
    #define Protection_CLK_SNAP               (* (reg8 *) Protection_CLK__SNAP)
    
	#define Protection_CLK_0_INTTYPE_REG 		(* (reg8 *) Protection_CLK__0__INTTYPE)
#endif /* (Protection_CLK__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Protection_CLK_H */


/* [] END OF FILE */
