/*******************************************************************************
* File Name: AudioCodecClk.c  
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
#include "AudioCodecClk.h"

/* APIs are not generated for P15[7:6] on PSoC 5 */
#if !(CY_PSOC5A &&\
	 AudioCodecClk__PORT == 15 && ((AudioCodecClk__MASK & 0xC0) != 0))


/*******************************************************************************
* Function Name: AudioCodecClk_Write
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
void AudioCodecClk_Write(uint8 value) 
{
    uint8 staticBits = (AudioCodecClk_DR & (uint8)(~AudioCodecClk_MASK));
    AudioCodecClk_DR = staticBits | ((uint8)(value << AudioCodecClk_SHIFT) & AudioCodecClk_MASK);
}


/*******************************************************************************
* Function Name: AudioCodecClk_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  AudioCodecClk_DM_STRONG     Strong Drive 
*  AudioCodecClk_DM_OD_HI      Open Drain, Drives High 
*  AudioCodecClk_DM_OD_LO      Open Drain, Drives Low 
*  AudioCodecClk_DM_RES_UP     Resistive Pull Up 
*  AudioCodecClk_DM_RES_DWN    Resistive Pull Down 
*  AudioCodecClk_DM_RES_UPDWN  Resistive Pull Up/Down 
*  AudioCodecClk_DM_DIG_HIZ    High Impedance Digital 
*  AudioCodecClk_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void AudioCodecClk_SetDriveMode(uint8 mode) 
{
	CyPins_SetPinDriveMode(AudioCodecClk_0, mode);
}


/*******************************************************************************
* Function Name: AudioCodecClk_Read
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
*  Macro AudioCodecClk_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 AudioCodecClk_Read(void) 
{
    return (AudioCodecClk_PS & AudioCodecClk_MASK) >> AudioCodecClk_SHIFT;
}


/*******************************************************************************
* Function Name: AudioCodecClk_ReadDataReg
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
uint8 AudioCodecClk_ReadDataReg(void) 
{
    return (AudioCodecClk_DR & AudioCodecClk_MASK) >> AudioCodecClk_SHIFT;
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(AudioCodecClk_INTSTAT) 

    /*******************************************************************************
    * Function Name: AudioCodecClk_ClearInterrupt
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
    uint8 AudioCodecClk_ClearInterrupt(void) 
    {
        return (AudioCodecClk_INTSTAT & AudioCodecClk_MASK) >> AudioCodecClk_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 

#endif /* CY_PSOC5A... */

    
/* [] END OF FILE */
