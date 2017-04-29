//***************************************** DEFINES ***********************************************/
#include "screen_frequencys.h"
#include "SCREEN_MAIN.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"
//_________________________________________________________________________________________________


unsigned int freq = 0x00;
unsigned char txt = 0x00;

unsigned char i;




/*----------- interrupcao timer0 --------------------------------------*/
void ConfigTimer0()
{
 //contar 1 uS -->Delay_us 1Khz
 //overflow = 4/fosc * prescaller * (mod_bits - carga_inicial)

 // 1uS = 1/5MHz * 256 * (65536 - carga_inicial)
 //  1uS = 0.2uS*256*65536 * (65536 - carga_inicial)
 //  1uS = 3.355*65536 - 3.55*carga_inicial
 //  1uS = 219902.3256 - 3.55*carga_inicial
 // -219902.3256 = -3.55*carga_inicial
 // carga_inicial = 219902.3256/3.55
 // carga_inicial = 61944.31706
 //carga_inicial_ = 61944

 T0CON = 0b00000111;
 TMR0H = 0xF1;
 TMR0L = 0xF8;

 INTCON.TMR0IF = 0x00;             //limpa a flag
 T0CON.TMR0ON  = 0x01;             //inicia o timer0
}



void ConfigInterrupcaoGeral()
{
 INTCON.GIEH = 0x01;  //chave geral + habilita vetor de alta prioridade de interrupcao
 INTCON.GIEL = 0x00;  //habilita vetor de baixa prioridade
 RCON.IPEN   = 0x01;  //0 -> default -> apenas modo de alta prioridade; 1 -> dois modos de prioridade (alta e baixa)

}



void ConfigInterrupTimer0 ()
{
  INTCON.TMR0IF  = 0x00;  //flag de estouro do timer 0; (iniciar sempre em 0)
  INTCON.TMR0IE  = 0x01;  //prioridade de interrupcao do timer0 (alta prioridade)
  INTCON2.TMR0IP = 0x01;  //habilita interrup individual do timer0
}



void interrupt()
{
  /*if (INTCON.TMR0IF)
  {
    RB0_BIT = ~RB0_BIT;
   }
    INTCON.TMR0IF = 0x00;   //else apaga o apaga o flag
    TMR0H = 0xF1;
    TMR0L = 0xF8;  */
  }


void test2 ();
void test (unsigned char c);
/*--------------------------------------------------------------------------------------*/





//***************************************** GLOBAL VARIABLES *************************************/
extern char          subMenuNumber_freq;
extern unsigned int  analog_read;
extern unsigned char key;
extern char          flag;

volatile  unsigned char  counter = 0x01;
//_________________________________________________________________________________________________


/************************ 'MAIN' *****************************************************************/
void Screen_Frequency_Main ()     //funcao que quando chamada executa a maquina de estados
{
  ChangeSubMenu__Freq ();         //exibe o menu
  NowSubMenu__Freq    ();         //chama o proximo menu
  KeyBoardRead        ();         //faz a varredura do teclado
 }
/**************************************************************************************************/




//***********************************   TELAS DOS MENUS   *****************************************/
/***************** frequencia ****************/
void ScreenFrequency  ()
{
  Lcd_Out(1,3,"Bateria de Teste");
  Lcd_Out(3,2,"<<  FREQUENCIA  >>" );

  if (key == 0x24)  flag.b1 = 0x01;
  if (key == 0x00 && flag.b1)
  {
   flag.b1 = 0x00;
   ClearLcd();
   while (key != 0x27 && key != 0x26)
   {
    Screen_Frequency_Main();
     }
   ClearLcd();
   }
}//end ScreenFreq
/*********************************************/





//************************************ CONTROLE DOS SUBMENUS ****************************************/
//*********************  controle do menu  ***********************/
void ChangeSubMenu__Freq  ()
{
 if (key == 0x23)    flag.b0 = 0x01;                               //botao "left"    foi precionado?
 if (key == 0x25)    flag.b2 = 0x01;                               //botao "right"   foi precionado?

 /******* proxima tela *******/
 if (key == 0x00 && flag.b2)                                       //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b2 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   subMenuNumber_freq++;                                           //incrementa a variavel contadora de menus

   if (subMenuNumber_freq > 0x04) subMenuNumber_freq = 0x01;       //caso chegue no ultimo menu, volte para o primeiro.
  }//end if "NEXT" menu

 /******* antiga tela *******/
 if (key == 0x00 && flag.b0)                                       //botao ja foi solto e a a respectiva flag esta setada.
 {
   flag.b0 = 0x00;                                                 //limpa a flag para uma proxima leitura
   ClearLcd();                                                     //limpa o LCD
   subMenuNumber_freq--;                                           //decrementa a variavel contadora de menus

   if (subMenuNumber_freq < 0x01) subMenuNumber_freq = 0x04;       //caso chegue no primeiro valor do menu, volte para o ultimo
  }//end if "PREV" menu
}//end ChangeMenu()
/************************************************************/





/****************** MENU ATUAL / MENU FUTURO ****************/
void NowSubMenu__Freq    ()
{
  switch(subMenuNumber_freq)
  {
    case 0x01: SubScreenFreq_1  ();  break;
    case 0x02: SubScreenFreq_2  ();  break;
    case 0x03: SubScreenFreq_3  ();  break;
    case 0x04: SubScreenFreq_4  ();  break;
    }//end switch(menuNumber)

}//end NowMenu()
/************************************************************/




//************************************ CONTROLE DAS SUBTELAS ****************************************/
/************ sub tela 1 ***************/
void SubScreenFreq_1  ()
{
 Lcd_Out(1,4,"FREQUENCIMETRO");
 Lcd_Out(3,1,"teste1");
 if (key == 0x24) flag.b1 = 0x01;
 if (key == 0x00 && flag.b1)
  {
    flag.b1 = 0x00;
    test(counter);
  }//end if (apertou e soltou o butao)
}
/************ sub tela 2 ***************/
void SubScreenFreq_2  ()
{
 Lcd_Out(1,4,"FREQUENCIMETRO");
 Lcd_Out(3,1,"teste2");
 }
/************ sub tela 3 ***************/
void SubScreenFreq_3  ()
{
 Lcd_Out(1,4,"FREQUENCIMETRO");
 Lcd_Out(3,1,"teste3");
 }
/************ sub tela 4  **************/
void SubScreenFreq_4  ()
{
 Lcd_Out(1,4,"FREQUENCIMETRO");
 Lcd_Out(3,1,"teste4");
 }
 //****************************************************************************************************/
 
 
 void test (unsigned char c)
 {
  if(c%2 !=0)
  {
   //ConfigTimer0();
   //ConfigInterrupcaoGeral();
   //ConfigInterrupTimer0  ();
   //j++;
   //intToStr(j,str);
   //Lcd_Out(3,3,str);
   RB0_BIT = 0x01;
   }
  else if(c%2 ==0)
  {
   //T0CON.TMR0ON  = 0x00;             //desliga o timer0
   //for(i=0; i<10; i++)
   //{
   // RB1_BIT = 0x01;
   // delay_ms(150);
   // RB1_BIT = 0x00;
   // delay_ms(150);
   // }
   RB0_BIT = 0x00;
   }
   counter++;
  }