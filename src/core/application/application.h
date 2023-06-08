#pragma once

#include "manager.h"

class ApplicationManager;

class Application {
protected:
  const char *name;
  ApplicationManager *appManager;

  Application(const char *name);

public:
  void onInstall(ApplicationManager *am);

  virtual void onUpdate() = 0;
  virtual void onRender() = 0;

  const char *getName();
};