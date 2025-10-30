#include <Arduino.h>

#define MOTOR1_PIN 2
#define MOTOR2_PIN 3

void setup() {
  pinMode(MOTOR1_PIN, OUTPUT);
  pinMode(MOTOR2_PIN, OUTPUT);
}

void loop() {
  // Move motor 1
  for (int i = 0; i < 200; i++) {
    digitalWrite(MOTOR1_PIN, HIGH);
    digitalWrite(MOTOR1_PIN, LOW);
    delay(10);
  }

  // Move motor 2
  for (int i = 0; i < 200; i++) {
    digitalWrite(MOTOR2_PIN, HIGH);
    digitalWrite(MOTOR2_PIN, LOW);
    delay(10);
  }
}
