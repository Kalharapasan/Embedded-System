#include <Arduino.h>
#include "SevSeg.h"
SevSeg sevseg; 

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; 
  byte hardwareConfig = COMMON_ANODE; 
  bool updateWithDelays = false; 
  bool leadingZeros = false; 
  bool disableDecPoint = false; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
  updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;
  if (millis() - timer >= 100) {
    timer += 100;
    deciSeconds++; 
    if (deciSeconds == 10000) { 
      deciSeconds=0;
    }
    sevseg.setNumber(deciSeconds, 1);
  }
  sevseg.refreshDisplay();
}

