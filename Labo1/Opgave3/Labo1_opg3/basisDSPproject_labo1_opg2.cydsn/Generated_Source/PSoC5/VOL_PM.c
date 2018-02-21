/*******************************************************************************
* File Name: VOL_PM.c
* Version 3.10
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

#include "VOL.h"


/***************************************
* Local data allocation
***************************************/

static VOL_BACKUP_STRUCT  VOL_backup =
{
    VOL_DISABLED
};


/*******************************************************************************
* Function Name: VOL_SaveConfig
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
void VOL_SaveConfig(void)
{
    /* All configuration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: VOL_RestoreConfig
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
void VOL_RestoreConfig(void)
{
    /* All congiguration registers are marked as [reset_all_retention] */
}


/*******************************************************************************
* Function Name: VOL_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred routine to prepare the component for sleep.
*  The VOL_Sleep() routine saves the current component state,
*  then it calls the ADC_Stop() function.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  VOL_backup - The structure field 'enableState' is modified
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void VOL_Sleep(void)
{
    if((VOL_PWRMGR_SAR_REG  & VOL_ACT_PWR_SAR_EN) != 0u)
    {
        if((VOL_SAR_CSR0_REG & VOL_SAR_SOF_START_CONV) != 0u)
        {
            VOL_backup.enableState = VOL_ENABLED | VOL_STARTED;
        }
        else
        {
            VOL_backup.enableState = VOL_ENABLED;
        }
        VOL_Stop();
    }
    else
    {
        VOL_backup.enableState = VOL_DISABLED;
    }
}


/*******************************************************************************
* Function Name: VOL_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred routine to restore the component to the state when
*  VOL_Sleep() was called. If the component was enabled before the
*  VOL_Sleep() function was called, the
*  VOL_Wakeup() function also re-enables the component.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  VOL_backup - The structure field 'enableState' is used to
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void VOL_Wakeup(void)
{
    if(VOL_backup.enableState != VOL_DISABLED)
    {
        VOL_Enable();
        #if(VOL_DEFAULT_CONV_MODE != VOL__HARDWARE_TRIGGER)
            if((VOL_backup.enableState & VOL_STARTED) != 0u)
            {
                VOL_StartConvert();
            }
        #endif /* End VOL_DEFAULT_CONV_MODE != VOL__HARDWARE_TRIGGER */
    }
}


/* [] END OF FILE */
