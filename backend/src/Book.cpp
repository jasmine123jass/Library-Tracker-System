#include "../include/Book.h"

Book::Book()
{
    id = 0;
    title = "";
    author = "";
    category = "";
    year = 0;
    available = true;
}

Book::Book(
    int id,
    std::string title,
    std::string author,
    std::string category,
    int year,
    bool available)
{
    this->id = id;
    this->title = title;
    this->author = author;
    this->category = category;
    this->year = year;
    this->available = available;
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

int Book::getYear() const
{
    return year;
}

bool Book::isAvailable() const
{
    return available;
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

void Book::setYear(int year)
{
    this->year = year;
}

void Book::setAvailability(bool status)
{
    available = status;
}