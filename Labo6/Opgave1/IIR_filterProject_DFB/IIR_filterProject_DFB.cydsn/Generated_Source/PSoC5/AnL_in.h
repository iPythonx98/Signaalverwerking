/*******************************************************************************
* File Name: AnL_in.h  
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

#if !defined(CY_PINS_AnL_in_H) /* Pins AnL_in_H */
#define CY_PINS_AnL_in_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AnL_in_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AnL_in__PORT == 15 && ((AnL_in__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    AnL_in_Write(uint8 value) ;
void    AnL_in_SetDriveMode(uint8 mode) ;
uint8   AnL_in_ReadDataReg(void) ;
uint8   AnL_in_Read(void) ;
uint8   AnL_in_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AnL_in_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define AnL_in_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define AnL_in_DM_RES_UP          PIN_DM_RES_UP
#define AnL_in_DM_RES_DWN         PIN_DM_RES_DWN
#define AnL_in_DM_OD_LO           PIN_DM_OD_LO
#define AnL_in_DM_OD_HI           PIN_DM_OD_HI
#define AnL_in_DM_STRONG          PIN_DM_STRONG
#define AnL_in_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define AnL_in_MASK               AnL_in__MASK
#define AnL_in_SHIFT              AnL_in__SHIFT
#define AnL_in_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AnL_in_PS                     (* (reg8 *) AnL_in__PS)
/* Data Register */
#define AnL_in_DR                     (* (reg8 *) AnL_in__DR)
/* Port Number */
#define AnL_in_PRT_NUM                (* (reg8 *) AnL_in__PRT) 
/* Connect to Analog Globals */                                                  
#define AnL_in_AG                     (* (reg8 *) AnL_in__AG)                       
/* Analog MUX bux enable */
#define AnL_in_AMUX                   (* (reg8 *) AnL_in__AMUX) 
/* Bidirectional Enable */                                                        
#define AnL_in_BIE                    (* (reg8 *) AnL_in__BIE)
/* Bit-mask for Aliased Register Access */
#define AnL_in_BIT_MASK               (* (reg8 *) AnL_in__BIT_MASK)
/* Bypass Enable */
#define AnL_in_BYP                    (* (reg8 *) AnL_in__BYP)
/* Port wide control signals */                                                   
#define AnL_in_CTL                    (* (reg8 *) AnL_in__CTL)
/* Drive Modes */
#define AnL_in_DM0                    (* (reg8 *) AnL_in__DM0) 
#define AnL_in_DM1                    (* (reg8 *) AnL_in__DM1)
#define AnL_in_DM2                    (* (reg8 *) AnL_in__DM2) 
/* Input Buffer Disable Override */
#define AnL_in_INP_DIS                (* (reg8 *) AnL_in__INP_DIS)
/* LCD Common or Segment Drive */
#define AnL_in_LCD_COM_SEG            (* (reg8 *) AnL_in__LCD_COM_SEG)
/* Enable Segment LCD */
#define AnL_in_LCD_EN                 (* (reg8 *) AnL_in__LCD_EN)
/* Slew Rate Control */
#define AnL_in_SLW                    (* (reg8 *) AnL_in__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AnL_in_PRTDSI__CAPS_SEL       (* (reg8 *) AnL_in__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AnL_in_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AnL_in__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AnL_in_PRTDSI__OE_SEL0        (* (reg8 *) AnL_in__PRTDSI__OE_SEL0) 
#define AnL_in_PRTDSI__OE_SEL1        (* (reg8 *) AnL_in__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AnL_in_PRTDSI__OUT_SEL0       (* (reg8 *) AnL_in__PRTDSI__OUT_SEL0) 
#define AnL_in_PRTDSI__OUT_SEL1       (* (reg8 *) AnL_in__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AnL_in_PRTDSI__SYNC_OUT       (* (reg8 *) AnL_in__PRTDSI__SYNC_OUT) 


#if defined(AnL_in__INTSTAT)  /* Interrupt Registers */

    #define AnL_in_INTSTAT                (* (reg8 *) AnL_in__INTSTAT)
    #define AnL_in_SNAP                   (* (reg8 *) AnL_in__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AnL_in_H */


/* [] END OF FILE */
