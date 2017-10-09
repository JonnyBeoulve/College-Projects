#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "course.h"
#include "department.h"
#include "faculty.h"
#include "person.h"
#include "student.h"
using namespace std;

class University
{
 protected:
  vector<Department> Departments;
  vector<Student> Students;
  vector<Course> Courses;
  vector<Faculty> Faculties;
  static bool failure;
  static bool success;

 public:
  University();
  ~University();

  //validation functions  
  bool DepartmentValidation(long departmentId);
  bool ChairValidation(long chairId);
  bool MajorValidation(string major);
  bool AdvisorValidation(long advisorId);
  bool StudentValidation(long stuId);
  bool StudentSpaceValidation(long courseId);
  bool CourseIdValidation(long courseId);
  bool StudentIdValidation(long stId);

  //database manipulation functions
  bool CreateNewDepartment(string depName, string depLoc, long depChairId);
  bool CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId);
  bool CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat);
  bool CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId);
  bool ListCoursesTaughtByFaculty(long facultyId);
  bool ListCoursesTakenByStudent(long studentId);
  bool ListFacultiesInDepartment (long departId);
  bool ListStudentsOfAFaculty(long facultyId);
  bool ListCoursesOfADepartment(long departId);
  bool AddACourseForAStudent(long courseId, long stId);
  bool DropACourseForAStudent(long courseId, long stId);
  bool AssignDepartmentChair(long facultyId, long departId);
  bool AssignInstructorToCourse (long facultyId, long courseId);
 
  //output functions
  bool ListDepartments();
  bool ListStudents();
  bool ListCourses();
  bool ListFaculties();
 
  //file execution/input function
  bool ProcessTransactionFile(string fileName);
};

#endif
