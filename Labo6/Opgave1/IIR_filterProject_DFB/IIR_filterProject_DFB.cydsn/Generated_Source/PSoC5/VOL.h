/*******************************************************************************
* File Name: VOL.h
* Version 3.0
*
* Description:
*  This file contains the function prototypes and constants used in
*  the Successive approximation ADC Component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/


#if !defined(CY_ADC_SAR_VOL_H) /* CY_ADC_SAR_VOL_H */
#define CY_ADC_SAR_VOL_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component ADC_SAR_v3_0 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*      Data Struct Definition
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 enableState;
} VOL_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

void VOL_Start(void);
void VOL_Stop(void);
void VOL_SetPower(uint8 power);
void VOL_SetResolution(uint8 resolution);

uint8 VOL_IsEndConversion(uint8 retMode);
int8 VOL_GetResult8(void);
int16 VOL_GetResult16(void);

void VOL_SetOffset(int16 offset);
void VOL_SetScaledGain(int32 adcGain);
int16 VOL_CountsTo_mVolts(int16 adcCounts);
int32 VOL_CountsTo_uVolts(int16 adcCounts);
float32 VOL_CountsTo_Volts(int16 adcCounts);

void VOL_Init(void);
void VOL_Enable(void);

void VOL_SaveConfig(void);
void VOL_RestoreConfig(void);
void VOL_Sleep(void);
void VOL_Wakeup(void);

CY_ISR_PROTO( VOL_ISR );

/* Obsolete API for backward compatibility.
*  Should not be used in new designs.
*/
void VOL_SetGain(int16 adcGain);


/***************************************
* Global variables external identifier
***************************************/

extern uint8 VOL_initVar;
extern volatile int16 VOL_offset;
extern volatile int16 VOL_countsPerVolt; /* Obsolete variable, do not modify in new design */
extern volatile int32 VOL_countsPer10Volt;
extern volatile int16 VOL_shift;


/**************************************
*           API Constants
**************************************/

/* Resolution setting constants  */
#define VOL__BITS_12 12
#define VOL__BITS_10 10
#define VOL__BITS_8 8


/*   Constants for IsEndConversion() "retMode" parameter  */
#define VOL_RETURN_STATUS              (0x01u)
#define VOL_WAIT_FOR_RESULT            (0x00u)

/* Constants for SetPower(power), "power" paramter */
#define VOL__HIGHPOWER 0
#define VOL__MEDPOWER 1
#define VOL__LOWPOWER 2
#define VOL__MINPOWER 3

#define VOL_SAR_API_POWER_MASK         (0x03u)

/* Constants for Sleep mode states */
#define VOL_STARTED                    (0x02u)
#define VOL_ENABLED                    (0x01u)
#define VOL_DISABLED                   (0x00u)

#define VOL_MAX_FREQUENCY              (18000000)       /* 18Mhz */

#define VOL_10V_COUNTS                 (10.0F)
#define VOL_10MV_COUNTS                (10000)
#define VOL_10UV_COUNTS                (10000000L)



/**************************************
*    Enumerated Types and Parameters
**************************************/

/*  Reference constants */
#define VOL__INT_REF_NOT_BYPASSED 0
#define VOL__INT_REF_BYPASS 1
#define VOL__EXT_REF 2

/*  Input Range setting constants */
#define VOL__VSS_TO_VREF 0
#define VOL__VSSA_TO_VDDA 1
#define VOL__VSSA_TO_VDAC 2
#define VOL__VNEG_VREF_DIFF 3
#define VOL__VNEG_VDDA_DIFF 4
#define VOL__VNEG_VDDA_2_DIFF 5
#define VOL__VNEG_VDAC_DIFF 6

/*  Sample Mode setting constants */
#define VOL__FREERUNNING 0
#define VOL__TRIGGERED 1

/*  Extended Sample Mode setting constants */
#define VOL__FREE_RUNNING 0
#define VOL__SOFTWARE_TRIGGER 1
#define VOL__HARDWARE_TRIGGER 2

/*  Clock Source setting constants */
#define VOL__INTERNAL 1
#define VOL__EXTERNAL 0



