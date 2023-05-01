#include <Arduino.h>

#include "mainmenu/application.h"

static const char *TAG = "main";

ApplicationManager appManager;

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;

  ESP_LOGI(TAG, "Willy is starting...");

  MainMenu *mainMenu = new MainMenu();
  appManager.registerApplication(mainMenu);
  mainMenu->run();
}

void loop() {
  Serial.println("Hey!");
  delay(1000);
}
