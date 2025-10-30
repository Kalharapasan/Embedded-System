#include <Arduino.h>
#include <Stepper.h>

const int stepsPerRevolution = 200;

Stepper stepper1(stepsPerRevolution, 2, 3, 4, 5);
Stepper stepper2(stepsPerRevolution, 8, 9, 10, 11);

void setup() {
  stepper1.setSpeed(20);
  stepper2.setSpeed(90);
  Serial.begin(9600);
}

void loop() {
  Serial.println("clockwise");
  stepper1.step(stepsPerRevolution);
  stepper2.step(stepsPerRevolution);
  delay(500);
  Serial.println("counterclockwise");
  stepper1.step(-stepsPerRevolution);
  stepper2.step(-stepsPerRevolution);
  delay(500);
}