#pragma once

class Application {
protected:
  const char *name;

  Application(const char *name);

public:
  virtual void onUpdate() = 0;
  virtual void onRender() = 0;

  const char *getName();
};