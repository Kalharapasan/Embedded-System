#include <Arduino.h>
#include <TM1637.h>

TM1637 TM1, TM2, TM3;    

unsigned long previousMillisClock; 
const unsigned long intervalClock = 1000;
bool colon = false;       

unsigned long previousMillisCountDown;  
const unsigned long intervalCountDown = 100;

int clockSeconds;           
int clockMinutes;           
int countDown = 9999;       

char buffer[5];         

void setup()
{
  Serial.begin(115200);
  Serial.println("Type your text for the third display.");
  Serial.println("Now displaying \"----\".");
  TM1.begin(8, 9, 4);       
  TM1.displayClear();
  TM1.setBrightness(7);     
  TM2.begin(6, 7, 4);       
  TM2.displayClear();
  TM2.setBrightness(7);    
  TM3.begin(4, 5, 4);       
  TM3.displayClear();
  TM3.setBrightness(7);     
  TM3.displayPChar("----"); 
}

void loop()
{
  unsigned long currentMillis = millis();
  if( currentMillis - previousMillisClock >= intervalClock)
  {
    previousMillisClock += intervalClock; 

    TM1.displayTime(clockMinutes,clockSeconds, colon); 
    colon = !colon; 
    clockSeconds++;
    if (clockSeconds >= 60)
    {
      clockSeconds = 0;
      clockMinutes++;
      if (clockMinutes >= 60)
      {
        clockMinutes = 0;
      }
    }
  }
  if( currentMillis - previousMillisCountDown >= intervalCountDown)
  {
    previousMillisCountDown += intervalCountDown; 
    TM2.displayInt(countDown); 

    countDown--; 
    if (countDown < 0)
    {
      countDown = 9999;
    }
  }
  if (Serial.available() > 0)
  {
    int inChar = Serial.read();
    if (isprint(inChar))
    {
      for( int i=0; i<3; i++) 
        buffer[i] = buffer[i+1];

      buffer[3] = (char) inChar; 
      buffer[4] = '\0';      
    }
    TM3.displayPChar(buffer); 
  }
}
