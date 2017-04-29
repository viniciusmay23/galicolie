#include "keyboard.h"


unsigned int analog_read;
unsigned char key = 0x00;



void KeyBoardRead()
{
  analog_read = ADC_Read(0);
  

  if (analog_read>180 && analog_read<230)  //LEFT
  {
    key = 0x23;
    } //"LEFT" foi precionado se a leitura analogica estiver nesse parametro

  else if (analog_read>760 && analog_read<910)  //ENTER
  {
   key = 0x24;                                  // return key;
   } //"CENTER" foi precionado se a leitura analogica estiver nesse parametro

  else if (analog_read>330 && analog_read<400)   //RIGTH
  {
   key = 0x25;
   } //"RIGHT" foi precionado se a leitura analogica estiver nesse parametro

  else if (analog_read>640 && analog_read<750)
  {
   key = 0x26;
   } //"UP" foi precionado se a leitura analogica estiver nesse parametro

  else if (analog_read> 470 && analog_read<550)
  {
   key = 0x27;
   } //"DOWN" foi precionado se a leitura analogica estiver nesse parametro
  else                      
   {
     key = 0x00;
   }
}