#include "LCD.h"
#include "keyboard.h"


char character_graus[] = {14,10,10,14,0,0,0,0,0,0,0};

void CustomChar_graus(char pos_row, char pos_char)
{
 char i;
 Lcd_Cmd(64);
 for (i=0; i<=10; i++)
    Lcd_Chr_CP(character_graus[i]);
 Lcd_Cmd(_LCD_RETURN_HOME);
 Lcd_Chr(pos_row, pos_char, 0);
}


void ClearLcd()
{
 Lcd_Cmd(_LCD_CLEAR);
 Lcd_Cmd(_LCD_CURSOR_OFF);
 delay_ms(50);
 }