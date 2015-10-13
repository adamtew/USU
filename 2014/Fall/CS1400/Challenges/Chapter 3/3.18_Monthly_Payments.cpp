/*The monthly payment on a loan may be calculated by the following formula:

	Payment = ((Rate * (1 + Rate)^N) / ((1 + Rate)^N - 1)) * L

Rate is the monthly interest rate, which is the annual interest rate divided by 12.
(A 12 percent annual interest would be 1 percent monthly interest.) N is the number
of payments and L is the amount of the loan. Write a program that asks for these
values and displays a report similar to the following:

	Loan Amount:			$ 10000.00
	Monthly Interest Rate:	        1%
	Number of Payments:		        36
	Monthly Payment:		$   332.14
	Amount Paid Back:		$ 11957.15
	Interest Paid:			$  1957.15*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	float annualRate = 0, monthlyRate, N = 0, L = 0, monthlyPay, totalPay, intPaid;

	cout << "\nWhat is the total loan amount? ";
	cin >> L;
	cout << "What is the annual interest rate? ";
	cin >> annualRate;
	cout << "What is the number of payments? ";
	cin >> N;

	monthlyRate = annualRate / 12;
	monthlyRate = monthlyRate * .01;
	monthlyPay = ((monthlyRate * pow((1 + monthlyRate), N)) / (pow(1 + monthlyRate, N) -1)) * L;
	totalPay = monthlyPay * 36;
	intPaid = totalPay - L;
	monthlyRate = monthlyRate * 100;

	cout << fixed << setprecision(2);
	cout << "\n\n\t------------------------------------------";
	cout << "\n\tLoan Amount:" << setw(15) << "$ " << setw(10) << L;
	cout << "\n\tMonthly Interest Rate:" << setw(14) << right << monthlyRate << "%";
	cout << "\n\tNumber of Payments:" 	<< setw(18) 
		<< setprecision(0) << N << setprecision(2);
	cout << "\n\tMonthly Payment"		<< setw(12) << "$ " << setw(10) 
		<< monthlyPay;
	cout << "\n\tAmount Paid Back:"		<< setw(10) << "$ " << setw(10)
		<< totalPay;
	cout << "\n\tInterest Paid:"		<< setw(13) << "$ " << setw(10)
		<< intPaid;
	cout << "\n\t-------------------------------------------\n\n";


	return 0;
}