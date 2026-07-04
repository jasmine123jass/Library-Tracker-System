#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book
{
private:
    int id;
    std::string title;
    std::string author;
    std::string category;
    int year;
    bool available;

public:
    Book();

    Book(
        int id,
        std::string title,
        std::string author,
        std::string category,
        int year,
        bool available = true
    );

    int getId() const;

    std::string getTitle() const;

    std::string getAuthor() const;

    std::string getCategory() const;

    int getYear() const;

    bool isAvailable() const;

    void setTitle(std::string title);

    void setAuthor(std::string author);

    void setCategory(std::string category);

    void setYear(int year);

    void setAvailability(bool status);
};

#endif