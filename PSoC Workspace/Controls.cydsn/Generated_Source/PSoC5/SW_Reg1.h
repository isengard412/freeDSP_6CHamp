/*******************************************************************************
* File Name: SW_Reg1.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_SW_Reg1_H) /* CY_STATUS_REG_SW_Reg1_H */
#define CY_STATUS_REG_SW_Reg1_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} SW_Reg1_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 SW_Reg1_Read(void) ;
void SW_Reg1_InterruptEnable(void) ;
void SW_Reg1_InterruptDisable(void) ;
void SW_Reg1_WriteMask(uint8 mask) ;
uint8 SW_Reg1_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define SW_Reg1_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define SW_Reg1_INPUTS              7


/***************************************
*             Registers
***************************************/

/* Status Register */
#define SW_Reg1_Status             (* (reg8 *) SW_Reg1_sts_intr_sts_reg__STATUS_REG )
#define SW_Reg1_Status_PTR         (  (reg8 *) SW_Reg1_sts_intr_sts_reg__STATUS_REG )
#define SW_Reg1_Status_Mask        (* (reg8 *) SW_Reg1_sts_intr_sts_reg__MASK_REG )
#define SW_Reg1_Status_Aux_Ctrl    (* (reg8 *) SW_Reg1_sts_intr_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_SW_Reg1_H */


/* [] END OF FILE */
