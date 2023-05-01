#include "screen.h"

class Menu : ActionScreen {
public:
  virtual void draw() = 0;
  virtual void go() = 0;
};

class ListMenu : Menu {
public:
  void draw();
  void go();
};

class TabMenu : Menu {
public:
  void draw();
  void go();
};