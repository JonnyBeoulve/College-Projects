#ifndef DEPARTMENT_C
#define DEPARTMENT_C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "department.h"
using namespace std;

long Department::nextDepartId = 100; //initialize base depart ID value

Department::Department()
{
  id = 0;
  name = "Unknown";
  location = "Unknown";
  chairId = 0;

  nextDepartId++; //increment Department ID after each constructor
}

Department::~Department()
{
}

Department::Department(string deptName, string loc, long deptChairId)
{
  id = nextDepartId; //set value to current nextDepartId value
  name = deptName;
  location = loc;
  chairId = deptChairId;

  nextDepartId++; //increment Department ID after each constructor
}

void Department::Print() const
{
  cout << "Department ID: " << id << endl;
  cout << "Department Name: " << name << endl;
  cout << "Department Location: " << location << endl;
  cout << "Department Chair ID: " << chairId << endl;
}

#endif

