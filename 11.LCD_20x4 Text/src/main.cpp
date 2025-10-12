#include <Arduino.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

uint8_t pacman[8] = {
  0b00000,
  0b00000,
  0b01110,
  0b11011,
  0b11111,
  0b01110,
  0b00000,
  0b00000
};

uint8_t pacmanOpen[] = {
  0b00000,
  0b00000,
  0b01110,
  0b11011,
  0b11100,
  0b01110,
  0b00000,
  0b00000
};

uint8_t dot[] = {
  0b00000,
  0b00000,
  0b00000,
  0b00110,
  0b00110,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  lcd.createChar(1, pacman);
  lcd.createChar(2, dot);
  lcd.begin(20, 4);
  lcd.setCursor(3, 0);
  lcd.print("wokwi-lcd2004");
  lcd.setCursor(2, 2);
  lcd.print("4 lines, 20 cols");
}

void loop() {
  for (int i = 3; i < 16; i++) {
    lcd.setCursor(i, 3);
    lcd.print("\1");
    for (int j = i + 1; j < 16; j++) {
      lcd.setCursor(j, 3);
      lcd.print("\2");
    }
    lcd.createChar(1, pacman);
    delay(200);
    lcd.createChar(1, pacmanOpen);
    delay(200);
    lcd.setCursor(i, 3);
    lcd.print(" ");
  }
  delay(1000);
}
