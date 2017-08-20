
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

        while (input < 1 || input > 5) {
            std::cout << "Wrong input, choose a valid key" << std::endl;
            std::cin >> input;

        }
        if (input == 1) {
            showAllBooks();
        } else if (input == 2) {
            addNewBook();
        } else if (input == 3) {
            delBook();
        } else if (input == 4) {
            search();
        } else {
            break;
        }
        clear();
    }
}

void Menu::showAllBooks() {
    this->shelf->showShelf(false);
    std::cout << "Press any # to continue" << std::endl;
    int i;
    std::cin >> i;

}

void Menu::search() {
    std::cin.ignore();
    std::cin.clear();
    std::string searchStr;
    std::cout << "Plese insert search term: " << std::endl;
    std::getline(std::cin, searchStr);
    std::vector<int> results = shelf->search(searchStr);
    std::cout << "The search term was found in the following books: " << std::endl;

    for (auto i:results) {
        std::cout << "Book: " << i << std::endl;
    }

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

void Menu::delBook() {
    int bookNrToDel;
    do {
        shelf->showShelf(true);
        std::cout << "Plese specify which book shall be deleted (0 to exit): " << std::endl;
        std::cin >> bookNrToDel;
        shelf->delBook(bookNrToDel);
    } while (bookNrToDel != 0);
}

void Menu::screenBar() {
    std::cout << "=============================================\n";
}

void Menu::clear() {
    std::cout << std::string(30, '\n');
}


