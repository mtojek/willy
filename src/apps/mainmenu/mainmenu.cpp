#include "mainmenu.h"

static const char *TAG = "main_menu";

void MainMenu::open() {
  xTaskCreate(taskHandler, TAG, 4096, NULL, 10, &taskHandle);
}

void MainMenu::taskHandler(void *params) {
  ESP_LOGI(TAG, "Open main menu");

  vTaskDelete(NULL);
}