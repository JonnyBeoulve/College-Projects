//=======================================================
//Name: Jonathan Leack
//Compiler:  G++ compiler
//File type: Header
//=======================================================
#ifndef queue_h
#define queue_h
#include <iostream>
#include <string>
using namespace std;

typedef string el_t; // el_t is an alias for the data type

const int MAX_SIZE = 60; // Maximum capacity for queue

class queue  
{
  private:
    el_t el[MAX_SIZE]; // An array called el.
                       // Elements will be found between front and rear but
                       // ...queue wraps around
    int  count; // An element counter          
    int  front; // Pointer for front of queue
    int  rear; // Pointer for end of queue

  public:
    class Underflow{};
    class Overflow{};
    queue(); 
    ~queue();

   // PURPOSE: Returns true if queue is empty, otherwise false
   bool isEmpty();

   // PURPOSE: Returns true if queue is full, otherwise false
   bool isFull();

   // PURPOSE: If full, throws an exception Overflow
   // ...if not full, enters an element at the rear 
   // HOW TO CALL: Provide the element to be added
   void add(el_t);

   // PURPOSE: If empty, calls an emergency exit routine
   // ...if not empty, removes the front element to give it back 
   // HOW TO CALL: Provide a holder for the element removed (pass by ref)
   void remove(el_t&);

   // PURPOSE: If empty, throws an exception Underflow
   // ...if not empty, give back the front element (but does not remove it)
   // TO CALL: Provide a holder for the element (pass by ref)
   void frontElem(el_t&);

   // PURPOSE: Returns the current size to make it 
   // ...accessible to the client caller
   int getSize();

   // PURPOSE: Display everything in the queue from front to rear
   // ....enclosed in [] ...if empty, displays [ empty ]
   void displayAll();

   // PURPOSE: if empty, throws an exception Underflow
   // ...if queue has just 1 element, does nothing
   // ...if queue has more than 1 element, moves the front one to the rear
   void goToBack();
};           
#endif
