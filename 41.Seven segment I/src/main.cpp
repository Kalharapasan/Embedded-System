#include <Arduino.h>

const int segmentPins[8] = {2, 3, 4, 5, 6, 7, 8};
const int commonCathodePin = 9;
const byte numbers[11] = {
  B11111100, // 0
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110  // 9
};

void displayNumber(int num) {
  for (int i = 0; i < 8; i++) {
    digitalWrite(segmentPins[i], HIGH);
  }
  for (int i = 0; i < 8; i++) {
    if (bitRead(numbers[num], i) == LOW) {
      digitalWrite(segmentPins[7-i], LOW);
    }
  }
}


void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
  pinMode(commonCathodePin, OUTPUT);
}

void loop() {
  // Count from 0 to 9
  for (int i = 0; i < 10; i++) 
  {
    displayNumber(i);
   // while(1);
    delay(1000); // Display each number for 1 second

   // for (int j = 0; j < 8; j++) {
   // digitalWrite(segmentPins[j], LOW);
  //}
  }
}

