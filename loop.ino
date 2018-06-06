void loop() 
{
  cls();

  blue();
  lcd.print("    FRC 1721    ");
  lcd.print("   Drive Team   ");
  delay(frame); //Comment out for testing
  cls();

  lcd.print("  Thinking In   ");
  lcd.print("   Progress...  ");
  delay(frame);
  cls();

  lcd.print("1v1 me m8, ur   ");
  lcd.print("bad at minecraft");
  delay(10);
  while(load <= 32)
  {
    blue();
    delay(200);
    red();
    delay(200);
    load++;
  }
}

