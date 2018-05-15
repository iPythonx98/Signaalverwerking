/*******************************************************************************
* File Name: AnL_uit.h  
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

#if !defined(CY_PINS_AnL_uit_H) /* Pins AnL_uit_H */
#define CY_PINS_AnL_uit_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AnL_uit_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AnL_uit__PORT == 15 && ((AnL_uit__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    AnL_uit_Write(uint8 value) ;
void    AnL_uit_SetDriveMode(uint8 mode) ;
uint8   AnL_uit_ReadDataReg(void) ;
uint8   AnL_uit_Read(void) ;
uint8   AnL_uit_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AnL_uit_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define AnL_uit_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define AnL_uit_DM_RES_UP          PIN_DM_RES_UP
#define AnL_uit_DM_RES_DWN         PIN_DM_RES_DWN
#define AnL_uit_DM_OD_LO           PIN_DM_OD_LO
#define AnL_uit_DM_OD_HI           PIN_DM_OD_HI
#define AnL_uit_DM_STRONG          PIN_DM_STRONG
#define AnL_uit_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define AnL_uit_MASK               AnL_uit__MASK
#define AnL_uit_SHIFT              AnL_uit__SHIFT
#define AnL_uit_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AnL_uit_PS                     (* (reg8 *) AnL_uit__PS)
/* Data Register */
#define AnL_uit_DR                     (* (reg8 *) AnL_uit__DR)
/* Port Number */
#define AnL_uit_PRT_NUM                (* (reg8 *) AnL_uit__PRT) 
/* Connect to Analog Globals */                                                  
#define AnL_uit_AG                     (* (reg8 *) AnL_uit__AG)                       
/* Analog MUX bux enable */
#define AnL_uit_AMUX                   (* (reg8 *) AnL_uit__AMUX) 
/* Bidirectional Enable */                                                        
#define AnL_uit_BIE                    (* (reg8 *) AnL_uit__BIE)
/* Bit-mask for Aliased Register Access */
#define AnL_uit_BIT_MASK               (* (reg8 *) AnL_uit__BIT_MASK)
/* Bypass Enable */
#define AnL_uit_BYP                    (* (reg8 *) AnL_uit__BYP)
/* Port wide control signals */                                                   
#define AnL_uit_CTL                    (* (reg8 *) AnL_uit__CTL)
/* Drive Modes */
#define AnL_uit_DM0                    (* (reg8 *) AnL_uit__DM0) 
#define AnL_uit_DM1                    (* (reg8 *) AnL_uit__DM1)
#define AnL_uit_DM2                    (* (reg8 *) AnL_uit__DM2) 
/* Input Buffer Disable Override */
#define AnL_uit_INP_DIS                (* (reg8 *) AnL_uit__INP_DIS)
/* LCD Common or Segment Drive */
#define AnL_uit_LCD_COM_SEG            (* (reg8 *) AnL_uit__LCD_COM_SEG)
/* Enable Segment LCD */
#define AnL_uit_LCD_EN                 (* (reg8 *) AnL_uit__LCD_EN)
/* Slew Rate Control */
#define AnL_uit_SLW                    (* (reg8 *) AnL_uit__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AnL_uit_PRTDSI__CAPS_SEL       (* (reg8 *) AnL_uit__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AnL_uit_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AnL_uit__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AnL_uit_PRTDSI__OE_SEL0        (* (reg8 *) AnL_uit__PRTDSI__OE_SEL0) 
#define AnL_uit_PRTDSI__OE_SEL1        (* (reg8 *) AnL_uit__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AnL_uit_PRTDSI__OUT_SEL0       (* (reg8 *) AnL_uit__PRTDSI__OUT_SEL0) 
#define AnL_uit_PRTDSI__OUT_SEL1       (* (reg8 *) AnL_uit__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AnL_uit_PRTDSI__SYNC_OUT       (* (reg8 *) AnL_uit__PRTDSI__SYNC_OUT) 


#if defined(AnL_uit__INTSTAT)  /* Interrupt Registers */

    #define AnL_uit_INTSTAT                (* (reg8 *) AnL_uit__INTSTAT)
    #define AnL_uit_SNAP                   (* (reg8 *) AnL_uit__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AnL_uit_H */


/* [] END OF FILE */
