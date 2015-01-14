/*There are three seating categories at a stadium. For a softball game, Class A 
seats cost $15, Class B seats cost $12, and Class C seats cost $9. Write a 
program that asks how many tickets for each class of seats were sold, then 
display the amount of income generated from ticket sales. Format your dollar 
amount in a fixed-point notation with two decimal points and make sure the 
decimal point is always displayed.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float classA = 0, classB = 0, classC = 0, total = 0;

	cout << "\nHow many tickets would you like purchased for each class?\nClass A: ";
	cin >> classA;
	cout << "Class B: ";
	cin >> classB;
	cout << "Class C: ";
	cin >> classC;

	total = (classA * 15) + (classB * 12) + (classC * 9);

	cout << fixed << setprecision(2);
	cout << "You will have to pay $" << total << " dollars for that.\n";

	return 0;
}