class Screen {
public:
  virtual void draw() = 0;
};

class ActionScreen : Screen {
public:
  virtual void draw() = 0;
  virtual void go() = 0;
};

class HomeScreen : Screen {
public:
  void draw();
};