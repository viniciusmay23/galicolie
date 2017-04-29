//***************************************** DEFINES ***********************************************/
#include "screen_powers.h"
#include "SCREEN_MAIN.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"
//_________________________________________________________________________________________________



//***************************************** GLOBAL VARIABLES *************************************/
extern char          subMenuNumber_RFPower;
extern unsigned int  analog_read;
extern unsigned char key;
extern char          flag;
//_________________________________________________________________________________________________


/************************ 'MAIN' *****************************************************************/
void Screen_RFPower_Main()
{
  ChangeSubMenu__RFPower ();
  NowSubMenu__RFPower    ();
  KeyBoardRead           ();
 }
/**************************************************************************************************/



//***********************************   TELAS DOS MENUS   *****************************************/
/***************** Potencia ****************/
void ScreenRFPower    ()
{
  Lcd_Out(1,3,"Bateria de Teste");
  Lcd_Out(3,2,"<<   POTENCIA   >>" );

  if (key == 0x24)  flag.b1 = 0x01;
  if (key == 0x00 && flag.b1)
  {
   flag.b1 = 0x00;
   ClearLcd();
   while (key != 0x27 && key != 0x26)
   {
    Screen_RFPower_Main     ();
     }
   ClearLcd();
   }
}
/*********************************************/





//************************************ CONTROLE DOS SUBMENUS ****************************************/
//*********************  controle do menu  ***********************/
void ChangeSubMenu__RFPower  ()
{
 if (key == 0x23)    flag.b0 = 0x01;                               //botao "left"    foi precionado?
 if (key == 0x25)    flag.b2 = 0x01;                               //botao "right"   foi precionado?

 /******* proxima tela *******/
 if (key == 0x00 && flag.b2)                                       //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b2 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   subMenuNumber_RFPower++;                                        //incrementa a variavel contadora de menus

   if (subMenuNumber_RFPower > 0x04) subMenuNumber_RFPower= 0x01;  //caso chegue no ultimo menu, volte para o primeiro.
  }//end if "NEXT" menu

 /******* antiga tela *******/
 if (key == 0x00 && flag.b0)                                       //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b0 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   subMenuNumber_RFPower--;                                        //decrementa a variavel contadora de menus

   if (subMenuNumber_RFPower < 0x01) subMenuNumber_RFPower = 0x04; //caso chegue no primeiro valor do menu, volte para o ultimo
  }//end if "PREV" menu
}//end ChangeMenu()
/************************************************************/






/****************** MENU ATUAL / MENU FUTURO ****************/
void NowSubMenu__RFPower()
{
  switch(subMenuNumber_RFPower)
  {
    case 0x01: SubScreenRFPower_1();  break;
    case 0x02: SubScreenRFPower_2();  break;
    case 0x03: SubScreenRFPower_3();  break;
    case 0x04: SubScreenRFPower_4();  break;
    }//end switch(menuNumber)
}//end NowMenu()
/************************************************************/




//************************************ CONTROLE DAS SUBTELAS ****************************************/
/************ sub tela 1 ***************/
void SubScreenRFPower_1  ()
{
 Lcd_Out(1,4,"WATTIMETRO");
 Lcd_Out(3,1,"teste1");
 }
/************ sub tela 2 ***************/
void SubScreenRFPower_2  ()
{
 Lcd_Out(1,4,"WATTIMETRO");
 Lcd_Out(3,1,"teste2");
 }
/************ sub tela 3 ***************/
void SubScreenRFPower_3  ()
{
 Lcd_Out(1,4,"WATTIMETRO");
 Lcd_Out(3,1,"teste3");
 }
/************ sub tela 4  ***************/
void SubScreenRFPower_4  ()
{
 Lcd_Out(1,4,"WATTIMETRO");
 Lcd_Out(3,1,"teste4");
 }
 //****************************************************************************************************/