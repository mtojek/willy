#include "core/hardware/buzzer.h"

const char *BUZZER_TAG = "buzzer";

Buzzer::Buzzer(int buzzerPin) : buzzer(ezBuzzer(buzzerPin)) {
  ledcSetup(BUZZER_CHANNEL, BUZZER_FREQUENCY, BUZZER_RESOLUTION);
  ledcAttachPin(buzzerPin, BUZZER_CHANNEL);
}

ezBuzzer *Buzzer ::getDriver() { return &buzzer; }

void Buzzer::sync() { buzzer.loop(); }