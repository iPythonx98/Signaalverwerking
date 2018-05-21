/*******************************************************************************
* File Name: L0.h  
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

#if !defined(CY_PINS_L0_H) /* Pins L0_H */
#define CY_PINS_L0_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "L0_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 L0__PORT == 15 && ((L0__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    L0_Write(uint8 value);
void    L0_SetDriveMode(uint8 mode);
uint8   L0_ReadDataReg(void);
uint8   L0_Read(void);
void    L0_SetInterruptMode(uint16 position, uint16 mode);
uint8   L0_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the L0_SetDriveMode() function.
     *  @{
     */
        #define L0_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define L0_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define L0_DM_RES_UP          PIN_DM_RES_UP
        #define L0_DM_RES_DWN         PIN_DM_RES_DWN
        #define L0_DM_OD_LO           PIN_DM_OD_LO
        #define L0_DM_OD_HI           PIN_DM_OD_HI
        #define L0_DM_STRONG          PIN_DM_STRONG
        #define L0_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define L0_MASK               L0__MASK
#define L0_SHIFT              L0__SHIFT
#define L0_WIDTH              1u

/* Interrupt constants */
#if defined(L0__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in L0_SetInterruptMode() function.
     *  @{
     */
        #define L0_INTR_NONE      (uint16)(0x0000u)
        #define L0_INTR_RISING    (uint16)(0x0001u)
        #define L0_INTR_FALLING   (uint16)(0x0002u)
        #define L0_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define L0_INTR_MASK      (0x01u) 
#endif /* (L0__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define L0_PS                     (* (reg8 *) L0__PS)
/* Data Register */
#define L0_DR                     (* (reg8 *) L0__DR)
/* Port Number */
#define L0_PRT_NUM                (* (reg8 *) L0__PRT) 
/* Connect to Analog Globals */                                                  
#define L0_AG                     (* (reg8 *) L0__AG)                       
/* Analog MUX bux enable */
#define L0_AMUX                   (* (reg8 *) L0__AMUX) 
/* Bidirectional Enable */                                                        
#define L0_BIE                    (* (reg8 *) L0__BIE)
/* Bit-mask for Aliased Register Access */
#define L0_BIT_MASK               (* (reg8 *) L0__BIT_MASK)
/* Bypass Enable */
#define L0_BYP                    (* (reg8 *) L0__BYP)
/* Port wide control signals */                                                   
#define L0_CTL                    (* (reg8 *) L0__CTL)
/* Drive Modes */
#define L0_DM0                    (* (reg8 *) L0__DM0) 
#define L0_DM1                    (* (reg8 *) L0__DM1)
#define L0_DM2                    (* (reg8 *) L0__DM2) 
/* Input Buffer Disable Override */
#define L0_INP_DIS                (* (reg8 *) L0__INP_DIS)
/* LCD Common or Segment Drive */
#define L0_LCD_COM_SEG            (* (reg8 *) L0__LCD_COM_SEG)
/* Enable Segment LCD */
#define L0_LCD_EN                 (* (reg8 *) L0__LCD_EN)
/* Slew Rate Control */
#define L0_SLW                    (* (reg8 *) L0__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define L0_PRTDSI__CAPS_SEL       (* (reg8 *) L0__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define L0_PRTDSI__DBL_SYNC_IN    (* (reg8 *) L0__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define L0_PRTDSI__OE_SEL0        (* (reg8 *) L0__PRTDSI__OE_SEL0) 
#define L0_PRTDSI__OE_SEL1        (* (reg8 *) L0__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define L0_PRTDSI__OUT_SEL0       (* (reg8 *) L0__PRTDSI__OUT_SEL0) 
#define L0_PRTDSI__OUT_SEL1       (* (reg8 *) L0__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define L0_PRTDSI__SYNC_OUT       (* (reg8 *) L0__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(L0__SIO_CFG)
    #define L0_SIO_HYST_EN        (* (reg8 *) L0__SIO_HYST_EN)
    #define L0_SIO_REG_HIFREQ     (* (reg8 *) L0__SIO_REG_HIFREQ)
    #define L0_SIO_CFG            (* (reg8 *) L0__SIO_CFG)
    #define L0_SIO_DIFF           (* (reg8 *) L0__SIO_DIFF)
#endif /* (L0__SIO_CFG) */

/* Interrupt Registers */
#if defined(L0__INTSTAT)
    #define L0_INTSTAT            (* (reg8 *) L0__INTSTAT)
    #define L0_SNAP               (* (reg8 *) L0__SNAP)
    
	#define L0_0_INTTYPE_REG 		(* (reg8 *) L0__0__INTTYPE)
#endif /* (L0__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_L0_H */


/* [] END OF FILE */
