class MainMenu {
private:
  TaskHandle_t taskHandle;

  static void menuHandler(void *params);

public:
  void open();
};