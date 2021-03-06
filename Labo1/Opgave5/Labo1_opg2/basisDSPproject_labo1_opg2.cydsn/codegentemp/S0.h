/*******************************************************************************
* File Name: S0.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_S0_H) /* Pins S0_H */
#define CY_PINS_S0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "S0_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 S0__PORT == 15 && ((S0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    S0_Write(uint8 value) ;
void    S0_SetDriveMode(uint8 mode) ;
uint8   S0_ReadDataReg(void) ;
uint8   S0_Read(void) ;
uint8   S0_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define S0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define S0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define S0_DM_RES_UP          PIN_DM_RES_UP
#define S0_DM_RES_DWN         PIN_DM_RES_DWN
#define S0_DM_OD_LO           PIN_DM_OD_LO
#define S0_DM_OD_HI           PIN_DM_OD_HI
#define S0_DM_STRONG          PIN_DM_STRONG
#define S0_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define S0_MASK               S0__MASK
#define S0_SHIFT              S0__SHIFT
#define S0_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define S0_PS                     (* (reg8 *) S0__PS)
/* Data Register */
#define S0_DR                     (* (reg8 *) S0__DR)
/* Port Number */
#define S0_PRT_NUM                (* (reg8 *) S0__PRT) 
/* Connect to Analog Globals */                                                  
#define S0_AG                     (* (reg8 *) S0__AG)                       
/* Analog MUX bux enable */
#define S0_AMUX                   (* (reg8 *) S0__AMUX) 
/* Bidirectional Enable */                                                        
#define S0_BIE                    (* (reg8 *) S0__BIE)
/* Bit-mask for Aliased Register Access */
#define S0_BIT_MASK               (* (reg8 *) S0__BIT_MASK)
/* Bypass Enable */
#define S0_BYP                    (* (reg8 *) S0__BYP)
/* Port wide control signals */                                                   
#define S0_CTL                    (* (reg8 *) S0__CTL)
/* Drive Modes */
#define S0_DM0                    (* (reg8 *) S0__DM0) 
#define S0_DM1                    (* (reg8 *) S0__DM1)
#define S0_DM2                    (* (reg8 *) S0__DM2) 
/* Input Buffer Disable Override */
#define S0_INP_DIS                (* (reg8 *) S0__INP_DIS)
/* LCD Common or Segment Drive */
#define S0_LCD_COM_SEG            (* (reg8 *) S0__LCD_COM_SEG)
/* Enable Segment LCD */
#define S0_LCD_EN                 (* (reg8 *) S0__LCD_EN)
/* Slew Rate Control */
#define S0_SLW                    (* (reg8 *) S0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define S0_PRTDSI__CAPS_SEL       (* (reg8 *) S0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define S0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) S0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define S0_PRTDSI__OE_SEL0        (* (reg8 *) S0__PRTDSI__OE_SEL0) 
#define S0_PRTDSI__OE_SEL1        (* (reg8 *) S0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define S0_PRTDSI__OUT_SEL0       (* (reg8 *) S0__PRTDSI__OUT_SEL0) 
#define S0_PRTDSI__OUT_SEL1       (* (reg8 *) S0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define S0_PRTDSI__SYNC_OUT       (* (reg8 *) S0__PRTDSI__SYNC_OUT) 


#if defined(S0__INTSTAT)  /* Interrupt Registers */

    #define S0_INTSTAT                (* (reg8 *) S0__INTSTAT)
    #define S0_SNAP                   (* (reg8 *) S0__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_S0_H */


/* [] END OF FILE */
