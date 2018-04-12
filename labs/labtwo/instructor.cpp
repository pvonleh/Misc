#include "instructor.h"


Instructor::Instructor(string name, string emailAddress, string employeeID)
: Person(name, emailAddress)
{
    this->name = name;
}
string Instructor::GetEmployeeID(){
    return this->employeeID;
}
