/*******************************************************************************
* File Name: SampleUitKlaar.h
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
#if !defined(CY_ISR_SampleUitKlaar_H)
#define CY_ISR_SampleUitKlaar_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SampleUitKlaar_Start(void);
void SampleUitKlaar_StartEx(cyisraddress address);
void SampleUitKlaar_Stop(void);

CY_ISR_PROTO(SampleUitKlaar_Interrupt);

void SampleUitKlaar_SetVector(cyisraddress address);
cyisraddress SampleUitKlaar_GetVector(void);

void SampleUitKlaar_SetPriority(uint8 priority);
uint8 SampleUitKlaar_GetPriority(void);

void SampleUitKlaar_Enable(void);
uint8 SampleUitKlaar_GetState(void);
void SampleUitKlaar_Disable(void);

void SampleUitKlaar_SetPending(void);
void SampleUitKlaar_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SampleUitKlaar ISR. */
#define SampleUitKlaar_INTC_VECTOR            ((reg32 *) SampleUitKlaar__INTC_VECT)

/* Address of the SampleUitKlaar ISR priority. */
#define SampleUitKlaar_INTC_PRIOR             ((reg8 *) SampleUitKlaar__INTC_PRIOR_REG)

/* Priority of the SampleUitKlaar interrupt. */
#define SampleUitKlaar_INTC_PRIOR_NUMBER      SampleUitKlaar__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SampleUitKlaar interrupt. */
#define SampleUitKlaar_INTC_SET_EN            ((reg32 *) SampleUitKlaar__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SampleUitKlaar interrupt. */
#define SampleUitKlaar_INTC_CLR_EN            ((reg32 *) SampleUitKlaar__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SampleUitKlaar interrupt state to pending. */
#define SampleUitKlaar_INTC_SET_PD            ((reg32 *) SampleUitKlaar__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SampleUitKlaar interrupt. */
#define SampleUitKlaar_INTC_CLR_PD            ((reg32 *) SampleUitKlaar__INTC_CLR_PD_REG)


#endif /* CY_ISR_SampleUitKlaar_H */


/* [] END OF FILE */
