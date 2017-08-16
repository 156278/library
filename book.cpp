#include <iostream>
#include "book.hpp"


Book::Book(std::string titel, std::string author, std::string pubDate, std::string publisher, std::string synopsis,
           unsigned int pageCount) : LibraryItem(titel, author, pubDate, publisher), synopsis(synopsis),
                                     pageCount(pageCount) {


}


void Book::showAll() const {
    std::cout << "Titel: " << this->titel << std::endl;
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Publishing date: " << this->pubDate << std::endl;
    std::cout << "Publisher: " << this->publisher << std::endl;
    std::cout << "Synopsis: " << this->synopsis << std::endl;
    std::cout << "# of pages: " << this->pageCount << std::endl;


}