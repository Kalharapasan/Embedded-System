#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal.h>

#define DS1307_ADDRESS 0x68

LiquidCrystal lcd(12, 11, 10, 9, 8, 7);
byte segment[8][8] =
{
  { B01111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111 },
  { B11111,  B11111,  B11111,  B00000,  B00000,  B00000,  B00000,  B00000 },
  { B11110,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111 },
  { B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B01111 },
  { B00000,  B00000,  B00000,  B00000,  B00000,  B11111,  B11111,  B11111 },
  { B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11111,  B11110 },
  { B11111,  B11111,  B11111,  B00000,  B00000,  B00000,  B11111,  B11111 },
  { B11111,  B00000,  B00000,  B00000,  B00000,  B11111,  B11111,  B11111 }
};

byte zero = 0x00;

int col = 0;

int number, lastMin1, lastMin2, lastHour1, lastHour2;
void showClock();

void setup()
{
  Wire.begin();
  lcd.begin(16, 2);
  for (byte i = 0; i < 8; i++) {
    lcd.createChar(i, segment[i]);
  }
}

void loop()
{
  showClock();
  delay(1000);
}

byte convertToBCD(byte val) { 
  return ( (val / 10 * 16) + (val % 10) );
}

byte convertToDecimal(byte val) { 
  return ( (val / 16 * 10) + (val % 16) );
}

void digit0() 
{
  lcd.setCursor(col, 0);
  lcd.write((byte)0); 
  lcd.write(1);  
  lcd.write(2);
  lcd.setCursor(col, 1); 
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
}

void digit1() 
{
  lcd.setCursor(col, 0);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(col + 1, 1);
  lcd.write(5);
}

void digit2()
{
  lcd.setCursor(col, 0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(col, 1);
  lcd.write(3);
  lcd.write(7);
  lcd.write(7);
}

void digit3() 
{
  lcd.setCursor(col, 0);
  lcd.write(6);
  lcd.write(6);
  lcd.write(2);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(7);
  lcd.write(5);
}

void digit4() 
{
  lcd.setCursor(col, 0);
  lcd.write(3);
  lcd.write(4);
  lcd.write(2);
  lcd.setCursor(col + 2, 1);
  lcd.write(5);
}

void digit5() 
{
  lcd.setCursor(col, 0);
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(col, 1);
  lcd.write(7);
  lcd.write(7);
  lcd.write(5);
}

void digit6() 
{
  lcd.setCursor(col, 0);
  lcd.write((byte)0);
  lcd.write(6);
  lcd.write(6);
  lcd.setCursor(col, 1);
  lcd.write(3);
  lcd.write(7);
  lcd.write(5);
}

void digit7() 
{
  lcd.setCursor(col, 0);
  lcd.write(1);
  lcd.write(1);
  lcd.write(2);
  lcd.setCursor(col + 1, 1);
  lcd.write((byte)0);
}

void digit8()
{
  lcd.setCursor(col, 0);
  lcd.write((byte)0);
  lcd.write((byte)6);
  lcd.write(2);
  lcd.setCursor(col, 1);
  lcd.write(3);
  lcd.write(7);
  lcd.write(5);
}

void digit9()
{
  lcd.setCursor(col, 0);
  lcd.write((byte)0);
  lcd.write((byte)6);
  lcd.write((byte)2);
  lcd.setCursor(col + 2, 1);
  lcd.write((byte)5);
}

void showDigit()
{
  switch (number) {
    case 0: digit0();
      break;
    case 1: digit1();
      break;
    case 2: digit2();
      break;
    case 3: digit3();
      break;
    case 4: digit4();
      break;
    case 5: digit5();
      break;
    case 6: digit6();
      break;
    case 7: digit7();
      break;
    case 8: digit8();
      break;
    case 9: digit9();
      break;
  }
}

void showClock()
{
  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_ADDRESS, 7);

  int seconds = convertToDecimal(Wire.read());
  int minutes = convertToDecimal(Wire.read());
  int hours = convertToDecimal(Wire.read() & 0b111111);
  int dayWeek = convertToDecimal(Wire.read());
  int dayMonth = convertToDecimal(Wire.read());
  int month = convertToDecimal(Wire.read());
  int year = convertToDecimal(Wire.read());

  if (seconds & 1) {
    lcd.setCursor(8, 0);
    lcd.print(".");
    lcd.setCursor(8, 1);
    lcd.print(".");
  } else {
    lcd.setCursor(8, 0);
    lcd.print(" ");
    lcd.setCursor(8, 1);
    lcd.print(" ");
  }

  col = 0;
  number = hours / 10;

  if (lastHour1 != minutes % 10) {
    lcd.setCursor(0, 0);
    lcd.print("   ");
    lcd.setCursor(0, 1);
    lcd.print("   ");
    lastHour1 = minutes % 10;
  }

  showDigit();

  col = 4;
  number = hours % 10;

  if (lastHour2 != minutes % 10) {
    lcd.setCursor(4, 0);
    lcd.print("   ");
    lcd.setCursor(4, 1);
    lcd.print("   ");
    lastHour2 = minutes % 10;
  }

  showDigit();

  col = 9;
  number = minutes / 10;

  if (lastMin1 != minutes % 10) {
    lcd.setCursor(9, 0);
    lcd.print("   ");
    lcd.setCursor(9, 1);
    lcd.print("   ");
    lastMin1 = minutes % 10;
  }

  showDigit();

  col = 13;
  number = minutes % 10;

  if (lastMin2 != minutes % 10) {
    lcd.setCursor(13, 0);
    lcd.print("   ");
    lcd.setCursor(13, 1);
    lcd.print("   ");
    lastMin2 = minutes % 10;
  }

  showDigit();
}

void setDateTime() 
{
  byte seconds = 00; 
  byte minutes = 00; 
  byte hours = 00;
  byte dayWeek = 1;
  byte dayMonth = 17; 
  byte month = 5;
  byte year = 21; 

  Wire.beginTransmission(DS1307_ADDRESS);
  Wire.write(zero); 
  Wire.write(convertToBCD(seconds));
  Wire.write(convertToBCD(minutes));
  Wire.write(convertToBCD(hours));
  Wire.write(convertToBCD(dayWeek));
  Wire.write(convertToBCD(dayMonth));
  Wire.write(convertToBCD(month));
  Wire.write(convertToBCD(year));
  Wire.write(zero); 
  Wire.endTransmission();
}
