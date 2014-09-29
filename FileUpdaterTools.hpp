#pragma once

#include <Wt/WContainerWidget>
#include <Wt/WString>

namespace Wt {
class WFileUpload;
}

class FileUpdaterTools : public Wt::WContainerWidget {
private:
    Wt::WFileUpload* uploader;
    void fileUploaded();
public:
     FileUpdaterTools(Wt::WContainerWidget* parent=0);
};
