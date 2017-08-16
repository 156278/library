#include "shelf.hpp"
#include "book.hpp"


void Shelf::addItem(LibraryItem libraryItem) {
    shelf.push_back(libraryItem);

}

void Shelf::addItem(std::string titel, std::string author, std::string pubDate, std::string publisher,
                    std::string synopsis, unsigned int pageCount) {
    Book book(titel, author, pubDate, publisher, synopsis, pageCount);
    shelf.push_back(book);
}


void Shelf::showShelf() {
    for (int i = 0; i < shelf.size(); i++){
        shelf[i].showAll();


    }



}