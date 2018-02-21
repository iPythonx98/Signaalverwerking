/*******************************************************************************
* File Name: L2.c  
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
#include "L2.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 L2__PORT == 15 && ((L2__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: L2_Write
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
void L2_Write(uint8 value) 
{
    uint8 staticBits = (L2_DR & (uint8)(~L2_MASK));
    L2_DR = staticBits | ((uint8)(value << L2_SHIFT) & L2_MASK);
}


/*******************************************************************************
* Function Name: L2_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  L2_DM_STRONG     Strong Drive 
*  L2_DM_OD_HI      Open Drain, Drives High 
*  L2_DM_OD_LO      Open Drain, Drives Low 
*  L2_DM_RES_UP     Resistive Pull Up 
*  L2_DM_RES_DWN    Resistive Pull Down 
*  L2_DM_RES_UPDWN  Resistive Pull Up/Down 
*  L2_DM_DIG_HIZ    High Impedance Digital 
*  L2_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void L2_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(L2_0, mode);
}


/*******************************************************************************
* Function Name: L2_Read
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
*  Macro L2_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 L2_Read(void) 
{
    return (L2_PS & L2_MASK) >> L2_SHIFT;
}


/*******************************************************************************
* Function Name: L2_ReadDataReg
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
uint8 L2_ReadDataReg(void) 
{
    return (L2_DR & L2_MASK) >> L2_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(L2_INTSTAT) 

    /*******************************************************************************
    * Function Name: L2_ClearInterrupt
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
    uint8 L2_ClearInterrupt(void) 
    {
        return (L2_INTSTAT & L2_MASK) >> L2_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
