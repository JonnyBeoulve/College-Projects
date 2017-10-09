#ifndef PERSON_C
#define PERSON_C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "person.h"
using namespace std;

Person::Person()
{
  name = "Unknown";
  email = "Unknown";
  address = "Unknown";
  dateOfBirth = "Unknown";
  gender = "Unknown";
}

Person::~Person()
{
}

Person::Person(string personName, string personEmail, string personAddress, string personDOB, string personGender)
{
  name = personName;
  email = personEmail;
  address = personAddress;
  dateOfBirth = personDOB;
  gender = personGender;
}

#endif
