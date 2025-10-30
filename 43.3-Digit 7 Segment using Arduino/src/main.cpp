#include <Arduino.h>

int numbers[][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // zero
  {1, 0, 0, 1, 1, 1, 1}, // one
  {0, 0, 1, 0, 0, 1, 0}, // two
  {0, 0, 0, 0, 1, 1, 0}, // three
  {1, 0, 0, 1, 1, 0, 0}, // four
  {0, 1, 0, 0, 1, 0, 0}, // five
  {0, 1, 0, 0, 0, 0, 0}, // six
  {0, 0, 0, 1, 1, 1, 1}, // seven
  {0, 0, 0, 0, 0, 0, 0}, // eight
  {0, 0, 0, 0, 1, 0, 0}  // nine
};


const int buttonPin = 5;  
int digitPins[] = {2, 3, 4}; 
int segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; 

int buttonState;            
int lastButtonState = LOW; 
int count = 0; 

unsigned long lastDebounceTime = 0;  
unsigned long debounceDelay = 50;    

void intializePins() {
  pinMode(buttonPin, INPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  for (int i = 0; i < 4; i++) {
    pinMode(digitPins[i], OUTPUT);
  }
}

void turnOffDisplay() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], 1);  
  }
}

void displayNumber(int number, int digitPin) {
  digitalWrite(digitPins[digitPin], 1);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], numbers[number][i]);  
  }
  digitalWrite(digitPins[digitPin], 0);
  turnOffDisplay();
}

void displayToThreeDigit(int num) {
  int hundreds = num / 100; 
  int tens = (num / 10) % 10; 
  int ones = num % 10; 
  displayNumber(hundreds, 0);
  displayNumber(tens, 1);
  displayNumber(ones, 2);
}

void getInput() {
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == HIGH) {
        count++;
      }
    }
  }

  lastButtonState = reading;
}

void setup() {
  intializePins();
  turnOffDisplay();
  Serial.begin(9600);
}

void loop() {
  getInput();
  displayToThreeDigit(count);
}
