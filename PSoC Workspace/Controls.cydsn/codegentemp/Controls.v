// ======================================================================
// Controls.v generated from TopDesign.cysch
// 11/26/2016 at 14:31
// This file is auto generated. ANY EDITS YOU MAKE MAY BE LOST WHEN THIS FILE IS REGENERATED!!!
// ======================================================================

/* -- WARNING: The following section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_DIE_LEOPARD 1
`define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3
`define CYDEV_CHIP_REV_LEOPARD_ES3 3
`define CYDEV_CHIP_REV_LEOPARD_ES2 1
`define CYDEV_CHIP_REV_LEOPARD_ES1 0
`define CYDEV_CHIP_DIE_TMA4 2
`define CYDEV_CHIP_REV_TMA4_PRODUCTION 17
`define CYDEV_CHIP_REV_TMA4_ES 17
`define CYDEV_CHIP_REV_TMA4_ES2 33
`define CYDEV_CHIP_DIE_PSOC4A 3
`define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17
`define CYDEV_CHIP_REV_PSOC4A_ES0 17
`define CYDEV_CHIP_DIE_PSOC5LP 4
`define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0
`define CYDEV_CHIP_REV_PSOC5LP_ES0 0
`define CYDEV_CHIP_DIE_PSOC5TM 5
`define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1
`define CYDEV_CHIP_REV_PSOC5TM_ES1 1
`define CYDEV_CHIP_REV_PSOC5TM_ES0 0
`define CYDEV_CHIP_DIE_VOLANS 6
`define CYDEV_CHIP_REV_VOLANS_PRODUCTION 0
`define CYDEV_CHIP_DIE_BERRYPECKER 7
`define CYDEV_CHIP_REV_BERRYPECKER_PRODUCTION 0
`define CYDEV_CHIP_DIE_CRANE 8
`define CYDEV_CHIP_REV_CRANE_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM3 9
`define CYDEV_CHIP_REV_FM3_PRODUCTION 0
`define CYDEV_CHIP_DIE_FM4 10
`define CYDEV_CHIP_REV_FM4_PRODUCTION 0
`define CYDEV_CHIP_DIE_EXPECT 4
`define CYDEV_CHIP_REV_EXPECT 0
`define CYDEV_CHIP_DIE_ACTUAL 4
/* -- WARNING: The previous section of defines are deprecated and will be removed in a future release -- */
`define CYDEV_CHIP_FAMILY_PSOC3 1
`define CYDEV_CHIP_FAMILY_PSOC4 2
`define CYDEV_CHIP_FAMILY_PSOC5 3
`define CYDEV_CHIP_FAMILY_FM0P 4
`define CYDEV_CHIP_FAMILY_FM3 5
`define CYDEV_CHIP_FAMILY_FM4 6
`define CYDEV_CHIP_FAMILY_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_UNKNOWN 0
`define CYDEV_CHIP_MEMBER_3A 1
`define CYDEV_CHIP_REVISION_3A_PRODUCTION 3
`define CYDEV_CHIP_REVISION_3A_ES3 3
`define CYDEV_CHIP_REVISION_3A_ES2 1
`define CYDEV_CHIP_REVISION_3A_ES1 0
`define CYDEV_CHIP_MEMBER_4G 2
`define CYDEV_CHIP_REVISION_4G_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4G_ES 17
`define CYDEV_CHIP_REVISION_4G_ES2 33
`define CYDEV_CHIP_MEMBER_4U 3
`define CYDEV_CHIP_REVISION_4U_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4E 4
`define CYDEV_CHIP_REVISION_4E_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4O 5
`define CYDEV_CHIP_REVISION_4O_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4N 6
`define CYDEV_CHIP_REVISION_4N_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4Q 7
`define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4D 8
`define CYDEV_CHIP_REVISION_4D_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4J 9
`define CYDEV_CHIP_REVISION_4J_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4K 10
`define CYDEV_CHIP_REVISION_4K_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4H 11
`define CYDEV_CHIP_REVISION_4H_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4A 12
`define CYDEV_CHIP_REVISION_4A_PRODUCTION 17
`define CYDEV_CHIP_REVISION_4A_ES0 17
`define CYDEV_CHIP_MEMBER_4F 13
`define CYDEV_CHIP_REVISION_4F_PRODUCTION 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0
`define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0
`define CYDEV_CHIP_MEMBER_4P 14
`define CYDEV_CHIP_REVISION_4P_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4M 15
`define CYDEV_CHIP_REVISION_4M_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4L 16
`define CYDEV_CHIP_REVISION_4L_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4I 17
`define CYDEV_CHIP_REVISION_4I_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_4C 18
`define CYDEV_CHIP_REVISION_4C_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_5B 19
`define CYDEV_CHIP_REVISION_5B_PRODUCTION 0
`define CYDEV_CHIP_REVISION_5B_ES0 0
`define CYDEV_CHIP_MEMBER_5A 20
`define CYDEV_CHIP_REVISION_5A_PRODUCTION 1
`define CYDEV_CHIP_REVISION_5A_ES1 1
`define CYDEV_CHIP_REVISION_5A_ES0 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 21
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 22
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 23
`define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM3 24
`define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0
`define CYDEV_CHIP_MEMBER_FM4 25
`define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0
`define CYDEV_CHIP_FAMILY_USED 3
`define CYDEV_CHIP_MEMBER_USED 19
`define CYDEV_CHIP_REVISION_USED 0
// Component: cy_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_virtualmux_v1_0\cy_virtualmux_v1_0.v"
`endif

