#include "Arduino.h"

#if defined(ARDUINO_ARCH_SAMD) || defined(__SAM3X8E__) 
  #define lcd Serial1 
#else
  #include <SoftwareSerial.h>
  SoftwareSerial lcd = SoftwareSerial(0,2);
#endif

  int val = 0;
  int coffee = 86;
  int stress = 67;

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
  
  // clear screen
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10);
  

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
  
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10);
  
  lcd.print("By Joe          "); 
  lcd.print("Version 1.4.4");
  delay(6000);
  
}

void loop() {
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10); //Clear
  
  lcd.print("    FRC 1721    ");
  lcd.print("   Drive Team");
  delay(8000);
    
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10); //Clear
  
  lcd.print("Coffee:");
  lcd.print(coffee);
  lcd.print("%      ");
  lcd.print("stress:");
  lcd.print(stress);
  lcd.print("%");
  delay(8000);

  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10); //Clear
  val + 1;

  if(val = 8) {
    coffee = coffee - 1;
    stress = stress + 1;
    val - 8;

    if (coffee >= 100 || coffee <= 0){
      coffee = 90;
      stress = 24;
    }
  }

}
