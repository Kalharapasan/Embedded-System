#include <Arduino.h>

long duration, distance; 


struct sonar_S {
  byte trigPin;
  byte echoPin;
  byte ledPin; 
  const char * name;
};
sonar_S sonars[] = {  
  {2, 3, 14, "FL"},
  {4, 5, 15, "FR"},
  {6, 7, 16, "L"},
  {8, 9, 17, "R"},
  {10, 11, 18, "Rear"},
};

byte sensors = sizeof(sonars) / sizeof(sonars[0]); 
byte sensor = 0;

unsigned long timer, interval = 250; 

void setup() {
  Serial.begin (115200);
  for (auto & sonar : sonars)  { 
    pinMode(sonar.echoPin, INPUT);
    pinMode(sonar.trigPin, OUTPUT);
    pinMode(sonar.ledPin, OUTPUT);
  }
}

void loop() {
  if (millis() - timer > interval) { 
    timer = millis(); 
    if (sensor == sensors) { 
      sensor = 0; 
      Serial.println(); 
    }
    myPing(sensor); 
    sensor++; 
  }
}

void myPing(int SR04) {
  auto & sonar = sonars[SR04]; 
  digitalWrite(sonar.ledPin, HIGH); 
  //Serial.print("D");
  Serial.print(sonar.name);
  Serial.print(": ");

  // ping
  // digitalWrite(sonar.trigPin, LOW);
  // delayMicroseconds(2);
  digitalWrite(sonar.trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sonar.trigPin, LOW);
  float distance = pulseIn(sonar.echoPin, HIGH) / 58.2;
  if (distance < 100) Serial.print(" ");
  if (distance < 10) Serial.print(" ");
  Serial.print(distance);
  // Serial.print(pulseIn(sonar.echoPin, HIGH) / 58.2 ); // (time / 2) / 29.1
  // delay(500);
  // print/LED
  Serial.print(" ");
  digitalWrite(sonar.ledPin, LOW);
}