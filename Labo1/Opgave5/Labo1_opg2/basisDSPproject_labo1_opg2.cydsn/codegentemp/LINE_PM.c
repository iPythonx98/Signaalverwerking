/*******************************************************************************
* File Name: LINE_PM.c
* Version 3.0
*
* Description:
*  This file provides Sleep/WakeUp APIs functionality.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "LINE.h"


/***************************************
* Local data allocation
***************************************/

static LINE_BACKUP_STRUCT  LINE_backup =
{
    LINE_DISABLED
};


/*******************************************************************************
* Function Name: LINE_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LINE_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: LINE_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void LINE_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: LINE_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The LINE_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  LINE_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void LINE_Sleep(void)
{
    if((LINE_PWRMGR_SAR_REG  & LINE_ACT_PWR_SAR_EN) != 0u)
    {
        if((LINE_SAR_CSR0_REG & LINE_SAR_SOF_START_CONV) != 0u)
        {
            LINE_backup.enableState = LINE_ENABLED | LINE_STARTED;
        }
        else
        {
            LINE_backup.enableState = LINE_ENABLED;
        }
        LINE_Stop();
    }
    else
    {
        LINE_backup.enableState = LINE_DISABLED;
    }
}


/*******************************************************************************
* Function Name: LINE_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  LINE_Sleep() was called. If the component was enabled before the
*  LINE_Sleep() function was called, the
*  LINE_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  LINE_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void LINE_Wakeup(void)
{
    if(LINE_backup.enableState != LINE_DISABLED)
    {
        LINE_Enable();
        #if(LINE_DEFAULT_CONV_MODE != LINE__HARDWARE_TRIGGER)
            if((LINE_backup.enableState & LINE_STARTED) != 0u)
            {
                LINE_StartConvert();
            }
        #endif /* End LINE_DEFAULT_CONV_MODE != LINE__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
