#include "esp32-hal-log.h"

#include "core/application/manager.h"

#include "apps/homescreen.h"
#include "apps/mainmenu.h"

#define TAG "main"

Device willy;
ApplicationManager appManager;

HomeScreen homeScreen(willy);
MainMenu mainMenu(willy);

void setup() {
  if (!willy.initialize()) {
    ESP_LOGE(TAG, "Willy initialization failed");
    exit(0);
  }
  ESP_LOGI(TAG, "Initialization done");

  appManager.install(homeScreen);
  appManager.install(mainMenu);

  appManager.start(homeScreen.getName());
}

void loop() {
  willy.sync();

  appManager.onUpdate();
  appManager.onRender();
}