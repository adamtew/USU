//Write a program that computes the tip on a restaurant bill for a patron with a 
//$44.50 meal charge. The tax should be 6.75 percent of the meal cost. 
//The tip should be 15 percent of the total after adding the tax. 
//Display the meal cost, tax amount, tip amount, and total bill on the screen.
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float meal = 44.5, tax = meal * .0675, tip = (meal + tax) * .15; 
	float bill = meal + tax + tip;

	cout <<"\nThe meal cost: " << meal << " dollars";
	cout <<"\nWhich mean you pay " << tax << " dollars in taxes.";
	cout <<"\nThis means your tip will be " << tip << "dollars.";
	cout <<"\nMaking your total bill come out to " << bill << " dollars.\n";

	return 0;
}