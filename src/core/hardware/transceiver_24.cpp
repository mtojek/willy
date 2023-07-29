#include "core/hardware/transceiver_24.h"

const char *TRANSCEIVER_24_TAG = "transceiver_24";

Transceiver24::Transceiver24(int cePin, int csnPin) : rf(RF24(cePin, csnPin)) {}

bool Transceiver24::initialize() {
  if (!rf.begin()) {
    ESP_LOGE(TRANSCEIVER_24_TAG, "Radio hardware is not responding.");
    return false;
  }

  rf.setPALevel(RF24_PA_HIGH);
  // rf.printDetails();
  return true;
}

RF24 *Transceiver24 ::getDriver() { return &rf; }