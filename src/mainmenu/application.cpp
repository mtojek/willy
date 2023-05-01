#include "esp32-hal-log.h"

#include "application.h"

static const char *TAG = "main_menu";

MainMenu::MainMenu() : Application(TAG) {}

void MainMenu::run() { ESP_LOGI(TAG, "Open main menu"); }