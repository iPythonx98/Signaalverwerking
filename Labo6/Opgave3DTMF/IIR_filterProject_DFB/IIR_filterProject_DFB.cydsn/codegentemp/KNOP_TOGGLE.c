/*******************************************************************************
* File Name: KNOP_TOGGLE.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "KNOP_TOGGLE.h"

#if !defined(KNOP_TOGGLE_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: KNOP_TOGGLE_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 KNOP_TOGGLE_Read(void) 
{ 
    return KNOP_TOGGLE_Status;
}


/*******************************************************************************
* Function Name: KNOP_TOGGLE_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void KNOP_TOGGLE_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    KNOP_TOGGLE_Status_Aux_Ctrl |= KNOP_TOGGLE_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: KNOP_TOGGLE_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void KNOP_TOGGLE_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    KNOP_TOGGLE_Status_Aux_Ctrl &= (uint8)(~KNOP_TOGGLE_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: KNOP_TOGGLE_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void KNOP_TOGGLE_WriteMask(uint8 mask) 
{
    #if(KNOP_TOGGLE_INPUTS < 8u)
    	mask &= ((uint8)(1u << KNOP_TOGGLE_INPUTS) - 1u);
	#endif /* End KNOP_TOGGLE_INPUTS < 8u */
    KNOP_TOGGLE_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: KNOP_TOGGLE_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 KNOP_TOGGLE_ReadMask(void) 
{
    return KNOP_TOGGLE_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
