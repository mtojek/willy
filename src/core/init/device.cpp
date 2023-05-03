#include "esp32-hal-log.h"
#include <Arduino.h>

#include "device.h"

static const char *TAG = "device_init";

void Device::initialize() {
  Serial.begin(115200);
  while (!Serial)
    ;

  ESP_LOGI(TAG, "Willy is starting...");
}