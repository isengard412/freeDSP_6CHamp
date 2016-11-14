/*******************************************************************************
* File Name: ILI9341.c
*
* Version: 1.2
* Author: Lukas Creutzburg
*
*******************************************************************************/

#include "ILI9341.h"

uint16 _width=320,_height=240;

void ILI9341init()
{
    SPIinit();
    Reset_Write(1u);
    CyDelay(5);
    Reset_Write(0u);
    CyDelay(20);
    Reset_Write(1u);
    CyDelay(150);
    
    //Initialization
    ILI9341writecommand(0xEF);
    ILI9341writedata(0x03);
    ILI9341writedata(0x80);
    ILI9341writedata(0x02);

    ILI9341writecommand(0xCF);  
    ILI9341writedata(0x00); 
    ILI9341writedata(0XC1); 
    ILI9341writedata(0X30); 

    ILI9341writecommand(0xED);  
    ILI9341writedata(0x64); 
    ILI9341writedata(0x03); 
    ILI9341writedata(0X12); 
    ILI9341writedata(0X81); 

    ILI9341writecommand(0xE8);  
    ILI9341writedata(0x85); 
    ILI9341writedata(0x00); 
    ILI9341writedata(0x78); 

    ILI9341writecommand(0xCB);  
    ILI9341writedata(0x39); 
    ILI9341writedata(0x2C); 
    ILI9341writedata(0x00); 
    ILI9341writedata(0x34); 
    ILI9341writedata(0x02); 

    ILI9341writecommand(0xF7);  
    ILI9341writedata(0x20); 

    ILI9341writecommand(0xEA);  
    ILI9341writedata(0x00); 
    ILI9341writedata(0x00); 

    ILI9341writecommand(ILI9341_PWCTR1);    //Power control 
    ILI9341writedata(0x23);   //VRH[5:0] 

    ILI9341writecommand(ILI9341_PWCTR2);    //Power control 
    ILI9341writedata(0x10);   //SAP[2:0];BT[3:0] 

    ILI9341writecommand(ILI9341_VMCTR1);    //VCM control 
    ILI9341writedata(0x3e); //¶Ô±È¶Èµ÷½Ú
    ILI9341writedata(0x28); 

    ILI9341writecommand(ILI9341_VMCTR2);    //VCM control2 
    ILI9341writedata(0x86);  //--

    ILI9341writecommand(ILI9341_MADCTL);    // Memory Access Control 
    ILI9341writedata(0x48);

    ILI9341writecommand(ILI9341_PIXFMT);    
    ILI9341writedata(0x55); 

    ILI9341writecommand(ILI9341_FRMCTR1);    
    ILI9341writedata(0x00);  
    ILI9341writedata(0x18); 

    ILI9341writecommand(ILI9341_DFUNCTR);    // Display Function Control 
    ILI9341writedata(0x08); 
    ILI9341writedata(0x82);
    ILI9341writedata(0x27);  

    ILI9341writecommand(0xF2);    // 3Gamma Function Disable 
    ILI9341writedata(0x00); 

    ILI9341writecommand(ILI9341_GAMMASET);    //Gamma curve selected 
    ILI9341writedata(0x01); 

    ILI9341writecommand(ILI9341_GMCTRP1);    //Set Gamma 
    ILI9341writedata(0x0F); 
    ILI9341writedata(0x31); 
    ILI9341writedata(0x2B); 
    ILI9341writedata(0x0C); 
    ILI9341writedata(0x0E); 
    ILI9341writedata(0x08); 
    ILI9341writedata(0x4E); 
    ILI9341writedata(0xF1); 
    ILI9341writedata(0x37); 
    ILI9341writedata(0x07); 
    ILI9341writedata(0x10); 
    ILI9341writedata(0x03); 
    ILI9341writedata(0x0E); 
    ILI9341writedata(0x09); 
    ILI9341writedata(0x00); 

    ILI9341writecommand(ILI9341_GMCTRN1);    //Set Gamma 
    ILI9341writedata(0x00); 
    ILI9341writedata(0x0E); 
    ILI9341writedata(0x14); 
    ILI9341writedata(0x03); 
    ILI9341writedata(0x11); 
    ILI9341writedata(0x07); 
    ILI9341writedata(0x31); 
    ILI9341writedata(0xC1); 
    ILI9341writedata(0x48); 
    ILI9341writedata(0x08); 
    ILI9341writedata(0x0F); 
    ILI9341writedata(0x0C); 
    ILI9341writedata(0x31); 
    ILI9341writedata(0x36); 
    ILI9341writedata(0x0F); 
    
    //LED on
    LED_Write(1u);
}

void ILI9341writecommand(uint8 c)
{
    DC_Write(0u);
    SPIsendNumber(c);
}

