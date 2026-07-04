#include "../include/Book.h"

Book::Book()
{
    id = 0;
    title = "";
    author = "";
    category = "";
    publishedYear = 0;
    available = true;
    borrowCount = 0;
}

Book::Book(
    int id,
    std::string title,
    std::string author,
    std::string category,
    int publishedYear,
    bool available
)
{
    this->id = id;
    this->title = title;
    this->author = author;
    this->category = category;
    this->publishedYear = publishedYear;
    this->available = available;
    borrowCount = 0;
}

int Book::getId() const
{
    return id;
}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

std::string Book::getCategory() const
{
    return category;
}

int Book::getPublishedYear() const
{
    return publishedYear;
}

bool Book::isAvailable() const
{
    return available;
}

int Book::getBorrowCount() const
{
    return borrowCount;
}

void Book::setTitle(std::string title)
{
    this->title = title;
}

void Book::setAuthor(std::string author)
{
    this->author = author;
}

void Book::setCategory(std::string category)
{
    this->category = category;
}

void Book::setPublishedYear(int year)
{
    publishedYear = year;
}

void Book::setAvailability(bool status)
{
    available = status;
}

void Book::increaseBorrowCount()
{
    borrowCount++;
}