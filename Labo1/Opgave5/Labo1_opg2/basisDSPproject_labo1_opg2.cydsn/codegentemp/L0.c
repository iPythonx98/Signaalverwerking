/*******************************************************************************
* File Name: L0.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "L0.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 L0__PORT == 15 && ((L0__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: L0_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None
*  
*******************************************************************************/
void L0_Write(uint8 value) 
{
    uint8 staticBits = (L0_DR & (uint8)(~L0_MASK));
    L0_DR = staticBits | ((uint8)(value << L0_SHIFT) & L0_MASK);
}


/*******************************************************************************
* Function Name: L0_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  L0_DM_STRONG     Strong Drive 
*  L0_DM_OD_HI      Open Drain, Drives High 
*  L0_DM_OD_LO      Open Drain, Drives Low 
*  L0_DM_RES_UP     Resistive Pull Up 
*  L0_DM_RES_DWN    Resistive Pull Down 
*  L0_DM_RES_UPDWN  Resistive Pull Up/Down 
*  L0_DM_DIG_HIZ    High Impedance Digital 
*  L0_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void L0_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(L0_0, mode);
}


/*******************************************************************************
* Function Name: L0_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro L0_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 L0_Read(void) 
{
    return (L0_PS & L0_MASK) >> L0_SHIFT;
}


/*******************************************************************************
* Function Name: L0_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 L0_ReadDataReg(void) 
{
    return (L0_DR & L0_MASK) >> L0_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(L0_INTSTAT) 

    /*******************************************************************************
    * Function Name: L0_ClearInterrupt
    ********************************************************************************
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 L0_ClearInterrupt(void) 
    {
        return (L0_INTSTAT & L0_MASK) >> L0_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
