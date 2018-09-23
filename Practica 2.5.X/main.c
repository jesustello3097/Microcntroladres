

#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
#include <stdio.h>
#include "flex_lcd.h"
void main(void) {
    //VARIABLES
    int adc1,adc;
    float voltaje1,voltaje,temperatura;
   
    unsigned char buffer2[16];
    unsigned char buffer1[16];
    
    ///oscilador Fosc=32MHz
    OSCFRQbits.HFFRQ=0b110;// 32 MHz
    //puertos
    ANSELD=0;// puerto d como digital
    
    ANSELAbits.ANSA5=1;/// RA5 COMO ANALOGICO
    TRISAbits.TRISA5=1;///ra5 como entrada
    ANSELBbits.ANSB4=1;/// RB4 COMO ANALOGICO
    TRISBbits.TRISB4=1;///rB4 como entrada
    
    /// convertidor adc
    ADCON0bits.ADON=1;///ADC ONN
    ADCON0bits.ADCONT=0;//OPERACION NORMAL
    ADCON0bits.ADCS=1;// CLOK SOURS
    ADCON0bits.ADFRM=1;//JUSTIFICASION DERECHA
    ADREFbits.ADNREF=0;// Vref- ---vss
    ADREFbits.ADPREF=0b00;// vref+----vdd
    ADPCH=0b000101;// canaL ANSA5
    ADPCH=0b0010110;// canal ANB4
    /// LCD
    Lcd_Init();// inicializa lcd
    Lcd_Cmd(1);// clear lcd
    Lcd_Cmd(12);// cursor off
    __delay_ms(100);
    //ciclo infinito
    while(1){
        ADPCH=0b000101;
        __delay_ms(20);
        ADCON0bits.ADGO=1;///inicia la conversion
        while(ADCON0bits.ADGO==1);// ESPERA A TERMINO DE CONVERSION
        adc=ADRESH; /// SE GUARDA EL RESULTADO
        adc=adc<<8; /// SE GUARDA EL RESULTADO
        adc=adc+ADRESL;/// SE GUARDA EL RESULTADO
        voltaje=adc*5/1023.0;/// conversion a voltaje
           
        
        sprintf(buffer1,"volt=%0.2f",voltaje);
        Lcd_Out2(1,2,buffer1);
        __delay_ms(300);
        
    ADPCH=0b0010110;
    __delay_ms(20);
    
   ADCON0bits.ADGO=1;///inicia la conversion
        (ADCON0bits.ADGO==1);// ESPERA A TERMINO DE CONVERSION
        
        adc1=ADRESH; /// SE GUARDA EL RESULTADO
        adc1=adc<<8; /// SE GUARDA EL RESULTADO
        adc1=adc1+ADRESL;/// SE GUARDA EL RESULTADO
        voltaje1=adc1*5/1023.0;/// conversion a voltaje
           
        
        sprintf(buffer2,"temp=%0.2f",temperatura);
        Lcd_Out2(2,1,buffer2);
        __delay_ms(300);
    }

   return;
}
