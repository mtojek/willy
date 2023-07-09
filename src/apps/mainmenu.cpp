#include "apps/mainmenu.h"

MainMenu::MainMenu(Device &device) : Application("main_menu"), device(device) {}

void MainMenu::onStart() {
  ESP_LOGD(name, "MainMenu::onStart");

  Display *display = device.getDisplay();
  Adafruit_PCD8544 *d = display->getDriver();

  d->clearDisplay();
  d->display();
}

void MainMenu::onUpdate() {
  if (!appManager->isDisplayed(getName())) {
    return;
  }
}