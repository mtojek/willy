#include "apps/homescreen.h"

HomeScreen::HomeScreen(Device &device)
    : Application("home_screen"), device(device) {}

void HomeScreen::onStart() {
  ESP_LOGD(name, "HomeScreen::onStart");

  Display *display = device.getDisplay();
  Adafruit_PCD8544 *d = display->getDriver();
  d->clearDisplay();

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

  Display *display = device.getDisplay();
  Adafruit_PCD8544 *d = display->getDriver();
  d->setCursor(30, 40);
  d->print("Menu");
  d->display();

  rendered = true;
}