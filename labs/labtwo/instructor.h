#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;
class Instructor : public Person
{
public:
    Instructor(string name, string emailAddress, string employeeID);
    string GetEmployeeID();
    
private:
    string employeeID;
};

#endif // INSTRUCTOR_H
