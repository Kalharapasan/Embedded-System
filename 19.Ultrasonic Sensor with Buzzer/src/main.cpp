#include <Arduino.h>
#define echoPin 8
#define trigPin 10
const int buzzer = 9;


long duration;
int distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("Ultrasonic Sensor HC-SRC04 Test");
  Serial.println("with Arduino UNO R3");
}

void loop() 
{
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if(distance < 5){
    tone(buzzer, 500);
    delay(1000);
    noTone(buzzer);
  }
}
