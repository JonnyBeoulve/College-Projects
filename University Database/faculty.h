#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "person.h"
using namespace std;

class Faculty: public Person
{
  friend class University;

 protected:
  long id;
  float salary;
  int yearOfExp;
  long departId;
  static long nextFacultyId;

 public:
  Faculty();
  ~Faculty();
  Faculty(string personName, string personEmail, string personAddress, string personDOB, string personGender, float personSalary, int personExp, long personDeptId);
  void Print() const;
};

#endif