/**************************************
*    Initial Parameter Constants
**************************************/

/* Default config values from user parameters */
#define VOL_DEFAULT_RESOLUTION     (8u)   /* ADC resolution selected with parameters.*/
#define VOL_DEFAULT_CONV_MODE      (0u)        /* Default conversion method */
#define VOL_DEFAULT_INTERNAL_CLK   (1u)             /* Default clock selection */
#define VOL_DEFAULT_REFERENCE      (0u)         /* Default reference */
#define VOL_DEFAULT_RANGE          (1u)       /* ADC Input Range selection */
#define VOL_CLOCK_FREQUENCY        (1599996u)   /* Clock frequency */
#define VOL_NOMINAL_CLOCK_FREQ     (1591837)  /* Nominal Clock Frequency */
#define VOL_HIGH_POWER_PULSE       (1u)        /* Not zero when clock pulse > 50 ns */
#define VOL_IRQ_REMOVE             (0u)                /* Removes internal interrupt */

/* Use VDDA voltage define directly from cyfitter.h when VDDA reference has been used */
#define VOL_DEFAULT_REF_VOLTAGE \
                                   (((VOL_DEFAULT_REFERENCE != (uint8)VOL__EXT_REF) && \
                                    ((VOL_DEFAULT_RANGE == (uint8)VOL__VSSA_TO_VDDA) || \
                                     (VOL_DEFAULT_RANGE == (uint8)VOL__VNEG_VDDA_2_DIFF))) ? \
                                     (CYDEV_VDDA / 2) : \
                                   (((VOL_DEFAULT_REFERENCE != (uint8)VOL__EXT_REF) && \
                                     (VOL_DEFAULT_RANGE == (uint8)VOL__VNEG_VDDA_2_DIFF)) ? \
                                     CYDEV_VDDA : (2.5)))      /* ADC reference voltage. */
#define VOL_DEFAULT_REF_VOLTAGE_MV \
                                   (((VOL_DEFAULT_REFERENCE != (uint8)VOL__EXT_REF) && \
                                    ((VOL_DEFAULT_RANGE == (uint8)VOL__VSSA_TO_VDDA) || \
                                     (VOL_DEFAULT_RANGE == (uint8)VOL__VNEG_VDDA_2_DIFF))) ? \
                                     (CYDEV_VDDA_MV / 2) : \
                                  (((VOL_DEFAULT_REFERENCE != (uint8)VOL__EXT_REF) && \
                                    (VOL_DEFAULT_RANGE == (uint8)VOL__VNEG_VDDA_2_DIFF)) ? \
                                     CYDEV_VDDA_MV : (2500)))   /* ADC reference voltage in mV */
/* The power is set to normal power, 1/2, 1/4 power depend on the clock setting. */
#define VOL_DEFAULT_POWER \
       ((VOL_NOMINAL_CLOCK_FREQ > (VOL_MAX_FREQUENCY / 4)) ? VOL__HIGHPOWER : \
       ((VOL_NOMINAL_CLOCK_FREQ > (VOL_MAX_FREQUENCY / 8)) ? VOL__MEDPOWER : \
                                                                                       VOL__MINPOWER))
/* Constant for a global usage */
/* Number of additional clocks for sampling data*/
#define VOL_SAMPLE_PRECHARGE       (4u)


/***************************************
*    Optional Function Prototypes
***************************************/

#if(VOL_DEFAULT_CONV_MODE != VOL__HARDWARE_TRIGGER)
    void VOL_StartConvert(void);
    void VOL_StopConvert(void);
#endif /* End VOL_DEFAULT_CONV_MODE != VOL__HARDWARE_TRIGGER */


/***************************************
*              Registers
***************************************/

