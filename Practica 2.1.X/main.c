
#include <xc.h>
#include "configuracion.h"
#define _XTAL_FREQ 32000000
#define boton1 PORTCbits.RC1
#define LED1 PORTCbits.RC2
#define boton2 PORTDbits.RD3
#define LED2 PORTDbits.RD1

void main(void) {
    OSCFRQbits.HFFRQ =0b110;
    PORTC=0;
    ANSELC=0b00000000;
    PORTD=0;
    ANSELD=0b00000000;
    
    TRISCbits.TRISC1 = 1;
    TRISCbits.TRISC2 = 0;
    TRISDbits.TRISD3 = 1;
    TRISDbits.TRISD1 = 0;
******************************************************
    while(1){
        //// LATCbits.LATC4=LATCbits.LATC4+1;//Toggle b1
       // __delay_ms(500);
        
        if (boton1 ==0){
            __delay_ms(500);
            LED1 = LED1 + 1;
        }
            if (boton2 ==0){
            __delay_ms(500);
            LED2 = LED2 + 1;
           
            
        }
    }
    
    
    return;
}
