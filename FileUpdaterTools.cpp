#include "FileUpdaterTools.hpp"

#include <string>

#include <Wt/WText>
#include <Wt/WFileUpload>
#include <Wt/WPushButton>

FileUpdaterTools::FileUpdaterTools(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent)
{
     new Wt::WText("Please upload the file", this);
     uploader = new Wt::WFileUpload(this);
     uploader->uploaded().connect(this, &FileUpdaterTools::fileUploaded);
     Wt::WPushButton* uploadBtn = new Wt::WPushButton("Upload", this);
     uploadBtn->clicked().connect(uploader, &Wt::WFileUpload::upload);
}

void FileUpdaterTools::fileUploaded() {
    std::string fn = uploader->spoolFileName();
    delete uploader;
    new Wt::WText(std::string("Your file was uploaded to: ") + fn, this);
}
