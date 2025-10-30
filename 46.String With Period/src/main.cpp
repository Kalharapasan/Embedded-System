#include <Arduino.h>
#include <string.h>
#include "SevSeg.h"
SevSeg sevseg; 

#define MAX_NUMBER_STRINGS 12
#define MAX_STRING_SIZE 12
char testStrings[MAX_NUMBER_STRINGS][MAX_STRING_SIZE];

#define PATTERN_CHANGE_TIME 1000
unsigned long timer;
byte testStringsPos = 0;

void setup() {
  byte numDigits = 4;
  byte digitPins[] = {2, 3, 4, 5};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  bool resistorsOnSegments = false; 
  byte hardwareConfig = COMMON_ANODE; 
  bool updateWithDelays = false; 
  bool leadingZeros = false; 

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, updateWithDelays, leadingZeros);
  sevseg.setBrightness(90);
  timer = millis() - PATTERN_CHANGE_TIME;
  strcpy(testStrings[0], "A..BC.");
  strcpy(testStrings[1], "....");
  strcpy(testStrings[2], ".   ");
  strcpy(testStrings[3], " .  ");
  strcpy(testStrings[4], "  . ");
  strcpy(testStrings[5], "   .");
  strcpy(testStrings[6], ".ABC");
  strcpy(testStrings[7], "A.BCD");
  strcpy(testStrings[8], "A.B.CD");
  strcpy(testStrings[9], "A.B.C.D");
  strcpy(testStrings[10], "A.B.C.D.");
  strcpy(testStrings[11], ". . . .");
}

void loop() {
  if (millis() > (timer + PATTERN_CHANGE_TIME)) {
    sevseg.setChars(testStrings[testStringsPos]);
    testStringsPos++;
    if (testStringsPos >= MAX_NUMBER_STRINGS) testStringsPos = 0;
    timer = millis();
  }
  sevseg.refreshDisplay(); 
}
