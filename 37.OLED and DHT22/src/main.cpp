#include <dht.h>
#include <TinyWireM.h>
#include <Tiny4kOLED.h>

#define DHT22_PIN PB1

const unsigned char  img_heart_small[] PROGMEM = {
  0x00, 0x00, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x80, 0x80, 0x80, 0xc0, 0xe0, 0xe0, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00, 0x00, 0x00
};

const unsigned char  img_heart_big[] PROGMEM = {
  0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0xe0, 0xe0, 0xf0, 0xf8, 0xf8, 0xf8, 0xf8, 0xf0, 0xe0, 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff, 0x7f, 0x3f, 0x1f, 0x0f, 0x07, 0x03, 0x01, 0x00
};

const unsigned char  img_thermometer[] PROGMEM = {
  0x00, 0xfe, 0x03, 0xfe, 0x50,
  0x00, 0xff, 0x00, 0xff, 0x55,
  0x60, 0x9f, 0x80, 0x9f, 0x65,
};

dht DHT;

void splash() {
  oled.clear();
  oled.setCursor(15, 1);
  oled.print(F("ATtiny85+SSD1306"));

  oled.setCursor(42, 3);
  oled.print(F("Example"));

  oled.setCursor(35, 7);
  oled.print(F("wokwi.com"));
}

void heartBeat() {
  static char big = 1;
  static long startTime = 0;
  long currentTime;
  currentTime = millis();
  if ((currentTime - startTime) > 200) {
    startTime = currentTime;
    big = 1 - big;

    if (big) {
      oled.bitmap(20, 4, 37, 6, img_heart_big);
    } else {
      oled.bitmap(20, 4, 37, 6, img_heart_small);
    }
  }
}

void prepareDisplay() {
  unsigned int i, k;
  unsigned char ch[5];

  oled.clear();
  oled.begin();

  oled.setCursor(20, 1);
  oled.print(F("ATtiny85+SSD1306"));
  oled.setCursor(3, 2);
  oled.print(F("temperature|humidity"));

  oled.bitmap(105, 4, 110, 7, img_thermometer);
  oled.setCursor(57, 4);
  oled.print(F("24.0C"));
  oled.setCursor(57, 5);
  oled.print(F("40.0%"));

  oled.bitmap(10, 5, 17, 2, img_heart_small);
}

float getTemperature() {
  return DHT.temperature;
}

float getHumidity() {
  return DHT.humidity;
}

void setup() {
  pinMode(DHT22_PIN, INPUT);
  oled.begin(128, 64, sizeof(tiny4koled_init_128x64br), tiny4koled_init_128x64br);
  oled.setFont(FONT6X8);
  oled.clear();
  oled.on();
  splash();
  delay(3000);
  prepareDisplay();
}

void loop() {
  static long startTime = 0;
  long currentTime;

  DHT.read22(DHT22_PIN);
  currentTime = millis();

  if ((currentTime - startTime) > 1000) {
    startTime = currentTime;
    float temperature = getTemperature();
    oled.setCursor(57, 4);
    oled.print(temperature, 1);
    oled.print("C  ");
    float humidity = getHumidity();
    oled.setCursor(57, 5);
    oled.print(humidity, 1);
    oled.print("%  ");

    oled.bitmap(105, 4, 110, 7, img_thermometer);
  }

  heartBeat();
}
