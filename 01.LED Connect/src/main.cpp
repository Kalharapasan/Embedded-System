#include <Arduino.h>

const int LEDPIN =13;

void setup() {
  pinMode (LEDPIN,OUTPUT);

}

void loop() {

  digitalWrite(LEDPIN,HIGH);
  delay(500);
  digitalWrite(LEDPIN,LOW);
  delay(500);
  
}

