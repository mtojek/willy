#include <Arduino.h>

#include "../core/init/device.h"

class HomeScreen {
private:
  Device &device;
  TaskHandle_t taskHandle;

  static void taskHandler(void *params);

public:
  HomeScreen(Device &device);

  void open();
};