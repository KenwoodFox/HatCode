#include "RTClib.h"

#if defined(ARDUINO_ARCH_SAMD) || defined(__SAM3X8E__) 
  #define lcd Serial1 
#else
  #include <SoftwareSerial.h>
  SoftwareSerial lcd = SoftwareSerial(0,2);
#endif

int matchNum = 1;
int rankNum = 1;
int load = 0;

void setup() {
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
  
  boot(); //Boot Loader Screen
}

void cls(){
  //This function will clear the screen and wait 10ms
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10);
}

void boot(){
  // booting sequence
  lcd.print("Booting potatOS ");
  lcd.print("=");
  delay(520);
  lcd.print("=");
  delay(400);
  for (load = 0; load < 14; load++) {
    lcd.print("=");
    delay(90);
  }
  delay(300);
  cls();
  lcd.print("Version 17.2.1");
  lcd.print("          by Joe");
  delay(6000);

  lcd.write(0xFE);
  lcd.write(0xD0);
  lcd.write(1); 
  delay(10);
}

void red()
{
  lcd.write(0xFE);
  lcd.write(0xD0);
  lcd.write(0xFF);
  lcd.write(0x1);
  lcd.write(0x1);
  //lcd.print("red");
  delay(10);
}

void green()
{
  lcd.write(0xFE);
  lcd.write(0xD0);
  lcd.write(0xFF);
  lcd.write(0xFF);
  lcd.write(0x1);
  //lcd.print("green");
  delay(10);
}

void blue()
{
  lcd.write(0xFE);
  lcd.write(0xD0);
  lcd.write(0xFF);
  lcd.write(0xFF);
  lcd.write(0xFF);
  //lcd.print("blue");
  delay(10);
}


void loop() {
  cls();
  
  lcd.print("    FRC 1721    ");
  lcd.print("   Drive Team");
  delay(8000); //Comment out for testing
  //delay(10); //Comment out for function
    
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10); //Clear

  lcd.print("  Thinking In   ");
  lcd.print("    Progress... ");
  delay(8000);

  red();
  lcd.print("1v1 me m8, ur   ");
  lcd.print("bad at minecraft");
  delay(8000);
  blue();
}
