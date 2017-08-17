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
            "          Press 3 to exit\n";
    Shelf *shelf;
    void clear();
    void screenBar();
    void showAllBooks();
    void addNewBook();


};