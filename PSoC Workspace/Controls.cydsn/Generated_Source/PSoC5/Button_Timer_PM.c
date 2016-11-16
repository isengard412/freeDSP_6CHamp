/*******************************************************************************
* File Name: Button_Timer_PM.c
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

#include "Button_Timer.h"

static Button_Timer_backupStruct Button_Timer_backup;


/*******************************************************************************
* Function Name: Button_Timer_SaveConfig
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
*  Button_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Button_Timer_SaveConfig(void) 
{
    #if (!Button_Timer_UsingFixedFunction)
        Button_Timer_backup.TimerUdb = Button_Timer_ReadCounter();
        Button_Timer_backup.InterruptMaskValue = Button_Timer_STATUS_MASK;
        #if (Button_Timer_UsingHWCaptureCounter)
            Button_Timer_backup.TimerCaptureCounter = Button_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Button_Timer_UDB_CONTROL_REG_REMOVED)
            Button_Timer_backup.TimerControlRegister = Button_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Button_Timer_RestoreConfig
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
*  Button_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Button_Timer_RestoreConfig(void) 
{   
    #if (!Button_Timer_UsingFixedFunction)

        Button_Timer_WriteCounter(Button_Timer_backup.TimerUdb);
        Button_Timer_STATUS_MASK =Button_Timer_backup.InterruptMaskValue;
        #if (Button_Timer_UsingHWCaptureCounter)
            Button_Timer_SetCaptureCount(Button_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Button_Timer_UDB_CONTROL_REG_REMOVED)
            Button_Timer_WriteControlRegister(Button_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Button_Timer_Sleep
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
*  Button_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Button_Timer_Sleep(void) 
{
    #if(!Button_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Button_Timer_CTRL_ENABLE == (Button_Timer_CONTROL & Button_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Button_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Button_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Button_Timer_Stop();
    Button_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Button_Timer_Wakeup
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
*  Button_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Button_Timer_Wakeup(void) 
{
    Button_Timer_RestoreConfig();
    #if(!Button_Timer_UDB_CONTROL_REG_REMOVED)
        if(Button_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Button_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
