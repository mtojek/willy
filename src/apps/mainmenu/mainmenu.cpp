#include "mainmenu.h"

MainMenu::MainMenu(Device &device) : Application("main_menu"), device(device) {}

void MainMenu::onUpdate() {
  if (appManager->isDisplayed(getName())) {
    return;
  }
}

void MainMenu::onRender() {}