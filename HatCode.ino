#include "RTClib.h"

#if defined(ARDUINO_ARCH_SAMD) || defined(__SAM3X8E__) 
  #define lcd Serial1 
#else
  #include <SoftwareSerial.h>
  SoftwareSerial lcd = SoftwareSerial(0,2);
#endif

int load = 0; //Inital Loader
int frame = 8000; //Time between frames

void setup()
{
  int load = 0;

  lcd.begin(9600);  

  // display size
  lcd.write(0xFE);
  lcd.write(0xD1);
  lcd.write(16);  // 16 columns
  lcd.write(2);   // 2 rows
  delay(10);       

  // contrast
  lcd.write(0xFE);
  lcd.write(0x50);
  lcd.write(200);
  delay(10);       
  
  // brightness. 255 is max
  lcd.write(0xFE);
  lcd.write(0x99);
  lcd.write(255);
  delay(10);       
  
  cls(); //clear screen of param lettering

  blue();
  boot(); //Boot Loader Screen
}
