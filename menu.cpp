
#include <iostream>
#include <climits>
#include "menu.hpp"
#include "shelf.hpp"

Menu::Menu() {
    this->shelf = new Shelf("../save.txt");

}

Menu::~Menu() {

    delete shelf;

}

void Menu::welcomeView() {
    while (true) {
        screenBar();
        std::cout << welcomeText;
        screenBar();
        int input = 0;
        std::cin >> input;

        while (input != 1 && input != 2 && input != 3) {
            std::cout << "Wrong input, choose a valid key" << std::endl;
            std::cin >> input;

        }
        if (input == 1) {
            showAllBooks();
        } else if (input == 2) {
            addNewBook();

        } else {
            break;
        }
        clear();
    }
}

void Menu::showAllBooks() {
    this->shelf->showShelf();
    std::cout << "Press any # to continue" << std::endl;
    int i;
    std::cin >> i;

}

void Menu::addNewBook() {
    std::string titel;
    std::string author;
    std::string pubDate;
    std::string publisher;
    std::string synopsis;
    unsigned int pageCount;
    clear();
    screenBar();
    std::cin.ignore();
    std::cin.clear();
    std::cout << "Plese insert title: " << std::endl;
    std::getline(std::cin, titel);
    std::cout << "Plese insert the Author's Name: " << std::endl;
    std::getline(std::cin, author);
    std::cout << "Plese insert publication date: " << std::endl;
    std::getline(std::cin, pubDate);
    std::cout << "Plese insert the name of the publisher: " << std::endl;
    std::getline(std::cin, publisher);
    std::cout << "Plese insert a synopsis: " << std::endl;
    std::getline(std::cin, synopsis);
    std::cout << "Plese insert the number of pages: " << std::endl;
    std::cin >> pageCount;
    shelf->addItem(titel, author, pubDate, publisher, synopsis, pageCount);

}

void Menu::screenBar() {
    std::cout << "=============================================\n";
}

void Menu::clear() {
    std::cout << std::string(30, '\n');
}


