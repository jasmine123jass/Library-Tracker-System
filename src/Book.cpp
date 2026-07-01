#include "../include/Book.h"

Book::Book()
{
    id = 0;
    name = "";
    author = "";
    category = "";
    borrowed = false;
    borrowCount = 0;
}

Book::Book(
    int id,
    string name,
    string author,
    string category,
    bool borrowed,
    int borrowCount
)
{
    this->id = id;
    this->name = name;
    this->author = author;
    this->category = category;
    this->borrowed = borrowed;
    this->borrowCount = borrowCount;
}

int Book::getId() const
{
    return id;
}

string Book::getName() const
{
    return name;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getCategory() const
{
    return category;
}

bool Book::isBorrowed() const
{
    return borrowed;
}

int Book::getBorrowCount() const
{
    return borrowCount;
}

void Book::setName(string name)
{
    this->name = name;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

void Book::setCategory(string category)
{
    this->category = category;
}

void Book::setBorrowed(bool status)
{
    borrowed = status;
}

void Book::increaseBorrowCount()
{
    borrowCount++;
}