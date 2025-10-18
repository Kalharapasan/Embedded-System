#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

int trigPin = 7;
int echoPin = 2;
int LedPinR = 8;
int LedPinG = 4;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
pinMode(LedPinR, OUTPUT);
pinMode(LedPinG, OUTPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
lcd.init(); // initialize the lcd
lcd.backlight();


Serial.begin(9600);
Serial.print("Distance from the object :\n");
}
void loop() {
  // put your main code here, to run repeatedly:
int distance;
int duration;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration=pulseIn(echoPin,HIGH);
distance = duration * 0.0344/2;

Serial.print("Distance: ");
Serial.println(distance);

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Distance");
lcd.setCursor(0,1);
lcd.print(distance);

if (distance >= 390){
  digitalWrite(LedPinR, HIGH);
  lcd.setCursor(9,0);
  lcd.print("Not");
  lcd.setCursor(9,1);
  lcd.print("Recived");
  delay(1500);
}else{
  digitalWrite(LedPinR, LOW);
  lcd.setCursor(9,0);
  lcd.print("Recived");
  delay(1500);

}
  if (distance <= 390){
    digitalWrite(LedPinG, HIGH);
  }else{
    digitalWrite(LedPinG, LOW);
  }

}
