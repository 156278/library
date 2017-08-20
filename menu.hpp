#pragma once

#include "shelf.hpp"

class Menu {

public:
    Menu();
    ~Menu();

    void welcomeView();

private:
    std::string welcomeText =
            "          Welcome to library!\n"
            "          Press 1 to show all books\n"
            "          Press 2 to add book\n"
            "          Press 3 to delete a book\n"
            "          Press 4 to search for (a) book(s)\n"
            "          Press 5 to exit\n";
    Shelf *shelf;
    void clear();
    void screenBar();
    void showAllBooks();
    void addNewBook();
    void delBook();
    void search();



};