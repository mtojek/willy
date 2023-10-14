#pragma once

#include "esp32-hal-log.h"

#include <SD.h>

class SDCard {
private:
  int csPin;

public:
  SDCard(int csPin);

  bool initialize();
};