#define VOL_SAR_TR0_REG                (* (reg8 *) VOL_ADC_SAR__TR0 )
#define VOL_SAR_TR0_PTR                (  (reg8 *) VOL_ADC_SAR__TR0 )
#define VOL_SAR_CSR0_REG               (* (reg8 *) VOL_ADC_SAR__CSR0 )
#define VOL_SAR_CSR0_PTR               (  (reg8 *) VOL_ADC_SAR__CSR0 )
#define VOL_SAR_CSR1_REG               (* (reg8 *) VOL_ADC_SAR__CSR1 )
#define VOL_SAR_CSR1_PTR               (  (reg8 *) VOL_ADC_SAR__CSR1 )
#define VOL_SAR_CSR2_REG               (* (reg8 *) VOL_ADC_SAR__CSR2 )
#define VOL_SAR_CSR2_PTR               (  (reg8 *) VOL_ADC_SAR__CSR2 )
#define VOL_SAR_CSR3_REG               (* (reg8 *) VOL_ADC_SAR__CSR3 )
#define VOL_SAR_CSR3_PTR               (  (reg8 *) VOL_ADC_SAR__CSR3 )
#define VOL_SAR_CSR4_REG               (* (reg8 *) VOL_ADC_SAR__CSR4 )
#define VOL_SAR_CSR4_PTR               (  (reg8 *) VOL_ADC_SAR__CSR4 )
#define VOL_SAR_CSR5_REG               (* (reg8 *) VOL_ADC_SAR__CSR5 )
#define VOL_SAR_CSR5_PTR               (  (reg8 *) VOL_ADC_SAR__CSR5 )
#define VOL_SAR_CSR6_REG               (* (reg8 *) VOL_ADC_SAR__CSR6 )
#define VOL_SAR_CSR6_PTR               (  (reg8 *) VOL_ADC_SAR__CSR6 )
#define VOL_SAR_SW0_REG                (* (reg8 *) VOL_ADC_SAR__SW0 )
#define VOL_SAR_SW0_PTR                (  (reg8 *) VOL_ADC_SAR__SW0 )
#define VOL_SAR_SW2_REG                (* (reg8 *) VOL_ADC_SAR__SW2 )
#define VOL_SAR_SW2_PTR                (  (reg8 *) VOL_ADC_SAR__SW2 )
#define VOL_SAR_SW3_REG                (* (reg8 *) VOL_ADC_SAR__SW3 )
#define VOL_SAR_SW3_PTR                (  (reg8 *) VOL_ADC_SAR__SW3 )
#define VOL_SAR_SW4_REG                (* (reg8 *) VOL_ADC_SAR__SW4 )
#define VOL_SAR_SW4_PTR                (  (reg8 *) VOL_ADC_SAR__SW4 )
#define VOL_SAR_SW6_REG                (* (reg8 *) VOL_ADC_SAR__SW6 )
#define VOL_SAR_SW6_PTR                (  (reg8 *) VOL_ADC_SAR__SW6 )
#define VOL_SAR_CLK_REG                (* (reg8 *) VOL_ADC_SAR__CLK )
#define VOL_SAR_CLK_PTR                (  (reg8 *) VOL_ADC_SAR__CLK )
#define VOL_SAR_WRK0_REG               (* (reg8 *) VOL_ADC_SAR__WRK0 )
#define VOL_SAR_WRK0_PTR               (  (reg8 *) VOL_ADC_SAR__WRK0 )
#define VOL_SAR_WRK1_REG               (* (reg8 *) VOL_ADC_SAR__WRK1 )
#define VOL_SAR_WRK1_PTR               (  (reg8 *) VOL_ADC_SAR__WRK1 )
#define VOL_SAR_WRK_PTR                (  (reg16 *) VOL_ADC_SAR__WRK0 )
#define VOL_PWRMGR_SAR_REG             (* (reg8 *) VOL_ADC_SAR__PM_ACT_CFG )
#define VOL_PWRMGR_SAR_PTR             (  (reg8 *) VOL_ADC_SAR__PM_ACT_CFG )
#define VOL_STBY_PWRMGR_SAR_REG        (* (reg8 *) VOL_ADC_SAR__PM_STBY_CFG )
#define VOL_STBY_PWRMGR_SAR_PTR        (  (reg8 *) VOL_ADC_SAR__PM_STBY_CFG )

/* renamed registers for backward compatible */
#define VOL_SAR_WRK0                   VOL_SAR_WRK0_REG
#define VOL_SAR_WRK1                   VOL_SAR_WRK1_REG

