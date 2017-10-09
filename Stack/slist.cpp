/*****************************************
Jonathan Leack
HW: HW3P2
Compiler: g++
File Type: .cpp
*****************************************/
#ifndef slist_CPP
#define slist_CPP
#include<iostream>
#include "slist.h"
using namespace std;


slist::slist(const slist& Original)
{
	Front = Rear = NULL;
	Count = 0;
	this -> operator=(Original);
}

//Note that OtherOne is being passed by reference
//The resulting List will be returned by reference
slist& slist::operator =(const slist& OtherOne)
{
	if(&OtherOne != this)
	{
		int foo = 0;
		while(!this->isEmpty())
		{
			this->deleteRear(foo);
		}
		Node* lCurr = NULL, * lPrior = NULL; //allocated new cells
		Node* rCurr = OtherOne.Front; //local pointer
		
		Front = NULL;
		while(rCurr !=NULL)
		{
			lCurr = new Node;
			lCurr->Elem = rCurr->Elem;
			lCurr->Next = NULL;
			
			if(lPrior)
			{lPrior->Next = lCurr;}
			else
			{Front = lCurr;}
			
			Count++;
			lPrior = lCurr;
			rCurr = rCurr->Next;
		}
		
		Rear = lCurr;
		
	}
return *this;
}
			


int slist::search(el_t key)
{
	Node* P = Front;
	int P_index = 1;
	while(P)
	{ //Search through the list for the key.
		if(P -> Elem == key) //If the key is found, return its position (>=1). Otherwise, return 0.
		{
			return P_index;
		}
		P = P->Next;
		P_index++;
	}
	return 0;
}

void slist::replace(el_t Elem, int I)
{
	if(I < 1 || I > Count) //Throw exception if value is out of range.
	{throw OutOfRange();}
	
	else if(isEmpty())
	{throw Underflow();}
	
	else
	{
		int P_index = 1;
		Node* P = Front;
		while(P_index != I) //Element at this location is replaced with a new element.
		{
			P = P->Next;
			P_index++;
		}
		P->Elem = Elem;
	}
}
#endif

