#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Book.h"

class FileManager
{
public:
    static void saveBooks(const std::vector<Book>& books);

    static std::vector<Book> loadBooks();
};

#endif