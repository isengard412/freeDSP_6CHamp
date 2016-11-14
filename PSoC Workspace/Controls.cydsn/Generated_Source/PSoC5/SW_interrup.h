/*******************************************************************************
* File Name: SW_interrup.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_SW_interrup_H)
#define CY_ISR_SW_interrup_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SW_interrup_Start(void);
void SW_interrup_StartEx(cyisraddress address);
void SW_interrup_Stop(void);

CY_ISR_PROTO(SW_interrup_Interrupt);

void SW_interrup_SetVector(cyisraddress address);
cyisraddress SW_interrup_GetVector(void);

void SW_interrup_SetPriority(uint8 priority);
uint8 SW_interrup_GetPriority(void);

void SW_interrup_Enable(void);
uint8 SW_interrup_GetState(void);
void SW_interrup_Disable(void);

void SW_interrup_SetPending(void);
void SW_interrup_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SW_interrup ISR. */
#define SW_interrup_INTC_VECTOR            ((reg32 *) SW_interrup__INTC_VECT)

/* Address of the SW_interrup ISR priority. */
#define SW_interrup_INTC_PRIOR             ((reg8 *) SW_interrup__INTC_PRIOR_REG)

/* Priority of the SW_interrup interrupt. */
#define SW_interrup_INTC_PRIOR_NUMBER      SW_interrup__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SW_interrup interrupt. */
#define SW_interrup_INTC_SET_EN            ((reg32 *) SW_interrup__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SW_interrup interrupt. */
#define SW_interrup_INTC_CLR_EN            ((reg32 *) SW_interrup__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SW_interrup interrupt state to pending. */
#define SW_interrup_INTC_SET_PD            ((reg32 *) SW_interrup__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SW_interrup interrupt. */
#define SW_interrup_INTC_CLR_PD            ((reg32 *) SW_interrup__INTC_CLR_PD_REG)


#endif /* CY_ISR_SW_interrup_H */


/* [] END OF FILE */
