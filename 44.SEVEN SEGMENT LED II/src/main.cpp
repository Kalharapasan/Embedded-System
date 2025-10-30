#include <Arduino.h>
int disp_pin[7];
const bool COMMON_ANODE = true;

void define_segment_pins(int a, int b, int c, int d, int e, int f, int g)	
{  
  disp_pin[0] = a;
  disp_pin[1] = b;
  disp_pin[2] = c;
  disp_pin[3] = d;
  disp_pin[4] = e;
  disp_pin[5] = f;
  disp_pin[6] = g;
}

void display_number(int num)	
{
  static const uint8_t digits[10][7] = {
    {1,1,1,1,1,1,0}, // 0
    {0,1,1,0,0,0,0}, // 1
    {1,1,0,1,1,0,1}, // 2
    {1,1,1,1,0,0,1}, // 3
    {0,1,1,0,0,1,1}, // 4
    {1,0,1,1,0,1,1}, // 5
    {1,0,1,1,1,1,1}, // 6
    {1,1,1,0,0,0,0}, // 7
    {1,1,1,1,1,1,1}, // 8
    {1,1,1,1,0,1,1}  // 9
  };

  if (num < 0 || num > 9) return;
  uint8_t onState = COMMON_ANODE ? LOW : HIGH;
  uint8_t offState = COMMON_ANODE ? HIGH : LOW;

  for (int seg = 0; seg < 7; ++seg) {
    digitalWrite(disp_pin[seg], digits[num][seg] ? onState : offState);
  }
}

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  define_segment_pins(0,1,2,3,4,5,6);
}

void loop() {
  int i;
  for(i = 9; i>=0; i--)
  {
    display_number(i);
    delay(1000);
  }
  for(i = 0; i<=9; i++)
  {
    display_number(i);
    delay(1000);
  }
}