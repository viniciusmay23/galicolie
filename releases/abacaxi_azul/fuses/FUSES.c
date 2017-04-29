void ConfigMCU()
{

 Lcd_Init();
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);

 ANSELD = 0x00;
 ANSELB = 0x00;
 
 TRISA.RA0 |= 0x01;                       //teclado_analogico
 PORTA.RA0 |= 0x01;
 TRISA.RA1 |= 0x01;                       //leitura analogica (voltimetro)
 PORTA.RA1 |= 0x01;
 
 ADCON0 = 0b00000101;
 ADCON1 = 0b00001111;
 ADCON2 = 0b10101010;
 ADCON0.GO_DONE = 0x00;
 
 TRISB.RB0 &= 0x00;                       //led0
 LATB.RB0  &= 0x00; 
 TRISB.RB1 &= 0x00;                       //led1
 LATB.RB1  &= 0x00; 
 TRISB.RB2 &= 0x00;                       //led2
 LATB.RB2  &= 0x00; 
 TRISB.RB5 |= 0x01;                       //BACK
 PORTB.RB5 |= 0x01;
 TRISB.RB6 |= 0x01;                       //sw2
 PORTB.RB6 |= 0x01;
 TRISB.RB7 |= 0x01;                       //sw3
 PORTB.RB7 |= 0x01;

 TRISC.RC0 |= 0x01;                       //sw0
 PORTC.RC0 |= 0x01;
 TRISC.RC1 |= 0x01;                       //sw1
 PORTC.RC1 |= 0x01;



 TRISD.RD4 &= 0x00;                       //LCD 'D4'
 PORTD.RD4 &= 0x00;
 TRISD.RD5 &= 0x00;                       //LCD 'D5'
 PORTD.RD5 &= 0x00;
 TRISD.RD6 &= 0x00;                       //LCD 'D6'
 PORTD.RD6 &= 0x00;
 TRISD.RD7 &= 0x00;                       //LCD 'D7'
 PORTD.RD7 &= 0x00;

 TRISE.RE1 &= 0x00;                       //LCD 'E'
 PORTE.RE1 &= 0x00;
 TRISE.RE2 &= 0x00;                       //LCD 'RS'
 PORTE.RE2 &= 0x00;

}