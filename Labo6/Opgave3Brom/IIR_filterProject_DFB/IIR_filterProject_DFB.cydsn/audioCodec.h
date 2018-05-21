/* ========================================
 *
 * AudioCodec.h
 * rev 1.6 10/2/2016
 * Piet Coussens & Rogier Delporte, 2015
 * Odisee PBa elektronica
 *
 * Wolfson WM8731 initialisatie parameters 
 * ========================================
 */

#include <project.h>

#ifdef AudioCodec_h // include guard
    // als reeds in het project aanwezig, doe niets
#else
    // indien niet in het project aanwezig, voeg definities in
    #define AudioCodec_h

/****************************************************
 * Functie-definities voor de audio-codec
 ****************************************************/
    
    // stel volume van de hoofdtelefoon-uitgang in i.f.v. een 8-bits getal (van een potmeter)
    uint8 StelHPvolumeIn(uint8 VolWaarde);
    
    // stel het ingangsvolume van de line-in van de codec in i.f.v. een 8-bits getal (van een potmeter)
    uint8 StelLineVolumeIn(uint8 VolWaarde);

    // Stelt de samplerate van de codec in. Toegestane waarden voor de parameter sampleFreq zijn
    // 88, 44, 29, 22, 14, 8, 7, 4 en 2 (waarde in kHz). Indien de samplefrequentie niet ondersteund wordt, 
    // dan wordt 0 geretourneerd, anders de waarde van sampleFreq
    // opm 1: de waarde 29 lijkt niet goed te werken
    // opm 2: De I2S-interface moet mee aangepast worden om de juiste wordrate te houden
    //      AudioCodeClock = 11,2896 MHz/2 => dus juiste deelfactor invoeren voor I2S-clock met 64 clks/word
    uint8 StelSampleRateIn(uint8 sampleFreq);
    
    // zend een commando naar de codec
    uint8 sendCodecCommand(uint8 registerAddress, uint8 newData);

    // initialiseer de codec met de datastructuur CodecInitData[] in AudioCodec.h
    uint8 initCodec();

/****************************************************
 * Initiële instellingen voor de audio-codec
 ****************************************************/

    #ifndef INIT_PARAMETERS
        #define INIT_PARAMETERS

        #ifndef SAMPLE_RATE 
          #define SAMPLE_RATE 44
        #endif

        #ifndef ADCHPD
          #define ADCHPD 0
        #endif

        #ifndef LINVOL
          #define LINVOL 31  
        #endif
        
        #ifndef RINVOL
          #define RINVOL 31
        #endif
        
        #ifndef LRINBOTH
          #define LRINBOTH 0
        #endif

        #ifndef LINMUTE
          #define LINMUTE 0
        #endif
        
        #ifndef RINMUTE
          #define RINMUTE 0
        #endif
        
//        #ifndef RLINBOTH
//          #define RLINBOTH 1
//        #endif

        #ifndef LHPVOL
          #define LHPVOL 100         
        #endif
        
        #ifndef LZCEN
          #define LZCEN 0
        #endif

        #ifndef LRHPBOTH
          #define LRHPBOTH 0
        #endif
        
        #ifndef RHPVOL
          #define RHPVOL 100         
        #endif
        
        #ifndef RZCEN
          #define RZCEN 0
        #endif

        #ifndef MICBOOST
          #define MICBOOST 0
        #endif

        #ifndef MUTEMIC
          #define MUTEMIC 1
        #endif

        #ifndef INSEL
          #define INSEL 0
        #endif

        #ifndef BYPASS
          #define BYPASS 0
        #endif

        #ifndef DACSEL
          #define DACSEL 1
        #endif

        #ifndef SIDETONE
          #define SIDETONE 0
        #endif

        #ifndef SIDEATT
          #define SIDEATT 0
        #endif

        #ifndef OVERSAMPLE
          #define OVERSAMPLE 64
        #endif
    #endif
    
/****************************************************
 * Codec register adres definities
 ****************************************************/
    #ifndef REGISTERS_CODEC
        #define REGISTERS_CODEC
        #define LEFT_LINE_IN_Reg 0x00
        #define RIGHT_LINE_IN_Reg 0x02
        #define LEFT_HP_OUT_Reg 0x04
        #define RIGHT_HP_OUT_Reg 0x06
        #define ANAL_AUDIO_PATH_CTRL_Reg 0x08
        #define DIGI_AUDIO_PATH_CTRL_Reg 0x0A
        #define PWR_DWN_CTRL_Reg 0x0C
        #define DIGI_AUDIO_INTERFACE_FORMAT_Reg 0x0E
        #define SAMPLING_CTRL_Reg 0x10
        #define ACTIVE_CTRL_Reg 0x12
        #define RESET_Reg 0x1E

