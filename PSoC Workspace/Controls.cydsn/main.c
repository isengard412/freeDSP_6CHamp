/*******************************************************************************
* File Name: main.c
*
* Version: 1.00
*
* Description:
*  This is the source code for the Interrupts example project of the Interrupt
*  and cy_boot components.
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <project.h>

/* priorities */
#define DEFAULT_PRIORITY                    (3u)
#define HIGHER_PRIORITY                     (2u)
/* constants */
#define SW_DELAY                            150u
#define HIGHEST_INPUT                       (0b00001000u)
#define NESTED_ERROR                        (1u)


/* Interrupt prototypes */
CY_ISR_PROTO(NestedErrorHandler);
CY_ISR_PROTO(Input_2_Handler);
CY_ISR_PROTO(Power_Handler);
CY_ISR_PROTO(Input_1_Handler);
CY_ISR_PROTO(Right_Handler);
CY_ISR_PROTO(Down_Handler);
CY_ISR_PROTO(Up_Handler);
CY_ISR_PROTO(Left_Handler);
CY_ISR_PROTO(Mute_Handler);
CY_ISR_PROTO(E_Handler);
int set_input(uint8 input);

/* Variables */
uint8 globalstate = 0;
uint8 input = 0b00000001;

/* Functions */
int main()
{
    /* Set initial state for Input selection */
    set_input(input);
    /* Set initial state for LEDs */
    Power_LED_Write(1u);
    D1_LED_Write(1u);
    D2_LED_Write(1u);
    D3_LED_Write(1u);
    U1_LED_Write(1u);
    U2_LED_Write(1u);
    U3_LED_Write(1u);
    U4_LED_Write(1u);
    U5_LED_Write(1u);
    U6_LED_Write(1u);
    U7_LED_Write(1u);
    U8_LED_Write(1u);
    CyDelay(500);
    Power_LED_Write(0u);
    D1_LED_Write(0u);
    D2_LED_Write(0u);
    D3_LED_Write(0u);
    U1_LED_Write(0u);
    U2_LED_Write(0u);
    U3_LED_Write(0u);
    U4_LED_Write(0u);
    U5_LED_Write(0u);
    U6_LED_Write(0u);
    U7_LED_Write(0u);
    U8_LED_Write(0u);


    /* Sets up the GPIO interrupt and enables it */
    i_Input_2_StartEx(Input_2_Handler);
    i_Power_StartEx(Power_Handler);
    i_Input_1_StartEx(Input_1_Handler);
    i_Right_StartEx(Right_Handler);
    i_Down_StartEx(Down_Handler);
    i_Up_StartEx(Up_Handler);
    i_Left_StartEx(Left_Handler);
    i_Mute_StartEx(Mute_Handler);
    i_Enter_StartEx(E_Handler);

    /* Sets up the nested interrupt, sets priority and enables it */
    //CyIntSetVector(NESTED_ERROR,NestedErrorHandler);
    //CyIntSetPriority(NESTED_ERROR,HIGHER_PRIORITY);
    //CyIntEnable(NESTED_ERROR);
    /* Changes initial priority for the GPIO interrupt */
    i_Input_2_SetPriority(DEFAULT_PRIORITY);
    i_Power_SetPriority(DEFAULT_PRIORITY);
    i_Input_1_SetPriority(DEFAULT_PRIORITY);
    i_Right_SetPriority(DEFAULT_PRIORITY);
    i_Down_SetPriority(DEFAULT_PRIORITY);
    i_Up_SetPriority(DEFAULT_PRIORITY);
    i_Left_SetPriority(DEFAULT_PRIORITY);
    i_Mute_SetPriority(DEFAULT_PRIORITY);
    i_Enter_SetPriority(DEFAULT_PRIORITY);

    /* Enable global interrupts */
    CyGlobalIntEnable;

    for(;;)
    {
        switch(globalstate){
            //Power OFF
            case 0:
                Power_LED_Write(1u);
                break;
            //Powering ON
            case 1:
                Power_LED_Write(0u);
                set_input(input);
                //switch to ON state
                globalstate=3;
                break;
            //Powering OFF
            case 2:
                //switch to Power OFF state
                globalstate=0;
                break;
            //ON
            case 3:
                break;
            //Other cases -> use 255 to trigger ERROR
            default:
                //ERROR Case
                //Shut everything down
                Input_Relais_0_Write(0u);
                Input_Relais_1_Write(0u);
                Input_Relais_2_Write(0u);
                Input_Relais_3_Write(0u);
                
                //Blink Power_LED
                while(1){
                    Power_LED_Write(!Power_LED_Read());
                    CyDelay(100);
                }
                break;
        }
    }
}

