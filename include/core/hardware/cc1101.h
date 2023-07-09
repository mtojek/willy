#pragma once

#include "esp32-hal-log.h"

#include <ELECHOUSE_CC1101_SRC_DRV.h>

class CC1101 {
private:
  int csnPin;
  int gdo0Pin;
  int gdo1Pin;
  int gdo2Pin;

  int sckPin;
  int mosiPin;

  ELECHOUSE_CC1101 elechouse;

public:
  CC1101(int sckPin, int mosiPin, int csnPin, int gdo0Pin, int gdo1Pin,
         int gdo2Pin);

  void initialize();
  ELECHOUSE_CC1101 *getElechouse();
};