#include "homescreen.h"

HomeScreen::HomeScreen(Device &device)
    : Application("home_screen"), device(device) {}

void HomeScreen::onStart() {
  Adafruit_PCD8544 *display = device.getDisplay();

  display->clearDisplay();
  display->display();

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

  Adafruit_PCD8544 *display = device.getDisplay();

  // draw screen
  display->setCursor(30, 40);
  display->print("Menu");
  display->display();

  rendered = true;
}