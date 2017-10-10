/*****************************************
Jonathan Leack
*****************************************/
#ifndef COURSE_C
#define COURSE_C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "course.h"
using namespace std;

long Course::nextCRN = 200; //set base value

Course::Course()
{
  CRN = 0;
  maxAvailableSeats = 0;
  name = "Unknown";
  departId = 0;
  assignedSeats = 0; //seats are incremented in the AddACourseForAStudent function
  isTaughtBy = 0;

  nextCRN++; //increment value after each constructor
}

Course::~Course()
{
}

Course::Course(string cName, long deptId, long taught, int seats)
{
  CRN = nextCRN; //set to current nextCRN value
  name = cName;
  departId = deptId;
  isTaughtBy = taught;
  maxAvailableSeats = seats;
  assignedSeats = 0; //seats are incremented in the AddACourseForAStudent function

  nextCRN++; //increment value after each constructor
}

void Course::Print() const
{
  cout << "CRN: " << CRN << endl;
  cout << "Max Available Seats: " << maxAvailableSeats << endl;
  cout << "Course Name: " << name << endl;
  cout << "Department ID: " << departId << endl;
  cout << "Assigned Seats: " << assignedSeats << endl;
  cout << "Taught By: " << isTaughtBy << endl;
}

#endif
