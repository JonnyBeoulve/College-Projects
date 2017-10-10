//================================================================
//Name: Jonathan Leack
//Compiler: G++ compiler
//File type: Implementation
//================================================================
#ifndef queue_cpp
#define queue_cpp
#include <iostream>
#include <string>
#include "queue.h"
using namespace std;

queue::queue() // Constructor
{ count = 0, front = 0, rear = -1; // Set default values 
}

queue::~queue() // Destructor
{}

// PURPOSE: Returns true if queue is empty, otherwise false
bool queue::isEmpty()
{ if(count == 0)
    return true;
  else
    return false; 
}

// PURPOSE: Returns true if queue is full, otherwise false
bool queue::isFull()
{ if(count >= MAX_SIZE)
    return true;
  else
    return false; 
}

// PURPOSE: If full, throws an exception Overflow
// ...if not full, enters an element at the rear 
// HOW TO CALL: Provide the element to be added
void queue::add(el_t elem)
{ if(isFull())
    throw Overflow();
  else
    { rear = (rear + 1) % MAX_SIZE; // Increment rear before insertion
      el[rear] = elem; // Toss element to end of queue
      count++; } // Increment Count to track total
}

// PURPOSE: Ff empty, calls an emergency exit routine
// ...if not empty, removes the front element to give it back 
// HOW TO CALL: Provide a holder for the element removed (pass by ref)
void queue::remove(el_t& elem)
{ if(isEmpty())
    throw Underflow();
  else
    { elem = el[front]; // Moves front element into elem
      front = (front + 1) % MAX_SIZE; // Increment front after removal
      count--; } // Decrement after removal
}

// PURPOSE: If empty, throws an exception Underflow
// ...if not empty, give back the front element (but does not remove it)
// TO CALL: Provide a holder for the element (pass by ref)
void queue::frontElem(el_t& elem)
{ if(isEmpty())
    throw Underflow();
  else
    elem = el[front]; // Moves front element into elem
}

// PURPOSE: Returns the current size to make it 
// ...accessible to the client caller
int queue::getSize()
{ return count; // Count is a counter for the queue size
}

// PURPOSE: Display everything in the queue from front to rear
// ...enclosed in []
// ...if empty, displays [ empty ]
void queue::displayAll()
{ if(isEmpty())
    cout << "[ Empty ]" << endl; // Queue is empty, display
  else
    { for(int i = 0; i < count; i++)
	{ cout << el[front] << endl; // Display element
	  front = (front + i) % MAX_SIZE; }} // Rotate through elements
}

// PURPOSE: If empty, throws an exception Underflow
// ...if queue has just 1 element, does nothing
// ...if queue has more than 1 element, moves the front one to the rear
void queue::goToBack()
{ if(isEmpty())
    throw Underflow();
  else if(count = 1)
    return;
  else
    { string elemToAdd = el[front]; // Temp. creates string in memory for move
      remove(elemToAdd); // Perform removal and movement for element
      add(elemToAdd); } // Front element is then moved to rear
}
#endif
