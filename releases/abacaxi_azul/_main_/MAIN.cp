#line 1 "C:/Users/vinicius_dark/Desktop/projeto_final/release_v2.0/MAIN.c"
#line 1 "c:/users/vinicius_dark/desktop/projeto_final/release_v2.0/lcd.h"




 sbit LCD_RS at LATE2_BIT;
 sbit LCD_EN at LATE1_BIT;
 sbit LCD_D4 at LATD4_BIT;
 sbit LCD_D5 at LATD5_BIT;
 sbit LCD_D6 at LATD6_BIT;
 sbit LCD_D7 at LATD7_BIT;

 sbit LCD_RS_Direction at TRISE2_BIT;
 sbit LCD_EN_Direction at TRISE1_BIT;
 sbit LCD_D4_Direction at TRISD4_BIT;
 sbit LCD_D5_Direction at TRISD5_BIT;
 sbit LCD_D6_Direction at TRISD6_BIT;
 sbit LCD_D7_Direction at TRISD7_BIT;

 static char count;
 extern character_graus[];

 void CustomChar_graus(char pos_row, char pos_char);
 void ClearLcd();
#line 1 "c:/users/vinicius_dark/desktop/projeto_final/release_v2.0/screen_app.h"


 void Screen_App();
#line 1 "c:/users/vinicius_dark/desktop/projeto_final/release_v2.0/fuses.h"



void ConfigMCU();

Lcd_Init();
Lcd_Cmd(_LCD_CLEAR);
Lcd_Cmd(_LCD_CURSOR_OFF);
#line 1 "c:/users/vinicius_dark/desktop/projeto_final/release_v2.0/keyboard.h"


 void KeyBoardRead();
#line 58 "C:/Users/vinicius_dark/Desktop/projeto_final/release_v2.0/MAIN.c"
void ConfigMCU ();
void Screen_App ();
void ClearLcd ();
void Screen_Main ();
#line 78 "C:/Users/vinicius_dark/Desktop/projeto_final/release_v2.0/MAIN.c"
void main()
{
 while( 1 )
 {
 ConfigMCU ();


 Screen_Main ();

 }
}
