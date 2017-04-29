#include "WHITCH_BUTTON.h"

 unsigned int  read      = 0x00;
 unsigned char  whichButt = 0x00;
 unsigned char flag      = 0x00;

void KeyBoardRead()
{
  read = ADC_Read(0);
  if      (read>818 && read<858)
                                {RIGHT = 0x00; whichButt = 1;} //"RIGHT" foi precionado se a leitura analogica estiver nesse parametro

  else if (read>676 && read<716)
                                {DOWN  = 0x00; whichButt = 2;} //"DOWN " foi precionado se a leitura analogica estiver nesse parametro
  
  else if (read>541 && read<581)
                                {ENTER = 0x00; whichButt = 3;} //"ENTER" foi precionado se a leitura analogica estiver nesse parametro
  
  else if (read>131 && read>171)
                                {LEFT  = 0x00; whichButt = 4;} //"LEFT " foi precionado se a leitura analogica estiver nesse parametro
  
  else if (read> 72 && read> 102)
                                {UP    = 0x00; whichButt = 5;} //"UP   " foi precionado se a leitura analogica estiver nesse parametro
  
  else
                                {flag  = 0x00; whichButt = whichButt;} //nenhum botao precionado!
 }