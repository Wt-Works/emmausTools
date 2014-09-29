#pragma once

#include <Wt/WContainerWidget>
#include <Wt/WString>

namespace Wt {
class WLineEdit;
class WText;
class WLabel;
class WButton;
}

class FileUpdaterTools : public Wt::WContainerWidget {
private:
public:
     FileUpdaterTools(Wt::WContainerWidget* parent=0);
};
