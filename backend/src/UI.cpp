#include "../include/UI.h"
#include "../include/FileManager.h"

#include <iostream>
#include <limits>

using namespace std;

void pauseScreen()
{
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

UI::UI(Library &library)
    : library(library)
{
}

void UI::showMainMenu()
{
    int choice;

    while (true)
    {
        system("cls");

        cout << "====================================\n";
        cout << "     LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n\n";

        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Edit Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Search Book\n";
        cout << "8. Statistics\n";
        cout << "9. Sort Books\n";
        cout << "10. Save Books\n";
        cout << "11. Exit\n\n";

        cout << "Enter Choice : ";

        cin >> choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid Input!\n";

            pauseScreen();

            continue;
        }

        switch(choice)
        {
            case 1:
                addBookUI();
                break;

            case 2:
                displayBooksUI();
                break;

            case 3:
                borrowBookUI();
                break;

            case 4:
                returnBookUI();
                break;

            case 5:
                editBookUI();
                break;

            case 6:
                deleteBookUI();
                break;

            case 7:
                searchBookUI();
                break;

            case 8:
                statisticsUI();
                break;

            case 9:
                sortBooksUI();
                break;

            case 10:

                if(FileManager::saveBooks(
                    library.getBooks(),
                    "data/books.txt"
                ))
                    cout << "\nBooks Saved Successfully.\n";
                else
                    cout << "\nUnable To Save Books.\n";

                pauseScreen();

                break;

            case 11:

                FileManager::saveBooks(
                    library.getBooks(),
                    "data/books.txt"
                );

                cout << "\nThank You!\n";

                return;

            default:

                cout << "\nInvalid Choice!\n";

                pauseScreen();
        }
    }
}

void UI::addBookUI()
{
    string title;
    string author;
    string category;
    int year;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nBook Title : ";
    getline(cin,title);

    cout << "Author : ";
    getline(cin,author);

    cout << "Category : ";
    getline(cin,category);

    cout << "Published Year : ";
    cin >> year;

    library.addBook(
        title,
        author,
        category,
        year
    );

    pauseScreen();
}

void UI::displayBooksUI()
{
    library.displayBooks();

    pauseScreen();
}

void UI::borrowBookUI()
{
    int id;

    cout << "\nEnter Book ID : ";
    cin >> id;

    library.borrowBook(id);

    pauseScreen();
}

void UI::returnBookUI()
{
    int id;

    cout << "\nEnter Book ID : ";
    cin >> id;

    library.returnBook(id);

    pauseScreen();
}

void UI::deleteBookUI()
{
    int id;

    cout << "\nEnter Book ID : ";
    cin >> id;

    library.deleteBook(id);

    pauseScreen();
}

void UI::editBookUI()
{
    int id;

    cout << "\nEnter Book ID : ";
    cin >> id;

    library.editBook(id);

    pauseScreen();
}

void UI::searchBookUI()
{
    string keyword;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter Book Title : ";

    getline(cin,keyword);

    library.searchBook(keyword);

    pauseScreen();
}

void UI::statisticsUI()
{
    library.showStatistics();

    pauseScreen();
}

void UI::sortBooksUI()
{
    int choice;

    cout << "\n1. Sort By Title\n";
    cout << "2. Sort By Author\n";

    cout << "\nChoice : ";

    cin >> choice;

    if(choice == 1)
    {
        library.sortByTitle();
    }
    else if(choice == 2)
    {
        library.sortByAuthor();
    }
    else
    {
        cout << "\nInvalid Choice.\n";
    }

    pauseScreen();
}