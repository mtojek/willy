#pragma once

#include <Arduino.h>

#include "../core/application/application.h"
#include "../core/hardware/device.h"

class MainMenu : public Application {
private:
  Device &device;

public:
  MainMenu(Device &device);

  void onUpdate();
  void onRender();
};