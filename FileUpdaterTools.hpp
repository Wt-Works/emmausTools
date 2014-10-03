#pragma once

#include <Wt/WContainerWidget>
#include <Wt/WFileUpload>
#include <Wt/WString>

class FileUpdaterTools : public Wt::WContainerWidget {
private:
     Wt::WContainerWidget* body;
     Wt::WFileUpload* uploader;
     void fileUploaded();
public:
     FileUpdaterTools(Wt::WContainerWidget* parent=0);
};
