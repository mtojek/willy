#include "src/mainmenu/application.h"

void setup() {
  Serial.begin(115200);

  Application mainMenu;
  mainMenu.run();
}

void loop() {
}
