#pragma once

#include "esp32-hal-ledc.h"
#include "esp32-hal-log.h"

#include <ezBuzzer.h>

#define BUZZER_FREQUENCY 2000
#define BUZZER_CHANNEL 0
#define BUZZER_RESOLUTION 8

class Buzzer {
private:
  ezBuzzer buzzer;

public:
  Buzzer(int buzzerPin);

  void initialize();
  void sync();

  ezBuzzer *getDriver();
};