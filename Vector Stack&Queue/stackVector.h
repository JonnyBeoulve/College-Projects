//=======================================================
//Name: Jonathan Leack
//Compiler:  G++ 
//File type: Header
//=======================================================
#ifndef stackvector_h
#define stackvector_h
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef int el_t;     // The el_t type is int for now
                      // el_t is unknown to the client
class stack
{
 private: // To be hidden from the client
  vector <el_t> el; // This vector will provide space for dynamic stack
  
 public: // Prototypes to be used by the client

  // Exception handling classes
  class Underflow{};

  stack();   // Constructor
  ~stack();  // Destructor - leaves no cells behind

  // HOW TO CALL: Pass the element to be pushed
  // PURPOSE: Enters an element at the top;
  void push(el_t);

  // HOW TO CALL: Provide variable to receive the popped element
  // PURPOSE: If not empty, removes and gives back the top element;
  // ...otherwise throws an Underflow exception
  void pop(el_t&);

  // HOW TO CALL: Refer to function name in implementation or driver
  // PURPOSE: If not empty, gives the top element without removing it;
  // ...otherwise, throws an Underflow exception
  void topElem(el_t&);

  // PURPOSE: Checks if the stack is empty to prevent potential errors
  bool isEmpty();

  // PURPOSE: Checks if the stack is full to prevent potential errors
  // ...and non-enterable data by user's input
  bool isFull();

  // PURPOSE: Displays all elements currently in the stack for user
  void displayAll();

  // PURPOSE: Removes all data from a stack if there is any
  void clearIt();
};
#endif
