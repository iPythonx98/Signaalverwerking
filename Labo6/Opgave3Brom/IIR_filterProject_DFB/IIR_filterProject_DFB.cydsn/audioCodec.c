/* ========================================
 *
 * AudioCodec.c
 * rev 1.6 10/2/2016
 * Piet Coussens & Rogier Delporte, 2015
 * Odisee PBa elektronica
 *
 * ========================================
*/

#include <AudioCodec.h>
#include <dspSystem.h>

#define I2C_CODEC_INIT_LENGTH   (11u)   /* lengte van de initialisatie datastructuur CodecInitData */

/* Codec initialisation data structure (always 2 bytes) */
const uint8 CodecInitData[I2C_CODEC_INIT_LENGTH][2] = {
    {RESET_Reg,0x00},
    {PWR_DWN_CTRL_Reg, 0x00},                         // Power reduction register
    {DIGI_AUDIO_INTERFACE_FORMAT_Reg, 0x02},          // Digital data format 16b I2S mode
    {LEFT_LINE_IN_Reg, (uint8) LINVOL},               // Left in setup register
    {RIGHT_LINE_IN_Reg, (uint8) RINVOL},              // right in setup register
    {LEFT_HP_OUT_Reg, (uint8) LHPVOL},                // Left headphone out setup register
    {RIGHT_HP_OUT_Reg, (uint8) RHPVOL},               // right headphone out  setup register
    {DIGI_AUDIO_PATH_CTRL_Reg, (uint8) ADCHPD},      // digital audio path configuration
    {ANAL_AUDIO_PATH_CTRL_Reg,                        // analog audio pathway configuration
        (uint8) ((SIDEATT << 6)|(SIDETONE << 5)|(DACSEL << 4)|(BYPASS << 3)|(INSEL << 2)|(MUTEMIC << 1)|(MICBOOST << 0))},      
    {SAMPLING_CTRL_Reg,                               // clock configuration
        #if SAMPLE_RATE == 88                            
        0xBC  
        #elif SAMPLE_RATE == 44
        0xA0
        #elif SAMPLE_RATE == 29
        0x9C
        #elif SAMPLE_RATE == 22
        0xE0
        #elif SAMPLE_RATE == 14
        0xE2
        #elif SAMPLE_RATE == 8
        0xAC
        #elif SAMPLE_RATE == 7
        0x8C
        #elif SAMPLE_RATE == 4
        0xEC
        #elif SAMPLE_RATE == 2
        0xCE
        #endif
    },
    {ACTIVE_CTRL_Reg, 0x01}      // Codec enable
};

/***********************************************************************************************
 * Private functie declaraties 
 ***********************************************************************************************/

// Bereken de volume-parameter voor de headphone (48-127) i.f.v. de potmeterwaarde (uint8 0-255)
// volume dient aangepast te worden als de returnwaarde van deze functie > 0;
uint8 _berekenVolumeHP(uint8 PotWaarde);

// Bereken de volume-parameter voor de line-ingang (0-31) i.f.v. de potmeterwaarde (uint8 0-255)
// zie definitie van LINVOL en RINVOC van de codec
// volume dient aangepast te worden als de returnwaarde van deze functie > 31;
uint8 _berekenVolumeLineIn(uint8 PotWaarde);

/***********************************************************************************************
 * Publieke functie Definities 
 ***********************************************************************************************/
// zend een commando naar de codec
uint8 sendCodecCommand(uint8 registerAddress, uint8 newData){
    uint8 I2CData[2];
    I2S_EN_Write(0);                            // stop I2S interface als actief
    I2C_Codec_control_MasterClearStatus();
    I2CData[0] = registerAddress; I2CData[1] = newData;
    I2C_Codec_control_MasterWriteBuf(I2C_CODEC_ADDRESS, I2CData, 2, I2C_Codec_control_MODE_COMPLETE_XFER) ;
    CyDelayUs(30);  
    I2S_EN_Write(1);                            // start I2S interface opnieuw
    return (I2C_Codec_control_MasterStatus());
}

// initialiseer de codec met de datastructuur CodecInitData[] in AudioCodec.h
uint8 initCodec() {
    uint8 temp;
    I2S_EN_Write(0);                            // stop I2S interface als actief
    for (temp = 0; temp < I2C_CODEC_INIT_LENGTH; temp++) {
        I2C_Codec_control_MasterWriteBuf(I2C_CODEC_ADDRESS, (uint8 *)CodecInitData[temp], 2, I2C_Codec_control_MODE_COMPLETE_XFER);
        // Wait for the data transfer to complete
        while(I2C_Codec_control_MasterStatus() & I2C_Codec_control_MSTAT_XFER_INP);    
        CyDelayUs(50);
        }
    I2S_EN_Write(1);                            // start I2S interface opnieuw
    return(1);
}

