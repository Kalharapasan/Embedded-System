#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

#define ENCODER_CLK 2
#define ENCODER_DT  3
#define ENCODER_SW  4

int counter = 0;


void readEncoder();

void setup() {
  lcd.init();
  lcd.backlight();
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
  pinMode(ENCODER_SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(ENCODER_CLK), readEncoder, FALLING);
}

void readEncoder() {
  int dtValue = digitalRead(ENCODER_DT);
  if (dtValue == HIGH) {
    counter++; 
  }
  if (dtValue == LOW) {
    counter--; 
  }
}

int getCounter() {
  int result;
  noInterrupts();
  result = counter;
  interrupts();
  return result;
}

void resetCounter() {
  noInterrupts();
  counter = 0;
  interrupts();
}

void loop() {
  lcd.setCursor(3, 0);
  lcd.print("Counter:");
  lcd.setCursor(7, 1);
  lcd.print(getCounter());
  lcd.print("        ");

  if (digitalRead(ENCODER_SW) == LOW) {
    resetCounter();
  }
}
