/***************************************************************************//**
* \file COM_pm.c
* \version 3.0
*
* \brief
*  This file provides Suspend/Resume APIs implementation.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_pvt.h"
#include "COM_Dp.h"
#include "cyapicallbacks.h"

/***************************************
* Custom Declarations
***************************************/
/* `#START PM_CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */


/***************************************
* Local data allocation
***************************************/

static COM_BACKUP_STRUCT  COM_backup;

#if (COM_DP_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_DP_ISR
    ****************************************************************************//**
    *
    *  This Interrupt Service Routine handles DP pin changes for wake-up from
    *  the sleep mode.
    *
    *******************************************************************************/
    CY_ISR(COM_DP_ISR)
    {
    #ifdef COM_DP_ISR_ENTRY_CALLBACK
        COM_DP_ISR_EntryCallback();
    #endif /* (COM_DP_ISR_ENTRY_CALLBACK) */

        /* `#START DP_USER_CODE` Place your code here */

        /* `#END` */

        (void) COM_Dp_ClearInterrupt();
		
	#ifdef COM_DP_ISR_EXIT_CALLBACK
        COM_DP_ISR_ExitCallback();
    #endif /* (COM_DP_ISR_EXIT_CALLBACK) */
    }
#endif /* (COM_DP_ISR_ACTIVE) */


/*******************************************************************************
* Function Name: COM_SaveConfig
****************************************************************************//**
*
*  Saves the current user configuration.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_SaveConfig(void) 
{
    /* Empty function added for the compatibility purpose. */
}


/*******************************************************************************
* Function Name: COM_RestoreConfig
****************************************************************************//**
*
*  Restores the current user configuration.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_RestoreConfig(void) 
{
    if (COM_configuration != 0u)
    {
        COM_ConfigReg();
        COM_EpStateInit();
    }
}


/*******************************************************************************
* Function Name: COM_Suspend
****************************************************************************//**
*
*  This function prepares the USBFS component to enter low power mode. The 
*  interrupt on falling edge on Dp pin is configured to wakeup device when the 
*  host drives resume condition. The pull-up is enabled on the Dp line while 
*  device is in low power mode. The supported low power modes are Deep Sleep 
*  (PSoC 4200L) and Sleep (PSoC 3/ PSoC 5LP).
*  
*  *Note* For PSoC 4200L devices, this function should not be called before 
*  entering Sleep.
*  
*  *Note* After enter low power mode, the data which is left in the IN or OUT 
*  endpoint buffers is not restored after wakeup and lost. Therefore it should 
*  be stored in the SRAM for OUT endpoint or read by the host for IN endpoint 
*  before enter low power mode.
*
* \globalvars
*  COM_backup.enable:  modified.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_Suspend(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    if (0u != (COM_CR0_REG & COM_CR0_ENABLE))
    {
        /* USB block is enabled. */
        COM_backup.enableState = 1u;

    #if (COM_EP_MANAGEMENT_DMA)
        COM_Stop_DMA(COM_MAX_EP);
    #endif /* (COM_EP_MANAGEMENT_DMA) */

    #if (CY_PSOC4)
        /* Suspend enter sequence. */
        COM_POWER_CTRL_REG |= (COM_POWER_CTRL_SUSPEND |
                                            COM_POWER_CTRL_SUSPEND_DEL);

        /* Store state of USB regulator and disable it. */
        COM_backup.mode = (uint8)  (COM_CR1_REG & COM_CR1_REG_ENABLE);
        COM_CR1_REG    &= (uint32) ~COM_CR1_REG_ENABLE;
        
        /* Store SIE interrupt sources. Valid bits are 0 - 4. */
        COM_backup.intrSeiMask = (uint8) COM_INTR_SIE_MASK_REG;

    #else
        /* Ensure USB transmit enable is low (USB_USBIO_CR0.ten). - Manual Transmission - Disabled. */
        COM_USBIO_CR0_REG &= (uint8) ~COM_USBIO_CR0_TEN;
        CyDelayUs(COM_WAIT_REG_STABILITY_50NS);  /*~50ns delay. */

        /* Disable the USBIO by asserting PM.USB_CR0.fsusbio_pd_n(Inverted) and pd_pullup_hv(Inverted) high. */
        COM_PM_USB_CR0_REG &= (uint8) ~(COM_PM_USB_CR0_PD_N |
                                                     COM_PM_USB_CR0_PD_PULLUP_N);

        /* Disable the SIE. */
        COM_CR0_REG &= (uint8) ~COM_CR0_ENABLE;

        CyDelayUs(COM_WAIT_REG_STABILITY_50NS);  /* ~50ns delay. */
        /* Store mode and disable VRegulator. */
        COM_backup.mode = (uint8) (COM_CR1_REG & COM_CR1_REG_ENABLE);
        COM_CR1_REG    &= (uint8) ~COM_CR1_REG_ENABLE;

        CyDelayUs(COM_WAIT_REG_STABILITY_1US); /* min 0.5us delay required. */

        /* Disable the USBIO reference by setting PM.USB_CR0.fsusbio_ref_en.*/
        COM_PM_USB_CR0_REG &= (uint8) ~COM_PM_USB_CR0_REF_EN;

        /* Switch DP and DM terminals to GPIO mode and disconnect 1.5k pull-up. */
        COM_USBIO_CR1_REG |= COM_USBIO_CR1_IOMODE;

        /* Disable USBFS block. */
        /* Clear power active and standby mode templates: disable USB block. */
        COM_PM_ACT_CFG_REG  &= (uint8) ~COM_PM_ACT_EN_FSUSB;
        COM_PM_STBY_CFG_REG &= (uint8) ~COM_PM_STBY_EN_FSUSB;

        CyDelayUs(COM_WAIT_REG_STABILITY_1US); /* min 0.5us delay required. */
    #endif /* (CY_PSOC4) */
    }
    else
    {
        COM_backup.enableState = 0u;
    }

    CyExitCriticalSection(enableInterrupts);

