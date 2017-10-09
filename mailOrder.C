/******************************
Jonathan Leack
11/7/2013

Description: This program will generate a receipt for a sale.
*****************************/
#include <iostream>
#include <iomanip>
using namespace std;

int getCustomerInfo(int &accountNum, int &saleMonth, int &saleDay, int &saleYear, char &countyCode);
void getItemsInfo(double &totalPrice, int &totalWeight);
double calcDiscount(int saleMonth);
float calcSalesTax(char countyCode);
double calcShipping(int totalWeight);
void outputInvoice(int accountNum,int saleMonth,int saleDay,int saleYear,char countyCode,double totalPrice,int totalWeight,double discount,float tax,double shipping);

int main()
{
  int accountNum;
  int saleMonth;
  int saleDay; 
  int saleYear; 
  char countyCode;
  double totalPrice;
  int totalWeight = 0;

  getCustomerInfo(accountNum,saleMonth,saleDay,saleYear,countyCode);
  if(totalPrice > 0)
    {
      getItemsInfo(totalPrice,totalWeight);
      double discount = calcDiscount(saleMonth);  
      float tax = calcSalesTax(countyCode);
      double shipping = calcShipping(totalWeight);
      outputInvoice(accountNum,saleMonth,saleDay,saleYear,countyCode,totalPrice,totalWeight,discount,tax,shipping);
    }
  else

  return 0;
}

int getCustomerInfo(int &accountNum, int &saleMonth, int &saleDay, int &saleYear, char &countyCode)
{
  cout << "Please enter your account number: ";
  cin >> accountNum;
  cout << "Please enter the month of sale: ";
  cin >> saleMonth;
  cout << "Please enter the day of sale: ";
  cin >> saleDay;
  cout << "Please enter the year of sale: ";
  cin >> saleYear;
  cout << "Please enter the county code ('S' for San Diego County, 'O' for Orange County and 'L' for LA county): ";
  cin >> countyCode;
}

void getItemsInfo(double &totalPrice, int &totalWeight)
{
  char order = 'Y';
  double price = 0;
  int weight = 0;

  cout << "Do you want to order an item? Enter Y or N: ";
  cin >> order;

  while(order == 'Y')
    {    	
	cout << "\tEnter a price: ";
        cin >> price;
        totalPrice = totalPrice + price;

        cout << "\tEnter a weight: ";
        cin >> weight;
        totalWeight = totalWeight + weight;	
     
        cout << "\tDo you want to order another item? Enter Y or N: ";
        cin >> order;
    }
}

double calcDiscount(int saleMonth)
{
  double discount = 0; 

  if(saleMonth >= 1 && saleMonth <= 5)
    discount = 0.05;
  else if(saleMonth >= 6 && saleMonth <= 8)
    discount = 0.10;
  else
    discount = 0.15;

  return discount;
}

float calcSalesTax(char countyCode)
{
  float tax = 0;

  if(countyCode == 'S')
    tax = 0.0775;
  else if(countyCode == 'O')
    tax = 0.0775;
  else
    tax = 0.0825;

  return tax;
}

double calcShipping(int totalWeight)
{
  double shipping = 0;

  if(totalWeight <= 25)
    shipping = 5.00;
  else if(totalWeight > 25 && totalWeight <= 50)
    shipping = 5.00 + ((totalWeight - 25) * 0.10);
  else
    shipping = 5.00 + (25 * 0.10) + ((totalWeight - 50) * 0.07);

  return shipping;
}

void outputInvoice(int accountNum,int saleMonth,int saleDay,int saleYear,char countyCode,double totalPrice,int totalWeight,double discount,float tax,double shipping)
{
  string county;


  if(countyCode == 'S')
    county = "San Diego";
  else if(countyCode == 'O')
    county = "Orange";
  else
    county = "Los Angeles";

  cout << setw(30) << left << "ACCOUNT NUMBER" << "COUNTY" << endl;
  cout << setw(30) << accountNum << county << endl;
  cout << endl;
  cout << "DATE OF SALE " << saleMonth << "/" << saleDay << "/" << saleYear << endl;
  cout << endl;
  cout << setw(18) << "TOTAL SALE AMOUNT:" << "$" << right << setw(8) << fixed << setprecision(2) << totalPrice << endl;
  cout << left << setw(18) << "DISCOUNT:" << "$" << right << setw(8) << fixed << setprecision(2) << (double)totalPrice * discount << endl;
  cout << left << setw(18) << "SALES TAX:" << "$" << right << setw(8) << fixed << setprecision(2) << ((float)totalPrice - ((float)totalPrice * discount)) * tax << endl;
  cout << left << setw(18) << "SHIPPING:" << "$" << right << setw(8) << fixed << setprecision(2) << shipping << endl;
  cout << left << setw(18) << "TOTAL DUE:" << "$" << right << setw(8) << fixed << setprecision(2) << totalPrice - ((double)totalPrice * discount) + (((float)totalPrice - ((float)totalPrice * discount)) * tax) + shipping << endl; 
}
