/***************************************************************************//**
* \file COM_descr.c
* \version 3.0
*
* \brief
*  This file contains the USB descriptors and storage.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_pvt.h"


/*****************************************************************************
*  User supplied descriptors.  If you want to specify your own descriptors,
*  define USER_SUPPLIED_DESCRIPTORS below and add your descriptors.
*****************************************************************************/
/* `#START USER_DESCRIPTORS_DECLARATIONS` Place your declaration here */

/* `#END` */


/***************************************
*  USB Customizer Generated Descriptors
***************************************/

#if !defined(USER_SUPPLIED_DESCRIPTORS)
/*********************************************************************
* Device Descriptors
*********************************************************************/
const uint8 CYCODE COM_DEVICE0_DESCR[18u] = {
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: DEVICE                  */ 0x01u,
/* bcdUSB (ver 2.0)                        */ 0x00u, 0x02u,
/* bDeviceClass                            */ 0xEFu,
/* bDeviceSubClass                         */ 0x02u,
/* bDeviceProtocol                         */ 0x01u,
/* bMaxPacketSize0                         */ 0x08u,
/* idVendor                                */ 0xB4u, 0x04u,
/* idProduct                               */ 0x32u, 0xF2u,
/* bcdDevice                               */ 0x01u, 0x00u,
/* iManufacturer                           */ 0x0Au,
/* iProduct                                */ 0x0Bu,
/* iSerialNumber                           */ 0x80u,
/* bNumConfigurations                      */ 0x01u
};
/*********************************************************************
* Config Descriptor  
*********************************************************************/
const uint8 CYCODE COM_DEVICE0_CONFIGURATION0_DESCR[141u] = {
/*  Config Descriptor Length               */ 0x09u,
/*  DescriptorType: CONFIG                 */ 0x02u,
/*  wTotalLength                           */ 0x8Du, 0x00u,
/*  bNumInterfaces                         */ 0x04u,
/*  bConfigurationValue                    */ 0x01u,
/*  iConfiguration                         */ 0x00u,
/*  bmAttributes                           */ 0x80u,
/*  bMaxPower                              */ 0xC8u,
/*********************************************************************
* Interface Association Descriptor
*********************************************************************/
/*  Interface Association Descriptor Length*/ 0x08u,
/*  DescriptorType: INTERFACE ASSOCIATION  */ 0x0Bu,
/*  bFirstInterface                        */ 0x00u,
/*  bInterfaceCount                        */ 0x02u,
/*  bFunctionClass                         */ 0x02u,
/*  bFunctionSubClass                      */ 0x02u,
/*  bFunctionProtocol                      */ 0x00u,
/*  iFunction                              */ 0x00u,
/*********************************************************************
* CDC Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x00u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x02u,
/*  bInterfaceSubClass                     */ 0x02u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x03u,
/*********************************************************************
* Header Descriptor
*********************************************************************/
/*  Header Descriptor Length               */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x00u,
/*  bcdADC                                 */ 0x10u, 0x01u,
/*********************************************************************
* Abstract Control Management Descriptor
*********************************************************************/
/*  Abstract Control Management Descriptor Length*/ 0x04u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x02u,
/*  bmCapabilities                         */ 0x02u,
/*********************************************************************
* Union Descriptor
*********************************************************************/
/*  Union Descriptor Length                */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x06u,
/*  bControlInterface                      */ 0x00u,
/*  bSubordinateInterface                  */ 0x01u,
/*********************************************************************
* Call Management Descriptor
*********************************************************************/
/*  Call Management Descriptor Length      */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x01u,
/*  bmCapabilities                         */ 0x00u,
/*  bDataInterface                         */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x81u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x0Cu, 0x00u,
/*  bInterval                              */ 0x0Au,
/*********************************************************************
* Data Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x01u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0x0Au,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x04u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x82u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x03u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* Interface Association Descriptor
*********************************************************************/
/*  Interface Association Descriptor Length*/ 0x08u,
/*  DescriptorType: INTERFACE ASSOCIATION  */ 0x0Bu,
/*  bFirstInterface                        */ 0x02u,
/*  bInterfaceCount                        */ 0x02u,
/*  bFunctionClass                         */ 0x02u,
/*  bFunctionSubClass                      */ 0x02u,
/*  bFunctionProtocol                      */ 0x00u,
/*  iFunction                              */ 0x00u,
/*********************************************************************
* CDC Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x02u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x01u,
/*  bInterfaceClass                        */ 0x02u,
/*  bInterfaceSubClass                     */ 0x02u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x06u,
/*********************************************************************
* Header Descriptor
*********************************************************************/
/*  Header Descriptor Length               */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x00u,
/*  bcdADC                                 */ 0x10u, 0x01u,
/*********************************************************************
* Abstract Control Management Descriptor
*********************************************************************/
/*  Abstract Control Management Descriptor Length*/ 0x04u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x02u,
/*  bmCapabilities                         */ 0x02u,
/*********************************************************************
* Union Descriptor
*********************************************************************/
/*  Union Descriptor Length                */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x06u,
/*  bControlInterface                      */ 0x00u,
/*  bSubordinateInterface                  */ 0x01u,
/*********************************************************************
* Call Management Descriptor
*********************************************************************/
/*  Call Management Descriptor Length      */ 0x05u,
/*  DescriptorType: CS_INTERFACE           */ 0x24u,
/*  bDescriptorSubtype                     */ 0x01u,
/*  bmCapabilities                         */ 0x00u,
/*  bDataInterface                         */ 0x01u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x84u,
/*  bmAttributes                           */ 0x03u,
/*  wMaxPacketSize                         */ 0x0Cu, 0x00u,
/*  bInterval                              */ 0x0Au,
/*********************************************************************
* Data Interface Descriptor
*********************************************************************/
/*  Interface Descriptor Length            */ 0x09u,
/*  DescriptorType: INTERFACE              */ 0x04u,
/*  bInterfaceNumber                       */ 0x03u,
/*  bAlternateSetting                      */ 0x00u,
/*  bNumEndpoints                          */ 0x02u,
/*  bInterfaceClass                        */ 0x0Au,
/*  bInterfaceSubClass                     */ 0x00u,
/*  bInterfaceProtocol                     */ 0x00u,
/*  iInterface                             */ 0x07u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x85u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u,
/*********************************************************************
* Endpoint Descriptor
*********************************************************************/
/*  Endpoint Descriptor Length             */ 0x07u,
/*  DescriptorType: ENDPOINT               */ 0x05u,
/*  bEndpointAddress                       */ 0x06u,
/*  bmAttributes                           */ 0x02u,
/*  wMaxPacketSize                         */ 0x40u, 0x00u,
/*  bInterval                              */ 0x00u
};

