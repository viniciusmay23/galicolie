//***************************************** DEFINES ***********************************************/
#include "screen_voltages.h"
#include "SCREEN_MAIN.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"
#include "fuses.h"
//_________________________________________________________________________________________________



//***************************************** GLOBAL VARIABLES *************************************/
extern char          subMenuNumber_Voltage;
extern unsigned char key;
extern char          flag;

volatile unsigned char v_counter  = 0x01;  //OnOff function

volatile unsigned int resultADC   = 0x00;   //adc_read --> voltage measure in AN1
volatile          float voltage   = 0.000;  //result VOLTAGE REAL
                  float       K   = 0.03910068;



unsigned char resultV        [12];
unsigned char resultV_media  [12];

volatile float v_media           = 0x00;
volatile float v_soma            = 0x00;
volatile float v_referencia      = 0x00;
volatile unsigned int v_iMedia   = 0x01;
//_________________________________________________________________________________________________





//**************************************** PROTOTYPE FUNCTIONS ************************************/
 void OnOff  (unsigned char c);
 void VoltageMonitor ();
 void Screen_Main();
//_________________________________________________________________________________________________/




/************************ 'MAIN' *****************************************************************/
void Screen_Voltage_Main  ()
{
  ChangeSubMenu__Voltage ();
  NowSubMenu__Voltage    ();
  KeyBoardRead           ();
 }
/**************************************************************************************************/



//***********************************   TELAS DOS MENUS   *****************************************/
/***************** Tensao ****************/
void ScreenVoltage    ()
{
  Lcd_Out(1,3,"Bateria de Teste");
  Lcd_Out(3,1," <<    TENSAO   >>" );
 
  if (key == 0x24)    flag.b1 = 0x01;                    //botao "center"  foi precionado?
  if (key == 0 && flag.b1)
  {
    ClearLcd();
    flag.b1 = 0x00;
    while (key != 0x27 && key != 0x26)
    {
     Screen_Voltage_Main ();
     }
    ClearLcd();
   }
}
/*********************************************/





//************************************ CONTROLE DOS SUBMENUS ****************************************/
//*********************  controle do menu  ***********************/
void ChangeSubMenu__Voltage  ()
{
 if (key == 0x23)    flag.b0 = 0x01;                       //botao "left"    foi precionado?
 if (key == 0x25)    flag.b2 = 0x01;                       //botao "right"   foi precionado?

 /******* proxima tela *******/
 if (key == 0x00 && flag.b2)                               //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b2 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   subMenuNumber_Voltage++;                                           //incrementa a variavel contadora de menus

  if (subMenuNumber_Voltage > 0x02) subMenuNumber_Voltage = 0x01;       //caso chegue no ultimo menu, volte para o primeiro.
  }//end if "NEXT" menu

 /******* antiga tela *******/
 if (key == 0x00 && flag.b0)                                    //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b0 = 0x00;                                              //limpa a flag para uma proxima leitura
   ClearLcd();                                                  //limpa o LCD
   subMenuNumber_Voltage--;                                        //decrementa a variavel contadora de menus

   if (subMenuNumber_Voltage < 0x01) subMenuNumber_Voltage = 0x02;    //caso chegue no primeiro valor do menu, volte para o ultimo
  }//end if "PREV" menu

}//end ChangeMenu()
/************************************************************/






/****************** MENU ATUAL / MENU FUTURO ****************/
void NowSubMenu__Voltage()
{
  switch(subMenuNumber_Voltage)
  {
    case 0x01: SubScreenVoltage_1 ();  break;
    case 0x02: SubScreenVoltage_2 ();  break;
    }//end switch(menuNumber)
}//end NowMenu()
/************************************************************/




//************************************ CONTROLE DAS SUBTELAS ****************************************/
/***********  sub tela 1 ***************/
void SubScreenVoltage_1  ()
{
 /*********** CONFIGURAR O ADC PARA ESTA FUNCAO ESPECIFICA ***********/
  ADCON0 = 0b00000101;
  ADCON1 = 0b00001111;
  ADCON2 = 0b10101010;
  ADCON0.GO_DONE = 0x00;
 /********************************************************************/

 VoltageMonitor();
 
 ADCON0.GO_DONE = 0x00;   //DESLIGANDO O CONVERSOR AD
 }
 
 
/***********  sub tela 2 ***************/
void SubScreenVoltage_2  ()
{
 ADCON0.GO_DONE = 0x00;  //desligando o ADC
 FloatToStr(v_media, resultV_media);
 
 Lcd_Out(1,4,"MEDIA");
 Lcd_Out(3,1,"Tensao:");

 Lcd_Out(3,8,resultV_media);
 }
 //****************************************************************************************************/
  
  
  
  
void VoltageMonitor()
{
  Lcd_Out(1,2,"RF VOLTAGE MONITOR");
  FloatToStr(voltage,resultV);
  Lcd_Out(3,1,"Tensao:");
  Lcd_Out(3,12,resultV);

  ADCON0.GO_DONE = 0x01;
  while(ADCON0.GO_DONE);
                        //fonte de bancada
                        // resultADC = ((ADRESH << 8) | (int)ADRESL);
                        //voltage = (resultADC)*(K)-0.19135;
  
 //fonte da maquina
  resultADC =  ((ADRESH << 8) | (int)ADRESL);
  voltage   =  (resultADC)*(K); //bancada: somar 0.27
  
 //configurar interrupcao de estouro do TMER0
  v_soma    =  v_soma + voltage;
  v_media   =  v_soma/v_iMedia;
  v_iMedia++;
 //--------------------------------------------

  if (voltage>1)
  {
   Lcd_CMD(_LCD_CLEAR);
   Lcd_Out(1,2,"RF VOLTAGE MONITOR");
   FloatToStr(voltage, resultV);
   Lcd_Out(3,1,"Tensao:");
   Lcd_Out(3,9,resultV);
   Lcd_Out(3,18,"V");
   delay_ms(300);
   }

  else
  {
   Lcd_CMD(_LCD_CLEAR);
   Lcd_Out(1,2,"RF VOLTAGE MONITOR");
   voltage = voltage*1000;// bancada: somar 156.7392;
   FloatToStr(voltage,resultV);
   Lcd_Out(3,1,"Tensao:");
   Lcd_Out(3,9,resultV);
   Lcd_Out(3,18,"mV");
   delay_ms(300);
   }

}