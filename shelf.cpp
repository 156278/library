#include <iostream>
#include <fstream>
#include "shelf.hpp"
#include "book.hpp"

Shelf::Shelf(std::string filePath) : filePath(filePath) {
    laodBooks();
}

Shelf::~Shelf() {
    saveBooks();
}

void Shelf::laodBooks() {
    std::ifstream infile(filePath);
    std::string line;
    while (std::getline(infile, line)) {
        addItem(readLine(line));
    }

}

void Shelf::addItem(Book book) {
    if (!checkIfBookExists(book)) {
        shelf.push_back(book);

    }
}


void Shelf::addItem(std::string titel, std::string author, std::string pubDate, std::string publisher,
                    std::string synopsis, unsigned int pageCount) {
    Book book(titel, author, pubDate, publisher, synopsis, pageCount);
    addItem(book);

}


void Shelf::showShelf(bool delYN) {


    if (shelf.size() < 1) {

        std::cout << "Currently no books saved!" << std::endl;

    } else {
        for (int i = 0; i < shelf.size(); i++) {
            if (delYN) {
                std::cout << "[" << (i + 1) << "] ";
            }
            shelf[i].showAll();
        }
        std::cout << std::endl;
    }
}

Book Shelf::readLine(std::string line) {
    std::vector<std::string> parts;
    std::string word = "";

    for (auto c : line) {

        if (c != ';') {
            word += c;
        } else {
            parts.push_back(word);
            word = "";
        }

    }
    parts.push_back(word);

    Book book(parts[0], parts[1], parts[2], parts[3], parts[4], std::stoi(parts[5]));
    return book;

}

void Shelf::delBook(int bookNrToDel) {
    if (this->shelf.size() < 1) {
        std::cout << "Currently no books saved!" << std::endl;
    } else {

        this->shelf.erase(this->shelf.begin() + (bookNrToDel - 1));
    }
}

void Shelf::saveBooks() {
    /*first we delete the content of the file*/
    std::ofstream ofs;
    ofs.open("save.txt", std::ofstream::out | std::ofstream::trunc);
    ofs.close();
    /*Now we write current books*/
    std::ofstream writeFile;
    writeFile.open(filePath);
    for (auto book : shelf) {
        std::string saveLine =
                book.getTitle() + ";" + book.getAuthor() + ";" + book.getPubDate() + ";" + book.getPublisher() +
                ";" +
                book.getSynopsis() + ";" +
                std::to_string(book.getPageCount()) + "\n";
        writeFile << saveLine;


    }
    writeFile.close();
}


bool Shelf::checkIfBookExists(Book newBook) {
    bool exists = false;
    for (auto book : shelf) {
        if (newBook.getAuthor() == book.getAuthor() && newBook.getTitle() == book.getTitle() &&
            newBook.getPublisher() == book.getPublisher() &&
            newBook.getPubDate() == book.getPubDate() && newBook.getPageCount() == book.getPageCount() &&
            newBook.getSynopsis() == book.getSynopsis()) {
            exists = true;


        }
    }
    return exists;

}