#include <Arduino.h>

// #include <MD_Parola.h>
// #include <MD_MAX72xx.h>
// #define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
// #define MAX_DEVICES 4
// #define CS_PIN 3
// MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// const float BETA = 3950; // should match the Beta Coefficient of the thermistor

// void setup() {
//   // put your setup code here, to run once:
//  myDisplay.begin();
//   // Set the intensity (brightness) of the display (0-15):
//   myDisplay.setIntensity(0);
//   // Clear the display:
//   myDisplay.displayClear();
//   float celsius;
//   myDisplay.displayText(celsius, PA_CENTER, 100, 0, PA_SCROLL_LEFT, PA_SCROLL_LEFT);
// Serial.begin(9600);

// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   // myDisplay.setTextAlignment(PA_CENTER);
//   // myDisplay.print("Temperature");
//   int analogValue = analogRead(10);
//  float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
//  Serial.print("Temperature: ");
//   Serial.print(celsius);
//   Serial.println(" ℃");
//   delay(2000);
//    if (myDisplay.displayAnimate()) {
//     myDisplay.displayReset();}
// }



#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 4
#define CS_PIN 10
MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
const float BETA = 3950; 

void setup() {
 myDisplay.begin();
  myDisplay.setIntensity(0);
  myDisplay.displayClear();
}

void loop() {
 int analogValue = analogRead(A0);
 float celsius = 1 / (log(1 / (1023. / analogValue - 1)) / BETA + 1.0 / 298.15) - 273.15;
String temp = (String) celsius;
myDisplay.print(temp);
delay(1000);
}