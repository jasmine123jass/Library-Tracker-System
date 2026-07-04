#include "../include/Library.h"
#include "../include/UI.h"
#include "../include/FileManager.h"

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

    return 0;
}