#include "AddressBook.h"

AddressBook::AddressBook(){

}

Entry* AddressBook::SearchAddressBook(std::string name){
	bool found = false;

	for(Entry* entry : this->entries){
		if(entry->GetName().compare(name) == 0){
			entry->PrintEntry();
			found = true;
		}
	}

	if(!found){
		std::cout<<"No entry with that name found."<<std::endl;
	}
}

void AddressBook::AddEntry(std::string name, std::string address, std::string phoneNumber){
	this->entries.push_back(new Entry(name, address, phoneNumber));
}

void AddressBook::PrintAddressBook(){
	for(Entry* entry : this->entries){
		entry->PrintEntry();
	}
}