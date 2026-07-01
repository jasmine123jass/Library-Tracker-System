#include "../include/Library.h"
#include "../include/UI.h"
#include "../include/FileManager.h"

#include <iostream>

using namespace std;

int main()
{
    Library library;

    library.setBooks(
        FileManager::loadBooks(
            "data/books.txt"
        )
    );

    UI ui(library);

    ui.showMainMenu();

    FileManager::saveBooks(
        library.getBooks(),
        "data/books.txt"
    );

    cout << "\nThank You For Using Library Management System.\n";

    return 0;
}