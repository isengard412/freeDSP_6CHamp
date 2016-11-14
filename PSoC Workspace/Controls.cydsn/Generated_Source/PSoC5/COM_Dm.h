/*******************************************************************************
* File Name: COM_Dm.h  
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

#if !defined(CY_PINS_COM_Dm_H) /* Pins COM_Dm_H */
#define CY_PINS_COM_Dm_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "COM_Dm_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 COM_Dm__PORT == 15 && ((COM_Dm__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    COM_Dm_Write(uint8 value);
void    COM_Dm_SetDriveMode(uint8 mode);
uint8   COM_Dm_ReadDataReg(void);
uint8   COM_Dm_Read(void);
void    COM_Dm_SetInterruptMode(uint16 position, uint16 mode);
uint8   COM_Dm_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the COM_Dm_SetDriveMode() function.
     *  @{
     */
        #define COM_Dm_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define COM_Dm_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define COM_Dm_DM_RES_UP          PIN_DM_RES_UP
        #define COM_Dm_DM_RES_DWN         PIN_DM_RES_DWN
        #define COM_Dm_DM_OD_LO           PIN_DM_OD_LO
        #define COM_Dm_DM_OD_HI           PIN_DM_OD_HI
        #define COM_Dm_DM_STRONG          PIN_DM_STRONG
        #define COM_Dm_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define COM_Dm_MASK               COM_Dm__MASK
#define COM_Dm_SHIFT              COM_Dm__SHIFT
#define COM_Dm_WIDTH              1u

/* Interrupt constants */
#if defined(COM_Dm__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in COM_Dm_SetInterruptMode() function.
     *  @{
     */
        #define COM_Dm_INTR_NONE      (uint16)(0x0000u)
        #define COM_Dm_INTR_RISING    (uint16)(0x0001u)
        #define COM_Dm_INTR_FALLING   (uint16)(0x0002u)
        #define COM_Dm_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define COM_Dm_INTR_MASK      (0x01u) 
#endif /* (COM_Dm__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define COM_Dm_PS                     (* (reg8 *) COM_Dm__PS)
/* Data Register */
#define COM_Dm_DR                     (* (reg8 *) COM_Dm__DR)
/* Port Number */
#define COM_Dm_PRT_NUM                (* (reg8 *) COM_Dm__PRT) 
/* Connect to Analog Globals */                                                  
#define COM_Dm_AG                     (* (reg8 *) COM_Dm__AG)                       
/* Analog MUX bux enable */
#define COM_Dm_AMUX                   (* (reg8 *) COM_Dm__AMUX) 
/* Bidirectional Enable */                                                        
#define COM_Dm_BIE                    (* (reg8 *) COM_Dm__BIE)
/* Bit-mask for Aliased Register Access */
#define COM_Dm_BIT_MASK               (* (reg8 *) COM_Dm__BIT_MASK)
/* Bypass Enable */
#define COM_Dm_BYP                    (* (reg8 *) COM_Dm__BYP)
/* Port wide control signals */                                                   
#define COM_Dm_CTL                    (* (reg8 *) COM_Dm__CTL)
/* Drive Modes */
#define COM_Dm_DM0                    (* (reg8 *) COM_Dm__DM0) 
#define COM_Dm_DM1                    (* (reg8 *) COM_Dm__DM1)
#define COM_Dm_DM2                    (* (reg8 *) COM_Dm__DM2) 
/* Input Buffer Disable Override */
#define COM_Dm_INP_DIS                (* (reg8 *) COM_Dm__INP_DIS)
/* LCD Common or Segment Drive */
#define COM_Dm_LCD_COM_SEG            (* (reg8 *) COM_Dm__LCD_COM_SEG)
/* Enable Segment LCD */
#define COM_Dm_LCD_EN                 (* (reg8 *) COM_Dm__LCD_EN)
/* Slew Rate Control */
#define COM_Dm_SLW                    (* (reg8 *) COM_Dm__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define COM_Dm_PRTDSI__CAPS_SEL       (* (reg8 *) COM_Dm__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define COM_Dm_PRTDSI__DBL_SYNC_IN    (* (reg8 *) COM_Dm__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define COM_Dm_PRTDSI__OE_SEL0        (* (reg8 *) COM_Dm__PRTDSI__OE_SEL0) 
#define COM_Dm_PRTDSI__OE_SEL1        (* (reg8 *) COM_Dm__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define COM_Dm_PRTDSI__OUT_SEL0       (* (reg8 *) COM_Dm__PRTDSI__OUT_SEL0) 
#define COM_Dm_PRTDSI__OUT_SEL1       (* (reg8 *) COM_Dm__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define COM_Dm_PRTDSI__SYNC_OUT       (* (reg8 *) COM_Dm__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(COM_Dm__SIO_CFG)
    #define COM_Dm_SIO_HYST_EN        (* (reg8 *) COM_Dm__SIO_HYST_EN)
    #define COM_Dm_SIO_REG_HIFREQ     (* (reg8 *) COM_Dm__SIO_REG_HIFREQ)
    #define COM_Dm_SIO_CFG            (* (reg8 *) COM_Dm__SIO_CFG)
    #define COM_Dm_SIO_DIFF           (* (reg8 *) COM_Dm__SIO_DIFF)
#endif /* (COM_Dm__SIO_CFG) */

/* Interrupt Registers */
#if defined(COM_Dm__INTSTAT)
    #define COM_Dm_INTSTAT            (* (reg8 *) COM_Dm__INTSTAT)
    #define COM_Dm_SNAP               (* (reg8 *) COM_Dm__SNAP)
    
	#define COM_Dm_0_INTTYPE_REG 		(* (reg8 *) COM_Dm__0__INTTYPE)
#endif /* (COM_Dm__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_COM_Dm_H */


/* [] END OF FILE */
