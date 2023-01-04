#ifndef Config_h
#define Config_h

#ifndef STASSID
#define STASSID "YourSSID"
#define STAPSK  "YourPassword"
#endif

//Put your time zone here: https://github.com/esp8266/Arduino/blob/master/cores/esp8266/TZ.h
#define MYTZ TZ_America_New_York

//pins definitions for TM1637 and can be changed to other ports
#define  CLK_PIN  5 
#define  DIO_PIN  0

#endif //Config_h
