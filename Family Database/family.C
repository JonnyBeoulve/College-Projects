#ifndef FAMILY_C
#define FAMILY_C

#include <fstream>
#include <string>
#include "family.h"
using namespace std;

Family::Family()
{
  top = NULL; //construct and set top to null
}

void Family::AddHusband(long SSN, string Fname, string Lname)
{
  if(top == NULL) //if no nodes available, create first one and insert data
    {
      top = new Husband(SSN, Fname, Lname);
      cout << "Husband successfully added to database.\n\n";
      return;
    }
  
  Husband* p = top; //create pointer at top

  while(p -> GetNextFamily() != NULL) //move pointer to end of nodes
    {
      p = p -> GetNextFamily();
    }

  Husband* q = new Husband(SSN, Fname, Lname); //create node
  p -> SetNextFamily(q); //move node into family
  cout << "Husband successfully added to database.\n\n";
}

void Family::RemoveHusband(long SSN)
{
  Husband * p = top; //create two pointers
  Husband * q = top;

  if(LocateHusband(SSN) == NULL) //if husband doesn't exist, cancel operation
    {
      cout << "ERROR: No husband with SSN #" << SSN << " exists in the database. Canceling remove husband operation.\n\n";
      return;
    }
    
  if(p -> GetNextFamily() == NULL) //if only one node exists, delete top
    {
      top = top -> GetNextFamily();
      delete p;
      cout << "Husband successfully added to database.\n\n";
      return;
    }
  
  if(p -> GetSSN() == SSN) //delete if ssn matches
    {
      q = top;
      p = top -> GetNextFamily();
      top = p;
      delete q;
      cout << "Husband successfully added to database.\n\n";
      return;
    }

  while(p -> GetSSN() != SSN) //loop until matched
    {
      q = p;
      p = p -> GetNextFamily();
    }
  
  if(p -> GetMyWife() != NULL) //remove wife before successful husband removal
    {
      Wife* w = p -> GetMyWife();
      RemoveWife(w -> GetSSN());
    }
  
  q -> SetNextFamily(p -> GetNextFamily()); //move pointer before husband removal
  delete p;
  cout << "Husband successfully removed from database.\n\n";
  return;
}

void Family::AddWife(long SSN, string Fname, string Lname, long husbandSSN)
{
  Husband* p = LocateHusband(husbandSSN); //create pointer and point to husband
  
  if(p == NULL) //if husband doesn't exist, cancel operation
    {
      cout << "ERROR: No husband with SSN #" << husbandSSN << " exists in the database. Canceling add wife operation.\n\n";
      return;
    }
  
  if (p -> GetMyWife() != NULL) //if husband already has a wife (only 1 allowed), cancel operation
    {
      cout << "ERROR: Husband already has a wife. Canceling add wife operation.\n\n";
      return;
    }
  
  Wife* q = new Wife(SSN, Fname, Lname); //create wife node
  p -> SetMyWife(q); //push wife node into family
  cout << "Wife successfully added to database.\n\n";
}

void Family::RemoveWife(long husbandSSN)
{
  Husband* p = LocateHusband(husbandSSN); //create pointer and point to husband of wife
  
  if(p == NULL) //if no match, cancel operation
    {
      cout << "ERROR: No husband with SSN #" << husbandSSN << " exists in the database. Canceling remove wife operation.\n\n";
      return;
    }
  
  Wife* q = p -> GetMyWife(); //create pointer at location
  
  if(q == NULL) //if husband ssn doesn't match a wife, cancel operation
    {
      cout << "ERROR: Person with SSN #" << husbandSSN << " has no wife. Canceling remove wife operation.\n\n";
      return;
    }
  
  bool child = true; //bool for determining if a child or more exists for family
  
  if(q -> GetMyChildren() == NULL)
    {
      child = false;
    }
  
  while(child = true) //
    {
      Child* r = q -> GetMyChildren(); //create pointer at children location
   
      while(r -> GetMySibling() != NULL) //loop until match
        {
	  r = r -> GetMySibling();
        }

      long childSSN = r -> GetSSN(); //create long with child's ssn

      RemoveAChild(husbandSSN, childSSN); //remove child before wife deletion

      if(q -> GetMyChildren() == NULL) //if no child present
        {
	  child = false;
	}
    }
  
  delete q; //remove wife and set location to null
  p -> SetMyWife(NULL);
  cout << "Wife successfully removed from database.\n\n";
}

