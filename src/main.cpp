#include <Arduino.h>

#include <mainmenu/application.h>

void setup() {
  Serial.begin(115200);
  while (!Serial)
    ;

  Serial.println("Welcome, willy!");

  Application mainMenu;
  mainMenu.run();
}

void loop() {
  Serial.println("Hey!");
  delay(1000);
}
