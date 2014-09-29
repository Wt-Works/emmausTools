#include "FileUpdaterTools.hpp"

#include <Wt/WLabel>

FileUpdaterTools::FileUpdaterTools(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent)
{
     new Wt::WLabel("I am here", this);
}
