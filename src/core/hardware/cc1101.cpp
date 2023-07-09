#include "core/hardware/cc1101.h"

const char *CC1101_TAG = "cc1101";

CC1101::CC1101(int csnPin, int gdo0Pin, int gdo2Pin, int gdo1Pin, int sckPin,
               int mosiPin)
    : csnPin(csnPin), gdo0Pin(gdo0Pin), gdo2Pin(gdo2Pin),
      elechouse(ELECHOUSE_CC1101()) {}

bool CC1101::initialize() {
  elechouse.setSpiPin(sckPin, gdo1Pin, mosiPin, csnPin);
  elechouse.Init();
  elechouse.setGDO(gdo0Pin, gdo2Pin);

  if (!elechouse.getCC1101()) {
    ESP_LOGE(CC1101_TAG, "CC1101 is not responding.");
    return false;
  }
}

ELECHOUSE_CC1101 *CC1101::getDriver() { return &elechouse; }