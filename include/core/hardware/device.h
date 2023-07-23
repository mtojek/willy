#pragma once

#include "esp32-hal-log.h"
#include <Arduino.h>

#include "pinout.h"

#include "cc1101.h"
#include "display.h"
#include "joystick.h"
#include "radio.h"

#include <Adafruit_NeoPixel.h>
#include <Adafruit_PCD8544.h>

class Device {
private:
  Display display;
  Adafruit_NeoPixel led;
  Joystick joystick;
  Radio radio;
  ModuleCC1101 cc1101;

  static void printHardwareInfo();
  void boot();

public:
  Device();
  bool initialize();
  void sync();

  Display *getDisplay();
  Joystick *getJoystick();
  Radio *getRadio();
  ModuleCC1101 *getCC1101();
};