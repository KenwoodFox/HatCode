void boot()
{
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

  cls();
  blue();
}