void Family::AddAChild(long SSN, string Fname, string Lname, long fatherSSN)
{
  Husband* p = LocateHusband(fatherSSN); //create pointer and point to husband  

  if(p == NULL) //if father doesn't exist, cancel operation
    {
      cout << "ERROR: No father with SSN #" << SSN << " exists in the database. Canceling add child operation.\n\n";
      return;
    }

  Wife* q = p -> GetMyWife(); //create pointer to wife of husband
  
  if(q == NULL) //if wife of father isn't located, cancel operation
    {
      cout << "ERROR: Father with SSN #" << SSN << " has no wife. Canceling add child operation.\n\n";
      return;
    }
  
  Child* r = q -> GetMyChildren(); //create pointer

  if(r == NULL)
    {
      q -> SetMyChildren(new Child(SSN, Fname, Lname));

    }
  else
    {
      while(r -> GetMySibling() != NULL) //move pointer through nodes
	{
	  r = r -> GetMySibling();
	}
      Child* newChild = new Child(SSN, Fname, Lname); //make node with child's info
      r -> SetMySibling(newChild); //push node into family
      cout << "Child successfully added to database.\n\n";
    }
}

void Family::RemoveAChild(long fatherSSN, long childSSN)
{
  Husband* p = LocateHusband(fatherSSN);

  if(p == NULL )
    {
      cout << "ERROR: No father with SSN #" << fatherSSN << " exists in the database. Canceling remove child operation.\n\n";
      return;
    }

  Wife * q = p -> GetMyWife();

  if(q == NULL )
    {
      cout << "ERROR: Father with SSN #" << fatherSSN << " has no wife. Canceling remove child operation.\n\n";
      return;
    }
  
  Child* r = LocateChild(childSSN, fatherSSN);

  if(r == NULL )
    {
      cout << "ERROR: Child with SSN #" << childSSN << " does not exist. Canceling remove child operation.\n\n";
      return;
    }
    
  r = q -> GetMyChildren();

  if(r -> GetMySibling() == NULL )
    {
      delete r;
      q -> SetMyChildren(NULL);
      cout << "Child successfully removed from database.\n\n";
      return;
    }
  else if((r -> GetSSN() == childSSN) && (r -> GetMySibling() != NULL) )
    {       
      q -> SetMyChildren(r -> GetMySibling());
      delete r;
      cout << "Child successfully removed from database.\n\n";
      return;
    }
    
  Child* t = r;

  while(r -> GetMySibling() != NULL )
    {
      if(r -> GetSSN() == childSSN )
        {
	  break; 
        }
      t = r;
      r = r -> GetMySibling();
    }

  t -> SetMySibling(r -> GetMySibling());
  delete r;
  cout << "Child successfully removed from database.\n\n";
}

void Family::PrintAFamily(long fatherSSN) 
{
  if(top == NULL) //if no nodes, exit print
    {
      cout << "ERROR: Family doesn't exist in the database. Exiting print.\n";
      return;
    }

  Husband* p = LocateHusband(fatherSSN); //set pointer to appropriate husband
 
  if(p == NULL) //if locate finds no match
    {
      cout << "ERROR: A husband with SSN #" << fatherSSN << " does not exist! Canceling print.\n";
      return;
    }
  cout << "FAMILY------------------\n"; //header for readability  
  cout << "=== Husband\n"; //display husband info
  cout <<  p -> GetLastName() << ", " << p -> GetFirstName();
  cout << "\nSSN: " << p -> GetSSN() << endl;

  if(p -> GetMyWife() == NULL) //if no wife for husband, exit print
    {
      cout << "------------------------" << endl;
      return;
    }
  
  Wife* q = p -> GetMyWife(); //set new pointer to wife

  cout << "=== Wife\n"; //display wife info
  cout << q -> GetLastName() << ", " << q -> GetFirstName();
  cout << "\nSSN: " << q -> GetSSN() << endl;;
  
  if (q -> GetMyChildren() == NULL) //if family has no children, exit print
    {
      cout << "------------------------" << endl;
      return;
    }
  
  Child* r = q -> GetMyChildren(); //set new pointer to child
  
  cout << "=== Child\n"; //display child info
  cout << r -> GetLastName() << ", " << r -> GetFirstName();
  cout << "\nSSN: " << r -> GetSSN() << endl;
  
  while(r -> GetMySibling() != NULL ) //determine if other children exist in family
    {
      r = r -> GetMySibling();
      
      cout << "=== Child\n"; //display child info
      cout << r -> GetLastName() << ", " << r -> GetFirstName();
      cout << "\nSSN: " << r -> GetSSN() << endl;
    }
  cout << "------------------------" << endl;
}

