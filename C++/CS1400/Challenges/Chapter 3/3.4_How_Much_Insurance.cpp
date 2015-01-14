/*Many financial experts advise property owners to insure their homes or 
buildings for at least 80 percent of the amount it would cost to replace 
the structure. Write a program that asks the user to enter the replacement 
cost of a building and then displays the minimum amount of insurance that 
should be purchased for the property.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float rCost = 0, percent = .8, percentCost = 0;

	cout << "\nWhat is the replacement cost of a building? ";
	cin >> rCost;

	percentCost = rCost * percent;

	cout <<"\nThe minimum you should pay on insurance is: " << percentCost << endl;

	return 0;
}