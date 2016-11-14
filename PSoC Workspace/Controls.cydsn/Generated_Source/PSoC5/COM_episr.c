/***************************************************************************//**
* \file COM_episr.c
* \version 3.0
*
* \brief
*  This file contains the Data endpoint Interrupt Service Routines.
*
********************************************************************************
* \copyright
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "COM_pvt.h"
#include "COM_cydmac.h"
#include "cyapicallbacks.h"


/***************************************
* Custom Declarations
***************************************/
/* `#START CUSTOM_DECLARATIONS` Place your declaration here */

/* `#END` */


#if (COM_EP1_ISR_ACTIVE)
    /******************************************************************************
    * Function Name: COM_EP_1_ISR
    ***************************************************************************//**
    *
    *  Endpoint 1 Interrupt Service Routine
    *
    ******************************************************************************/
    CY_ISR(COM_EP_1_ISR)
    {

    #ifdef COM_EP_1_ISR_ENTRY_CALLBACK
        COM_EP_1_ISR_EntryCallback();
    #endif /* (COM_EP_1_ISR_ENTRY_CALLBACK) */

        /* `#START EP1_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    
        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP1_INTR);
            
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to be read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP1].addr & COM_DIR_IN))
    #endif /* (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP1].epCr0;
            
            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP1) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP1].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP1].apiEpState = COM_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if (COM_midi_out_ep == COM_EP1)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */
    
        /* `#START EP1_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_1_ISR_EXIT_CALLBACK
        COM_EP_1_ISR_ExitCallback();
    #endif /* (COM_EP_1_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }

#endif /* (COM_EP1_ISR_ACTIVE) */


#if (COM_EP2_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_EP_2_ISR
    ****************************************************************************//**
    *
    *  Endpoint 2 Interrupt Service Routine.
    *
    *******************************************************************************/
    CY_ISR(COM_EP_2_ISR)
    {
    #ifdef COM_EP_2_ISR_ENTRY_CALLBACK
        COM_EP_2_ISR_EntryCallback();
    #endif /* (COM_EP_2_ISR_ENTRY_CALLBACK) */

        /* `#START EP2_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */

        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP2_INTR);

        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to be read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP2].addr & COM_DIR_IN))
    #endif /* (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO) */
        {            
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP2].epCr0;
            
            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP2) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP2].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP2].apiEpState = COM_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if (COM_midi_out_ep == COM_EP2)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */        
    
        /* `#START EP2_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_2_ISR_EXIT_CALLBACK
        COM_EP_2_ISR_ExitCallback();
    #endif /* (COM_EP_2_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (COM_EP2_ISR_ACTIVE) */


#if (COM_EP3_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_EP_3_ISR
    ****************************************************************************//**
    *
    *  Endpoint 3 Interrupt Service Routine.
    *
    *******************************************************************************/
    CY_ISR(COM_EP_3_ISR)
    {
    #ifdef COM_EP_3_ISR_ENTRY_CALLBACK
        COM_EP_3_ISR_EntryCallback();
    #endif /* (COM_EP_3_ISR_ENTRY_CALLBACK) */

        /* `#START EP3_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */

        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP3_INTR);    

        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to be read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP3].addr & COM_DIR_IN))
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
        {            
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP3].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP3) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP3].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP3].apiEpState = COM_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if (COM_midi_out_ep == COM_EP3)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */        

        /* `#START EP3_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_3_ISR_EXIT_CALLBACK
        COM_EP_3_ISR_ExitCallback();
    #endif /* (COM_EP_3_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (COM_EP3_ISR_ACTIVE) */


