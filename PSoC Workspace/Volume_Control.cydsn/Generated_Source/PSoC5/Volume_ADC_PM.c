/*******************************************************************************
* File Name: Volume_ADC_PM.c
* Version 3.20
*
* Description:
*  This file provides the power manager source code to the API for the
*  Delta-Sigma ADC Component.
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

static Volume_ADC_BACKUP_STRUCT Volume_ADC_backup =
{
    Volume_ADC_DISABLED,
    Volume_ADC_CFG1_DEC_CR
};


/*******************************************************************************
* Function Name: Volume_ADC_SaveConfig
********************************************************************************
*
* Summary:
*  Save the register configuration which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Volume_ADC_backup:  This global structure variable is used to store
*  configuration registers which are non retention whenever user wants to go
*  sleep mode by calling Sleep() API.
*
*******************************************************************************/
void Volume_ADC_SaveConfig(void) 
{
    Volume_ADC_backup.deccr = Volume_ADC_DEC_CR_REG;
}


/*******************************************************************************
* Function Name: Volume_ADC_RestoreConfig
********************************************************************************
*
* Summary:
*  Restore the register configurations which are not retention.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Volume_ADC_backup:  This global structure variable is used to restore
*  configuration registers which are non retention whenever user wants to switch
*  to active power mode by calling Wakeup() API.
*
*******************************************************************************/
void Volume_ADC_RestoreConfig(void) 
{
    Volume_ADC_DEC_CR_REG = Volume_ADC_backup.deccr;
}


/*******************************************************************************
* Function Name: Volume_ADC_Sleep
********************************************************************************
*
* Summary:
*  Stops the operation of the block and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Volume_ADC_backup:  The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void Volume_ADC_Sleep(void) 
{
    /* Save ADC enable state */
    if((Volume_ADC_ACT_PWR_DEC_EN == (Volume_ADC_PWRMGR_DEC_REG & Volume_ADC_ACT_PWR_DEC_EN)) &&
       (Volume_ADC_ACT_PWR_DSM_EN == (Volume_ADC_PWRMGR_DSM_REG & Volume_ADC_ACT_PWR_DSM_EN)))
    {
        /* Component is enabled */
        Volume_ADC_backup.enableState = Volume_ADC_ENABLED;
        if((Volume_ADC_DEC_CR_REG & Volume_ADC_DEC_START_CONV) != 0u)
        {   
            /* Conversion is started */
            Volume_ADC_backup.enableState |= Volume_ADC_STARTED;
        }
		
        /* Stop the configuration */
        Volume_ADC_Stop();
    }
    else
    {
        /* Component is disabled */
        Volume_ADC_backup.enableState = Volume_ADC_DISABLED;
    }

    /* Save the user configuration */
    Volume_ADC_SaveConfig();
}


/*******************************************************************************
* Function Name: Volume_ADC_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and enables the power to the block.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  Volume_ADC_backup:  The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void Volume_ADC_Wakeup(void) 
{
    /* Restore the configuration */
    Volume_ADC_RestoreConfig();

    /* Enables the component operation */
    if(Volume_ADC_backup.enableState != Volume_ADC_DISABLED)
    {
        Volume_ADC_Enable();
        if((Volume_ADC_backup.enableState & Volume_ADC_STARTED) != 0u)
        {
            Volume_ADC_StartConvert();
        }
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
