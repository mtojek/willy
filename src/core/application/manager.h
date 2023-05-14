#include <Array.h>

#include "application.h"

const int RUNNING_APPS_COUNT_MAX = 10;
typedef Array<Application *, RUNNING_APPS_COUNT_MAX> Apps;

class ApplicationManager {
private:
  Apps installed;
  Apps running;

public:
  void install(Application *app);
  void start(const char *name);
  void stop(const char *name);

  void onUpdate();
  void onRender();
};