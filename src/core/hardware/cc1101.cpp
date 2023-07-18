#include "core/hardware/cc1101.h"

const char *CC1101_TAG = "cc1101";

ModuleCC1101::ModuleCC1101(int csPin, int gdo0Pin, int gdo2Pin, int gdo1Pin,
                           int sckPin, int mosiPin)
    : csPin(csPin), gdo0Pin(gdo0Pin), gdo2Pin(gdo2Pin), gdo1Pin(gdo1Pin),
      sckPin(sckPin), mosiPin(mosiPin),
      radio(new Module(csPin, gdo0Pin, RADIOLIB_NC, gdo2Pin)) {}

bool ModuleCC1101::initialize() {
  int state = radio.begin(434.0, 4.8, 5.0, 135.0, 10, 16);
  if (state != RADIOLIB_ERR_NONE) {
    ESP_LOGE(CC1101_TAG, "radio.begin(): CC1101 is not responding: %d", state);
    return false;
  }

  // radio.reset();
  state = radio.disableAddressFiltering();
  if (state != RADIOLIB_ERR_NONE) {
    ESP_LOGE(CC1101_TAG,
             "radio.disableAddressFiltering(): CC1101 is not responding: %d",
             state);
    return false;
  }

  // state = radio.setRxBandwidth(812.0);
  // if (state != RADIOLIB_ERR_NONE) {
  //   ESP_LOGE(CC1101_TAG, "radio.setFrequency(): CC1101 is not responding:
  //   %d",
  //            state);
  //   return false;
  // }

  state = radio.setFrequencyDeviation(120.0);
  if (state != RADIOLIB_ERR_NONE) {
    ESP_LOGE(CC1101_TAG,
             "radio.setFrequencyDeviation(): CC1101 is not responding: %d",
             state);
    return false;
  }

  // state = radio.setPreambleLength(32, 28);
  // if (state != RADIOLIB_ERR_NONE) {
  //   ESP_LOGE(CC1101_TAG,
  //            "radio.setPreambleLength(): CC1101 is not responding: %d",
  //            state);
  //   return false;
  // }

  return true;
}

CC1101 *ModuleCC1101::getDriver() { return &radio; }