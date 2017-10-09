// =========================================================
//HW1P1 stack
//Your name: Jonathan Leack
//Complier:  g++
//File type: .cpp Implementation file of stack
//================================================================
#ifndef Stack_CPP
#define Stack_CPP
//================================================================
#include<iostream>
#include<vector>
#include "stack.h"
using namespace std;
//The constructor does not have to do anything since the vector is dynamic.
stack::stack()
{}//nothing to do

//The deconstructor makes sure that the cells are empty.
stack::~stack()
{
	clearIt();
}
  
// ** isEmpty checks if vector is empty and returns true if empty, false otherwise.
//    In the comment, make sure you define "empty" in terms of top.
bool stack::isEmpty()
{ if (el.size() == 0) return true; else return false; }
    
// ** isFull is always false
bool stack::isFull()
  { return false; }
  
// ** push calls isFull and if true, throws an exception (Overflow)
//   Otherwise, adds an element to el after incrementing top.
void stack::push(el_t elem)
{ if(isFull()) throw Overflow(); 
	else el.push_back(elem);}
  
// ** pop calls isEmpty and if true, throws an exception (Underflow)
//  Otherwise, removes an element from el and gives it back.
void stack::pop(el_t &elem)
{ if (isEmpty()) throw Underflow();
    else { 
	elem = el[el.size()-1];
	el.pop_back();}}

// ** topElem calls isEmpty and if true, throws an exception (underflow)
//    Otherwise, gives back the top element from el.
void stack::topElem(el_t &elem)
{ if (isEmpty()) throw Underflow();
    else { elem=el[el.size()-1]; } }

//dislayAll calls isEmpty and if true, displays [ empty ].
//  Otherwise, diplays the elements vertically.
void stack::displayAll()
  {  if (isEmpty()) cout << "[ empty ]" << endl;
    else for (int i = 0; i<el.size(); i++)
      { cout << el[i] << endl; }}//Endl is used so the elements would be displayed vertically

//** clearIt pops all elements from the stack to make it empty if it is not empty yet.
void stack::clearIt()
{
  while (!isEmpty())//Checks if stack is already empty.
    {      
      el.erase(el.begin(),el.begin()+el.size());//Clears all elements.
    }
}
#endif
