#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <Wt/WContainerWidget>
#include <Wt/WString>
#include <string>

namespace Wt {
class WLineEdit;
class WText;
class WLabel;
class WButton;
}

class FileUpdaterTools;

class MainWindow : public Wt::WContainerWidget {
private:
     Wt::WLabel* _title;
     Wt::WLabel* _about;
     Wt::WContainerWidget* _body;
     FileUpdaterTools* _fileUpdaterTools;
     void sayHi();
     void pathChanged(const std::string& newPath);
public:
     MainWindow(Wt::WContainerWidget* parent=0);
};

#endif // MAINWINDOW_HPP
