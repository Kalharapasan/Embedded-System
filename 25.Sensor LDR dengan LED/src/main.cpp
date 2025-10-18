#include <Arduino.h>

int ldrPin = A0;     // LDR pin
int ldrVal = 0;      // Value of LDR
int ledPin = 2;     // Build in LED pin

const float GAMMA = 0.7;
const float RL10 = 50;
void setup() {
  Serial.begin(9600);  
   pinMode(2, OUTPUT);
}
void loop() {
  ldrVal = analogRead(ldrPin); 
   float voltage = ldrVal / 1024. * 5;
  float resistance = 2000 * voltage / (1 - voltage / 5);
  float lux = pow(RL10 * 1e3 * pow(10, GAMMA) / resistance, (1 / GAMMA));

 if (lux < 200) {            
    digitalWrite(ledPin, HIGH);  
  } else {
    digitalWrite(ledPin, LOW);  
  }
  Serial.println(lux);      
  delay(1000);                 
}
