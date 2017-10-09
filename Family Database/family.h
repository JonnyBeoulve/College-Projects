#ifndef FAMILY_H
#define FAMILY_H

#include <string>
#include <iostream>
#include "husband.h"
#include "wife.h"
#include "child.h"
using namespace std;

class Husband;
class Wife;
class Child;

class Family
{
 protected:
  Husband* top;
  
 public:
  Family();
  void AddHusband(long SSN, string Fname, string Lname);
  void RemoveHusband(long SSN);
  void AddWife(long SSN, string Fname, string Lname, long husbandSSN);
  void RemoveWife(long husbandSSN);
  void AddAChild(long SSN, string Fname, string Lname, long fatherSSN);
  void RemoveAChild(long FatherSSN, long childSSN);
  void PrintAFamily(long fatherSSN);
  void PrintAllFamilies();
  void ReadTransactionFile();

  Husband* LocateHusband(long SSN);
  Child* LocateChild(long childSSN, long fatherSSN);
  bool LocateSSN(long SSN);
};

#endif
