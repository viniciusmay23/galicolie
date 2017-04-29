/*###############################################################################################*\
  ************************************************************************************************
  **********************       Project Name: lcd manipulation                         ************
  **********************       Project features: lcd alpha-numeric                    ************
  **********************                                                              ************
  **********************       MCU features:  PIC18f4550                              ************
  **********************       Crystal OSC:   20 MHz                                  ************
  **********************                                                              ************
  **********************       Firmware purpose: learn of display LCD device          ************
  **********************       Version: 1.0    date: 12/25/2016   last update:        ************
  **********************                                                              ************
  **********************       Author: viniciusmay23                                  ************
  **********************       Company: histerese copyrights HEST(c)                  ************
  **********************                                                              ************
  ************************************************************************************************
/*###############################################################################################*/





//***************************************** PRAGMAS ***********************************************
//_________________________________________________________________________________________________





//**************************************** INCLUDES ***********************************************

//_________________________________________________________________________________________________





//***************************************** DEFINES ***********************************************
  /*********** lcd mode ***************/
   #define lcd_4bits
   #define TRUE 1

   #define BACK PORTB.RB7
   #define SW0  PORTC.RB0
   #define SW1  PORTC.RB1
   #define SW2  PORTB.RB5
   #define SW3  PORTB.RB6

//_________________________________________________________________________________________________




//************************************ GLOBAL VARIABLES********************************************




//*********************************** PROTOTYPE FUNCTIONS *****************************************



  /************************************ LCD FUNCTIONS MIKROC *****************************
  void    Lcd_Init     ();            //lcd in 4 bit mode
  void    Lcd_Cmd      ();            //lcd + command byte
  void    Lcd_Out      ();            //lcd output display
  void    Lcd_Out_Cp   ();
  void    Lcd_Chr      ();
  void    Lcd_Chr_Cp   ();
  /***************************************************************************************

  /************************************ LCD COMANDS MIKROC *******************************
  / _LCD_FIRST_ROW               move cursor to the 1st row
  / _LCD_SECOND_ROW              move cursor to the 2nd row
  / _LCD_THIRD_ROW               move cursor to the 3rd row
  / _LCD_FOURTH_ROW              move cursor to the 4th row
  / _LCD_CLEAR                   clear lcd_display
  / _LCD_RETURN_HOME             clear lcd_display
  / _LCD_CURSOR_OFF              turn off cursor
  / _LCD_UNDERLINE_ON            underline cursor on
  / _LCD_BLINK_CURSOR_ON         blink cursor on
  / _LCD_MOVE_CURSOR_LEFT        move cursor left without changing display data  RAM
  / _LCD_MOVE_CUSROR_RIGHT       move cursor rigth without changing display data RAM
  / _LCD_TURN_ON                 turn lcd_display on
  / _LCD_TURN_OFF                turn lcd_display_off
  / _LCD_SHIFT_LEFT              shift display left without changing display data  RAM
  / _LCD_SHIFT_RIGHT             shift display rigth without changing display data RAM
  /
  /***************************************************************************************/
//________________________________________________________________________________________________




//***************************************** THREADS **********************************************
//________________________________________________________________________________________________





//**************************************** FUNCTIONS *********************************************

//_________________________________________________________________________________________________
{    unsigned char ucX;                                    //ucX --> X eh do tipo unsigned char
    Lcd_Init();
    Lcd_Cmd(_LCD_CLEAR);
    lcd_Cmd(_LCD_CURSOR_OFF);

    for(ucX=0; ucX<3; ucX++)
    {
      Lcd_Out(1,4,"Body Health BR");
      delay_ms(300);
      Lcd_Cmd(_LCD_TURN_OFF);
      delay_ms(300);
      Lcd_Cmd(_LCD_TURN_ON);
     }
    delay_ms(700);
    Lcd_Cmd(_LCD_CLEAR);
    Lcd_Cmd(_LCD_CURSOR_OFF);
    Lcd_Out(1,1,"BHS-TESTER");

    for(ucX=0; ucX<5; ++ucX)
    {
     Lcd_Cmd(_LCD_SHIFT_RIGHT);
     delay_ms(200);
    }
   Lcd_Out(2,2,"ver1.0.0");

} //END FUNCTION