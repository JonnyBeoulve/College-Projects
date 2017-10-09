//=======================================================
//HW7P2
//Jonathan Leack
//Compiler: G++ 
//File type: Header
//=======================================================
#ifndef DGRAPH_H
#define DGRAPH_H
#include "slist.h"
#include "stack.h"
#include "llist.h"
struct Gvertex 
{
  
  char name;
  int visitNo;
  int outDegree;
  slist adjacentOnes;
 
};

class dgraph
{
 public:
  // Purpose: Initialize data members when creating dgraph objects
  // How To Call: Client calls when declaring dgraph objects
  dgraph();

  // Purpose: Ensures composed objects and dgraph object are properly deleted
  // How To Call: Implicitly called when an automatic object goes out of scope
  //               or explicitly deleted when on the heap
  ~dgraph();

  // Purpose: Displays the table content in a readable format.  Unused slots
  //           are not displayed.
  // How To Call: Call only when you want to display the graph using stdout stream
  void displayGraph();

  // Purpose: Reads the input file 'table.txt' to fill the table
  // How To Call: As of this time, you can only read from the file 'table.txt'
  //               Because of this, call the function without a parameter
  void fillTable();  

  // Purpose: Returns the out degree of a given vertex
  // How To Call: pass the character of the vertex that you'd like to find
  //               the out degree of
  int findOutDegree(char);

  // Purpose: Returns a list of vertices that are adjacent to a chosen vertex
  // How To Call: pass the vertex that you'd like to know the adjacent vectors of
  slist findAdjacency(char);
void visit( int , char );
bool isMarked( char );


 protected:

  // Purpose: Sort the table of Gvertex after it is filled
  // How To Call: Call after the table is filled
  void GtableSort(Gvertex filledTable[], int length);

  // Purpose: Access particular vertices quickly
  // How To Call: Use to return an index directly
  int binarySearch(char search);

  Gvertex Gtable[28]; // array of vertices large enough to store all uppercase letters
  static const int MAX_TABLE_LENGTH;
  int currentSlot;
};

#endif // DGRAPH_H  
