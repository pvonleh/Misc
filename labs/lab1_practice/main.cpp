#include <iostream>

using namespace std;
/*
 * Create an address book that:
 * 1. Add Entry
 * 2. Search By Name
 * 3. List All Entries
 * 4. Quit
 * Enter Choice:*/



int main()
{
    int choice;
    cout << "Create an address book that:\n"
         << " 1. Add Entry\n"
         << " 2. Search By Name\n"
         << " 3. List All Entries\n"
         << " 4. Quit\n"
         << " Enter Choice: ";

    switch (choice) {
    case 1:
        cout << "Add Entry: ";
        break;
    case 2:
        cout << "Search Name: ";
        break;
    case 3:
        cout << "List All Entries: ";
    case 4:
        cout << "Quit";
    default:
        break;
    }
    return 0;
}
