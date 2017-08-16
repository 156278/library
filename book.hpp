#pragma once

#include "libraryItem.hpp"

class Book /*: public LibraryItem*/ {
public:
    Book(std::string titel, std::string author, std::string pubDate, std::string publisher, std::string synopsis,
         unsigned int pageCount);

    void showAll() const;

    const std::string titel;
    const std::string author;
    const std::string pubDate;
    const std::string publisher;
    const std::string synopsis;
    const unsigned int pageCount;
private:


};