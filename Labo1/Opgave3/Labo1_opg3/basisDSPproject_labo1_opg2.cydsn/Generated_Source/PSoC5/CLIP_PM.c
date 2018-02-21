/*******************************************************************************
* File Name: CLIP_PM.c
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

#include "CLIP.h"

/* Check for removal by optimization */
#if !defined(CLIP_Sync_ctrl_reg__REMOVED)

static CLIP_BACKUP_STRUCT  CLIP_backup = {0u};

    
/*******************************************************************************
* Function Name: CLIP_SaveConfig
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
void CLIP_SaveConfig(void) 
{
    CLIP_backup.controlState = CLIP_Control;
}


/*******************************************************************************
* Function Name: CLIP_RestoreConfig
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
void CLIP_RestoreConfig(void) 
{
     CLIP_Control = CLIP_backup.controlState;
}


/*******************************************************************************
* Function Name: CLIP_Sleep
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
void CLIP_Sleep(void) 
{
    CLIP_SaveConfig();
}


/*******************************************************************************
* Function Name: CLIP_Wakeup
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
void CLIP_Wakeup(void)  
{
    CLIP_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
