#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 2          
#define DHTTYPE DHT22     
DHT dht(DHTPIN, DHTTYPE); 

float H; 
float T; 
int buzzer = 12;

void setup(){
  lcd.init(); lcd.backlight();  dht.begin();  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);  Serial.println("DHT22 sensor with Arduino Uno R3!");
  pinMode(9, OUTPUT);  pinMode(10, OUTPUT);  pinMode(11, OUTPUT);
}

void loop(){
  delay(2000);
  H = dht.readHumidity();  T = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(H);
  Serial.println(" %; ");
  Serial.print("Temperature: ");
  Serial.print(T);
  Serial.println(" Celsius.\n");

  if(H >= 70.00 && T >= 30.00){
    digitalWrite(9, HIGH);  digitalWrite(10, LOW);  digitalWrite(11, LOW);
   
    lcd.println("   Too warm!    ");
    lcd.setCursor(0, 1);
    lcd.println("   Cool down!   ");
    lcd.setCursor(0, 0);
   
    digitalWrite(buzzer, 1); tone(buzzer, 900, 100);
    delay(400);
    digitalWrite(buzzer, 0); tone(buzzer, 900, 100);
    delay(400);
    digitalWrite(buzzer, 1); tone(buzzer, 900, 100);
    delay(400);
    digitalWrite(buzzer, 0); tone(buzzer, 900, 100);
    delay(400);
  }else{
    digitalWrite(9, LOW);  digitalWrite(10, LOW);  digitalWrite(11, HIGH);
    lcd.println("Temp. & hum. are");  lcd.setCursor(0, 1);
    lcd.println("in normal limits");  lcd.setCursor(0, 0);
    digitalWrite(buzzer, 0);
  }
  if(H < 70.00 && T >= 30.00){
    digitalWrite(9, LOW);  digitalWrite(10, HIGH);  digitalWrite(11, LOW);
    lcd.println("Be ware!        ");  lcd.setCursor(0, 1);
    lcd.println("Temp. too high! ");  lcd.setCursor(0, 0);
    digitalWrite(buzzer, 1); tone(buzzer, 400, 400);  delay(400);
    digitalWrite(buzzer, 0); tone(buzzer, 400, 400);  delay(400);
  }
  if(H >= 70.00 && T < 30.00){
    digitalWrite(9, LOW);  digitalWrite(10, HIGH);  digitalWrite(11, LOW);
    lcd.println("Be ware!        ");  lcd.setCursor(0, 1);
    lcd.println("Hum. too high!  ");  lcd.setCursor(0, 0);
    digitalWrite(buzzer, 1); tone(buzzer, 400, 400);  delay(400);
    digitalWrite(buzzer, 0); tone(buzzer, 400, 400);  delay(400);
  } 
}
 