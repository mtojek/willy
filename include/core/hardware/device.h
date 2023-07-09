#pragma once

#include "esp32-hal-log.h"
#include <Arduino.h>

#include "pinout.h"

#include "joystick.h"
#include "radio.h"

#include <Adafruit_NeoPixel.h>
#include <Adafruit_PCD8544.h>

class Device {
private:
  Adafruit_PCD8544 display;
  Adafruit_NeoPixel led;
  Joystick joystick;
  Radio radio;

  static void printHardwareInfo();

  void initializeDisplay();
  void initializeRadio();
  void boot();

public:
  Device();
  void initialize();
  void sync();

  Adafruit_PCD8544 *getDisplay();
  Joystick *getJoystick();
  Radio *getRadio();
};