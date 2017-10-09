/*******************************************************
Jonathan Leack
HW3 llist
Complier:  g++
File type: .cpp
*******************************************************/
#ifndef llist_CPP
#define llist_CPP
#include<iostream>
#include<iomanip>
#include "llist.h" 
using namespace std;

llist::llist() //Constructor: Initialize Front and Rear to be NULL and Count = 0.
{
	Front=NULL;
	Rear=NULL; 
	Count=0;
}

llist::~llist() //Destructor: While the list is not empty, call deleteFront to delete all nodes.
{
	cout << endl << "Calling the llist destructor. " << endl;
	int element;
	while(!isEmpty())
	{
		deleteFront(element); //Front node of the list is deleted while the list is not empty
	}
}

bool llist:: isEmpty()
//return true if Front and Rear are both pointing to NULL.
//(note: do not use Count for this!!!)
{//if the front and rear is equal to NULL, that means that there are no nodes
	if(Front == NULL && Rear == NULL)
		return true; //List is empty (No nodes)
	else
		return false;
}

void llist:: displayAll()
{
Node* slot;
if(isEmpty()) //special case:if the list is empty, display empty.
	{cout << endl << "[Empty]" << endl;}
else
	{
		slot = Front;
		cout << endl;
		for(int i=1; i<=Count; i++)
		{//displays all elements in the linked list before it reaches NULL
			cout << slot -> Elem << " ";
			slot = slot -> Next;
			
		}
	}
}

void llist:: addRear(el_t NewNum)
{
Node* P;
if(Front == NULL)//special case: if this is going to be the very first node, you must
	{//create a new node and make Front and Rear point to it.
		P = new Node;
		Front = P;
		Front -> Elem = NewNum;
		Rear = Front;
	}
else
	{//Regular case:
	//adds a new node at the rear and puts NewNum in the Elem field
	//of this new node. Count is updated.
		Rear->Next = new Node;
		Rear = Rear->Next;
		Rear->Elem = NewNum;
		Rear->Next = NULL;
	}
Count++;
	
}

void llist:: deleteFront(el_t& OldNum)
{//3 cases
//error case: if the List is empty, throw an exception.
Node *Second;
if(isEmpty())throw Underflow();
else //else give back the front node element through OldNum (pass by reference)
   //and also remove the front node. Count is updated.
   {//Regular case:
		OldNum = Front->Elem;
		Second = Front->Next;
		delete Front;
		Front = Second;
		Count--;
//(special case: if this is going to make the list empty, 
//make sure both Front and Rear become NULL).	
		if(Front == NULL)
		{Rear = Front;}
	}

}

void llist:: addFront(el_t NewNum)
{//2 cases
	Node * P;
	Node * X;
	if(isEmpty())//special case: if this is going to be the very first node, you must
	{//create a new node and make Front and Rear point to it.)
		P = new Node;
		Front = P;
		Front -> Elem = NewNum;
		Front -> Next = NULL;
		Rear = Front;
	}

	else//Regular case:
	{//will add a new node to the front of the list. Count is updated.
		X = Front;
		P = new Node;
		Front = P;
		Front->Elem = NewNum;
		Front -> Next = X;
	}
Count ++;
}

void llist:: deleteRear(el_t& OldNum)
{//3 cases
	Node* P;
	Node* Q;
	
	if(isEmpty())
	{throw Underflow();}//error case: if empty, throw an exception.
		//(special case: if this is going to make the list empty, 
			//make sure both Front and Rear become NULL).
	if(Count ==1)
	{deleteFront(OldNum);}//calls deletefront and passes OldNum if there is only one Node
	else//else give back the rear node element through OldNum (pass by reference)
	//and also remove the rear node. Count is updated.
	{//Regular case:
		P=Front;
		Q=Front;
		while(Q->Next !=NULL)
		{
			P = Q;
			Q=Q->Next;
		}
		OldNum= Q->Elem;
		delete Q;
		Rear = P;
		Rear -> Next = NULL;
		Count--;
		if(isEmpty())//(special case: if this is going to make the list empty, 
			//make sure both Front and Rear become NULL).
		{Rear = Front;}
	}
}

void llist:: deleteIth(int I, el_t& OldNum)
//4 cases
{
Node* P;
Node* Q;
P = Front;
Q = Front;
//Error cases:
//If I is an illegal value (i.e. > Count or < 1) throw an exception.
if(I > Count || I < 1){throw OutOfRange();}
//(note: this may simply call deleteFront or deleteRear for some cases)		
else if(I == Count)deleteRear(OldNum);
else if(I == 1)deleteFront(OldNum);
else//will delete the Ith node (I starts out at 1).  Count is updated.
{
for(int y=1; y<I-1;y++)
{P=P->Next;}
Q=P->Next;
OldNum=Q->Elem;
P->Next=Q->Next;
delete Q;
Count --;
}
}

void llist:: addbeforeIth(int I, el_t newNum)
//4 cases
{
Node* P;
Node* Q;
Node* X;
P = Front; 
Q = Front;
//will add right before the Ith node.  Count is updated.
//Error cases:
//If I is an illegal value (i.e. > Count+1 or < 1) throw an exception.      
//(note: this may simply call addFront or addRear for some cases)
if(I > Count + 1 || I < 1)throw OutOfRange();
else if(I == Count + 1)addRear(newNum);
else if(I == 1)addFront(newNum);
else
{
	for(int y=1; y < I-1; y++)
	{P = P->Next;}
	
	Q = P -> Next;
	X = new Node;
	X -> Elem = newNum;
	X -> Next = Q;
	P -> Next = X;
	Count ++;
}
}

#endif
