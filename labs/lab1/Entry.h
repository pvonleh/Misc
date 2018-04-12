#ifndef ENTRY_HPP
#define ENTRY_HPP

#include <string>
#include <iostream>

class Entry{
	public:
		Entry(std::string name, std::string address, std::string phoneNumber);
		void PrintEntry();
		std::string GetName();

	private:
		std::string name;
		std::string address;
		std::string phoneNumber;
};

#endif