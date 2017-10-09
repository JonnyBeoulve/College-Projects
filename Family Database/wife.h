#ifndef WIFE_H
#define WIFE_H

#include "person.h"
#include "family.h"
#include "child.h"
using namespace std;

class Child;

class Wife : public Person
{
  friend class Family;

private:
  Child* myChildren;

public:
  Wife(long SSN, string firstName, string lastName);
  Child* GetMyChildren();
  void SetMyChildren(Child* node);
};

#endif
