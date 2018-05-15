/*******************************************************************************
* File Name: POT_2.h  
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

#if !defined(CY_PINS_POT_2_H) /* Pins POT_2_H */
#define CY_PINS_POT_2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "POT_2_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 POT_2__PORT == 15 && ((POT_2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    POT_2_Write(uint8 value) ;
void    POT_2_SetDriveMode(uint8 mode) ;
uint8   POT_2_ReadDataReg(void) ;
uint8   POT_2_Read(void) ;
uint8   POT_2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define POT_2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define POT_2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define POT_2_DM_RES_UP          PIN_DM_RES_UP
#define POT_2_DM_RES_DWN         PIN_DM_RES_DWN
#define POT_2_DM_OD_LO           PIN_DM_OD_LO
#define POT_2_DM_OD_HI           PIN_DM_OD_HI
#define POT_2_DM_STRONG          PIN_DM_STRONG
#define POT_2_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define POT_2_MASK               POT_2__MASK
#define POT_2_SHIFT              POT_2__SHIFT
#define POT_2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define POT_2_PS                     (* (reg8 *) POT_2__PS)
/* Data Register */
#define POT_2_DR                     (* (reg8 *) POT_2__DR)
/* Port Number */
#define POT_2_PRT_NUM                (* (reg8 *) POT_2__PRT) 
/* Connect to Analog Globals */                                                  
#define POT_2_AG                     (* (reg8 *) POT_2__AG)                       
/* Analog MUX bux enable */
#define POT_2_AMUX                   (* (reg8 *) POT_2__AMUX) 
/* Bidirectional Enable */                                                        
#define POT_2_BIE                    (* (reg8 *) POT_2__BIE)
/* Bit-mask for Aliased Register Access */
#define POT_2_BIT_MASK               (* (reg8 *) POT_2__BIT_MASK)
/* Bypass Enable */
#define POT_2_BYP                    (* (reg8 *) POT_2__BYP)
/* Port wide control signals */                                                   
#define POT_2_CTL                    (* (reg8 *) POT_2__CTL)
/* Drive Modes */
#define POT_2_DM0                    (* (reg8 *) POT_2__DM0) 
#define POT_2_DM1                    (* (reg8 *) POT_2__DM1)
#define POT_2_DM2                    (* (reg8 *) POT_2__DM2) 
/* Input Buffer Disable Override */
#define POT_2_INP_DIS                (* (reg8 *) POT_2__INP_DIS)
/* LCD Common or Segment Drive */
#define POT_2_LCD_COM_SEG            (* (reg8 *) POT_2__LCD_COM_SEG)
/* Enable Segment LCD */
#define POT_2_LCD_EN                 (* (reg8 *) POT_2__LCD_EN)
/* Slew Rate Control */
#define POT_2_SLW                    (* (reg8 *) POT_2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define POT_2_PRTDSI__CAPS_SEL       (* (reg8 *) POT_2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define POT_2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) POT_2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define POT_2_PRTDSI__OE_SEL0        (* (reg8 *) POT_2__PRTDSI__OE_SEL0) 
#define POT_2_PRTDSI__OE_SEL1        (* (reg8 *) POT_2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define POT_2_PRTDSI__OUT_SEL0       (* (reg8 *) POT_2__PRTDSI__OUT_SEL0) 
#define POT_2_PRTDSI__OUT_SEL1       (* (reg8 *) POT_2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define POT_2_PRTDSI__SYNC_OUT       (* (reg8 *) POT_2__PRTDSI__SYNC_OUT) 


#if defined(POT_2__INTSTAT)  /* Interrupt Registers */

    #define POT_2_INTSTAT                (* (reg8 *) POT_2__INTSTAT)
    #define POT_2_SNAP                   (* (reg8 *) POT_2__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_POT_2_H */


/* [] END OF FILE */
