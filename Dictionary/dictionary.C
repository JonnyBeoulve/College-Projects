#ifndef DICTIONARY_C
#define DICTIONARY_C

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "dictionary.h"
using namespace std;

bool Dictionary::failure = false; //globally set failure to 0 boolean
bool Dictionary::success = true; //globally set success to 1 boolean

//default constructor
Dictionary::Dictionary(): maxWordsInDict(10000), maxWordsPerFile(100), totalWordsInDict(0)
{
     for(int i = 0; i < 26; i++)
       {
	 numOfWordsInFile[i] = 0; //loop through array and set each slot to 0 (0 = a, 26 = z in dictionary)
       }
}

//constructor if passed values dictMaxWords and fileMaxWords (2)
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords): maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords), totalWordsInDict(0)
{
  for(int i = 0; i < 26; i++)
    {
      numOfWordsInFile[i] = 0; //loop through array and set each slot to 0 (0 = a, 26 = z in dictionary)
    }
}

bool Dictionary::AddAWord(string word)
{
  string fileName = "#.txt"; //make a filename string with a temporary first letter
  fileName[0] = toupper(word[0]); //replace # with first letter of word

  ofstream fout; 
  fout.open(fileName.data(), ios::app); //open file corresponding to first letter of word

  for(int i = 0; word[i] != '\0'; i++) //convert word to full lower case
    {
      word[i] = tolower(word[i]);
    }
  int ascii = word[0] - 97; //convert first letter of word to ascii value 0 - 25

  if(!Dictionary::SearchForWord(word)) //confirm that word is not in the dictionary
   {
     if(totalWordsInDict <= maxWordsInDict && numOfWordsInFile[ascii] <= maxWordsPerFile) //check both limits
       {
	 fout << word << endl; //push word to dictionary file
	 numOfWordsInFile[ascii]++; //increment dictionary letter total by 1
	 totalWordsInDict++; //increment total words in dictionary by 1
	 fout.close(); 
	 return Dictionary::success;
       }  
     else //limit has been reached
       {
	 cout << "\nERROR: The word '" << word << "' could not be added! Capacity has been reached.\n";
       }
   }

  fout.close();
  return Dictionary::failure; 
}

bool Dictionary::DeleteAWord(string word)
{
  vector<string> wordVector;
  string wd;

  string fileName = "#.txt"; 
  fileName[0] = toupper(word[0]); 

  ifstream fin;
  fin.open(fileName.data()); //open file corresponding to first letter of word

  if(!Dictionary::SearchForWord(word)) //if word doesn't exist in dictionary, return failure
    {
      cout << "\nThe word '" << word << "' doesn't exist in the dictionary!\n";
      return Dictionary::failure;
    }

  while(fin>>wd) //push words into vector one by one
    {
      for(int i = 0; word[i] != '\0'; i++) //convert word to full lower case
	{
	  word[i] = tolower(word[i]);
	}
      wordVector.push_back(wd); //insert into vector
    }

  fin.close(); //file no longer needed, close

  for(int i = 0; i < wordVector.size(); i++) //check every word in the vector for match
    {
      if(wordVector[i] == word) //if match
	{
	  cout << "\nRemoving " << word << " from dictionary.\n";
	  wordVector.erase(wordVector.begin() + i); //remove word from vector
	  int ascii = word[0] - 97; //determine ascii value of first letter
	  numOfWordsInFile[ascii]--; //decrement total number of words for corresponding file letter
	  totalWordsInDict--; //decrement total words
	  i--;	//jump back one value since a vector slot has been deleted
	}
    }

  ofstream fout;
  fout.open(fileName.data());

  for(int i = 0; i < wordVector.size(); i++) //push modified vector back into file
    {
      fout << wordVector[i] << endl;
    }

  fout.close();
  return Dictionary::success;
}

