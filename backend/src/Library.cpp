#include "../include/Library.h"

#include <iostream>
#include <iomanip>

using namespace std;

Library::Library()
{
    nextBookId = 1001;
}

vector<Book>& Library::getBooks()
{
    return books;
}

void Library::setBooks(vector<Book> books)
{
    this->books = books;

    if(!books.empty())
    {
        nextBookId = books.back().getId() + 1;
    }
}

void Library::addBook(
    string title,
    string author,
    string category,
    int year
)
{
    Book book(
        nextBookId++,
        title,
        author,
        category,
        year
    );

    books.push_back(book);

    cout << "\nBook Added Successfully.\n";
}

void Library::displayBooks() const
{
    if(books.empty())
    {
        cout << "\nNo Books Available.\n";
        return;
    }

    cout << left;

    cout << setw(8)  << "ID"
        << setw(30) << "Title"
        << setw(25) << "Author"
        << setw(20) << "Category"
        << setw(10) << "Year"
        << setw(15) << "Issue"
        << setw(15) << "Return"
        << setw(10) << "Fine"
        << setw(15) << "Status"
        << endl;

    cout << string(110,'-') << endl;

for( const Book &book : books)
{
    cout << setw(8)  << book.getId()
        << setw(30) << book.getTitle()
        << setw(25) << book.getAuthor()
        << setw(20) << book.getCategory()
        << setw(10) << book.getPublishedYear()
        << setw(15) << book.getIssueDate()
        << setw(15) << book.getReturnDate()
        << setw(10) << book.getFine();

    if(book.isAvailable())
        cout << "Available";
    else
        cout << "Borrowed";

    cout << endl;
}
}
void Library::deleteBook(int id)
{
    for(auto it = books.begin(); it != books.end(); it++)
    {
        if(it->getId() == id)
        {
            books.erase(it);

            cout << "\nBook Deleted Successfully.\n";

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}

void Library::editBook(int id)
{
    for(Book &book : books)
    {
        if(book.getId() == id)
        {
            string title;
            string author;
            string category;
            int year;

            cin.ignore();

            cout << "New Title : ";
            getline(cin, title);

            cout << "New Author : ";
            getline(cin, author);

            cout << "New Category : ";
            getline(cin, category);

            cout << "Published Year : ";
            cin >> year;

            book.setTitle(title);
            book.setAuthor(author);
            book.setCategory(category);
            book.setPublishedYear(year);

            cout << "\nBook Updated Successfully.\n";

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}

void Library::borrowBook(int id)
{
    for(Book &book : books)
    {
        if(book.getId() == id)
        {
            if(!book.isAvailable())
            {
                cout << "\nBook Already Borrowed.\n";
                return;
            }

            book.setAvailability(false);

            std::string issue;

            std::cout << "Enter Issue Date (DD/MM/YYYY): ";
            std::cin >> issue;

            book.setIssueDate(issue);

            book.increaseBorrowCount();

            cout << "\nBook Borrowed Successfully.\n";

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}

void Library::returnBook(int id)
{
    for(Book &book : books)
    {
        if(book.getId() == id)
        {
            if(book.isAvailable())
            {
                cout << "\nBook Already Available.\n";
                return;
            }

            std::string ret;

            std::cout << "Enter Return Date (DD/MM/YYYY): ";
            std::cin >> ret;

            book.setReturnDate(ret);

            int days;

            std::cout << "Enter Number of Days Book was Kept : ";
            std::cin >> days;

            int fine = 0;

            if(days > 7)
            {
                fine = (days - 7) * 10;
            }

            book.setFine(fine);

            if(fine > 0)
            {
                std::cout << "\nFine Amount : Rs. " << fine << std::endl;
            }
            else
            {
               std::cout << "\nNo Fine.\n";
            }

            book.setAvailability(true);

            cout << "\nBook Returned Successfully.\n";

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}
#include <algorithm>

void Library::searchBook(std::string keyword)
{
    transform(
        keyword.begin(),
        keyword.end(),
        keyword.begin(),
        ::tolower
    );

    bool found = false;

    for(const Book &book : books)
    {
        string title = book.getTitle();

        transform(
            title.begin(),
            title.end(),
            title.begin(),
            ::tolower
        );

        if(title.find(keyword) != string::npos)
        {
            found = true;

            cout << "\n-----------------------------------------\n";
            cout << "ID       : " << book.getId() << endl;
            cout << "Title    : " << book.getTitle() << endl;
            cout << "Author   : " << book.getAuthor() << endl;
            cout << "Category : " << book.getCategory() << endl;
            cout << "Year     : " << book.getPublishedYear() << endl;
            cout << "Status   : ";

            if(book.isAvailable())
                cout << "Available";
            else
                cout << "Borrowed";

            cout << endl;
        }
    }

    if(!found)
    {
        cout << "\nNo Book Found.\n";
    }
}

void Library::sortByTitle()
{
    sort(
        books.begin(),
        books.end(),
        [](const Book &a,const Book &b)
        {
            return a.getTitle() < b.getTitle();
        }
    );

    cout << "\nBooks Sorted By Title.\n";
}

void Library::sortByAuthor()
{
    sort(
        books.begin(),
        books.end(),
        [](const Book &a,const Book &b)
        {
            return a.getAuthor() < b.getAuthor();
        }
    );

    cout << "\nBooks Sorted By Author.\n";
}

void Library::showStatistics()
{
    int available = 0;
    int borrowed = 0;

    for(const Book &book : books)
    {
        if(book.isAvailable())
            available++;
        else
            borrowed++;
    }

    cout << "\n=================================\n";
    cout << "      Library Statistics\n";
    cout << "=================================\n";

    cout << "Total Books      : " << books.size() << endl;
    cout << "Available Books  : " << available << endl;
    cout << "Borrowed Books   : " << borrowed << endl;

    if(!books.empty())
    {
        Book best = books[0];

        for(const Book &book : books)
        {
            if(book.getBorrowCount() > best.getBorrowCount())
            {
                best = book;
            }
        }

        cout << "\nMost Borrowed Book\n";
        cout << "-------------------------\n";
        cout << "Title        : " << best.getTitle() << endl;
        cout << "Author       : " << best.getAuthor() << endl;
        cout << "Borrow Count : " << best.getBorrowCount() << endl;
    }

    cout << "=================================\n";
}
void Library::searchByAuthor(std::string author)
{
    bool found = false;

    for(const Book &book : books)
    {
        if(book.getAuthor().find(author) != std::string::npos)
        {
            found = true;

            std::cout << "\nID : " << book.getId() << std::endl;
            std::cout << "Title : " << book.getTitle() << std::endl;
            std::cout << "Author : " << book.getAuthor() << std::endl;
            std::cout << "Category : " << book.getCategory() << std::endl;
            std::cout << "Year : " << book.getPublishedYear() << std::endl;
            std::cout << "--------------------------\n";
        }
    }

    if(!found)
        std::cout << "\nNo Books Found.\n";
}
void Library::searchByCategory(std::string category)
{
    bool found = false;

    for(const Book &book : books)
    {
        if(book.getCategory().find(category) != std::string::npos)
        {
            found = true;

            std::cout << "\nID : " << book.getId() << std::endl;
            std::cout << "Title : " << book.getTitle() << std::endl;
            std::cout << "Author : " << book.getAuthor() << std::endl;
            std::cout << "Category : " << book.getCategory() << std::endl;
            std::cout << "Year : " << book.getPublishedYear() << std::endl;
            std::cout << "--------------------------\n";
        }
    }

    if(!found)
        std::cout << "\nNo Books Found.\n";
}
void Library::displayAvailableBooks() const
{
    bool found = false;

    cout << left;

    cout << setw(8)  << "ID"
         << setw(30) << "Title"
         << setw(25) << "Author"
         << setw(20) << "Category"
         << setw(10) << "Year"
         << endl;

    cout << string(95,'-') << endl;

    for(const Book &book : books)
    {
        if(book.isAvailable())
        {
            found = true;

            cout << setw(8)  << book.getId()
                 << setw(30) << book.getTitle()
                 << setw(25) << book.getAuthor()
                 << setw(20) << book.getCategory()
                 << setw(10) << book.getPublishedYear()
                 << endl;
        }
    }

    if(!found)
    {
        cout << "\nNo Available Books.\n";
    }
}
void Library::displayBorrowedBooks() const
{
    bool found = false;

    cout << left;

    cout << setw(8)  << "ID"
         << setw(30) << "Title"
         << setw(25) << "Author"
         << setw(20) << "Category"
         << setw(10) << "Year"
         << endl;

    cout << string(95,'-') << endl;

    for(const Book &book : books)
    {
        if(!book.isAvailable())
        {
            found = true;

            cout << setw(8)  << book.getId()
                 << setw(30) << book.getTitle()
                 << setw(25) << book.getAuthor()
                 << setw(20) << book.getCategory()
                 << setw(10) << book.getPublishedYear()
                 << endl;
        }
    }

    if(!found)
    {
        cout << "\nNo Borrowed Books.\n";
    }
}