/************************
Name: Jonathan Leack

Description: This program creates and implements a database for a university. The university
has Courses, Departments, Faculty, and Students. These are divided into five classes.
The program takes a transaction file and executes commands, of which there are 17 different
types. These commands allow the user to create objects and mesh them in a variety of ways.
Output functions are also available to view the data.
************************/
#ifndef DRIVER_C
#define DRIVER_C

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include "university.h"
using namespace std;

int main()
{
  University csusm;
  csusm.ProcessTransactionFile("TransactionFile.txt");

  return 0;
}

#endif