#if (COM_EP4_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_EP_4_ISR
    ****************************************************************************//**
    *
    *  Endpoint 4 Interrupt Service Routine.
    *
    *******************************************************************************/
    CY_ISR(COM_EP_4_ISR)
    {
    #ifdef COM_EP_4_ISR_ENTRY_CALLBACK
        COM_EP_4_ISR_EntryCallback();
    #endif /* (COM_EP_4_ISR_ENTRY_CALLBACK) */

        /* `#START EP4_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */

        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP4_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP4].addr & COM_DIR_IN))
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP4].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP4) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP4].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP4].apiEpState = COM_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if(COM_midi_out_ep == COM_EP4)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */        

        /* `#START EP4_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_4_ISR_EXIT_CALLBACK
        COM_EP_4_ISR_ExitCallback();
    #endif /* (COM_EP_4_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (COM_EP4_ISR_ACTIVE) */


#if (COM_EP5_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_EP_5_ISR
    ****************************************************************************//**
    *
    *  Endpoint 5 Interrupt Service Routine
    *
    *
    *******************************************************************************/
    CY_ISR(COM_EP_5_ISR)
    {
    #ifdef COM_EP_5_ISR_ENTRY_CALLBACK
        COM_EP_5_ISR_EntryCallback();
    #endif /* (COM_EP_5_ISR_ENTRY_CALLBACK) */

        /* `#START EP5_USER_CODE` Place your code here */

        /* `#END` */

    #if (defined(COM_ENABLE_MIDI_STREAMING) && !defined(COM_MAIN_SERVICE_MIDI_OUT) && \
                 COM_ISR_SERVICE_MIDI_OUT && CY_PSOC3)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */

        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP5_INTR);
    
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP5].addr & COM_DIR_IN))
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
        {            
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP5].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP5) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP5].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP5].apiEpState = COM_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))        
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if (COM_midi_out_ep == COM_EP5)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP5_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_5_ISR_EXIT_CALLBACK
        COM_EP_5_ISR_ExitCallback();
    #endif /* (COM_EP_5_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (COM_EP5_ISR_ACTIVE) */


#if (COM_EP6_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_EP_6_ISR
    ****************************************************************************//**
    *
    *  Endpoint 6 Interrupt Service Routine.
    *
    *
    *******************************************************************************/
    CY_ISR(COM_EP_6_ISR)
    {
    #ifdef COM_EP_6_ISR_ENTRY_CALLBACK
        COM_EP_6_ISR_EntryCallback();
    #endif /* (COM_EP_6_ISR_ENTRY_CALLBACK) */

        /* `#START EP6_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */

        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP6_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP6].addr & COM_DIR_IN))
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP6].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP6) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP6].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }
            
            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP6].apiEpState = COM_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if (COM_midi_out_ep == COM_EP6)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP6_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_6_ISR_EXIT_CALLBACK
        COM_EP_6_ISR_ExitCallback();
    #endif /* (COM_EP_6_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (COM_EP6_ISR_ACTIVE) */


