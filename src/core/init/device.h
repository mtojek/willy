#define PCD8544_DC_PIN 21
#define PCD8544_CS_PIN 9
#define PCD8544_RST_PIN 14
#define PCD8544_CONTRAST 90

#define LED_PIN 38
#define LED_BRIGHTNESS 10

#include <Adafruit_NeoPixel.h>
#include <Adafruit_PCD8544.h>

class Device {
private:
  Adafruit_PCD8544 display;
  Adafruit_NeoPixel led;

  static void printHardwareInfo();
  void initializeDisplay();
  void initializeLED();
  void bootDisplay();
  void bootLED();

public:
  Device();
  void initialize();
};