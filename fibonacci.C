#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int determineIfFibonacci(int num);
int fibonacci(int n);
int getNum(int num);
int gcd(int x, int y);

int main()
{
  int x = 54;
  int y = 6;
  int val = gcd(x, y);
  cout << val << endl;

  /*  bool match; //bool for fibonacci maching
  int num = getNum(num); //requests num from user

  while(num >= 0) //negative int exits loop
    {
      match = determineIfFibonacci(num);
      if(match == true)
	cout << "Yes, you got it, '" << num << "' is a Fibonacci number!" << endl;
      else
	cout << "!!!!! Sorry, '" << num << "' is not a Fibonacci number." << endl;
      num = getNum(num);
    }	     
 
    cout << "(*Thanks - Have a Good Day*)\n"; */

  return 0;
}

int getNum(int num)
{
  cout << "Please enter a number (enter a negative number to quit): ";
  cin >> num;

  return num;
}

int determineIfFibonacci(int num)
{
  int fib;

  for(int n = 0; true; n++)
    {
    fib = fibonacci(n);
    if(fib == num)
      return true;
    else if(fib > num)
      return false;
    }
  return false;
}

int fibonacci(int n)
{
  int value;
  
  if(n <= 1) //if 1, don't proceed
    return n; 
  else
    value = fibonacci(n - 1) + fibonacci(n - 2); //recursion  

  return value;
}

int gcd(int x, int y)
{
  if(y == 0)
    return x;
  else
    return gcd(y, x % y);
}
