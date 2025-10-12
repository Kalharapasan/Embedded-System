#include <Arduino.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
	lcd.begin(16,2);
	lcd.print("Hello (^__^)");
        lcd.setCursor(0, 1);
        lcd.print("ThaiEasyElec");
}

void loop()
{

}