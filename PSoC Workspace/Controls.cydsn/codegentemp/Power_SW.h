/*******************************************************************************
* File Name: Power_SW.h  
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

#if !defined(CY_PINS_Power_SW_H) /* Pins Power_SW_H */
#define CY_PINS_Power_SW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Power_SW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Power_SW__PORT == 15 && ((Power_SW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Power_SW_Write(uint8 value);
void    Power_SW_SetDriveMode(uint8 mode);
uint8   Power_SW_ReadDataReg(void);
uint8   Power_SW_Read(void);
void    Power_SW_SetInterruptMode(uint16 position, uint16 mode);
uint8   Power_SW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Power_SW_SetDriveMode() function.
     *  @{
     */
        #define Power_SW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Power_SW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Power_SW_DM_RES_UP          PIN_DM_RES_UP
        #define Power_SW_DM_RES_DWN         PIN_DM_RES_DWN
        #define Power_SW_DM_OD_LO           PIN_DM_OD_LO
        #define Power_SW_DM_OD_HI           PIN_DM_OD_HI
        #define Power_SW_DM_STRONG          PIN_DM_STRONG
        #define Power_SW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Power_SW_MASK               Power_SW__MASK
#define Power_SW_SHIFT              Power_SW__SHIFT
#define Power_SW_WIDTH              1u

/* Interrupt constants */
#if defined(Power_SW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Power_SW_SetInterruptMode() function.
     *  @{
     */
        #define Power_SW_INTR_NONE      (uint16)(0x0000u)
        #define Power_SW_INTR_RISING    (uint16)(0x0001u)
        #define Power_SW_INTR_FALLING   (uint16)(0x0002u)
        #define Power_SW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Power_SW_INTR_MASK      (0x01u) 
#endif /* (Power_SW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Power_SW_PS                     (* (reg8 *) Power_SW__PS)
/* Data Register */
#define Power_SW_DR                     (* (reg8 *) Power_SW__DR)
/* Port Number */
#define Power_SW_PRT_NUM                (* (reg8 *) Power_SW__PRT) 
/* Connect to Analog Globals */                                                  
#define Power_SW_AG                     (* (reg8 *) Power_SW__AG)                       
/* Analog MUX bux enable */
#define Power_SW_AMUX                   (* (reg8 *) Power_SW__AMUX) 
/* Bidirectional Enable */                                                        
#define Power_SW_BIE                    (* (reg8 *) Power_SW__BIE)
/* Bit-mask for Aliased Register Access */
#define Power_SW_BIT_MASK               (* (reg8 *) Power_SW__BIT_MASK)
/* Bypass Enable */
#define Power_SW_BYP                    (* (reg8 *) Power_SW__BYP)
/* Port wide control signals */                                                   
#define Power_SW_CTL                    (* (reg8 *) Power_SW__CTL)
/* Drive Modes */
#define Power_SW_DM0                    (* (reg8 *) Power_SW__DM0) 
#define Power_SW_DM1                    (* (reg8 *) Power_SW__DM1)
#define Power_SW_DM2                    (* (reg8 *) Power_SW__DM2) 
/* Input Buffer Disable Override */
#define Power_SW_INP_DIS                (* (reg8 *) Power_SW__INP_DIS)
/* LCD Common or Segment Drive */
#define Power_SW_LCD_COM_SEG            (* (reg8 *) Power_SW__LCD_COM_SEG)
/* Enable Segment LCD */
#define Power_SW_LCD_EN                 (* (reg8 *) Power_SW__LCD_EN)
/* Slew Rate Control */
#define Power_SW_SLW                    (* (reg8 *) Power_SW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Power_SW_PRTDSI__CAPS_SEL       (* (reg8 *) Power_SW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Power_SW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Power_SW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Power_SW_PRTDSI__OE_SEL0        (* (reg8 *) Power_SW__PRTDSI__OE_SEL0) 
#define Power_SW_PRTDSI__OE_SEL1        (* (reg8 *) Power_SW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Power_SW_PRTDSI__OUT_SEL0       (* (reg8 *) Power_SW__PRTDSI__OUT_SEL0) 
#define Power_SW_PRTDSI__OUT_SEL1       (* (reg8 *) Power_SW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Power_SW_PRTDSI__SYNC_OUT       (* (reg8 *) Power_SW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Power_SW__SIO_CFG)
    #define Power_SW_SIO_HYST_EN        (* (reg8 *) Power_SW__SIO_HYST_EN)
    #define Power_SW_SIO_REG_HIFREQ     (* (reg8 *) Power_SW__SIO_REG_HIFREQ)
    #define Power_SW_SIO_CFG            (* (reg8 *) Power_SW__SIO_CFG)
    #define Power_SW_SIO_DIFF           (* (reg8 *) Power_SW__SIO_DIFF)
#endif /* (Power_SW__SIO_CFG) */

/* Interrupt Registers */
#if defined(Power_SW__INTSTAT)
    #define Power_SW_INTSTAT            (* (reg8 *) Power_SW__INTSTAT)
    #define Power_SW_SNAP               (* (reg8 *) Power_SW__SNAP)
    
	#define Power_SW_0_INTTYPE_REG 		(* (reg8 *) Power_SW__0__INTTYPE)
#endif /* (Power_SW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Power_SW_H */


/* [] END OF FILE */
