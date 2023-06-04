#define PCD8544_DC_PIN 21
#define PCD8544_CS_PIN 9
#define PCD8544_RST_PIN 14
#define PCD8544_BIAS 4
#define PCD8544_CONTRAST 55

#define LED_PIN LED_BUILTIN
#define LED_BRIGHTNESS 10

#define JOYSTICK_VRX_PIN 1
#define JOYSTICK_VRY_PIN 2
#define JOYSTICK_SW_PIN 40

#include <Adafruit_NeoPixel.h>
#include <Adafruit_PCD8544.h>

#include "joystick.h"

class Device {
private:
  Adafruit_PCD8544 display;
  Adafruit_NeoPixel led;
  Joystick joystick;

  static void printHardwareInfo();

  void initializeDisplay();
  void boot();

public:
  Device();
  void initialize();
  void sync();

  Adafruit_PCD8544 *getDisplay();
  Joystick *getJoystick();
};