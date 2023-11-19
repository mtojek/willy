#pragma once

#include "esp32-hal-log.h"

#include <IRrecv.h>
#include <IRremoteESP8266.h>

#define BUZZER_FREQUENCY 2000
#define BUZZER_CHANNEL 0
#define BUZZER_RESOLUTION 8

class IrDA {
private:
  IRrecv irrecv;

public:
  IrDA(int receiverPin);

  void initialize();

  IRrecv *getReceiverDriver();
};