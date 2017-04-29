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


//******************************************* P.S *************************************************/





//***************************************** PRAGMAS ***********************************************/
//_________________________________________________________________________________________________




//**************************************** INCLUDES ***********************************************/
#include "SCREEN_MAIN.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"

/*********** screen_files **********/
#include "screen_frequencys.h"
#include "screen_powers.h"
#include "screen_bombs.h"
#include "screen_temps.h"
#include "screen_currents.h"
#include "screen_voltages.h"
//_________________________________________________________________________________________________




//***************************************** DEFINES ***********************************************/
#define       TRUE      0x01

#define       LEFT      0x23
#define       CENTER    0x24
#define       RIGHT     0x25
#define       UP        0x26
#define       DOWN      0x27
//_________________________________________________________________________________________________




//*************************************************GLOBAL VARIABLES**************************************************/
 char menuNumber                    = 0x01;           //iniciar na primeira tela: Frequencimetro

 char subMenuNumber_freq            = 0x01;           //iniciar sem nenhum submenu do menu de frequencia
 char subMenuNumber_RFPower         = 0x01;           //iniciar sem nenhum submenu do menu de potencia de RF
 char subMenuNumber_Bomb            = 0x01;           //iniciar sem nenhum submenu do menu de bomba
 char subMenuNumber_Temp            = 0x01;           //iniciar sem nenhum submenu do menu de temperatura
 char subMenuNumber_Current         = 0x01;           //iniciar sem nenhum submenu do menu de corrente
 char subMenuNumber_Voltage         = 0x01;           //iniciar sem nenhum submenu do menu de tensao

 char flag                          = 0x00;           //variavel char (abstracao pra variavel binaria)
 
 extern unsigned int  analog_read          = 0x00;           //leitura analogica
 extern unsigned char key                  = 0x00;           //leitura analogica (copia de seg)
/*__________________________________________________________________________________________________________________*/


//*********************************** PROTOTYPE FUNCTIONS *****************************************/
/*-------------controle do menu-------------*/
void ChangeMenu  ();

/*--------------exibicao do menu------------*/
void NowMenu     ();

/*-------controle do teclado analogico------*/
void KeyBoardRead();
//_____________________________________________________________________________________________________________________


//********************************************************* MAIN *****************************************************/
void Screen_Main ()
{
  flag.b0 = 0x00;                                           //Flag binaria --> Left
  flag.b1 = 0x00;                                           //Flag binaria --> Center
  flag.b2 = 0x00;                                           //Flag binaria --> Right
  flag.b3 = 0x00;                                           //Flag binaria --> Up
  flag.b4 = 0x00;                                           //Flag binaria --> down

  while (TRUE)
  {
   KeyBoardRead();                                          //Verifica qual a tecla precionada
   ChangeMenu  ();                                          //Efetua a troca do menu quando necessario
   NowMenu     ();                                          //Exibicao do menu futuro (atual, na primeira vez)
  }
}
//_____________________________________________________________________________________________________________________


//************************************************ FUNCTIONS ********************************************************/
//***********************************  controle do menu  ***************************************/
void ChangeMenu ()
{
 if (key == 0x23)    flag.b0 = 0x01;                       //botao "left"    foi precionado?
 if (key == 0x25)    flag.b2 = 0x01;                       //botao "right"   foi precionado?

 /******* proxima tela *******/
 if (key == 0x00 && flag.b2==1)                               //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b2 = 0x00;                                         //limpa a flag para uma proxima leitura
   ClearLcd();                                             //limpa o LCD
   menuNumber++;                                           //incrementa a variavel contadora de menus
  
   if (menuNumber > 0x06) menuNumber = 0x01;               //caso chegue no ultimo menu, volte para o primeiro.
  }//end if "NEXT" menu

 /******* antiga tela *******/
 if (key == 0x00 && flag.b0)                               //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b0 = 0x00;                                         //limpa a flag para uma proxima leitura
   ClearLcd();                                             //limpa o LCD
   menuNumber--;                                           //decrementa a variavel contadora de menus

   if (menuNumber < 0x01) menuNumber = 0x06;               //caso chegue no primeiro valor do menu, volte para o ultimo
  }//end if "PREV" menu

}//end ChangeMenu()
/***********************************************************************************************/


/***********************************   exibicao do menu  ***************************************/
void NowMenu()
{
  switch(menuNumber)
  {
    case 0x01: ScreenFrequency   (); break;
    case 0x02: ScreenRFPower     (); break;
    case 0x03: ScreenBomb        (); break;
    case 0x04: ScreenTemperature (); break;
    case 0x05: ScreenCurrent     (); break;
    case 0x06: ScreenVoltage     (); break;
    }//end switch(menuNumber)
    
}//end NowMenu()
/***********************************************************************************************/