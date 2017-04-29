//***************************************** DEFINES ***********************************************/
#include "screen_temps.h"
#include "SCREEN_MAIN.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"
#include "i2c_protocol.h"
//_________________________________________________________________________________________________


/************************** prototype functions **************************************************/
//void DataLogger();
/*************************************************************************************************/




//***************************************** GLOBAL VARIABLES *************************************/
extern char          subMenuNumber_Temp;
extern unsigned int  analog_read;
extern unsigned char key;
extern char          flag;
//_________________________________________________________________________________________________


/************************ 'MAIN' *****************************************************************/
void Screen_Temperature_Main  ()
{
  ChangeSubMenu__Temp ();
  NowSubMenu__Temp    ();
  KeyBoardRead        ();
 }
/**************************************************************************************************/



//***********************************   TELAS DOS MENUS   *****************************************/
/***************** Temperatura ****************/
void ScreenTemperature()
{
  Lcd_Out(1,3,"Bateria de Teste");
  Lcd_Out(3,2,"<<  TEMPERATURA >>" );

  if (key == 0x24)    flag.b1 = 0x01;
  if (key == 0 && flag.b1)
  {
    ClearLcd();
    flag.b1 = 0x00;
   while (key != 0x27 && key != 0x26)
   {
    Screen_Temperature_Main ();
     }
   ClearLcd();
   }
}
/*********************************************/





//************************************ CONTROLE DOS SUBMENUS ****************************************/
//*********************  controle do menu  ***********************/
void ChangeSubMenu__Temp  ()
{
 if (key == 0x23)    flag.b0 = 0x01;                       //botao "left"    foi precionado?
 if (key == 0x25)    flag.b2 = 0x01;                       //botao "right"   foi precionado?

 /******* proxima tela *******/
 if (key == 0x00 && flag.b2)                               //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b2 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   subMenuNumber_Temp++;                                           //incrementa a variavel contadora de menus

   if (subMenuNumber_Temp > 0x02) subMenuNumber_Temp = 0x01;       //caso chegue no ultimo menu, volte para o primeiro.
  }//end if "NEXT" menu

 /******* antiga tela *******/
 if (key == 0x00 && flag.b0)                                    //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b0 = 0x00;                                              //limpa a flag para uma proxima leitura
   ClearLcd();                                                  //limpa o LCD
   subMenuNumber_Temp--;                                        //decrementa a variavel contadora de menus

   if (subMenuNumber_Temp < 0x01) subMenuNumber_Temp = 0x02;    //caso chegue no primeiro valor do menu, volte para o ultimo
  }//end if "PREV" menu

}//end ChangeMenu()
/************************************************************/






/****************** MENU ATUAL / MENU FUTURO ****************/
void NowSubMenu__Temp    ()
{
  switch(subMenuNumber_Temp)
  {
    case 0x01: SubScreenTemp_1 ();  break;
    case 0x02: SubScreenTemp_2 ();  break;
    }//end switch(menuNumber)
}//end NowMenu()
/************************************************************/




//************************************ CONTROLE DAS SUBTELAS ****************************************/
/***********  sub tela 1 ***************/
void SubScreenTemp_1  ()
{
 Lcd_Out(1,4,"TEMPERATURA");
 Lcd_Out(3,1,"datalogger");

  DataLogger();

 }
/***********  sub tela 2 ***************/
void SubScreenTemp_2  ()
{
 Lcd_Out(1,4,"TEMPERATURA");
 Lcd_Out(3,1,"teste2");
 }
 //****************************************************************************************************/