bool Dictionary::SearchForWord(string word)
{
  ifstream fin2;
  string fileName = "#.txt";
  string wd;

  fileName[0] = toupper(word[0]);
  fin2.open(fileName.data());

  if(!fin2) //the file doesn't exist
    {
      return Dictionary::failure;
    }

  while(!fin2.eof())
    {
      fin2 >> wd; //push next word into wd
      for(int i = 0; word[i] != '\0'; i++) //convert word to full lower case
	{
	  word[i] = tolower(word[i]);
	}
      if(wd == word) //if word matches one already in file return true
        {
	  fin2.close();
          return Dictionary::success;
        }
    }

  fin2.close();
  return Dictionary::failure; //if file exists but no word match
}

bool Dictionary::SpellChecking(string fileName)
{
  string wd;
  ifstream fin;

  fin.open(fileName.data());

  if(!fin) //determine if file exists
    {
      cout << "\nERROR: The file '" << fileName << "' doesn't exist!\n";
      return Dictionary::failure;
    }

  while(!fin.eof()) //check file for word match
    {
      fin >> wd;
      for(int i = 0; wd[i] != '\0'; i++) //convert wd to full lower case
        {
          wd[i] = tolower(wd[i]);
        }
      if(!SearchForWord(wd)) //if no match found, display error
	cout << "\nERROR: The word '" << wd << "' is misspelled!\n";
      }

  fin.close();
  return Dictionary::success;
}

bool Dictionary::InsertWordsIntoDict(string fileName)
{
  string wd;
  ifstream fin;

  if(!fin) //determine if file exists
    {
      cout << "\nERROR: The file '" << fileName << "' doesn't exist!\n";
      return Dictionary::failure;
    }

  fin.open(fileName.data());

  while(!fin.eof()) //push all words to AddAWord for dictionary entry
    {
      fin >> wd;
      AddAWord(wd);
    }
  fin.close();
  return Dictionary::success;
}

bool Dictionary::PrintAFileInDict(string fileName)
{
  vector<string> myVector;
  string word;
  int count = 0; //total words in file

  ifstream fin;
  fin.open(fileName.data());

  if(!fin) //determine if file exists
    {
      cout << "\nERROR: The file '" << fileName << "' doesn't exist!\n";
      return Dictionary::failure;
    }

  while(!fin.eof()) //push words into vector
    {
      fin >> word;
      myVector.push_back(word);
      count++; //increment count
    }

  cout << "\nWords beginning with '" << word[0] << "':\n";

  for(int i = 1;i <= count; i++) //output words with only 5 words per line
    {
      cout << myVector[i - 1] << " ";
      if(i%5 == 0) //if a 5th word has been output, go to next line
	{
	  cout << "\n";
	}
    }

  cout << "\n"; //space for readability

  fin.close();
  return Dictionary::success;
}

void Dictionary::ProcessTransactionFile()
{
  string transFile; //user's entered file name
  string command; //command in transaction file (left column)
  string data; //data related to command in transaction file (right column)

  cout << "Please enter the name of the transaction file you would like to use: ";
  cin >> transFile;

  ifstream transFin; //transaction file
  transFin.open(transFile.data());

  if(!transFin) //the file doesn't exist -> exit
    {
      cout << "\nERROR: The file " << transFile << " doesn't exist!\n";
      return;
    }
  else
    {
      cout << "\nFile opened successfully!\n";
    }

  while(!transFin.eof()) //look at command and proceed to corresponding function with data
    {
      transFin >> command >> data;
      if(command == "AddW")
	{
	  AddAWord(data);
	}
      else if(command == "DeleteW")
	{
	  DeleteAWord(data);
	}
      else if(command == "SearchW")
	{
	  if(SearchForWord(data) == false) //determine if word exists and state result outside of inner functions
	      cout << "\nThe word '" << data << "' doesn't exist in the dictionary!\n";
	  else
	    cout << "\nThe word '" << data << "' exists in the dictionary.\n";
	}
      else if(command == "PrintF")
	{
	  PrintAFileInDict(data);
	}
      else if(command == "SpellCheck")
	{
	  SpellChecking(data);
	}
      else if(command == "InsertF")
	{
	  InsertWordsIntoDict(data);
	}
      else
	{
	  cout << "\nERROR: Command unknown!\n";
	}
    }

  transFin.close();
  return;
}

#endif
