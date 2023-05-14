#include "application.h"

Application::Application(const char *name) : name(name) {}

const char *Application::getName() { return name; }