void ILI9341writedata(uint8 d)
{
    DC_Write(1u);
    SPIsendNumber(d);
}

void ILI9341setAddrWindow(uint16 x0, uint16 y0, uint16 x1, uint16 y1) 
{
  ILI9341writecommand(ILI9341_CASET); // Column addr set
  ILI9341writedata(x0 >> 8);
  ILI9341writedata(x0 & 0xFF);     // XSTART 
  ILI9341writedata(x1 >> 8);
  ILI9341writedata(x1 & 0xFF);     // XEND

  ILI9341writecommand(ILI9341_PASET); // Row addr set
  ILI9341writedata(y0>>8);
  ILI9341writedata(y0);     // YSTART
  ILI9341writedata(y1>>8);
  ILI9341writedata(y1);     // YEND

  ILI9341writecommand(ILI9341_RAMWR); // write to RAM
}

void ILI9341pushColor(uint16 color) 
{
    DC_Write(1u);

    SPIsendNumber(color >> 8);
    SPIsendNumber(color);
}

void ILI9341drawPixel(int16 x, int16 y, uint16 color) 
{
    if((x < 0) ||(x >= _width) || (y < 0) || (y >= _height)) return;

    ILI9341setAddrWindow(x,y,x+1,y+1);

    DC_Write(1u);

    SPIsendNumber(color >> 8);
    SPIsendNumber(color);

}

void ILI9341drawFastVLine(int16 x, int16 y, int16 h, uint16 color) 
{
    // Rudimentary clipping
    if((x >= _width) || (y >= _height)) return;

    if((y+h-1) >= _height) h = _height-y;

    ILI9341setAddrWindow(x, y, x, y+h-1);

    uint8 hi = color >> 8, lo = color;

    DC_Write(1u);

    while (h--) {
        SPIsendNumber(hi);
        SPIsendNumber(lo);
    }
}

void ILI9341drawFastHLine(int16 x, int16 y, int16 w, uint16 color) 
{
    // Rudimentary clipping
    if((x >= _width) || (y >= _height)) return;
    if((x+w-1) >= _width)  w = _width-x;
    ILI9341setAddrWindow(x, y, x+w-1, y);

    uint8 hi = color >> 8, lo = color;
    DC_Write(1u);
  
    while (w--) {
        SPIsendNumber(hi);
        SPIsendNumber(lo);
    }
}

void ILI9341fillScreen(uint16 color) 
{
    ILI9341fillRect(0, 0,  _width, _height, color);
}

void ILI9341fillRect(int16 x, int16 y, int16 w, int16 h, uint16 color) 
{
    // rudimentary clipping (drawChar w/big text requires this)
    if((x >= _width) || (y >= _height)) return;
    if((x + w - 1) >= _width)  w = _width  - x;
    if((y + h - 1) >= _height) h = _height - y;

    ILI9341setAddrWindow(x, y, x+w-1, y+h-1);

    uint8 hi = color >> 8, lo = color;

    DC_Write(1u);

    for(y=h; y>0; y--) {
        for(x=w; x>0; x--) {
            SPIsendNumber(hi);
            SPIsendNumber(lo);
        }
    }
}

// Pass 8-bit (each) R,G,B, get back 16-bit packed color
uint16 ILI9341color565(uint8 r, uint8 g, uint8 b) 
{
    return ((r & 0xF8) << 8) | ((g & 0xFC) << 3) | (b >> 3);
}

void ILI9341setRotation(uint8 m) 
{
    ILI9341writecommand(ILI9341_MADCTL);
    uint8 rotation = m % 4; // can't be higher than 3
    switch (rotation) {
    case 0:
        ILI9341writedata(MADCTL_MX | MADCTL_BGR);
        _width  = ILI9341_TFTWIDTH;
        _height = ILI9341_TFTHEIGHT;
        break;
    case 1:
        ILI9341writedata(MADCTL_MV | MADCTL_BGR);
        _width  = ILI9341_TFTHEIGHT;
        _height = ILI9341_TFTWIDTH;
        break;
    case 2:
        ILI9341writedata(MADCTL_MY | MADCTL_BGR);
        _width  = ILI9341_TFTWIDTH;
        _height = ILI9341_TFTHEIGHT;
        break;
    case 3:
        ILI9341writedata(MADCTL_MX | MADCTL_MY | MADCTL_MV | MADCTL_BGR);
        _width  = ILI9341_TFTHEIGHT;
        _height = ILI9341_TFTWIDTH;
        break;
    }
}

void ILI9341invertDisplay(uint8 i) 
{
    if(i==0) ILI9341writecommand(ILI9341_INVOFF);
    else ILI9341writecommand(ILI9341_INVON);
}

/* [] END OF FILE */
