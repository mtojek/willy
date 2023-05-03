#include "apps/homescreen/homescreen.h"
#include "core/init/device.h"

static const char *TAG = "main";

Device willy;
HomeScreen homeScreen;

void setup() {
  willy.initialize();

  homeScreen.open();
}

void loop() { delay(1000); }
