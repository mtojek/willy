#include "core/application/manager.h"

#include "apps/homescreen/homescreen.h"
#include "apps/mainmenu/mainmenu.h"

Device willy;
ApplicationManager appManager;

HomeScreen homeScreen(willy);
MainMenu mainMenu(willy);

void setup() {
  willy.initialize();

  appManager.install(&homeScreen);
  appManager.install(&mainMenu);

  appManager.start(homeScreen.getName());
}

void loop() {
  willy.sync();

  appManager.onUpdate();
  appManager.onRender();
}