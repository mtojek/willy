#include "core/hardware/cc1101.h"

const char *CC1101_TAG = "cc1101";

ModuleCC1101::ModuleCC1101(int csPin, int gdo0Pin, int gdo2Pin, int gdo1Pin,
                           int sckPin, int mosiPin)
    : csPin(csPin), gdo0Pin(gdo0Pin), gdo2Pin(gdo2Pin), gdo1Pin(gdo1Pin),
      sckPin(sckPin), mosiPin(mosiPin),
      radio(CC1101(sckPin, gdo1Pin, mosiPin, csPin, gdo0Pin, gdo2Pin)) {}

bool ModuleCC1101::initialize() {
  radio.init();
  ESP_LOGI(CC1101_TAG, "CC1101: 0x%02x, version: 0x%02x", radio.getPartnum(),
           radio.getVersion());
  return true;
}

CC1101 *ModuleCC1101::getDriver() { return &radio; }