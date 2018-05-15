/*******************************************************************************
* File Name: AnL_uit.c  
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
#include "AnL_uit.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 AnL_uit__PORT == 15 && ((AnL_uit__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: AnL_uit_Write
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
void AnL_uit_Write(uint8 value) 
{
    uint8 staticBits = (AnL_uit_DR & (uint8)(~AnL_uit_MASK));
    AnL_uit_DR = staticBits | ((uint8)(value << AnL_uit_SHIFT) & AnL_uit_MASK);
}


/*******************************************************************************
* Function Name: AnL_uit_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  AnL_uit_DM_STRONG     Strong Drive 
*  AnL_uit_DM_OD_HI      Open Drain, Drives High 
*  AnL_uit_DM_OD_LO      Open Drain, Drives Low 
*  AnL_uit_DM_RES_UP     Resistive Pull Up 
*  AnL_uit_DM_RES_DWN    Resistive Pull Down 
*  AnL_uit_DM_RES_UPDWN  Resistive Pull Up/Down 
*  AnL_uit_DM_DIG_HIZ    High Impedance Digital 
*  AnL_uit_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void AnL_uit_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(AnL_uit_0, mode);
}


/*******************************************************************************
* Function Name: AnL_uit_Read
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
*  Macro AnL_uit_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 AnL_uit_Read(void) 
{
    return (AnL_uit_PS & AnL_uit_MASK) >> AnL_uit_SHIFT;
}


/*******************************************************************************
* Function Name: AnL_uit_ReadDataReg
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
uint8 AnL_uit_ReadDataReg(void) 
{
    return (AnL_uit_DR & AnL_uit_MASK) >> AnL_uit_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(AnL_uit_INTSTAT) 

    /*******************************************************************************
    * Function Name: AnL_uit_ClearInterrupt
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
    uint8 AnL_uit_ClearInterrupt(void) 
    {
        return (AnL_uit_INTSTAT & AnL_uit_MASK) >> AnL_uit_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
