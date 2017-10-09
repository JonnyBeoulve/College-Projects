// =======================================================
// HW1P1
// Your name: Jonathan Leack
// Compiler:  g++
// File type: header file stack.h
//=======================================================
#ifndef Stack_H
#define Stack_H
//=======================================================
#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef int el_t;      // the el_t type int for now
                      // el_t is unknown to the client


class stack
  { 

   private: // to be hidden from the client

       vector <el_t> el; //vector el is a vector of type el_t(int)

   public: // prototypes to be used by the client
		
		
        // exception handling classes  
        class Overflow{};
        class Underflow{};

      	stack();   // constructor
      	~stack();  // destructor  

        // HOW TO CALL: pass the element to be pushed
        // PURPOSE: if not full, enters an element at the top;
        //          otherwise throws an exception - Overflow
        void push(el_t);

        // HOW TO CALL: provide variable to receive the popped element
        // PURPOSE: if not empty, removes and gives back the top element;
        //          otherwise throws an exception - Underflow
        void pop(el_t &);

        // HOW TO CALL: Call topElem in the mainfunction or cpp file by referring to the function name or calling the object in the Main function
        // PURPOSE: if not empty, gives the top element without removing it;
        //          otherwise, throws an exception - Underflow
        void topElem(el_t &);

        // ************ add good comments for each function *****
      	//PURPOSE: This checks if the stack is empty, so and error or underflow does not occur
		bool isEmpty();
		//PURPOSE: This checks to see if the stack is full, so overflow does not occur
      	bool isFull();
		//PURPOSE: Displays all elements in the stack without altering them
        void displayAll();
		//PURPOSE: Clears out the stack is not already empty
        void clearIt();
        
  };  
#endif
// Note: semicolon is needed at the end of the header file

