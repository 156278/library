#pragma once

#include "libraryItem.hpp"

class Book : public LibraryItem {
public:
    Book(std::string titel, std::string author, std::string pubDate, std::string publisher, std::string synopsis,
         unsigned int pageCount);

    void showAll() const;

private:
    const std::string synopsis;
    const unsigned int pageCount;


};