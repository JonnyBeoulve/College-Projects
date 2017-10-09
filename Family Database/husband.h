#ifndef HUSBAND_H
#define HUSBAND_H

#include "person.h"
#include "wife.h"
#include "family.h"
using namespace std;

class Wife;

class Husband : public Person
{
  friend class Family;

private:
  Husband* nextFamily;
  Wife* myWife;
  
public:
  Husband(long SSN, string firstName, string lastName);
  Husband * GetNextFamily();
  void SetNextFamily(Husband* node);
  Wife* GetMyWife();
  void SetMyWife(Wife* node);
};

#endif
