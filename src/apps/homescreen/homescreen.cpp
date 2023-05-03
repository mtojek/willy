#include "homescreen.h"

static const char *TAG = "home_screen";

void HomeScreen::open() {
  xTaskCreate(taskHandler, TAG, 4096, NULL, 10, &taskHandle);
}

void HomeScreen::taskHandler(void *params) {
  ESP_LOGI(TAG, "Open home screen");

  vTaskDelete(NULL);
}