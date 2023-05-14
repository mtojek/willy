#include "homescreen.h"

HomeScreen::HomeScreen(Device &device)
    : Application("home_screen"), device(device) {}

void HomeScreen::onUpdate() {
  if (opened) {
    return;
  }

  ESP_LOGI(name, "Open home screen");

  opened = true;
}

void HomeScreen::onRender() {
  if (rendered) {
    return;
  }

  Adafruit_PCD8544 *display = device.getDisplay();

  // draw screen
  display->setCursor(30, 40);
  display->print("Menu");
  display->display();

  rendered = true;
}