# THIS FILE IS AUTOMATICALLY GENERATED
# Project: C:\Users\Lukas Creutzburg\Documents\GitHub\freeDSP_6CHamp\PSoC Workspace\Controls.cydsn\Controls.cyprj
# Date: Fri, 18 Nov 2016 17:00:58 GMT
#set_units -time ns
create_clock -name {Volume_ADC_Ext_CP_Clk(routed)} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_0}]]
create_clock -name {CyILO} -period 10000 -waveform {0 5000} [list [get_pins {ClockBlock/ilo}] [get_pins {ClockBlock/clk_100k}] [get_pins {ClockBlock/clk_1k}] [get_pins {ClockBlock/clk_32k}]]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CyPLL_OUT} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/pllout}]]
create_clock -name {CyMASTER_CLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/clk_sync}]]
create_generated_clock -name {CyBUS_CLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 2 3} [list [get_pins {ClockBlock/clk_bus_glb}]]
create_clock -name {Volume_ADC_Ext_CP_Clk} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dclk_glb_0}]]
create_generated_clock -name {Volume_ADC_theACLK} -source [get_pins {ClockBlock/clk_sync}] -edges {1 39 77} [list [get_pins {ClockBlock/aclk_glb_0}]]
create_clock -name {Volume_ADC_theACLK(fixed-function)} -period 1583.3333333333333 -waveform {0 791.666666666667} [get_pins {ClockBlock/aclk_glb_ff_0}]
create_generated_clock -name {timer_clock} -source [get_pins {ClockBlock/clk_sync}] -edges {1 65537 131073} [list [get_pins {ClockBlock/dclk_glb_1}]]
create_clock -name {timer_clock(fixed-function)} -period 2730666.6666666665 -waveform {0 41.6666666666667} [get_pins {ClockBlock/dclk_glb_ff_1}]

set_false_path -from [get_pins {__ONE__/q}]

# Component constraints for C:\Users\Lukas Creutzburg\Documents\GitHub\freeDSP_6CHamp\PSoC Workspace\Controls.cydsn\TopDesign\TopDesign.cysch
# Project: C:\Users\Lukas Creutzburg\Documents\GitHub\freeDSP_6CHamp\PSoC Workspace\Controls.cydsn\Controls.cyprj
# Date: Fri, 18 Nov 2016 17:00:52 GMT
