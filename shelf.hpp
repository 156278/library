#pragma once

#include <vector>
#include "libraryItem.hpp"

class Shelf {
public:
    void addItem(LibraryItem libraryItem);
    void addItem(std::string titel, std::string author, std::string pubDate, std::string publisher, std::string synopsis,
                 unsigned int pageCount);
    void showShelf();


private:
    std::vector<LibraryItem> shelf;


};