#include <iostream>
#include "Course.hpp"

int main(){

	//Proof Instructor works.
	Instructor* myInstructor = new Instructor("Tom", "Tom@gmail.com", "12376");
	std::cout<<myInstructor->GetName()<<"\t"<<myInstructor->GetEmailAddress()<<"\t"<<myInstructor->GetEmployeeID()<<std::endl<<std::endl;

	//Proof Student works.
	Student* myStudent1 = new Student("Greg", "Greg@gmail.com", "1316");
	std::cout<<myStudent1->GetName()<<"\t"<<myStudent1->GetEmailAddress()<<"\t"<<myStudent1->GetStudentID()<<std::endl;

	Student* myStudent2 = new Student("Harvey", "myStudent2@gmail.com", "2763");
	std::cout<<myStudent2->GetName()<<"\t"<<myStudent2->GetEmailAddress()<<"\t"<<myStudent2->GetStudentID()<<std::endl;

	Student* myStudent3 = new Student("Steve", "Steve@gmail.com", "8172");
	std::cout<<myStudent3->GetName()<<"\t"<<myStudent3->GetEmailAddress()<<"\t"<<myStudent3->GetStudentID()<<std::endl<<std::endl;

	//Proof Course works.
	Course* myCourse = new Course("COMP 799 - Much Difficult", myInstructor);
	myCourse->AddStudent(myStudent1);
	myCourse->AddStudent(myStudent2);
	myCourse->AddStudent(myStudent3);

	int grades[3][4] = {{100, 100, 100, 100},
					  {90, 90, 90, 90},
					  {80, 80, 80, 80}};

	std::cout<<"Course Title: "<<myCourse->GetTitle()<<std::endl;
	std::cout<<"Instructor Name: "<<myCourse->GetInstructor()->GetName()<<std::endl;
	std::cout<<"Instructor ID: "<<myCourse->GetInstructor()->GetEmployeeID()<<std::endl;
	int currIndex = 0;

	//Loop through all students in the course, assign them grades, compute their average, and print them out.
	for(Student* currStudent : myCourse->GetStudents()){
		for(int i = 0; i < 4; i++){
			currStudent->AddGrade(grades[currIndex][i]);
		}
		currStudent->ComputeAverage();
		std::cout<<currStudent->GetName()<<"'s average is "<<currStudent->GetAverage()<<std::endl;
		currIndex++;
	}

}