class Application {
protected:
  const char *name;

public:
  Application(const char *name);

  virtual void run() = 0;
};

class ApplicationManager {
public:
  void registerApplication(Application *application);
};