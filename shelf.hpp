#pragma once

#include <vector>
#include "libraryItem.hpp"
#include "book.hpp"

class Shelf {
public:
    Shelf(std::string filePath);

    ~Shelf();

    void addItem(Book book);

    void
    addItem(std::string titel, std::string author, std::string pubDate, std::string publisher, std::string synopsis,
            unsigned int pageCount);

    void showShelf();


private:
    bool checkIfBookExists(Book newBook);

    void laodBooks();

    void saveBooks();

    std::string filePath;

    Book readLine(std::string line);

    std::vector<Book> shelf;


};