/*******************************
Name: Jonathan Leack
*******************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Node;
typedef Node* NodePtr;
class LL;

class Node 
{
  friend class LL;
private:
  int stId;
  string stName;
  string stEmail;
  int stAge;
  NodePtr nextStudent;
};

class LL
{
private:
  NodePtr top;
  void destroy (NodePtr&);
  int listSize;
public:
  LL();
  LL(const LL& source);
  ~LL();
  void insertDataFromFile();
  void print ();
  bool search (int);
  void insertAfterFirst (int id, string name, string email, int age);
  void insertBeforeFirst (int id, string name, string email, int age);
  void insertAfterLast (int id, string name, string email, int age);
  void insertBeforeLast (int id, string name, string email, int age);
  void remove (int);
  void copy (NodePtr top1, NodePtr& top2);
};

LL::LL()
{
  top = NULL;
  listSize = 0;
}

LL::LL(const LL& source)
{
  top = NULL;
  copy(source.top, top);
}

LL::~LL()
{
  cout << "===== Destructor has been called =====\n\n";
  destroy (top);
}

void LL::insertDataFromFile()
{
  int studentId, studentAge;
  string studentName, studentEmail;
  char command;
  bool cmdEnter = false;

  ifstream fin;
  fin.open("data.txt");
  
  while(fin >> studentId >> studentName >> studentEmail >> studentAge) //better option?
    {
      cout << "Where would you like to place " << studentName << "'s data?" << endl;
      
      while(cmdEnter == false)
	{
	  cout << "Enter 'A' for Before First, 'B' for After First, 'C' for Before Last, or 'D' for After Last: ";
	  cin >> command;

	  if(command == 'A')
	    {	 
	      cmdEnter = true;	
	      insertBeforeFirst (studentId, studentName, studentEmail, studentAge);
	    }	 
	  else if(command == 'B')
	    {	 
	      cmdEnter = true;
	      insertAfterFirst (studentId, studentName, studentEmail, studentAge);
	    }
	  else if(command == 'C')
	    {	 
	      cmdEnter = true;
	      insertBeforeLast (studentId, studentName, studentEmail, studentAge);
	    }
	  else if(command == 'D')
	    {	 
	      cmdEnter = true;
	      insertAfterLast (studentId, studentName, studentEmail, studentAge);
	    }
	  else
	    cout << "ERROR: Invalid input!" << endl;	
	}
      cmdEnter = false;
    }
  cout << endl;
  fin.close();
}

void LL::print ()
{
  NodePtr curr = top;
  while(curr != NULL)
    {
      cout << curr -> stId << " -> " << curr -> stName << " -> " << curr -> stEmail << " -> " << curr -> stAge << endl;
      curr = curr -> nextStudent;
    }
  cout << endl;
}

bool LL::search (int id)
{
  NodePtr curr = top;
  bool found = false;
  while ((curr != NULL) && (!found))
    if (curr -> stId == id)
      found = true;
    else
      curr = curr -> nextStudent;
  return (found);
}

void LL::insertAfterFirst (int id, string name, string email, int age)
{
  NodePtr curr = top, prev = NULL, newNode;
  bool found = false;
  newNode = new Node;
  newNode -> stId = id;
  newNode -> stName = name;
  newNode -> stEmail = email;
  newNode -> stAge = age;
  prev = curr;
  curr = curr -> nextStudent;
  newNode -> nextStudent = curr;
  prev -> nextStudent = newNode;
  listSize++;
}

void LL::insertBeforeFirst (int id, string name, string email, int age)
{
  NodePtr curr = top, newNode;
  newNode = new Node;
  newNode -> stId = id;
  newNode -> stName = name;
  newNode -> stEmail = email;
  newNode -> stAge = age;
  newNode -> nextStudent = top;
  top = newNode;
  listSize++;
}

void LL::insertAfterLast (int id, string name, string email, int age)
{
  NodePtr curr = top, prev = NULL, newNode;
  bool found = false;
  newNode = new Node;
  newNode -> stId = id;
  newNode -> stName = name;
  newNode -> stEmail = email;
  newNode -> stAge = age;
  for(int i = 0; i < listSize; i++)
    {
      prev = curr;
      curr = curr -> nextStudent;
    }
  newNode -> nextStudent = curr;
  prev -> nextStudent = newNode;
  listSize++;
}

void LL::insertBeforeLast (int id, string name, string email, int age)
{
  NodePtr curr = top, prev = NULL, newNode;
  bool found = false;
  newNode = new Node;
  newNode -> stId = id;
  newNode -> stName = name;
  newNode -> stEmail = email;
  newNode -> stAge = age;
  for(int i = 1; i < listSize; i++)
    {
      prev = curr;
      curr = curr -> nextStudent;
    }
  newNode -> nextStudent = curr;
  prev -> nextStudent = newNode;
  listSize++;
}

void LL::remove (int id)
{
  NodePtr curr, temp;

  if (id == top -> stId) 
    {
      temp = top;
      top = top -> nextStudent;
    }
  else 
    {
      curr = top;
      while (curr -> nextStudent -> stId != id)
	curr = curr -> nextStudent;
      temp = curr -> nextStudent;
      curr -> nextStudent = curr -> nextStudent -> nextStudent;
    }

  delete temp; 
  listSize--;
  cout << "Record for ID #" << id << " has been deleted!\n\n" << endl;
}

void LL::copy (NodePtr atop, NodePtr& btop)
{
  NodePtr acurr, bcurr;
  destroy (btop); 
   
  if (atop != NULL) 
    {
      btop = new (Node);
      btop -> stId = atop -> stId;
      btop -> stName = atop -> stName;
      btop -> stEmail = atop -> stEmail;
      btop -> stAge = atop -> stAge;
      acurr = atop;
      bcurr = btop;
      while (acurr -> nextStudent != NULL) 
	{
	  bcurr -> nextStudent = new (Node);
	  acurr = acurr -> nextStudent;
	  bcurr = bcurr -> nextStudent;
	  bcurr -> stId = acurr -> stId;
	  bcurr -> stName = acurr -> stName;
	  bcurr -> stEmail = acurr -> stEmail;
	  bcurr -> stAge = acurr -> stAge;
	} 
      bcurr -> nextStudent = NULL;
    }
}       

void LL::destroy(NodePtr& top) 
{
  NodePtr curr = top, temp;

  while (curr != NULL) 
    {
      temp = curr;
      curr = curr -> nextStudent;
      delete temp;
    }
  top = NULL;
}

int main () 
{
  LL list1;
  list1.insertDataFromFile();
  list1.print();
  list1.insertBeforeFirst (54123, "Joe", "joe@csusm.edu", 35);
  list1.insertAfterFirst (54321, "Jim", "jim@csusm.edu", 25);
  list1.insertAfterLast (63421, "Adam", "adam@csusm.edu", 20);
  list1.insertBeforeLast (66641, "Nancy", "nancy@csusm.edu", 27);
  list1.print();
  bool found = list1.search (66641);
  if (found)
    cout << "The record was found!\n" << endl;
  else
    cout << "The record was NOT found!\n" << endl;
  list1.remove (54321);
  list1.print();

  LL list2(list1);
  list2.print();

  return 0;
}