void Family::PrintAllFamilies()
{
  Husband* p = top; //create pointer at top

  if(top == NULL) //if no nodes exist, exit print
    {
      cout << "ERROR:: No families are in the database. Exiting print.\n";
      return;
    }

  cout << "Printing all families...\n";
  
  while(p != NULL) //while new family is still available, print their info
    {
      PrintAFamily(p -> GetSSN());
      p = p -> GetNextFamily(); //move pointer
    }
}

Husband * Family::LocateHusband(long SSN)
{
  Husband* p = top; //create pointer at top

  while(p != NULL) //while nodes still exist
    {
      if(p -> SSN == SSN) //if husband SSN matches passed SSN
        {
	  return p; //return pointer
        }
      p = p-> GetNextFamily(); //move pointer to try next husband SSN
    }

  return NULL; //if no match, set equal to null
}

Child* Family::LocateChild(long SSN, long fatherSSN)
{
  Husband* p = top;
  while(p != NULL )
    {
      if(p -> GetSSN() == fatherSSN )
        {
	  break;
        }
      p = p -> GetNextFamily();
    }
  if(p == NULL)
    {
      return NULL;
    }

  Wife* q = p -> GetMyWife();
  
  if(q == NULL)
    {
      return NULL;
    }
  
  Child* r = q -> GetMyChildren();
  
  while(r != NULL)
    {
      if(r -> GetSSN() == SSN )
        {
	  return r;
        }
      r = r -> GetMySibling();
    }
  return NULL;
}

void Family::ReadTransactionFile()
{
  string command, fileName, fname, lname;
  long ssn, husbandssn, fatherssn;

  cout << "Please enter the full name of your transaction file: "; //user prompt
  cin >> fileName;

  ifstream fin; //open file
  fin.open(fileName.data());

  if(!fin)
    {
      cout << "\nERROR: Transaction file with name " << fileName << " could not be found! Exiting.\n\n";
      return;
    }
  else
    {
      cout << "\n========== FILE SUCCESSFULLY OPENED ==========\n\n"; 
    }

  while(fin >> command) //read transaction file and operate accordingly
    {      
      if(command == "AddHusband")
        {
	  fin >> ssn >> fname >> lname;
	  cout << "Attempting to add husband to database...\n";
	  AddHusband(ssn, fname, lname);
        }
      if(command == "RemoveHusband")
        {
	  fin >> ssn;
	  cout << "Attempting to remove husband from database...\n";
	  RemoveHusband(ssn);
	  }
      if(command == "AddWife")
        {
	  fin >> ssn >> fname >> lname >> husbandssn;
	  cout << "Attempting to add wife to database...\n";
	  AddWife(ssn, fname, lname, husbandssn);
        }
      if(command == "RemoveWife")
        {
	  fin >> husbandssn;
	  cout << "Attempting to remove wife from database...\n";
	  RemoveWife(husbandssn);
	}
      if(command == "AddAChild")
        {
	  fin >> ssn >> fname >> lname >> fatherssn;
	  cout << "Attempting to add child to database...\n";
	  AddAChild(ssn, fname, lname, fatherssn);
	}
      if(command == "RemoveAchild")
        {
	  fin >> fatherssn >> ssn;
	  cout << "Attempting to remove child from database...\n";
	  RemoveAChild(fatherssn, ssn);
	}
      if(command == "PrintAFamily")
        {
	  fin >> fatherssn;
	  cout << endl;
	  PrintAFamily(fatherssn);
	  cout << endl;
        }
      if(command == "PrintAllFamilies")
        {
	  cout << endl;
	  PrintAllFamilies();
	  cout << endl;
        }
    }
  cout << "\n========== EXECUTION OF FILE COMPLETE ==========\n\n";
  fin.close();
}

#endif
