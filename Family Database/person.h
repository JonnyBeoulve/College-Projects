#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
 protected:
  long SSN;
  string firstName;
  string lastName;
  
 public:
  Person(long ssn, string fname, string lname);
  ~Person();
  void SetSSN(long ssn);
  long GetSSN() const;
  void SetFirstName (string fname);
  string GetFirstName();
  void SetLastName (string lname);
  string GetLastName();
};

#endif
