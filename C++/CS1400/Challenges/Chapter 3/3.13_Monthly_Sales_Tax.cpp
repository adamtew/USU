/*A retail company must file a monthly sales tax report listing the sales for the 
month and the amount of sales tax collected. Write a program that asks for the 
month, the year, and the total amount collected at the cash register (that is,
sales plus sales tax). Assume the state sales tax is 4 percent and the county
sales tax is 2 percent.

If the total amount collected is known and the total sales tax is 6 percent, the
amount of product sales may be calculates as 

							S = T/1.06

Where S is the product sales and T is the total income (product sales plus sales tax).

The program should display a report similar to the following:

	Month: March 2008
	-------------------
	Total Collected:	$ 26572.89
	Sales:				$ 25068.76
	County Sales Tax:	$   501.38
	State Sales Tax:	$  1002.75
	Total Sales Tax:	$  1504.13*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	string month, year;
	float cash = 0, stateTax = .04, countyTax = .02, tax = .06, 
		taxed = 0, productSales = 0, sales = 0;

	cout << "\nWhat is the month? ";
	getline(cin, month);
	cout << "What is the year? ";
	getline(cin, year);
	cout << "How much cash was collected? ";
	cin >> cash;

	productSales = cash / 1.06;

	cout << fixed << setprecision(2);
	cout << "\n\n\tMonth: " << month << " " << year;
	cout << "\n\t--------------------";
	cout << "\n\tTotal Collected:" << setw(6) <<  "$ " << cash;
	cout << "\n\tSales:"			<< setw(16) << "$ " << productSales;
	cout << "\n\tCounty Sales Tax:" << setw(5) << "$ " << countyTax * cash;
	cout << "\n\tState Sales Tax:" 	<< setw(6) << "$ " << stateTax * cash;
	cout << "\n\tTotal Sales Tax:" 	<< setw(6) << "$ " << tax * cash << endl;

	return 0;
}