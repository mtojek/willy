#include "homescreen.h"

HomeScreen::HomeScreen(Device &device)
    : Application("home_screen"), device(device) {}

void HomeScreen::onUpdate() {
  Joystick *joystick = device.getJoystick();
  JoystickState *joystickState = joystick->getState();

  int vrx = joystickState->getVRx();
  int vry = joystickState->getVRy();
  bool sw = joystickState->getSW();

  if (vrx < 1000 || vrx > 3000) {
    ESP_LOGI(name, "Joystick: vx = %d", vrx);
  }
  if (vry < 1000 || vry > 3000) {
    ESP_LOGI(name, "Joystick: vy = %d", vry);
  }

  if (sw) {
    ESP_LOGI(name, "Joystick: clicked", sw);
  }

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