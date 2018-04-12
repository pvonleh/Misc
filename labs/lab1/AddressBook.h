#ifndef ADDRESSBOOK_HPP
#define ADDRESSBOOK_HPP

#include "Entry.h"
#include <list>

class AddressBook{
	public:
		AddressBook();
		Entry* SearchAddressBook(std::string name);
		void AddEntry(std::string name, std::string address, std::string phoneNumber);
		void PrintAddressBook();
		
	private:
		std::list<Entry*> entries;
};
#endif