#include <Arduino.h>
#define MQ2pin 8

int sensorValue;  

void setup() {
	Serial.begin(9600); 
	Serial.println("MQ2 warming up");
	delay(200);
}

void loop() {
	sensorValue = digitalRead(MQ2pin); 
	Serial.print("Digital Output: ");
	Serial.print(sensorValue);
	if (sensorValue) {
		Serial.println("  |  Smoke: -");
	} else {
		Serial.println("  |  Smoke: Detected!");
	}
	
	delay(2000); 
}