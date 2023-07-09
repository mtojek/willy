#include "core/hardware/radio.h"

const char *RADIO_TAG = "radio";

Radio::Radio(int cePin, int csnPin) : rf(RF24(cePin, csnPin)) {}

bool Radio::initialize() {
  if (!rf.begin()) {
    ESP_LOGE(RADIO_TAG, "Radio hardware is not responding.");
    return false;
  }

  rf.setPALevel(RF24_PA_HIGH);
  // rf.printDetails();
  return true;
}

RF24 *Radio ::getRF24() { return &rf; }