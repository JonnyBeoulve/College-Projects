#ifndef WIFE_C
#define WIFE_C

#include "wife.h"
using namespace std;

Wife::Wife(long SSN, string firstName, string lastName) : Person(SSN, firstName, lastName)
{
  myChildren = NULL;
}

Child* Wife::GetMyChildren()
{
  return myChildren;
}

void Wife::SetMyChildren(Child* node)
{
  myChildren = node;
}

#endif
