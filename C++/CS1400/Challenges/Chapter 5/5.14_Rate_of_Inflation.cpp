/*The annual rate of inflation is the rate at which money loses its value. For 
example, if the annual rate of inflation is 3.0%, then in one year it will cost
$1030 to buy the goods that could have been purchased for $1000 today. Put another
way, a year from now $1000 will only buy 1/1.03 * $1000, or $970.87, worth of goods.
Write a program that allows the user to enter an annual rate of inflation between
1% and 15%, and which then reports how much $1000 today will be worth each year for
the next 10 years.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float iRatePercent, iRate;
	double value = 1000;

	cout << "\n*********************";
	cout << "\nRate of Inflation   |";
	cout << "\n*********************";

	cout << "\n\nEnter an inflation rate between 1 and 15%";
	cout << "\nInflation Rate: ";
	cin >> iRate;
	while(iRate < 1 || iRate > 15){
		cout << "Enter an inflation rate between 1% and 15%";
		cout << "\nInflation Rate: ";
		cin >> iRate;
	}

	iRatePercent = iRate / 100;
	cout << fixed << setprecision(2);
	cout << "\n\t-------------------------------------";
	cout << "\n\tYear\tValue of $1,000  at " << iRate << "%";
	cout << "\n\t-------------------------------------";
	for(int i = 1; i < 11; i++){
		value = (1/(1 + iRatePercent)) * value;
		cout << "\n\t" << i << "\t\t$" << value;
	}

	cout << endl;

	return 0;
}