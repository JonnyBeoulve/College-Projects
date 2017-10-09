/***********************************
Jonathan Leack
2/18/2014

Description: This program will allow the user to either encrypt or decrypt a file. Either rot
or cryptogram can be utilized per the user's choice. In the case of rot, an encryption key
can be specified.
***********************************/
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

char cryptionChoice();
char cryptionType(char cryption);

class security
{
private:
  int rotNum; //rot encryption key input by user
  string code; //cryptogram key obtained from file
  vector<string> vCodedWord; //vector containing all post encrypt or decrypt operation words from file
public:
  string word; //string used for encryption or decryption before vector input
  vector<string> vUncodedWord; //vector containing all pre encrypt or decrypt operation words
  void rotNumChoice();
  void encryptWithRot();
  void encryptRotWord();
  void decryptWithRot();
  void decryptRotWord();
  void encryptWithCrypto();
  void encryptCryptoWord();
  void getACode();
  void decryptWithCrypto();
  void decryptCryptoWord();
};
security s; //create security member s

int main()
{
  char cryption = cryptionChoice(); //determine if user wants to encrypt or decrypt
  char type = cryptionType(cryption); //determine if user wants to use rot or cryptogram encryption/decryption

  if(type == 'r') //rot encryption/decryption
    {  
      s.rotNumChoice(); //determine number for rot encryption(user selected)
    
      if(cryption == 'e')
	{
	  s.encryptWithRot();
	  cout << "Your file has been encrypted with rot and has been stored in encrypt01.txt" << endl; 
	}
      else if(cryption == 'd')
	{
	  s.decryptWithRot();
          cout << "Your file has been decrypted from rot and has been stored in decrypt01.txt" << endl;
	}
    }

  if(type == 'c') //cryptogram encryption/decryption
    {
      if(cryption == 'e')
	{
	  s.encryptWithCrypto();
          cout << "Your file has been encrypted with cryptogram and has been stored in encrypt02.txt" << endl;
	}
      else if(cryption == 'd')
	{
	  s.decryptWithCrypto();
          cout << "Your file has been decrypted from cryptogram and has been stored in decrypt02.txt" << endl;	
        }
    }

  return 0;
}
  
char cryptionChoice()
{
  char cryption; //user's cryption type choice
  bool entered = false; //forces a valid character entry

  while(entered == false) //while no valid option has been selected(d or e)
    {
    cout << "Please enter 'e' for encryption or 'd' for decryption: ";
    cin >> cryption; 
        
    if(cryption == 'd' || cryption == 'e') //if valid input, then exit function
      {       
	entered = true;
      }
    else
      {
	cout << "ERROR: You must enter a 'd' or 'e'!" << endl; //shows error and lets user enter a new key
      }
    }   

  return cryption;
}

char cryptionType(char cryption)
{
  char type; //user's choice to employ either rot or cryptogram
  bool entered = false; //forces a valid character entry

  if(cryption == 'e') //encryption
    {
      cout << "Are you looking to encrypt using rot or cryptogram? Please enter 'r' for rot or 'c' for cryptogram: ";
      cin >> type;    
     
      while(entered == false)
	{
          if(type == 'r' || type == 'c') //determine if a proper character was entered
	    {
	      entered = true;
	    }
          else
	    {
	      cout << "ERROR: You must enter a 'r' or 'c'!" << endl; //request re-entry if disqualified
	      cout << "Please enter 'r' for rot or 'c' for cryptogram: ";
	      cin >> type;
            }
        }
    }
  else if(cryption == 'd') //decryption
    {
      cout << "Are you looking to decrypt a rot or cryptogram file? Please enter 'r' for rot or 'c' for cryptogram: ";
      cin >> type;      

      while(entered == false)
        {
          if(type == 'r' || type == 'c') //determine if a proper character was entered
	    {
	      entered = true;
	    }
          else
	    {
	      cout << "ERROR: You must enter a 'r' or 'c'!" << endl; //request re-entry if disqualified
	      cout << "Plese enter 'r' for rot or 'c' for cryptogram: ";
	      cin >> type;
	    }
       }
    }

  return type;
}

void security::rotNumChoice() 
{
  bool entered = false; //force a valid number entry (1-26)

  while(entered == false) //repeat until valid number is entered
    {
      cout << "Please enter the encryption key number: ";
      cin >> rotNum;

      if(rotNum >= 1 && rotNum <= 26)
	{
	  entered = true; //exit function
	}
      else
	{
	  cout << "ERROR: You must enter a value between 1 and 26!" << endl; //show error and allow user re-entry
	}
    }
}

void security::encryptWithRot()
{
  ifstream fin; //source file
  fin.open("original.txt");

  ofstream fout; //destination file
  fout.open("encrypt01.txt");
  
  int count = 0; //counts the total number of words in user's file

  while(fin>>word) //while there are letters left in the file
   {
     vUncodedWord.push_back(word); //inserts words into vector
     count++;
   }

  for(int index = 0; index < count; index++)
    {
      word = vUncodedWord[index]; //move vector into word string  
      s.encryptRotWord(); //encrypt word using rot with user entered value
    }
   
  for(int index = 0; index < count; index++)
    { 
      fout << vCodedWord[index] << " "; //moves encrypted word to destination file with spaces between words
    }

  fin.close();
  fout.close();
}

