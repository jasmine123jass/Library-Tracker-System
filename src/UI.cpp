#include "../include/UI.h"
#include "../include/FileManager.h"

#include <iostream>
#include <limits>

using namespace std;

UI::UI(Library &library)
    : library(library)
{

}

void UI::showMainMenu()
{
    int choice;

    while(true)
    {
        system("cls");

        cout<<"=====================================================\n";
        cout<<"          LIBRARY MANAGEMENT SYSTEM\n";
        cout<<"=====================================================\n\n";

        cout<<"1. Add Book\n";
        cout<<"2. Display Books\n";
        cout<<"3. Borrow Book\n";
        cout<<"4. Return Book\n";
        cout<<"5. Edit Book\n";
        cout<<"6. Delete Book\n";
        cout<<"7. Search Books\n";
        cout<<"8. Statistics\n";
        cout<<"9. Sort Books\n";
        cout<<"10. Save Books\n";
        cout<<"11. Exit\n\n";

        cout<<"Enter Choice : ";

        cin>>choice;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
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
            searchMenuUI();
            break;

        case 8:
            statisticsUI();
            break;

        case 9:
            sortMenuUI();
            break;

        case 10:

            if(FileManager::saveBooks(
                library.getBooks(),
                "data/books.txt"
            ))
                cout<<"\nBooks Saved Successfully.\n";
            else
                cout<<"\nUnable To Save.\n";

            system("pause");

            break;

        case 11:

            FileManager::saveBooks(
                library.getBooks(),
                "data/books.txt"
            );

            return;

        default:

            cout<<"\nInvalid Choice.\n";

            system("pause");

        }

    }

}

void UI::addBookUI()
{
    string name;
    string author;
    string category;

    cin.ignore();

    cout<<"\nBook Name : ";
    getline(cin,name);

    cout<<"Author : ";
    getline(cin,author);

    cout<<"Category : ";
    getline(cin,category);

    library.addBook(
        name,
        author,
        category
    );

    cout<<"\nBook Added Successfully.\n";

    system("pause");
}

void UI::displayBooksUI()
{
    library.displayBooks();

    system("pause");
}

void UI::borrowBookUI()
{
    library.borrowBook();

    system("pause");
}

void UI::returnBookUI()
{
    library.returnBook();

    system("pause");
}

void UI::deleteBookUI()
{
    library.deleteBook();

    system("pause");
}

void UI::editBookUI()
{
    library.editBook();

    system("pause");
}

void UI::statisticsUI()
{
    library.statistics();

    library.mostBorrowedBook();

    system("pause");
}

void UI::sortMenuUI()
{
    int choice;

    cout<<"\n";

    cout<<"1. Sort By Name\n";
    cout<<"2. Sort By Author\n";

    cout<<"\nChoice : ";

    cin>>choice;

    if(choice==1)
        library.sortByName();

    else if(choice==2)
        library.sortByAuthor();

    system("pause");
}

void UI::searchMenuUI()
{
    int choice;

    cout<<"\n";

    cout<<"1. Search By Book Name\n";
    cout<<"2. Search By Author\n";
    cout<<"3. Search By Category\n";

    cout<<"\nChoice : ";

    cin>>choice;

    switch(choice)
    {

    case 1:

        library.searchBook();

        break;

    case 2:

        library.searchByAuthor();

        break;

    case 3:

        library.searchByCategory();

        break;

    }

    system("pause");
}