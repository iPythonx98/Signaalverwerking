/*******************************************************************************
* File Name: I2S_watchdog_PM.c
* Version 1.0
*
* Description:
*  This file provides Low power mode APIs for Count7 component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2S_watchdog.h"


I2S_watchdog_BACKUP_STRUCT I2S_watchdog_backup;


/*******************************************************************************
* Function Name: I2S_watchdog_SaveConfig
********************************************************************************
*
* Summary:
*  This function saves the component configuration and non-retention registers.
*  This function is called by the Count7_Sleep() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  I2S_watchdog_backup - used to save component configuration and non-
*  retention registers before enter sleep mode.
*
*******************************************************************************/
void I2S_watchdog_SaveConfig(void) 
{
    I2S_watchdog_backup.count = I2S_watchdog_COUNT_REG;
}


/*******************************************************************************
* Function Name: I2S_watchdog_Sleep
********************************************************************************
*
* Summary:
*  This is the preferred API to prepare the component for low power mode
*  operation. The Count7_Sleep() API saves the current component state using
*  Count7_SaveConfig() and disables the counter.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2S_watchdog_Sleep(void) 
{
    if(0u != (I2S_watchdog_AUX_CONTROL_REG & I2S_watchdog_COUNTER_START))
    {
        I2S_watchdog_backup.enableState = 1u;
        I2S_watchdog_Stop();
    }
    else
    {
        I2S_watchdog_backup.enableState = 0u;
    }

    I2S_watchdog_SaveConfig();
}


/*******************************************************************************
* Function Name: I2S_watchdog_RestoreConfig
********************************************************************************
*
* Summary:
*  This function restores the component configuration and non-retention
*  registers. This function is called by the Count7_Wakeup() function.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global Variables:
*  I2S_watchdog_backup - used to save component configuration and
*  non-retention registers before exit sleep mode.
*
*******************************************************************************/
void I2S_watchdog_RestoreConfig(void) 
{
    I2S_watchdog_COUNT_REG = I2S_watchdog_backup.count;
}


/*******************************************************************************
* Function Name: I2S_watchdog_Wakeup
********************************************************************************
*
* Summary:
*  This is the preferred API to restore the component to the state when
*  Count7_Sleep() was called. The Count7_Wakeup() function calls the
*  Count7_RestoreConfig() function to restore the configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2S_watchdog_Wakeup(void) 
{
    I2S_watchdog_RestoreConfig();

    /* Restore enable state */
    if (I2S_watchdog_backup.enableState != 0u)
    {
        I2S_watchdog_Enable();
    }
}


/* [] END OF FILE */
