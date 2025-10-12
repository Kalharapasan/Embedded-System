#include <Arduino.h>
const int redLED=13;
const int yellowLED=12;

void setup() {

  pinMode(redLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  Serial.begin(9600);
  Serial.println("Commands : RED On for =R,YELLOW on for =Y");
 
 
}

void loop() {

  String command = Serial.readStringUntil('\n');
  if(command == "R"){
    digitalWrite(redLED,HIGH);
    digitalWrite(yellowLED,LOW);
    Serial.println("Red LED on");
    
  }else if(command == "Y"){
    digitalWrite(yellowLED,HIGH);
    digitalWrite(redLED,LOW);
    Serial.println("Yellow LED on");
    
  }else{
    Serial.println("Enter Correct Command!!");
    digitalWrite(yellowLED,LOW);
    digitalWrite(redLED,LOW);
  }

}

