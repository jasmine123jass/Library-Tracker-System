#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
private:
    int id;
    string name;
    string author;
    string category;
    bool borrowed;
    int borrowCount;

public:

    Book();

    Book(
        int id,
        string name,
        string author,
        string category,
        bool borrowed = false,
        int borrowCount = 0
    );

    int getId() const;

    string getName() const;

    string getAuthor() const;

    string getCategory() const;

    bool isBorrowed() const;

    int getBorrowCount() const;

    void setName(string name);

    void setAuthor(string author);

    void setCategory(string category);

    void setBorrowed(bool status);

    void increaseBorrowCount();
};

#endif