//================================================================
//Name: Jonathan Leack
//Compiler: G++ compiler
//File type: Client
//================================================================
#ifndef queueclient_cpp
#define queueclient_cpp
#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

int main()
{ queue abc; // 10 slot queue used in this program
  string displayElem; // Used to store elements for display

  abc.add ("A"); // Begin by manually placing A, B, and C in queue
  abc.add ("B"); // " " 
  abc.add ("C"); // " "

  while(true)
    {
      try
	{
	  abc.remove(displayElem); // Remove item and store in dElem
	  cout << displayElem << endl;
	  abc.add(displayElem + "A"); // Add letter to end of queue
	  abc.add(displayElem + "B"); // " "
	  abc.add(displayElem + "C"); // " "
	}

      // Check for common program exceptions
      catch(queue::Overflow)
	{ cout << "EXCEPTION: Overflow" << endl;
	  exit(1); }
 
      catch(queue::Underflow)
	{ cout << "EXCEPTION: Underflow" << endl;
	  exit(1); }
    }
}
#endif
