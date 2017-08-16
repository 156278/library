#pragma once

#include <iosfwd>
#include <string>

class LibraryItem {


public:
    LibraryItem(std::string titel, std::string author, std::string pubDate, std::string publisher);

    void showAll() const;


protected:
    const std::string titel;
    const std::string author;
    const std::string pubDate;
    const std::string publisher;


};