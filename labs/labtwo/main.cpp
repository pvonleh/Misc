#include <iostream>
//#include "Course.hpp"
#include "instructor.h"
using namespace std;
int main(){

    //Proof Instructor works.
    Instructor* myInstructor = new Instructor("Tom", "Tom@gmail.com", "12376");
    cout<<myInstructor->GetName()<<"\t"<<myInstructor->GetEmailAddress()<<"\t"<<myInstructor->GetEmployeeID()<<endl<<endl;
/*
    //Proof Student works.
    Student* myStudent1 = new Student("Greg", "Greg@gmail.com", "1316");
    cout<<myStudent1->GetName()<<"\t"<<myStudent1->GetEmailAddress()<<"\t"<<myStudent1->GetStudentID()<<endl;

    Student* myStudent2 = new Student("Harvey", "myStudent2@gmail.com", "2763");
    cout<<myStudent2->GetName()<<"\t"<<myStudent2->GetEmailAddress()<<"\t"<<myStudent2->GetStudentID()<<endl;

    Student* myStudent3 = new Student("Steve", "Steve@gmail.com", "8172");
    cout<<myStudent3->GetName()<<"\t"<<myStudent3->GetEmailAddress()<<"\t"<<myStudent3->GetStudentID()<<endl<<endl;

    //Proof Course works.
    Course* myCourse = new Course("COMP 799 - Much Difficult", myInstructor);
    myCourse->AddStudent(myStudent1);
    myCourse->AddStudent(myStudent2);
    myCourse->AddStudent(myStudent3);

    int grades[3][4] = {{100, 100, 100, 100},
                      {90, 90, 90, 90},
                      {80, 80, 80, 80}};

    cout<<"Course Title: "<<myCourse->GetTitle()<<endl;
    cout<<"Instructor Name: "<<myCourse->GetInstructor()->GetName()<<endl;
    cout<<"Instructor ID: "<<myCourse->GetInstructor()->GetEmployeeID()<<endl;
    int currIndex = 0;

    //Loop through all students in the course, assign them grades, compute their average, and print them out.
    for(Student* currStudent : myCourse->GetStudents()){
        for(int i = 0; i < 4; i++){
            currStudent->AddGrade(grades[currIndex][i]);
        }
        currStudent->ComputeAverage();
        cout<<currStudent->GetName()<<"'s average is "<<currStudent->GetAverage()<<endl;
        currIndex++;
    }
*/

}
