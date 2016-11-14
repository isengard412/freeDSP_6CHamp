/*******************************************************************************
* File Name: SW_Reg1.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "SW_Reg1.h"

#if !defined(SW_Reg1_sts_intr_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: SW_Reg1_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 SW_Reg1_Read(void) 
{ 
    return SW_Reg1_Status;
}


/*******************************************************************************
* Function Name: SW_Reg1_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SW_Reg1_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SW_Reg1_Status_Aux_Ctrl |= SW_Reg1_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SW_Reg1_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void SW_Reg1_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    SW_Reg1_Status_Aux_Ctrl &= (uint8)(~SW_Reg1_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: SW_Reg1_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void SW_Reg1_WriteMask(uint8 mask) 
{
    #if(SW_Reg1_INPUTS < 8u)
    	mask &= ((uint8)(1u << SW_Reg1_INPUTS) - 1u);
	#endif /* End SW_Reg1_INPUTS < 8u */
    SW_Reg1_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: SW_Reg1_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 SW_Reg1_ReadMask(void) 
{
    return SW_Reg1_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