// Component: ZeroTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\ZeroTerminal\ZeroTerminal.v"
`endif

// USBFS_v3_10(AudioDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_10">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Audio">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, CDCDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_10">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="CDC">\r\n      <Nodes>\r\n        <DescriptorNode Key="Interface847">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 1</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 1</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor848">\r\n              <m_value d8p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>9</iwInterface>\r\n                <bInterfaceClass>2</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>2</iInterface>\r\n                <sInterface>CDC Communication Interface</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>9</iwInterface>\r\n                <bInterfaceClass>2</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>0</bInterfaceNumber>\r\n                <bNumEndpoints>1</bNumEndpoints>\r\n                <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>2</iInterface>\r\n                <sInterface>CDC Communication Interface</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor850">\r\n                  <m_value d10p1:type="CyCDCHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>272</bcdADC>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCHeaderDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                    <bcdADC>272</bcdADC>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor851">\r\n                  <m_value d10p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>4</bLength>\r\n                    <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bmCapabilities>2</bmCapabilities>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>4</bLength>\r\n                    <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bmCapabilities>2</bmCapabilities>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor852">\r\n                  <m_value d10p1:type="CyCDCUnionDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                    <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCUnionDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                    <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor853">\r\n                  <m_value d10p1:type="CyCDCCallManagementDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bDataInterface>1</bDataInterface>\r\n                  </m_value>\r\n                  <Value d10p1:type="CyCDCCallManagementDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>CDC</bDescriptorType>\r\n                    <bLength>5</bLength>\r\n                    <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                    <bDataInterface>1</bDataInterface>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor854">\r\n                  <m_value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>129</bEndpointAddress>\r\n                    <bmAttributes>3</bmAttributes>\r\n                  </m_value>\r\n                  <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>129</bEndpointAddress>\r\n                    <bmAttributes>3</bmAttributes>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="Interface855">\r\n          <m_value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 2</DisplayName>\r\n          </m_value>\r\n          <Value d6p1:type="InterfaceGeneralDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>ALTERNATE</bDescriptorType>\r\n            <bLength>0</bLength>\r\n            <DisplayName>CDC Interface 2</DisplayName>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor856">\r\n              <m_value d8p1:type="CyDataInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>612</iwInterface>\r\n                <bInterfaceClass>10</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>2</bNumEndpoints>\r\n                <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>3</iInterface>\r\n                <sInterface>CDC Data Interface</sInterface>\r\n              </m_value>\r\n              <Value d8p1:type="CyDataInterfaceDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>INTERFACE</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwInterface>612</iwInterface>\r\n                <bInterfaceClass>10</bInterfaceClass>\r\n                <bAlternateSetting>0</bAlternateSetting>\r\n                <bInterfaceNumber>1</bInterfaceNumber>\r\n                <bNumEndpoints>2</bNumEndpoints>\r\n                <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                <iInterface>3</iInterface>\r\n                <sInterface>CDC Data Interface</sInterface>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="USBDescriptor858">\r\n                  <m_value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>130</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>130</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="USBDescriptor859">\r\n                  <m_value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>3</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </m_value>\r\n                  <Value d10p1:type="EndpointDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                    <bLength>7</bLength>\r\n                    <DoubleBuffer>false</DoubleBuffer>\r\n                    <bEndpointAddress>3</bEndpointAddress>\r\n                    <bmAttributes>2</bmAttributes>\r\n                    <wMaxPacketSize>64</wMaxPacketSize>\r\n                  </Value>\r\n                  <Nodes />\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DeviceDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_10">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Device">\r\n      <Nodes>\r\n        <DescriptorNode Key="USBDescriptor838">\r\n          <m_value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>860</iwManufacturer>\r\n            <iwProduct>861</iwProduct>\r\n            <sManufacturer>Lukas Creutzburg</sManufacturer>\r\n            <sProduct>DSP_Amp</sProduct>\r\n            <sSerialNumber />\r\n            <bDeviceClass>2</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>62002</idProduct>\r\n            <bcdDevice>1</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>5</iManufacturer>\r\n            <iProduct>6</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </m_value>\r\n          <Value d6p1:type="DeviceDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>DEVICE</bDescriptorType>\r\n            <bLength>18</bLength>\r\n            <iwManufacturer>860</iwManufacturer>\r\n            <iwProduct>861</iwProduct>\r\n            <sManufacturer>Lukas Creutzburg</sManufacturer>\r\n            <sProduct>DSP_Amp</sProduct>\r\n            <sSerialNumber />\r\n            <bDeviceClass>2</bDeviceClass>\r\n            <bDeviceSubClass>0</bDeviceSubClass>\r\n            <bDeviceProtocol>0</bDeviceProtocol>\r\n            <bMaxPacketSize0>0</bMaxPacketSize0>\r\n            <idVendor>1204</idVendor>\r\n            <idProduct>62002</idProduct>\r\n            <bcdDevice>1</bcdDevice>\r\n            <bcdUSB>512</bcdUSB>\r\n            <iManufacturer>5</iManufacturer>\r\n            <iProduct>6</iProduct>\r\n            <iSerialNumber>0</iSerialNumber>\r\n            <bNumConfigurations>1</bNumConfigurations>\r\n            <bMemoryMgmt>0</bMemoryMgmt>\r\n            <bMemoryAlloc>0</bMemoryAlloc>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor843">\r\n              <m_value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>861</iwConfiguration>\r\n                <sConfiguration>DSP_Amp</sConfiguration>\r\n                <wTotalLength>67</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>6</iConfiguration>\r\n                <bmAttributes>128</bmAttributes>\r\n                <bMaxPower>250</bMaxPower>\r\n              </m_value>\r\n              <Value d8p1:type="ConfigDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>CONFIGURATION</bDescriptorType>\r\n                <bLength>9</bLength>\r\n                <iwConfiguration>861</iwConfiguration>\r\n                <sConfiguration>DSP_Amp</sConfiguration>\r\n                <wTotalLength>67</wTotalLength>\r\n                <bNumInterfaces>2</bNumInterfaces>\r\n                <bConfigurationValue>0</bConfigurationValue>\r\n                <iConfiguration>6</iConfiguration>\r\n                <bmAttributes>128</bmAttributes>\r\n                <bMaxPower>250</bMaxPower>\r\n              </Value>\r\n              <Nodes>\r\n                <DescriptorNode Key="Interface847">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 1</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 1</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor848">\r\n                      <m_value d12p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>9</iwInterface>\r\n                        <bInterfaceClass>2</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>2</iInterface>\r\n                        <sInterface>CDC Communication Interface</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyCommunicationsInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>9</iwInterface>\r\n                        <bInterfaceClass>2</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>0</bInterfaceNumber>\r\n                        <bNumEndpoints>1</bNumEndpoints>\r\n                        <bInterfaceSubClass>2</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>2</iInterface>\r\n                        <sInterface>CDC Communication Interface</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor850">\r\n                          <m_value d14p1:type="CyCDCHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>272</bcdADC>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCHeaderDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>HEADER</bDescriptorSubtype>\r\n                            <bcdADC>272</bcdADC>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor851">\r\n                          <m_value d14p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>4</bLength>\r\n                            <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bmCapabilities>2</bmCapabilities>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCAbstractControlMgmtDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>4</bLength>\r\n                            <bDescriptorSubtype>ABSTRACT_CONTROL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bmCapabilities>2</bmCapabilities>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor852">\r\n                          <m_value d14p1:type="CyCDCUnionDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                            <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCUnionDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>UNION</bDescriptorSubtype>\r\n                            <bSubordinateInterface>AQ==</bSubordinateInterface>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor853">\r\n                          <m_value d14p1:type="CyCDCCallManagementDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bDataInterface>1</bDataInterface>\r\n                          </m_value>\r\n                          <Value d14p1:type="CyCDCCallManagementDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>CDC</bDescriptorType>\r\n                            <bLength>5</bLength>\r\n                            <bDescriptorSubtype>CALL_MANAGEMENT</bDescriptorSubtype>\r\n                            <bDataInterface>1</bDataInterface>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor854">\r\n                          <m_value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>129</bEndpointAddress>\r\n                            <bmAttributes>3</bmAttributes>\r\n                          </m_value>\r\n                          <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>129</bEndpointAddress>\r\n                            <bmAttributes>3</bmAttributes>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n                <DescriptorNode Key="Interface855">\r\n                  <m_value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 2</DisplayName>\r\n                  </m_value>\r\n                  <Value d10p1:type="InterfaceGeneralDescriptor" xmlns:d10p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                    <bDescriptorType>ALTERNATE</bDescriptorType>\r\n                    <bLength>0</bLength>\r\n                    <DisplayName>CDC Interface 2</DisplayName>\r\n                  </Value>\r\n                  <Nodes>\r\n                    <DescriptorNode Key="USBDescriptor856">\r\n                      <m_value d12p1:type="CyDataInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>612</iwInterface>\r\n                        <bInterfaceClass>10</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>2</bNumEndpoints>\r\n                        <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>3</iInterface>\r\n                        <sInterface>CDC Data Interface</sInterface>\r\n                      </m_value>\r\n                      <Value d12p1:type="CyDataInterfaceDescriptor" xmlns:d12p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                        <bDescriptorType>INTERFACE</bDescriptorType>\r\n                        <bLength>9</bLength>\r\n                        <iwInterface>612</iwInterface>\r\n                        <bInterfaceClass>10</bInterfaceClass>\r\n                        <bAlternateSetting>0</bAlternateSetting>\r\n                        <bInterfaceNumber>1</bInterfaceNumber>\r\n                        <bNumEndpoints>2</bNumEndpoints>\r\n                        <bInterfaceSubClass>0</bInterfaceSubClass>\r\n                        <bInterfaceProtocol>0</bInterfaceProtocol>\r\n                        <iInterface>3</iInterface>\r\n                        <sInterface>CDC Data Interface</sInterface>\r\n                      </Value>\r\n                      <Nodes>\r\n                        <DescriptorNode Key="USBDescriptor858">\r\n                          <m_value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>130</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>130</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                        <DescriptorNode Key="USBDescriptor859">\r\n                          <m_value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>3</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </m_value>\r\n                          <Value d14p1:type="EndpointDescriptor" xmlns:d14p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                            <bDescriptorType>ENDPOINT</bDescriptorType>\r\n                            <bLength>7</bLength>\r\n                            <DoubleBuffer>false</DoubleBuffer>\r\n                            <bEndpointAddress>3</bEndpointAddress>\r\n                            <bmAttributes>2</bmAttributes>\r\n                            <wMaxPacketSize>64</wMaxPacketSize>\r\n                          </Value>\r\n                          <Nodes />\r\n                        </DescriptorNode>\r\n                      </Nodes>\r\n                    </DescriptorNode>\r\n                  </Nodes>\r\n                </DescriptorNode>\r\n              </Nodes>\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, DmaChannelPriority=3, DW_Hide_DmaAuto=true, DW_Hide_Usbv2Regs=true, DW_RegSize=8, DW_USB_CHGDET_CTRL=CR0, DW_USB_INTR_CAUSE_HI=CR0, DW_USB_INTR_CAUSE_LO=CR0, DW_USB_INTR_CAUSE_MED=CR0, DW_USB_INTR_LVL_SEL=CR0, DW_USB_INTR_SIE=CR0, DW_USB_INTR_SIE_MASK=CR0, DW_USB_LPM_CTRL=CR0, DW_USB_LPM_STAT=CR0, DW_USB_POWER_CTRL=CR0, EnableBatteryChargDetect=false, EnableCDCApi=true, EnableMidiApi=true, endpointMA=0, endpointMM=0, epDMAautoOptimization=false, extern_cls=false, extern_vbus=false, extern_vnd=false, extJackCount=0, Gen16bitEpAccessApi=false, HandleMscRequests=true, HIDReportDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_10">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="HIDReport">\r\n      <Nodes>\r\n        <DescriptorNode Key="USBDescriptor761">\r\n          <m_value d6p1:type="HIDReportDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>HID_REPORT</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <Name>3-Button Mouse</Name>\r\n            <wLength>50</wLength>\r\n          </m_value>\r\n          <Value d6p1:type="HIDReportDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>HID_REPORT</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <Name>3-Button Mouse</Name>\r\n            <wLength>50</wLength>\r\n          </Value>\r\n          <Nodes>\r\n            <DescriptorNode Key="USBDescriptor762">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor763">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor764">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor765">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor766">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="160" Type="COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>161</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor767">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>9</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>9</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor768">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="24" Type="USAGE_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>25</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="24" Type="USAGE_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>25</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor769">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="40" Type="USAGE_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>41</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="40" Type="USAGE_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>41</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor770">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor771">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor772">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>3</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor773">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor774">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor775">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor776">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>5</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>5</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor777">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor778">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="4" Type="USAGE_PAGE">\r\n                  <Value>\r\n                    <unsignedByte>5</unsignedByte>\r\n                    <unsignedByte>1</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor779">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>48</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>48</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor780">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>49</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="8" Type="USAGE">\r\n                  <Value>\r\n                    <unsignedByte>9</unsignedByte>\r\n                    <unsignedByte>49</unsignedByte>\r\n                  </Value>\r\n                  <Kind>List</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor781">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="20" Type="LOGICAL_MINIMUM">\r\n                  <Value>\r\n                    <unsignedByte>21</unsignedByte>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor782">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>127</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="36" Type="LOGICAL_MAXIMUM">\r\n                  <Value>\r\n                    <unsignedByte>37</unsignedByte>\r\n                    <unsignedByte>127</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor783">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>8</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="116" Type="REPORT_SIZE">\r\n                  <Value>\r\n                    <unsignedByte>117</unsignedByte>\r\n                    <unsignedByte>8</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor784">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="148" Type="REPORT_COUNT">\r\n                  <Value>\r\n                    <unsignedByte>149</unsignedByte>\r\n                    <unsignedByte>2</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Int</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor785">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>6</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="128" Type="INPUT">\r\n                  <Value>\r\n                    <unsignedByte>129</unsignedByte>\r\n                    <unsignedByte>6</unsignedByte>\r\n                  </Value>\r\n                  <Kind>Bits</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor786">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n            <DescriptorNode Key="USBDescriptor787">\r\n              <m_value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </m_value>\r\n              <Value d8p1:type="HIDReportItemDescriptor" xmlns:d8p1="http://www.w3.org/2001/XMLSchema-instance">\r\n                <bDescriptorType>HID_REPORT_ITEM</bDescriptorType>\r\n                <bLength>1</bLength>\r\n                <Item Code="192" Type="END_COLLECTION">\r\n                  <Value>\r\n                    <unsignedByte>192</unsignedByte>\r\n                    <unsignedByte>0</unsignedByte>\r\n                  </Value>\r\n                  <Kind>None</Kind>\r\n                </Item>\r\n              </Value>\r\n              <Nodes />\r\n            </DescriptorNode>\r\n          </Nodes>\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, isrGroupArbiter=0, isrGroupBusReset=2, isrGroupEp0=1, isrGroupEp1=1, isrGroupEp2=1, isrGroupEp3=1, isrGroupEp4=1, isrGroupEp5=1, isrGroupEp6=1, isrGroupEp7=1, isrGroupEp8=1, isrGroupLpm=0, isrGroupSof=2, M0S8USBDSS_BLOCK_COUNT_1=0, max_interfaces_num=2, MidiDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_10">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="Midi">\r\n      <Nodes />\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, Mode=false, mon_vbus=false, MscDescriptors=, MscLogicalUnitsNum=1, out_sof=false, Pid=F232, powerpad_vbus=true, PRIMITIVE_INSTANCE=USB, ProdactName=, ProdactRevision=, REG_SIZE=reg8, RemoveDmaAutoOpt=true, RemoveVbusPin=true, rm_arb_int=false, rm_dma_1=true, rm_dma_2=true, rm_dma_3=true, rm_dma_4=true, rm_dma_5=true, rm_dma_6=true, rm_dma_7=true, rm_dma_8=true, rm_dp_int=false, rm_ep_isr_0=false, rm_ep_isr_1=false, rm_ep_isr_2=false, rm_ep_isr_3=false, rm_ep_isr_4=true, rm_ep_isr_5=true, rm_ep_isr_6=true, rm_ep_isr_7=true, rm_ep_isr_8=true, rm_lpm_int=true, rm_ord_int=false, rm_sof_int=false, rm_usb_int=false, SofTermEnable=false, StringDescriptors=<?xml version="1.0" encoding="utf-16"?>\r\n<Tree xmlns:CustomizerVersion="3_10">\r\n  <Tree_x0020_Descriptors>\r\n    <DescriptorNode Key="String">\r\n      <Nodes>\r\n        <DescriptorNode Key="LANGID">\r\n          <m_value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </m_value>\r\n          <Value d6p1:type="StringZeroDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>4</bLength>\r\n            <wLANGID>1033</wLANGID>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor7">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Semiconductor</bString>\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>44</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Cypress Semiconductor</bString>\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor9">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>56</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Communication Interface</bString>\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>56</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Communication Interface</bString>\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor612">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>38</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Data Interface</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>38</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>CDC Data Interface</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor613">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>USBUART</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>USBUART</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor860">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>34</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Lukas Creutzburg</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>34</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>Lukas Creutzburg</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="USBDescriptor861">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>DSP_Amp</bString>\r\n            <bUsed>false</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>DSP_Amp</bString>\r\n            <bUsed>false</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n    <DescriptorNode Key="SpecialString">\r\n      <Nodes>\r\n        <DescriptorNode Key="Serial">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>SILICON_NUMBER</snType>\r\n            <bString />\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>2</bLength>\r\n            <snType>SILICON_NUMBER</snType>\r\n            <bString />\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n        <DescriptorNode Key="EE">\r\n          <m_value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>true</bUsed>\r\n          </m_value>\r\n          <Value d6p1:type="StringDescriptor" xmlns:d6p1="http://www.w3.org/2001/XMLSchema-instance">\r\n            <bDescriptorType>STRING</bDescriptorType>\r\n            <bLength>16</bLength>\r\n            <snType>USER_ENTERED_TEXT</snType>\r\n            <bString>MSFT100</bString>\r\n            <bUsed>true</bUsed>\r\n          </Value>\r\n          <Nodes />\r\n        </DescriptorNode>\r\n      </Nodes>\r\n    </DescriptorNode>\r\n  </Tree_x0020_Descriptors>\r\n</Tree>, UINT_TYPE=uint8, VbusDetectTermEnable=false, VendorName=, Vid=04B4, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=USBFS_v3_10, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=USBUART, CY_INSTANCE_SHORT_NAME=USBUART, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=10, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=USBUART, )
module USBFS_v3_10_0 (
    sof,
    vbusdet);
    output      sof;
    input       vbusdet;

    parameter epDMAautoOptimization = 0;

          wire  Net_1914;
          wire  Net_1915;
          wire  Net_1916;
          wire  Net_1917;
          wire  Net_1918;
          wire  Net_1919;
          wire [7:0] dma_request;
          wire  Net_1920;
          wire  Net_1921;
          wire  Net_1922;
          wire [7:0] Net_2039;
          wire  Net_2038;
          wire  Net_2037;
          wire  EPs_1_to_7_dma_complete;
          wire  Net_2036;
          wire  Net_2035;
          wire  Net_2034;
          wire  Net_2033;
          wire  Net_2032;
          wire  Net_2031;
          wire  Net_2030;
          wire  Net_2029;
          wire  Net_2028;
          wire  Net_2027;
          wire  Net_2026;
          wire  Net_2025;
          wire  Net_2024;
          wire [7:0] Net_1940;
          wire  Net_1939;
          wire  Net_1938;
          wire  Net_1937;
          wire  Net_1936;
          wire  Net_1935;
          wire  Net_1934;
          wire  Net_1933;
          wire  Net_1932;
          wire  Net_2047;
          wire  Net_1202;
          wire  dma_terminate;
          wire [7:0] Net_2040;
          wire  Net_1010;
    electrical  Net_1000;
    electrical  Net_597;
          wire  Net_1495;
          wire  Net_1498;
          wire  Net_1559;
          wire  Net_1567;
          wire  Net_1576;
          wire  Net_1579;
          wire  Net_1591;
          wire [7:0] dma_complete;
          wire  Net_1588;
          wire  Net_1876;
          wire [8:0] ep_int;
          wire  Net_1889;
          wire  busClk;
          wire  Net_95;


	cy_isr_v1_0
		#(.int_type(2'b10))
		dp_int
		 (.int_signal(Net_1010));


	wire [0:0] tmpOE__Dm_net;
	wire [0:0] tmpFB_0__Dm_net;
	wire [0:0] tmpIO_0__Dm_net;
	wire [0:0] tmpINTERRUPT_0__Dm_net;
	electrical [0:0] tmpSIOVREF__Dm_net;

	cy_psoc3_pins_v1_10
		#(.id("c39ef993-d787-4c0c-8ad6-c0c81f866442/8b77a6c4-10a0-4390-971c-672353e2a49c"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("NONCONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(1),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dm
		 (.oe(tmpOE__Dm_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dm_net[0:0]}),
		  .analog({Net_597}),
		  .io({tmpIO_0__Dm_net[0:0]}),
		  .siovref(tmpSIOVREF__Dm_net),
		  .interrupt({tmpINTERRUPT_0__Dm_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dm_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Dp_net;
	wire [0:0] tmpFB_0__Dp_net;
	wire [0:0] tmpIO_0__Dp_net;
	electrical [0:0] tmpSIOVREF__Dp_net;

	cy_psoc3_pins_v1_10
		#(.id("c39ef993-d787-4c0c-8ad6-c0c81f866442/618a72fc-5ddd-4df5-958f-a3d55102db42"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b10),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Dp
		 (.oe(tmpOE__Dp_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Dp_net[0:0]}),
		  .analog({Net_1000}),
		  .io({tmpIO_0__Dp_net[0:0]}),
		  .siovref(tmpSIOVREF__Dp_net),
		  .interrupt({Net_1010}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Dp_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_psoc3_usb_v1_0 USB (
        .dp(Net_1000),
        .dm(Net_597),
        .sof_int(sof),
        .arb_int(Net_1889),
        .usb_int(Net_1876),
        .ept_int(ep_int[8:0]),
        .ord_int(Net_95),
        .dma_req(dma_request[7:0]),
        .dma_termin(dma_terminate));


	cy_isr_v1_0
		#(.int_type(2'b10))
		ord_int
		 (.int_signal(Net_95));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_3
		 (.int_signal(ep_int[3]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_2
		 (.int_signal(ep_int[2]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_1
		 (.int_signal(ep_int[1]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		ep_0
		 (.int_signal(ep_int[0]));



	cy_isr_v1_0
		#(.int_type(2'b10))
		bus_reset
		 (.int_signal(Net_1876));



	cy_isr_v1_0
		#(.int_type(2'b10))
		arb_int
		 (.int_signal(Net_1889));



	cy_isr_v1_0
		#(.int_type(2'b10))
		sof_int
		 (.int_signal(sof));


	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign dma_complete[0] = Net_1922;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_1922));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign dma_complete[1] = Net_1921;

    ZeroTerminal ZeroTerminal_2 (
        .z(Net_1921));

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign dma_complete[2] = Net_1920;

    ZeroTerminal ZeroTerminal_3 (
        .z(Net_1920));

	// VirtualMux_4 (cy_virtualmux_v1_0)
	assign dma_complete[3] = Net_1919;

    ZeroTerminal ZeroTerminal_4 (
        .z(Net_1919));

	// VirtualMux_5 (cy_virtualmux_v1_0)
	assign dma_complete[4] = Net_1918;

	// VirtualMux_6 (cy_virtualmux_v1_0)
	assign dma_complete[5] = Net_1917;

    ZeroTerminal ZeroTerminal_5 (
        .z(Net_1918));

    ZeroTerminal ZeroTerminal_6 (
        .z(Net_1917));

	// VirtualMux_7 (cy_virtualmux_v1_0)
	assign dma_complete[6] = Net_1916;

	// VirtualMux_8 (cy_virtualmux_v1_0)
	assign dma_complete[7] = Net_1915;

    ZeroTerminal ZeroTerminal_7 (
        .z(Net_1916));

    ZeroTerminal ZeroTerminal_8 (
        .z(Net_1915));



endmodule

// Component: OneTerminal
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\OneTerminal\OneTerminal.v"
`endif

