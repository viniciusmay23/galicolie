/********************INCLUDES***********************/
#include "i2c_protocol.h"
#include "LCD.h"
#include "BUTTONS.H"
#include "keyboard.h"
#include "SCREEN_MAIN.h"
/***************************************************/




/*********************DEFINES***********************/
 
 #define sda_pin PORTD.RD1
 #define sda_dir TRISD.RD1

 #define scl_pin PORTD.RD0
 #define scl_dir TRISD.RD0
 
 #define slaveAddress 0b1010101
 #define addressWrite 0b10101010
 #define addressRead  0b10101011

/***************************************************/




/******************PROTOTYPES***********************/
 void i2c_Start   ();
 void i2c_stop    ();
 void i2c_sr_start();

 void i2c_low_scl  ();
 void i2c_high_scl ();
 void i2c_low_sda  ();
 void i2c_high_sda ();
  
                void i2c_write (unsigned char Data);
 unsigned short int  i2c_read  (const    char _ck );

 void i2c_ack  (void);
 void i2c_nack (void);

 void Read_i2c();
 void RW_i2c();
/***************************************************/



/********************** MAIN ***********************/
void DataLogger()
{
 RW_i2c();
 Read_i2c();
 }


void Read_i2c()
{
 ANSELC    = 0x00;      //all portC in digital mode
 ANSELB    = 0x00;      //all portB in digital mode


 TRISD.RD0 |= 0x01;
 PORTD.RD0 |= 0x01;
 TRISD.RD1 |= 0x01;
 PORTD.RD1 |= 0x01;


 TRISB = 0x00;
 latb = 0x00;
 

 i2c_Start();
 i2c_Write(addressWrite);
 i2c_Write(12);
 i2c_sr_start();
 i2c_Write(addressRead);
 portb = i2c_read(0u);
 i2c_stop();
 delay_ms(3000);
 }


void RW_i2c()
{
 ANSELC    = 0x00;      //all portC in digital mode
 ANSELB    = 0x00;      //all portB in digital mode
 

 TRISD.RD0 |= 0x01;
 PORTD.RD0 |= 0x01;
 TRISD.RD1 |= 0x01;
 PORTD.RD1 |= 0x01;


 TRISB = 0x00;
 latb = 0x00;
 
/**************** i2c******************/

 i2c_Start();               //i2c start

 i2c_write(addressWrite);   //modo de gravacao
 i2c_write(12);           //endereço 23 por exemplo...
 i2c_write(0b00000101);           //data
 i2c_stop();

 delay_100ms();

 i2c_start();
 i2c_write(addressWrite);   //modo de gravacao
 i2c_write(12);           //endereço acima

 i2c_sr_start();

 i2c_write(addressRead);   //
 //latb = i2c_read(1u);
 latb = i2c_read(0u);  //0 --> nack
 delay_ms(3000);
 i2c_stop();

}//end 'main'

/************************************************/






/****************** functions *******************/

 void i2c_low_scl  ()
 {
  scl_pin = 0x00;     //nivel 0
  scl_dir = 0x00;     //pino como saida digital
  delay_us(10);
 }



 void i2c_high_scl ()
 {
  scl_pin = 0x01;     //nivel 1
  scl_dir = 0x01;     //pino como entrada digital
  delay_us(10);
 }



 void i2c_low_sda  ()
 {
  sda_pin = 0x00;     //nivel 0
  sda_dir = 0x00;     //pino como saida digital
  delay_us(10);
 }



 void i2c_high_sda ()
 {
  sda_pin = 0x01;                  //nivel 1
  sda_dir = 0x01;                  //pino como entrada digital
  delay_us(10);
 }



void i2c_write(unsigned char Data)
{
 unsigned char n;                  //variavel local 'n' usada para contagem

   for(n=0;n<8;n++)
   {
    if(Data&0x80)                  //0x80 --> 0b10000000 --> o bit 8 eh 1?
     i2c_high_sda();
    else
     i2c_low_sda ();

    i2c_high_scl();                //pulso em scl
    i2c_low_scl ();
    Data <<=1;                     //pega o proximo bit (trem de pulso deslocado)
    }
    i2c_high_sda();                //sda em alta impedancia

    i2c_high_scl();
    i2c_low_scl ();
}//end i2c_write




unsigned short int  i2c_read  (const    char _ck )
{
 unsigned short int DATA=0, N=0;

 i2c_high_sda();
 i2c_low_scl ();

 for (N=0; N<8; N++)
 {
  i2c_high_scl();
  if(sda_pin)
   DATA = (DATA<<1) | 0x01;        //SE SIM: ESCREVE '1' E ROTACIONA
  else
   DATA = DATA<<1;                //SE NAO: ESCREVE '0' E ROTACIONA
  i2c_low_scl();
  }

 if(_ck==1u) i2c_ack ();
 else        i2c_nack();
return (DATA);
}//end i2c_read




void i2c_stop()
 {
  i2c_low_scl ();
  i2c_low_sda ();
  i2c_high_scl();
  i2c_high_sda();
 }//end i2c_stop




void i2c_sr_start()
 {
  i2c_low_scl  ();
  i2c_high_sda ();

  i2c_high_scl ();
  i2c_low_sda  ();

  i2c_low_scl  ();
 }//end i2c_sr_start()




void i2c_Start()
 {
  i2c_low_scl  ();
  i2c_high_sda ();

  i2c_high_scl ();
  i2c_low_sda  ();

  i2c_low_scl  ();
 }//end i2c_start




void i2c_ack  (void)
{
 i2c_low_sda  ();
 i2c_high_scl ();
 i2c_low_scl  ();
 i2c_high_sda ();
}



void i2c_nack (void)
{
 i2c_high_sda ();
 i2c_high_scl ();
 i2c_low_scl  ();
}