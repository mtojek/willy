class JoystickState {
private:
  int vrx, vry;
  bool sw;

public:
  JoystickState(int vrx, int vry, bool sw);

  int getVRx();
  int getVRy();
  bool getSW();
};