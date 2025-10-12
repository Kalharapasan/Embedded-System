#include <Arduino.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

void setup() {
  lcd.begin(16, 2);
  // you can now interact with the LCD, e.g.:
  lcd.print("Hello World!");
}

void loop() {
  // ...
}