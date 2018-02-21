/*******************************************************************************
* File Name: Debounce.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Debounce_H)
#define CY_CLOCK_Debounce_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void Debounce_Start(void) ;
void Debounce_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void Debounce_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void Debounce_StandbyPower(uint8 state) ;
void Debounce_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 Debounce_GetDividerRegister(void) ;
void Debounce_SetModeRegister(uint8 modeBitMask) ;
void Debounce_ClearModeRegister(uint8 modeBitMask) ;
uint8 Debounce_GetModeRegister(void) ;
void Debounce_SetSourceRegister(uint8 clkSource) ;
uint8 Debounce_GetSourceRegister(void) ;
#if defined(Debounce__CFG3)
void Debounce_SetPhaseRegister(uint8 clkPhase) ;
uint8 Debounce_GetPhaseRegister(void) ;
#endif /* defined(Debounce__CFG3) */

#define Debounce_Enable()                       Debounce_Start()
#define Debounce_Disable()                      Debounce_Stop()
#define Debounce_SetDivider(clkDivider)         Debounce_SetDividerRegister(clkDivider, 1u)
#define Debounce_SetDividerValue(clkDivider)    Debounce_SetDividerRegister((clkDivider) - 1u, 1u)
#define Debounce_SetMode(clkMode)               Debounce_SetModeRegister(clkMode)
#define Debounce_SetSource(clkSource)           Debounce_SetSourceRegister(clkSource)
#if defined(Debounce__CFG3)
#define Debounce_SetPhase(clkPhase)             Debounce_SetPhaseRegister(clkPhase)
#define Debounce_SetPhaseValue(clkPhase)        Debounce_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(Debounce__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define Debounce_CLKEN              (* (reg8 *) Debounce__PM_ACT_CFG)
#define Debounce_CLKEN_PTR          ((reg8 *) Debounce__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define Debounce_CLKSTBY            (* (reg8 *) Debounce__PM_STBY_CFG)
#define Debounce_CLKSTBY_PTR        ((reg8 *) Debounce__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define Debounce_DIV_LSB            (* (reg8 *) Debounce__CFG0)
#define Debounce_DIV_LSB_PTR        ((reg8 *) Debounce__CFG0)
#define Debounce_DIV_PTR            ((reg16 *) Debounce__CFG0)

/* Clock MSB divider configuration register. */
#define Debounce_DIV_MSB            (* (reg8 *) Debounce__CFG1)
#define Debounce_DIV_MSB_PTR        ((reg8 *) Debounce__CFG1)

/* Mode and source configuration register */
#define Debounce_MOD_SRC            (* (reg8 *) Debounce__CFG2)
#define Debounce_MOD_SRC_PTR        ((reg8 *) Debounce__CFG2)

#if defined(Debounce__CFG3)
/* Analog clock phase configuration register */
#define Debounce_PHASE              (* (reg8 *) Debounce__CFG3)
#define Debounce_PHASE_PTR          ((reg8 *) Debounce__CFG3)
#endif /* defined(Debounce__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define Debounce_CLKEN_MASK         Debounce__PM_ACT_MSK
#define Debounce_CLKSTBY_MASK       Debounce__PM_STBY_MSK

/* CFG2 field masks */
#define Debounce_SRC_SEL_MSK        Debounce__CFG2_SRC_SEL_MASK
#define Debounce_MODE_MASK          (~(Debounce_SRC_SEL_MSK))

#if defined(Debounce__CFG3)
/* CFG3 phase mask */
#define Debounce_PHASE_MASK         Debounce__CFG3_PHASE_DLY_MASK
#endif /* defined(Debounce__CFG3) */

#endif /* CY_CLOCK_Debounce_H */


/* [] END OF FILE */
