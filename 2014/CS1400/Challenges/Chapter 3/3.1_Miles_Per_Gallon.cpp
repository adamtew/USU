/*Write a program that calculates a car's gas mileage. The program should ask 
the user to enter the number of gallons of gas the car can hold and the number 
of miles it can be driven on a full tank. It should then calculate and display 
the number of miles per gallon the car gets.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int galOfGas = 0, numOFMiles = 0, mpg = 0;


	cout << "\nHow many gallons of gas can your car hold? ";
	cin >> galOfGas;

	cout << "\nHow many miles can your car drive on a full tank? ";
	cin >> numOFMiles;

	mpg = numOFMiles / galOfGas;

	cout << "\nLooks like your car gets " << mpg << " miles per gallon.\n";

	return 0;
}