#if (COM_DP_ISR_ACTIVE)
    /* Clear active mode Dp interrupt source history. */
    (void) COM_Dp_ClearInterrupt();
    CyIntClearPending(COM_DP_INTC_VECT_NUM);

    CyIntEnable      (COM_DP_INTC_VECT_NUM);
#endif /* (COM_DP_ISR_ACTIVE). */
}


/*******************************************************************************
* Function Name: COM_Resume
****************************************************************************//**
*
*  This function prepares the USBFS component for active mode operation after 
*  exit low power mode. It restores the component active mode configuration such 
*  as device address assigned previously by the host, endpoints buffer and disables 
*  interrupt on Dp pin.
*  The supported low power modes are Deep Sleep (PSoC 4200L) and Sleep 
*  (PSoC 3/ PSoC 5LP).
*  
*  *Note* For PSoC 4200L devices, this function should not be called after 
*  exiting Sleep.
*  
*  *Note* To resume communication with the host, the data endpoints must be 
*  managed: the OUT endpoints must be enabled and IN endpoints must be loaded 
*  with data. For DMA with Automatic Buffer Management, all endpoints buffers 
*  must be initialized again before making them available to the host.
*
*
* \globalvars
*  COM_backup - checked.
*
* \reentrant
*  No.
*
*******************************************************************************/
void COM_Resume(void) 
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    if (0u != COM_backup.enableState)
    {
    #if (COM_DP_ISR_ACTIVE)
        CyIntDisable(COM_DP_INTC_VECT_NUM);
    #endif /* (COM_DP_ISR_ACTIVE) */

    #if (CY_PSOC4)
        /* Enable clock to USB IP. */
        COM_USB_CLK_EN_REG |= COM_USB_CLK_CSR_CLK_EN;

        /* Restore arbiter configuration for DMA transfers. */
        #if (COM_EP_MANAGEMENT_DMA)
            #if (COM_ARB_ISR_ACTIVE)
                /* Enable ARB EP interrupt sources. */
                COM_ARB_INT_EN_REG = COM_DEFAULT_ARB_INT_EN;
            #endif /* (COM_EP_MANAGEMENT_DMA) */

            /* Configure arbiter for Manual or Auto DMA operation and clear 
            * configuration completion. 
            */
            COM_ARB_CFG_REG = COM_DEFAULT_ARB_CFG;
        #endif /* (COM_EP_MANAGEMENT_DMA) */

        /* Restore level (hi, lo, med) for each interrupt source. */
        COM_INTR_LVL_SEL_REG = COM_DEFAULT_INTR_LVL_SEL;
        
        /* Store SIE interrupt sources. */
        COM_INTR_SIE_MASK_REG = (uint32) COM_backup.intrSeiMask;

        /* Set EP0.CR: ACK Setup, NAK IN/OUT. */
        COM_EP0_CR_REG = COM_MODE_NAK_IN_OUT;

        /* Restore data EP1-8 configuration. */
        COM_RestoreConfig();

        /* Restore state of USB regulator and wait until it supples stable power. */
        COM_CR1_REG |= COM_backup.mode;
        CyDelayUs(COM_WAIT_VREF_STABILITY);

        /* Suspend exit sequence. */
        COM_POWER_CTRL_REG &= (uint32) ~COM_POWER_CTRL_SUSPEND;
        CyDelayUs(COM_WAIT_SUSPEND_DEL_DISABLE);
        COM_POWER_CTRL_REG &= (uint32) ~COM_POWER_CTRL_SUSPEND_DEL;

    #else
        /* Set power active and standby mode templates: enable USB block. */
        COM_PM_ACT_CFG_REG  |= COM_PM_ACT_EN_FSUSB;
        COM_PM_STBY_CFG_REG |= COM_PM_STBY_EN_FSUSB;

        /* Enable core clock. */
        COM_USB_CLK_EN_REG |= COM_USB_CLK_ENABLE;

        /* Enable the USBIO reference by setting PM.USB_CR0.fsusbio_ref_en.*/
        COM_PM_USB_CR0_REG |= COM_PM_USB_CR0_REF_EN;

        /* The reference is available ~40us after power restored. */
        CyDelayUs(COM_WAIT_VREF_RESTORE);
        /* Restore state of USB regulator and wait until it supples stable power. */
        COM_CR1_REG |= COM_backup.mode;
        CyDelayUs(COM_WAIT_VREF_STABILITY);   /*~50ns delay. */

        /* Enable USBIO. */
        COM_PM_USB_CR0_REG |= COM_PM_USB_CR0_PD_N;
        CyDelayUs(COM_WAIT_PD_PULLUP_N_ENABLE);
        /* Set the USBIO pull-up enable. */
        COM_PM_USB_CR0_REG |= COM_PM_USB_CR0_PD_PULLUP_N;

        /* Restore arbiter configuration for DMA transfers. */
        #if (COM_EP_MANAGEMENT_DMA)
            #if (COM_ARB_ISR_ACTIVE)
                /* Enable ARB EP interrupt sources. */
                COM_ARB_INT_EN_REG = COM_DEFAULT_ARB_INT_EN;
            #endif /* (COM_EP_MANAGEMENT_DMA) */

            /* Configure arbiter for Manual or Auto DMA operation and clear 
            * configuration completion. 
            */
            COM_ARB_CFG_REG = COM_DEFAULT_ARB_CFG;
        #endif /* (COM_EP_MANAGEMENT_DMA) */

        /* Set EP0.CR: ACK Setup, STALL IN/OUT. */
        COM_EP0_CR_REG = COM_MODE_STALL_IN_OUT;

        /* Enable the USB IP to respond to USB traffic with the last address. */
        COM_CR0_REG |= COM_CR0_ENABLE;
        CyDelayCycles(COM_WAIT_CR0_REG_STABILITY);

        /* Enable D+ pull-up and keep USB control on IO. */
        COM_USBIO_CR1_REG = COM_USBIO_CR1_USBPUEN;

        /* Restore data EP1-8 configuration. */
        COM_RestoreConfig();
    #endif /* (CY_PSOC4) */
    }

    CyExitCriticalSection(enableInterrupts);
}


/* [] END OF FILE */
