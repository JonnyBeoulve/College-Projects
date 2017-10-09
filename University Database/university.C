#ifndef UNIVERSITY_C
#define UNIVERSITY_C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "course.h"
#include "department.h"
#include "faculty.h"
#include "person.h"
#include "student.h"
#include "university.h"
using namespace std;

bool University::failure = false; //set default boolean values
bool University::success = true;

University::University()
{
}

University::~University()
{
}

bool University::ChairValidation(long chairId) //determine if Chair ID already exists
{
  for(int i = 0; i < Faculties.size(); i++)
    {
      if(Faculties[i].id == chairId)
        {
          return success;
        }
    }
  return failure;
}

bool University::MajorValidation(string major) //determine if Major already exists
{
  for (int i = 0; i < Departments.size(); i++)
    {
      if(Departments[i].name == major)
	{     
	  return success;
	}
    }
  return failure;
}

bool University::AdvisorValidation(long advisorId) //determine if Advisor already exists
{
  for(int i = 0; i < Faculties.size(); i++)
    {
      if(Faculties[i].id == advisorId)
	{
	  return success;
	}
    }
  return failure;
}

bool University::DepartmentValidation(long departmentId) //determine if Department already exists
{
  for(int i = 0; i < Departments.size(); i++)
    {
      if(Departments[i].id == departmentId)
	{
	  return success;
	}
    }
  return failure;
}

bool University::StudentValidation(long stuId) //determine if Student already exists
{
  for(int i = 0; i < Students.size(); i++)
    {
      if(Students[i].id == stuId)
        {
          return success;
        }
    }
  return failure;
}

bool University::StudentSpaceValidation(long courseId) //determine if Course has seats available for Students
{
  for(int i = 0; i < Courses.size(); i++)
    {
      if(Courses[i].CRN == courseId)
	{
	  if(Courses[i].assignedSeats < Courses[i].maxAvailableSeats)
	    {
	      return success;
	    }
	}
    }
  return failure;
}

bool University::CourseIdValidation(long courseId) //determine if Course ID already exists
{
  for(int i = 0; i < Courses.size(); i++)
    {
      if(Courses[i].CRN == courseId)
	{
	  return success;
	}
    }
  return failure;
}

bool University::StudentIdValidation(long stuId) //determine if Student ID already exists
{
  for(int i =0; i < Students.size(); i++)
    {
      if(Students[i].id == stuId)
        {
          return success;
        }
    }
  return failure;
}

bool University::CreateNewDepartment(string depName, string depLoc, long depChairId)
{
  bool validity = true;

  if(depChairId != 0) //determine if depChairId has a value
    {
      validity = ChairValidation(depChairId); //check for existence
    }

  if(validity == false) //if validation failed, print error and return failure
    {
      cout << "\nERROR: Chair ID '#" << depChairId << "' is not valid! Create New Department aborted!" << endl;
      return failure;
    }

  Department dept(depName, depLoc, depChairId); //create Department
  Departments.push_back(dept); //push Department into Departments vector

  return success;
}

bool University::CreateNewStudent(string sName, string sEmail, string sAddress, string sDateOfBirth, string sGender, int sYearOfStudy, string sMajor, long sAdvisorId)
{
  bool validMajor, validAdvisor = true;

  if(sMajor != "0") //determine if sMajor has a value
    validMajor = MajorValidation(sMajor); //check value if present
  if(sAdvisorId != 0) //determine if sAdvisorId has a value
    validAdvisor = AdvisorValidation(sAdvisorId); //check value if present

  if(validMajor == false) //if Major validation failed, print error and return failure
    {
      cout << "\nERROR: Major Name '" << sMajor << "' is not valid! Create New Student aborted!" << endl;
      return failure;
    }
  if(validAdvisor == false) //if Advisor validation failed, print error and return failure
    {
      cout << "\nERROR: Advisor ID '" << sAdvisorId << "' is not valid! Create New Student aborted!" << endl;
      return failure;
    }

  Student stu(sName, sEmail, sAddress, sDateOfBirth, sGender, sYearOfStudy, sMajor, sAdvisorId); //create Student
  Students.push_back(stu); //push Student into Students vector

  return success;
}

