/*******************************************************************************
* File Name: AnR_in.c  
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
#include "AnR_in.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 AnR_in__PORT == 15 && ((AnR_in__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: AnR_in_Write
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
void AnR_in_Write(uint8 value) 
{
    uint8 staticBits = (AnR_in_DR & (uint8)(~AnR_in_MASK));
    AnR_in_DR = staticBits | ((uint8)(value << AnR_in_SHIFT) & AnR_in_MASK);
}


/*******************************************************************************
* Function Name: AnR_in_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  AnR_in_DM_STRONG     Strong Drive 
*  AnR_in_DM_OD_HI      Open Drain, Drives High 
*  AnR_in_DM_OD_LO      Open Drain, Drives Low 
*  AnR_in_DM_RES_UP     Resistive Pull Up 
*  AnR_in_DM_RES_DWN    Resistive Pull Down 
*  AnR_in_DM_RES_UPDWN  Resistive Pull Up/Down 
*  AnR_in_DM_DIG_HIZ    High Impedance Digital 
*  AnR_in_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void AnR_in_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(AnR_in_0, mode);
}


/*******************************************************************************
* Function Name: AnR_in_Read
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
*  Macro AnR_in_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 AnR_in_Read(void) 
{
    return (AnR_in_PS & AnR_in_MASK) >> AnR_in_SHIFT;
}


/*******************************************************************************
* Function Name: AnR_in_ReadDataReg
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
uint8 AnR_in_ReadDataReg(void) 
{
    return (AnR_in_DR & AnR_in_MASK) >> AnR_in_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(AnR_in_INTSTAT) 

    /*******************************************************************************
    * Function Name: AnR_in_ClearInterrupt
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
    uint8 AnR_in_ClearInterrupt(void) 
    {
        return (AnR_in_INTSTAT & AnR_in_MASK) >> AnR_in_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
