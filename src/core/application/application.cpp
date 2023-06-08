#include "application.h"

Application::Application(const char *name) : name(name) {}

void Application::onInstall(ApplicationManager *am) { appManager = am; }

const char *Application::getName() { return name; }