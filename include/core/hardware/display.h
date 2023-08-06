#pragma once

#include <Adafruit_PCD8544.h>

class Display {
private:
  int contrast;
  int bias;
  Adafruit_PCD8544 display;

public:
  Display(int dcPin, int csPin, int rstPin, int contrast, int bias);

  bool initialize();
  Adafruit_PCD8544 *getDriver();
};