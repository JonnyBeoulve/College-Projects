#ifndef PERSON_C
#define PERSON_C

#include <iostream>
#include <string>
#include "person.h"
using namespace std;

Person::Person(long ssn, string fname, string lname)
{
  SSN = ssn;
  firstName = fname;
  lastName = lname;
}

Person::~Person()
{
}

void Person::SetSSN(long ssn)
{
  SSN = ssn;
}

long Person::GetSSN() const
{
  return SSN;
}

void Person::SetFirstName(string fname)
{
  firstName = fname;
}

string Person::GetFirstName()
{
  return firstName;
}

void Person::SetLastName(string lname)
{
  lastName = lname;
}

string Person::GetLastName()
{
  return lastName;
}

#endif
