#pragma once

#include "esp32-hal-log.h"
#include <Arduino.h>

#include "pinout.h"

#include "joystick.h"

#include "device.h"

#include <Adafruit_NeoPixel.h>
#include <Adafruit_PCD8544.h>
#include <RF24.h>

class Device {
private:
  Adafruit_PCD8544 display;
  Adafruit_NeoPixel led;
  Joystick joystick;
  RF24 radio;

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
};