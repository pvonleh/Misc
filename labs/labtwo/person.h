#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(string &name, string &emailAddress);
	string GetName();
	string GetEmailAddress();
protected:
	string name;
	string emailAddress;

};

#endif // PERSON_H
