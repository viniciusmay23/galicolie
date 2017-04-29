#ifndef _screen_temps_
#define _Screen_temps_
  void SubScreenTemp_1         ();                   //SubTelaTemp1: Temperatura ambiente
  void SubScreenTemp_2         ();                   //SubTelaTemp2: Temperatura na ponteira
  void SubScreenTemp_3         ();                   //SubTelaTemp3: Teste do sensor DS18x20

  void ChangeSubMenu__Temp     ();
  void NowSubMenu__Temp        ();
  void ScreenTemperature       ();                   //Tela4: Temperatura das ponteiras, temperat ambiente e teste do sensor
  void Screen_Temperature_Main ();
  
  void KeyBoardRead();
#endif