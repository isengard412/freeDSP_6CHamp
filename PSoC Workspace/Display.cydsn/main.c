/*******************************************************************************
* File Name: main.c
*
* Version: 0.0
*
* author: Lukas Creutzburg
*
*******************************************************************************/

#include "main.h"


int main()
{
    ILI9341init();

    for(;;)
    {
        ILI9341fillScreen(ILI9341_BLACK);
        CyDelay(500);
        ILI9341fillScreen(ILI9341_RED);
        CyDelay(500);
        ILI9341fillScreen(ILI9341_GREEN);
        CyDelay(500);
        ILI9341fillScreen(ILI9341_BLUE);
        CyDelay(500);
        ILI9341fillScreen(ILI9341_BLACK);
        CyDelay(500);
    }
}

    
   
	
/* [] END OF FILE */