#if (COM_EP7_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_EP_7_ISR
    ****************************************************************************//**
    *
    *  Endpoint 7 Interrupt Service Routine.
    *
    *
    *******************************************************************************/
    CY_ISR(COM_EP_7_ISR)
    {
    #ifdef COM_EP_7_ISR_ENTRY_CALLBACK
        COM_EP_7_ISR_EntryCallback();
    #endif /* (COM_EP_7_ISR_ENTRY_CALLBACK) */

        /* `#START EP7_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    
        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP7_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP7].addr & COM_DIR_IN))
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
        {           
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP7].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP7) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP7].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }
            
            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP7].apiEpState = COM_EVENT_PENDING;
        }


    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if(COM_midi_out_ep == COM_EP7)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP7_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_7_ISR_EXIT_CALLBACK
        COM_EP_7_ISR_ExitCallback();
    #endif /* (COM_EP_7_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (COM_EP7_ISR_ACTIVE) */


#if (COM_EP8_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_EP_8_ISR
    ****************************************************************************//**
    *
    *  Endpoint 8 Interrupt Service Routine
    *
    *
    *******************************************************************************/
    CY_ISR(COM_EP_8_ISR)
    {
    #ifdef COM_EP_8_ISR_ENTRY_CALLBACK
        COM_EP_8_ISR_EntryCallback();
    #endif /* (COM_EP_8_ISR_ENTRY_CALLBACK) */

        /* `#START EP8_USER_CODE` Place your code here */

        /* `#END` */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        {
            uint8 intEn = EA;
            CyGlobalIntEnable;  /* Enable nested interrupts. */
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */

        COM_ClearSieEpInterruptSource(COM_SIE_INT_EP8_INTR);
        
        /* Notifies user that transfer IN or OUT transfer is completed.
        * IN endpoint: endpoint buffer can be reloaded, Host is read data.
        * OUT endpoint: data is ready to read from endpoint buffer. 
        */
    #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
        if (0u != (COM_EP[COM_EP8].addr & COM_DIR_IN))
    #endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */
        {
            /* Read CR0 register to clear SIE lock. */
            (void) COM_SIE_EP_BASE.sieEp[COM_EP8].epCr0;

            /* Toggle all endpoint types except ISOC. */
            if (COM_GET_EP_TYPE(COM_EP8) != COM_EP_TYPE_ISOC)
            {
                COM_EP[COM_EP8].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
            }

            /* EP_MANAGEMENT_DMA_AUTO (Ticket ID# 214187): For OUT endpoint this event is used to notify
            * user that DMA has completed copying data from OUT endpoint which is not completely true.
            * Because last chunk of data is being copied.
            * For CY_PSOC 3/5LP: it is acceptable as DMA is really fast.
            * For CY_PSOC4: this event is set in Arbiter interrupt (source is DMA_TERMIN).
            */
            COM_EP[COM_EP8].apiEpState = COM_EVENT_PENDING;
        }

    #if (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO))
        #if (defined(COM_ENABLE_MIDI_STREAMING) && \
            !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
            if (COM_midi_out_ep == COM_EP8)
            {
                COM_MIDI_OUT_Service();
            }
        #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
    #endif /* (!(CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)) */

        /* `#START EP8_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_EP_8_ISR_EXIT_CALLBACK
        COM_EP_8_ISR_ExitCallback();
    #endif /* (COM_EP_8_ISR_EXIT_CALLBACK) */

    #if (CY_PSOC3 && defined(COM_ENABLE_MIDI_STREAMING) && \
        !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
        
            EA = intEn; /* Restore nested interrupt configuration. */
        }
    #endif /* (CY_PSOC3 && COM_ISR_SERVICE_MIDI_OUT) */
    }
#endif /* (COM_EP8_ISR_ACTIVE) */


#if (COM_SOF_ISR_ACTIVE)
    /*******************************************************************************
    * Function Name: COM_SOF_ISR
    ****************************************************************************//**
    *
    *  Start of Frame Interrupt Service Routine.
    *
    *
    *******************************************************************************/
    CY_ISR(COM_SOF_ISR)
    {
    #ifdef COM_SOF_ISR_ENTRY_CALLBACK
        COM_SOF_ISR_EntryCallback();
    #endif /* (COM_SOF_ISR_ENTRY_CALLBACK) */

        /* `#START SOF_USER_CODE` Place your code here */

        /* `#END` */

        COM_ClearSieInterruptSource(COM_INTR_SIE_SOF_INTR);

    #ifdef COM_SOF_ISR_EXIT_CALLBACK
        COM_SOF_ISR_ExitCallback();
    #endif /* (COM_SOF_ISR_EXIT_CALLBACK) */
    }
#endif /* (COM_SOF_ISR_ACTIVE) */


#if (COM_BUS_RESET_ISR_ACTIVE)
/*******************************************************************************
* Function Name: COM_BUS_RESET_ISR
****************************************************************************//**
*
*  USB Bus Reset Interrupt Service Routine.  Calls _Start with the same
*  parameters as the last USER call to _Start
*
*
*******************************************************************************/
CY_ISR(COM_BUS_RESET_ISR)
{
#ifdef COM_BUS_RESET_ISR_ENTRY_CALLBACK
    COM_BUS_RESET_ISR_EntryCallback();
#endif /* (COM_BUS_RESET_ISR_ENTRY_CALLBACK) */

    /* `#START BUS_RESET_USER_CODE` Place your code here */

    /* `#END` */

    COM_ClearSieInterruptSource(COM_INTR_SIE_BUS_RESET_INTR);

    COM_ReInitComponent();

#ifdef COM_BUS_RESET_ISR_EXIT_CALLBACK
    COM_BUS_RESET_ISR_ExitCallback();
#endif /* (COM_BUS_RESET_ISR_EXIT_CALLBACK) */
}
#endif /* (COM_BUS_RESET_ISR_ACTIVE) */


#if (COM_LPM_ACTIVE)
/***************************************************************************
* Function Name: COM_INTR_LPM_ISR
************************************************************************//**
*
*   Interrupt Service Routine for LPM of the interrupt sources.
*
*
***************************************************************************/
CY_ISR(COM_LPM_ISR)
{
#ifdef COM_LPM_ISR_ENTRY_CALLBACK
    COM_LPM_ISR_EntryCallback();
#endif /* (COM_LPM_ISR_ENTRY_CALLBACK) */

    /* `#START LPM_BEGIN_USER_CODE` Place your code here */

    /* `#END` */

    COM_ClearSieInterruptSource(COM_INTR_SIE_LPM_INTR);

    /* `#START LPM_END_USER_CODE` Place your code here */

    /* `#END` */

#ifdef COM_LPM_ISR_EXIT_CALLBACK
    COM_LPM_ISR_ExitCallback();
#endif /* (COM_LPM_ISR_EXIT_CALLBACK) */
}
#endif /* (COM_LPM_ACTIVE) */


#if (COM_EP_MANAGEMENT_DMA && COM_ARB_ISR_ACTIVE)
    /***************************************************************************
    * Function Name: COM_ARB_ISR
    ************************************************************************//**
    *
    *  Arbiter Interrupt Service Routine.
    *
    *
    ***************************************************************************/
    CY_ISR(COM_ARB_ISR)
    {
        uint8 arbIntrStatus;
        uint8 epStatus;
        uint8 ep = COM_EP1;

    #ifdef COM_ARB_ISR_ENTRY_CALLBACK
        COM_ARB_ISR_EntryCallback();
    #endif /* (COM_ARB_ISR_ENTRY_CALLBACK) */

        /* `#START ARB_BEGIN_USER_CODE` Place your code here */

        /* `#END` */

        /* Get pending ARB interrupt sources. */
        arbIntrStatus = COM_ARB_INT_SR_REG;

        while (0u != arbIntrStatus)
        {
            /* Check which EP is interrupt source. */
            if (0u != (arbIntrStatus & 0x01u))
            {
                /* Get endpoint enable interrupt sources. */
                epStatus = (COM_ARB_EP_BASE.arbEp[ep].epSr & COM_ARB_EP_BASE.arbEp[ep].epIntEn);

                /* Handle IN endpoint buffer full event: happens only once when endpoint buffer is loaded. */
                if (0u != (epStatus & COM_ARB_EPX_INT_IN_BUF_FULL))
                {
                    if (0u != (COM_EP[ep].addr & COM_DIR_IN))
                    {
                        /* Clear data ready status. */
                        COM_ARB_EP_BASE.arbEp[ep].epCfg &= (uint8) ~COM_ARB_EPX_CFG_IN_DATA_RDY;

                    #if (CY_PSOC3 || CY_PSOC5LP)
                        #if (COM_EP_MANAGEMENT_DMA_AUTO && (COM_EP_DMA_AUTO_OPT == 0u))
                            /* Set up common area DMA with rest of data. */
                            if(COM_inLength[ep] > COM_DMA_BYTES_PER_BURST)
                            {
                                COM_LoadNextInEP(ep, 0u);
                            }
                            else
                            {
                                COM_inBufFull[ep] = 1u;
                            }
                        #endif /* (COM_EP_MANAGEMENT_DMA_AUTO && (COM_EP_DMA_AUTO_OPT == 0u)) */
                    #endif /* (CY_PSOC3 || CY_PSOC5LP) */

                        /* Arm IN endpoint. */
                        COM_SIE_EP_BASE.sieEp[ep].epCr0 = COM_EP[ep].epMode;

                    #if (defined(COM_ENABLE_MIDI_STREAMING) && COM_ISR_SERVICE_MIDI_IN)
                        if (ep == COM_midi_in_ep)
                        {
                            /* Clear MIDI input pointer. */
                            COM_midiInPointer = 0u;
                        }
                    #endif /* (COM_ENABLE_MIDI_STREAMING) */
                    }
                }

            #if (COM_EP_MANAGEMENT_DMA_MANUAL)
                /* Handle DMA completion event for OUT endpoints. */
                if (0u != (epStatus & COM_ARB_EPX_SR_DMA_GNT))
                {
                    if (0u == (COM_EP[ep].addr & COM_DIR_IN))
                    {
                        /* Notify user that data has been copied from endpoint buffer. */
                        COM_EP[ep].apiEpState = COM_NO_EVENT_PENDING;

                        /* DMA done coping data: OUT endpoint has to be re-armed by user. */
                    }
                }
            #endif /* (COM_EP_MANAGEMENT_DMA_MANUAL) */

            #if (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO)
                /* Handle DMA completion event for OUT endpoints. */
                if (0u != (epStatus & COM_ARB_EPX_INT_DMA_TERMIN))
                {
                    uint32 channelNum = COM_DmaChan[ep];

                    /* Restore burst counter for endpoint. */
                    COM_DmaEpBurstCnt[ep] = COM_DmaEpBurstCntBackup[ep];

                    /* Disable DMA channel to restore descriptor configuration. The on-going transfer is aborted. */
                    COM_CyDmaChDisable(channelNum);

                    /* Generate DMA tr_out signal to notify USB IP that DMA is done. This signal is not generated
                    * when transfer was aborted (it occurs when host writes less bytes than buffer size).
                    */
                    COM_CyDmaTriggerOut(COM_DmaBurstEndOut[ep]);

                    /* Restore destination address for output endpoint. */
                    COM_CyDmaSetDstAddress(channelNum, COM_DMA_DESCR0, (void*) ((uint32) COM_DmaEpBufferAddrBackup[ep]));
                    COM_CyDmaSetDstAddress(channelNum, COM_DMA_DESCR1, (void*) ((uint32) COM_DmaEpBufferAddrBackup[ep] +
                                                                                                                   COM_DMA_BYTES_PER_BURST));

                    /* Restore number of data elements to transfer which was adjusted for last burst. */
                    if (0u != (COM_DmaEpLastBurstEl[ep] & COM_DMA_DESCR_REVERT))
                    {
                        COM_CyDmaSetNumDataElements(channelNum, (COM_DmaEpLastBurstEl[ep] >> COM_DMA_DESCR_SHIFT),
                                                                             COM_DMA_GET_MAX_ELEM_PER_BURST(COM_DmaEpLastBurstEl[ep]));
                    }

                    /* Validate descriptor 0 and 1 (also reset current state). Command to start with descriptor 0. */
                    COM_CyDmaValidateDescriptor(channelNum, COM_DMA_DESCR0);
                    COM_CyDmaValidateDescriptor(channelNum, COM_DMA_DESCR1);
                    COM_CyDmaSetDescriptor0Next(channelNum);

                    /* Enable DMA channel: configuration complete. */
                    COM_CyDmaChEnable(channelNum);
                    
                    
                    /* Read CR0 register to clear SIE lock. */
                    (void) COM_SIE_EP_BASE.sieEp[ep].epCr0;
                    
                    /* Toggle all endpoint types except ISOC. */
                    if (COM_GET_EP_TYPE(ep) != COM_EP_TYPE_ISOC)
                    {
                        COM_EP[ep].epToggle ^= COM_EPX_CNT_DATA_TOGGLE;
                    }
            
                    /* Notify user that data has been copied from endpoint buffer. */
                    COM_EP[ep].apiEpState = COM_EVENT_PENDING;
                    
                #if (defined(COM_ENABLE_MIDI_STREAMING) && \
                    !defined(COM_MAIN_SERVICE_MIDI_OUT) && COM_ISR_SERVICE_MIDI_OUT)
                    if (COM_midi_out_ep == ep)
                    {
                        COM_MIDI_OUT_Service();
                    }
                #endif /* (COM_ISR_SERVICE_MIDI_OUT) */
                }
            #endif /* (CY_PSOC4 && COM_EP_MANAGEMENT_DMA_AUTO) */


                /* `#START ARB_USER_CODE` Place your code here for handle Buffer Underflow/Overflow */

                /* `#END` */

            #ifdef COM_ARB_ISR_CALLBACK
                COM_ARB_ISR_Callback(ep, epStatus);
            #endif /* (COM_ARB_ISR_CALLBACK) */

                /* Clear serviced endpoint interrupt sources. */
                COM_ARB_EP_BASE.arbEp[ep].epSr = epStatus;
            }

            ++ep;
            arbIntrStatus >>= 1u;
        }

        /* `#START ARB_END_USER_CODE` Place your code here */

        /* `#END` */

    #ifdef COM_ARB_ISR_EXIT_CALLBACK
        COM_ARB_ISR_ExitCallback();
    #endif /* (COM_ARB_ISR_EXIT_CALLBACK) */
    }

