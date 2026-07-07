#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

class Library
{
private:

    std::vector<Book> books;

    int nextBookId;

public:

    Library();

    std::vector<Book>& getBooks();

    void setBooks(std::vector<Book> books);

    void addBook(
        std::string title,
        std::string author,
        std::string category,
        int year
    );

    void displayBooks() const;

    void deleteBook(int id);

    void editBook(int id);

    void borrowBook(int id);

    void returnBook(int id);

    void searchBook(std::string keyword);

    void searchByAuthor(std::string author);

    void searchByCategory(std::string category);

    void sortByTitle();

    void sortByAuthor();

    void showStatistics();

    void displayAvailableBooks() const;

    void displayBorrowedBooks() const;
};

#endif