/* helper functions */
int set_input(uint8 input)
{
    //error for undefined inputs or more than one input set
    if( input & 0xF0)// || (input && !(input & (input-1))) )
    {
        //trigger errorstate
        globalstate=255;
        return 1; //ERROR
    }
    //otherwise set inputs
    else
    {
        Input_Relais_0_Write(input & 0b00000001);
        U1_LED_Write(input & 0b00000001);
        Input_Relais_1_Write((input & 0b00000010) >> 1);
        U2_LED_Write((input & 0b00000010) >> 1);
        Input_Relais_2_Write((input & 0b00000100) >> 2);
        U3_LED_Write((input & 0b00000100) >> 2);
        Input_Relais_3_Write((input & 0b00001000) >> 3);
        U4_LED_Write((input & 0b00001000) >> 3);
        return 0; //SUCCESS
    }
}

/* button interrupt handler */
CY_ISR(Input_2_Handler)
{
    if(Input_2_SW_Read())
    {
        if(input < HIGHEST_INPUT) input = input << 1;
        else input = 0b00000001;
        set_input(input);
        CyDelay(SW_DELAY);
    }
    
    /* Clear pending Interrupt */
    i_Input_2_ClearPending();
}
CY_ISR(Power_Handler)
{
    if(Power_SW_Read())
    {
        //->powering on
        if(globalstate==0) globalstate=1;
        //->powering off
        else globalstate=2;
        CyDelay(SW_DELAY);
    }
        
    /* Clear pending Interrupt */
    i_Power_ClearPending();
}
CY_ISR(Input_1_Handler)
{
    if(Input_1_SW_Read())
    {
        if(input > 0b00000001) input = input >> 1;
        else input = HIGHEST_INPUT;
        set_input(input);
        CyDelay(SW_DELAY);
    }
    
    /* Clear pending Interrupt */
    i_Input_1_ClearPending();
}
CY_ISR(Right_Handler)
{
    if(Right_SW_Read())
    {
        U4_LED_Write(!U4_LED_Read());
        CyDelay(SW_DELAY);
    }
        
    /* Clear pending Interrupt */
    i_Right_ClearPending();
}
CY_ISR(Down_Handler)
{
    if(Down_SW_Read())
    {
        U5_LED_Write(!U5_LED_Read());
        CyDelay(SW_DELAY);
    }
    
    /* Clear pending Interrupt */
    i_Down_ClearPending();
}
CY_ISR(Up_Handler)
{
    if(Up_SW_Read())
    {
        U6_LED_Write(!U6_LED_Read());
        CyDelay(SW_DELAY);
    }
        
    /* Clear pending Interrupt */
    i_Up_ClearPending();
}
CY_ISR(Left_Handler)
{
    if(Left_SW_Read())
    {
        U7_LED_Write(!U7_LED_Read());
        CyDelay(SW_DELAY);
    }
        
    /* Clear pending Interrupt */
    i_Left_ClearPending();
}
CY_ISR(Mute_Handler)
{
    if(Mute_SW_Read())
    {
        U8_LED_Write(!U8_LED_Read());
        CyDelay(SW_DELAY);
    }
    
    /* Clear pending Interrupt */
    i_Mute_ClearPending();
}
CY_ISR(E_Handler)
{
    if(Enter_SW_Read())
    {
        D1_LED_Write(!D1_LED_Read());
        CyDelay(SW_DELAY);
    }
        
    /* Clear pending Interrupt */
    i_Enter_ClearPending();
}
CY_ISR(NestedErrorHandler)
{
    /* To fire this use */
    //CyIntSetPending(NESTED_ERROR);
    
    for(;;)
    {
        Power_LED_Write(!Power_LED_Read());
        CyDelay(250);
    }
    
    /* Clear pending Interrupt */
    CyIntClearPending(NESTED_ERROR);
}

/* [] END OF FILE */
