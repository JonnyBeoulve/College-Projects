//================================================================
//Name: Jonathan Leack
//Compiler:  G++
//File type: Driver
//================================================================
#ifndef client1vector_cpp
#define client1vector_cpp
#include <iostream>
#include <string>
#include <vector>
#include "stack.h"
using namespace std;

int main()
{
  stack postfixstack; // Integer stack
  string expression; // User's string input

  cout << "Type a postfix expression: " ;
  cin >> expression;

  int i = 0; // Character position within expression, default at 0
  int result; // Output during arithmetic or to show user an element
  char item; // Operator in expression

  int box1;  // Receive things from pop
  int box2;  // Receive things from pop

  while (expression[i] != '\0') // Loop until nothing left to evaluate
    {
      try
        { item = expression[i]; // Assign expression element to item
          if(isdigit(item)) // Determine if item is an int (0-9)
	    { result = int(expression[i]) - 48; // Convert to int
	      postfixstack.push(result); // Push value into stack
	      postfixstack.displayAll(); } // Show user all stack items
	  // If not integer, determine if item is an operator
	  else if ((item == '+') || (item == '-') || (item == '*'))
	    { postfixstack.pop(box1); // Pop last two stack items
	      postfixstack.pop(box2);
	      if(item == '+') // In case of addition
		result = box1 + box2; // Add both stack items
	      else if(item == '-') // In case of subtraction
		result = box1 - box2; // Sub both stack items
	      else if(item == '*') // In case of multiplication
		result = box1 * box2; // Mult both stack items
	      postfixstack.push(result); // Push result into stack
	      postfixstack.displayAll(); } // Show user all stack items
	  else throw "ERROR: Invalid Element"; }
      // Test for error, and end program if one is caught
      catch (stack::Underflow)
	{ cout << "EXCEPTION: Underflow" << endl;  exit(1); }
      catch (char const* errorcode) // For invalid item
	{cout << "ERROR: Invalid Element" << endl; exit(1); } 
      i++;
    }
  postfixstack.pop(result); // Moves final expression to result
  if(postfixstack.isEmpty()) // Determines if stack is empty
    cout << "The final result is: " << result << endl;
  else // Result is OK, show to user
    cout << "ERROR: Invalid Expression" << endl;
}
#endif
