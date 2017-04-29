#ifndef _WHITCH_BUTTON_
  #define    _WHITCH_BUTTON_
  #define    RIGHT    flag.b0
  #define    DOWN     flag.b1
  #define    ENTER    flag.b2
  #define    LEFT     flag.b3
  #define    UP       flag.b4
  /*
  extern unsigned int  read      = 0x00;
  extern unsigned int  whichButt = 0x00;
  extern unsigned char flag      = 0x00;
 */
 extern void KeyBoardRead();
 extern unsigned int  whichButt = 0x00;
 extern flag = 0x00;
#endif