/* This is only valid if there is an internal clock */
#if(VOL_DEFAULT_INTERNAL_CLK)
    /* Clock Power manager Reg */
    #define VOL_PWRMGR_CLK_REG         (* (reg8 *) VOL_theACLK__PM_ACT_CFG )
    #define VOL_PWRMGR_CLK_PTR         (  (reg8 *) VOL_theACLK__PM_ACT_CFG )
    #define VOL_STBY_PWRMGR_CLK_REG    (* (reg8 *) VOL_theACLK__PM_STBY_CFG )
    #define VOL_STBY_PWRMGR_CLK_PTR    (  (reg8 *) VOL_theACLK__PM_STBY_CFG )
#endif /*End VOL_DEFAULT_INTERNAL_CLK */


/**************************************
*       Register Constants
**************************************/
/* PM_ACT_CFG (Active Power Mode CFG Register) Power enable mask */
#define VOL_ACT_PWR_SAR_EN             (uint8)(VOL_ADC_SAR__PM_ACT_MSK)

/* PM_STBY_CFG (Alternate Active Power Mode CFG Register) Power enable mask */
#define VOL_STBY_PWR_SAR_EN            (uint8)(VOL_ADC_SAR__PM_STBY_MSK)

/* This is only valid if there is an internal clock */
#if(VOL_DEFAULT_INTERNAL_CLK)
    /* Power enable mask */
    #define VOL_ACT_PWR_CLK_EN         (uint8)(VOL_theACLK__PM_ACT_MSK)
    /* Standby power enable mask */
    #define VOL_STBY_PWR_CLK_EN        (uint8)(VOL_theACLK__PM_STBY_MSK)
#endif /*End VOL_DEFAULT_INTERNAL_CLK */

#if(VOL_IRQ_REMOVE == 0u)

    /* Priority of the ADC_SAR_IRQ interrupt. */
    #define VOL_INTC_PRIOR_NUMBER          (uint8)(VOL_IRQ__INTC_PRIOR_NUM)

    /* ADC_SAR_IRQ interrupt number */
    #define VOL_INTC_NUMBER                (uint8)(VOL_IRQ__INTC_NUMBER)

#endif   /* End VOL_IRQ_REMOVE */


/******************************************/
/* SAR.TR0 Trim Register 0 definitions    */
/******************************************/

/* Bit Field  SAR_CAP_TRIM_ENUM */
#define VOL_SAR_CAP_TRIM_MASK          (0x07u)
#define VOL_SAR_CAP_TRIM_0             (0x00u)    /*decrease attenuation capacitor by 0*/
#define VOL_SAR_CAP_TRIM_1             (0x01u)    /*decrease by 0.5 LSB*/
#define VOL_SAR_CAP_TRIM_2             (0x02u)    /*decrease by 2*0.5 LSB = 1 LSB*/
#define VOL_SAR_CAP_TRIM_3             (0x03u)    /*decrease by 3*0.5 LSB = 1.5 LSB*/
#define VOL_SAR_CAP_TRIM_4             (0x04u)    /*decrease by 4*0.5 LSB = 2 LSB*/
#define VOL_SAR_CAP_TRIM_5             (0x05u)    /*decrease by 5*0.5 LSB = 2.5 LSB*/
#define VOL_SAR_CAP_TRIM_6             (0x06u)    /*decrease by 6*0.5 LSB = 3 LSB*/
#define VOL_SAR_CAP_TRIM_7             (0x07u)    /*decrease by 7*0.5 LSB = 3.5 LSB*/

#define VOL_SAR_TRIMUNIT               (0x08u)    /*Increase by 6fF*/

/*******************************************************/
/* SAR.CSR0 Satatus and Control Register 0 definitions */
/*******************************************************/

/* Bit Field  SAR_ICONT_LV_ENUM */
#define VOL_SAR_POWER_MASK             (0xC0u)
#define VOL_SAR_POWER_SHIFT            (0x06u)
#define VOL_ICONT_LV_0                 (0x00u)
#define VOL_ICONT_LV_1                 (0x40u)
#define VOL_ICONT_LV_2                 (0x80u)
#define VOL_ICONT_LV_3                 (0xC0u)
#define VOL_ICONT_FULL_CURRENT         (0x00u)