bool University::CreateNewCourse(string cName, long cDepId, long cTaughtBy, int cMaxSeat)
{
  bool validity = true;

  if(cTaughtBy != 0) //determine if cTaughtBy hsa a value
    {
      validity = ChairValidation(cTaughtBy); //check value if present
    }

  if(validity == false) //if Chair validation failed, print error and return failure
    {
      cout << "\nERROR: Faculty ID '#" << cTaughtBy << "' is not valid! Create New Course aborted!" << endl;
      return failure;
    }

  validity = DepartmentValidation(cDepId); //validate Department ID

  if(validity == false) //if Department validation failed, print error and return failure
    {
      cout << "\nERROR: Department ID '#" << cDepId << "' is not valid! Create New Course aborted!" << endl;
      return failure;
    }

  Course course(cName, cDepId, cTaughtBy, cMaxSeat); //create Course object
  Courses.push_back(course); //push Course into Courses vector

  return success;
}

bool University::CreateNewFaculty(string fName, string fEmail, string fAddress, string fDateOfBirth, string fGender, float fSalary, int fYearOfExp, long fDepId)
{
  bool validity = DepartmentValidation(fDepId); //determine if Faculty exists

  if(validity == false) //if Faculty validation failed, print error and return failure
    {
      cout << "\nERROR: Department ID '#" << fDepId << "' is not valid! Create New Faculty aborted!" << endl;
      return failure;
    }

  Faculty fac(fName, fEmail, fAddress, fDateOfBirth, fGender, fSalary, fYearOfExp, fDepId); //create Faculty object
  Faculties.push_back(fac); //push Faculty into Faculties vector

  return success;
}

bool University::ListCoursesTaughtByFaculty(long facultyId)
{
  bool validity = ChairValidation(facultyId); //determine if Chair exists

  if(validity == false) //if Chair validation failed, print error and return failure
    {
      cout << "\nERROR: Chair ID '#" << facultyId << "' is not valid! Course List aborted!" << endl;
      return failure;
    }

  cout << "\nCOURSES TAUGHT BY FACULTY ID '#" << facultyId << "'" << endl;
  for(int i = 0; i < Courses.size(); i++) //for all Courses
    {
      if (Courses[i].isTaughtBy == facultyId) //check if existing Faculty ID matches passed ID
	{
	  Courses[i].Print(); //print Courses once matched
	}
    }
  cout << endl;
  return success;
}

bool University::ListCoursesTakenByStudent(long studentId)
{
  bool validity = StudentValidation(studentId); //determine if Student exists

  if(validity == false) //if Student validation failed, print error and return failure
    {
      cout << "\nERROR: Student ID '#" << studentId << "' is not valid! Course List aborted!" << endl;
      return failure;
    }

  cout << "\nCOURSES TAKEN BY STUDENT ID '#" << studentId << "'" << endl;
  for(int i = 0; i < Students.size(); i++) //for all Students
    {
      if(Students[i].id == studentId) //check if existing ID matches passed ID
	{
	  for(int k = 0; k < Students[i].coursesTaken.size(); k++)
	    {
	      Students[i].coursesTaken[k].Print(); //print Courses Taken once matched
	    }
	}
    }
  cout << endl;
  return success;
}

bool University::ListFacultiesInDepartment (long departId)
{
  bool validity = DepartmentValidation(departId); //determine if Department exists

  if(validity == false) //if Department validation failed, print error and return false
    {
      cout << "\nERROR: Department ID '#" << departId << "' is not valid! Faculty List aborted!" << endl;
      return failure;
    }

  cout << "\nFACULTIES IN DEPARTMENT ID '#" << departId << "'" << endl;
  for(int i = 0; i < Faculties.size(); i++) //for all Faculty
    {
      if(Faculties[i].departId == departId) //check if existing Department ID matches passed ID
	{
	  Faculties[i].Print(); //print Faculty
	}
    }
  cout << endl;
  return success;
}

