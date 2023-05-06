#include "homescreen.h"

static const char *TAG = "home_screen";

HomeScreen::HomeScreen(Device &device) : device(device) {}

void HomeScreen::open() {
  xTaskCreate(taskHandler, TAG, 4096, this, 10, &taskHandle);
}

void HomeScreen::taskHandler(void *params) {
  ESP_LOGI(TAG, "Open home screen");

  HomeScreen *that = (HomeScreen *)params;
  Adafruit_PCD8544 *display = that->device.getDisplay();

  // draw screen
  display->setCursor(30, 40);
  display->print("Menu");
  display->display();

  // check go button
  vTaskDelete(NULL);
}