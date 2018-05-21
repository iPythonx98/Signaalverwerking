/*******************************************************************************
* File Name: AnalogeIngang_R_PM.c
* Version 1.90
*
* Description:
*  This file provides the power management source code to the API for the 
*  OpAmp (Analog Buffer) component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "AnalogeIngang_R.h"

static AnalogeIngang_R_BACKUP_STRUCT  AnalogeIngang_R_backup;


/*******************************************************************************  
* Function Name: AnalogeIngang_R_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the current user configuration registers.
* 
* Parameters:
*  void
* 
* Return:
*  void
*
*******************************************************************************/
void AnalogeIngang_R_SaveConfig(void) 
{
    /* Nothing to save as registers are System reset on retention flops */
}


/*******************************************************************************  
* Function Name: AnalogeIngang_R_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration registers.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AnalogeIngang_R_RestoreConfig(void) 
{
    /* Nothing to restore */
}


/*******************************************************************************   
* Function Name: AnalogeIngang_R_Sleep
********************************************************************************
*
* Summary:
*  Disables block's operation and saves its configuration. Should be called 
*  just prior to entering sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  AnalogeIngang_R_backup: The structure field 'enableState' is modified 
*  depending on the enable state of the block before entering to sleep mode.
*
*******************************************************************************/
void AnalogeIngang_R_Sleep(void) 
{
    /* Save OpAmp enable state */
    if((AnalogeIngang_R_PM_ACT_CFG_REG & AnalogeIngang_R_ACT_PWR_EN) != 0u)
    {
        /* Component is enabled */
        AnalogeIngang_R_backup.enableState = 1u;
         /* Stops the component */
         AnalogeIngang_R_Stop();
    }
    else
    {
        /* Component is disabled */
        AnalogeIngang_R_backup.enableState = 0u;
    }
    /* Saves the configuration */
    AnalogeIngang_R_SaveConfig();
}


/*******************************************************************************  
* Function Name: AnalogeIngang_R_Wakeup
********************************************************************************
*
* Summary:
*  Enables block's operation and restores its configuration. Should be called
*  just after awaking from sleep.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  AnalogeIngang_R_backup: The structure field 'enableState' is used to 
*  restore the enable state of block after wakeup from sleep mode.
*
*******************************************************************************/
void AnalogeIngang_R_Wakeup(void) 
{
    /* Restore the user configuration */
    AnalogeIngang_R_RestoreConfig();

    /* Enables the component operation */
    if(AnalogeIngang_R_backup.enableState == 1u)
    {
        AnalogeIngang_R_Enable();
    } /* Do nothing if component was disable before */
}


/* [] END OF FILE */
