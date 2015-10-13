/*Write a program that alculates the balance of a savings account at the end of a
three-month period. It should ask the user for the starting balance and the annual
interest rate. A loop should then iterate once for every month in the period, 
performing the following steps:
	A) Ask the user for the total amount deposited into the account during that month
		and add it to the balance. Do not accept negative numbers.
	B) Ask the user for the total cmound withdrawn from the account during that month
		and subtract it from the balance. Do not accept negative numbers or numbers
		greater than the balance after the deposits for the month have been added in.
	c) Calculate the interest for that month. The monthly interest rate is the annual
		interest rate divided by 12. Multiply the monthly interest rate by the average
		of that month's starting and ending balance to get the interest amount for
		the month. This amount should be added to the balance.

After the last iteration, the program should display a report that includes the 
following information:

	• Starting balance at the beginning of the three-month period
	• Total deposits made during the three months
	• Total withdrawals made during the three months
	• Total interest posted to the account during the three months
	• Final balance	*/
// Adam Tew ---- CS1400
#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double 	startBal, finalBal = 0, 
			annualInt, monthlyInt, finalInt = 0,
			deposit, deposits = 0,
			withdrawl, withdrawls = 0;

	cout << "\n***************************";
	cout << "\nSavings Account Balance   |";
	cout << "\n***************************";

	cout << "\n\n\tEnter the starting balance of your bank account, the annual";
	cout << "\n\tinterest rate, and then the amount deposited each month for a";
	cout << "\n\tthree-month period.";

	cout << "\n\n\tStarting Balance: ";
	cin >> startBal;
	cout << "\tAnnual Interest: ";
	cin >> annualInt;
	annualInt = annualInt / 100;
	monthlyInt = (annualInt / 12);

	for(int i = 0; i < 3; i++){
		cout << "\tThis month's deposit: ";
		cin >> deposit;
		while(deposit < 0){
			"\tEnter a value greater than 0: ";
			cin >> deposit;
		}
		deposits += deposit;

		cout << "\tThis month's withdrawals: ";
		cin >> withdrawl;
		while(withdrawl < 0 || withdrawl > startBal){
			"\tEnter a value greater than 0: ";
			cin >> withdrawl;
		}
		withdrawls += withdrawl;
		finalInt += monthlyInt * (startBal + (deposits - withdrawls / 2));
		cout << "\n\n\tfinalInt: " << finalInt; 
	}

	finalBal = startBal + deposits - withdrawls + finalInt;

	cout << fixed << setprecision(2);
	cout << "\n\tStarting Balance: " 	<< setw(7) << startBal;
	cout << "\n\tTotal Deposits: " 		<< setw(9) << deposits;
	cout << "\n\tTotal Withdrawls: "	<< setw(7) << withdrawls;
	cout << "\n\tTotal Interest: "		<< setw(9) << finalInt;
	cout << "\n\tFinal Balance: "		<< setw(10) << finalBal;

	cout << endl;

	return 0;
}