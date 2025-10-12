#include <Arduino.h>

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C MyLCD(0x27, 20, 4); 

void setup()
{
  MyLCD.init();
  MyLCD.backlight();
  MyLCD.setCursor(0, 0);
  MyLCD.print("    Hello World!");
  MyLCD.setCursor(0, 1);
  MyLCD.print("    I2C LCD 20x4");
  MyLCD.setCursor(0, 2);
  MyLCD.print("  Arduino Tutorial");
  MyLCD.setCursor(0, 3);
  MyLCD.print("  DeepBlueMbedded");
}

void loop()
{
}