bool University::ListStudentsOfAFaculty(long facultyId)
{
  bool validity = ChairValidation(facultyId); //determine if Faculty exists

  if(validity == false) //if Chair validation failed, print error and return false
    {
      cout << "\nERROR: Faculty ID '#" << facultyId << "' is not valid! Student List aborted!" << endl;
      return failure;
    }

  cout << "\nSTUDENTS OF FACULTY ID '#" << facultyId << "'" << endl;
  for(int i = 0; i < Students.size(); i++) //for all Students
    {
      if(Students[i].advisorId == facultyId) //check if Advisor ID matches passed ID
	{
	  Students[i].Print(); //print Student
	}
    }
  cout << endl;
  return success;
}

bool University::ListCoursesOfADepartment(long departId)
{
  bool validity = DepartmentValidation(departId); //determine if Department exists

  if(validity == false) //if Department validation failed, print error and return false
    {
      cout << "\nERROR: Department ID '#" << departId << "' is not valid! Course List aborted!" << endl;
      return failure;
    }

  cout << "\nCOURSES OF DEPARTMENT '#" << departId << "'" << endl;
  for(int i = 0; i < Courses.size(); i++) //for all Courses
    {
      if(Courses[i].departId == departId) //check if existing Department ID matches passed ID
        {
	  Courses[i].Print(); //print Courses
        }
    }
  cout << endl;
  return success;
}

bool University::AddACourseForAStudent(long courseId, long stId)
{
  bool studentSpaceValidity = StudentSpaceValidation(courseId); //determine if there's space for Student
  bool courseIdValidity = CourseIdValidation(courseId); //determine if Course Id is valid
  bool stuIdValidity = StudentIdValidation(stId); //determine if Student Id is valid

  if(studentSpaceValidity == false) //if Space validation failed, print error and return false
    {
      cout << "\nERROR: There is no space available for Student ID #" << stId << "! Add Course aborted!" << endl;
      return failure;
    }

  if(courseIdValidity == false) //if Course ID validation failed, print error and return false
    {
      cout << "\nERROR: Course ID #" << courseId << " is not valid! Add Course aborted!" << endl;
      return failure;
    }

  if(stuIdValidity == false) //if Student ID validation failed, print error and return false
    {
      cout << "\nERROR: Student ID ##" << stId << "is not valid! Add Course aborted!" << endl;
      return failure;
    }

  Course newCourse; //create a new course object

  for(int i = 0; i < Courses.size(); i++) //for all Courses
    {
      if(Courses[i].CRN == courseId) //if CRN matches the passed ID
	{
	  Courses[i].assignedSeats++; //increment seat number
	  newCourse = Courses[i]; //duplicate matched Course
	} 
    }

  for(int k = 0; k < Students.size(); k++) //for all Students
    {
      if(Students[k].id == stId) //if ID matches passed ID
	{
	  Students[k].coursesTaken.push_back(newCourse); //push created object into Student Vector
	  return success;
	}
    }
  return failure;
}

bool University::DropACourseForAStudent(long courseId, long stId)
{
  bool courseIdValidity = CourseIdValidation(courseId); //determine if Course Id is valid
  bool stuIdValidity = StudentIdValidation(stId); //determine if Student Id is valid

  if(courseIdValidity == false) //if Course ID validation failed, print error and return false
    {
      cout << "\nERROR: Course ID '#" << courseId << "' is not valid! Drop Course aborted!" << endl;
      return failure;
    }

  if(stuIdValidity == false) //if Student ID validation failed, print error and return false
    {
      cout << "\nERROR: Student ID '#" << stId << "' is not valid! Drop Course aborted!" << endl;
      return failure;
    }

  for(int i = 0; i < Courses.size(); i++) //for all Courses
    {
      if(Courses[i].CRN == courseId) //if CRN matches passed Course ID
	{
	  Courses[i].assignedSeats--; //decrement value of Assigned Seats
	}
    }

  for(int k = 0; k < Students.size(); k++) //for all Students
    {
      if(Students[k].id == stId) //if ID matches passed Student ID
	{
	  for(int m = 0; m < Students[k].coursesTaken.size(); m++) //for all Courses Taken
	    {
	      if(Students[k].coursesTaken[m].CRN == courseId) //if CRN matches passed Course ID
		{
		  Students[k].coursesTaken.erase(Students[k].coursesTaken.begin() + m); //drop Student from Course
		  return success;
		}
	    }
	}
    }
  return failure;;
}

