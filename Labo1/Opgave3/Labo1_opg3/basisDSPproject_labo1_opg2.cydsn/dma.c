/* ========================================
 *
 * File: dma.c
 * rev 1.6 10/2/2016
 * Piet Coussens, Odisee PBa elektronica
 * Geïnspireerd op het vb-programma van Cypress
 *
 * Code file voor DMA van I2S-interface
 *
 * ========================================
*/

#include <project.h>
#include <dspSystem.h>
#include <dma.h>
#include <stdlib.h>

/* DMA Configuration for RxDMA */
#define RxDMA_BYTES_PER_BURST       (1u)
#define RxDMA_REQUEST_PER_BURST     (1u)
#define RxDMA_SRC_BASE              (CYDEV_PERIPH_BASE)
#define RxDMA_DST_BASE              (CYDEV_SRAM_BASE)

/* DMA Configuration for TxDMA */
#define TxDMA_BYTES_PER_BURST       (1u)
#define TxDMA_REQUEST_PER_BURST     (1u)
#define TxDMA_SRC_BASE              (CYDEV_SRAM_BASE)
#define TxDMA_DST_BASE              (CYDEV_PERIPH_BASE)

/* Variable declarations for RxDMA and TxDMA */
static uint8 rxDmaChan;
static uint8 rxDmaTd[1u];
static uint8 txDmaChan;
static uint8 txDmaTd[1u];

// Haal de audiosamples van de codec uit de I2S interface en stop ze in samplesIn
// Verzend de audiosamples in samplesUit via de I2S interface naar de codec
// de data komt toe in de 4-byte buffer als [3]=R_lo, [2]=R_hi, [1]=L_lo, [0]=L_hi
// plaats 0 = LINKS, plaats 1 = RECHTS

/*******************************************************************************
* Function Name: sampleIntRx_ISR - sampleIntTx_ISR
********************************************************************************
* interrupt-routines voor het ophalen en verwerken van de samples van de codec
* Parameters: None.
* Return: None.
* Uitvoeringstijd: 2,3 us voor sampleIntTx_ISR (@78 MHz) 
*                  3,0 us voor sampleIntRx_ISR (@78 MHz)
*******************************************************************************/
CY_ISR(sampleIntRx_ISR) {
    #if CLIPnTIME == 0
      CLIP_Write(1);
    #endif
    sampleIn[0] = (int16)((rxBuff[0]<<8) | rxBuff[1]);
    sampleIn[1] = (int16)((rxBuff[2]<<8) | rxBuff[3]);
    berekenMetSamples();
    #if CLIPnTIME == 0
      CLIP_Write(0);
    #else
      if((abs(sampleIn[0]>>8) > CLIP_LEVEL) || (abs(sampleIn[1]>>8) > CLIP_LEVEL))
        CLIP_Write(1);
      else
        CLIP_Write(0);
    #endif
    }

CY_ISR(sampleIntTx_ISR) {
    #if CLIPnTIME == 0
      CLIP_Write(1);
    #endif
    txBuff[0]    = (uint8)((sampleUit[0]>> 8) &0xFF);      // hoog byte links
    txBuff[1]    = (uint8)(sampleUit[0] & 0xFF);           // laag byte links
    txBuff[2]    = (uint8)((sampleUit[1]>> 8) &0xFF);      // hoog byte rechts
    txBuff[3]    = (uint8)(sampleUit[1] & 0xFF);           // laag byte rechts
    #if CLIPnTIME == 0
      CLIP_Write(0);
    #endif
    }

/*******************************************************************************
* Function Name: DmaRxConfiguration
********************************************************************************
* Configures the DMA transfer for the Rx direction.
* Parameters: None.
* Return: None.
*******************************************************************************/
void DmaRxConfiguration(void)
{
    /* Rx DMA Config
    * Init DMA, 1 byte bursts, each burst requires a request */
    rxDmaChan = RxDMA_DmaInitialize(RxDMA_BYTES_PER_BURST, RxDMA_REQUEST_PER_BURST,
                                     HI16(RxDMA_SRC_BASE), HI16(RxDMA_DST_BASE));

    rxDmaTd[0u] = CyDmaTdAllocate();
    /* Configure this Td as follows:
    *  - The TD is looping on itself
    *  - Increment the destination address, but not the source address
    */
    CyDmaTdSetConfiguration(rxDmaTd[0], BUFFER_SIZE, rxDmaTd[0u], TD_INC_DST_ADR | RxDMA__TD_TERMOUT_EN);

    /* From the I2S to the memory */
    CyDmaTdSetAddress(rxDmaTd[0u], LO16((uint32)I2S_Codec_audio_RX_CH0_F0_PTR), LO16((uint32)rxBuff));

    /* Associate the TD with the channel */
    CyDmaChSetInitialTd(rxDmaChan, rxDmaTd[0u]);

    /* Enable the channel */
    CyDmaChEnable(rxDmaChan, 1u);
}

/*******************************************************************************
* Function Name: DmaTxConfiguration
********************************************************************************
* Configures the DMA transfer for the Tx direction.
* Parameters: None.
* Return: None.
*******************************************************************************/
void DmaTxConfiguration(void)
{
     /* Tx DMA Config
    * Init DMA, 1 byte bursts, each burst requires a request
    */ 
    txDmaChan = TxDMA_DmaInitialize(TxDMA_BYTES_PER_BURST, TxDMA_REQUEST_PER_BURST, 
                                    HI16(TxDMA_SRC_BASE), HI16(TxDMA_DST_BASE));

    txDmaTd[0u] = CyDmaTdAllocate();

    /* Configure this Td chain as follows:
    *  - The TD is looping on itself
    *  - Increment the source address, but not the destination address   
    */
    CyDmaTdSetConfiguration(txDmaTd[0u], BUFFER_SIZE, txDmaTd[0u], TD_INC_SRC_ADR | TxDMA__TD_TERMOUT_EN);
    
    /* From the memory to the I2S */
    CyDmaTdSetAddress(txDmaTd[0u], LO16((uint32)txBuff), LO16((uint32)I2S_Codec_audio_TX_CH0_F0_PTR));

    /* Associate the TD with the channel */
    CyDmaChSetInitialTd(txDmaChan, txDmaTd[0u]);

    /* Enable the channel */
    CyDmaChEnable(txDmaChan, 1u);
}

/* [] END OF FILE */
