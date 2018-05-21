/*******************************************************************************
* File Name: AnR_uit.h  
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

#if !defined(CY_PINS_AnR_uit_H) /* Pins AnR_uit_H */
#define CY_PINS_AnR_uit_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AnR_uit_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AnR_uit__PORT == 15 && ((AnR_uit__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AnR_uit_Write(uint8 value);
void    AnR_uit_SetDriveMode(uint8 mode);
uint8   AnR_uit_ReadDataReg(void);
uint8   AnR_uit_Read(void);
void    AnR_uit_SetInterruptMode(uint16 position, uint16 mode);
uint8   AnR_uit_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AnR_uit_SetDriveMode() function.
     *  @{
     */
        #define AnR_uit_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AnR_uit_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AnR_uit_DM_RES_UP          PIN_DM_RES_UP
        #define AnR_uit_DM_RES_DWN         PIN_DM_RES_DWN
        #define AnR_uit_DM_OD_LO           PIN_DM_OD_LO
        #define AnR_uit_DM_OD_HI           PIN_DM_OD_HI
        #define AnR_uit_DM_STRONG          PIN_DM_STRONG
        #define AnR_uit_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AnR_uit_MASK               AnR_uit__MASK
#define AnR_uit_SHIFT              AnR_uit__SHIFT
#define AnR_uit_WIDTH              1u

/* Interrupt constants */
#if defined(AnR_uit__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AnR_uit_SetInterruptMode() function.
     *  @{
     */
        #define AnR_uit_INTR_NONE      (uint16)(0x0000u)
        #define AnR_uit_INTR_RISING    (uint16)(0x0001u)
        #define AnR_uit_INTR_FALLING   (uint16)(0x0002u)
        #define AnR_uit_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AnR_uit_INTR_MASK      (0x01u) 
#endif /* (AnR_uit__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AnR_uit_PS                     (* (reg8 *) AnR_uit__PS)
/* Data Register */
#define AnR_uit_DR                     (* (reg8 *) AnR_uit__DR)
/* Port Number */
#define AnR_uit_PRT_NUM                (* (reg8 *) AnR_uit__PRT) 
/* Connect to Analog Globals */                                                  
#define AnR_uit_AG                     (* (reg8 *) AnR_uit__AG)                       
/* Analog MUX bux enable */
#define AnR_uit_AMUX                   (* (reg8 *) AnR_uit__AMUX) 
/* Bidirectional Enable */                                                        
#define AnR_uit_BIE                    (* (reg8 *) AnR_uit__BIE)
/* Bit-mask for Aliased Register Access */
#define AnR_uit_BIT_MASK               (* (reg8 *) AnR_uit__BIT_MASK)
/* Bypass Enable */
#define AnR_uit_BYP                    (* (reg8 *) AnR_uit__BYP)
/* Port wide control signals */                                                   
#define AnR_uit_CTL                    (* (reg8 *) AnR_uit__CTL)
/* Drive Modes */
#define AnR_uit_DM0                    (* (reg8 *) AnR_uit__DM0) 
#define AnR_uit_DM1                    (* (reg8 *) AnR_uit__DM1)
#define AnR_uit_DM2                    (* (reg8 *) AnR_uit__DM2) 
/* Input Buffer Disable Override */
#define AnR_uit_INP_DIS                (* (reg8 *) AnR_uit__INP_DIS)
/* LCD Common or Segment Drive */
#define AnR_uit_LCD_COM_SEG            (* (reg8 *) AnR_uit__LCD_COM_SEG)
/* Enable Segment LCD */
#define AnR_uit_LCD_EN                 (* (reg8 *) AnR_uit__LCD_EN)
/* Slew Rate Control */
#define AnR_uit_SLW                    (* (reg8 *) AnR_uit__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AnR_uit_PRTDSI__CAPS_SEL       (* (reg8 *) AnR_uit__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AnR_uit_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AnR_uit__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AnR_uit_PRTDSI__OE_SEL0        (* (reg8 *) AnR_uit__PRTDSI__OE_SEL0) 
#define AnR_uit_PRTDSI__OE_SEL1        (* (reg8 *) AnR_uit__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AnR_uit_PRTDSI__OUT_SEL0       (* (reg8 *) AnR_uit__PRTDSI__OUT_SEL0) 
#define AnR_uit_PRTDSI__OUT_SEL1       (* (reg8 *) AnR_uit__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AnR_uit_PRTDSI__SYNC_OUT       (* (reg8 *) AnR_uit__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AnR_uit__SIO_CFG)
    #define AnR_uit_SIO_HYST_EN        (* (reg8 *) AnR_uit__SIO_HYST_EN)
    #define AnR_uit_SIO_REG_HIFREQ     (* (reg8 *) AnR_uit__SIO_REG_HIFREQ)
    #define AnR_uit_SIO_CFG            (* (reg8 *) AnR_uit__SIO_CFG)
    #define AnR_uit_SIO_DIFF           (* (reg8 *) AnR_uit__SIO_DIFF)
#endif /* (AnR_uit__SIO_CFG) */

/* Interrupt Registers */
#if defined(AnR_uit__INTSTAT)
    #define AnR_uit_INTSTAT            (* (reg8 *) AnR_uit__INTSTAT)
    #define AnR_uit_SNAP               (* (reg8 *) AnR_uit__SNAP)
    
	#define AnR_uit_0_INTTYPE_REG 		(* (reg8 *) AnR_uit__0__INTTYPE)
#endif /* (AnR_uit__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AnR_uit_H */


/* [] END OF FILE */
