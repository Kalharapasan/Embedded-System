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
    Serial.println("Red LED on");
    Serial.println("Yello LED Off");
    delay(500);
  }else if(command == "YELLO"){
    digitalWrite(yelloLED,HIGH);
    digitalWrite(redLED,LOW);
    Serial.println("Yello LED on");
    Serial.println("Red LED Off");
    delay(500);
  }else{
    Serial.println("Enter Curect Command!!");
    digitalWrite(yelloLED,LOW);
    digitalWrite(redLED,LOW);
    Serial.println("Yello and Red LEDS Off ");
    delay(500);

  }

}

