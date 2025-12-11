#include <Arduino.h>
#include <AccelStepper.h>
AccelStepper stepper; 
const byte PositionPot = A0;
const byte AccelerationPot = A1;
void setup()
{  
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(35);
}
void loop()
{
  int analog_in = analogRead(PositionPot);
  stepper.setAcceleration(analogRead(AccelerationPot));
  stepper.moveTo(analog_in);
  stepper.run();
}