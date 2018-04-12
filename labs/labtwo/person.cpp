#include "person.h"

Person::Person(string &name, string &emailAddress)
{
	this->name = name;
	this->emailAddress = emailAddress;
}
string Person::GetName()
{
return this->name;
}
	string Person::GetEmailAddress(){
return this->emailAddress;
}
