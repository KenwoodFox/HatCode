void cls()
{
  //This function will clear the screen and wait 10ms
  lcd.write(0xFE);
  lcd.write(0x58);
  delay(10);
}
