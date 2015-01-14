/*A movie theater only keeps a percentage of the revenue earner from ticket sales. 
The remainder goes to the distributor. Write a program that calculates a theater's 
gross and net box office profit for a night. The program should ask for the name of 
the movie, and how many adult and child tickets were sold. (The price of an adult 
ticket is $6.00 and a child's ticket is $3.00.) It should display a 
report similar to the following:

	Movie Name:					"Wheels of Fury"
	Adult Tickets Sold:				382
	Child Tickets Sold:				127
	Gross Box Office Profit:		$ 2673.00
	Amount Paid to distributor 	   -$ 2138.40
	Net Box Office Profit:			$ 534.60

Assume the theater keeps 20 percent of the gross box office profit.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	float adultPrice = 6.00, childPrice = 3.00, gross, profit, paid, percent = .2;
	int adultTic = 0, childTic = 0;
	string movieName;

	cout << "\nWhat is the movie name? ";
	getline(cin, movieName);
	cout << "How many adult tickets were sold? ";
	cin >> adultTic;
	cout << "How many child tickets were sold? ";
	cin >> childTic;

	gross = (adultTic * adultPrice) + (childTic * childPrice);
	paid = gross * percent;
	profit = gross - paid;

	cout << fixed << setprecision(2) << right;
	cout << "\n\n\tMovie Name: " 		<< setw(15) << movieName << endl;
	cout << "\tAdult Tickets: " 		<< setw(12) << adultTic << endl;
	cout << "\tChild Tickets: " 		<< setw(12) << childTic << endl;
	cout << "\tBox Office Gross: " 		<< setw(8) << "$ " <<gross << endl;
	cout << "\tPaid to Distributor: " 	<< setw(5) << "-$ " << paid << endl;
	cout << "\tNet Box Office Profit: " << setw(3) << "$ " << profit << endl;

	return 0;
}