#include <Arduino.h>

#include "Ultrasonic.h"

Ultrasonic ultrasonic(12, 13);
int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {

  distance = ultrasonic.read(CM);

  Serial.print("Distance in CM: ");
  Serial.println(distance);

  distance = ultrasonic.read(INC);

  Serial.print("Distance in Inches: ");
  Serial.println(distance);

  delay(1000);
}