/*******************************************************************************
* File Name: Codec_en.c  
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
#include "Codec_en.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 Codec_en__PORT == 15 && ((Codec_en__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: Codec_en_Write
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
void Codec_en_Write(uint8 value) 
{
    uint8 staticBits = (Codec_en_DR & (uint8)(~Codec_en_MASK));
    Codec_en_DR = staticBits | ((uint8)(value << Codec_en_SHIFT) & Codec_en_MASK);
}


/*******************************************************************************
* Function Name: Codec_en_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Codec_en_DM_STRONG     Strong Drive 
*  Codec_en_DM_OD_HI      Open Drain, Drives High 
*  Codec_en_DM_OD_LO      Open Drain, Drives Low 
*  Codec_en_DM_RES_UP     Resistive Pull Up 
*  Codec_en_DM_RES_DWN    Resistive Pull Down 
*  Codec_en_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Codec_en_DM_DIG_HIZ    High Impedance Digital 
*  Codec_en_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Codec_en_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(Codec_en_0, mode);
}


/*******************************************************************************
* Function Name: Codec_en_Read
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
*  Macro Codec_en_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Codec_en_Read(void) 
{
    return (Codec_en_PS & Codec_en_MASK) >> Codec_en_SHIFT;
}


/*******************************************************************************
* Function Name: Codec_en_ReadDataReg
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
uint8 Codec_en_ReadDataReg(void) 
{
    return (Codec_en_DR & Codec_en_MASK) >> Codec_en_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Codec_en_INTSTAT) 

    /*******************************************************************************
    * Function Name: Codec_en_ClearInterrupt
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
    uint8 Codec_en_ClearInterrupt(void) 
    {
        return (Codec_en_INTSTAT & Codec_en_MASK) >> Codec_en_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
