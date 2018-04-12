#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H
#include "entry.h"

#include <list>

// Address book should save entry and search for an entry
class AddressBook
{
public:
    AddressBook();
    Entry *SearchAddressBook(string name);
    void AddEntry(string name, string address, string phoneNumber);
    void PrintAddressBook();

private:
    list<Entry*> entries;
};

#endif // ADDRESSBOOK_H
