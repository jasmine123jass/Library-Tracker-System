#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

using namespace std;

class Library
{
private:

    vector<Book> books;
    int nextBookId;

public:

    Library();

    void addBook(string name, string author, string category);
    void setBooks(vector<Book> books);
    void displayBooks();

    void borrowBook();

    void returnBook();

    void deleteBook();

    void editBook();

    void searchBook();

    void searchByAuthor();

    void searchByCategory();

    void sortByName();

    void sortByAuthor();

    void statistics();

    void mostBorrowedBook();

    vector<Book>& getBooks();
};

#endif