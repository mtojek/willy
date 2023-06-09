#pragma once

#include <Arduino.h>

#include "../core/application/application.h"
#include "../core/hardware/device.h"

class HomeScreen : public Application {
private:
  Device &device;

  bool rendered;

public:
  HomeScreen(Device &device);

  void onUpdate();
  void onRender();
};