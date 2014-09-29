#include "MainWindow.hpp"

#include <Wt/WLineEdit>
#include <Wt/WText>
#include <Wt/WLabel>
#include <Wt/WPushButton>
#include <Wt/WString>
#include <Wt/WApplication>

#include "FileUpdaterTools.hpp"

const char * fileUpdater = "/file-updater";

MainWindow::MainWindow(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent)
{
     _title = new Wt::WLabel("Emmaus", this);
     _body = new Wt::WContainerWidget(this);

    Wt::WApplication* app = Wt::WApplication::instance();
    app->internalPathChanged().connect(this, &MainWindow::pathChanged);
    pathChanged(app->internalPath());
}

void MainWindow::pathChanged(const std::string& newPath) {
    if (newPath == "/") {
        _body->clear();
        Wt::WAnchor* fileUpdaterLink = new Wt::WAnchor(Wt::WLink(Wt::WLink::InternalPath, fileUpdater), "File Updater Tool", _body);
    } else if (newPath == fileUpdater) {
        _body->clear();
        new FileUpdaterTools(_body);
    }



}
