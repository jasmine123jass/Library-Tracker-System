#include "../include/FileManager.h"

#include <fstream>
#include <sstream>

using namespace std;

bool FileManager::saveBooks(
    const vector<Book>& books,
    const string& filename
)
{
    ofstream file(filename);

    if(!file.is_open())
        return false;

    for(const Book &book : books)
    {
        file
            << book.getId() << ","
            << book.getTitle() << ","
            << book.getAuthor() << ","
            << book.getCategory() << ","
            << book.getPublishedYear() << ","
            << book.isAvailable() << ","
            << book.getBorrowCount()
            << endl;
    }

    file.close();

    return true;
}
vector<Book> FileManager::loadBooks(
    const string& filename
)
{
    vector<Book> books;

    ifstream file(filename);

    if(!file.is_open())
        return books;

    string line;

    while(getline(file,line))
    {
        stringstream ss(line);

        string id;
        string title;
        string author;
        string category;
        string year;
        string available;
        string borrowCount;

        getline(ss,id,',');
        getline(ss,title,',');
        getline(ss,author,',');
        getline(ss,category,',');
        getline(ss,year,',');
        getline(ss,available,',');
        getline(ss,borrowCount,',');

        Book book(
            stoi(id),
            title,
            author,
            category,
            stoi(year),
            available == "1"
        );

        for(int i = 0; i < stoi(borrowCount); i++)
        {
            book.increaseBorrowCount();
        }

        books.push_back(book);
    }

    file.close();

    return books;
}