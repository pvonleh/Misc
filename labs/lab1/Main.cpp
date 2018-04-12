#include "AddressBook.h"

void PrintMenu();

int main(){
	
	AddressBook myBook;

	std::string name;
	std::string address;
	std::string phoneNumber;	
	std::string userMenuChoice = "";

	do{
		PrintMenu();
		//Read a string from the user, store it into 'userMenuChoice'
		getline(std::cin, userMenuChoice);

		//Convert the string in 'userMenuChoice' into an integer
		int convertedInput = stoi(userMenuChoice);

		switch(convertedInput){
			case 1:
				std::cout<<"Enter Name: ";
				getline(std::cin, name);
				std::cout<<"Enter Address: ";
				getline(std::cin, address);
				std::cout<<"Enter Phone Number: ";
				getline(std::cin, phoneNumber);

				myBook.AddEntry(name, address, phoneNumber);
				break;
			case 2:
				std::cout<<"Enter Name: ";
				getline(std::cin, name);
				myBook.SearchAddressBook(name);
				break;
			case 3:
				myBook.PrintAddressBook();
				break;
			case 4:
				break;
			default:
				std::cout<<"Invalid Entry."<<std::endl;
		}
	}while(userMenuChoice.compare("4") != 0);
	
	return 0;
}

void PrintMenu(){
	std::cout<<"1. Add Entry"<<std::endl;
	std::cout<<"2. Search By Name"<<std::endl;
	std::cout<<"3. List All Entries"<<std::endl;
	std::cout<<"4. Quit"<<std::endl;
	std::cout<<"Enter Choice: ";
}