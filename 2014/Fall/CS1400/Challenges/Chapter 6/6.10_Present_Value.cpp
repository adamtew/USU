/*Suppose you want to deposit a certain amount of money into a savings account and
 then leave it alone to draw interest for the next 10 years. At the end of 10 years 
 you would like to have $10,000 in the account. How much do you need to deposit today to make that happen? To find out you can use the following formula, which is known as the present value formula:

	P = F/(1 + r)^n

	The terms in the formula are as follows:

	 • P is the present value, or the amount that you need to deposit today.
	 • F is the future value that you want in the account (in this case, $10,000).
	 • r is the annual interest rate (expressed in decimal form, such as .042).
	 • n is the number of years that you plan to let the money sit in the account.

 Write a program with a function named presentValue that performs this calculation.
 The function should accept the future value, annual interest rate, and number of
 years as arguments. It should return the present value, which is the amount that you 
 need to deposit today. Demonstrate the function in a program that lets the user
 experiment with different values for the formula's terms.*/
 // Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void printTitle();
double presentValue(double, double, int);

 int main(){
 	double F, r;
 	int n;

 	printTitle();

 	cout << "\n\n\tEnter a future value you want, the going interest rate, and";
 	cout << "\n\tthe number years you have to wait and I'll tell you how much";
 	cout << "\n\tmoney you'll need to deposit now to make it happen.";
 	cout << "\n\n\tFuture value: ";
 	cin >> F;
 	cout << "\tInterest rate: ";
 	cin >> r;
 	cout << "\tNumber of years: ";
 	cin >> n;

 	cout << fixed << setprecision(2);
 	cout << "\n\tThat will take $" << presentValue(F,r,n) << " up-front.\n";

 	return 0;
 }


 void printTitle(){

 	cout << "\n*****************";
 	cout << "\nPresent Value   |";
 	cout << "\n*****************";

 }

double presentValue(double F, double r, int n){
	double P;
	r = r / 100;
	P = F / pow((1 + r),n);

	return P;
}