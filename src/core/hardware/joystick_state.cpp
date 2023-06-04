#include "joystick_state.h"

JoystickState::JoystickState(int vrx, int vry, bool sw)
    : vrx(vrx), vry(vry), sw(sw) {}

int JoystickState::getVRx() { return vrx; }

int JoystickState::getVRy() { return vry; }

bool JoystickState::getSW() { return sw; }