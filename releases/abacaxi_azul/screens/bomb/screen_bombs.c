//***************************************** DEFINES ***********************************************/
#include "screen_bombs.h"
#include "SCREEN_MAIN.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"
//_________________________________________________________________________________________________



//***************************************** GLOBAL VARIABLES *************************************/
extern char          subMenuNumber_Bomb;
extern unsigned int  analog_read;
extern unsigned char key;
extern char          flag;
//_________________________________________________________________________________________________


/************************ 'MAIN' *****************************************************************/
void Screen_Bomb_Main()
{
  ChangeSubMenu__Bomb    ();
  NowSubMenu__Bomb       ();
  KeyBoardRead           ();
 }
/**************************************************************************************************/



//***********************************   TELAS DOS MENUS   *****************************************/
/***************** Potencia ****************/
void ScreenBomb       ()
{
  Lcd_Out(1,3,"Bateria de Teste");
  Lcd_Out(3,2,"<<     BOMBA    >>" );

  if (key == 0x24)    flag.b1 = 0x01;
  if (key == 0 && flag.b1)
  {
    ClearLcd();
    flag.b1 = 0x00;
   while (key != 0x27 && key != 0x26)
   {
    Screen_Bomb_Main ();
     }
   ClearLcd();
   }
}
/*********************************************/





//************************************ CONTROLE DOS SUBMENUS ****************************************/
//*********************  controle do menu  ***********************/
void ChangeSubMenu__Bomb  ()
{
 if (key == 0x23)    flag.b0 = 0x01;                       //botao "left"    foi precionado?
 if (key == 0x25)    flag.b2 = 0x01;                       //botao "right"   foi precionado?

 /******* proxima tela *******/
 if (key == 0x00 && flag.b2)                               //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b2 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   subMenuNumber_Bomb++;                                        //incrementa a variavel contadora de menus

   if (subMenuNumber_Bomb > 0x02) subMenuNumber_Bomb= 0x01;  //caso chegue no ultimo menu, volte para o primeiro.
  }//end if "NEXT" menu

 /******* antiga tela *******/
 if (key == 0x00 && flag.b0)                                    //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b0 = 0x00;                                              //limpa a flag para uma proxima leitura
   ClearLcd();                                                  //limpa o LCD
   subMenuNumber_Bomb--;                                     //decrementa a variavel contadora de menus

   if (subMenuNumber_Bomb < 0x01) subMenuNumber_Bomb = 0x02; //caso chegue no primeiro valor do menu, volte para o ultimo
  }//end if "PREV" menu

}//end ChangeMenu()
/************************************************************/






/****************** MENU ATUAL / MENU FUTURO ****************/
void NowSubMenu__Bomb()
{
  switch(subMenuNumber_Bomb)
  {
    case 0x01: SubScreenBomb_1();  break;
    case 0x02: SubScreenBomb_2();  break;
    }//end switch(menuNumber)
}//end NowMenu()
/************************************************************/




//************************************ CONTROLE DAS SUBTELAS ****************************************/
/************ sub tela 1 ***************/
void SubScreenBomb_1  ()
{
 Lcd_Out(1,4,"BOMBA");
 Lcd_Out(3,1,"teste1");
}
/************ sub tela 2 ***************/
void SubScreenBomb_2  ()
{
 Lcd_Out(1,4,"BOMBA");
 Lcd_Out(3,1,"teste2");
 }
 //****************************************************************************************************/