/****************************************************
 * Codec register bit offset definities
 ****************************************************/
    //R_LEFT_LINE_IN
        #define OFF_LINVOL 0 
        #define OFF_LINMUTE 7  
        #define OFF_LRINBOTH 8 
        
    //R_RIGHT_LINE_IN
        #define OFF_RINVOL 0  
        #define OFF_RINMUTE 7  
        #define OFF_RLINBOTH 8 
        
    //R_LEFT_HP_OUT
        #define OFF_LHPVOL 0  
        #define OFF_LZCEN 7 
        #define OFF_LRHPBOTH 8 
        
    //R_RIGHT_HP_OUT
        #define OFF_RHPVOL 0  
        #define OFF_RZCEN 7 
        #define OFF_RLHPBOTH 8  
        
    //R_ANAL_AUDIO_PATH_CTRL
        #define OFF_MICBOOST 0  
        #define OFF_MUTEMIC 1  
        #define OFF_INSEL 2  
        #define OFF_BYPASS 3  
        #define OFF_DACSEL 4  
        #define OFF_SIDETONE 5  
        #define OFF_SIDEATT 6  
        
    //R_DIGI_AUDIO_PATH_CTRL
        #define OFF_ADCHPD 0 
        #define OFF_DEEMP 1  
        #define OFF_DACMU 3  
        #define OFF_HPOR 4  
        
    //R_PWR_DWN_CTRL
       #define OFF_LINEINPD 0  
        #define OFF_MICPD 1  
        #define OFF_ADCPD 2  
        #define OFF_DACPD 3  
        #define OFF_OUTPD 4  
        #define OFF_OSCPD 5  
        #define OFF_CLKOUTPD 6  
        #define OFF_POWEROFF 7  
        
    //R_DIGI_AUDIO_INTERFACE_FORMAT
        #define OFF_FORMAT 0  
        #define OFF_IWL 2  
        #define OFF_LRP 4  
       #define OFF_LRSWAP 5  
        #define OFF_MS 6  
        #define OFF_BCLKINV 7  
        
    //R_SAMPLING_CTRL
        #define OFF_USB_NORMAL 0  
        #define OFF_BOSR 1  
        #define OFF_SR 2  
        #define OFF_CLKDIV2 6  
        #define OFF_CLKODIV2 7  
        
    //R_ACTIVE_CTRL
        #define OFF_ACTIVE 0  
        
    //R_RESET_REG
        #define OFF_RESET 0  

    #endif

/****************************************************
 * Codec initiële parameters controle
 ****************************************************/
        #if (SAMPLE_RATE != 88)&&(SAMPLE_RATE != 44)&&(SAMPLE_RATE != 29)&&(SAMPLE_RATE != 22)&&(SAMPLE_RATE != 14)&&(SAMPLE_RATE != 8)&&(SAMPLE_RATE != 7)&&(SAMPLE_RATE != 4)&&(SAMPLE_RATE != 2)
          #error SAMPLE_RATE value not valid
        #endif
        #if (ADCHPD != 0) && (ADCHPD != 1)
          #error ADCHPD value not valid
        #endif
        #if (LINVOL < 0) || (LINVOL > 0x1f)
          #error LINVOL value out of range (0-31)
        #endif
        #if (RINVOL < 0) || (RINVOL > 0x1f)
          #error RINVOL value out of range (0-31)
        #endif
        #if (LRINBOTH != 0) && (LRINBOTH != 1)
          #error LRINBOTH value not valid (0,1)
        #endif
        #if (LINMUTE != 0) && (LINMUTE != 1)
          #error LINMUTE value not valid (0,1)
        #endif
        #if (RINMUTE != 0) && (RINMUTE != 1)
          #error RINMUTE value not valid (0,1)
        #endif
        #if (RLINBOTH != 0) && (RLINBOTH != 1)
          #error RLINBOTH value not valid (0,1)
        #endif
        #if ((LHPVOL != 0) && ((LHPVOL < 0x30) && (LHPVOL > 0x7f)))
           #error LHPVOL value out of range (48-127)
        #endif
        #if (LZCEN != 0) && (LZCEN != 1)
          #error LZCEN value not valid (0,1)
        #endif
        #if (LRHPBOTH != 0) && (LRHPBOTH != 1)
          #error LRHPBOTH value not valid (0,1)
        #endif
        #if ((RHPVOL != 0) && ((RHPVOL < 0x30) && (RHPVOL > 0x7f)))
          #error RHPVOL value out of range (48-127)
        #endif
        #if (RZCEN != 0) && (RZCEN != 1)
          #error RZCEN value not valid
        #endif
        #if (MICBOOST != 0) && (MICBOOST != 1)
          #error MICBOOST value not valid (0,1)
        #endif
        #if (MUTEMIC != 0) && (MUTEMIC != 1)
          #error MUTEMIC value not valid (0,1)
        #endif
        #if (INSEL != 0) && (INSEL != 1)
          #error INSEL value not valid (0,1)
        #endif
        #if (BYPASS != 0) && (BYPASS != 1)
          #error BYPASS value not valid (0,1)
        #endif
        #if (DACSEL != 0) && (DACSEL != 1)
          #error DACSEL value not valid (0,1)
        #endif
        #if (SIDETONE != 0) && (SIDETONE != 1)
          #error SIDETONE value not valid (0,1)
        #endif
        #if (SIDEATT < 0)&&(SIDEATT > 3)
          #error SIDEATT value out of range (0-3)
        #endif
        #if (OVERSAMPLE != 1)&&(OVERSAMPLE != 2)&&(OVERSAMPLE != 4)&&(OVERSAMPLE != 8)&&(OVERSAMPLE != 16)&&(OVERSAMPLE != 32)&&(OVERSAMPLE != 64)
          #error OVERSAMPLE value not valid (1,2,4,8,16,32 of 64)
        #endif
#endif

    