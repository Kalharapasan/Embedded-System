#include <Arduino.h>
const int redLED=13;
const int yelloLED=12;

void setup() {

  pinMode(redLED,OUTPUT);
  pinMode(yelloLED,OUTPUT);
  Serial.begin(9600);
  Serial.println("Commands : RED,YELLO");
 
 
}

void loop() {

  String command = Serial.readStringUntil('\n');
  if(command == "RED"){
    digitalWrite(redLED,HIGH);
    digitalWrite(yelloLED,LOW);
    delay(500);
    Serial.println("Red LED on");
    Serial.println("Yello LED Off");
  }else if(command == "YELLO"){

  }

}

