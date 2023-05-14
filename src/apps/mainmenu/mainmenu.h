#include <Arduino.h>

#include "../core/application/application.h"

class MainMenu : public Application {
public:
  MainMenu();

  void onUpdate();
  void onRender();
};