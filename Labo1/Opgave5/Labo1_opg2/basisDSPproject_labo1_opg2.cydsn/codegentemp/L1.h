/*******************************************************************************
* File Name: L1.h  
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

#if !defined(CY_PINS_L1_H) /* Pins L1_H */
#define CY_PINS_L1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "L1_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 L1__PORT == 15 && ((L1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    L1_Write(uint8 value) ;
void    L1_SetDriveMode(uint8 mode) ;
uint8   L1_ReadDataReg(void) ;
uint8   L1_Read(void) ;
uint8   L1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define L1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define L1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define L1_DM_RES_UP          PIN_DM_RES_UP
#define L1_DM_RES_DWN         PIN_DM_RES_DWN
#define L1_DM_OD_LO           PIN_DM_OD_LO
#define L1_DM_OD_HI           PIN_DM_OD_HI
#define L1_DM_STRONG          PIN_DM_STRONG
#define L1_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define L1_MASK               L1__MASK
#define L1_SHIFT              L1__SHIFT
#define L1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define L1_PS                     (* (reg8 *) L1__PS)
/* Data Register */
#define L1_DR                     (* (reg8 *) L1__DR)
/* Port Number */
#define L1_PRT_NUM                (* (reg8 *) L1__PRT) 
/* Connect to Analog Globals */                                                  
#define L1_AG                     (* (reg8 *) L1__AG)                       
/* Analog MUX bux enable */
#define L1_AMUX                   (* (reg8 *) L1__AMUX) 
/* Bidirectional Enable */                                                        
#define L1_BIE                    (* (reg8 *) L1__BIE)
/* Bit-mask for Aliased Register Access */
#define L1_BIT_MASK               (* (reg8 *) L1__BIT_MASK)
/* Bypass Enable */
#define L1_BYP                    (* (reg8 *) L1__BYP)
/* Port wide control signals */                                                   
#define L1_CTL                    (* (reg8 *) L1__CTL)
/* Drive Modes */
#define L1_DM0                    (* (reg8 *) L1__DM0) 
#define L1_DM1                    (* (reg8 *) L1__DM1)
#define L1_DM2                    (* (reg8 *) L1__DM2) 
/* Input Buffer Disable Override */
#define L1_INP_DIS                (* (reg8 *) L1__INP_DIS)
/* LCD Common or Segment Drive */
#define L1_LCD_COM_SEG            (* (reg8 *) L1__LCD_COM_SEG)
/* Enable Segment LCD */
#define L1_LCD_EN                 (* (reg8 *) L1__LCD_EN)
/* Slew Rate Control */
#define L1_SLW                    (* (reg8 *) L1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define L1_PRTDSI__CAPS_SEL       (* (reg8 *) L1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define L1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) L1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define L1_PRTDSI__OE_SEL0        (* (reg8 *) L1__PRTDSI__OE_SEL0) 
#define L1_PRTDSI__OE_SEL1        (* (reg8 *) L1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define L1_PRTDSI__OUT_SEL0       (* (reg8 *) L1__PRTDSI__OUT_SEL0) 
#define L1_PRTDSI__OUT_SEL1       (* (reg8 *) L1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define L1_PRTDSI__SYNC_OUT       (* (reg8 *) L1__PRTDSI__SYNC_OUT) 


#if defined(L1__INTSTAT)  /* Interrupt Registers */

    #define L1_INTSTAT                (* (reg8 *) L1__INTSTAT)
    #define L1_SNAP                   (* (reg8 *) L1__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_L1_H */


/* [] END OF FILE */
