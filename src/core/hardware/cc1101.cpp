#include "core/hardware/cc1101.h"

const char *CC1101_TAG = "cc1101";

ModuleCC1101::ModuleCC1101(int csPin, int gdo0Pin, int gdo2Pin, int gdo1Pin,
                           int sckPin, int mosiPin)
    : csPin(csPin), gdo0Pin(gdo0Pin), gdo2Pin(gdo2Pin), gdo1Pin(gdo1Pin),
      sckPin(sckPin), mosiPin(mosiPin),
      radio(new Module(csPin, gdo0Pin, RADIOLIB_NC, gdo2Pin)) {}

bool ModuleCC1101::initialize() {
  int state = radio.begin();
  if (state != RADIOLIB_ERR_NONE) {
    ESP_LOGE(CC1101_TAG, "CC1101 is not responding: %d", state);
    return false;
  }
  return true;
}

CC1101 *ModuleCC1101::getDriver() { return &radio; }