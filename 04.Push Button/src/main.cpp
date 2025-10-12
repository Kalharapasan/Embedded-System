#include <Arduino.h>
#define BUTTON_PIN 4

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
}

int counter = 0;
int lastState = HIGH;
void loop() {
  int value = digitalRead((BUTTON_PIN));
  if (lastState != value) {
    counter++;
    lastState = value;
    Serial.println(counter);
  }
}