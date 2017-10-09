#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

class Course
{
  friend class University;

 protected: 
  long CRN;
  int maxAvailableSeats;
  string name;
  long departId;
  long assignedSeats;
  long isTaughtBy;
  static long nextCRN;

 public:
  Course();
  ~Course();
  Course(string cName, long deptId, long taught, int seats);
  void Print() const;
};

#endif