bool University::AssignDepartmentChair(long facultyId, long departId)
{
  bool chairValidity = ChairValidation(facultyId); //check validity of Faculty ID
  bool departmentValidity = DepartmentValidation(departId); //check validity of Department ID
 
  if(chairValidity == false) //if Chair validation failed, print error and return false
    {
      cout << "\nERROR: Faculty ID '#" << facultyId << "' is not valid! Assign Department Chair aborted!" << endl;
      return failure;
    }

  if(departmentValidity == false) //if Department validation failed, print error and return false
    {
      cout << "\nERROR: Department ID '#" << departId << "' is not valid! Assign Department Chair aborted!" << endl;
      return failure;
    }
    
  for(int i = 0; i < Departments.size(); i++) //for all Departments
    {
      if(Departments[i].id == departId) //if ID matches passed ID
	{ 
	  Departments[i].chairId = facultyId; //assign Chair ID to passed Faculty ID
	  return success;
	}
    }
  return failure;
}

bool University::AssignInstructorToCourse (long facultyId, long courseId)
{
  bool chairValidity = ChairValidation(facultyId); //check validity of Faculty ID
  bool courseIdValidity = CourseIdValidation(courseId); //check validity of Course ID

  if(chairValidity == false) //if Chair validation failed, print error and return false
    {
      cout << "\nERROR: Faculty ID '#" << facultyId << "' is not valid! Assign Instructor to Course aborted!" << endl;
      return failure;
    }

  if(courseIdValidity == false) //if Course ID validation failed, print error and return false
    {
      cout << "\nERROR: Course ID '#" << courseId << "' is not valid! Assign Instructor to Course aborted!" << endl;
      return failure;
    }

  for(int i = 0; i < Courses.size(); i++) //for all Courses
    {
      if(Courses[i].CRN == courseId) //if CRN matches passed Course ID
	{
	  Courses[i].isTaughtBy = facultyId; //set Faculty to passed Faculty ID
	}
    }

  for(int k = 0; k < Students.size(); k++) //for all Students
    {
      for(int m = 0; m < Students[k].coursesTaken.size(); m++) //for all Courses Taken
	{
	  if(Students[k].coursesTaken[m].CRN == courseId) //if CRN matches pased Course ID
	    {
	      Students[k].coursesTaken[m].isTaughtBy = facultyId; //set Taught By to passed Faculty ID
	    }
	}
    }
  return success;
}

bool University::ListDepartments()
{
  cout << "\nDEPARTMENT LIST" << endl; //header
  for (int i = 0; i < Departments.size(); i++) //print the ID and Name of all Departments
    {
      cout << "Department ID: " << Departments[i].id << endl;
      cout << "Department Name: " << Departments[i].name << endl;
    }
  cout << endl;
}

bool University::ListStudents()
{
  cout << "\nSTUDENT LIST" << endl; //header
  for (int i = 0; i < Students.size(); i++) //print the ID and Name of all Students
    {
      cout << "Student ID: " << Students[i].id << endl;
      cout << "Student Name: " << Students[i].name << endl;
    }
  cout << endl;
}

bool University::ListCourses()
{
  cout << "\nCOURSE LIST" << endl; //header
  for (int i = 0; i < Courses.size(); i++) //print the CRN and Name of all Courses
    {
      cout << "Course ID: " << Courses[i].CRN << endl;
      cout << "Course Name: " << Courses[i].name << endl;
    }
  cout << endl;
}

