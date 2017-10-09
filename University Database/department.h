#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Department
{
  friend class University;

 protected:
  long id;
  string name;
  string location;
  long chairId;
  static long nextDepartId;

 public:
  Department();
  ~Department();
  Department(string deptName, string loc, long deptChairId);
  void Print() const;
};

#endif
