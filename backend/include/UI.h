#ifndef UI_H
#define UI_H

#include "Library.h"

class UI
{
private:
    Library &library;

public:

    UI(Library &library);

    void showMainMenu();

    bool adminLogin();

    void addBookUI();

    void displayBooksUI();

    void borrowBookUI();

    void returnBookUI();

    void deleteBookUI();

    void editBookUI();

    void searchBookUI();

    void statisticsUI();

    void sortBooksUI();
};

#endif