// Timer_v2_70(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=1, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG8, CySetRegReplacementString=CY_SET_REG8, DeviceFamily=PSoC5, EnableMode=0, FF16=false, FF8=true, FixedFunction=true, FixedFunctionUsed=1, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=false, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=0, NumberOfCaptures=1, param45=1, Period=24, RegDefReplacementString=reg8, RegSizeReplacementString=uint8, Resolution=8, RstStatusReplacementString=rstSts, RunMode=1, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=false, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=false, UsesHWEnable=0, VerilogSectionReplacementString=sT8, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Timer_v2_70, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Button_Timer, CY_INSTANCE_SHORT_NAME=Button_Timer, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=Button_Timer, )
module Timer_v2_70_1 (
    reset,
    interrupt,
    enable,
    trigger,
    capture,
    capture_out,
    tc,
    clock);
    input       reset;
    output      interrupt;
    input       enable;
    input       trigger;
    input       capture;
    output      capture_out;
    output      tc;
    input       clock;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 0;
    parameter Resolution = 8;
    parameter SiliconRevision = "0";

          wire  Net_261;
          wire  Net_260;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    cy_psoc3_timer_v1_0 TimerHW (
        .timer_reset(reset),
        .capture(capture),
        .enable(Net_266),
        .kill(Net_260),
        .clock(clock),
        .tc(Net_51),
        .compare(Net_261),
        .interrupt(Net_57));

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_57;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_51;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = Net_102;



