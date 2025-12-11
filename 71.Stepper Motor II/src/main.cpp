#include <Arduino.h>
#define Ap 10 
#define Am 11  
#define Bp 9   
#define Bm 8  

void setup() {
  pinMode(Ap,OUTPUT);  pinMode(Am,OUTPUT);
  pinMode(Bp,OUTPUT);  pinMode(Bm,OUTPUT);
}

int I = 0 ;
void loop() {
  if ( I++ <25 ) {  
    delay(10);
    digitalWrite(Bm,LOW) ;  digitalWrite(Ap,HIGH);
    delay(10);
    digitalWrite(Ap,LOW) ;  digitalWrite(Bp,HIGH);
    delay(10);
    digitalWrite(Bp,LOW) ;  digitalWrite(Am,HIGH);
    delay(10);
    digitalWrite(Am,LOW) ;  digitalWrite(Bm,HIGH);
  } else while(1);
}
