/*******************************************************************************
* File Name: Volume_0.h  
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

#if !defined(CY_PINS_Volume_0_H) /* Pins Volume_0_H */
#define CY_PINS_Volume_0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Volume_0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Volume_0__PORT == 15 && ((Volume_0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Volume_0_Write(uint8 value);
void    Volume_0_SetDriveMode(uint8 mode);
uint8   Volume_0_ReadDataReg(void);
uint8   Volume_0_Read(void);
void    Volume_0_SetInterruptMode(uint16 position, uint16 mode);
uint8   Volume_0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Volume_0_SetDriveMode() function.
     *  @{
     */
        #define Volume_0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Volume_0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Volume_0_DM_RES_UP          PIN_DM_RES_UP
        #define Volume_0_DM_RES_DWN         PIN_DM_RES_DWN
        #define Volume_0_DM_OD_LO           PIN_DM_OD_LO
        #define Volume_0_DM_OD_HI           PIN_DM_OD_HI
        #define Volume_0_DM_STRONG          PIN_DM_STRONG
        #define Volume_0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Volume_0_MASK               Volume_0__MASK
#define Volume_0_SHIFT              Volume_0__SHIFT
#define Volume_0_WIDTH              1u

/* Interrupt constants */
#if defined(Volume_0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Volume_0_SetInterruptMode() function.
     *  @{
     */
        #define Volume_0_INTR_NONE      (uint16)(0x0000u)
        #define Volume_0_INTR_RISING    (uint16)(0x0001u)
        #define Volume_0_INTR_FALLING   (uint16)(0x0002u)
        #define Volume_0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Volume_0_INTR_MASK      (0x01u) 
#endif /* (Volume_0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Volume_0_PS                     (* (reg8 *) Volume_0__PS)
/* Data Register */
#define Volume_0_DR                     (* (reg8 *) Volume_0__DR)
/* Port Number */
#define Volume_0_PRT_NUM                (* (reg8 *) Volume_0__PRT) 
/* Connect to Analog Globals */                                                  
#define Volume_0_AG                     (* (reg8 *) Volume_0__AG)                       
/* Analog MUX bux enable */
#define Volume_0_AMUX                   (* (reg8 *) Volume_0__AMUX) 
/* Bidirectional Enable */                                                        
#define Volume_0_BIE                    (* (reg8 *) Volume_0__BIE)
/* Bit-mask for Aliased Register Access */
#define Volume_0_BIT_MASK               (* (reg8 *) Volume_0__BIT_MASK)
/* Bypass Enable */
#define Volume_0_BYP                    (* (reg8 *) Volume_0__BYP)
/* Port wide control signals */                                                   
#define Volume_0_CTL                    (* (reg8 *) Volume_0__CTL)
/* Drive Modes */
#define Volume_0_DM0                    (* (reg8 *) Volume_0__DM0) 
#define Volume_0_DM1                    (* (reg8 *) Volume_0__DM1)
#define Volume_0_DM2                    (* (reg8 *) Volume_0__DM2) 
/* Input Buffer Disable Override */
#define Volume_0_INP_DIS                (* (reg8 *) Volume_0__INP_DIS)
/* LCD Common or Segment Drive */
#define Volume_0_LCD_COM_SEG            (* (reg8 *) Volume_0__LCD_COM_SEG)
/* Enable Segment LCD */
#define Volume_0_LCD_EN                 (* (reg8 *) Volume_0__LCD_EN)
/* Slew Rate Control */
#define Volume_0_SLW                    (* (reg8 *) Volume_0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Volume_0_PRTDSI__CAPS_SEL       (* (reg8 *) Volume_0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Volume_0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Volume_0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Volume_0_PRTDSI__OE_SEL0        (* (reg8 *) Volume_0__PRTDSI__OE_SEL0) 
#define Volume_0_PRTDSI__OE_SEL1        (* (reg8 *) Volume_0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Volume_0_PRTDSI__OUT_SEL0       (* (reg8 *) Volume_0__PRTDSI__OUT_SEL0) 
#define Volume_0_PRTDSI__OUT_SEL1       (* (reg8 *) Volume_0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Volume_0_PRTDSI__SYNC_OUT       (* (reg8 *) Volume_0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Volume_0__SIO_CFG)
    #define Volume_0_SIO_HYST_EN        (* (reg8 *) Volume_0__SIO_HYST_EN)
    #define Volume_0_SIO_REG_HIFREQ     (* (reg8 *) Volume_0__SIO_REG_HIFREQ)
    #define Volume_0_SIO_CFG            (* (reg8 *) Volume_0__SIO_CFG)
    #define Volume_0_SIO_DIFF           (* (reg8 *) Volume_0__SIO_DIFF)
#endif /* (Volume_0__SIO_CFG) */

/* Interrupt Registers */
#if defined(Volume_0__INTSTAT)
    #define Volume_0_INTSTAT            (* (reg8 *) Volume_0__INTSTAT)
    #define Volume_0_SNAP               (* (reg8 *) Volume_0__SNAP)
    
	#define Volume_0_0_INTTYPE_REG 		(* (reg8 *) Volume_0__0__INTTYPE)
#endif /* (Volume_0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Volume_0_H */


/* [] END OF FILE */
