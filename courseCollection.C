/*******************************
Jonathan Leack
*******************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

//declare classes
class Course
{
  public:
  long CourseNum;
  string CourseName;
};

class Person
{
  public:
  long SSN;
  string Fname;
  string Lname;
  int Age;
  char Gender;
};

class Student
{
  public:
  long StNo;
  Course Course1;
  Course Course2;
  Course Course3;
};

class StudentProfile
{
  public:
  Person PersonalInfo;
  Student StdInfo;
};

//declare functions
void createCollection(vector<StudentProfile>& StCollection, int& count);
void printCollection(const vector<StudentProfile>& StCollection, int& count);

//main
int main()
{
  vector<StudentProfile> StCollection;
  int count = 0;  

  createCollection(StCollection,count);
  printCollection(StCollection,count);
}

//move collections from data.txt to vector
void createCollection(vector<StudentProfile>& StCollection, int& count)
{
  StudentProfile new_entry; 

  ifstream fin;
  fin.open("data.txt");

  while(!fin.eof()) 
    {    
      fin >> new_entry.PersonalInfo.SSN >> new_entry.PersonalInfo.Fname >> new_entry.PersonalInfo.Lname >> new_entry.PersonalInfo.Age >> new_entry.PersonalInfo.Gender >> new_entry.StdInfo.StNo >> new_entry.StdInfo.Course1.CourseNum;
      fin >> new_entry.StdInfo.Course1.CourseName >> new_entry.StdInfo.Course2.CourseNum >> new_entry.StdInfo.Course2.CourseName >> new_entry.StdInfo.Course3.CourseNum >> new_entry.StdInfo.Course3.CourseName;
      StCollection.push_back(new_entry);
      count++;    
    }

  fin.close();
}

//print collections in vector
void printCollection(const vector<StudentProfile>& StCollection, int& count)
{
  for(int i = 0; i < count; i++)
    {
      cout << endl;
      cout << "SSN: " << StCollection[i].PersonalInfo.SSN << endl;
      cout << "FName: " << StCollection[i].PersonalInfo.Fname << endl;
      cout << "LName: " << StCollection[i].PersonalInfo.Lname << endl;
      cout << "Age: " << StCollection[i].PersonalInfo.Age << endl;
      cout << "Gender: " << StCollection[i].PersonalInfo.Gender << endl;
      cout << "StNo: " << StCollection[i].StdInfo.StNo << endl;
      cout << "CourseNum: " << StCollection[i].StdInfo.Course1.CourseNum << endl;
      cout << "CourseName: " << StCollection[i].StdInfo.Course1.CourseName << endl;
      cout << "CourseNum: " << StCollection[i].StdInfo.Course2.CourseNum << endl;
      cout << "CourseName: " << StCollection[i].StdInfo.Course2.CourseName << endl;
      cout << "CourseNum: " << StCollection[i].StdInfo.Course3.CourseNum << endl;
      cout << "CourseName: " << StCollection[i].StdInfo.Course3.CourseName << endl;
      cout << endl;
    }
}