/*********************************************************************
* String Descriptor Table
*********************************************************************/
const uint8 CYCODE COM_STRING_DESCRIPTORS[349u] = {
/*********************************************************************
* Language ID Descriptor
*********************************************************************/
/* Descriptor Length                       */ 0x04u,
/* DescriptorType: STRING                  */ 0x03u,
/* Language Id                             */ 0x09u, 0x04u,
/*********************************************************************
* String Descriptor: "USBUART"
*********************************************************************/
/* Descriptor Length                       */ 0x10u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'U', 0u,(uint8)'S', 0u,(uint8)'B', 0u,(uint8)'U', 0u,(uint8)'A', 0u,
 (uint8)'R', 0u,(uint8)'T', 0u,
/*********************************************************************
* String Descriptor: "USBUART 1"
*********************************************************************/
/* Descriptor Length                       */ 0x14u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'U', 0u,(uint8)'S', 0u,(uint8)'B', 0u,(uint8)'U', 0u,(uint8)'A', 0u,
 (uint8)'R', 0u,(uint8)'T', 0u,(uint8)' ', 0u,(uint8)'1', 0u,
/*********************************************************************
* String Descriptor: "CDC Communication Interface 0"
*********************************************************************/
/* Descriptor Length                       */ 0x3Cu,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'C', 0u,(uint8)'D', 0u,(uint8)'C', 0u,(uint8)' ', 0u,(uint8)'C', 0u,
 (uint8)'o', 0u,(uint8)'m', 0u,(uint8)'m', 0u,(uint8)'u', 0u,(uint8)'n', 0u,
 (uint8)'i', 0u,(uint8)'c', 0u,(uint8)'a', 0u,(uint8)'t', 0u,(uint8)'i', 0u,
 (uint8)'o', 0u,(uint8)'n', 0u,(uint8)' ', 0u,(uint8)'I', 0u,(uint8)'n', 0u,
 (uint8)'t', 0u,(uint8)'e', 0u,(uint8)'r', 0u,(uint8)'f', 0u,(uint8)'a', 0u,
 (uint8)'c', 0u,(uint8)'e', 0u,(uint8)' ', 0u,(uint8)'0', 0u,
/*********************************************************************
* String Descriptor: "CDC Data Interface 0"
*********************************************************************/
/* Descriptor Length                       */ 0x2Au,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'C', 0u,(uint8)'D', 0u,(uint8)'C', 0u,(uint8)' ', 0u,(uint8)'D', 0u,
 (uint8)'a', 0u,(uint8)'t', 0u,(uint8)'a', 0u,(uint8)' ', 0u,(uint8)'I', 0u,
 (uint8)'n', 0u,(uint8)'t', 0u,(uint8)'e', 0u,(uint8)'r', 0u,(uint8)'f', 0u,
 (uint8)'a', 0u,(uint8)'c', 0u,(uint8)'e', 0u,(uint8)' ', 0u,(uint8)'0', 0u,
/*********************************************************************
* String Descriptor: "USBUART 2"
*********************************************************************/
/* Descriptor Length                       */ 0x14u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'U', 0u,(uint8)'S', 0u,(uint8)'B', 0u,(uint8)'U', 0u,(uint8)'A', 0u,
 (uint8)'R', 0u,(uint8)'T', 0u,(uint8)' ', 0u,(uint8)'2', 0u,
/*********************************************************************
* String Descriptor: "CDC Communication Interface 1"
*********************************************************************/
/* Descriptor Length                       */ 0x3Cu,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'C', 0u,(uint8)'D', 0u,(uint8)'C', 0u,(uint8)' ', 0u,(uint8)'C', 0u,
 (uint8)'o', 0u,(uint8)'m', 0u,(uint8)'m', 0u,(uint8)'u', 0u,(uint8)'n', 0u,
 (uint8)'i', 0u,(uint8)'c', 0u,(uint8)'a', 0u,(uint8)'t', 0u,(uint8)'i', 0u,
 (uint8)'o', 0u,(uint8)'n', 0u,(uint8)' ', 0u,(uint8)'I', 0u,(uint8)'n', 0u,
 (uint8)'t', 0u,(uint8)'e', 0u,(uint8)'r', 0u,(uint8)'f', 0u,(uint8)'a', 0u,
 (uint8)'c', 0u,(uint8)'e', 0u,(uint8)' ', 0u,(uint8)'1', 0u,
/*********************************************************************
* String Descriptor: "CDC Data Interface 1"
*********************************************************************/
/* Descriptor Length                       */ 0x2Au,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'C', 0u,(uint8)'D', 0u,(uint8)'C', 0u,(uint8)' ', 0u,(uint8)'D', 0u,
 (uint8)'a', 0u,(uint8)'t', 0u,(uint8)'a', 0u,(uint8)' ', 0u,(uint8)'I', 0u,
 (uint8)'n', 0u,(uint8)'t', 0u,(uint8)'e', 0u,(uint8)'r', 0u,(uint8)'f', 0u,
 (uint8)'a', 0u,(uint8)'c', 0u,(uint8)'e', 0u,(uint8)' ', 0u,(uint8)'1', 0u,
/*********************************************************************
* String Descriptor: "USBcom1"
*********************************************************************/
/* Descriptor Length                       */ 0x10u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'U', 0u,(uint8)'S', 0u,(uint8)'B', 0u,(uint8)'c', 0u,(uint8)'o', 0u,
 (uint8)'m', 0u,(uint8)'1', 0u,
/*********************************************************************
* String Descriptor: "USBcom2"
*********************************************************************/
/* Descriptor Length                       */ 0x10u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'U', 0u,(uint8)'S', 0u,(uint8)'B', 0u,(uint8)'c', 0u,(uint8)'o', 0u,
 (uint8)'m', 0u,(uint8)'2', 0u,
/*********************************************************************
* String Descriptor: "Lukas Creutzburg"
*********************************************************************/
/* Descriptor Length                       */ 0x22u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'L', 0u,(uint8)'u', 0u,(uint8)'k', 0u,(uint8)'a', 0u,(uint8)'s', 0u,
 (uint8)' ', 0u,(uint8)'C', 0u,(uint8)'r', 0u,(uint8)'e', 0u,(uint8)'u', 0u,
 (uint8)'t', 0u,(uint8)'z', 0u,(uint8)'b', 0u,(uint8)'u', 0u,(uint8)'r', 0u,
 (uint8)'g', 0u,
/*********************************************************************
* String Descriptor: "AMP_Psoc"
*********************************************************************/
/* Descriptor Length                       */ 0x12u,
/* DescriptorType: STRING                  */ 0x03u,
 (uint8)'A', 0u,(uint8)'M', 0u,(uint8)'P', 0u,(uint8)'_', 0u,(uint8)'P', 0u,
 (uint8)'s', 0u,(uint8)'o', 0u,(uint8)'c', 0u,
/*********************************************************************/
/* Marks the end of the list.              */ 0x00u};
/*********************************************************************/

