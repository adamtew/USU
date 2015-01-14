/*An International Internet phone company has three different substription packages
for its customers:

	Package A: 	For $9.95 per month 5 hours of call time are provided. Additional
				usagecosts $0.08 per minute.

	Package B:	For $14.95 per month 10 hours of call time are provided. Additional
				usage costs $0.06 per minute.

	Package C:	For $19.95 per month unlimited call time is provided.

Write a program that calculates acustomer's monthly bill. It should input customer
name, which package the customer has purchased, and how many hours were used. It 
should then create a bill that includees the input information and the total amount
due. Wherever possible use named constants instead of numbers.

	Input Validation: Be sure the user only selects package A, B, or C.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	const float aCost = 9.95, bCost = 14.95, cCost = 19.95, 
				aRate = .08, bRate = .06;
	const int aTime = 300, bTime = 600;
	int minutes = 0; 
	char package;
	string name = "No input";
	float bill, hours;

	cout << "\n***********************************";
	cout << "\nInternet Service Provider Part 1";
	cout << "\n***********************************";
	cout << "\n\n\t------------------------------";
	cout << "\n\t|Package      Monthly Cost   |";
	cout << "\n\t------------------------------";
	cout << "\n\t|  a)               $ 9.95   |";
	cout << "\n\t|  b)               $14.95   |";
	cout << "\n\t|  c)               $19.95   |";
	cout << "\n\t------------------------------";
	cout << "\n\n\tName: ";
	getline(cin, name);
	
	cout << "\tPackage: ";
	cin >> package;
	if(package != 'a' && package != 'b' && package != 'c')return 0;
	
	cout << "\tMinutes Used: ";
	cin >> minutes;
	hours = minutes / 60;
	if(minutes < 0)return 0;
	
	switch(package){
		case 'a': 
			if(aCost < aCost + ((minutes - aTime) * aRate))
				bill = aCost + ((minutes - aTime) * aRate);
			else
				bill = aCost;
			break;
		case 'b': 
			if(bCost < bCost + ((minutes - aTime) * aRate))
				bill = bCost + ((minutes - bTime) * bRate);
			else
				bill = bCost;
			break;
		case 'c': bill = cCost;
			break;
		default:
			break;
	}

	cout << right << fixed << setprecision(1);
	cout << "\n\n\t---------------------------";
	cout << "\n\t| Internet Bill           |";
	cout << "\n\t---------------------------";
	cout << "\n\t| Customer: " << setw(13) << name << " |";
	cout << "\n\t| Package: " << setw(14) << package << " |";
	cout << "\n\t| Hours: " << setw(16) << hours << " |" << setprecision(2);
	cout << "\n\t| Total: " << setw(10) << right << "$" << setw(6) << bill <<  " |";
	cout << "\n\t---------------------------\n\n";
	return 0;
}