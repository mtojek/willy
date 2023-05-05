#define PCD8544_DC_PIN 21
#define PCD8544_CS_PIN 9
#define PCD8544_RST_PIN 14

#include <Adafruit_PCD8544.h>

class Device {
private:
  Adafruit_PCD8544 display;

  static void printHardwareInfo();
  void initializeDisplay();

public:
  Device();
  void initialize();
};