// stel volume van de hoofdtelefoon-uitgang in i.f.v. een 8-bits getal (van een potmeter)
uint8 StelHPvolumeIn(uint8 VolWaarde) {
    uint8 HPvolume;
    static uint8 HPvolumeUit = 0;
    HPvolume = _berekenVolumeHP(VolWaarde);                     // Bereken HPvolume a.h.v. potmeter
    if (HPvolume != 0) {
        HPvolumeUit = HPvolume;
        sendCodecCommand(LEFT_HP_OUT_Reg|1, HPvolume);          // update  HP-volume links & rechts
    }
    return (HPvolumeUit);
}

// stel het ingangsvolume van de line-in van de codec in i.f.v. een 8-bits getal (van een potmeter)
uint8 StelLineVolumeIn(uint8 VolWaarde) {
    uint8 LineVolume;
    static uint8 LineVolumeUit = 0;
    LineVolume = _berekenVolumeLineIn(VolWaarde);             // Bereken LineVolume a.h.v. potmeter
    if (LineVolume < 32) {
        LineVolumeUit = LineVolume;
         sendCodecCommand(RIGHT_LINE_IN_Reg|1, LineVolume);    // update  Line-volume links & rechts
    }
    return (LineVolumeUit);
}
// Stelt de samplerate van de codec in. Toegestane waarden voor de parameter 'sampleFreq' zijn
// 88, 44, 29, 22, 14, 8, 7, 4 en 2 (waarde in kHz). Indien de samplefrequentie niet ondersteund wordt, 
// dan wordt 0 geretourneerd, anders de waarde van sampleFreq
// opm 1: de waarde 29 lijkt niet goed te werken (werkt enkel op linker kanaal)
// opm 2: De I2S-interface moet mee aangepast worden om de juiste wordrate te houden
//      AudioCodeClock = 11,2896 MHz/2 => dus juiste deelfactor invoeren voor I2S-clock met 64 clks/word
uint8 StelSampleRateIn(uint8 sampleFreq){
    uint8 divider;
    switch (sampleFreq) {
        case 88: divider = 0xBC; break;
        case 44: divider = 0xA0; break;
        case 29: divider = 0xA2; break; 
        case 22: divider = 0xE0; break;
        case 14: divider = 0xE2; break;     
        case  8: divider = 0xAC; break;
        case  7: divider = 0x8C; break;
        case  4: divider = 0xEC; break;
        case  2: divider = 0xCE; break;
        default: return(0);
    }
    sendCodecCommand(SAMPLING_CTRL_Reg, divider);
    return(sampleFreq);
}

/***********************************************************************************************
 * Private functie Definities 
 ***********************************************************************************************/
// Bereken de volume-parameter voor de headphone (48-127) i.f.v. de potmeterwaarde (uint8 0-255)
// zie definitie van LHPVOL en RHPVOC van de codec
// volume dient aangepast te worden als de returnwaarde van deze functie > 0;
uint8 _berekenVolumeHP(uint8 PotWaarde) {
    static uint16 Volume, VolumeOud = 1000;
    if (VolumeOud > 255) 
        // Initialisatie van de routine de eerste keer
        Volume = (uint16)(PotWaarde & 0xFF);
    else
        Volume = (Volume * 31 + ((uint16)PotWaarde & 0xFF)) >> 5;
    if ((Volume - VolumeOud)!= 0) {
        VolumeOud = Volume;
        return(MIN((uint8)((Volume*90>> 8) + 49),127));              // zie def LHPVOL en RHPVOC codec
    }
    else 
        return(0);
}

// Bereken de volume-parameter voor de line-ingang (0-31) i.f.v. de potmeterwaarde (uint8 0-255)
// zie definitie van LINVOL en RINVOC van de codec
// volume dient aangepast te worden als de returnwaarde van deze functie > 31;
uint8 _berekenVolumeLineIn(uint8 PotWaarde) {
    static uint16 LVolume, LVolumeOud = 1000;
    if (LVolumeOud > 255) 
        // Initialisatie van de routine de eerste keer
        LVolume = (uint16)(PotWaarde & 0xFF);
    else
        LVolume = (LVolume * 31 + ((uint16)PotWaarde & 0xFF)) >> 5;
    if ((LVolume - LVolumeOud)!= 0) {
        LVolumeOud = LVolume;
        return(MIN((uint8)((LVolume*9)>>6),31));              // zie def LINVOL en RINVOC codec
    }
    else 
        return(32);
}

/* [] END OF FILE */
