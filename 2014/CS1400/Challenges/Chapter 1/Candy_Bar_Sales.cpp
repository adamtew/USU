//Write a program that calculates how much a student organization earns
//during its fund raising candy sale. The program should prompt the user
//to enter the number of candy bars sold and the amount the organization earns for
//each bar of sold. It should then calculate and display the total amount earned.
// Adam Tew ---- CS1400
#include <iostream>

using namespace std;

int main(){
	int bars;
	float cost, total; 

	cout << "\nHow many candy bars were sold? ";
	cin >> bars;

	cout << "\nHow much was each bar worth? (In dollars) ";
	cin >> cost;

	total = cost * bars;

	cout << "\nLooks like you made " << total << " dollars in profit.\n";

	return 0;
}