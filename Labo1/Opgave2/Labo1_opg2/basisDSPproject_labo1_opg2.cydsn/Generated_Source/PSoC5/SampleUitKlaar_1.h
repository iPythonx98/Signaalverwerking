/*******************************************************************************
* File Name: SampleUitKlaar_1.h
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
#if !defined(CY_ISR_SampleUitKlaar_1_H)
#define CY_ISR_SampleUitKlaar_1_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SampleUitKlaar_1_Start(void);
void SampleUitKlaar_1_StartEx(cyisraddress address);
void SampleUitKlaar_1_Stop(void);

CY_ISR_PROTO(SampleUitKlaar_1_Interrupt);

void SampleUitKlaar_1_SetVector(cyisraddress address);
cyisraddress SampleUitKlaar_1_GetVector(void);

void SampleUitKlaar_1_SetPriority(uint8 priority);
uint8 SampleUitKlaar_1_GetPriority(void);

void SampleUitKlaar_1_Enable(void);
uint8 SampleUitKlaar_1_GetState(void);
void SampleUitKlaar_1_Disable(void);

void SampleUitKlaar_1_SetPending(void);
void SampleUitKlaar_1_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SampleUitKlaar_1 ISR. */
#define SampleUitKlaar_1_INTC_VECTOR            ((reg32 *) SampleUitKlaar_1__INTC_VECT)

/* Address of the SampleUitKlaar_1 ISR priority. */
#define SampleUitKlaar_1_INTC_PRIOR             ((reg8 *) SampleUitKlaar_1__INTC_PRIOR_REG)

/* Priority of the SampleUitKlaar_1 interrupt. */
#define SampleUitKlaar_1_INTC_PRIOR_NUMBER      SampleUitKlaar_1__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SampleUitKlaar_1 interrupt. */
#define SampleUitKlaar_1_INTC_SET_EN            ((reg32 *) SampleUitKlaar_1__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SampleUitKlaar_1 interrupt. */
#define SampleUitKlaar_1_INTC_CLR_EN            ((reg32 *) SampleUitKlaar_1__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SampleUitKlaar_1 interrupt state to pending. */
#define SampleUitKlaar_1_INTC_SET_PD            ((reg32 *) SampleUitKlaar_1__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SampleUitKlaar_1 interrupt. */
#define SampleUitKlaar_1_INTC_CLR_PD            ((reg32 *) SampleUitKlaar_1__INTC_CLR_PD_REG)


#endif /* CY_ISR_SampleUitKlaar_1_H */


/* [] END OF FILE */
