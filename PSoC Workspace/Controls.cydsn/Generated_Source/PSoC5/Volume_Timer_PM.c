/*******************************************************************************
* File Name: Volume_Timer_PM.c
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

#include "Volume_Timer.h"

static Volume_Timer_backupStruct Volume_Timer_backup;


/*******************************************************************************
* Function Name: Volume_Timer_SaveConfig
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
*  Volume_Timer_backup:  Variables of this global structure are modified to
*  store the values of non retention configuration registers when Sleep() API is
*  called.
*
*******************************************************************************/
void Volume_Timer_SaveConfig(void) 
{
    #if (!Volume_Timer_UsingFixedFunction)
        Volume_Timer_backup.TimerUdb = Volume_Timer_ReadCounter();
        Volume_Timer_backup.InterruptMaskValue = Volume_Timer_STATUS_MASK;
        #if (Volume_Timer_UsingHWCaptureCounter)
            Volume_Timer_backup.TimerCaptureCounter = Volume_Timer_ReadCaptureCount();
        #endif /* Back Up capture counter register  */

        #if(!Volume_Timer_UDB_CONTROL_REG_REMOVED)
            Volume_Timer_backup.TimerControlRegister = Volume_Timer_ReadControlRegister();
        #endif /* Backup the enable state of the Timer component */
    #endif /* Backup non retention registers in UDB implementation. All fixed function registers are retention */
}


/*******************************************************************************
* Function Name: Volume_Timer_RestoreConfig
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
*  Volume_Timer_backup:  Variables of this global structure are used to
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Volume_Timer_RestoreConfig(void) 
{   
    #if (!Volume_Timer_UsingFixedFunction)

        Volume_Timer_WriteCounter(Volume_Timer_backup.TimerUdb);
        Volume_Timer_STATUS_MASK =Volume_Timer_backup.InterruptMaskValue;
        #if (Volume_Timer_UsingHWCaptureCounter)
            Volume_Timer_SetCaptureCount(Volume_Timer_backup.TimerCaptureCounter);
        #endif /* Restore Capture counter register*/

        #if(!Volume_Timer_UDB_CONTROL_REG_REMOVED)
            Volume_Timer_WriteControlRegister(Volume_Timer_backup.TimerControlRegister);
        #endif /* Restore the enable state of the Timer component */
    #endif /* Restore non retention registers in the UDB implementation only */
}


/*******************************************************************************
* Function Name: Volume_Timer_Sleep
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
*  Volume_Timer_backup.TimerEnableState:  Is modified depending on the
*  enable state of the block before entering sleep mode.
*
*******************************************************************************/
void Volume_Timer_Sleep(void) 
{
    #if(!Volume_Timer_UDB_CONTROL_REG_REMOVED)
        /* Save Counter's enable state */
        if(Volume_Timer_CTRL_ENABLE == (Volume_Timer_CONTROL & Volume_Timer_CTRL_ENABLE))
        {
            /* Timer is enabled */
            Volume_Timer_backup.TimerEnableState = 1u;
        }
        else
        {
            /* Timer is disabled */
            Volume_Timer_backup.TimerEnableState = 0u;
        }
    #endif /* Back up enable state from the Timer control register */
    Volume_Timer_Stop();
    Volume_Timer_SaveConfig();
}


/*******************************************************************************
* Function Name: Volume_Timer_Wakeup
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
*  Volume_Timer_backup.enableState:  Is used to restore the enable state of
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Volume_Timer_Wakeup(void) 
{
    Volume_Timer_RestoreConfig();
    #if(!Volume_Timer_UDB_CONTROL_REG_REMOVED)
        if(Volume_Timer_backup.TimerEnableState == 1u)
        {     /* Enable Timer's operation */
                Volume_Timer_Enable();
        } /* Do nothing if Timer was disabled before */
    #endif /* Remove this code section if Control register is removed */
}


/* [] END OF FILE */
