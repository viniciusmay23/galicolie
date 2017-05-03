/*###############################################################################################*\
  ************************************************************************************************
  **********************       Project Name: GALICOLIE                                ************
  **********************       Project features: ABOUT BHS 156                        ************
  **********************                                                              ************
  **********************       MCU features:  P18f45K22 (MASTER)                      ************
  **********************       Crystal OSC:   20 MHz                                  ************
  **********************                                                              ************
  **********************       Firmware purpose: Configure fuses device target        ************
  **********************       Version: 1.0  date: 12/25/2016 last update: 05/03/17   ************
  **********************                                                              ************
  **********************       Author: viniciusmay23                                  ************
  **********************       Company: histerese copyrights HEST(c)                  ************
  **********************                BODY HEALTH BRASIL (c)                        ************
  **********************                                                              ************
  ************************************************************************************************
/*###############################################################################################*/


//******************************************* P.S ************************************************/
/*                                      
                                       HARDWARE MAPPING
_________________________________________________________________________________________________*/




void ConfigMCU()                            //  It's a  main function of FUSES.H library                //    
{
 Lcd_Init();                                //  LCD:   self function of mikroc compilator (IDE)         //              
 Lcd_Cmd(_LCD_CLEAR);                       //  LCD:   self function of mikroc compilator (IDE)         //
 Lcd_Cmd(_LCD_CURSOR_OFF);                  //  LCD:   self function of mikroc compilator (IDE)         //




 ANSELD = 0x00;                             //  disable all analog comparatores (about portD)           //
 ANSELB = 0x00;                             //  disable all analog comparatores (about portB)           //
 
 
 ADCON0 = 0b00000101;                       //   CHANNEL SELECTION AND OTHERS                           //
 ADCON1 = 0b00001111;                       //   VOLTAGE REFERENTE AND OTHERS                           //
 ADCON2 = 0b10101010;                       //   SELECTING AND CONFIGURING ACQUISITION TIME             //
 ADCON0.GO_DONE = 0x00;                     //   START/STOP ADC                                         //




 TRISA.RA0 |= 0x01;                         //  this register has been destination on my self keyboard  //
 PORTA.RA0 |= 0x01;
 TRISA.RA1 |= 0x01;                         //  this register has been set on my self voltimeter        //
 PORTA.RA1 |= 0x01;
 

 
 TRISB.RB0 &= 0x00;                         //  STATUS A: led0                                          //
 LATB.RB0  &= 0x00; 
 TRISB.RB1 &= 0x00;                         //  STATUS B: led1                                          //
 LATB.RB1  &= 0x00; 
 TRISB.RB2 &= 0x00;                         //  STATUS C: led2                                          //
 LATB.RB2  &= 0x00; 
 TRISB.RB5 |= 0x01;                         //  EMERGENCY KEY: BACK                                     //
 PORTB.RB5 |= 0x01;
 TRISB.RB6 |= 0x01;                         //  sw2 ---> not used                                       //
 PORTB.RB6 |= 0x01;
 TRISB.RB7 |= 0x01;                         //  sw3 ---> not used                                       //
 PORTB.RB7 |= 0x01;



 TRISC.RC0 |= 0x01;                         //  sw0 ---> not used                                       //
 PORTC.RC0 |= 0x01;
 TRISC.RC1 |= 0x01  ;                       //  sw1 ---> not used                                       //
 PORTC.RC1 |= 0x01;



//@@@@@@@@@@@@@@@@@@@@    LCD HD MAPPING    @@@@@@@@@@@@@@@@@@@@@@@@@                                   //
//                          SEE LCD.H                                                                   //
                                                                                                       
 TRISD.RD4 &= 0x00;                         //  LCD_DATA 4  'D4'                                        //
 PORTD.RD4 &= 0x00;                                                                                   
 TRISD.RD5 &= 0x00;                         //  LCD_DATA 5  'D5'                                        //  
 PORTD.RD5 &= 0x00;
 TRISD.RD6 &= 0x00;                         //  LCD_DATA 6  'D6'                                        //
 PORTD.RD6 &= 0x00;
 TRISD.RD7 &= 0x00;                         //  LCD_DATA 7  'D7'                                        //
 PORTD.RD7 &= 0x00;



 TRISE.RE1 &= 0x00;                         //  LCD_SPI  'E'                                            //
 PORTE.RE1 &= 0x00; 
 TRISE.RE2 &= 0x00;                         //  LCD_SPI  'RS'                                           //
 PORTE.RE2 &= 0x00;

}