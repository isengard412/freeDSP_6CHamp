/*******************************************************************************
* File Name: Volume_ADC_PM.c
* Version 3.0
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "Volume_ADC.h"


/***************************************
* Local data allocation
***************************************/

static Volume_ADC_BACKUP_STRUCT  Volume_ADC_backup =
{
    Volume_ADC_DISABLED
};


/*******************************************************************************
* Function Name: Volume_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Volume_ADC_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Volume_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void Volume_ADC_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: Volume_ADC_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The Volume_ADC_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Volume_ADC_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Volume_ADC_Sleep(void)
{
    if((Volume_ADC_PWRMGR_SAR_REG  & Volume_ADC_ACT_PWR_SAR_EN) != 0u)
    {
        if((Volume_ADC_SAR_CSR0_REG & Volume_ADC_SAR_SOF_START_CONV) != 0u)
        {
            Volume_ADC_backup.enableState = Volume_ADC_ENABLED | Volume_ADC_STARTED;
        }
        else
        {
            Volume_ADC_backup.enableState = Volume_ADC_ENABLED;
        }
        Volume_ADC_Stop();
    }
    else
    {
        Volume_ADC_backup.enableState = Volume_ADC_DISABLED;
    }
}


/*******************************************************************************
* Function Name: Volume_ADC_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  Volume_ADC_Sleep() was called. If the component was enabled before the
*  Volume_ADC_Sleep() function was called, the
*  Volume_ADC_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  Volume_ADC_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Volume_ADC_Wakeup(void)
{
    if(Volume_ADC_backup.enableState != Volume_ADC_DISABLED)
    {
        Volume_ADC_Enable();
        #if(Volume_ADC_DEFAULT_CONV_MODE != Volume_ADC__HARDWARE_TRIGGER)
            if((Volume_ADC_backup.enableState & Volume_ADC_STARTED) != 0u)
            {
                Volume_ADC_StartConvert();
            }
        #endif /* End Volume_ADC_DEFAULT_CONV_MODE != Volume_ADC__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