/* Bit Field SAR_RESET_SOFT_ENUM */
#define VOL_SAR_RESET_SOFT_NOTACTIVE   (0x00u)
#define VOL_SAR_RESET_SOFT_ACTIVE      (0x20u)

/* Bit Field  SAR_COHERENCY_EN_ENUM */
#define VOL_SAR_COHERENCY_EN_NOLOCK    (0x00u)
#define VOL_SAR_COHERENCY_EN_LOCK      (0x10u)

/* Bit Field  SAR_HIZ_ENUM */
#define VOL_SAR_HIZ_RETAIN             (0x00u)
#define VOL_SAR_HIZ_CLEAR              (0x08u)

/* Bit Field SAR_MX_SOF_ENUM */
#define VOL_SAR_MX_SOF_BIT             (0x00u)
#define VOL_SAR_MX_SOF_UDB             (0x04u)

/* Bit Field SAR_SOF_MODE_ENUM */
#define VOL_SAR_SOF_MODE_LEVEL         (0x00u)
#define VOL_SAR_SOF_MODE_EDGE          (0x02u)

/* Bit Field SAR_SOF_BIT_ENUM */
#define VOL_SAR_SOF_STOP_CONV          (0x00u)            /* Disable conversion */
#define VOL_SAR_SOF_START_CONV         (0x01u)            /* Enable conversion */

/*******************************************************/
/* SAR.CSR1 Satatus and Control Register 1 definitions */
/*******************************************************/

/* Bit Field  SAR_MUXREF_ENUM */
#define VOL_SAR_MUXREF_MASK            (0xE0u)
#define VOL_SAR_MUXREF_NONE            (0x00u)
#define VOL_SAR_MUXREF_VDDA_2          (0x40u)
#define VOL_SAR_MUXREF_DAC             (0x60u)
#define VOL_SAR_MUXREF_1_024V          (0x80u)
#define VOL_SAR_MUXREF_1_20V           (0xA0u)

/* Bit Field  SAR_SWVP_SRC_ENUM */
#define VOL_SAR_SWVP_SRC_REG           (0x00u)
#define VOL_SAR_SWVP_SRC_UDB           (0x10u)

/* Bit Field  SAR_SWVP_SRC_ENUM */
#define VOL_SAR_SWVN_SRC_REG           (0x00u)
#define VOL_SAR_SWVN_SRC_UDB           (0x08u)

/* Bit Field  SAR_IRQ_MODE_ENUM */
#define VOL_SAR_IRQ_MODE_LEVEL         (0x00u)
#define VOL_SAR_IRQ_MODE_EDGE          (0x04u)

/* Bit Field  SAR_IRQ_MASK_ENUM */
#define VOL_SAR_IRQ_MASK_DIS           (0x00u)
#define VOL_SAR_IRQ_MASK_EN            (0x02u)

/* Bit Field  SAR_EOF_ENUM */
#define VOL_SAR_EOF_0                  (0x00u)
#define VOL_SAR_EOF_1                  (0x01u)

/*******************************************************/
/* SAR.CSR2 Satatus and Control Register 2 definitions */
/*******************************************************/

/* Bit Field  SAR_RESOLUTION_ENUM */
#define VOL_SAR_RESOLUTION_MASK        (0xC0u)
#define VOL_SAR_RESOLUTION_SHIFT       (0x06u)
#define VOL_SAR_RESOLUTION_12BIT       (0xC0u)
#define VOL_SAR_RESOLUTION_10BIT       (0x80u)
#define VOL_SAR_RESOLUTION_8BIT        (0x40u)