bool University::ListFaculties()
{
  cout << "\nFACULTY LIST" << endl; //header
  for (int i = 0; i < Faculties.size(); i++) //print the ID and Name of all Faculty
    {    
      cout << "Faculty ID: " << Faculties[i].id << endl;
      cout << "Faculty Name: " << Faculties[i].name << endl;
    }
  cout << endl;
}

bool University::ProcessTransactionFile(string fileName)
{
  string transFile; //user's entered file name
  string command; //command in transaction file (left column)
  string depName, depLoc, name, email, address, dateOfBirth, gender, major; //string values
  long depChairId, depId, advisorId, stId, taughtBy, CRN, facId, courseId; //long values
  int yearOfStudy, maxSeats, yearOfExp; //int values
  float salary; //float value

  ifstream fin;
  fin.open(fileName.data());

  if(!fin) //if file doesn't exist, print error and return failure
    {
      cout << "ERROR: The transaction file with filename '" << fileName << "' does not exist!" << endl;
      return failure;
    }
  else //if file exists, display success dialog
    {
      cout << "======= File with filename '" << fileName << "' successfully opened! =======" << endl;
    }

  while(fin >> command) //read commands from file and execute them accordingly
    {
      if (command == "CreateNewDepartment")
	{
	  fin >> depName >> depLoc >> depChairId;
	  CreateNewDepartment(depName, depLoc, depChairId);
	}
      else if (command == "CreateNewCourse")
        {
          fin >> name >> depId >> taughtBy >> maxSeats;
          CreateNewCourse(name, depId, taughtBy, maxSeats);
        }
      else if (command == "CreateNewStudent")
	{
	  fin >> name >> email >> address >> dateOfBirth >> gender >> yearOfStudy >> major >> advisorId;
	  CreateNewStudent(name, email, address, dateOfBirth, gender, yearOfStudy, major, advisorId);
	}
      else if (command == "CreateNewFaculty")
	{
	  fin >> name >> email >> address >> dateOfBirth >> gender >> salary >> yearOfExp >> depId;
	  CreateNewFaculty(name, email, address, dateOfBirth, gender, salary, yearOfExp, depId);
	}
      else if (command == "ListCoursesTaughtByFaculty")
	{
	  fin >> facId;
	  ListCoursesTaughtByFaculty(facId);
	}
      else if (command == "ListCoursesTakenByStudent")
	{
	  fin >> stId;
	  ListCoursesTakenByStudent(stId);
	}
      else if (command == "ListFacultiesInDepartment")
	{
	  fin >> depId;
	  ListFacultiesInDepartment(depId);
	}
      else if (command == "ListStudentsOfAFaculty")
	{
	  fin >> facId;
	  ListStudentsOfAFaculty(facId);
	}
      else if (command == "ListCoursesOfADepartment")
	{
	  fin >> depId;
	  ListCoursesOfADepartment(depId);
	}
      else if (command == "AddACourseForAStudent")
	{
	  fin >> courseId >> stId;
	  AddACourseForAStudent(courseId, stId);
	}
      else if (command == "DropACourseForAStudent")
	{
	  fin >> courseId >> stId;
	  DropACourseForAStudent(courseId, stId);
	}
      else if (command == "AssignDepartmentChair")
	{
	  fin >> facId >> depId;
	  AssignDepartmentChair(facId, depId);
	}
      else if (command == "AssignInstructorToCourse")
	{
	  fin >> facId >> courseId;
	  AssignInstructorToCourse(facId, courseId);
	}
      else if (command == "ListDepartments")
	{
	  ListDepartments();
	}
      else if (command == "ListStudents")
	{
	  ListStudents();
	}
      else if (command == "ListCourses")
	{
	  ListCourses();
	}
      else if (command == "ListFaculties")
	{
	  ListFaculties();
	}
    }
  fin.close();
  cout << "======= Execution of file '" << fileName << "' has completed! =======" << endl;
  return success;
}
  
#endif
