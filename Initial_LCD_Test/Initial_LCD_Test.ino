#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,10,11,12,13);

void setup() {
  lcd.begin(16, 2);
}

void loop(){
  lcd.setCursor(0,0);
  lcd.print("Welcome to");
  lcd.setCursor(0,1);
  lcd.print("Veldora");
  delay(2000);
  lcd.clear();
  delay(500);
}