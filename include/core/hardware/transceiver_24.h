#pragma once

#include "esp32-hal-log.h"

#include <RF24.h>

class Transceiver24 {
private:
  RF24 rf;

public:
  Transceiver24(int cePin, int csnPin);

  bool initialize();
  RF24 *getDriver();
};