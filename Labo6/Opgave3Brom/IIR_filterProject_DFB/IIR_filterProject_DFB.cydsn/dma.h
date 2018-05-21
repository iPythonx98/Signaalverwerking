/* ========================================
 *
 * I2S_dma.h
 * rev 1.6 10/2/2016
 * Piet Coussens, Odisee PBa elektronica
 *
 * Header file voor DMA van I2S-interface
 *
 * ========================================
*/
#ifndef I2S_DMA_HEADER
    #define I2S_DMA_HEADER
    
    #include <project.h>

    #define BUFFER_SIZE                 4       /* stereo = 2 samples van 16 bytes => past in 4 x uint8 */

    /* Receive & transmit buffer */
    uint8 rxBuff[BUFFER_SIZE];
    uint8 txBuff[BUFFER_SIZE];

    // Variabelen voor de audiosamples in en uit voor de berekeningen = array met LINKS en RECHTS
    int16 sampleIn[2];
    int16 sampleUit[2];

    /* Function prototypes */
    void DmaRxConfiguration(void);
    void DmaTxConfiguration(void);
    void berekenMetSamples(void);
    CY_ISR_PROTO(sampleIntRx_ISR);
    CY_ISR_PROTO(sampleIntTx_ISR);
    
#endif

/* [] END OF FILE */
