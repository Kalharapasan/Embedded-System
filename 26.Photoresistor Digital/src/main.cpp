#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

#define LDR_PIN 2

LiquidCrystal_I2C lcd(0x27, 20, 4);

void setup() {
  pinMode(LDR_PIN, INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(2, 0);
  lcd.print("Room: ");
  if (digitalRead(LDR_PIN) == LOW) {
    lcd.print("Light!");
  } else {
    lcd.print("Dark  ");
  }
  delay(100);
}
