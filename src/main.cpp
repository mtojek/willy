#include "apps/homescreen/homescreen.h"

static const char *TAG = "main";

Device willy;
HomeScreen homeScreen(willy);

void setup() {
  willy.initialize();

  homeScreen.open();
}

void loop() { delay(1000); }
