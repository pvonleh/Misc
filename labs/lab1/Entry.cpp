#include "Entry.h"

Entry::Entry(std::string name, std::string address, std::string phoneNumber){
	this->name = name;
	this->address = address;
	this->phoneNumber = phoneNumber;
}

void Entry::PrintEntry(){
	std::cout<<this->name<<"\t"<<this->address<<"\t"<<this->phoneNumber<<std::endl;
}

std::string Entry::GetName(){
	return this->name;
}