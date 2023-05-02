#include "esp32-hal-log.h"
#include <Arduino.h>

#include "application.h"

static const char *TAG = "main_menu";

void MainMenu::open() {
  xTaskCreate(menuHandler, TAG, 4096, NULL, 10, &taskHandle);
}

void MainMenu::menuHandler(void *params) {
  ESP_LOGI(TAG, "Open main menu");

  vTaskDelete(NULL);
  while (1) {
  }
}