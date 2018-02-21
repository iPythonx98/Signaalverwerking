/*******************************************************************************
* File Name: AudioCodecClk.h  
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

#if !defined(CY_PINS_AudioCodecClk_H) /* Pins AudioCodecClk_H */
#define CY_PINS_AudioCodecClk_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AudioCodecClk_aliases.h"

/* Check to see if required defines such as CY_PSOC5A are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5A)
    #error Component cy_pins_v2_10 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5A) */

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AudioCodecClk__PORT == 15 && ((AudioCodecClk__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

void    AudioCodecClk_Write(uint8 value) ;
void    AudioCodecClk_SetDriveMode(uint8 mode) ;
uint8   AudioCodecClk_ReadDataReg(void) ;
uint8   AudioCodecClk_Read(void) ;
uint8   AudioCodecClk_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define AudioCodecClk_DM_ALG_HIZ         PIN_DM_ALG_HIZ
#define AudioCodecClk_DM_DIG_HIZ         PIN_DM_DIG_HIZ
#define AudioCodecClk_DM_RES_UP          PIN_DM_RES_UP
#define AudioCodecClk_DM_RES_DWN         PIN_DM_RES_DWN
#define AudioCodecClk_DM_OD_LO           PIN_DM_OD_LO
#define AudioCodecClk_DM_OD_HI           PIN_DM_OD_HI
#define AudioCodecClk_DM_STRONG          PIN_DM_STRONG
#define AudioCodecClk_DM_RES_UPDWN       PIN_DM_RES_UPDWN

/* Digital Port Constants */
#define AudioCodecClk_MASK               AudioCodecClk__MASK
#define AudioCodecClk_SHIFT              AudioCodecClk__SHIFT
#define AudioCodecClk_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AudioCodecClk_PS                     (* (reg8 *) AudioCodecClk__PS)
/* Data Register */
#define AudioCodecClk_DR                     (* (reg8 *) AudioCodecClk__DR)
/* Port Number */
#define AudioCodecClk_PRT_NUM                (* (reg8 *) AudioCodecClk__PRT) 
/* Connect to Analog Globals */                                                  
#define AudioCodecClk_AG                     (* (reg8 *) AudioCodecClk__AG)                       
/* Analog MUX bux enable */
#define AudioCodecClk_AMUX                   (* (reg8 *) AudioCodecClk__AMUX) 
/* Bidirectional Enable */                                                        
#define AudioCodecClk_BIE                    (* (reg8 *) AudioCodecClk__BIE)
/* Bit-mask for Aliased Register Access */
#define AudioCodecClk_BIT_MASK               (* (reg8 *) AudioCodecClk__BIT_MASK)
/* Bypass Enable */
#define AudioCodecClk_BYP                    (* (reg8 *) AudioCodecClk__BYP)
/* Port wide control signals */                                                   
#define AudioCodecClk_CTL                    (* (reg8 *) AudioCodecClk__CTL)
/* Drive Modes */
#define AudioCodecClk_DM0                    (* (reg8 *) AudioCodecClk__DM0) 
#define AudioCodecClk_DM1                    (* (reg8 *) AudioCodecClk__DM1)
#define AudioCodecClk_DM2                    (* (reg8 *) AudioCodecClk__DM2) 
/* Input Buffer Disable Override */
#define AudioCodecClk_INP_DIS                (* (reg8 *) AudioCodecClk__INP_DIS)
/* LCD Common or Segment Drive */
#define AudioCodecClk_LCD_COM_SEG            (* (reg8 *) AudioCodecClk__LCD_COM_SEG)
/* Enable Segment LCD */
#define AudioCodecClk_LCD_EN                 (* (reg8 *) AudioCodecClk__LCD_EN)
/* Slew Rate Control */
#define AudioCodecClk_SLW                    (* (reg8 *) AudioCodecClk__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AudioCodecClk_PRTDSI__CAPS_SEL       (* (reg8 *) AudioCodecClk__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AudioCodecClk_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AudioCodecClk__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AudioCodecClk_PRTDSI__OE_SEL0        (* (reg8 *) AudioCodecClk__PRTDSI__OE_SEL0) 
#define AudioCodecClk_PRTDSI__OE_SEL1        (* (reg8 *) AudioCodecClk__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AudioCodecClk_PRTDSI__OUT_SEL0       (* (reg8 *) AudioCodecClk__PRTDSI__OUT_SEL0) 
#define AudioCodecClk_PRTDSI__OUT_SEL1       (* (reg8 *) AudioCodecClk__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AudioCodecClk_PRTDSI__SYNC_OUT       (* (reg8 *) AudioCodecClk__PRTDSI__SYNC_OUT) 


#if defined(AudioCodecClk__INTSTAT)  /* Interrupt Registers */

    #define AudioCodecClk_INTSTAT                (* (reg8 *) AudioCodecClk__INTSTAT)
    #define AudioCodecClk_SNAP                   (* (reg8 *) AudioCodecClk__SNAP)

#endif /* Interrupt Registers */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AudioCodecClk_H */


/* [] END OF FILE */
