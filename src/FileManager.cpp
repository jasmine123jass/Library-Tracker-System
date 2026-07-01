#include "../include/FileManager.h"

#include <fstream>
#include <sstream>

bool FileManager::saveBooks(
    const vector<Book>& books,
    const string& filename
)
{
    ofstream file(filename);

    if(!file.is_open())
        return false;

    for(const Book &book : books)
    {
        file
        << book.getId() << "|"
        << book.getName() << "|"
        << book.getAuthor() << "|"
        << book.getCategory() << "|"
        << book.isBorrowed() << "|"
        << book.getBorrowCount()
        << endl;
    }

    file.close();

    return true;
}

vector<Book> FileManager::loadBooks(
    const string& filename
)
{
    vector<Book> books;

    ifstream file(filename);

    if(!file.is_open())
        return books;

    string line;

    while(getline(file,line))
    {
        stringstream ss(line);

        string id;
        string name;
        string author;
        string category;
        string borrowed;
        string borrowCount;

        getline(ss,id,'|');
        getline(ss,name,'|');
        getline(ss,author,'|');
        getline(ss,category,'|');
        getline(ss,borrowed,'|');
        getline(ss,borrowCount,'|');

        Book book(

            stoi(id),

            name,

            author,

            category,

            stoi(borrowed),

            stoi(borrowCount)

        );

        books.push_back(book);
    }

    file.close();

    return books;
}