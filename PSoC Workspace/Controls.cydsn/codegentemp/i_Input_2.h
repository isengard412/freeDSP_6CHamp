/*******************************************************************************
* File Name: i_Input_2.h
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
#if !defined(CY_ISR_i_Input_2_H)
#define CY_ISR_i_Input_2_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void i_Input_2_Start(void);
void i_Input_2_StartEx(cyisraddress address);
void i_Input_2_Stop(void);

CY_ISR_PROTO(i_Input_2_Interrupt);

void i_Input_2_SetVector(cyisraddress address);
cyisraddress i_Input_2_GetVector(void);

void i_Input_2_SetPriority(uint8 priority);
uint8 i_Input_2_GetPriority(void);

void i_Input_2_Enable(void);
uint8 i_Input_2_GetState(void);
void i_Input_2_Disable(void);

void i_Input_2_SetPending(void);
void i_Input_2_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the i_Input_2 ISR. */
#define i_Input_2_INTC_VECTOR            ((reg32 *) i_Input_2__INTC_VECT)

/* Address of the i_Input_2 ISR priority. */
#define i_Input_2_INTC_PRIOR             ((reg8 *) i_Input_2__INTC_PRIOR_REG)

/* Priority of the i_Input_2 interrupt. */
#define i_Input_2_INTC_PRIOR_NUMBER      i_Input_2__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable i_Input_2 interrupt. */
#define i_Input_2_INTC_SET_EN            ((reg32 *) i_Input_2__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the i_Input_2 interrupt. */
#define i_Input_2_INTC_CLR_EN            ((reg32 *) i_Input_2__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the i_Input_2 interrupt state to pending. */
#define i_Input_2_INTC_SET_PD            ((reg32 *) i_Input_2__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the i_Input_2 interrupt. */
#define i_Input_2_INTC_CLR_PD            ((reg32 *) i_Input_2__INTC_CLR_PD_REG)


#endif /* CY_ISR_i_Input_2_H */


/* [] END OF FILE */
