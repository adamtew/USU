/*Assuming there are no deposits other than the original investment, the balance in a
savings account after one year may be calculated as

	Amount = Principal * (1 + Rate/Time) ^ T

Where Principal is the balance in the account, Rate is the annual interest rate, and T
is the number of times the interest rate compounded during a year (e.g., T is 4 if the
interest is compounded quarterly).

Write a program that asks for the principal, the interest rate, and the number of 
times the interest is compounded. It should display a report similar to the following:

	Interest Rate:				 4.25%
	Times Compounded:				12
	Principal:				$  1000.00
	Interest:				$    43.33
	Final Balance:			$  1043.33*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	float principal = 0, intRate = 0, comp = 0, intpaid, finalBal;

	cout << "\nWhat is the principal? ";
	cin >> principal;
	cout << "What is the percent interest rate? ";
	cin >> intRate;
	cout << "How many times is the interest compounded? ";
	cin >> comp;

	intRate = intRate * .01;	
	finalBal = principal * pow((1 + (intRate / comp)), comp);
	intpaid = finalBal - principal;
	intRate = intRate * 100;

	cout << fixed << setprecision(2);
	cout << "\n\n\t----------------------------\n";
	cout << "\tInterest Rate:" 		<< setw(13) << intRate << "%";
	cout << "\n\tTimes Compounded:" << setw(11) 
		<< setprecision(0) << comp << setprecision(2);
	cout << "\n\tPrincipal"  		<< setw(12) << "$ " << right << principal;
	cout << "\n\tInterest:" 		<< setw(14) << " $ " << right << intpaid;
	cout << "\n\tFinal Balance:" 	<< setw(7) << "$ " << right << finalBal;
	cout << "\n\t----------------------------\n\n";

	return 0;
}