void security::encryptRotWord()
{
  for(int i = 0; i < word.size(); i++) //lasts for character length of word
    {
      char ch = word[i];
      ch = tolower(ch);
      if((ch >= 97) && (ch <= 122)) //determine if within alphabet in ascii value
	{
	  int K = (int)ch;
	  K = K + rotNum; //add encryption key number that was input by user
	  if(K > 122) //determine if rotNum addition has pushed it outside the a-z range
	    {
	      K = (K - 71) % 26;
	      K = K + 97;
	    }
	  word[i] = (char)K; //move encrypted letter into index slot
	}
    }

  vCodedWord.push_back(word); //push encrypted word into vector
}

void security::decryptWithRot()
{
  ifstream fin; //source file
  fin.open("encrypt01.txt");

  ofstream fout; //destination file
  fout.open("decrypt01.txt");

  int count = 0; //counts the total number of words

  while(fin>>word) //while there are letters left in the file
    {
      vUncodedWord.push_back(word); //inserts words into vector
      count++;
    }

  for(int index = 0; index < count; index++)
    {
      word = vUncodedWord[index]; //move vector into word string
      s.decryptRotWord(); //decrypt word using rot with user entered value
    }

  for(int index = 0; index < count; index++)
    {
      fout << vCodedWord[index] << " "; //moves decrypted word to destination file with spaces between words
    }

  fin.close();
  fout.close();
}

void security::decryptRotWord()
{

  for(int i = 0; i < word.size(); i++) //lasts for length of word
    {
      char ch = word[i];
      ch = tolower(ch);
      if((ch >= 97) && (ch <= 122)) //determine if within alphabet in ascii value
        {
          int K = (int)ch;
          K = K - rotNum;
          if(K < 122) //determine if rotNum addition has pushed it outside the a-z range
            {
              K = (K - 45) % 26;
              K = K + 97; //brings alphabet letter number up to ascii value
            }
          word[i] = (char)K; //moves decrypted letter to index
        }
    }

  vCodedWord.push_back(word); //pushes decrypted word to vector
}

void security::encryptWithCrypto()
{
  s.getACode(); //move cryptogram file code to code string

  ifstream fin; //source file
  fin.open("original.txt");

  ofstream fout; //destination file
  fout.open("encrypt02.txt");

  int count = 0; //counts the total number of words

  while(fin>>word) //while there are letters left in the file
    {
      vUncodedWord.push_back(word); //inserts words into vector
      count++;
    }

  for(int index = 0; index < count; index++)
    {
      word = vUncodedWord[index]; //move vector into word string
      s.encryptCryptoWord(); //encrypt word using cryptogram with cryptogram.txt code
    }

  for(int index = 0; index < count; index++)
    {
      fout << vCodedWord[index] << " "; //moves encrypted word to destination file with spaces between words
    }

  fin.close();
  fout.close();
}

void security::encryptCryptoWord()
{
  for(int i = 0;i < word.size();i++) //lasts duration of word length
    {
      char c = tolower(word[i]);
      if((c >= 97) && (c <= 122)) //if value is within a -> z ascii value range
	{
	  int index = c - 97; //drop ascii value down to alphabet range for input index
	  word[i] = code[index];
	}
    }

  vCodedWord.push_back(word); //push encrypted word to vector
}

void security::decryptWithCrypto()
{
  s.getACode(); //move cryptogram file code to code string

  ifstream fin; //source file
  fin.open("encrypt02.txt");

  ofstream fout; //destination file
  fout.open("decrypt02.txt");

  int count = 0; //counts the total number of words

  while(fin>>word) //while there are letters left in the file
    {
      vUncodedWord.push_back(word); //inserts words into vector
      count++;
    }

  for(int index = 0; index < count; index++)
    {
      word = vUncodedWord[index]; //move vector into word string
      s.decryptCryptoWord(); //decrypt word using cryptogram with cryptogram.txt code
    }

  for(int index = 0; index < count; index++)
    {
      fout << vCodedWord[index] << " "; //moves decrypted word to destination file with spaces between words
    }

  fin.close();
  fout.close();
}

void security::decryptCryptoWord()
{
  for(int i = 0;i < word.size();i++) //lasts for duration of word length
    {
      char c = tolower(word[i]);
      if((c >= 97) && (c <= 122)) //if letter is within ascii value range
        {
	  for(int index = 0;index < 26;index++) //loops through alphabet range
	    {
	      if(word[i] == code[index]) //if character is same as index value in cryptogram file...
		{
		  word[i] = char(index + 97); //set decrypted character to alphabet value
		  index = 26; //force loop exit
                }
	    }
        }
    }

  vCodedWord.push_back(word); //pushes decrypted word to vector
}

void security::getACode()
{
  ifstream fileCrypto;
  fileCrypto.open("cryptogram.txt"); //cryptogram file with changed values allocated for a -> z

  fileCrypto >> code; //move cryptogram key to code member in security class

  fileCrypto.close();
}
