#include <Arduino.h>
const int relay1Pin = 5;
const int relay2Pin = 4;
const int relay3Pin = 3;
const int relay4Pin = 2;

void setup() 
{
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);
  pinMode(relay3Pin, OUTPUT);
  pinMode(relay4Pin, OUTPUT);

  delay(1000);
}

void loop() 
{
  digitalWrite(relay1Pin,HIGH); 
  delay(1000);
  digitalWrite(relay1Pin,LOW);  
  delay(1000);

  digitalWrite(relay2Pin,HIGH);
  delay(1000);
  digitalWrite(relay2Pin,LOW);
  delay(1000);

  digitalWrite(relay3Pin,HIGH);
  delay(1000);
  digitalWrite(relay3Pin,LOW);
  delay(1000);

  digitalWrite(relay4Pin,HIGH);
  delay(1000);
  digitalWrite(relay4Pin,LOW);
  delay(1000);
}
