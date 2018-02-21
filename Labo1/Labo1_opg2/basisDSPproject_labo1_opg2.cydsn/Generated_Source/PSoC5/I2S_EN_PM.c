/*******************************************************************************
* File Name: I2S_EN_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "I2S_EN.h"

/* Check for removal by optimization */
#if !defined(I2S_EN_Sync_ctrl_reg__REMOVED)

static I2S_EN_BACKUP_STRUCT  I2S_EN_backup = {0u};

    
/*******************************************************************************
* Function Name: I2S_EN_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2S_EN_SaveConfig(void) 
{
    I2S_EN_backup.controlState = I2S_EN_Control;
}


/*******************************************************************************
* Function Name: I2S_EN_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void I2S_EN_RestoreConfig(void) 
{
     I2S_EN_Control = I2S_EN_backup.controlState;
}


/*******************************************************************************
* Function Name: I2S_EN_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2S_EN_Sleep(void) 
{
    I2S_EN_SaveConfig();
}


/*******************************************************************************
* Function Name: I2S_EN_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2S_EN_Wakeup(void)  
{
    I2S_EN_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
