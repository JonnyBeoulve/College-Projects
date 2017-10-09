/***********************************
Jonathan Leack
11/2/2013

Description: This program will use a two dimensional array to capture information from the user and display it.
**********************************/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  const int NUM_MONKEYS = 3;
  const int NUM_DAYS = 7; 
  int monkey = 0;
  int day = 0;
  int entered_value;
  int foodEaten[NUM_MONKEYS][NUM_DAYS];
  double avgDay = 0; 
  int highest = 0; 
  int lowest = 999999;

  for(int monkeyNum = 0;monkeyNum < NUM_MONKEYS;monkeyNum++)
    {    
    cout << "Enter the number of pounds Monkey " << monkeyNum + 1 << " ate each day\n";
    for(int dayNum = 0;dayNum < NUM_DAYS;dayNum++)
      {  
        do    
	  {        
            cout << "Day " << dayNum + 1 << ": ";
            cin >> foodEaten[monkeyNum][dayNum];
	  }
        while(foodEaten[monkeyNum][dayNum] < 0);
	cout << endl;
      }
    }

  for(int dayNum = 0;dayNum < NUM_DAYS;dayNum++)
    {
      for(int monkeyNum = 0;monkeyNum < NUM_MONKEYS;monkeyNum++)
        {
          if(foodEaten[monkeyNum][dayNum] < lowest)
            lowest = foodEaten[monkeyNum][dayNum];
        }
    }

  for(int dayNum = 0;dayNum < NUM_DAYS;dayNum++)
    {
      for(int monkeyNum = 0;monkeyNum < NUM_MONKEYS;monkeyNum++)
        {
          if(foodEaten[monkeyNum][dayNum] > highest)
            highest = foodEaten[monkeyNum][dayNum];
	}
    }

  cout << left << setw(3) << "Day" << right << setw(24) << "Average pounds" << endl;;

  for(int dayNum = 0;dayNum < NUM_DAYS;dayNum++)
    {    
      int totalDay = 0;
    for(int monkeyNum = 0;monkeyNum < NUM_MONKEYS;monkeyNum++)
      {     
        totalDay = totalDay + foodEaten[monkeyNum][dayNum];
      }
    avgDay = (double)totalDay / 3;
    cout << left << setw(3) << dayNum + 1 << fixed << setprecision(2) << right << setw(24) << avgDay << endl; 
    }
 
  cout << "The least amount ate is " << lowest << endl;
  cout << "The largest amount ate is " << highest << endl;
 
  return 0;
}
