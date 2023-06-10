#include "apps/homescreen.h"

HomeScreen::HomeScreen(Device &device)
    : Application("home_screen"), device(device) {}

void HomeScreen::onStart() {
  ESP_LOGD(name, "HomeScreen::onStart");

  Adafruit_PCD8544 *display = device.getDisplay();
  display->clearDisplay();

  rendered = false;
}

void HomeScreen::onUpdate() {
  if (!appManager->isDisplayed(getName())) {
    return;
  }

  Joystick *joystick = device.getJoystick();
  JoystickState *joystickState = joystick->getState();
  bool sw = joystickState->getSW();

  if (sw) {
    appManager->start("main_menu");
  }
}

void HomeScreen::onRender() {
  if (rendered) {
    return;
  }

  ESP_LOGD(name, "HomeScreen::onRender (once)");

  Adafruit_PCD8544 *display = device.getDisplay();
  display->setCursor(30, 40);
  display->print("Menu");
  display->display();

  rendered = true;
}