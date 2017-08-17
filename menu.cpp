
#include <iostream>
#include "menu.hpp"
#include "shelf.hpp"

Menu::Menu() {
    this->shelf = new Shelf("../save.txt");

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
    std::cout << "Plese insert title: ";

    std::cin >> titel;
    std::cin >> titel;
    std::cin >> titel;
    std::cin >> titel;
    std::cin >> titel;
    std::cin >> titel;


}

void Menu::screenBar() {
    std::cout << "=============================================\n";
}

void Menu::clear() {
    std::cout << std::string(30, '\n');
}

