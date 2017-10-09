#ifndef FACULTY_C
#define FACULTY_C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "faculty.h"
using namespace std;

long Faculty::nextFacultyId = 600; //set base value

Faculty::Faculty(): Person()
{
  id = 0;
  salary = 0.0;
  yearOfExp = 0;
  departId = 0;

  nextFacultyId++; //increment to next number
}

Faculty::~Faculty()
{
}

Faculty::Faculty(string personName, string personEmail, string personAddress, string personDOB, string personGender, float personSalary, int personExp, long personDeptId): Person(personName, personEmail, personAddress, personDOB, personGender)
{
  id = nextFacultyId; //set to current nextFacultyId value
  salary = personSalary;
  yearOfExp = personExp;
  departId = personDeptId;

  nextFacultyId++; //increment to next number
}

void Faculty::Print() const
{
  cout << "Faculty ID: " << id << endl;
  cout << "Faculty Name: " << Person::name << endl;
  cout << "Faculty E-mail: " << Person::email << endl;
  cout << "Faculty Address: " << Person::address << endl;
  cout << "Faculty DOB: " << Person::dateOfBirth << endl;
  cout << "Faculty Gender: " << Person::gender << endl;
  cout << "Faculty Salary: " << salary << endl;
  cout << "Faculty Years of Exp: " << yearOfExp << endl;
  cout << "Faculty Dept. ID: " << departId << endl;
}

#endif