#endif /*  (COM_ARB_ISR_ACTIVE && COM_EP_MANAGEMENT_DMA) */


#if (COM_EP_MANAGEMENT_DMA_AUTO)
#if (CY_PSOC4)
    #if (COM_DMA1_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP1_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 1 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP1_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP1])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP1];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP1_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP1] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP1] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP1].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP1_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP1_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP1_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP1_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP1_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP1_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP1_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP1_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP1]);
        }
    #endif /* (COM_DMA1_ACTIVE) */


    #if (COM_DMA2_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP2_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 2 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP2_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP2])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP2];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP2_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP2] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP2] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP2].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP2_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP2_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP2_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP2_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP2_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP2_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP2_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP2_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP2]);
        }
    #endif /* (COM_DMA2_ACTIVE) */


    #if (COM_DMA3_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP3_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 3 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP3_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP3])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP3];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP3_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP3] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP3] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP3].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP3_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP3_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP3_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP3_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP3_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP3_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP3_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP3_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP3]);
        }
    #endif /* (COM_DMA3_ACTIVE) */


    #if (COM_DMA4_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP4_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 4 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP4_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP4])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP4];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP4_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP4] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP4] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP4].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP4_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP4_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP4_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP4_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP4_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP4_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP4_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP4_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP4]);
        }
    #endif /* (COM_DMA4_ACTIVE) */


    #if (COM_DMA5_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP5_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 5 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP5_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP5])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP5];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP5_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP5] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP5] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP5].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP5_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP5_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP5_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP5_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP5_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP5_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP5_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP5_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP5]);
        }
    #endif /* (COM_DMA5_ACTIVE) */


    #if (COM_DMA6_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP6_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 6 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP6_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP6])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP6];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP6_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP6] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP6] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP6].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP6_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP6_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP6_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP6_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP6_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP6_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable the DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP6_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP6_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP6]);
        }
    #endif /* (COM_DMA6_ACTIVE) */


    #if (COM_DMA7_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP7_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 7 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP7_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP7])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP7];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP7_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP7] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP7] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP7].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP7_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP7_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP7_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP7_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP7_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP7_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP7_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP7_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP7]);
        }
    #endif /* (COM_DMA7_ACTIVE) */


    #if (COM_DMA8_ACTIVE)
        /******************************************************************************
        * Function Name: COM_EP8_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  Endpoint 8 DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        void COM_EP8_DMA_DONE_ISR(void)
        {
            uint32 nextAddr;

            /* Manage data elements which remain to transfer. */
            if (0u != COM_DmaEpBurstCnt[COM_EP8])
            {
                /* Decrement burst counter. */
                --COM_DmaEpBurstCnt[COM_EP8];
            }
            else
            {
                /* Adjust length of last burst. */
                COM_CyDmaSetNumDataElements(COM_EP8_DMA_CH,
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP8] >> COM_DMA_DESCR_SHIFT),
                                                        ((uint32) COM_DmaEpLastBurstEl[COM_EP8] &  COM_DMA_BURST_BYTES_MASK));
            }

            /* Advance source for input endpoint or destination for output endpoint. */
            if (0u != (COM_EP[COM_EP8].addr & COM_DIR_IN))
            {
                /* Change source for descriptor 0. */
                nextAddr = (uint32) COM_CyDmaGetSrcAddress(COM_EP8_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetSrcAddress(COM_EP8_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change source for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetSrcAddress(COM_EP8_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }
            else
            {
                /* Change destination for descriptor 0. */
                nextAddr  = (uint32) COM_CyDmaGetDstAddress(COM_EP8_DMA_CH, COM_DMA_DESCR0);
                nextAddr += (2u * COM_DMA_BYTES_PER_BURST);
                COM_CyDmaSetDstAddress(COM_EP8_DMA_CH, COM_DMA_DESCR0, (void *) nextAddr);

                /* Change destination for descriptor 1. */
                nextAddr += COM_DMA_BYTES_PER_BURST;
                COM_CyDmaSetDstAddress(COM_EP8_DMA_CH, COM_DMA_DESCR1, (void *) nextAddr);
            }

            /* Enable DMA to execute transfer as it was disabled because there were no valid descriptor. */
            COM_CyDmaValidateDescriptor(COM_EP8_DMA_CH, COM_DMA_DESCR0);
            COM_CyDmaChEnable (COM_EP8_DMA_CH);
            COM_CyDmaTriggerIn(COM_DmaReqOut[COM_EP8]);
        }
    #endif /* (COM_DMA8_ACTIVE) */

#else
    #if (COM_EP_DMA_AUTO_OPT == 0u)
        /******************************************************************************
        * Function Name: COM_EP_DMA_DONE_ISR
        ***************************************************************************//**
        *
        *  DMA Done Interrupt Service Routine.
        *
        *
        ******************************************************************************/
        CY_ISR(COM_EP_DMA_DONE_ISR)
        {
            uint8 int8Status;
            uint8 int17Status;
            uint8 ep_status;
            uint8 ep = COM_EP1;

        #ifdef COM_EP_DMA_DONE_ISR_ENTRY_CALLBACK
            COM_EP_DMA_DONE_ISR_EntryCallback();
        #endif /* (COM_EP_DMA_DONE_ISR_ENTRY_CALLBACK) */

            /* `#START EP_DMA_DONE_BEGIN_USER_CODE` Place your code here */

            /* `#END` */

            /* Read clear on read status register with EP source of interrupt. */
            int17Status = COM_EP17_DMA_Done_SR_Read() & COM_EP17_SR_MASK;
            int8Status  = COM_EP8_DMA_Done_SR_Read()  & COM_EP8_SR_MASK;

            while (int8Status != 0u)
            {
                while (int17Status != 0u)
                {
                    if ((int17Status & 1u) != 0u)  /* If EpX interrupt present. */
                    {
                        /* Read Endpoint Status Register. */
                        ep_status = COM_ARB_EP_BASE.arbEp[ep].epSr;

                        if ((0u == (ep_status & COM_ARB_EPX_SR_IN_BUF_FULL)) &&
                            (0u ==COM_inBufFull[ep]))
                        {
                            /* `#START EP_DMA_DONE_USER_CODE` Place your code here */

                            /* `#END` */

                        #ifdef COM_EP_DMA_DONE_ISR_CALLBACK
                            COM_EP_DMA_DONE_ISR_Callback();
                        #endif /* (COM_EP_DMA_DONE_ISR_CALLBACK) */

                            /* Transfer again 2 last bytes into pre-fetch endpoint area. */
                            COM_ARB_EP_BASE.arbEp[ep].rwWaMsb = 0u;
                            COM_ARB_EP_BASE.arbEp[ep].rwWa = (COM_DMA_BYTES_PER_BURST * ep) - COM_DMA_BYTES_REPEAT;
                            COM_LoadNextInEP(ep, 1u);

                            /* Set Data ready status to generate DMA request. */
                            COM_ARB_EP_BASE.arbEp[ep].epCfg |= COM_ARB_EPX_CFG_IN_DATA_RDY;
                        }
                    }

                    ep++;
                    int17Status >>= 1u;
                }

                int8Status >>= 1u;

                if (int8Status != 0u)
                {
                    /* Prepare pointer for EP8. */
                    ep = COM_EP8;
                    int17Status = int8Status & 0x01u;
                }
            }

            /* `#START EP_DMA_DONE_END_USER_CODE` Place your code here */

            /* `#END` */

    #ifdef COM_EP_DMA_DONE_ISR_EXIT_CALLBACK
        COM_EP_DMA_DONE_ISR_ExitCallback();
    #endif /* (COM_EP_DMA_DONE_ISR_EXIT_CALLBACK) */
        }
    #endif /* (COM_EP_DMA_AUTO_OPT == 0u) */
#endif /* (CY_PSOC4) */
#endif /* (COM_EP_MANAGEMENT_DMA_AUTO) */


#if (CY_PSOC4)
    /***************************************************************************
    * Function Name: COM_IntrHandler
    ************************************************************************//**
    *
    *   Interrupt handler for Hi/Mid/Low ISRs.
    *
    *  regCause - The cause register of interrupt. One of the three variants:
    *       COM_INTR_CAUSE_LO_REG - Low interrupts.
    *       COM_INTR_CAUSE_MED_REG - Med interrupts.
    *       COM_INTR_CAUSE_HI_REG - - High interrupts.
    *
    *
    ***************************************************************************/
    CY_INLINE static void COM_IntrHandler(uint32 intrCause)
    {
        /* Array of pointers to component interrupt handlers. */
        static const cyisraddress COM_isrCallbacks[] =
        {

        };

        uint32 cbIdx = 0u;

        /* Check arbiter interrupt source first. */
        if (0u != (intrCause & COM_INTR_CAUSE_ARB_INTR))
        {
            COM_isrCallbacks[COM_ARB_EP_INTR_NUM]();
        }

        /* Check all other interrupt sources (except arbiter and resume). */
        intrCause = (intrCause  & COM_INTR_CAUSE_CTRL_INTR_MASK) |
                    ((intrCause & COM_INTR_CAUSE_EP1_8_INTR_MASK) >>
                                  COM_INTR_CAUSE_EP_INTR_SHIFT);

        /* Call interrupt handlers for active interrupt sources. */
        while (0u != intrCause)
        {
            if (0u != (intrCause & 0x1u))
            {
                 COM_isrCallbacks[cbIdx]();
            }

            intrCause >>= 1u;
            ++cbIdx;
        }
    }


    /***************************************************************************
    * Function Name: COM_INTR_HI_ISR
    ************************************************************************//**
    *
    *   Interrupt Service Routine for the high group of the interrupt sources.
    *
    *
    ***************************************************************************/
    CY_ISR(COM_INTR_HI_ISR)
    {
        COM_IntrHandler(COM_INTR_CAUSE_HI_REG);
    }

    /***************************************************************************
    * Function Name: COM_INTR_MED_ISR
    ************************************************************************//**
    *
    *   Interrupt Service Routine for the medium group of the interrupt sources.
    *
    *
    ***************************************************************************/
    CY_ISR(COM_INTR_MED_ISR)
    {
       COM_IntrHandler(COM_INTR_CAUSE_MED_REG);
    }

    /***************************************************************************
    * Function Name: COM_INTR_LO_ISR
    ************************************************************************//**
    *
    *   Interrupt Service Routine for the low group of the interrupt sources.
    *
    *
    ***************************************************************************/
    CY_ISR(COM_INTR_LO_ISR)
    {
        COM_IntrHandler(COM_INTR_CAUSE_LO_REG);
    }
#endif /* (CY_PSOC4) */


/* [] END OF FILE */
