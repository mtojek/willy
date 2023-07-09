#include "core/hardware/cc1101.h"

const char *CC1101_TAG = "cc1101";

CC1101::CC1101(int sckPin, int mosiPin, int csnPin, int gdo0Pin, int gdo1Pin,
               int gdo2Pin)
    : sckPin(sckPin), mosiPin(mosiPin), csnPin(csnPin), gdo0Pin(gdo0Pin),
      gdo1Pin(gdo1Pin), gdo2Pin(gdo2Pin), elechouse(ELECHOUSE_CC1101()) {}

bool CC1101::initialize() {
  elechouse.setSpiPin(sckPin, gdo1Pin, mosiPin, csnPin);
  elechouse.Init();
  elechouse.setGDO(gdo0Pin, gdo2Pin);

  if (!elechouse.getCC1101()) {
    ESP_LOGE(CC1101_TAG, "CC1101 is not responding.");
    return false;
  }
}

ELECHOUSE_CC1101 *CC1101::getElechouse() { return &elechouse; }