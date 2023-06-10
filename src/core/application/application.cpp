#include "application.h"

Application::Application(const char *name) : name(name) {}

void Application::onInstall(ApplicationManager *am) { appManager = am; }

void Application::onStart() { ESP_LOGD(name, "onStart() is not implemented"); }

void Application::onRender() {
  // ESP_LOGI(name, "onRender() is not implemented");
}

const char *Application::getName() { return name; }