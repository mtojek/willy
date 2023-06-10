#include "manager.h"

ApplicationManager::ApplicationManager() : name("application_manager") {}

void ApplicationManager::install(Application &app) {
  installed.push_back(&app);
  app.onInstall(this);
}

void ApplicationManager::start(const char *appName) {
  ESP_LOGI(name, "Start application: %s", appName);

  // If the application has been already started,
  // then let's move it to the last position (= displayed);
  for (int i = 0; i < running.size(); i++) {
    if (strcmp(running[i]->getName(), appName) != 0) {
      continue;
    }

    if (i == (running.size() - 1)) {
      return; // application is already running and it's displayed
    }

    running.push_back(running[i]);
    running.remove(i);
    return;
  }

  for (Application *app : installed) {
    if (strcmp(app->getName(), appName) == 0) {
      running.push_back(app);

      app->onStart();
      return;
    }
  }
}

void ApplicationManager::stop(const char *appName) {
  ESP_LOGI(name, "Stop application: %s", appName);

  for (int i = 0; i < running.size(); i++) {
    if (strcmp(running[i]->getName(), appName) == 0) {
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

boolean ApplicationManager::isDisplayed(const char *appName) {
  if (running.size() == 0) {
    return false;
  }

  if (strcmp(running.back()->getName(), appName) != 0) {
    return false;
  }
  return true;
}
