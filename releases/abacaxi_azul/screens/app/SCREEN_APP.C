void Screen_App()
{
  unsigned char ucX;                                 

  Lcd_Cmd(_LCD_CLEAR);
  lcd_Cmd(_LCD_CURSOR_OFF);

  for(ucX=0; ucX<1; ucX++)
   {
    Lcd_Out(2,4,"Body Health BR");
    delay_ms(800);
    Lcd_Cmd(_LCD_TURN_OFF);
    delay_ms(800);
    Lcd_Cmd(_LCD_TURN_ON);
    }
  delay_ms(1200);
  /*
  Lcd_Cmd(_LCD_CLEAR);
  lcd_Cmd(_LCD_CURSOR_OFF);
  Lcd_Out(2,3,"BHS-156");
  Lcd_Out(3,1,"Relatorios");
  for(ucX=0; ucX<10; ++ucX)
   {
   Lcd_Cmd(_LCD_SHIFT_RIGHT);
   delay_ms(80);
   }
   delay_ms(1500);
   */
   Lcd_CMD(_LCD_CLEAR);
   Lcd_CMD(_LCD_RETURN_HOME);
   Lcd_Out(1,4,"Body Health BR");
   Lcd_Out(2,4,"BHS-156 Tester");
   Lcd_Out(4,7,"v2017.1.8");
   delay_ms(2500);
   /*
   for(ucX=0; ucX<5; ucX++)
   {
    Lcd_CMD(_LCD_SHIFT_RIGHT);
    delay_ms(100);
    }
    */
  }