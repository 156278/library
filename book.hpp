#pragma once

#include "libraryItem.hpp"

class Book /*: public LibraryItem*/ {
public:
    Book(std::string titel, std::string author, std::string pubDate, std::string publisher, std::string synopsis,
         unsigned int pageCount);

    void showAll() const;

    std::string getTitle() const;

    std::string getPubDate() const;

    std::string getAuthor() const;

    std::string getPublisher() const;

    std::string getSynopsis() const;

    int getPageCount() const;


private:
    std::string titel;
    std::string author;
    std::string pubDate;
    std::string publisher;
    std::string synopsis;
    unsigned int pageCount;


};