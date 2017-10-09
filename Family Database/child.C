#ifndef CHILD_C
#define CHILD_C

#include "person.h"
#include "child.h"
using namespace std;

Child::Child(long SSN, string firstName, string lastName) : Person(SSN, firstName, lastName)
{
  mySibling = NULL;
}

Child* Child::GetMySibling()
{
  return mySibling;
}

void Child::SetMySibling(Child* node)
{
  mySibling = node;
}

#endif
