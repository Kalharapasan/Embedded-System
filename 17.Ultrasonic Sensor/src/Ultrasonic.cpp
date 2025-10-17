#if ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin, unsigned long timeOut) {
  trig = trigPin;
  echo = echoPin;
  threePins = trig == echo ? true : false;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  timeout = timeOut;
}

unsigned int Ultrasonic::timing() {
  if (threePins)
    pinMode(trig, OUTPUT);

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  if (threePins)
    pinMode(trig, INPUT);
  
  previousMicros = micros();
  while(!digitalRead(echo) && (micros() - previousMicros) <= timeout); 
  previousMicros = micros();
  while(digitalRead(echo)  && (micros() - previousMicros) <= timeout); 

  return micros() - previousMicros; 
}


unsigned int Ultrasonic::read(uint8_t und) {
  return timing() / und / 2;  
}


unsigned int Ultrasonic::distanceRead(uint8_t und) {
  return read(und);
}