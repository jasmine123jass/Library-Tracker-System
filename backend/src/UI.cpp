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
bool UI::adminLogin()
{
    string username;
    string password;

    cout << "\n========== ADMIN LOGIN ==========\n";

    cout << "Username : ";
    cin >> username;

    cout << "Password : ";
    cin >> password;

    if(username=="admin" && password=="admin123")
    {
        cout<<"\nLogin Successful!\n";

        pauseScreen();

        return true;
    }

    cout<<"\nInvalid Username or Password!\n";

    pauseScreen();

    return false;
}
void UI::showMainMenu()
{
    int choice;

    while(true)
    {
        system("cls");

        cout << "====================================\n";
        cout << "     LIBRARY MANAGEMENT SYSTEM\n";
        cout << "====================================\n\n";

        cout << "1. Admin Login\n";
        cout << "2. User Menu\n";
        cout << "3. Exit\n\n";

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

            if(adminLogin())
            {
                bool adminMenu = true;

                while(adminMenu)
                {
                    system("cls");

                    int adminChoice;

                    cout << "========== ADMIN MENU ==========\n\n";

                    cout << "1. Add Book\n";
                    cout << "2. Edit Book\n";
                    cout << "3. Delete Book\n";
                    cout << "4. Statistics\n";
                    cout << "5. Save Books\n";
                    cout << "6. Back\n\n";

                    cout << "Choice : ";
                    cin >> adminChoice;

                    switch(adminChoice)
                    {
                    case 1:
                        addBookUI();
                        break;

                    case 2:
                        editBookUI();
                        break;

                    case 3:
                        deleteBookUI();
                        break;

                    case 4:
                        statisticsUI();
                        break;

                    case 5:

                        if(FileManager::saveBooks(
                            library.getBooks(),
                            "data/books.txt"
                        ))
                            cout << "\nBooks Saved Successfully.\n";
                        else
                            cout << "\nUnable To Save Books.\n";

                        pauseScreen();

                        break;

                    case 6:
                        adminMenu = false;
                        break;

                    default:
                        cout << "\nInvalid Choice!\n";
                        pauseScreen();
                    }
                }
            }

            break;

        case 2:
        {
            bool userMenu = true;

            while(userMenu)
            {
                system("cls");

                int userChoice;

                cout << "========== USER MENU ==========\n\n";

                cout << "1. Display Books\n";
                cout << "2. Display Available Books\n";
                cout << "3. Display Borrowed Books\n";
                cout << "4. Borrow Book\n";
                cout << "5. Return Book\n";
                cout << "6. Search Book\n";
                cout << "7. Sort Books\n";
                cout << "8. Back\n\n";

                cout << "Choice : ";
                cin >> userChoice;

                switch(userChoice)
                {
                case 1:
                    displayBooksUI();
                    break;

                case 2:
                    displayAvailableBooksUI();
                    break;

                case 3:
                    displayBorrowedBooksUI();
                    break;

                case 4:
                    borrowBookUI();
                    break;

                case 5:
                    returnBookUI();
                    break;

                case 6:
                    searchBookUI();
                    break;

                case 7:
                    sortBooksUI();
                    break;

                case 8:
                    userMenu = false;
                    break;

                default:
                    cout << "\nInvalid Choice!\n";
                    pauseScreen();
                }
            }       

            break;
        }

        case 3:

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
    int choice;

    cout << "\nSearch By\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. Category\n";

    cout << "\nChoice : ";
    cin >> choice;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string keyword;

    switch(choice)
    {
        case 1:

            cout << "\nEnter Book Title : ";
            getline(cin, keyword);

            library.searchBook(keyword);

            break;

        case 2:

            cout << "\nEnter Author Name : ";
            getline(cin, keyword);

            library.searchByAuthor(keyword);

            break;

        case 3:

            cout << "\nEnter Category : ";
            getline(cin, keyword);

            library.searchByCategory(keyword);

            break;

        default:

            cout << "\nInvalid Choice.\n";
    }

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
void UI::displayAvailableBooksUI()
{
    library.displayAvailableBooks();

    pauseScreen();
}
void UI::displayBorrowedBooksUI()
{
    library.displayBorrowedBooks();

    pauseScreen();
}