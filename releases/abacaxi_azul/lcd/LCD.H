/*********** lcd mode ***************/
#ifndef _LCD_
#define _LCD_

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
   
  static char count;
  extern character_graus[];
  
  void CustomChar_graus(char pos_row, char pos_char);
  void ClearLcd();
#endif