/* ========================================
 *
 * dspSystem.h
 * rev 1.6 10/2/2016
 * Piet Coussens, Odisee PBa elektronica
 *
 * Systeem definities voor het DSP-systeem
 *
 * ========================================
 */

#ifndef DSP_SYSTEM_HEADER
    #define DSP_SYSTEM_HEADER

/****************************************************
 * Instellingen voor de clip-indicator
 ****************************************************/
    #define CLIPnTIME                   1       /* CLIP toont clip-niveau als 1, interrupt servicetijd als 0 */
    #define CLIP_LEVEL                  120     /* CLIP-indicator: als hoogste byte te groot => clip tonen (max 127) */

/****************************************************
 * Instellingen voor de audio-codec
 ****************************************************/
    #define I2C_CODEC_ADDRESS       (0x1A)      /* Het I2C Slave adres van de Wolfson-codec is 1A */
    #define LINKS                       0
    #define RECHTS                      1

/****************************************************
 * macro's
 ****************************************************/
    #define MIN(a,b) ((a) < (b) ? a : b)
    #define MAX(a,b) ((a) > (b) ? a : b)
    #define ABS(a) ((a) < 0 ? -a : a)

#endif    
/* [] END OF FILE */
