#include <Arduino.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);  // LCD: (rs, enable, d4, d5, d6, d7)

const int trigPin = 9;
const int echoPin = 8;

long duration;
int distanceCm, distanceInch;

void setup() {
    lcd.begin(16, 2);

    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

void loop() {
    // Trigger the ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the echo time
    duration = pulseIn(echoPin, HIGH);

    // Convert to distance
    distanceCm   = duration * 0.034  / 2;
    distanceInch = duration * 0.0133 / 2;

    // Display on LCD
    lcd.setCursor(0, 0);
    lcd.print("Distance: ");
    lcd.print(distanceCm);
    lcd.print(" cm");

    lcd.setCursor(0, 1);
    lcd.print("Distance: ");
    lcd.print(distanceInch);
    lcd.print(" inch");

    delay(10);
}
