/*****************************************
Jonathan Leack

Description: This program will generate an electric bill from input information.
*****************************************/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  int month; //the month
  int currentReading;
  int previousReading;
  int consumed;

  //the program will request the month from the user
  cout << "Enter the month: ";
  cin >> month;

  //the program will now generate an electric bill
  if(month <= 0 || month >= 12)
    cout << "Invalid month" << endl;
  else
    {
      cout << "Enter the current meter reading: ";
      cin >> currentReading;
      cout << "Enter the previous meter reading: ";
      cin >> previousReading;
     
      //calculate the difference 
      consumed = currentReading - previousReading;
      //determine price range  
      if(currentReading >= previousReading)
	{
	  if(consumed > 400)
	    {
	      if(month >= 5 && month <=9)	    
		{  
		  cout << "You consumed " << consumed << " and your amount due is " << setw(1) << "$" << fixed << setprecision(2) << (consumed - 400) * 0.07525 + 8.505 << endl;
		}
	      else
		{
		  cout << "You consumed " << consumed << " and your amount due is " << setw(1) << "$" << fixed << setprecision(2) << (consumed - 400) * 0.06575 + 8.505 << endl;
		}
	    }
	  else
	    {
	      cout << "You consumed " << consumed << " and your amount due is " << setw(1) << fixed << setprecision(2) << "$" << 8.5 << endl;
	    }	
        }
      else
	{
	  cout << "The readings are invalid" << endl;   
        }
    }

  return 0;
}
