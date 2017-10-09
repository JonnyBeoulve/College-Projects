#ifndef CHILD_H
#define CHILD_H

#include "person.h"
#include "family.h"
using namespace std;

class Child : public Person
{
  friend class Family;
  
 private:
  Child* mySibling;
  
 public:
  Child(long SSN, string firstName, string lastName);
  Child* GetMySibling();
  void SetMySibling(Child* node);
};

#endif
