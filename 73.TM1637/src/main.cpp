#include <Arduino.h>
#include <TM1637.h>

const int CLK = 2;
const int DIO = 3;

TM1637 tm(CLK, DIO);

void setup() {
  tm.init();
  tm.set(BRIGHT_TYPICAL);
}

unsigned int counter = 0;

void loop() {
  tm.display(0, (counter / 1000) % 10);
  tm.display(1, (counter / 100) % 10);
  tm.display(2, (counter / 10) % 10);
  tm.display(3, counter % 10);

  counter++;
  if (counter == 10000) {
    counter = 0;
  }

  delay(100);
}
