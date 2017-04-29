#ifndef _i2c_protocol_

#define _i2c_protocol_
  

 #define sda_pin PORTD.RD1
 #define sda_dir TRISD.RD1

 #define scl_pin PORTD.RD0
 #define scl_dir TRISD.RD0

 #define addWrite 0b10101010
 #define addRead  0b10101011
  
  
  void DataLogger();
  void Read_i2c();
  void RW_i2c();
  
  void i2c_Start   ();
  void i2c_stop    ();
  void i2c_sr_start();

  void i2c_low_scl  ();
  void i2c_high_scl ();
  void i2c_low_sda  ();
  void i2c_high_sda ();

                void i2c_write (unsigned char Data);
 unsigned short int  i2c_read  (const    char _ck );
  
 void KeyBoardRead();
#endif