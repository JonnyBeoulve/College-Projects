// =========================================================
//Jonathan Leack
//===========================================================
#ifndef DGRAPH_C
#define DGRAPH_C
#include <iostream> 
#include <fstream> 
#include <cctype> // for toupper
#include "dgraph.h"
using namespace std;

const int dgraph::MAX_TABLE_LENGTH = 28;
                             // number is also hard coded in class
                             // definition as an array size of Gtable

// PURPOSE: Initialize data members of dgraph objects
dgraph::dgraph()
{
  currentSlot = 0;

  for( int i = 0; i < MAX_TABLE_LENGTH; i++ )
    {
      Gtable[i].name = ' ';
      Gtable[i].visitNo = 0;
      Gtable[i].outDegree = 0;
    }
}

// PURPOSE: Destroy dgraph objects
//the destructors from slist and llist should be called 
dgraph::~dgraph()
{
 
}

void dgraph::displayGraph()
{
  string seperator = "*********************\n";
  cout << seperator;
  cout << "Printing the Graph\n";
  slist tmpList;
  for( int i = 0; i < currentSlot; i++ )// currentSlot is also how many slots of
    {                                    //  the table you're using
      cout << Gtable[i].name << " "
	   << Gtable[i].outDegree << " ";
      tmpList = Gtable[i].adjacentOnes;
      for( int j = 0; j < Gtable[i].outDegree; j++ )
	{
	  el_t adj;
	  tmpList.deleteFront(adj);
	  cout << adj << " ";
	}
      cout << "\n";
    }
  cout << seperator;
}


// PURPOSE: Find the number of Adjacent vertices easily
// PARAMETERS: Input the name of the vertex as a char
// RETURNED VALUES: -1(chosenVertex DNE), any positive int(chosenVertex found)
int dgraph::findOutDegree(char chosenVertex)
{
  int index = binarySearch(chosenVertex);
  if( index == -1 )
    return -1;
  else
    return Gtable[index].outDegree;
}

// PURPOSE: Fill the table using a very specific file named "table.txt"
// PARAMETERS: none; it would be good to allow users to pick different
//   file names
void dgraph::fillTable()
{
  
  string fileName = "table.txt";
  ifstream fin;
  fin.open(fileName.c_str());

  //if any problem opening file, then throw EXCEPTION
  if( ! fin.is_open() ) 
      throw "ERROR: File could not be opened\n"; 


  //fin successfully opened the file
  while( fin >> Gtable[currentSlot].name ) // first token is NAME
    {
      fin >> Gtable[currentSlot].outDegree; // second token is # ADJACENT VERTICES
	
      for( int i = 0; i < Gtable[currentSlot].outDegree; i++ )
	{
	  el_t anAdjVertex;
	  fin >> anAdjVertex; // additional tokens per line are ADJACENT VERTICES
	  (Gtable[currentSlot].adjacentOnes).addRear(anAdjVertex); 
	}
      ++currentSlot;
    }

  GtableSort(Gtable, currentSlot); // sort table contents by NAME  

}

// PURPOSE: Get the list of adjacent vertices to a chosen vertex
// PARAMETERS: Input the chosen vertex as a char
slist dgraph::findAdjacency(char chosenVertex)
{

  int index = binarySearch(chosenVertex);
  if( index == -1 ) //if not found
    {
      slist empty;
      return empty;
    }
  else //vertex was found, so return it
    return Gtable[index].adjacentOnes;
}



// Algorithm: uses quicksort; implemenetation relies on order of tokens;
//   only the first token of each slist, NAME, is compared for sorting
void dgraph::GtableSort(Gvertex filledTable[], int length)
{
  int i,j;
  char temp;
  for( i=1; i<length; i++ )
    {
      j=i;
      while( j>0 && (filledTable[j-i].name > filledTable[j].name) ) 
	{
	  temp = filledTable[j].name;
	  filledTable[j].name = filledTable[j-1].name;
	  filledTable[j-1].name = temp;
	  --j;
	}
    }
}


// Algorithm: binary search; midpoint is chosen to be floor(middle)
int dgraph::binarySearch(char key)
{
  key = toupper(key); //make sure key is upper case

  int first, last, mid;
  first = 0;
  last = currentSlot-1;
  mid = (first+last)/2;
  while( (Gtable[mid].name != key) && (first<=last) )
    {
      if(Gtable[mid].name > key)
	last = mid-1;
      else
	first = mid+1;

      mid = (first+last)/2;
    }


  if( first <= last ) // vertex was found
    {
      return mid; // return it
    }
  else //vertex DNE
    return -1; //return what cannot be an index
}



void dgraph::visit( int newVisitNo, char givenVertex )
{
  Gtable[binarySearch(givenVertex)].visitNo = newVisitNo;  
}


bool dgraph::isMarked( char givenVertex )
{
  if( Gtable[binarySearch(givenVertex)].visitNo > 0 )
    return true;
  else
    return false;
}

#endif // DGRAPH_C
