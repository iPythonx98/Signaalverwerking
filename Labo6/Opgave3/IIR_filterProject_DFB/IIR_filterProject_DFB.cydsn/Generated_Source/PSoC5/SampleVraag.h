/*******************************************************************************
* File Name: SampleVraag.h
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
#if !defined(CY_ISR_SampleVraag_H)
#define CY_ISR_SampleVraag_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void SampleVraag_Start(void);
void SampleVraag_StartEx(cyisraddress address);
void SampleVraag_Stop(void);

CY_ISR_PROTO(SampleVraag_Interrupt);

void SampleVraag_SetVector(cyisraddress address);
cyisraddress SampleVraag_GetVector(void);

void SampleVraag_SetPriority(uint8 priority);
uint8 SampleVraag_GetPriority(void);

void SampleVraag_Enable(void);
uint8 SampleVraag_GetState(void);
void SampleVraag_Disable(void);

void SampleVraag_SetPending(void);
void SampleVraag_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the SampleVraag ISR. */
#define SampleVraag_INTC_VECTOR            ((reg32 *) SampleVraag__INTC_VECT)

/* Address of the SampleVraag ISR priority. */
#define SampleVraag_INTC_PRIOR             ((reg8 *) SampleVraag__INTC_PRIOR_REG)

/* Priority of the SampleVraag interrupt. */
#define SampleVraag_INTC_PRIOR_NUMBER      SampleVraag__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable SampleVraag interrupt. */
#define SampleVraag_INTC_SET_EN            ((reg32 *) SampleVraag__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the SampleVraag interrupt. */
#define SampleVraag_INTC_CLR_EN            ((reg32 *) SampleVraag__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the SampleVraag interrupt state to pending. */
#define SampleVraag_INTC_SET_PD            ((reg32 *) SampleVraag__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the SampleVraag interrupt. */
#define SampleVraag_INTC_CLR_PD            ((reg32 *) SampleVraag__INTC_CLR_PD_REG)


#endif /* CY_ISR_SampleVraag_H */


/* [] END OF FILE */
