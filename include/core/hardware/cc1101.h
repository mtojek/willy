#pragma once

#include "esp32-hal-log.h"

#include "pinout.h"

#include <CC1101_ESP_Arduino.h>

class ModuleCC1101 {
private:
  int csPin;
  int gdo0Pin;
  int gdo1Pin;
  int gdo2Pin;

  int sckPin;
  int mosiPin;

  CC1101 radio;

public:
  ModuleCC1101(int csPin, int gdo0Pin, int gdo2Pin, int gdo1Pin = SPI_MISO_PIN,
               int sckPin = SPI_SCK_PIN, int mosiPin = SPI_MOSI_PIN);

  bool initialize();
  CC1101 *getDriver();
};