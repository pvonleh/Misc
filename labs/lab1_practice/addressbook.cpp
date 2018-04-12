#include "addressbook.h"

AddressBook::AddressBook()
{

}

Entry *AddressBook::SearchAddressBook(string name){
    bool found = false;
    for(Entry *entry: this->entries)
    {
        if(entry->Getname().compare(name)==0)
        {
            entry->PrintEntr
        }
    }

}
void AddressBook::AddEntry(string name, string address, string phoneNumber){

}
void AddressBook::PrintAddressBook(){

}
