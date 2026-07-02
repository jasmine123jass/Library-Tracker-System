#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include <string>
#include "Book.h"

using namespace std;

class FileManager
{
public:

    static bool saveBooks(
        const vector<Book>& books,
        const string& filename
    );

    static vector<Book> loadBooks(
        const string& filename
    );

};

#endif