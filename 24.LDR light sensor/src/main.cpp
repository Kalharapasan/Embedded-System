#include <Arduino.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(A2);

  Serial.print("Analog reading = ");
  Serial.println(light); 
  delay(1000);

}
