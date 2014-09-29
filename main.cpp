#include <Wt/WApplication>
#include "MainWindow.hpp"

class HelloApp : public Wt::WApplication {
public:
     MainWindow* mainWindow;
     HelloApp(const Wt::WEnvironment& env) : Wt::WApplication(env) {
          setTitle("Hello world");
          mainWindow = new MainWindow(root());
     }
};

Wt::WApplication* createApplication(const Wt::WEnvironment& env)
{
     return new HelloApp(env);
}

int main(int argc, char** argv)
{
     return Wt::WRun(argc, argv, &createApplication);
}
