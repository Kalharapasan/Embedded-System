#include <Arduino.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

float cm;
float inches;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
	pinMode(triggerPin, OUTPUT);  
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
	pinMode(echoPin, INPUT);
	return pulseIn(echoPin, HIGH);
}

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.print("--> Distance <--");
	delay(3000);
	lcd.clear();
}

void loop()
{
  cm = 0.0344/2 * readUltrasonicDistance(3, 2);
	inches = (cm / 2.54);
  /*
	Serial.print("Inches ");
	Serial.print(inches, 1);
	Serial.print("\t");
  Serial.print("cm ");
	Serial.println(cm, 1);
	*/
	lcd.setCursor(0,0);
	lcd.print("Inches");
	lcd.setCursor(4,0);
	lcd.setCursor(12,0);
	lcd.print("cm");
	lcd.setCursor(1,1);
	lcd.print(inches, 1);
	lcd.setCursor(11,1);
	lcd.print(cm, 1);
	lcd.setCursor(14,1);
	delay(2000);
	lcd.clear();
}