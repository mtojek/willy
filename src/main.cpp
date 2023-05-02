#include <Arduino.h>

#include "mainmenu/application.h"

static const char *TAG = "main";

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;

  ESP_LOGI(TAG, "Willy is starting...");

  MainMenu mainMenu;
  mainMenu.open();
}

void loop() { delay(1000); }
