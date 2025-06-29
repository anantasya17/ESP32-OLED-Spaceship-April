#define SSD1306_NO_SPLASH
#include  <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display (SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// --> Disini letakkan bitmap
static const unsigned char PROGMEM kiss_bmp[] = {
  B00000000, B00000000,
  B00011000, B00011000,
  B00111100, B00111100,
  B01111110, B01111110,
  B01011010, B01011010,
  B01111110, B01111110,
  B01000010, B01000010,
  B00100100, B00100100,
  B00011000, B00011000,
  B00000000, B00000000,
  B00001000, B00001000,
  B00000100, B00000100,
  B00001000, B00001000,
  B00010000, B00010000,
  B00000000, B00000000,
  B00000000, B00000000
};

void setup() {
   Serial.begin(115200);

    if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)) {
      Serial.println(F("SSD1306 allocation failed"));
      for(;;);
    }

    display.clearDisplay();
    display.drawBitmap(56, 24, kiss_bmp, 16, 16, WHITE); //POSISI TENGAH OLED
    display.display();
}

void loop() {
}
