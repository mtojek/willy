#include <Arduino.h>

class HomeScreen {
private:
  TaskHandle_t taskHandle;

  static void taskHandler(void *params);

public:
  void open();
};