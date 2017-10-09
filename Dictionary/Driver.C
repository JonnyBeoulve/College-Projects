/*********************************
Name: Jonathan Leack

Description: This program allows a user to import a specified transaction file.
The transaction file interfaces with functions which build and edit a dictionary.
Commands include the ability to add a word, remove a word, spellcheck, search for
the existence of a word, and printing of all words beginning with a certain letter.
The program also allots a capacity for the entire dictionary size as well as the size
for each individual letter.
********************************/
#include <iostream>
#include <string>
#include "dictionary.h"
using namespace std;

int main()
{
  Dictionary DictForCS211;
  DictForCS211.ProcessTransactionFile();

  return 0;
}
