/*A car holds 16 gallons of gasoline and can travel 350 miles before refueling. 
Write a program that calculates the number of miles per gallon the car gets. 
Display the result on the screen.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int gallons = 16, miles = 350;
	float mpg = miles / gallons;

	cout << "\nThe car get " << mpg << " miles per gallon\n";

	return 0;
}