#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>

#include "Book.h"

class FileManager
{
public:

    static bool saveBooks(
        const std::vector<Book>& books,
        const std::string& filename
    );

    static std::vector<Book> loadBooks(
        const std::string& filename
    );
};

#endif