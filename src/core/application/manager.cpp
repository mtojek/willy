#include "manager.h"

void ApplicationManager::install(Application *app) {
  app->onInstall(this);
  installed.push_back(app);
}

void ApplicationManager::start(const char *name) {
  ESP_LOGI(name, "Start application: %s", name);

  for (Application *app : installed) {
    if (strcmp(app->getName(), name) == 0) {
      running.push_back(app);
      return;
    }
  }
}

void ApplicationManager::stop(const char *name) {
  ESP_LOGI(name, "Stop application: %s", name);

  for (int i = 0; i < running.size(); i++) {
    if (strcmp(running[i]->getName(), name) == 0) {
      running.remove(i);
      return;
    }
  }
}

void ApplicationManager::onUpdate() {
  for (Application *app : running) {
    app->onUpdate();
  }
}

void ApplicationManager::onRender() {
  for (Application *app : running) {
    if (isDisplayed(app->getName())) {
      app->onRender();
    }
  }
}

boolean ApplicationManager::isDisplayed(const char *name) {
  if (running.size() == 0) {
    return false;
  }

  if (strcmp(running.back()->getName(), name) != 0) {
    return false;
  }
  return true;
}
