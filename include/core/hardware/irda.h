#pragma once

#include "esp32-hal-log.h"

#include <IRremoteESP8266.h>

#include <IRrecv.h>
#include <IRsend.h>

#define BUZZER_FREQUENCY 2000
#define BUZZER_CHANNEL 0
#define BUZZER_RESOLUTION 8

class IrDA {
private:
  IRrecv irrecv;
  IRsend irsend;

public:
  IrDA(int receiverPin, int senderPin);

  void initialize();

  IRrecv *getReceiverDriver();
  IRsend *getSenderDriver();
};