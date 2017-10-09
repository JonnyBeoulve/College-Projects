// =========================================================
//HW7P2
//Jonathan Leack
//Compiler: G++
//File type: Client
//==========================================================
#include <iostream>
#include <string>
using namespace std;
#include "dgraph.h"
#include "stack.h"
void pushListOnStack(el_t vertexName, stack & depthFirstStack,  dgraph & theGraph);

int main()
{
  dgraph g;
  string fileName = "table.txt"; // only used to inform user of the filename
  cout << "An empty graph was created\n\n";  g.fillTable(); // text file 'table.txt' must exist in the directory                    
  cout << "The graph was filled using data file " << fileName << "\n\n";
  g.displayGraph();  //DFS implemented here; in client file  
  el_t vertexName = 'A'; // for moving chars between stack and list
  int visitNo = 1;  
  g.visit(visitNo,vertexName); // mark vertex A as first visited vertex  
  ++visitNo;  
  slist adjList = g.findAdjacency(vertexName); // get A's adjacency list  
  stack dfsStack;  // char stack holds adjacent vertex list    
  pushListOnStack(vertexName, dfsStack, g);  
  cout << "\tINITIAL STACK:\n";  
  dfsStack.displayAll(); // display current stack  

  //Enter loop  
  while( ! dfsStack.isEmpty() )    
    {      
      dfsStack.pop(vertexName);      
      cout << "\nPopping " << vertexName << "\n";      
      cout << "Has vertex " << vertexName << " been visited?\n";      
      
      if ( ! g.isMarked(vertexName) ) // if vertex has not been visited	
	{	  
	  cout << "No, visiting vertex " << vertexName << "\n";	  
	  g.visit(visitNo,vertexName); // then visit it	  
	  ++visitNo;	  
	  pushListOnStack(vertexName, dfsStack, g);	  
	  cout << "\n\tUPDATED STACK:\n";	  
	  dfsStack.displayAll();	}     
      else	
	cout << "Yes, NOT  visiting " << vertexName << "\n";    
    }  
  cout << "\n\nDFS order of Graph:\n";  
  g.displayGraph();
}

// Purpose: Used to cleanly push all adjacencyList elements onto stack
// Parameter Purpose: pass the vertexName whose adjList you wish to add
void pushListOnStack(el_t vertexName, stack & depthFirstStack, dgraph & theGraph)  
{    
  slist adjList = theGraph.findAdjacency(vertexName);    
  while( ! adjList.isEmpty() )      
    {	
      // deleteRear returns rear element	
      adjList.deleteRear(vertexName);	
      depthFirstStack.push(vertexName);      
    }   
}
