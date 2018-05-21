/*******************************************************************************
* File Name: SampleInKlaar.h
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
#if !defined(CY_ISR_SampleInKlaar_H)
#define CY_ISR_SampleInKlaar_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SampleInKlaar_Start(void);
void SampleInKlaar_StartEx(cyisraddress address);
void SampleInKlaar_Stop(void);

CY_ISR_PROTO(SampleInKlaar_Interrupt);

void SampleInKlaar_SetVector(cyisraddress address);
cyisraddress SampleInKlaar_GetVector(void);

void SampleInKlaar_SetPriority(uint8 priority);
uint8 SampleInKlaar_GetPriority(void);

void SampleInKlaar_Enable(void);
uint8 SampleInKlaar_GetState(void);
void SampleInKlaar_Disable(void);

void SampleInKlaar_SetPending(void);
void SampleInKlaar_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SampleInKlaar ISR. */
#define SampleInKlaar_INTC_VECTOR            ((reg32 *) SampleInKlaar__INTC_VECT)

/* Address of the SampleInKlaar ISR priority. */
#define SampleInKlaar_INTC_PRIOR             ((reg8 *) SampleInKlaar__INTC_PRIOR_REG)

/* Priority of the SampleInKlaar interrupt. */
#define SampleInKlaar_INTC_PRIOR_NUMBER      SampleInKlaar__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SampleInKlaar interrupt. */
#define SampleInKlaar_INTC_SET_EN            ((reg32 *) SampleInKlaar__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SampleInKlaar interrupt. */
#define SampleInKlaar_INTC_CLR_EN            ((reg32 *) SampleInKlaar__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SampleInKlaar interrupt state to pending. */
#define SampleInKlaar_INTC_SET_PD            ((reg32 *) SampleInKlaar__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SampleInKlaar interrupt. */
#define SampleInKlaar_INTC_CLR_PD            ((reg32 *) SampleInKlaar__INTC_CLR_PD_REG)


#endif /* CY_ISR_SampleInKlaar_H */


/* [] END OF FILE */
