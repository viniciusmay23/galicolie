/*###############################################################################################*\
  ************************************************************************************************
  **********************       Project Name: GALICOLIE                                ************
  **********************       Project features: ABOUT BHS 156                        ************
  **********************                                                              ************
  **********************       MCU features:  P18f45K22 (MASTER)                      ************
  **********************       Crystal OSC:   20 MHz                                  ************
  **********************                                                              ************
  **********************       Firmware purpose: Configure fuses device target        ************
  **********************       Version: 1.0  date: 12/25/2016 last update: 05/03/17   ************
  **********************                                                              ************
  **********************       Author: viniciusmay23                                  ************
  **********************       Company: histerese copyrights HEST(c)                  ************
  **********************                BODY HEALTH BRASIL (c)                        ************
  **********************                                                              ************
  ************************************************************************************************
/*###############################################################################################*/


//******************************************* P.S ************************************************/
/*LIBRARRY FUSES*/


#ifndef FUSES_H_							 //  IF:    not defined "FUSES_H_"                   //

#define FUSES_H_							 //  THEN:  define "FUSES_H"                         //
void ConfigMCU();						     //  MAIN:  main function this lib (see in FUSES.C)  //	

Lcd_Init();							         //  LCD:   self function of mikroc compilator (IDE) //
Lcd_Cmd(_LCD_CLEAR); 				         //  LCD:   self function of mikroc compilator (IDE) //
Lcd_Cmd(_LCD_CURSOR_OFF);				     //  LCD:   self function of mikroc compilator (IDE) //

#endif