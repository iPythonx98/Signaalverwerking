/*******************************************************************************
*
* Naam student 1:
* Naam student 2:
*
* Datum: 
*
* File Naam: main.c
* Projectnaam: IIR_filterproject
* Versie: 2.0 10/2/2016
* Author: Piet Coussens 
*
* Beschrijving:
*  Demo programma voor het samplen van audio via de codec
*
* Gebruikte instellingen I2S:
*   Direction:           Tx and Rx
*   WordSelect:          32 bits
*   DataBits:            16 bits
*   DataInterleaving:    Interleaved
*   DMA Request:         Tx and Rx
*   Rx clip detection:   Enabled op 120
*
* Gebruikte instellingen codec
*   Via P1 is het uitgangsniveau van de hoofdtelefoon in te stellen (tussen 0 en 79 dB)
*   Via P2 is de gevoeligheid van de line-ingang in te stellen (tussen 0 en 31 dB)
*   CLIP is een oversturingsindicator die oplicht als het ingangsniveau te hoog is.
*     Deze LED gaat aan als de sample-waarde boven de clip-treshold uitkomt (MSB=120)
*     Regel P2 zo dat deze LED uit blijft. 
*   CLIP kan ook ingesteld worden om op te lichten als de sample-interrupt actief is. 
*     Daarmee kan de lengte van de sample-interrupt gemeten worden
*     Zet daartoe de define CLIPnTIME in de file dma.h op 0 i.p.v. op 1
*   L0 licht op als filter A niet op tijd berekend kan worden
*   L1 licht op als filter B niet op tijd berekend kan worden
*
*   Codec-instellingen: inputLevel: 22, HPlevel: 75, ingangsignaal: 2Vpp
*
********************************************************************************/

#include <project.h>
#include <dspSystem.h>
#include <dma.h>
#include <audioCodec.h>
#include <stdlib.h>

// zet filters aan (1) of uit (0) in linker of rechter kanaal
#define USE_FILTER_LINKS 1
#define USE_FILTER_RECHTS 0
// LCD-tekst
#define TITEL1 "Butterworth LPF "
#define TITEL2 "4e orde 2,00 kHz"

// Globale variabelen
uint8 HPvolume, displayVolume, LineVolume, ClipIndicator = ' ';
int maxL, maxR;
uint32 cyclusTel;

void berekenMetSamples(){
    // zet hier je code voor de berekeningen met de samples
    // check of filterblok klaar is, indien niet, zet L0
#if USE_FILTER_LINKS == 1
    if (Filter_IsInterruptChannelA() == 0) {
        sampleUit[LINKS] = 0;
        LEDs_Write(LEDs_Read() | 0x01);
    }
    else {
        sampleUit[LINKS] = Filter_Read16(Filter_CHANNEL_A);
        LEDs_Write(LEDs_Read() & 0xE);
    }
    Filter_Write16(Filter_CHANNEL_A, sampleIn[LINKS]);
#else
    sampleUit[LINKS] = sampleIn[LINKS];
#endif
#if USE_FILTER_RECHTS == 1
    if (Filter_IsInterruptChannelB() == 0) {
        sampleUit[RECHTS] = 0;
        LEDs_Write(LEDs_Read() | 0x02);
    }
    else {
        sampleUit[RECHTS] = Filter_Read16(Filter_CHANNEL_B);
        LEDs_Write(LEDs_Read() & 0xD);
    }
    Filter_Write16(Filter_CHANNEL_B, sampleIn[RECHTS]);
#else
    sampleUit[RECHTS] = sampleIn[RECHTS];
#endif
    
    // Dit is niet strikt nodig, maar dient om het maximum signaalniveau op het LCD te tonen
    // Deze berekening kost 1,5 us
    maxL = MAX(ABS(sampleIn[LINKS]) , maxL);
    maxR = MAX(ABS(sampleIn[RECHTS]), maxR);
}

