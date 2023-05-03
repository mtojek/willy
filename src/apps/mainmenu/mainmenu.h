#include <Arduino.h>

class MainMenu {
private:
  TaskHandle_t taskHandle;

  static void taskHandler(void *params);

public:
  void open();
};