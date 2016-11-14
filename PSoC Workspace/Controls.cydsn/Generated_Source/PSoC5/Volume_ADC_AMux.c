/*******************************************************************************
* File Name: Volume_ADC_AMux.c
* Version 1.80
*
*  Description:
*    This file contains all functions required for the analog multiplexer
*    AMux User Module.
*
*   Note:
*
*******************************************************************************
* Copyright 2008-2010, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#include "Volume_ADC_AMux.h"

static uint8 Volume_ADC_AMux_lastChannel = Volume_ADC_AMux_NULL_CHANNEL;


/*******************************************************************************
* Function Name: Volume_ADC_AMux_Start
********************************************************************************
* Summary:
*  Disconnect all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Volume_ADC_AMux_Start(void) 
{
    uint8 chan;

    for(chan = 0u; chan < Volume_ADC_AMux_CHANNELS ; chan++)
    {
#if (Volume_ADC_AMux_MUXTYPE == Volume_ADC_AMux_MUX_SINGLE)
        Volume_ADC_AMux_Unset(chan);
#else
        Volume_ADC_AMux_CYAMUXSIDE_A_Unset(chan);
        Volume_ADC_AMux_CYAMUXSIDE_B_Unset(chan);
#endif
    }

    Volume_ADC_AMux_lastChannel = Volume_ADC_AMux_NULL_CHANNEL;
}


#if (!Volume_ADC_AMux_ATMOSTONE)
/*******************************************************************************
* Function Name: Volume_ADC_AMux_Select
********************************************************************************
* Summary:
*  This functions first disconnects all channels then connects the given
*  channel.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Volume_ADC_AMux_Select(uint8 channel) 
{
    Volume_ADC_AMux_DisconnectAll();        /* Disconnect all previous connections */
    Volume_ADC_AMux_Connect(channel);       /* Make the given selection */
    Volume_ADC_AMux_lastChannel = channel;  /* Update last channel */
}
#endif


/*******************************************************************************
* Function Name: Volume_ADC_AMux_FastSelect
********************************************************************************
* Summary:
*  This function first disconnects the last connection made with FastSelect or
*  Select, then connects the given channel. The FastSelect function is similar
*  to the Select function, except it is faster since it only disconnects the
*  last channel selected rather than all channels.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Volume_ADC_AMux_FastSelect(uint8 channel) 
{
    /* Disconnect the last valid channel */
    if( Volume_ADC_AMux_lastChannel != Volume_ADC_AMux_NULL_CHANNEL)
    {
        Volume_ADC_AMux_Disconnect(Volume_ADC_AMux_lastChannel);
    }

    /* Make the new channel connection */
#if (Volume_ADC_AMux_MUXTYPE == Volume_ADC_AMux_MUX_SINGLE)
    Volume_ADC_AMux_Set(channel);
#else
    Volume_ADC_AMux_CYAMUXSIDE_A_Set(channel);
    Volume_ADC_AMux_CYAMUXSIDE_B_Set(channel);
#endif


    Volume_ADC_AMux_lastChannel = channel;   /* Update last channel */
}


#if (Volume_ADC_AMux_MUXTYPE == Volume_ADC_AMux_MUX_DIFF)
#if (!Volume_ADC_AMux_ATMOSTONE)
/*******************************************************************************
* Function Name: Volume_ADC_AMux_Connect
********************************************************************************
* Summary:
*  This function connects the given channel without affecting other connections.
*
* Parameters:
*  channel:  The channel to connect to the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Volume_ADC_AMux_Connect(uint8 channel) 
{
    Volume_ADC_AMux_CYAMUXSIDE_A_Set(channel);
    Volume_ADC_AMux_CYAMUXSIDE_B_Set(channel);
}
#endif

/*******************************************************************************
* Function Name: Volume_ADC_AMux_Disconnect
********************************************************************************
* Summary:
*  This function disconnects the given channel from the common or output
*  terminal without affecting other connections.
*
* Parameters:
*  channel:  The channel to disconnect from the common terminal.
*
* Return:
*  void
*
*******************************************************************************/
void Volume_ADC_AMux_Disconnect(uint8 channel) 
{
    Volume_ADC_AMux_CYAMUXSIDE_A_Unset(channel);
    Volume_ADC_AMux_CYAMUXSIDE_B_Unset(channel);
}
#endif

#if (Volume_ADC_AMux_ATMOSTONE)
/*******************************************************************************
* Function Name: Volume_ADC_AMux_DisconnectAll
********************************************************************************
* Summary:
*  This function disconnects all channels.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void Volume_ADC_AMux_DisconnectAll(void) 
{
    if(Volume_ADC_AMux_lastChannel != Volume_ADC_AMux_NULL_CHANNEL) 
    {
        Volume_ADC_AMux_Disconnect(Volume_ADC_AMux_lastChannel);
        Volume_ADC_AMux_lastChannel = Volume_ADC_AMux_NULL_CHANNEL;
    }
}
#endif

/* [] END OF FILE */
