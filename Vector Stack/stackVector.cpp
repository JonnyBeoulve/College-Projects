//================================================================
//HW1P2 - Vector Stack
//Name: Jonathan Leack
//Complier:  G++
//File type: Implementation
//================================================================
#ifndef stackvector_cpp
#define stackvector_cpp
#include "stackVector.h"
using namespace std;

// Constructor creates an empty vector stack
stack::stack()
{} // Empty stack

// Destructor clears out any cells holding data
stack::~stack()
{clearIt();}

// isEmpty determines if vector is empty, and if so returns true
bool stack::isEmpty()
{ if (el.size() == 0) return true; else return false; }

// push adds an element to el
void stack::push(el_t elem)
{ el.push_back(elem); }

// pop calls isEmpty and if true, throws an Underflow exception
// ...otherwise, removes an element from el and gives it back
void stack::pop(el_t& elem)
{ if (isEmpty()) throw Underflow();
  else
    { elem = el[el.size() - 1];
      el.pop_back(); } }

// topElem calls isEmpty and if true, throws an Underflow exception
// ...otherwise, gives back the top element from el
void stack::topElem(el_t& elem)
{ if (isEmpty()) throw Underflow();
  else elem = el[el.size() - 1]; }

// dislayAll calls isEmpty and if true, displays [ empty ]
// ...otherwise, diplays the elements vertically to the user using for loop
void stack::displayAll()
{ if (isEmpty()) cout << "[ empty ]" << endl;
  else for (int i = 0; i < el.size(); i++)
    { cout << el[i] << endl; }
  cout << "----------" << endl; }

// clearIt calls isEmpty and continues to remove elements from the stack
// ...until the vector is empty
void stack::clearIt()
{ while(!isEmpty()) // Loops until no elements are left in the stack
    { el.erase(el.begin(), el.end()); } }
#endif
