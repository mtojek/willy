#include "core/hardware/display.h"

const char *DISPLAY_TAG = "display";

Display::Display(int dcPin, int csPin, int rstPin, int contrast, int bias)
    : contrast(contrast), bias(bias),
      display(Adafruit_PCD8544(dcPin, csPin, rstPin)) {}

bool Display::initialize() {
  if (!display.begin()) {
    ESP_LOGE(DISPLAY_TAG, "display.begin() failed");
    return false;
  }

  display.setRotation(2);
  display.setContrast(contrast);
  display.setBias(bias);
  display.clearDisplay();
  display.display();
  return true;
}

Adafruit_PCD8544 *Display::getDriver() { return &display; }