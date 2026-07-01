#include "../include/Library.h"

#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Library::Library()
{
    nextBookId = 1001;
}

vector<Book>& Library::getBooks()
{
    return books;
}
void Library::addBook(string name, string author, string category)
{
    Book book(
        nextBookId++,
        name,
        author,
        category
    );

    books.push_back(book);
}
void Library::displayBooks()
{
    if(books.empty())
    {
        cout<<"\nLibrary Empty.\n";
        return;
    }

    cout<<left;

    cout<<setw(8)<<"ID"
        <<setw(30)<<"Book"
        <<setw(25)<<"Author"
        <<setw(20)<<"Category"
        <<setw(15)<<"Status"
        <<endl;

    cout<<string(95,'-')<<endl;

    for(Book &b:books)
    {
        cout<<setw(8)<<b.getId()
            <<setw(30)<<b.getName()
            <<setw(25)<<b.getAuthor()
            <<setw(20)<<b.getCategory();

        if(b.isBorrowed())
            cout<<"Borrowed";
        else
            cout<<"Available";

        cout<<endl;
    }
}

void Library::borrowBook()
{
    int id;

    cout<<"Enter Book ID : ";
    cin>>id;

    for(Book &b:books)
    {
        if(b.getId()==id)
        {
            if(b.isBorrowed())
            {
                cout<<"Already Borrowed.\n";
                return;
            }

            b.setBorrowed(true);

            b.increaseBorrowCount();

            cout<<"Book Borrowed Successfully.\n";

            return;
        }
    }

    cout<<"Book Not Found.\n";
}

void Library::returnBook()
{
    int id;

    cout<<"Enter Book ID : ";

    cin>>id;

    for(Book &b:books)
    {
        if(b.getId()==id)
        {
            if(!b.isBorrowed())
            {
                cout<<"Book Already Available.\n";
                return;
            }

            b.setBorrowed(false);

            cout<<"Book Returned Successfully.\n";

            return;
        }
    }

    cout<<"Book Not Found.\n";
}
void Library::deleteBook()
{
    int id;

    cout << "Enter Book ID : ";
    cin >> id;

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
void Library::editBook()
{
    int id;

    cout << "Enter Book ID : ";
    cin >> id;

    cin.ignore();

    for(Book &b : books)
    {
        if(b.getId() == id)
        {
            string name;
            string author;
            string category;

            cout << "New Book Name : ";
            getline(cin,name);

            cout << "New Author : ";
            getline(cin,author);

            cout << "New Category : ";
            getline(cin,category);

            b.setName(name);
            b.setAuthor(author);
            b.setCategory(category);

            cout << "\nBook Updated Successfully.\n";

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}
void Library::searchBook()
{
    cin.ignore();

    string keyword;

    cout << "Enter Book Name : ";

    getline(cin,keyword);

    bool found = false;

    transform(keyword.begin(),keyword.end(),keyword.begin(),::tolower);

    for(Book &b : books)
    {
        string temp = b.getName();

        transform(temp.begin(),temp.end(),temp.begin(),::tolower);

        if(temp.find(keyword)!=string::npos)
        {
            found = true;

            cout << "\nID : " << b.getId() << endl;
            cout << "Book : " << b.getName() << endl;
            cout << "Author : " << b.getAuthor() << endl;
            cout << "Category : " << b.getCategory() << endl;
            cout << "Status : ";

            if(b.isBorrowed())
                cout << "Borrowed\n";
            else
                cout << "Available\n";

            cout << "--------------------------\n";
        }
    }

    if(!found)
        cout << "\nNo Book Found.\n";
}
void Library::searchByAuthor()
{
    cin.ignore();

    string author;

    cout << "Enter Author Name : ";

    getline(cin,author);

    transform(author.begin(),author.end(),author.begin(),::tolower);

    bool found = false;

    for(Book &b : books)
    {
        string temp = b.getAuthor();

        transform(temp.begin(),temp.end(),temp.begin(),::tolower);

        if(temp.find(author)!=string::npos)
        {
            found = true;

            cout << b.getId()
                 << " | "
                 << b.getName()
                 << " | "
                 << b.getAuthor()
                 << endl;
        }
    }

    if(!found)
        cout << "\nNo Books Found.\n";
}
void Library::searchByCategory()
{
    cin.ignore();

    string category;

    cout << "Enter Category : ";

    getline(cin,category);

    transform(category.begin(),category.end(),category.begin(),::tolower);

    bool found = false;

    for(Book &b : books)
    {
        string temp = b.getCategory();

        transform(temp.begin(),temp.end(),temp.begin(),::tolower);

        if(temp.find(category)!=string::npos)
        {
            found = true;

            cout << b.getId()
                 << " | "
                 << b.getName()
                 << " | "
                 << b.getAuthor()
                 << endl;
        }
    }

    if(!found)
        cout << "\nNo Books Found.\n";
}
void Library::sortByName()
{
    sort(
        books.begin(),
        books.end(),
        [](Book a,Book b)
        {
            return a.getName()<b.getName();
        });

    cout << "\nBooks Sorted By Name.\n";
}
void Library::sortByAuthor()
{
    sort(
        books.begin(),
        books.end(),
        [](Book a,Book b)
        {
            return a.getAuthor()<b.getAuthor();
        });

    cout << "\nBooks Sorted By Author.\n";
}
void Library::statistics()
{
    int borrowed = 0;

    for(Book &b : books)
    {
        if(b.isBorrowed())
            borrowed++;
    }

    cout << "\n==============================\n";
    cout << "Library Statistics\n";
    cout << "==============================\n";

    cout << "Total Books      : " << books.size() << endl;
    cout << "Borrowed Books   : " << borrowed << endl;
    cout << "Available Books  : " << books.size()-borrowed << endl;
}
void Library::mostBorrowedBook()
{
    if(books.empty())
    {
        cout << "No Books Available.\n";
        return;
    }

    Book *best = &books[0];

    for(Book &b : books)
    {
        if(b.getBorrowCount()>best->getBorrowCount())
            best=&b;
    }

    cout << "\nMost Borrowed Book\n";

    cout << "-------------------------\n";

    cout << "Book : " << best->getName() << endl;
    cout << "Author : " << best->getAuthor() << endl;
    cout << "Borrow Count : " << best->getBorrowCount() << endl;
}
void Library::setBooks(vector<Book> books)
{
    this->books = books;

    if(!books.empty())
    {
        nextBookId = books.back().getId() + 1;
    }
}