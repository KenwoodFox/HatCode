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
