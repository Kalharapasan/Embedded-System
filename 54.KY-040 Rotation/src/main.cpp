#include <Arduino.h>
#define ENCODER_CLK 2
#define ENCODER_DT  3

void setup() {
  Serial.begin(115200);
  pinMode(ENCODER_CLK, INPUT);
  pinMode(ENCODER_DT, INPUT);
}

int lastClk = HIGH;

void loop() {
  int newClk = digitalRead(ENCODER_CLK);
  if (newClk != lastClk) {
    lastClk = newClk;
    int dtValue = digitalRead(ENCODER_DT);
    if (newClk == LOW && dtValue == HIGH) {
      Serial.println("Rotated clockwise ⏩");
    }
    if (newClk == LOW && dtValue == LOW) {
      Serial.println("Rotated counterclockwise ⏪");
    }
  }
}