/* Bit Field SAR_SAMPLE_WIDTH_ENUM */
#define VOL_SAR_SAMPLE_WIDTH_MASK      (0x3Fu)
#define VOL_SAR_SAMPLE_WIDTH_MIN       (0x00u)   /* minimum sample time: +1 clock cycle */
#define VOL_SAR_SAMPLE_WIDTH           (VOL_SAMPLE_PRECHARGE - 0x02u)
#define VOL_SAR_SAMPLE_WIDTH_MAX       (0x07u)   /* maximum sample time: +8 clock cycles */

/*******************************************************/
/* SAR.CSR3 Satatus and Control Register 3 definitions */
/*******************************************************/

/* Bit Field  SAR_EN_CP_ENUM */
#define VOL_SAR_EN_CP_DIS              (0x00u)
#define VOL_SAR_EN_CP_EN               (0x80u)

/* Bit Field  SAR_EN_RESVDA_ENUM */
#define VOL_SAR_EN_RESVDA_DIS          (0x00u)
#define VOL_SAR_EN_RESVDA_EN           (0x40u)

/* Bit Field  SAR_PWR_CTRL_VCM_ENUM */
#define VOL_SAR_PWR_CTRL_VCM_MASK      (0x30u)
#define VOL_SAR_PWR_CTRL_VCM_0         (0x00u)
#define VOL_SAR_PWR_CTRL_VCM_1         (0x10u)
#define VOL_SAR_PWR_CTRL_VCM_2         (0x20u)
#define VOL_SAR_PWR_CTRL_VCM_3         (0x30u)

/* Bit Field  SAR_PWR_CTRL_VREF_ENUM */
#define VOL_SAR_PWR_CTRL_VREF_MASK     (0x0Cu)
#define VOL_SAR_PWR_CTRL_VREF_0        (0x00u)
#define VOL_SAR_PWR_CTRL_VREF_DIV_BY2  (0x04u)
#define VOL_SAR_PWR_CTRL_VREF_DIV_BY3  (0x08u)
#define VOL_SAR_PWR_CTRL_VREF_DIV_BY4  (0x0Cu)

/* Bit Field  SAR_EN_BUF_VCM_ENUM */
#define VOL_SAR_EN_BUF_VCM_DIS         (0x00u)
#define VOL_SAR_EN_BUF_VCM_EN          (0x02u)

/* Bit Field  SAR_EN_BUF_VREF_ENUM */
#define VOL_SAR_EN_BUF_VREF_DIS        (0x00u)
#define VOL_SAR_EN_BUF_VREF_EN         (0x01u)

/*******************************************************/
/* SAR.CSR4 Satatus and Control Register 4 definitions */
/*******************************************************/

/* Bit Field  SAR_DFT_INC_ENUM */
#define VOL_SAR_DFT_INC_MASK           (0x0Fu)
#define VOL_SAR_DFT_INC_DIS            (0x00u)
#define VOL_SAR_DFT_INC_EN             (0x0Fu)

/* Bit Field  SAR_DFT_INC_ENUM */
#define VOL_SAR_DFT_OUTC_MASK          (0x70u)
#define VOL_SAR_DFT_OUTC_DIS           (0x00u)
#define VOL_SAR_DFT_OUTC_EN            (0x70u)

/*******************************************************/
/* SAR.CSR5 Satatus and Control Register 5 definitions */
/*******************************************************/

/* Bit Field  SAR_OVERRUN_DET_EN_ENUM */
#define VOL_SAR_OVERRUN_DET_EN_EN      (0x80u)

/* Bit Field  SAR_DLY_INC_ENUM */
#define VOL_SAR_DLY_INC                (0x40u)

/* Bit Field  SAR_DCEN_ENUM */
#define VOL_SAR_DCEN                   (0x20u)

/* Bit Field  SAR_EN_CSEL_DFT_ENUM */
#define VOL_SAR_EN_CSEL_DFT_DISABLED   (0x00u)
#define VOL_SAR_EN_CSEL_DFT_ENABLED    (0x10u)

/* Bit Field  SAR_SEL_CSEL_DFT_ENUM */
#define VOL_SAR_SEL_CSEL_DFT_MASK      (0x0Fu)
#define VOL_SAR_SEL_CSEL_DFT_MIN       (0x00u)
#define VOL_SAR_SEL_CSEL_DFT_MAX       (0x0Fu)
#define VOL_SAR_SEL_CSEL_DFT_CHAR      (0x03u)

