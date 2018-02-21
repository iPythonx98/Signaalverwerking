/*******************************************************************************
* File Name: L2.h  
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

#if !defined(CY_PINS_L2_H) /* Pins L2_H */
#define CY_PINS_L2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "L2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 L2__PORT == 15 && ((L2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    L2_Write(uint8 value) ;
void    L2_SetDriveMode(uint8 mode) ;
uint8   L2_ReadDataReg(void) ;
uint8   L2_Read(void) ;
uint8   L2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define L2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define L2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define L2_DM_RES_UP          PIN_DM_RES_UP
#define L2_DM_RES_DWN         PIN_DM_RES_DWN
#define L2_DM_OD_LO           PIN_DM_OD_LO
#define L2_DM_OD_HI           PIN_DM_OD_HI
#define L2_DM_STRONG          PIN_DM_STRONG
#define L2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define L2_MASK               L2__MASK
#define L2_SHIFT              L2__SHIFT
#define L2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define L2_PS                     (* (reg8 *) L2__PS)
/* Data Register */
#define L2_DR                     (* (reg8 *) L2__DR)
/* Port Number */
#define L2_PRT_NUM                (* (reg8 *) L2__PRT) 
/* Connect to Analog Globals */                                                  
#define L2_AG                     (* (reg8 *) L2__AG)                       
/* Analog MUX bux enable */
#define L2_AMUX                   (* (reg8 *) L2__AMUX) 
/* Bidirectional Enable */                                                        
#define L2_BIE                    (* (reg8 *) L2__BIE)
/* Bit-mask for Aliased Register Access */
#define L2_BIT_MASK               (* (reg8 *) L2__BIT_MASK)
/* Bypass Enable */
#define L2_BYP                    (* (reg8 *) L2__BYP)
/* Port wide control signals */                                                   
#define L2_CTL                    (* (reg8 *) L2__CTL)
/* Drive Modes */
#define L2_DM0                    (* (reg8 *) L2__DM0) 
#define L2_DM1                    (* (reg8 *) L2__DM1)
#define L2_DM2                    (* (reg8 *) L2__DM2) 
/* Input Buffer Disable Override */
#define L2_INP_DIS                (* (reg8 *) L2__INP_DIS)
/* LCD Common or Segment Drive */
#define L2_LCD_COM_SEG            (* (reg8 *) L2__LCD_COM_SEG)
/* Enable Segment LCD */
#define L2_LCD_EN                 (* (reg8 *) L2__LCD_EN)
/* Slew Rate Control */
#define L2_SLW                    (* (reg8 *) L2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define L2_PRTDSI__CAPS_SEL       (* (reg8 *) L2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define L2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) L2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define L2_PRTDSI__OE_SEL0        (* (reg8 *) L2__PRTDSI__OE_SEL0) 
#define L2_PRTDSI__OE_SEL1        (* (reg8 *) L2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define L2_PRTDSI__OUT_SEL0       (* (reg8 *) L2__PRTDSI__OUT_SEL0) 
#define L2_PRTDSI__OUT_SEL1       (* (reg8 *) L2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define L2_PRTDSI__SYNC_OUT       (* (reg8 *) L2__PRTDSI__SYNC_OUT) 


#if defined(L2__INTSTAT)  /* Interrupt Registers */

    #define L2_INTSTAT                (* (reg8 *) L2__INTSTAT)
    #define L2_SNAP                   (* (reg8 *) L2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_L2_H */


/* [] END OF FILE */
