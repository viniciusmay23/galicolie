//***************************************** DEFINES ***********************************************/
#include "screen_currents.h"
#include "SCREEN_MAIN.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"
#include "screen_voltages.h"
//_________________________________________________________________________________________________



//***************************************** GLOBAL VARIABLES *************************************/
extern            char    subMenuNumber_Current;
extern unsigned   char    key;
extern            char    flag;

volatile unsigned   int     resultADC_i    = 0x00;
volatile float      volts                  = 0x00;
unsigned char resultI            [12];
unsigned char resultI_media      [12];

volatile float current           = 0x00;

volatile float i_media           = 0x00;
volatile float i_soma            = 0x00;
volatile int   i_ref             = 0x00;
volatile unsigned int i_iMedia   = 0x01;
//_________________________________________________________________________________________________


void CurrentMonitor();



/************************ 'MAIN' *****************************************************************/
void Screen_Current_Main  ()
{
  ChangeSubMenu__Current  ();
  NowSubMenu__Current     ();
  KeyBoardRead            ();
 }
/**************************************************************************************************/



//***********************************   TELAS DOS MENUS   *****************************************/
/***************** Corrente ****************/
void ScreenCurrent    ()
{
  Lcd_Out(1,3,"Bateria de Teste");
  Lcd_Out(3,1," <<   CORRENTE  >>" );
  
  if (key == 0x24)    flag.b1 = 0x01;                    //botao "center"  foi precionado?
  if (key == 0 && flag.b1)
  {
    ClearLcd();
    flag.b1 = 0x00;
   while (key != 0x27 && key != 0x26)
   {
    Screen_Current_Main ();
     }
   ClearLcd();
   }
}
/*********************************************/





//************************************ CONTROLE DOS SUBMENUS ****************************************/
//*********************  controle do menu  ***********************/
void ChangeSubMenu__Current  ()
{
 if (key == 0x23)    flag.b0 = 0x01;                       //botao "left"    foi precionado?
 if (key == 0x25)    flag.b2 = 0x01;                       //botao "right"   foi precionado?

 /******* proxima tela *******/
 if (key == 0x00 && flag.b2)                               //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b2 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   //subMenuNumber_Current++;                                           //incrementa a variavel contadora de menus

  // if (subMenuNumber_Current > 0x02) subMenuNumber_Current = 0x01;       //caso chegue no ultimo menu, volte para o primeiro.
  }//end if "NEXT" menu

 /******* antiga tela *******/
 if (key == 0x00 && flag.b0)                                    //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b0 = 0x00;                                              //limpa a flag para uma proxima leitura
   ClearLcd();                                                  //limpa o LCD
   //subMenuNumber_Current--;                                        //decrementa a variavel contadora de menus

   //if (subMenuNumber_Current < 0x01) subMenuNumber_Current = 0x02;    //caso chegue no primeiro valor do menu, volte para o ultimo
  }//end if "PREV" menu

}//end ChangeMenu()
/************************************************************/






/****************** MENU ATUAL / MENU FUTURO ****************/
void NowSubMenu__Current()
{
  switch(subMenuNumber_Current)
  {
    case 0x01: SubScreenCurrent ();  break;
    }//end switch(menuNumber)
}//end NowMenu()
/************************************************************/




//************************************ CONTROLE DAS SUBTELAS ****************************************/
/***********  sub tela 1 ***************/
void SubScreenCurrent  ()
{
  /*********** CONFIGURAR O ADC PARA ESTA FUNCAO ESPECIFICA ***********/
  TRISA.RA2 = 0x01;
  PORTA.RA2 = 0x01;
  ANSELA.B2 = 0x01;
  
  ADCON0 = 0b00001001;
  ADCON1 = 0x00;
  ADCON2 = 0b10101010;
  //ADCON0.GO_DONE = 0x00;
  /********************************************************************/
 CurrentMonitor();
 
 ADCON0.GO_DONE = 0x00;   //DESLIGANDO O CONVERSOR AD
 }
 //**************************************************************************************************/

 void CurrentMonitor()
 {
   Lcd_Out(1,4,"CORRENTE AC");
   FloatToStr(current,resultI);
   //Lcd_Out(3,1,"i(t) = ");
   Lcd_Out(3,2,resultI);

   ADCON0.GO_DONE = 0x01;
   while(ADCON0.GO_DONE==1);

  //fonte de bancada
  
  /**********************************************
    sensor de -30 a +30 amperes
    considerando somente a parte positiva
       
         /**************************************
            0 A = Vcc/2 --> 512  (0x200)
                  sendo 66mV/1Amp
           .:. V(30) = 2.5 + (66mV/A)*(30A)
               V(30) = 4.48 volts
        /***************************************/
  
  resultADC_i = ((ADRESH << 8) | (int)ADRESL);

 //model 1
 //current = (0.074)*(resultADC_i)-(37.88);


 //model 2
 volts = (resultADC_i / 1023.0)*5000;
 current = ((volts - 2500)/66);
 
 
 //model3
 /*for (i_ref=0; i_ref<100; i_ref++)
  {
   i_media =  (resultADC_i - 511);
   i_iMedia += pow(i_media,2.);
   }
  i_iMedia = sqrt(i_iMedia);
  current = i_iMedia/0.066;
  */
  
  if (current <1.0)
  {
   current = current*1000.0;
   Lcd_CMD(_LCD_CLEAR);
   Lcd_Out(1,4,"CORRENTE AC");
   FloatToStr(current, resultI);
   //Lcd_Out(3,1,"i(t) = ");
   Lcd_Out(3,2,resultI);
   delay_ms(250);
  }

  else
  {
   Lcd_CMD(_LCD_CLEAR);
   Lcd_Out(1,4,"CORRENTE AC");
   FloatToStr(current, resultI);
   //Lcd_Out(3,1,"i(t) = ");
   Lcd_Out(3,2,resultI);
   delay_ms(250);
  }
}