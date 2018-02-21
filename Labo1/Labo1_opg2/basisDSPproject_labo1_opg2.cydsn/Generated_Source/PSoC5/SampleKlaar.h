/*******************************************************************************
* File Name: SampleKlaar.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_SampleKlaar_H)
#define CY_ISR_SampleKlaar_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SampleKlaar_Start(void);
void SampleKlaar_StartEx(cyisraddress address);
void SampleKlaar_Stop(void);

CY_ISR_PROTO(SampleKlaar_Interrupt);

void SampleKlaar_SetVector(cyisraddress address);
cyisraddress SampleKlaar_GetVector(void);

void SampleKlaar_SetPriority(uint8 priority);
uint8 SampleKlaar_GetPriority(void);

void SampleKlaar_Enable(void);
uint8 SampleKlaar_GetState(void);
void SampleKlaar_Disable(void);

void SampleKlaar_SetPending(void);
void SampleKlaar_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SampleKlaar ISR. */
#define SampleKlaar_INTC_VECTOR            ((reg32 *) SampleKlaar__INTC_VECT)

/* Address of the SampleKlaar ISR priority. */
#define SampleKlaar_INTC_PRIOR             ((reg8 *) SampleKlaar__INTC_PRIOR_REG)

/* Priority of the SampleKlaar interrupt. */
#define SampleKlaar_INTC_PRIOR_NUMBER      SampleKlaar__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SampleKlaar interrupt. */
#define SampleKlaar_INTC_SET_EN            ((reg32 *) SampleKlaar__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SampleKlaar interrupt. */
#define SampleKlaar_INTC_CLR_EN            ((reg32 *) SampleKlaar__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SampleKlaar interrupt state to pending. */
#define SampleKlaar_INTC_SET_PD            ((reg32 *) SampleKlaar__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SampleKlaar interrupt. */
#define SampleKlaar_INTC_CLR_PD            ((reg32 *) SampleKlaar__INTC_CLR_PD_REG)


#endif /* CY_ISR_SampleKlaar_H */


/* [] END OF FILE */
