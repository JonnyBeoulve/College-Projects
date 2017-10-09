/*************************************
Name: Jonathan Leack

Description: In this program the user is able to create and manipulate
a database constructed of families consisting of one husband, an optional
wife, and optional children. The user can add any of these, remove them,
and print the contents of the database. The database is fully constructed
using Linked List allowing for dynamic manipulation.
************************************/
#include "family.h"
using namespace std;

int main()
{
  Family USAFamilies;
  USAFamilies.ReadTransactionFile();
 
  return 0;
}
