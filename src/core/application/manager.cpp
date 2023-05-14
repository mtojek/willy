#include "manager.h"

void ApplicationManager::install(Application *app) { installed.push_back(app); }

void ApplicationManager::start(const char *name) {
  for (Application *app : installed) {
    if (strcmp(app->getName(), name) == 0) {
      running.push_back(app);
      return;
    }
  }
}

void ApplicationManager::stop(const char *name) {
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
    app->onRender();
  }
}