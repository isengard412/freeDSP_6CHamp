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

#if defined (__GNUC__)
    /* Add an explicit reference to the floating point printf library */
    /* to allow usage of the floating point conversion specifiers. */
    /* This is not linked in by default with the newlib-nano library. */
    asm (".global _printf_float");
#endif
#define USBFS_DEVICE    (0u)
/* The buffer size is equal to the maximum packet size of the IN and OUT bulk
* endpoints.
*/
#define USBUART_BUFFER_SIZE (64u)
#define LINE_STR_LENGTH     (20u)

char8* parity[] = {"None", "Odd", "Even", "Mark", "Space"};
char8* stop[]   = {"1", "1.5", "2"};

/* priorities */
#define LOWER_PRIORITY                      (4u)
#define DEFAULT_PRIORITY                    (3u)
#define HIGHER_PRIORITY                     (2u)
/* constants */
#define SW_DELAY                            10u
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
CY_ISR_PROTO(Button_Timer_Handler);
int protection_clear();
int protection_set();
int volume_zero();
int set_volume(uint8 vol);
int change_volume(int change);
int set_input(uint8 input);

/* Variables */
uint8_t globalstate = 2;
uint8_t input = 0b00000001;
uint8_t muted = 0;

/* Functions */
int main()
{
    /* USB init */
    uint16 count;
    uint8 buffer[USBUART_BUFFER_SIZE];
    /* Set initial state for Volume */
    Volume_1_Write(0u);
    Volume_2_Write(0u);
    Volume_ADC_Start();
    Volume_ADC_StartConvert();
    /* Set initial state for Protection */
    Protection_CLK_Write(0u);
    Protection_CLR_Write(1u);
    Protection_IN_Write(0u);
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
    Button_Timer_Start();
    Button_Timer_Interrupt_StartEx(Button_Timer_Handler);
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
    //CyIntSetPriority(NESTED_ERROR,LOWER_PRIORITY);
    //CyIntEnable(NESTED_ERROR);
    /* Changes initial priority for the GPIO interrupt */
    Button_Timer_Interrupt_SetPriority(LOWER_PRIORITY);
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
    
    USBUART_Start(USBFS_DEVICE, USBUART_5V_OPERATION);

    for(;;)
    {
        switch(globalstate){
            //Power OFF
            case 0:
                
                break;
            //Powering ON
            case 1:
                Power_LED_Write(0u);
                //enable controls
                i_Input_2_Enable();
                i_Input_1_Enable();
                i_Right_Enable();
                i_Down_Enable();
                i_Up_Enable();
                i_Left_Enable();
                i_Mute_Enable();
                i_Enter_Enable();
                //enable modules
                protection_set();
                //enable input
                set_input(input);
                //switch to ON state
                globalstate=3;
                break;
            //Powering OFF
            case 2:
                Power_LED_Write(1u);
                //disable inputs
                muted=0;
                set_input(0u);
                //disable modules
                protection_clear();
                //disable controls
                i_Input_2_Disable();
                i_Input_1_Disable();
                i_Right_Disable();
                i_Down_Disable();
                i_Up_Disable();
                i_Left_Disable();
                i_Mute_Disable();
                i_Enter_Disable();
                //switch to Power OFF state
                globalstate=0;
                break;
            //ON
            case 3:
                /* Host can send double SET_INTERFACE request. */
                if (0u != USBUART_IsConfigurationChanged())
                {
                    /* Initialize IN endpoints when device is configured. */
                    if (0u != USBUART_GetConfiguration())
                    {
                        /* Enumeration is done, enable OUT endpoint to receive data 
                         * from host. */
                        USBUART_CDC_Init();
                    }
                }

                /* Service USB CDC when device is configured. */
                if (0u != USBUART_GetConfiguration())
                {
                    /* Check for input data from host. */
                    if (0u != USBUART_DataIsReady())
                    {
                        /* Read received data and re-enable OUT endpoint. */
                        count = USBUART_GetAll(buffer);

                        if (0u != count)
                        {
                            /* Wait until component is ready to send data to host. */
                            while (0u == USBUART_CDCIsReady())
                            {
                            }

                            /* Send data back to host. */
                            
                            USBUART_PutData(buffer, count);

                            /* If the last sent packet is exactly the maximum packet 
                            *  size, it is followed by a zero-length packet to assure
                            *  that the end of the segment is properly identified by 
                            *  the terminal.
                            */
                            if (USBUART_BUFFER_SIZE == count)
                            {
                                /* Wait until component is ready to send data to PC. */
                                while (0u == USBUART_CDCIsReady())
                                {
                                }

                                /* Send zero-length packet to PC. */
                                USBUART_PutData(NULL, 0u);
                            }
                        }
                    }
                }
                break;
            //Other cases -> use 255 to trigger ERROR
            default:
                //ERROR Case
                //Shut everything down
                protection_clear();
                muted=0;
                set_input(0u);
                
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
int protection_clear()
{
    Protection_CLR_Write(0u);
    Protection_IN_Write(0u);
    Protection_CLK_Write(0u);
    return 0;
}

int protection_set()
{
    Protection_CLK_Write(0u);
    Protection_CLR_Write(1u);
    Protection_IN_Write(1u);
    //Enable amplifiers
    Protection_CLK_Write(1u);
    CyDelay(1);
    Protection_CLK_Write(0u);
    CyDelay(1);
    //ca. 700ms for trafo soft start!
    //Enable DSP
    Protection_CLK_Write(1u);
    CyDelay(1);
    Protection_CLK_Write(0u);
    CyDelay(1);
    //wait for DSP and amps to start
    CyDelay(2000);
    //connect speakers
    int i;
    for(i=0;i<6;i++)
    {
        Protection_CLK_Write(1u);
        CyDelay(1);
        Protection_CLK_Write(0u);
        CyDelay(1);
    }
    return 0;
}

/* reset volume */
int volume_zero()
{
    Volume_1_Write(1u);
    CyDelay(200);
    uint16 endvalue=0;
    while(endvalue<1943)
    {
        endvalue=(Volume_ADC_GetResult16() + Volume_ADC_GetResult16())/2;
        CyDelay(5);
    }
    Volume_1_Write(0u);
    return 0;
}

/* set volume in percent */
int set_volume(uint8 vol)
{
    //16 sec for a 100% turn
    if(vol > 100)
    {
        globalstate=255;
        return 1;
    }
    volume_zero();
    Volume_2_Write(1u);
    CyDelay(vol*160);
    Volume_2_Write(0u);
    return 0;
}

/* changes the volume relativ to position in percent */
int change_volume(int change)
{
    //16 sec for a 100% turn
    if(change > 100 || change < -100 || change == 0)
    {
        globalstate=255;
        return 1;
    }
    if(change > 0)
    {
        Volume_2_Write(1u);
        CyDelay(change*160);
        Volume_2_Write(0u);
    }
    else
    {
        Volume_1_Write(1u);
        CyDelay(change*160);
        Volume_1_Write(0u);
    }
    
    return 0;
}

/* gets volume */
int get_volume()
{
    uint16 value;
    Volume_Timer_Start();
    Volume_Timer_WriteCounter(0x270F);
    volume_zero();
    value = Volume_Timer_ReadCounter();
    Volume_Timer_Stop();
    if(value==0x270F) return 100; //timer was 0 and has been reset
    else value = (10000 - (value+1)) / 100;
    return value;
}

int set_input(uint8 input)
{
    //error for undefined inputs or more than one input set
    if(0)//input && !(input & (input-1)))
    {
        //trigger errorstate
        globalstate=255;
        return 1; //ERROR
    }
    //otherwise set inputs
    else
    {
        if(muted)
        {
            Input_Relais_0_Write(0u);
            Input_Relais_1_Write(0u);
            Input_Relais_2_Write(0u);
            Input_Relais_3_Write(0u);
            Input_Relais_4_Write(0u);
            Input_Relais_5_Write(0u);
            Input_Relais_6_Write(0u);
            Input_Relais_7_Write(0u);
        }
        else
        {
            Input_Relais_0_Write(input & 0b00000001);
            Input_Relais_1_Write((input & 0b00000010) >> 1);
            Input_Relais_2_Write((input & 0b00000100) >> 2);
            Input_Relais_3_Write((input & 0b00001000) >> 3);
            Input_Relais_4_Write((input & 0b00010000) >> 4);
            Input_Relais_5_Write((input & 0b00100000) >> 5);
            Input_Relais_6_Write((input & 0b01000000) >> 6);
            Input_Relais_7_Write((input & 0b10000000) >> 7);
        }
        //LEDs
        U1_LED_Write(input & 0b00000001);
        U2_LED_Write((input & 0b00000010) >> 1);
        U3_LED_Write((input & 0b00000100) >> 2);
        U4_LED_Write((input & 0b00001000) >> 3);
        U5_LED_Write((input & 0b00010000) >> 4);
        U6_LED_Write((input & 0b00100000) >> 5);
        U7_LED_Write((input & 0b01000000) >> 6);
        U8_LED_Write((input & 0b10000000) >> 7);
        D1_LED_Write(muted);
        return 0; //SUCCESS
    }
}

/* button interrupt handler */
CY_ISR(Input_2_Handler)
{
    i_Input_2_Disable();
    if(Input_2_SW_Read())
    {
        if(input < 0b10000000) input = input << 1;
        else input = 0b00000001;
        set_input(input);
        USBUART_PutChar('j');
    }
    //wait for button no longer pressed
    while(Input_2_SW_Read()){
        CyDelay(SW_DELAY);
    } 
    
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(Power_Handler)
{
    i_Power_Disable();
    if(Power_SW_Read())
    {
        //->powering on
        if(globalstate==0) globalstate=1;
        //->powering off
        else globalstate=2;
    }
    //wait for button no longer pressed
    while(Power_SW_Read()){
        CyDelay(SW_DELAY);
    }        
    /* Clear pending Interrupt */
    i_Power_ClearPending();
    i_Power_Enable();
}
CY_ISR(Input_1_Handler)
{
    i_Input_1_Disable();
    if(Input_1_SW_Read())
    {
        if(input > 0b00000001) input = input >> 1;
        else input = 0b10000000;
        set_input(input);
        USBUART_PutChar('i');
    }
    //wait for button no longer pressed
    while(Input_1_SW_Read()){
        CyDelay(SW_DELAY);
    } 
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(Right_Handler)
{
    i_Right_Disable();
    if(Right_SW_Read())
    {
        USBUART_PutChar('r');
    }
    //wait for button no longer pressed
    while(Right_SW_Read()){
        CyDelay(SW_DELAY);
    }     
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(Down_Handler)
{
    i_Down_Disable();
    if(Down_SW_Read())
    {
        USBUART_PutChar('d');
    }
    //wait for button no longer pressed
    while(Down_SW_Read()){
        CyDelay(SW_DELAY);
    } 
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(Up_Handler)
{
    i_Up_Disable();
    if(Up_SW_Read())
    {
        USBUART_PutChar('u');
    }
    //wait for button no longer pressed
    while(Up_SW_Read()){
        CyDelay(SW_DELAY);
    } 
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(Left_Handler)
{
    i_Left_Disable();
    if(Left_SW_Read())
    {
        USBUART_PutChar('l');
    }
    //wait for button no longer pressed
    while(Left_SW_Read()){
        CyDelay(SW_DELAY);
    } 
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(Mute_Handler)
{
    i_Mute_Disable();
    if(Mute_SW_Read())
    {
        if(muted) muted=0;
        else muted=1;
        set_input(input);
        USBUART_PutChar('m');
    }
    //wait for button no longer pressed
    while(Mute_SW_Read()){
        CyDelay(SW_DELAY);
    } 
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(E_Handler)
{
    i_Enter_Disable();
    if(Enter_SW_Read())
    {
        USBUART_PutChar('e');
    }
    //wait for button no longer pressed
    while(Enter_SW_Read()){
        CyDelay(SW_DELAY);
    } 
    /* Clear pending Interrupt */
    Button_Timer_Start();
}
CY_ISR(Button_Timer_Handler)
{
    Button_Timer_Stop();
    
    i_Input_2_ClearPending();
    i_Input_1_ClearPending();
    i_Right_ClearPending();
    i_Down_ClearPending();
    i_Up_ClearPending();
    i_Left_ClearPending();
    i_Mute_ClearPending();
    i_Enter_ClearPending();
    
    i_Input_2_Enable();
    i_Input_1_Enable();
    i_Right_Enable();
    i_Down_Enable();
    i_Up_Enable();
    i_Left_Enable();
    i_Mute_Enable();
    i_Enter_Enable();
    
    /* Clear pending Interrupt */
    Button_Timer_Interrupt_ClearPending();
}
CY_ISR(NestedErrorHandler)
{
    /* To fire this use */
    //CyIntSetPending(NESTED_ERROR);
    
    
    
    /* Clear pending Interrupt */
    CyIntClearPending(NESTED_ERROR);
}

/* [] END OF FILE */