/*******************************************************/
/* SAR.CSR6 Satatus and Control Register 6 definitions */
/*******************************************************/
#define VOL_INT_VREF                   (0x18u)
#define VOL_INT_BYPASS_EXT_VREF        (0x04u)
#define VOL_VDDA_VREF                  (0x80u)

/*******************************************************/
/* SAR.CSR7 Satatus and Control Register 7 definitions */
/*******************************************************/

/* Bit Field  SAR_REF_S_ENUM */
#define VOL_SAR_REF_S_MSB_MASK         (0x3Fu)
#define VOL_SAR_REF_S_MSB_DIS          (0x00u)
#define VOL_SAR_REF_S8_MSB_DIS         (0x01u)
#define VOL_SAR_REF_S9_MSB_EN          (0x02u)
#define VOL_SAR_REF_S10_MSB_EN         (0x04u)
#define VOL_SAR_REF_S11_MSB_EN         (0x08u)
#define VOL_SAR_REF_S12_MSB_EN         (0x10u)
#define VOL_SAR_REF_S13_MSB_EN         (0x20u)

/*******************************************************/
/* SAR.CLK SAR Clock Selection Register definitions    */
/*******************************************************/

/* Bit Field  MX_PUMPCLK_ENUM */
#define VOL_SAR_MX_PUMPCLK_MASK        (0xE0u)
#define VOL_SAR_MX_PUMPCLK_0           (0x00u)
#define VOL_SAR_MX_PUMPCLK_1           (0x20u)
#define VOL_SAR_MX_PUMPCLK_2           (0x40u)
#define VOL_SAR_MX_PUMPCLK_3           (0x60u)
#define VOL_SAR_MX_PUMPCLK_4           (0x80u)

/* Bit Field  BYPASS_SYNC_ENUM */
#define VOL_SAR_BYPASS_SYNC_0          (0x00u)
#define VOL_SAR_BYPASS_SYNC_1          (0x10u)

/* Bit Field  MX_CLK_EN_ENUM */
#define VOL_SAR_MX_CLK_EN              (0x08u)

/* Bit Field  MX_CLK_ENUM  */
#define VOL_SAR_MX_CLK_MASK            (0x07u)
#define VOL_SAR_MX_CLK_0               (0x00u)
#define VOL_SAR_MX_CLK_1               (0x01u)
#define VOL_SAR_MX_CLK_2               (0x02u)
#define VOL_SAR_MX_CLK_3               (0x03u)
#define VOL_SAR_MX_CLK_4               (0x04u)

/*********************************************************/
/* ANAIF.WRK.SARS.SOF SAR Global Start-of-frame register */
/*********************************************************/

/* Bit Field  SAR_SOF_BIT_ENUM */
#define VOL_SAR_SOFR_BIT_MASK          (0x03u)
#define VOL_SAR_SOFR_BIT_0             (0x00u)
#define VOL_SAR_SOFR_BIT_1             (0x01u)

/***********************************************/
/* SAR.SW3 SAR Analog Routing Register 3       */
/***********************************************/
#define VOL_SAR_VP_VSSA                (0x04u)
#define VOL_SAR_VN_AMX                 (0x10u)
#define VOL_SAR_VN_VREF                (0x20u)
#define VOL_SAR_VN_VSSA                (0x40u)
#define VOL_SAR_VN_MASK                (0x60u)

/***********************************************/
/* SAR.WRKx SAR Working Register               */
/***********************************************/
#define VOL_SAR_WRK_MAX                (0xFFFu)
#define VOL_SAR_DIFF_SHIFT             (0x800u)

/* Absolute maximum counts equivalent reference voltage */
#define VOL_SAR_WRK_MAX_12BIT          (0x00001000Lu)
#define VOL_SAR_WRK_MAX_10BIT          (0x00000400Lu)
#define VOL_SAR_WRK_MAX_8BIT           (0x00000100Lu)


#endif /* End CY_ADC_SAR_VOL_H */


/* [] END OF FILE */
