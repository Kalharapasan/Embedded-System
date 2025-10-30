#include <Arduino.h>
#include <Wire.h>

void setup() 
{
  pinMode( 13, OUTPUT);      
  pinMode( 11, OUTPUT);     
  digitalWrite( 11, HIGH);   
  Serial.begin( 115200);
  Wire.begin();
  delay( 100);
  digitalWrite( 13, HIGH);   
  digitalWrite( 13, LOW);
  tone(8, 20000);
  Serial.print( "Hello World");
  Wire.beginTransmission( 8);
  Wire.endTransmission();
  delayMicroseconds( 100);
  Wire.beginTransmission( 0x68);
  Wire.write( 0);
  Wire.endTransmission();
  delayMicroseconds( 100);    
  Wire.requestFrom( 0x68, 1);
  noTone( 8);
  serialToggle( "Wokwi");
  digitalWrite( 13, HIGH);   
  digitalWrite( 13, LOW);
}

void loop() {}
#define serialToggleHIGH   bitSet(PORTB,3)
#define serialToggleLOW    bitClear(PORTB,3)
#define serialToggleCYCLES 1665

void serialToggle( char *text)
{
  for( int i=0; i<strlen(text); i++)      
  {
    noInterrupts();                      
    serialToggleLOW;                      
    __builtin_avr_delay_cycles(serialToggleCYCLES);  

    for( int j=0; j<8; j++)     
    {
      if( bitRead( text[i], j) == 0)
      {
        serialToggleLOW;
      }
      else
      {
        serialToggleHIGH;
      }
      __builtin_avr_delay_cycles(serialToggleCYCLES);  
    }
    serialToggleHIGH;                    
    __builtin_avr_delay_cycles( 2 * serialToggleCYCLES);
    interrupts();
  }
}