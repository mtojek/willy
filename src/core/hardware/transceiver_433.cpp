#include "core/hardware/transceiver_433.h"

const char *TRANSCEIVER_433_TAG = "transceiver_433";

Transceiver433::Transceiver433(int csPin, int gdo0Pin, int gdo2Pin, int gdo1Pin,
                               int sckPin, int mosiPin)
    : csPin(csPin), gdo0Pin(gdo0Pin), gdo2Pin(gdo2Pin), gdo1Pin(gdo1Pin),
      sckPin(sckPin), mosiPin(mosiPin),
      radio(CC1101(sckPin, gdo1Pin, mosiPin, csPin, gdo0Pin, gdo2Pin)) {}

bool Transceiver433::initialize() {
  radio.init();
  ESP_LOGI(TRANSCEIVER_433_TAG, "CC1101: 0x%02x, version: 0x%02x",
           radio.getPartnum(), radio.getVersion());
  return true;
}

CC1101 *Transceiver433::getDriver() { return &radio; }