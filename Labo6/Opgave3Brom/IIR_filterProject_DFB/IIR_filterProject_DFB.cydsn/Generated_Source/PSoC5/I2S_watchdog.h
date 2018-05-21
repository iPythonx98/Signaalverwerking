/*******************************************************************************
* File Name: I2S_watchdog.h
* Version 1.0
*
* Description:
*  This header file contains registers and constants associated with the
*  Count7 component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_COUNT7_I2S_watchdog_H)
#define CY_COUNT7_I2S_watchdog_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Function Prototypes
***************************************/
void  I2S_watchdog_Init(void) ;
void  I2S_watchdog_Enable(void) ;
void  I2S_watchdog_Start(void) ;
void  I2S_watchdog_Stop(void) ;
void  I2S_watchdog_WriteCounter(uint8 count) ;
uint8 I2S_watchdog_ReadCounter(void) ;
void  I2S_watchdog_WritePeriod(uint8 period) ;
uint8 I2S_watchdog_ReadPeriod(void) ;
void  I2S_watchdog_SaveConfig(void) ;
void  I2S_watchdog_RestoreConfig(void) ;
void  I2S_watchdog_Sleep(void) ;
void  I2S_watchdog_Wakeup(void) ;


/***************************************
*     Data Struct Definitions
***************************************/
/* Structure to save registers before go to sleep */
typedef struct
{
    uint8 enableState;
    uint8 count;
} I2S_watchdog_BACKUP_STRUCT;


/***************************************
*           Global Variables
***************************************/
extern I2S_watchdog_BACKUP_STRUCT I2S_watchdog_backup;
extern uint8 I2S_watchdog_initVar;


/***************************************
* Initial Parameter
***************************************/
#define I2S_watchdog_INITIAL_PERIOD               (127u)


/***************************************
* Registers
***************************************/
#define I2S_watchdog_COUNT_REG                    (*(reg8 *) I2S_watchdog_Counter7__COUNT_REG)
#define I2S_watchdog_COUNT_PTR                    ( (reg8 *) I2S_watchdog_Counter7__COUNT_REG)
#define I2S_watchdog_PERIOD_REG                   (*(reg8 *) I2S_watchdog_Counter7__PERIOD_REG)
#define I2S_watchdog_PERIOD_PTR                   ( (reg8 *) I2S_watchdog_Counter7__PERIOD_REG)
#define I2S_watchdog_AUX_CONTROL_REG              (*(reg8 *) I2S_watchdog_Counter7__CONTROL_AUX_CTL_REG)
#define I2S_watchdog_AUX_CONTROL_PTR              ( (reg8 *) I2S_watchdog_Counter7__CONTROL_AUX_CTL_REG)


/***************************************
* Register Constants
***************************************/
#define I2S_watchdog_COUNTER_START                (0x20u)

/* This constant is used to mask the TC bit (bit#7) in the Count register */
#define I2S_watchdog_COUNT_7BIT_MASK              (0x7Fu)


#endif /* CY_COUNT7_I2S_watchdog_H */


/* [] END OF FILE */
