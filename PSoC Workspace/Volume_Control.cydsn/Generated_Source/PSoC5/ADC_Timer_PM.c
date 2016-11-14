/*******************************************************************************
* File Name: ADC_Timer_PM.c
* Version 2.70
*
*  Description:
*     This file provides the power management source code to API for the
*     Timer.
*
*   Note:
*     None
*
*******************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
********************************************************************************/

#include "ADC_Timer.h"

static ADC_Timer_backupStruct ADC_Timer_backup;


/*******************************************************************************
* Function Name: ADC_Timer_SaveConfig
********************************************************************************
*
* Summary:
*     Save the current user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  ADC_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void ADC_Timer_SaveConfig(void) 
{
    #if (!ADC_Timer_UsingFixedFunction)
        ADC_Timer_backup.TimerUdb = ADC_Timer_ReadCounter();
        ADC_Timer_backup.InterruptMaskValue = ADC_Timer_STATUS_MASK;
        #if (ADC_Timer_UsingHWCaptureCounter)
            ADC_Timer_backup.TimerCaptureCounter = ADC_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!ADC_Timer_UDB_CONTROL_REG_REMOVED)
            ADC_Timer_backup.TimerControlRegister = ADC_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: ADC_Timer_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  ADC_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void ADC_Timer_RestoreConfig(void) 
{   
    #if (!ADC_Timer_UsingFixedFunction)

        ADC_Timer_WriteCounter(ADC_Timer_backup.TimerUdb);
        ADC_Timer_STATUS_MASK =ADC_Timer_backup.InterruptMaskValue;
        #if (ADC_Timer_UsingHWCaptureCounter)
            ADC_Timer_SetCaptureCount(ADC_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!ADC_Timer_UDB_CONTROL_REG_REMOVED)
            ADC_Timer_WriteControlRegister(ADC_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: ADC_Timer_Sleep
********************************************************************************
*
* Summary:
*     Stop and Save the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  ADC_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void ADC_Timer_Sleep(void) 
{
    #if(!ADC_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(ADC_Timer_CTRL_ENABLE == (ADC_Timer_CONTROL & ADC_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            ADC_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            ADC_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    ADC_Timer_Stop();
    ADC_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: ADC_Timer_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  ADC_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void ADC_Timer_Wakeup(void) 
{
    ADC_Timer_RestoreConfig();
    #if(!ADC_Timer_UDB_CONTROL_REG_REMOVED)
        if(ADC_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                ADC_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