endmodule

// Component: cy_analog_virtualmux_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_analog_virtualmux_v1_0\cy_analog_virtualmux_v1_0.v"
`endif

// Component: cy_vref_v1_60
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_vref_v1_60\cy_vref_v1_60.v"
`endif

// Component: or_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\or_v1_0\or_v1_0.v"
`endif

// Component: cy_constant_v1_0
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cyprimitives\CyPrimitives.cylib\cy_constant_v1_0\cy_constant_v1_0.v"
`endif

// ADC_SAR_v3_0(ADC_Clock=1, ADC_Clock_Frequency=1600000, ADC_Input_Range=0, ADC_Power=0, ADC_Reference=0, ADC_Resolution=12, ADC_SampleMode=0, Enable_next_out=false, Ref_Voltage=1.024, Ref_Voltage_mV=1024, rm_int=false, Sample_Precharge=4, Sample_Rate=100000, Sample_Rate_def=631579, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=ADC_SAR_v3_0, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Volume_ADC, CY_INSTANCE_SHORT_NAME=Volume_ADC, CY_MAJOR_VERSION=3, CY_MINOR_VERSION=0, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=Volume_ADC, )
module ADC_SAR_v3_0_2 (
    vplus,
    vminus,
    soc,
    eoc,
    aclk,
    vdac_ref,
    eos);
    inout       vplus;
    electrical  vplus;
    inout       vminus;
    electrical  vminus;
    input       soc;
    output      eoc;
    input       aclk;
    inout       vdac_ref;
    electrical  vdac_ref;
    output      eos;


          wire [3:0] vp_ctl;
          wire [3:0] vn_ctl;
          wire  Net_381;
    electrical  Net_255;
    electrical  Net_267;
    electrical  Net_210;
    electrical  Net_209;
          wire [11:0] Net_207;
          wire  Net_252;
          wire  Net_205;
          wire  Net_378;
          wire  Net_376;
    electrical  Net_368;
    electrical  Net_235;
    electrical  Net_216;
    electrical  Net_233;
          wire  Net_221;
    electrical  Net_248;
    electrical  Net_257;
    electrical  Net_149;
    electrical  Net_126;
    electrical  Net_215;
          wire  Net_188;

	// cy_analog_virtualmux_3 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_3_connect(Net_248, Net_233);
	defparam cy_analog_virtualmux_3_connect.sig_width = 1;


	cy_isr_v1_0
		#(.int_type(2'b10))
		IRQ
		 (.int_signal(eoc));


    ZeroTerminal ZeroTerminal_1 (
        .z(vp_ctl[0]));

    ZeroTerminal ZeroTerminal_2 (
        .z(vp_ctl[2]));

    ZeroTerminal ZeroTerminal_3 (
        .z(vn_ctl[1]));

    ZeroTerminal ZeroTerminal_4 (
        .z(vn_ctl[3]));

    ZeroTerminal ZeroTerminal_5 (
        .z(vp_ctl[1]));

    ZeroTerminal ZeroTerminal_6 (
        .z(vp_ctl[3]));

    ZeroTerminal ZeroTerminal_7 (
        .z(vn_ctl[0]));

    ZeroTerminal ZeroTerminal_8 (
        .z(vn_ctl[2]));


	cy_clock_v1_0
		#(.id("09407a78-929d-49da-8938-71880eb27d59/696a0979-21fc-4185-bf38-6c79febcde7a"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("625000000"),
		  .is_direct(0),
		  .is_digital(1))
		theACLK
		 (.clock_out(Net_376));


	// Clock_VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_188 = Net_221;

    cy_psoc5_sar_v2_0 ADC_SAR (
        .clock(Net_188),
        .sof_udb(soc),
        .clk_udb(),
        .vp_ctl_udb(vp_ctl[3:0]),
        .vn_ctl_udb(vn_ctl[3:0]),
        .vplus(vplus),
        .vminus(Net_126),
        .irq(Net_252),
        .data_out(Net_207[11:0]),
        .eof_udb(eoc),
        .pump_clock(Net_188),
        .ext_pin(Net_215),
        .vrefhi_out(Net_257),
        .vref(Net_248),
        .next_out(eos));

	// cy_analog_virtualmux_2 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_2_connect(Net_215, Net_209);
	defparam cy_analog_virtualmux_2_connect.sig_width = 1;

	// cy_analog_virtualmux_1 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_1_connect(Net_126, Net_149);
	defparam cy_analog_virtualmux_1_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 noconnect (
        .noconnect(Net_209));


	cy_vref_v1_0
		#(.autoenable(1),
		  .guid("89B398AD-36A8-4627-9212-707F2986319E"),
		  .name("1.024V"))
		vRef_1024
		 (.vout(Net_233));


	// cy_analog_virtualmux_4 (cy_analog_virtualmux_v1_0)
	cy_connect_v1_0 cy_analog_virtualmux_4_connect(Net_257, Net_149);
	defparam cy_analog_virtualmux_4_connect.sig_width = 1;

    cy_analog_noconnect_v1_0 cy_analog_noconnect_1 (
        .noconnect(Net_255));

    cy_analog_noconnect_v1_0 noconnect_1 (
        .noconnect(Net_368));


    assign Net_221 = Net_381 | Net_376;

    assign Net_381 = 1'h0;



endmodule

// Component: B_Timer_v2_70
`ifdef CY_BLK_DIR
`undef CY_BLK_DIR
`endif

`ifdef WARP
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70\B_Timer_v2_70.v"
`else
`define CY_BLK_DIR "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70"
`include "C:\Program Files (x86)\Cypress\PSoC Creator\4.0\PSoC Creator\psoc\content\cycomponentlibrary\CyComponentLibrary.cylib\B_Timer_v2_70\B_Timer_v2_70.v"
`endif

// Timer_v2_70(CaptureAlternatingFall=false, CaptureAlternatingRise=false, CaptureCount=2, CaptureCounterEnabled=false, CaptureInputEnabled=false, CaptureMode=0, CONTROL3=0, ControlRegRemoved=0, CtlModeReplacementString=SyncCtl, CyGetRegReplacementString=CY_GET_REG16, CySetRegReplacementString=CY_SET_REG16, DeviceFamily=PSoC5, EnableMode=0, FF16=false, FF8=false, FixedFunction=false, FixedFunctionUsed=0, HWCaptureCounterEnabled=false, InterruptOnCapture=false, InterruptOnFIFOFull=false, InterruptOnTC=false, IntOnCapture=0, IntOnFIFOFull=0, IntOnTC=0, NumberOfCaptures=1, param45=1, Period=9999, RegDefReplacementString=reg16, RegSizeReplacementString=uint16, Resolution=16, RstStatusReplacementString=rstSts, RunMode=1, SiliconRevision=0, SoftwareCaptureModeEnabled=false, SoftwareTriggerModeEnabled=false, TriggerInputEnabled=false, TriggerMode=0, UDB16=true, UDB24=false, UDB32=false, UDB8=false, UDBControlReg=true, UsesHWEnable=0, VerilogSectionReplacementString=sT16, CY_API_CALLBACK_HEADER_INCLUDE=#include "cyapicallbacks.h", CY_COMPONENT_NAME=Timer_v2_70, CY_CONST_CONFIG=true, CY_CONTROL_FILE=<:default:>, CY_DATASHEET_FILE=<:default:>, CY_FITTER_NAME=Volume_Timer, CY_INSTANCE_SHORT_NAME=Volume_Timer, CY_MAJOR_VERSION=2, CY_MINOR_VERSION=70, CY_PDL_DRIVER_NAME=, CY_PDL_DRIVER_REQ_VERSION=, CY_PDL_DRIVER_SUBGROUP=, CY_PDL_DRIVER_VARIANT=, CY_REMOVE=false, CY_SUPPRESS_API_GEN=false, CY_VERSION=PSoC Creator  4.0, INSTANCE_NAME=Volume_Timer, )
module Timer_v2_70_3 (
    reset,
    interrupt,
    enable,
    trigger,
    capture,
    capture_out,
    tc,
    clock);
    input       reset;
    output      interrupt;
    input       enable;
    input       trigger;
    input       capture;
    output      capture_out;
    output      tc;
    input       clock;

    parameter CaptureCount = 2;
    parameter CaptureCounterEnabled = 0;
    parameter DeviceFamily = "PSoC5";
    parameter InterruptOnCapture = 0;
    parameter InterruptOnTC = 0;
    parameter Resolution = 16;
    parameter SiliconRevision = "0";

          wire  Net_261;
          wire  Net_260;
          wire  Net_266;
          wire  Net_102;
          wire  Net_55;
          wire  Net_57;
          wire  Net_53;
          wire  Net_51;

    ZeroTerminal ZeroTerminal_1 (
        .z(Net_260));

	// VirtualMux_2 (cy_virtualmux_v1_0)
	assign interrupt = Net_55;

	// VirtualMux_3 (cy_virtualmux_v1_0)
	assign tc = Net_53;

    B_Timer_v2_70 TimerUDB (
        .reset(reset),
        .interrupt(Net_55),
        .enable(enable),
        .trigger(trigger),
        .capture_in(capture),
        .capture_out(capture_out),
        .tc(Net_53),
        .clock(clock));
    defparam TimerUDB.Capture_Count = 2;
    defparam TimerUDB.CaptureCounterEnabled = 0;
    defparam TimerUDB.CaptureMode = 0;
    defparam TimerUDB.EnableMode = 0;
    defparam TimerUDB.InterruptOnCapture = 0;
    defparam TimerUDB.Resolution = 16;
    defparam TimerUDB.RunMode = 1;
    defparam TimerUDB.TriggerMode = 0;

    OneTerminal OneTerminal_1 (
        .o(Net_102));

	// VirtualMux_1 (cy_virtualmux_v1_0)
	assign Net_266 = Net_102;



