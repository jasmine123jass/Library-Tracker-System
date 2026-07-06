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
    std::string issueDate;
    std::string returnDate;
    int publishedYear;
    bool available;
    int borrowCount;

public:

    Book();

    Book(
        int id,
        std::string title,
        std::string author,
        std::string category,
        int publishedYear,
        bool available = true
    );

    int getId() const;

    std::string getTitle() const;

    std::string getAuthor() const;

    std::string getCategory() const;

    std::string getIssueDate() const;

    std::string getReturnDate() const;

    void setIssueDate(std::string date);

    void setReturnDate(std::string date);

    int getPublishedYear() const;

    bool isAvailable() const;

    int getBorrowCount() const;

    void setTitle(std::string title);

    void setAuthor(std::string author);

    void setCategory(std::string category);

    void setPublishedYear(int year);

    void setAvailability(bool status);

    void increaseBorrowCount();
};

#endif