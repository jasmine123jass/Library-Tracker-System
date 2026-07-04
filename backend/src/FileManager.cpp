#include "../include/FileManager.h"

#include <fstream>
#include <sstream>

using namespace std;

void FileManager::saveBooks(const vector<Book>& books)
{
    ofstream file("../data/books.txt");

    if (!file.is_open())
        return;

    for (const Book& book : books)
    {
        file
            << book.getId() << "|"
            << book.getTitle() << "|"
            << book.getAuthor() << "|"
            << book.getCategory() << "|"
            << book.getYear() << "|"
            << book.isAvailable()
            << endl;
    }

    file.close();
}

vector<Book> FileManager::loadBooks()
{
    vector<Book> books;

    ifstream file("../data/books.txt");

    if (!file.is_open())
        return books;

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id;
        string title;
        string author;
        string category;
        string year;
        string available;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, category, '|');
        getline(ss, year, '|');
        getline(ss, available, '|');

        books.push_back(

            Book(

                stoi(id),

                title,

                author,

                category,

                stoi(year),

                stoi(available)

            )

        );
    }

    file.close();

    return books;
}