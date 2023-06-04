#include <ezButton.h>

#include "joystick_state.h"

class Joystick {
private:
  int vrxPin, vryPin;
  ezButton sw;

  JoystickState state;

public:
  Joystick(int vrxPin, int vryPin, int swPin);

  void sync();
  JoystickState *getState();
};