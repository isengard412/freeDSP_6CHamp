/*******************************************************************************
* File Name: i_Down.h
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
#if !defined(CY_ISR_i_Down_H)
#define CY_ISR_i_Down_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void i_Down_Start(void);
void i_Down_StartEx(cyisraddress address);
void i_Down_Stop(void);

CY_ISR_PROTO(i_Down_Interrupt);

void i_Down_SetVector(cyisraddress address);
cyisraddress i_Down_GetVector(void);

void i_Down_SetPriority(uint8 priority);
uint8 i_Down_GetPriority(void);

void i_Down_Enable(void);
uint8 i_Down_GetState(void);
void i_Down_Disable(void);

void i_Down_SetPending(void);
void i_Down_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the i_Down ISR. */
#define i_Down_INTC_VECTOR            ((reg32 *) i_Down__INTC_VECT)

/* Address of the i_Down ISR priority. */
#define i_Down_INTC_PRIOR             ((reg8 *) i_Down__INTC_PRIOR_REG)

/* Priority of the i_Down interrupt. */
#define i_Down_INTC_PRIOR_NUMBER      i_Down__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable i_Down interrupt. */
#define i_Down_INTC_SET_EN            ((reg32 *) i_Down__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the i_Down interrupt. */
#define i_Down_INTC_CLR_EN            ((reg32 *) i_Down__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the i_Down interrupt state to pending. */
#define i_Down_INTC_SET_PD            ((reg32 *) i_Down__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the i_Down interrupt. */
#define i_Down_INTC_CLR_PD            ((reg32 *) i_Down__INTC_CLR_PD_REG)


#endif /* CY_ISR_i_Down_H */


/* [] END OF FILE */