/*********************************************************************
* Serial Number String Descriptor
*********************************************************************/
const uint8 CYCODE COM_SN_STRING_DESCRIPTOR[2] = {
/* Descriptor Length                       */ 0x02u,
/* DescriptorType: STRING                  */ 0x03u,

};



/*********************************************************************
* Endpoint Setting Table -- This table contain the endpoint setting
*                           for each endpoint in the configuration. It
*                           contains the necessary information to
*                           configure the endpoint hardware for each
*                           interface and alternate setting.
*********************************************************************/
const T_COM_EP_SETTINGS_BLOCK CYCODE COM_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE[6u] = {
/* IFC  ALT    EPAddr bmAttr MaxPktSize Class ********************/
{0x00u, 0x00u, 0x81u, 0x03u, 0x000Cu,   0x02u},
{0x01u, 0x00u, 0x82u, 0x02u, 0x0040u,   0x0Au},
{0x01u, 0x00u, 0x03u, 0x02u, 0x0040u,   0x0Au},
{0x02u, 0x00u, 0x84u, 0x03u, 0x000Cu,   0x02u},
{0x03u, 0x00u, 0x85u, 0x02u, 0x0040u,   0x0Au},
{0x03u, 0x00u, 0x06u, 0x02u, 0x0040u,   0x0Au}
};
const uint8 CYCODE COM_DEVICE0_CONFIGURATION0_INTERFACE_CLASS[4u] = {
0x02u, 0x0Au, 0x02u, 0x0Au
};
/*********************************************************************
* Config Dispatch Table -- Points to the Config Descriptor and each of
*                          and endpoint setup table and to each
*                          interface table if it specifies a USB Class
*********************************************************************/
const T_COM_LUT CYCODE COM_DEVICE0_CONFIGURATION0_TABLE[7u] = {
    {0x01u,     &COM_DEVICE0_CONFIGURATION0_DESCR},
    {0x06u,     &COM_DEVICE0_CONFIGURATION0_EP_SETTINGS_TABLE},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,    NULL},
    {0x00u,     &COM_DEVICE0_CONFIGURATION0_INTERFACE_CLASS}
};
/*********************************************************************
* Device Dispatch Table -- Points to the Device Descriptor and each of
*                          and Configuration Tables for this Device 
*********************************************************************/
const T_COM_LUT CYCODE COM_DEVICE0_TABLE[3u] = {
    {0x01u,     &COM_DEVICE0_DESCR},
    {0x00u,    NULL},
    {0x01u,     &COM_DEVICE0_CONFIGURATION0_TABLE}
};
/*********************************************************************
* Device Table -- Indexed by the device number.
*********************************************************************/
const T_COM_LUT CYCODE COM_TABLE[1u] = {
    {0x01u,     &COM_DEVICE0_TABLE}
};

