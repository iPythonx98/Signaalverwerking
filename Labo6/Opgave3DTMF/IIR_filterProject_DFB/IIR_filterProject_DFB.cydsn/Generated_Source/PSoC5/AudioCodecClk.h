/*******************************************************************************
* File Name: AudioCodecClk.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
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

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AudioCodecClk__PORT == 15 && ((AudioCodecClk__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AudioCodecClk_Write(uint8 value);
void    AudioCodecClk_SetDriveMode(uint8 mode);
uint8   AudioCodecClk_ReadDataReg(void);
uint8   AudioCodecClk_Read(void);
void    AudioCodecClk_SetInterruptMode(uint16 position, uint16 mode);
uint8   AudioCodecClk_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AudioCodecClk_SetDriveMode() function.
     *  @{
     */
        #define AudioCodecClk_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AudioCodecClk_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AudioCodecClk_DM_RES_UP          PIN_DM_RES_UP
        #define AudioCodecClk_DM_RES_DWN         PIN_DM_RES_DWN
        #define AudioCodecClk_DM_OD_LO           PIN_DM_OD_LO
        #define AudioCodecClk_DM_OD_HI           PIN_DM_OD_HI
        #define AudioCodecClk_DM_STRONG          PIN_DM_STRONG
        #define AudioCodecClk_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AudioCodecClk_MASK               AudioCodecClk__MASK
#define AudioCodecClk_SHIFT              AudioCodecClk__SHIFT
#define AudioCodecClk_WIDTH              1u

/* Interrupt constants */
#if defined(AudioCodecClk__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AudioCodecClk_SetInterruptMode() function.
     *  @{
     */
        #define AudioCodecClk_INTR_NONE      (uint16)(0x0000u)
        #define AudioCodecClk_INTR_RISING    (uint16)(0x0001u)
        #define AudioCodecClk_INTR_FALLING   (uint16)(0x0002u)
        #define AudioCodecClk_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AudioCodecClk_INTR_MASK      (0x01u) 
#endif /* (AudioCodecClk__INTSTAT) */


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

/* SIO registers */
#if defined(AudioCodecClk__SIO_CFG)
    #define AudioCodecClk_SIO_HYST_EN        (* (reg8 *) AudioCodecClk__SIO_HYST_EN)
    #define AudioCodecClk_SIO_REG_HIFREQ     (* (reg8 *) AudioCodecClk__SIO_REG_HIFREQ)
    #define AudioCodecClk_SIO_CFG            (* (reg8 *) AudioCodecClk__SIO_CFG)
    #define AudioCodecClk_SIO_DIFF           (* (reg8 *) AudioCodecClk__SIO_DIFF)
#endif /* (AudioCodecClk__SIO_CFG) */

/* Interrupt Registers */
#if defined(AudioCodecClk__INTSTAT)
    #define AudioCodecClk_INTSTAT            (* (reg8 *) AudioCodecClk__INTSTAT)
    #define AudioCodecClk_SNAP               (* (reg8 *) AudioCodecClk__SNAP)
    
	#define AudioCodecClk_0_INTTYPE_REG 		(* (reg8 *) AudioCodecClk__0__INTTYPE)
#endif /* (AudioCodecClk__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AudioCodecClk_H */


/* [] END OF FILE */
