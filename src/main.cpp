#include "core/application/manager.h"

#include "apps/homescreen/homescreen.h"
#include "apps/mainmenu/mainmenu.h"

Device willy;
HomeScreen homeScreen(willy);
MainMenu mainMenu;

ApplicationManager appManager;

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