endmodule

// top
module top ;

          wire  Net_866;
          wire  Net_865;
          wire  Net_864;
          wire  Net_863;
          wire  Net_862;
          wire  Net_861;
          wire  Net_860;
          wire  Net_885;
          wire  Net_857;
    electrical  Net_856;
          wire  Net_855;
          wire  Net_854;
          wire  Net_853;
    electrical  Net_852;
          wire  Net_843;
          wire  Net_842;
          wire  Net_841;
          wire  Net_840;
          wire  Net_839;
          wire  Net_838;
          wire  Net_847;
          wire  Net_850;
          wire  Net_849;
          wire  Net_311;
          wire  Net_308;
          wire  Net_309;
          wire  Net_144;
          wire  Net_179;
          wire  Net_147;
          wire  Net_140;
          wire  Net_69;
          wire  Net_65;
          wire  Net_858;
    electrical  Net_824;
          wire  Net_12;
          wire  Net_10;
    electrical  Net_37;
    electrical  Net_34;
    electrical  Net_31;
    electrical  Net_28;
    electrical  Net_177;
    electrical  Net_419;
    electrical  Net_416;
    electrical  Net_325;
    electrical  Net_358;
    electrical  Net_360;
    electrical  Net_361;
    electrical  Net_362;
    electrical  Net_359;
    electrical  Net_365;
    electrical  Net_364;
    electrical  Net_363;
    electrical  Net_413;
    electrical  Net_418;
    electrical  Net_422;
    electrical  Net_367;
    electrical  Net_357;
    electrical  Net_299;
    electrical  Net_327;
    electrical  Net_330;
    electrical  Net_333;
    electrical  Net_336;
    electrical  Net_339;
    electrical  Net_342;
    electrical  Net_345;
    electrical  Net_348;
    electrical  Net_351;
    electrical  Net_16;
    electrical  Net_25;
    electrical  Net_190;
    electrical  Net_22;
    electrical  Net_15;

	wire [0:0] tmpOE__Up_SW_net;
	wire [0:0] tmpIO_0__Up_SW_net;
	wire [0:0] tmpINTERRUPT_0__Up_SW_net;
	electrical [0:0] tmpSIOVREF__Up_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("50e171f0-fb23-4d46-af70-b06dec0c8dff"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Up_SW
		 (.oe(tmpOE__Up_SW_net),
		  .y({1'b0}),
		  .fb({Net_65}),
		  .io({tmpIO_0__Up_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Up_SW_net),
		  .interrupt({tmpINTERRUPT_0__Up_SW_net[0:0]}),
		  .annotation({Net_28}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Up_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Power_LED_net;
	wire [0:0] tmpFB_0__Power_LED_net;
	wire [0:0] tmpIO_0__Power_LED_net;
	wire [0:0] tmpINTERRUPT_0__Power_LED_net;
	electrical [0:0] tmpSIOVREF__Power_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("bd9c6da6-f194-44a8-bc2e-1361f5eda610"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Power_LED
		 (.oe(tmpOE__Power_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Power_LED_net[0:0]}),
		  .io({tmpIO_0__Power_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__Power_LED_net),
		  .interrupt({tmpINTERRUPT_0__Power_LED_net[0:0]}),
		  .annotation({Net_299}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Power_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_9 (
        .connect({
            Net_357,
            Net_363
        })
    );
    defparam LED_9.comp_name = "LED_v1_0";
    defparam LED_9.port_names = "A, K";
    defparam LED_9.width = 2;

    cy_annotation_universal_v1_0 LED (
        .connect({
            Net_357,
            Net_367
        })
    );
    defparam LED.comp_name = "LED_v1_0";
    defparam LED.port_names = "A, K";
    defparam LED.width = 2;

    cy_annotation_universal_v1_0 Power_1 (
        .connect({
            Net_15
        })
    );
    defparam Power_1.comp_name = "Power_v1_0";
    defparam Power_1.port_names = "T1";
    defparam Power_1.width = 1;

    cy_annotation_universal_v1_0 SW (
        .connect({
            Net_15,
            Net_177
        })
    );
    defparam SW.comp_name = "SwitchSPST_v1_0";
    defparam SW.port_names = "T1, T2";
    defparam SW.width = 2;

	wire [0:0] tmpOE__D3_LED_net;
	wire [0:0] tmpFB_0__D3_LED_net;
	wire [0:0] tmpIO_0__D3_LED_net;
	wire [0:0] tmpINTERRUPT_0__D3_LED_net;
	electrical [0:0] tmpSIOVREF__D3_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("f9c14bb4-65a3-498e-82c9-ef9e31615f60"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		D3_LED
		 (.oe(tmpOE__D3_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__D3_LED_net[0:0]}),
		  .io({tmpIO_0__D3_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__D3_LED_net),
		  .interrupt({tmpINTERRUPT_0__D3_LED_net[0:0]}),
		  .annotation({Net_333}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__D3_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Input_2_SW_net;
	wire [0:0] tmpIO_0__Input_2_SW_net;
	wire [0:0] tmpINTERRUPT_0__Input_2_SW_net;
	electrical [0:0] tmpSIOVREF__Input_2_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("8dfd268b-0e32-4a50-8b58-8fd94eeda2f1"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_2_SW
		 (.oe(tmpOE__Input_2_SW_net),
		  .y({1'b0}),
		  .fb({Net_69}),
		  .io({tmpIO_0__Input_2_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_2_SW_net),
		  .interrupt({tmpINTERRUPT_0__Input_2_SW_net[0:0]}),
		  .annotation({Net_177}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_2_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Volume_2_net;
	wire [0:0] tmpFB_0__Volume_2_net;
	wire [0:0] tmpIO_0__Volume_2_net;
	wire [0:0] tmpINTERRUPT_0__Volume_2_net;
	electrical [0:0] tmpSIOVREF__Volume_2_net;

	cy_psoc3_pins_v1_10
		#(.id("331b5e82-c5b1-452a-b203-ff01c5fd0ce6"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Volume_2
		 (.oe(tmpOE__Volume_2_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Volume_2_net[0:0]}),
		  .io({tmpIO_0__Volume_2_net[0:0]}),
		  .siovref(tmpSIOVREF__Volume_2_net),
		  .interrupt({tmpINTERRUPT_0__Volume_2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Volume_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_1 (
        .connect({
            Net_15,
            Net_16
        })
    );
    defparam SW_1.comp_name = "SwitchSPST_v1_0";
    defparam SW_1.port_names = "T1, T2";
    defparam SW_1.width = 2;

	wire [0:0] tmpOE__Power_SW_net;
	wire [0:0] tmpIO_0__Power_SW_net;
	wire [0:0] tmpINTERRUPT_0__Power_SW_net;
	electrical [0:0] tmpSIOVREF__Power_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("971d97b6-ade6-4ef4-bc4f-a1bf65dbb16f"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Power_SW
		 (.oe(tmpOE__Power_SW_net),
		  .y({1'b0}),
		  .fb({Net_140}),
		  .io({tmpIO_0__Power_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Power_SW_net),
		  .interrupt({tmpINTERRUPT_0__Power_SW_net[0:0]}),
		  .annotation({Net_16}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Power_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Volume_Input_net;
	wire [0:0] tmpFB_0__Volume_Input_net;
	wire [0:0] tmpIO_0__Volume_Input_net;
	wire [0:0] tmpINTERRUPT_0__Volume_Input_net;
	electrical [0:0] tmpSIOVREF__Volume_Input_net;

	cy_psoc3_pins_v1_10
		#(.id("77715107-f8d5-47e5-a629-0fb83101ac6b"),
		  .drive_mode(3'b000),
		  .ibuf_enabled(1'b0),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("A"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Volume_Input
		 (.oe(tmpOE__Volume_Input_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Volume_Input_net[0:0]}),
		  .analog({Net_824}),
		  .io({tmpIO_0__Volume_Input_net[0:0]}),
		  .siovref(tmpSIOVREF__Volume_Input_net),
		  .interrupt({tmpINTERRUPT_0__Volume_Input_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Volume_Input_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_2 (
        .connect({
            Net_15,
            Net_190
        })
    );
    defparam SW_2.comp_name = "SwitchSPST_v1_0";
    defparam SW_2.port_names = "T1, T2";
    defparam SW_2.width = 2;

    cy_annotation_universal_v1_0 Q_11 (
        .connect({
            Net_416,
            Net_422,
            Net_413
        })
    );
    defparam Q_11.comp_name = "NFET_En_v1_0";
    defparam Q_11.port_names = "D, G, S";
    defparam Q_11.width = 3;

	wire [0:0] tmpOE__Input_1_SW_net;
	wire [0:0] tmpIO_0__Input_1_SW_net;
	wire [0:0] tmpINTERRUPT_0__Input_1_SW_net;
	electrical [0:0] tmpSIOVREF__Input_1_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("ef87732d-50ae-4837-a2f2-9bc7abb56da7"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_1_SW
		 (.oe(tmpOE__Input_1_SW_net),
		  .y({1'b0}),
		  .fb({Net_147}),
		  .io({tmpIO_0__Input_1_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_1_SW_net),
		  .interrupt({tmpINTERRUPT_0__Input_1_SW_net[0:0]}),
		  .annotation({Net_190}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_1_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Down_SW_net;
	wire [0:0] tmpIO_0__Down_SW_net;
	wire [0:0] tmpINTERRUPT_0__Down_SW_net;
	electrical [0:0] tmpSIOVREF__Down_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("552713cf-e0b2-4430-b87d-3eb8a47f6f8b"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Down_SW
		 (.oe(tmpOE__Down_SW_net),
		  .y({1'b0}),
		  .fb({Net_179}),
		  .io({tmpIO_0__Down_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Down_SW_net),
		  .interrupt({tmpINTERRUPT_0__Down_SW_net[0:0]}),
		  .annotation({Net_25}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Down_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 SW_3 (
        .connect({
            Net_15,
            Net_22
        })
    );
    defparam SW_3.comp_name = "SwitchSPST_v1_0";
    defparam SW_3.port_names = "T1, T2";
    defparam SW_3.width = 2;

	wire [0:0] tmpOE__D2_LED_net;
	wire [0:0] tmpFB_0__D2_LED_net;
	wire [0:0] tmpIO_0__D2_LED_net;
	wire [0:0] tmpINTERRUPT_0__D2_LED_net;
	electrical [0:0] tmpSIOVREF__D2_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("33ac696c-e798-4d3e-9f6a-74dc4b8440bd"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		D2_LED
		 (.oe(tmpOE__D2_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__D2_LED_net[0:0]}),
		  .io({tmpIO_0__D2_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__D2_LED_net),
		  .interrupt({tmpINTERRUPT_0__D2_LED_net[0:0]}),
		  .annotation({Net_330}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__D2_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Right_SW_net;
	wire [0:0] tmpIO_0__Right_SW_net;
	wire [0:0] tmpINTERRUPT_0__Right_SW_net;
	electrical [0:0] tmpSIOVREF__Right_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("10a80419-1f55-47b0-98df-b46daf1266c6"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Right_SW
		 (.oe(tmpOE__Right_SW_net),
		  .y({1'b0}),
		  .fb({Net_144}),
		  .io({tmpIO_0__Right_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Right_SW_net),
		  .interrupt({tmpINTERRUPT_0__Right_SW_net[0:0]}),
		  .annotation({Net_22}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Right_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Up
		 (.int_signal(Net_65));


    cy_annotation_universal_v1_0 SW_4 (
        .connect({
            Net_15,
            Net_25
        })
    );
    defparam SW_4.comp_name = "SwitchSPST_v1_0";
    defparam SW_4.port_names = "T1, T2";
    defparam SW_4.width = 2;

	wire [0:0] tmpOE__Left_SW_net;
	wire [0:0] tmpIO_0__Left_SW_net;
	wire [0:0] tmpINTERRUPT_0__Left_SW_net;
	electrical [0:0] tmpSIOVREF__Left_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("c937e65c-5a70-420f-9e4b-a33a186a7307"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Left_SW
		 (.oe(tmpOE__Left_SW_net),
		  .y({1'b0}),
		  .fb({Net_309}),
		  .io({tmpIO_0__Left_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Left_SW_net),
		  .interrupt({tmpINTERRUPT_0__Left_SW_net[0:0]}),
		  .annotation({Net_31}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Left_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Left
		 (.int_signal(Net_309));


    cy_annotation_universal_v1_0 SW_5 (
        .connect({
            Net_15,
            Net_28
        })
    );
    defparam SW_5.comp_name = "SwitchSPST_v1_0";
    defparam SW_5.port_names = "T1, T2";
    defparam SW_5.width = 2;

    cy_annotation_universal_v1_0 Q_12 (
        .connect({
            Net_419,
            Net_418,
            Net_413
        })
    );
    defparam Q_12.comp_name = "NFET_En_v1_0";
    defparam Q_12.port_names = "D, G, S";
    defparam Q_12.width = 3;

	wire [0:0] tmpOE__Mute_SW_net;
	wire [0:0] tmpIO_0__Mute_SW_net;
	wire [0:0] tmpINTERRUPT_0__Mute_SW_net;
	electrical [0:0] tmpSIOVREF__Mute_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("7ac1459d-a78c-4867-98a8-5f1e2a1937fe"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Mute_SW
		 (.oe(tmpOE__Mute_SW_net),
		  .y({1'b0}),
		  .fb({Net_308}),
		  .io({tmpIO_0__Mute_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Mute_SW_net),
		  .interrupt({tmpINTERRUPT_0__Mute_SW_net[0:0]}),
		  .annotation({Net_34}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Mute_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Mute
		 (.int_signal(Net_308));


    cy_annotation_universal_v1_0 SW_6 (
        .connect({
            Net_15,
            Net_31
        })
    );
    defparam SW_6.comp_name = "SwitchSPST_v1_0";
    defparam SW_6.port_names = "T1, T2";
    defparam SW_6.width = 2;

	wire [0:0] tmpOE__Enter_SW_net;
	wire [0:0] tmpIO_0__Enter_SW_net;
	wire [0:0] tmpINTERRUPT_0__Enter_SW_net;
	electrical [0:0] tmpSIOVREF__Enter_SW_net;

	cy_psoc3_pins_v1_10
		#(.id("a20e79aa-8d54-4001-9fb7-62ac841dfc23"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Enter_SW
		 (.oe(tmpOE__Enter_SW_net),
		  .y({1'b0}),
		  .fb({Net_311}),
		  .io({tmpIO_0__Enter_SW_net[0:0]}),
		  .siovref(tmpSIOVREF__Enter_SW_net),
		  .interrupt({tmpINTERRUPT_0__Enter_SW_net[0:0]}),
		  .annotation({Net_37}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Enter_SW_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Enter
		 (.int_signal(Net_311));


    cy_annotation_universal_v1_0 SW_7 (
        .connect({
            Net_15,
            Net_34
        })
    );
    defparam SW_7.comp_name = "SwitchSPST_v1_0";
    defparam SW_7.port_names = "T1, T2";
    defparam SW_7.width = 2;

    cy_annotation_universal_v1_0 LED_10 (
        .connect({
            Net_357,
            Net_416
        })
    );
    defparam LED_10.comp_name = "LED_v1_0";
    defparam LED_10.port_names = "A, K";
    defparam LED_10.width = 2;

    USBFS_v3_10_0 USBUART (
        .sof(Net_849),
        .vbusdet(1'b0));
    defparam USBUART.epDMAautoOptimization = 0;

    cy_annotation_universal_v1_0 SW_8 (
        .connect({
            Net_15,
            Net_37
        })
    );
    defparam SW_8.comp_name = "SwitchSPST_v1_0";
    defparam SW_8.port_names = "T1, T2";
    defparam SW_8.width = 2;

	wire [0:0] tmpOE__D1_LED_net;
	wire [0:0] tmpFB_0__D1_LED_net;
	wire [0:0] tmpIO_0__D1_LED_net;
	wire [0:0] tmpINTERRUPT_0__D1_LED_net;
	electrical [0:0] tmpSIOVREF__D1_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("8d9a8170-97d0-41fd-85f1-482e1d28ddb5"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		D1_LED
		 (.oe(tmpOE__D1_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__D1_LED_net[0:0]}),
		  .io({tmpIO_0__D1_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__D1_LED_net),
		  .interrupt({tmpINTERRUPT_0__D1_LED_net[0:0]}),
		  .annotation({Net_327}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__D1_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__U1_LED_net;
	wire [0:0] tmpFB_0__U1_LED_net;
	wire [0:0] tmpIO_0__U1_LED_net;
	wire [0:0] tmpINTERRUPT_0__U1_LED_net;
	electrical [0:0] tmpSIOVREF__U1_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("0c5ee041-aa58-4005-bf74-0e51ef3cc74c"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U1_LED
		 (.oe(tmpOE__U1_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U1_LED_net[0:0]}),
		  .io({tmpIO_0__U1_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U1_LED_net),
		  .interrupt({tmpINTERRUPT_0__U1_LED_net[0:0]}),
		  .annotation({Net_336}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U1_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_8 (
        .connect({
            Net_357,
            Net_364
        })
    );
    defparam LED_8.comp_name = "LED_v1_0";
    defparam LED_8.port_names = "A, K";
    defparam LED_8.width = 2;

	wire [0:0] tmpOE__U2_LED_net;
	wire [0:0] tmpFB_0__U2_LED_net;
	wire [0:0] tmpIO_0__U2_LED_net;
	wire [0:0] tmpINTERRUPT_0__U2_LED_net;
	electrical [0:0] tmpSIOVREF__U2_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("34ee5d3c-f116-4855-9841-716bbf2d5c0a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U2_LED
		 (.oe(tmpOE__U2_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U2_LED_net[0:0]}),
		  .io({tmpIO_0__U2_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U2_LED_net),
		  .interrupt({tmpINTERRUPT_0__U2_LED_net[0:0]}),
		  .annotation({Net_339}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U2_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_7 (
        .connect({
            Net_357,
            Net_365
        })
    );
    defparam LED_7.comp_name = "LED_v1_0";
    defparam LED_7.port_names = "A, K";
    defparam LED_7.width = 2;

	wire [0:0] tmpOE__U3_LED_net;
	wire [0:0] tmpFB_0__U3_LED_net;
	wire [0:0] tmpIO_0__U3_LED_net;
	wire [0:0] tmpINTERRUPT_0__U3_LED_net;
	electrical [0:0] tmpSIOVREF__U3_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("f147d88c-09e5-4bb2-a98f-c260f43c8615"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U3_LED
		 (.oe(tmpOE__U3_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U3_LED_net[0:0]}),
		  .io({tmpIO_0__U3_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U3_LED_net),
		  .interrupt({tmpINTERRUPT_0__U3_LED_net[0:0]}),
		  .annotation({Net_342}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U3_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_6 (
        .connect({
            Net_357,
            Net_359
        })
    );
    defparam LED_6.comp_name = "LED_v1_0";
    defparam LED_6.port_names = "A, K";
    defparam LED_6.width = 2;

	wire [0:0] tmpOE__U4_LED_net;
	wire [0:0] tmpFB_0__U4_LED_net;
	wire [0:0] tmpIO_0__U4_LED_net;
	wire [0:0] tmpINTERRUPT_0__U4_LED_net;
	electrical [0:0] tmpSIOVREF__U4_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("ad253024-065b-42b7-9791-2c9cc73335ee"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U4_LED
		 (.oe(tmpOE__U4_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U4_LED_net[0:0]}),
		  .io({tmpIO_0__U4_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U4_LED_net),
		  .interrupt({tmpINTERRUPT_0__U4_LED_net[0:0]}),
		  .annotation({Net_345}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U4_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_5 (
        .connect({
            Net_357,
            Net_362
        })
    );
    defparam LED_5.comp_name = "LED_v1_0";
    defparam LED_5.port_names = "A, K";
    defparam LED_5.width = 2;

	wire [0:0] tmpOE__U5_LED_net;
	wire [0:0] tmpFB_0__U5_LED_net;
	wire [0:0] tmpIO_0__U5_LED_net;
	wire [0:0] tmpINTERRUPT_0__U5_LED_net;
	electrical [0:0] tmpSIOVREF__U5_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("0716addc-4e8d-4934-9483-eca0f82c3b0e"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U5_LED
		 (.oe(tmpOE__U5_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U5_LED_net[0:0]}),
		  .io({tmpIO_0__U5_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U5_LED_net),
		  .interrupt({tmpINTERRUPT_0__U5_LED_net[0:0]}),
		  .annotation({Net_348}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U5_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_4 (
        .connect({
            Net_357,
            Net_361
        })
    );
    defparam LED_4.comp_name = "LED_v1_0";
    defparam LED_4.port_names = "A, K";
    defparam LED_4.width = 2;

	wire [0:0] tmpOE__U6_LED_net;
	wire [0:0] tmpFB_0__U6_LED_net;
	wire [0:0] tmpIO_0__U6_LED_net;
	wire [0:0] tmpINTERRUPT_0__U6_LED_net;
	electrical [0:0] tmpSIOVREF__U6_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("5d492976-dee9-4c6a-ac75-2e818927f392"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U6_LED
		 (.oe(tmpOE__U6_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U6_LED_net[0:0]}),
		  .io({tmpIO_0__U6_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U6_LED_net),
		  .interrupt({tmpINTERRUPT_0__U6_LED_net[0:0]}),
		  .annotation({Net_351}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U6_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_3 (
        .connect({
            Net_357,
            Net_360
        })
    );
    defparam LED_3.comp_name = "LED_v1_0";
    defparam LED_3.port_names = "A, K";
    defparam LED_3.width = 2;

	wire [0:0] tmpOE__U7_LED_net;
	wire [0:0] tmpFB_0__U7_LED_net;
	wire [0:0] tmpIO_0__U7_LED_net;
	wire [0:0] tmpINTERRUPT_0__U7_LED_net;
	electrical [0:0] tmpSIOVREF__U7_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("3a8f1d10-2142-40fe-bf2c-1dc73b880ee1"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U7_LED
		 (.oe(tmpOE__U7_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U7_LED_net[0:0]}),
		  .io({tmpIO_0__U7_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U7_LED_net),
		  .interrupt({tmpINTERRUPT_0__U7_LED_net[0:0]}),
		  .annotation({Net_422}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U7_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    cy_annotation_universal_v1_0 LED_2 (
        .connect({
            Net_357,
            Net_358
        })
    );
    defparam LED_2.comp_name = "LED_v1_0";
    defparam LED_2.port_names = "A, K";
    defparam LED_2.width = 2;

    cy_annotation_universal_v1_0 LED_1 (
        .connect({
            Net_357,
            Net_325
        })
    );
    defparam LED_1.comp_name = "LED_v1_0";
    defparam LED_1.port_names = "A, K";
    defparam LED_1.width = 2;

	wire [0:0] tmpOE__U8_LED_net;
	wire [0:0] tmpFB_0__U8_LED_net;
	wire [0:0] tmpIO_0__U8_LED_net;
	wire [0:0] tmpINTERRUPT_0__U8_LED_net;
	electrical [0:0] tmpSIOVREF__U8_LED_net;

	cy_psoc3_pins_v1_10
		#(.id("132f002a-c46f-4c4c-8e78-448460a60d97"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b1),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b1),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		U8_LED
		 (.oe(tmpOE__U8_LED_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__U8_LED_net[0:0]}),
		  .io({tmpIO_0__U8_LED_net[0:0]}),
		  .siovref(tmpSIOVREF__U8_LED_net),
		  .interrupt({tmpINTERRUPT_0__U8_LED_net[0:0]}),
		  .annotation({Net_418}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__U8_LED_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Volume_1_net;
	wire [0:0] tmpFB_0__Volume_1_net;
	wire [0:0] tmpIO_0__Volume_1_net;
	wire [0:0] tmpINTERRUPT_0__Volume_1_net;
	electrical [0:0] tmpSIOVREF__Volume_1_net;

	cy_psoc3_pins_v1_10
		#(.id("e851a3b9-efb8-48be-bbb8-b303b216c393"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Volume_1
		 (.oe(tmpOE__Volume_1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Volume_1_net[0:0]}),
		  .io({tmpIO_0__Volume_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Volume_1_net),
		  .interrupt({tmpINTERRUPT_0__Volume_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Volume_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Down
		 (.int_signal(Net_179));



	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Right
		 (.int_signal(Net_144));


    cy_annotation_universal_v1_0 Q_1 (
        .connect({
            Net_367,
            Net_299,
            Net_413
        })
    );
    defparam Q_1.comp_name = "NFET_En_v1_0";
    defparam Q_1.port_names = "D, G, S";
    defparam Q_1.width = 3;


	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Input_1
		 (.int_signal(Net_147));



	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Power
		 (.int_signal(Net_140));


    cy_annotation_universal_v1_0 Power_2 (
        .connect({
            Net_357
        })
    );
    defparam Power_2.comp_name = "Power_v1_0";
    defparam Power_2.port_names = "T1";
    defparam Power_2.width = 1;

    cy_annotation_universal_v1_0 GND_1 (
        .connect({
            Net_413
        })
    );
    defparam GND_1.comp_name = "Gnd_v1_0";
    defparam GND_1.port_names = "T1";
    defparam GND_1.width = 1;

    cy_annotation_universal_v1_0 Q_2 (
        .connect({
            Net_325,
            Net_327,
            Net_413
        })
    );
    defparam Q_2.comp_name = "NFET_En_v1_0";
    defparam Q_2.port_names = "D, G, S";
    defparam Q_2.width = 3;

    cy_annotation_universal_v1_0 Q_3 (
        .connect({
            Net_358,
            Net_330,
            Net_413
        })
    );
    defparam Q_3.comp_name = "NFET_En_v1_0";
    defparam Q_3.port_names = "D, G, S";
    defparam Q_3.width = 3;

    cy_annotation_universal_v1_0 Q_4 (
        .connect({
            Net_360,
            Net_333,
            Net_413
        })
    );
    defparam Q_4.comp_name = "NFET_En_v1_0";
    defparam Q_4.port_names = "D, G, S";
    defparam Q_4.width = 3;

    cy_annotation_universal_v1_0 Q_5 (
        .connect({
            Net_361,
            Net_336,
            Net_413
        })
    );
    defparam Q_5.comp_name = "NFET_En_v1_0";
    defparam Q_5.port_names = "D, G, S";
    defparam Q_5.width = 3;

    cy_annotation_universal_v1_0 Q_6 (
        .connect({
            Net_362,
            Net_339,
            Net_413
        })
    );
    defparam Q_6.comp_name = "NFET_En_v1_0";
    defparam Q_6.port_names = "D, G, S";
    defparam Q_6.width = 3;

    cy_annotation_universal_v1_0 Q_7 (
        .connect({
            Net_359,
            Net_342,
            Net_413
        })
    );
    defparam Q_7.comp_name = "NFET_En_v1_0";
    defparam Q_7.port_names = "D, G, S";
    defparam Q_7.width = 3;

    cy_annotation_universal_v1_0 Q_8 (
        .connect({
            Net_365,
            Net_345,
            Net_413
        })
    );
    defparam Q_8.comp_name = "NFET_En_v1_0";
    defparam Q_8.port_names = "D, G, S";
    defparam Q_8.width = 3;

    cy_annotation_universal_v1_0 Q_9 (
        .connect({
            Net_364,
            Net_348,
            Net_413
        })
    );
    defparam Q_9.comp_name = "NFET_En_v1_0";
    defparam Q_9.port_names = "D, G, S";
    defparam Q_9.width = 3;

    cy_annotation_universal_v1_0 Q_10 (
        .connect({
            Net_363,
            Net_351,
            Net_413
        })
    );
    defparam Q_10.comp_name = "NFET_En_v1_0";
    defparam Q_10.port_names = "D, G, S";
    defparam Q_10.width = 3;

    cy_annotation_universal_v1_0 LED_11 (
        .connect({
            Net_357,
            Net_419
        })
    );
    defparam LED_11.comp_name = "LED_v1_0";
    defparam LED_11.port_names = "A, K";
    defparam LED_11.width = 2;


	cy_isr_v1_0
		#(.int_type(2'b00))
		i_Input_2
		 (.int_signal(Net_69));


	wire [0:0] tmpOE__Input_Relais_0_net;
	wire [0:0] tmpFB_0__Input_Relais_0_net;
	wire [0:0] tmpIO_0__Input_Relais_0_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_0_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_0_net;

	cy_psoc3_pins_v1_10
		#(.id("d8417365-78ff-4769-a457-2b44df14e437"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_0
		 (.oe(tmpOE__Input_Relais_0_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_0_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_0_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_0_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_0_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_0_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Input_Relais_1_net;
	wire [0:0] tmpFB_0__Input_Relais_1_net;
	wire [0:0] tmpIO_0__Input_Relais_1_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_1_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_1_net;

	cy_psoc3_pins_v1_10
		#(.id("6eed563a-205c-4eba-8a18-2f60c4f4af5b"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_1
		 (.oe(tmpOE__Input_Relais_1_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_1_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_1_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_1_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_1_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_1_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Input_Relais_2_net;
	wire [0:0] tmpFB_0__Input_Relais_2_net;
	wire [0:0] tmpIO_0__Input_Relais_2_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_2_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_2_net;

	cy_psoc3_pins_v1_10
		#(.id("edcbfb75-585e-43aa-9c48-258d8e96465c"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_2
		 (.oe(tmpOE__Input_Relais_2_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_2_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_2_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_2_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_2_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_2_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Input_Relais_3_net;
	wire [0:0] tmpFB_0__Input_Relais_3_net;
	wire [0:0] tmpIO_0__Input_Relais_3_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_3_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_3_net;

	cy_psoc3_pins_v1_10
		#(.id("debeec55-d250-411c-bbd8-482aa67969e8"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_3
		 (.oe(tmpOE__Input_Relais_3_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_3_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_3_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_3_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_3_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_3_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};


	cy_clock_v1_0
		#(.id("c0fb34bd-1044-4931-9788-16b01ce89812"),
		  .source_clock_id(""),
		  .divisor(0),
		  .period("10000000000000"),
		  .is_direct(0),
		  .is_digital(1))
		timer_clock
		 (.clock_out(Net_10));


    ZeroTerminal ZeroTerminal_1 (
        .z(Net_12));

    Timer_v2_70_1 Button_Timer (
        .reset(Net_12),
        .interrupt(Net_838),
        .enable(1'b1),
        .trigger(1'b1),
        .capture(1'b0),
        .capture_out(Net_842),
        .tc(Net_843),
        .clock(Net_10));
    defparam Button_Timer.CaptureCount = 2;
    defparam Button_Timer.CaptureCounterEnabled = 0;
    defparam Button_Timer.DeviceFamily = "PSoC5";
    defparam Button_Timer.InterruptOnCapture = 0;
    defparam Button_Timer.InterruptOnTC = 0;
    defparam Button_Timer.Resolution = 8;
    defparam Button_Timer.SiliconRevision = "0";


	cy_isr_v1_0
		#(.int_type(2'b10))
		Button_Timer_Interrupt
		 (.int_signal(Net_843));


	wire [0:0] tmpOE__Input_Relais_4_net;
	wire [0:0] tmpFB_0__Input_Relais_4_net;
	wire [0:0] tmpIO_0__Input_Relais_4_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_4_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_4_net;

	cy_psoc3_pins_v1_10
		#(.id("2196071d-f902-4600-a30b-0e5ed093a29e"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_4
		 (.oe(tmpOE__Input_Relais_4_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_4_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_4_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_4_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_4_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_4_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Input_Relais_5_net;
	wire [0:0] tmpFB_0__Input_Relais_5_net;
	wire [0:0] tmpIO_0__Input_Relais_5_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_5_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_5_net;

	cy_psoc3_pins_v1_10
		#(.id("fee8d0cb-e22f-44be-997b-c5de7a01ff10"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_5
		 (.oe(tmpOE__Input_Relais_5_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_5_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_5_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_5_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_5_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_5_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Input_Relais_6_net;
	wire [0:0] tmpFB_0__Input_Relais_6_net;
	wire [0:0] tmpIO_0__Input_Relais_6_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_6_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_6_net;

	cy_psoc3_pins_v1_10
		#(.id("0e54dd9b-028c-4d98-b62e-b3e85a35578a"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_6
		 (.oe(tmpOE__Input_Relais_6_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_6_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_6_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_6_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_6_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_6_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Input_Relais_7_net;
	wire [0:0] tmpFB_0__Input_Relais_7_net;
	wire [0:0] tmpIO_0__Input_Relais_7_net;
	wire [0:0] tmpINTERRUPT_0__Input_Relais_7_net;
	electrical [0:0] tmpSIOVREF__Input_Relais_7_net;

	cy_psoc3_pins_v1_10
		#(.id("216d2b50-61b3-421d-bb96-f508642c8fb5"),
		  .drive_mode(3'b110),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b0),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("I"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b00),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Input_Relais_7
		 (.oe(tmpOE__Input_Relais_7_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Input_Relais_7_net[0:0]}),
		  .io({tmpIO_0__Input_Relais_7_net[0:0]}),
		  .siovref(tmpSIOVREF__Input_Relais_7_net),
		  .interrupt({tmpINTERRUPT_0__Input_Relais_7_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Input_Relais_7_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Protection_IN_net;
	wire [0:0] tmpFB_0__Protection_IN_net;
	wire [0:0] tmpIO_0__Protection_IN_net;
	wire [0:0] tmpINTERRUPT_0__Protection_IN_net;
	electrical [0:0] tmpSIOVREF__Protection_IN_net;

	cy_psoc3_pins_v1_10
		#(.id("d1aaa034-280c-4081-8f3f-e469690163fe"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Protection_IN
		 (.oe(tmpOE__Protection_IN_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Protection_IN_net[0:0]}),
		  .io({tmpIO_0__Protection_IN_net[0:0]}),
		  .siovref(tmpSIOVREF__Protection_IN_net),
		  .interrupt({tmpINTERRUPT_0__Protection_IN_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Protection_IN_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Protection_CLR_net;
	wire [0:0] tmpFB_0__Protection_CLR_net;
	wire [0:0] tmpIO_0__Protection_CLR_net;
	wire [0:0] tmpINTERRUPT_0__Protection_CLR_net;
	electrical [0:0] tmpSIOVREF__Protection_CLR_net;

	cy_psoc3_pins_v1_10
		#(.id("145fb2a3-062a-4513-8368-10eb10920cba"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Protection_CLR
		 (.oe(tmpOE__Protection_CLR_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Protection_CLR_net[0:0]}),
		  .io({tmpIO_0__Protection_CLR_net[0:0]}),
		  .siovref(tmpSIOVREF__Protection_CLR_net),
		  .interrupt({tmpINTERRUPT_0__Protection_CLR_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Protection_CLR_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

	wire [0:0] tmpOE__Protection_CLK_net;
	wire [0:0] tmpFB_0__Protection_CLK_net;
	wire [0:0] tmpIO_0__Protection_CLK_net;
	wire [0:0] tmpINTERRUPT_0__Protection_CLK_net;
	electrical [0:0] tmpSIOVREF__Protection_CLK_net;

	cy_psoc3_pins_v1_10
		#(.id("285d059c-11c0-4f83-bf2f-775a37cfba2a"),
		  .drive_mode(3'b011),
		  .ibuf_enabled(1'b1),
		  .init_dr_st(1'b0),
		  .input_clk_en(0),
		  .input_sync(1'b1),
		  .input_sync_mode(1'b0),
		  .intr_mode(2'b00),
		  .invert_in_clock(0),
		  .invert_in_clock_en(0),
		  .invert_in_reset(0),
		  .invert_out_clock(0),
		  .invert_out_clock_en(0),
		  .invert_out_reset(0),
		  .io_voltage(""),
		  .layout_mode("CONTIGUOUS"),
		  .oe_conn(1'b0),
		  .oe_reset(0),
		  .oe_sync(1'b0),
		  .output_clk_en(0),
		  .output_clock_mode(1'b0),
		  .output_conn(1'b0),
		  .output_mode(1'b0),
		  .output_reset(0),
		  .output_sync(1'b0),
		  .pa_in_clock(-1),
		  .pa_in_clock_en(-1),
		  .pa_in_reset(-1),
		  .pa_out_clock(-1),
		  .pa_out_clock_en(-1),
		  .pa_out_reset(-1),
		  .pin_aliases(""),
		  .pin_mode("O"),
		  .por_state(4),
		  .sio_group_cnt(0),
		  .sio_hyst(1'b1),
		  .sio_ibuf(""),
		  .sio_info(2'b00),
		  .sio_obuf(""),
		  .sio_refsel(""),
		  .sio_vtrip(""),
		  .sio_hifreq(""),
		  .sio_vohsel(""),
		  .slew_rate(1'b0),
		  .spanning(0),
		  .use_annotation(1'b0),
		  .vtrip(2'b10),
		  .width(1),
		  .ovt_hyst_trim(1'b0),
		  .ovt_needed(1'b0),
		  .ovt_slew_control(2'b00),
		  .input_buffer_sel(2'b00))
		Protection_CLK
		 (.oe(tmpOE__Protection_CLK_net),
		  .y({1'b0}),
		  .fb({tmpFB_0__Protection_CLK_net[0:0]}),
		  .io({tmpIO_0__Protection_CLK_net[0:0]}),
		  .siovref(tmpSIOVREF__Protection_CLK_net),
		  .interrupt({tmpINTERRUPT_0__Protection_CLK_net[0:0]}),
		  .in_clock({1'b0}),
		  .in_clock_en({1'b1}),
		  .in_reset({1'b0}),
		  .out_clock({1'b0}),
		  .out_clock_en({1'b1}),
		  .out_reset({1'b0}));

	assign tmpOE__Protection_CLK_net = (`CYDEV_CHIP_MEMBER_USED == `CYDEV_CHIP_MEMBER_3A && `CYDEV_CHIP_REVISION_USED < `CYDEV_CHIP_REVISION_3A_ES3) ? ~{1'b1} : {1'b1};

    ADC_SAR_v3_0_2 Volume_ADC (
        .vplus(Net_824),
        .vminus(Net_852),
        .soc(1'b0),
        .eoc(Net_854),
        .aclk(1'b0),
        .vdac_ref(Net_856),
        .eos(Net_857));


	cy_clock_v1_0
		#(.id("0c0c722d-8cc5-42c0-a3f5-66165e9d0bc0"),
		  .source_clock_id("315365C3-2E3E-4f04-84A2-BB564A173261"),
		  .divisor(0),
		  .period("1600000000000"),
		  .is_direct(0),
		  .is_digital(1))
		timer_clock_1
		 (.clock_out(Net_858));


    ZeroTerminal ZeroTerminal_2 (
        .z(Net_860));

    Timer_v2_70_3 Volume_Timer (
        .reset(Net_860),
        .interrupt(Net_861),
        .enable(1'b1),
        .trigger(1'b1),
        .capture(1'b0),
        .capture_out(Net_865),
        .tc(Net_866),
        .clock(Net_858));
    defparam Volume_Timer.CaptureCount = 2;
    defparam Volume_Timer.CaptureCounterEnabled = 0;
    defparam Volume_Timer.DeviceFamily = "PSoC5";
    defparam Volume_Timer.InterruptOnCapture = 0;
    defparam Volume_Timer.InterruptOnTC = 0;
    defparam Volume_Timer.Resolution = 16;
    defparam Volume_Timer.SiliconRevision = "0";



endmodule

