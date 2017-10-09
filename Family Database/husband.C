#ifndef HUSBAND_C
#define HUSBAND_C

#include "husband.h"
using namespace std;

Husband::Husband(long SSN, string firstName, string lastName) : Person(SSN, firstName, lastName)
{
  nextFamily = NULL;
  myWife = NULL;
}

Husband* Husband::GetNextFamily()
{
  return nextFamily;
}

void Husband::SetNextFamily(Husband* node)
{
  nextFamily = node;
}

Wife* Husband::GetMyWife()
{
  return myWife;
}

void Husband::SetMyWife(Wife* node )
{
  myWife = node;
}

#endif

