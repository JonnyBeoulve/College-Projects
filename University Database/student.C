#ifndef STUDENT_C
#define STUDENT_C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "student.h"
#include "course.h"
using namespace std;

long Student::nextStId = 500; //set base value

Student::Student(): Person()
{
  id = 0;
  yearOfStudy = 0;
  major = "Unknown";
  advisorId = 0;

  nextStId++; //increment Student ID after each constructor
}

Student::~Student()
{
}

Student::Student(string personName, string personEmail, string personAddress, string personDOB, string personGender, int personYOS, string personMajor, long personAdvId):Person(personName, personEmail, personAddress, personDOB, personGender)
{
  id = nextStId; //set to current nextStId value
  yearOfStudy = personYOS;
  major = personMajor;
  advisorId = personAdvId;

  nextStId++; //increment Student ID after each constructor
}

void Student::Print() const
{
  cout << "Student ID: " << id << endl;
  cout << "Student Name: " << Person::name << endl;
  cout << "Student E-Mail: " << Person::email << endl;
  cout << "Student Address: " << Person::address << endl;
  cout << "Student DOB: " << Person::dateOfBirth << endl;
  cout << "Student Gender: " << Person::gender << endl;
  cout << "Student Year of Study: " << yearOfStudy << endl;
  cout << "Student Major: " << major << endl;
  cout << "Student Advisor ID: " << advisorId << endl;

  for(int i = 0; i < coursesTaken.size(); i++) //print vector
    {
      coursesTaken[i].Print();
    }
}

#endif
