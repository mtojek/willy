#pragma once

#include "esp32-hal-log.h"
#include <Arduino.h>

#include "pinout.h"

#include "buzzer.h"
#include "display.h"
#include "irda.h"
#include "joystick.h"
#include "sdcard.h"
#include "transceiver_24.h"
#include "transceiver_433.h"

#include <Adafruit_NeoPixel.h>
#include <Adafruit_PCD8544.h>

#include <IRtext.h>
#include <IRutils.h>

class Device {
private:
  Display display;
  Adafruit_NeoPixel led;
  Joystick joystick;
  Transceiver24 transceiver24;
  Transceiver433 transceiver433;
  Buzzer buzzer;
  SDCard sdCard;
  IrDA irDA;

  static void printHardwareInfo();
  void boot();

public:
  Device();
  bool initialize();
  void sync();

  Display *getDisplay();
  Joystick *getJoystick();
  Transceiver24 *getTransceiver24();
  Transceiver433 *getTransceiver433();
  Buzzer *getBuzzer();
  SDCard *getSDCard();
  IrDA *getIrDA();
};