
#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000
void main(void) {
    //Oscilador
    OSCFRQbits.HFFRQ=0b110; // HFINTOSC=32mHZ
    //*********Puertos********
    PORTC=0; //Limpia el puerto c
    ANSELC=0b00000000;//Puerto c como digital
    TRISC=0b00000000;//Puerto c como salida
    WPUCbits.WPUC1=1;// pull up en rc1
    WPUCbits.WPUC3=1;// pull up en rc3
    //*********************************************
    while(1){
       // LATCbits.LATC4=LATCbits.LATC4+1;//Toggle b1
       // __delay_ms(500);
        
        if(PORTCbits.RC1==0){
        __delay_ms(500);
        LATCbits.LATC4=LATCbits.LATC4+1;
        }
    
         if(PORTCbits.RC3==0){
        __delay_ms(500);
        LATCbits.LATC5=LATCbits.LATC5+1;
   
         }
        
    }
    return;
}
    