int main()
{   
    // Setup-gedeelte van het hoofdprogramma
    LEDs_Write(LEDs_Read() | 0x03);
    CyGlobalIntEnable;              // Enable global interrupts
    I2C_Codec_control_Start();      // I2C start
    LCD_Start();
    LCD_WriteControl(LCD_CLEAR_DISPLAY);
    LCD_Position(0u, 0u);
    LCD_PrintString(TITEL1);
    LCD_Position(1u, 0u);
    LCD_PrintString(TITEL2);
    CyDelay(1000);
    LCD_WriteControl(LCD_CLEAR_DISPLAY);
    LCD_Position(0u, 0u);
    LCD_PrintString("P1: Vol uitgang");
    LCD_Position(1u, 0u);
    LCD_PrintString("P2: Level ingang");
    CyDelay(500);
    LCD_WriteControl(LCD_CLEAR_DISPLAY);
    LCD_Position(0u, 0u);
    LCD_PrintString("Lev:   HP:  ");
    LCD_Position(1u, 0u);
    LCD_PrintString("Line:");
    sampleUit[LINKS] = 0;
    sampleUit[RECHTS]  = 0;
    initCodec();                    // initialiseer codec
    VOL_Start();                    // start ADC in continious mode
    VOL_StartConvert();
    LINE_Start();                   // start ADC in continious mode
    LINE_StartConvert();

    AnalogeIngang_L_Start();        // opamps starten
    AnalogeIngang_R_Start();
	// Filterblok starten, interrupt register bits aanzetten voor polling
    Filter_Start(); 
    LCD_Position(0u, 15u);
#if USE_FILTER_LINKS == 1
    Filter_INT_CTRL_REG |= (1 << Filter_CHANNEL_A);
    LCD_PutChar('L');
    LCD_Position(0u, 14u);
#endif
#if USE_FILTER_RECHTS == 1
    Filter_INT_CTRL_REG |= (1 << Filter_CHANNEL_B);
    LCD_PutChar('R');
#endif
    
    I2S_EN_Write(1);                // zet de codec-klok voor I2S interface aan
    
    // Configureer DMAs voor zenden en ontvangen via I2S
    DmaRxConfiguration();
    DmaTxConfiguration();
    
    // Declareer interrupt-routines voor zenden en ontvangen via I2S
    SampleVraag_StartEx(sampleIntTx_ISR);
    SampleKlaar_StartEx(sampleIntRx_ISR);

    I2S_Codec_audio_Start();        // Start I2S-interface
    I2S_Codec_audio_EnableRx();     // Enable Rx direction 
    I2S_Codec_audio_EnableTx();     // Enable Tx direction 
    LEDs_Write(LEDs_Read() & 0x0C);
    
    cyclusTel = 0;
    for(;;) {
        // Loop-gedeelte van het hoofdprogramma

        // Line gevoeligheid-instelling op het display
        LineVolume = StelLineVolumeIn(LINE_GetResult8());
        LCD_Position(0u,4u);
        if (LineVolume < 10) LCD_PutChar(' ');
        LCD_PrintNumber(LineVolume);

        // Als niveau te hoog, dan meld dat op LCD
        if(CLIP_Read()) ClipIndicator = '!';
        
        // HP volume-instelling op het display
        HPvolume = StelHPvolumeIn(VOL_GetResult8());
        LCD_Position(0u,10u);
        displayVolume = HPvolume-48;
        if (displayVolume < 10) LCD_PutChar(' ');
        LCD_PrintNumber(displayVolume);
        
        // zet elke seconde maximum inputwaarde op het LCD
        if (cyclusTel >= 100) {
            cyclusTel = 0;
            LCD_Position(0u, 6);
            LCD_PutChar(ClipIndicator); 
            ClipIndicator = ' ';
            LCD_Position(1u, 5);
            if (maxL < 10000) LCD_PutChar(' ');
            if (maxL < 1000)  LCD_PutChar(' ');
            if (maxL < 100)   LCD_PutChar(' ');
            if (maxL < 10)    LCD_PutChar(' ');
            LCD_PrintNumber(maxL);
            maxL = 0; 
            LCD_PutChar(' ');
            if (maxR < 10000) LCD_PutChar(' ');
            if (maxR < 1000)  LCD_PutChar(' ');
            if (maxR < 100)   LCD_PutChar(' ');
            if (maxR < 10)    LCD_PutChar(' ');
            LCD_PrintNumber(maxR);
            maxR = 0;
        }
        cyclusTel++;
        CyDelayUs(1000);
    }
}

