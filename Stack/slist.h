/*****************************************
Jonathan Leack
HW: HW3P2
Compiler: g++
File Type: .h
*****************************************/
#ifndef slist_H
#define slist_H
#include<iostream>
#include "llist.h"
class slist: public llist
{
	public:
	slist() : llist(){}; //default constructor
	slist(const slist&); //copy constructor
	~slist() {};
	
	slist& operator=(const slist&); //Assigns object's values to another object using the = operator.
	
	
	int search(el_t key);
	void replace(el_t Elem, int I); 
};
#endif
