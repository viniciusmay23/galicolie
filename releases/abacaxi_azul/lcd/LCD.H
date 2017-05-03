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
/* lcd mode */


#ifndef _LCD_                                            //  IF:    not defined "LCD_H_"       //
#define _LCD_                                            //  IF:    not defined "LCD_H_"       //

   sbit    LCD_RS   at   LATE2_BIT;
   sbit    LCD_EN   at   LATE1_BIT;
   sbit    LCD_D4   at   LATD4_BIT;
   sbit    LCD_D5   at   LATD5_BIT;
   sbit    LCD_D6   at   LATD6_BIT;
   sbit    LCD_D7   at   LATD7_BIT;

   sbit    LCD_RS_Direction   at    TRISE2_BIT;
   sbit    LCD_EN_Direction   at    TRISE1_BIT;
   sbit    LCD_D4_Direction   at    TRISD4_BIT;
   sbit    LCD_D5_Direction   at    TRISD5_BIT;
   sbit    LCD_D6_Direction   at    TRISD6_BIT;
   sbit    LCD_D7_Direction   at    TRISD7_BIT;
   

//@@@@@@@@@@@@@@@ EXPECIAL CHARACTERS @@@@@@@@@@@@@
  static char count;                                    //  variable counter                    //
  extern character_graus[];                             //  variable with new lcd char          //
  void CustomChar_graus(char pos_row, char pos_char);   //  lcd map new char                    //


#endif