#include <iostream>
#include "libraryItem.hpp"
#include "shelf.hpp"
#include "book.hpp"

int main() {

    Book book("GoT", "George R.R. Martin", "08/08/2008", "Bantam", "", 12313);
    Shelf shelf;
    shelf.addItem(book);
    shelf.addItem("Hans", "Christian", "10/10/2008", "Anderson", "", 2);
    
    shelf.showShelf();

    return 0;
}