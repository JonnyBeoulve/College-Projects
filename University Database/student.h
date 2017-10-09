#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "course.h"
#include "person.h"
using namespace std;

class Student: public Person
{
  friend class University;

 protected:
  long id;
  int yearOfStudy;
  string major;
  long advisorId;
  vector<Course> coursesTaken;
  static long nextStId;

 public:
  Student();
  ~Student();
  Student(string personName, string personEmail, string personAddress, string personDOB, string personGender, int personYOS, string personMajor, long personAdvId);
  void Print() const;
};

#endif
