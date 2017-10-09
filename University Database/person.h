#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Person
{
  friend class University;

 protected:
  string name;
  string email;
  string address;
  string dateOfBirth;
  string gender;

 public:
  Person();
  ~Person();
  Person(string personName, string personEmail, string personAddress, string personDOB, string personGender);
};

#endif
