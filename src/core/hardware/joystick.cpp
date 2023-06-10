#include "core/hardware/joystick.h"

Joystick::Joystick(int vrxPin, int vryPin, int swPin)
    : vrxPin(vrxPin), vryPin(vryPin), sw(ezButton(swPin)),
      state(JoystickState(0, 0, false)) {
  sw.setDebounceTime(50);
}

void Joystick::sync() {
  sw.loop();

  const int vrx = analogRead(vrxPin);
  const int vry = analogRead(vryPin);
  JoystickState newState(vrx, vry, sw.isPressed());

  // free(&state);
  state = newState;
}

JoystickState *Joystick::getState() { return &state; }