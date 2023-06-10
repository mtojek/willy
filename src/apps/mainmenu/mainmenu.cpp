#include "mainmenu.h"

MainMenu::MainMenu(Device &device) : Application("main_menu"), device(device) {}

void MainMenu::onStart() {
  ESP_LOGI(name, "MainMenu::onStart");

  Adafruit_PCD8544 *display = device.getDisplay();

  display->clearDisplay();
  display->display();
}

void MainMenu::onUpdate() {
  if (!appManager->isDisplayed(getName())) {
    return;
  }
}