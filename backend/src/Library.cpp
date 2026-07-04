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

    cout << setw(8) << "ID"
         << setw(30) << "Title"
         << setw(25) << "Author"
         << setw(20) << "Category"
         << setw(10) << "Year"
         << setw(15) << "Status"
         << endl;

    cout << string(110,'-') << endl;

    for(const Book &book : books)
    {
        cout << setw(8) << book.getId()
             << setw(30) << book.getTitle()
             << setw(25) << book.getAuthor()
             << setw(20) << book.getCategory()
             << setw(10) << book.getPublishedYear();

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