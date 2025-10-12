#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const byte ROWS = 4; 
const byte COLS = 4; 
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

const int maxInput = 32;
const int halfMaxInput = maxInput / 2;

char inputArray[maxInput]; 
int arrayIndex = 0; 
char firstline[halfMaxInput];
char secondline[halfMaxInput];

// Forward declarations (prototypes) to ensure functions are known before use
void addCharacter(char key);
void deleteLastCharacter();
void clearArray();
void splitArray();
void printToLCD();
void displayErrorMessage(const char *message);
void clearLCD();

void setup() {
  lcd.init();
  
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    if (key == 'C') {
      clearArray();
      clearLCD();
    } else if (key == 'D') {
      deleteLastCharacter();
    } else {
      if (arrayIndex < maxInput) {
        addCharacter(key);
      } else {
        displayErrorMessage("Input is full");
      }
    }
    splitArray(); 
    printToLCD();
  }
}

void addCharacter(char key) {
  if (arrayIndex < maxInput) {
    inputArray[arrayIndex++] = key;
  }
}

void deleteLastCharacter() {
  if (arrayIndex > 0) {
    arrayIndex--;
    inputArray[arrayIndex] = '\0';
  }
}

void clearArray() {
  arrayIndex = 0;
  for (int i = 0; i < maxInput; i++) {
    inputArray[i] = '\0';
  }
}

void splitArray() {
  for (int i = 0; i < halfMaxInput; i++) {
    firstline[i] = inputArray[i];
    secondline[i] = inputArray[i + halfMaxInput];
  }
}

void printToLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(firstline);
  lcd.setCursor(0, 1);
  lcd.print(secondline);
}

void displayErrorMessage(const char *message) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Error: ");
  lcd.setCursor(0, 1);
  lcd.print(message);
  delay(2000); 
  lcd.clear();
}

void clearLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Input");
  lcd.setCursor(0, 1);
  lcd.print("Cleared");
  delay(2000); 
  lcd.clear();
}
