/*******************************************************************************
* File: main.c
*
* Version: 2.2
*
* Description:
*   This is a basic design source code.
*
* Note:
*  Pin_Vin pin (P0[4]) should be connected to the VR.
*  Verify that VR_PWR(J11) is jumpered to ON.
*
* Hardware Dependency:
*  CY8CKIT-001 DVK
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* This software is owned by Cypress Semiconductor Corporation and is protected
* by and subject to worldwide patent and copyright laws and treaties.
* Therefore, you may use this software only as provided in the license agreement
* accompanying the software package from which you obtained this software.
* CYPRESS AND ITS SUPPLIERS MAKE NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
* WITH REGARD TO THIS SOFTWARE, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*******************************************************************************/

#include <device.h>






/*******************************************************************************
* Function Name: main
********************************************************************************/
int main()
{
    
    CyGlobalIntEnable;

    
    CyDelay(3000);
    //Shutdown everything, init states
    Protection_CLR_Write(0u);
    Protection_CLK_Write(0u);
    Protection_IN_Write(1u);
    //Enable Register
    Protection_CLR_Write(1u);
    
    
    for(;;)
    {
        //Enable Clock
        CyDelay(200);
        Protection_CLK_Write(1u);
        CyDelay(200);
        Protection_CLK_Write(0u);
    }
}


/* [] END OF FILE */