#endif /* USER_SUPPLIED_DESCRIPTORS */

#if defined(COM_ENABLE_MSOS_STRING)

    /******************************************************************************
    *  USB Microsoft OS String Descriptor
    *  "MSFT" identifies a Microsoft host
    *  "100" specifies version 1.00
    *  COM_GET_EXTENDED_CONFIG_DESCRIPTOR becomes the bRequest value
    *  in a host vendor device/class request
    ******************************************************************************/

    const uint8 CYCODE COM_MSOS_DESCRIPTOR[COM_MSOS_DESCRIPTOR_LENGTH] = {
    /* Descriptor Length                       */   0x12u,
    /* DescriptorType: STRING                  */   0x03u,
    /* qwSignature - "MSFT100"                 */   (uint8)'M', 0u, (uint8)'S', 0u, (uint8)'F', 0u, (uint8)'T', 0u,
                                                    (uint8)'1', 0u, (uint8)'0', 0u, (uint8)'0', 0u,
    /* bMS_VendorCode:                         */   COM_GET_EXTENDED_CONFIG_DESCRIPTOR,
    /* bPad                                    */   0x00u
    };

    /* Extended Configuration Descriptor */

    const uint8 CYCODE COM_MSOS_CONFIGURATION_DESCR[COM_MSOS_CONF_DESCR_LENGTH] = {
    /*  Length of the descriptor 4 bytes       */   0x28u, 0x00u, 0x00u, 0x00u,
    /*  Version of the descriptor 2 bytes      */   0x00u, 0x01u,
    /*  wIndex - Fixed:INDEX_CONFIG_DESCRIPTOR */   0x04u, 0x00u,
    /*  bCount - Count of device functions.    */   0x01u,
    /*  Reserved : 7 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u,
    /*  bFirstInterfaceNumber                  */   0x00u,
    /*  Reserved                               */   0x01u,
    /*  compatibleID    - "CYUSB\0\0"          */   (uint8)'C', (uint8)'Y', (uint8)'U', (uint8)'S', (uint8)'B',
                                                    0x00u, 0x00u, 0x00u,
    /*  subcompatibleID - "00001\0\0"          */   (uint8)'0', (uint8)'0', (uint8)'0', (uint8)'0', (uint8)'1',
                                                    0x00u, 0x00u, 0x00u,
    /*  Reserved : 6 bytes                     */   0x00u, 0x00u, 0x00u, 0x00u, 0x00u, 0x00u
    };

#endif /* COM_ENABLE_MSOS_STRING */

/* DIE ID string descriptor for 8 bytes ID */
#if defined(COM_ENABLE_IDSN_STRING)
    uint8 COM_idSerialNumberStringDescriptor[COM_IDSN_DESCR_LENGTH];
#endif /* COM_ENABLE_IDSN_STRING */


/* [] END OF FILE */
