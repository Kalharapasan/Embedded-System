#include <Arduino.h>
const int a = 3;
const int b = 4;
const int c = 5;
const int d = 6;
const int e = 7;
const int f = 8;
const int g = 9;
const int h = 10;
void setup()
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(h, OUTPUT);
}
void writeSegments(bool A, bool B, bool C, bool D, bool E, bool F, bool G, bool H)
{
  digitalWrite(a, A ? HIGH : LOW);
  digitalWrite(b, B ? HIGH : LOW);
  digitalWrite(c, C ? HIGH : LOW);
  digitalWrite(d, D ? HIGH : LOW);
  digitalWrite(e, E ? HIGH : LOW);
  digitalWrite(f, F ? HIGH : LOW);
  digitalWrite(g, G ? HIGH : LOW);
  digitalWrite(h, H ? HIGH : LOW);
}

void displayDigit(int digit)
{
  switch (digit)
  {
    case 0: 
      writeSegments(true, true, true, true, true, true, false, false);
      break;
    case 1: 
      writeSegments(false, true, true, false, false, false, false, false);
      break;
    case 2: 
      writeSegments(true, true, false, true, true, false, true, false);
      break;
    case 3: 
      writeSegments(true, true, true, true, false, false, true, false);
      break;
    case 4: 
      writeSegments(false, true, true, false, false, true, true, false);
      break;
    case 5: 
      writeSegments(true, false, true, true, false, true, true, false);
      break;
    case 6: 
      writeSegments(true, false, true, true, true, true, true, false);
      break;
    case 7:
      writeSegments(true, true, true, false, false, false, false, false);
      break;
    case 8: 
      writeSegments(true, true, true, true, true, true, true, false);
      break;
    case 9: 
      writeSegments(true, true, true, true, false, true, true, false);
      break;
    default:
      writeSegments(false, false, false, false, false, false, false, false);
      break;
  }
}

void displayDotOnly()
{
  writeSegments(false, false, false, false, false, false, false, true);
}

void loop()
{
  
  for (int i = 1; i <= 9; ++i)
  {
    displayDigit(i);
    delay(1000);
  }
  displayDigit(0);
  delay(1000);
  displayDotOnly();
  delay(1000);
}




