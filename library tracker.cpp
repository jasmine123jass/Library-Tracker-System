#include <bits/stdc++.h>
using namespace std;

class Book {
private:
    string name;
    string author;
    bool isBorrowed;

public:
    Book(string name, string author) {
        this->name = name;
        this->author = author;
        isBorrowed = false;
    }

    string getBookName() {
        return this->name;
    }

    string getAuthorName() {
        return this->author;
    }

    bool BorrowedStatus() {
        return this->isBorrowed;
    }

    void setBookStatus(bool f) {
        this->isBorrowed = f;
    }
};

class Library {
private:
    vector<Book> list;

public:
    Library() {}

    void addBook(Book b) {
        list.push_back(b);
    }

    void returnBook(int ind) {
        if (list.empty() || ind <= 0 || ind > list.size())
            return;
        list[ind - 1].setBookStatus(false);
    }

    void displayBooks() {
        if (list.empty()) {
            cout << "No books in library.\n";
            return;
        }
        for (int i = 0; i < list.size(); i++) {
            cout << (i + 1) << ". Book name: " << list[i].getBookName()
                 << ", written by " << list[i].getAuthorName();
            if (list[i].BorrowedStatus()) cout << " [Borrowed]";
            cout << endl;
        }
    }

    void displayBorrowedBooks() {
        bool found = false;
        for (int i = 0; i < list.size(); i++) {
            if (list[i].BorrowedStatus()) {
                cout << (i + 1) << ". Book name: " << list[i].getBookName()
                     << ", written by " << list[i].getAuthorName() << endl;
                found = true;
            }
        }
        if (!found) cout << "No borrowed books.\n";
    }

    void borrowBook(int ind) {
        if (list.empty() || ind <= 0 || ind > list.size())
            return;
        list[ind - 1].setBookStatus(true);
    }
};

int main() {
    Library lib;
    int choice;

    do {
        cout << "\n===== Library Menu =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "5. Display Borrowed Books\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: \n";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name, author;
                cout << "Enter book name: \n";
                cin.ignore();
                getline(cin, name);
                cout << "Enter author name: ";
                getline(cin, author);
                Book b(name, author);
                lib.addBook(b);
                cout << "Book added successfully!\n";
                break;
            }
            case 2:
                cout << "\nAll Books:\n";
                lib.displayBooks();
                break;

            case 3: {
                int id;
                cout << "Enter book index to borrow: ";
                cin >> id;
                lib.borrowBook(id);
                cout << "Book borrowed!\n";
                break;
            }
            case 4: {
                int id;
                cout << "Enter book index to return: ";
                cin >> id;
                lib.returnBook(id);
                cout << "Book returned!\n";
                break;
            }
            case 5:
                cout << "\nBorrowed Books:\n";
                lib.displayBorrowedBooks();
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
