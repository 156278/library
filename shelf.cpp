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
        shelf.push_back(readLine(line));
    }

}

/*void Shelf::addItem(LibraryItem libraryItem) {
    shelf.push_back(libraryItem);

}*/

void Shelf::addItem(std::string titel, std::string author, std::string pubDate, std::string publisher,
                    std::string synopsis, unsigned int pageCount) {
    Book book(titel, author, pubDate, publisher, synopsis, pageCount);
    shelf.push_back(book);
}


void Shelf::showShelf() {
    for (int i = 0; i < shelf.size(); i++) {
        shelf[i].showAll();
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
                book.titel + ";" + book.author + ";" + book.pubDate + ";" + book.publisher + ";" + book.synopsis + ";" +
                std::to_string(book.pageCount) + "\n";
        writeFile << saveLine;


    }
    writeFile.close();


}