#include "core/hardware/display.h"

Display::Display(int dcPin, int csPin, int rstPin, int contrast, int bias)
    : contrast(contrast), bias(bias),
      display(Adafruit_PCD8544(dcPin, csPin, rstPin)) {}

void Display::initialize() {
  display.begin();
  display.setRotation(2);
  display.setContrast(contrast);
  display.setBias(bias);
  display.clearDisplay();
  display.display();
}

Adafruit_PCD8544 *Display::getPCD() { return &display; }