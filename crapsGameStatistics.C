/*****************************************
Jonathan Leack
10/16/2013

Description: This program will play 100000 games of craps and calculate the probabilities of winning and losing per game.
****************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

  srand(time(0));
  const int NUM_GAMES = 100000;
  int die1; //the user's first die roll
  int die2; //the user's second die roll
  int firstRoll; //the user's total roll
  int additionalRolls;
  float win;
  float loss;
  char playing;

  for(int gameNumber = 1; gameNumber <= NUM_GAMES; gameNumber++)
    {       
      playing = 'y';    
      die1 = rand() % 6 + 1;
      die2 = rand() % 6 + 1;
      firstRoll = die1 + die2;
    if(firstRoll == 7 || firstRoll == 11)
    {	
      win = win + 1;	  
      playing = 'n';
    }
    else if(firstRoll == 2 || firstRoll == 3 || firstRoll == 12)
    {	  
      loss = loss + 1;
      playing = 'n';
    }
  
    while(playing == 'y')
    {    
      { 
      die1 = rand() % 6 + 1;
      die2 = rand() % 6 + 1;
      additionalRolls = die1 + die2;
      }	
      if(additionalRolls == firstRoll)
	{
          win = win + 1;
	  playing = 'n';
        }
      else if(additionalRolls == 7)
	{	   
          loss = loss + 1;
	  playing = 'n';
        }
     }   
    }

  cout << setw(6) << "win%" << setw(7) << "lose%" << endl;
  cout << fixed << setprecision(3) << setw(6) << (win / (win + loss)) * 100 << setprecision(3) << setw(7) << (loss / (win + loss)) * 100 << endl;
  cout << endl;

  return 0;
}
