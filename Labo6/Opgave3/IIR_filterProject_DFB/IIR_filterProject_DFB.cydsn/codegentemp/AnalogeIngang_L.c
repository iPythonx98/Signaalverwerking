/*******************************************************************************
* File Name: AnalogeIngang_L.c
* Version 1.90
*
* Description:
*  This file provides the source code to the API for OpAmp (Analog Buffer) 
*  Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "AnalogeIngang_L.h"

uint8 AnalogeIngang_L_initVar = 0u;


/*******************************************************************************   
* Function Name: AnalogeIngang_L_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the 
*  customizer of the component placed onto schematic. Usually called in 
*  AnalogeIngang_L_Start().
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AnalogeIngang_L_Init(void) 
{
    AnalogeIngang_L_SetPower(AnalogeIngang_L_DEFAULT_POWER);
}


/*******************************************************************************   
* Function Name: AnalogeIngang_L_Enable
********************************************************************************
*
* Summary:
*  Enables the OpAmp block operation
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AnalogeIngang_L_Enable(void) 
{
    /* Enable negative charge pumps in ANIF */
    AnalogeIngang_L_PUMP_CR1_REG  |= (AnalogeIngang_L_PUMP_CR1_CLKSEL | AnalogeIngang_L_PUMP_CR1_FORCE);

    /* Enable power to buffer in active mode */
    AnalogeIngang_L_PM_ACT_CFG_REG |= AnalogeIngang_L_ACT_PWR_EN;

    /* Enable power to buffer in alternative active mode */
    AnalogeIngang_L_PM_STBY_CFG_REG |= AnalogeIngang_L_STBY_PWR_EN;
}


/*******************************************************************************
* Function Name:   AnalogeIngang_L_Start
********************************************************************************
*
* Summary:
*  The start function initializes the Analog Buffer with the default values and 
*  sets the power to the given level. A power level of 0, is same as 
*  executing the stop function.
*
* Parameters:
*  void
*
* Return:
*  void
*
* Global variables:
*  AnalogeIngang_L_initVar: Used to check the initial configuration, modified 
*  when this function is called for the first time.
*
*******************************************************************************/
void AnalogeIngang_L_Start(void) 
{
    if(AnalogeIngang_L_initVar == 0u)
    {
        AnalogeIngang_L_initVar = 1u;
        AnalogeIngang_L_Init();
    }

    AnalogeIngang_L_Enable();
}


/*******************************************************************************
* Function Name: AnalogeIngang_L_Stop
********************************************************************************
*
* Summary:
*  Powers down amplifier to lowest power state.
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
void AnalogeIngang_L_Stop(void) 
{
    /* Disable power to buffer in active mode template */
    AnalogeIngang_L_PM_ACT_CFG_REG &= (uint8)(~AnalogeIngang_L_ACT_PWR_EN);

    /* Disable power to buffer in alternative active mode template */
    AnalogeIngang_L_PM_STBY_CFG_REG &= (uint8)(~AnalogeIngang_L_STBY_PWR_EN);
    
    /* Disable negative charge pumps for ANIF only if all ABuf is turned OFF */
    if(AnalogeIngang_L_PM_ACT_CFG_REG == 0u)
    {
        AnalogeIngang_L_PUMP_CR1_REG &= (uint8)(~(AnalogeIngang_L_PUMP_CR1_CLKSEL | AnalogeIngang_L_PUMP_CR1_FORCE));
    }
}


/*******************************************************************************
* Function Name: AnalogeIngang_L_SetPower
********************************************************************************
*
* Summary:
*  Sets power level of Analog buffer.
*
* Parameters: 
*  power: PSoC3: Sets power level between low (1) and high power (3).
*         PSoC5: Sets power level High (0)
*
* Return:
*  void
*
**********************************************************************************/
void AnalogeIngang_L_SetPower(uint8 power) 
{
    #if (CY_PSOC3 || CY_PSOC5LP)
        AnalogeIngang_L_CR_REG &= (uint8)(~AnalogeIngang_L_PWR_MASK);
        AnalogeIngang_L_CR_REG |= power & AnalogeIngang_L_PWR_MASK;      /* Set device power */
    #else
        CYASSERT(AnalogeIngang_L_HIGHPOWER == power);
    #endif /* CY_PSOC3 || CY_PSOC5LP */
}


/* [] END OF FILE */
