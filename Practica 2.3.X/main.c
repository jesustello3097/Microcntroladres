


#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000 // FOSC
#include "flex_lcd.h"
#include<stdio.h>//STANDAR I/O



void main(void) {
    
    
    unsigned i;
    unsigned char buffer1[16];
    /// FRECUNECIA DEL OSCILADOR
    OSCFRQbits.HFFRQ = 0b110;/// 32 Mhz
    ///Puertos como salidas digitales
    
    
    ANSELD=0;
  /// inicializacion de la LCD
    Lcd_Init();// inicializa la LCD
    Lcd_Cmd(LCD_CLEAR); //LIMPIA LA LCD
    Lcd_Cmd(LCD_CURSOR_OFF);// APAGA EL CURSOR
    Lcd_Cmd(LCD_BLINK_CURSOR_ON);// PARPADEA EL CURSOE
    __delay_ms(1000);
    
    while(1){
        for (i=0; i<13; i++){
            Lcd_Out(1,i+1,  "Mecatronica");
            __delay_ms(500);
            Lcd_Cmd(LCD_CLEAR);
            sprintf(buffer1,"Cuenta: %03d",i);
            Lcd_Out2(2,3,buffer1);
            
        }
          }
    
    return;
}
