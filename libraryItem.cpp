#include <iostream>
#include "libraryItem.hpp"


LibraryItem::LibraryItem(std::string titel, std::string author, std::string pubDate, std::string publisher) : titel(
        titel), author(author), pubDate(pubDate), publisher(publisher) {


}


void LibraryItem::showAll() const {
    std::cout << "Titel: " << this->titel << std::endl;
    std::cout << "Author: " << this->author << std::endl;
    std::cout << "Publishing date: " << this->pubDate << std::endl;
    std::cout << "Publisher: " << this->publisher << std::endl;

}