#include <iostream>
#include "book.hpp"


Book::Book(std::string titel, std::string author, std::string pubDate, std::string publisher, std::string synopsis,
           unsigned int pageCount) : titel(titel), author(author), pubDate(pubDate), publisher(publisher),
                                     synopsis(synopsis),
                                     pageCount(pageCount) {


}

std::string Book::getTitle() const {

    return this->titel;

}

std::string Book::getAuthor() const {


    return this->author;

}

std::string Book::getSynopsis() const {

    return this->synopsis;

}

std::string Book::getPubDate() const {

    return this->pubDate;

}

std::string Book::getPublisher() const {

    return this->publisher;
}

int Book::getPageCount() const {

    return this->pageCount;
}

void Book::showAll() const {
    std::cout << "Titel: " << this->titel << " Author: " << this->author << " Publishing date: " << this->pubDate
              << " Publisher: " << this->publisher << " Synopsis: " << this->synopsis << " # of pages: "
              << this->pageCount << std::endl;


}