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


