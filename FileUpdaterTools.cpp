#include "FileUpdaterTools.hpp"

#include <string>
#include <fstream>
#include <vector>

#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WContainerWidget>
#include <Wt/WMemoryResource>

FileUpdaterTools::FileUpdaterTools(Wt::WContainerWidget* parent) : Wt::WContainerWidget(parent)
{
     new Wt::WText("Please upload the file", this);
     body = new Wt::WContainerWidget(this);
     uploader = new Wt::WFileUpload(body);
     uploader->uploaded().connect(this, &FileUpdaterTools::fileUploaded);
     Wt::WPushButton* uploadBtn = new Wt::WPushButton("Upload", body);
     uploadBtn->clicked().connect(uploader, &Wt::WFileUpload::upload);
}

void FileUpdaterTools::fileUploaded() {
    // Open the file
    std::ifstream file(uploader->spoolFileName().c_str());
    // We'll copy it to this block of memory
    std::vector<unsigned char> data;
    // Using this iterator
    std::back_insert_iterator<std::vector<unsigned char> > out(data);
    // process the file
    const std::string ending = " store 33\r\n";
    while (file.good()) {
        std::string line;
        std::getline(file, line);
        if (line.empty()) {
            *(out++) = '\r';
            *(out++) = '\n';
        } else {
            std::copy(line.begin(), line.end(), out);
            std::copy(ending.begin(), ending.end(), out);
        }
    }
    // Turn the fixed file into a resource
    Wt::WMemoryResource* resource = new Wt::WMemoryResource("text/plain", data, this);
    resource->suggestFileName("modified-file.txt", Wt::WResource::Attachment);
    body->clear(); // This will delete the upload box, and the upload button
    new Wt::WAnchor(resource, "Download fixed version", body);
}
