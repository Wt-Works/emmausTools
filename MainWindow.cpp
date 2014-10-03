#include "MainWindow.hpp"
#include <Wt/WLineEdit>
#include <Wt/WText>
#include <Wt/WLabel>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WApplication>
#include "FileUpdaterTools.hpp"

const char * ToolinternalPath = "/file-updater";

MainWindow::MainWindow(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent)
{
     _title = new Wt::WLabel("this application was build for Emmaus ",this);
     Wt::WAnchor *anchor = new Wt::WAnchor(Wt::WLink("http://www.emmausavenir.com/neuillyplaisance.html "), "Emmaus", this);
     _body = new Wt::WContainerWidget(this);
     _about = new Wt::WLabel("this application was a contribution from lyase damasked & Matthew Sherborne ", this);
     _body = new Wt::WContainerWidget(this);
     Wt::WApplication* app = Wt::WApplication::instance();
     app->internalPathChanged().connect(this, &MainWindow::pathChanged);
     pathChanged(app->internalPath());
}

void MainWindow::pathChanged(const std::string& newPath)
{
     if (newPath == "/") {
          _body->clear();
          Wt::WAnchor* fileUpdaterLink = new Wt::WAnchor(Wt::WLink(Wt::WLink::InternalPath, ToolinternalPath), "File Updater Tool", _body);
     } else if (newPath == ToolinternalPath) {
          _body->clear();
          new FileUpdaterTools(_body);
     }
}
