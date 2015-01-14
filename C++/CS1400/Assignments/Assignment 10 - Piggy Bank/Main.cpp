//driver program for PigyBank assignment
//D. Watson  10/24/2014
//
// MAKE NO CHANGES TO THIS FILE
// TO TEST YOUR ASSIGNMENT
//
/*

Expected output from this driver program:

myBank has $0.
yourBank has $1.25.
myBank has $100.34.
myBank has $100.35.
myBank has $100.36.
myBank has $100.37.
myBank has $100.38.
myBank has $100.38.
yourBank has $1.25.
myBank has $0.
yourBank has $1.25.
Noooooooooooo!

*/
#include <iostream>
#include "PiggyBank.h"

using namespace std;

int main(){
	//make some piggy banks
	PiggyBank myBank;
	PiggyBank yourBank(1.25, false);
	
	//print the contents of the banks
	cout << "myBank has $" << myBank.countSavings() << ".\n";
	cout << "yourBank has $" << yourBank.countSavings() << ".\n";

	
	//add some money to myBank
	myBank.depositMoney(100.34);

	//print the contents of myBank
	cout << "myBank has $" << myBank.countSavings() << ".\n";

	//add some money to myBank
	myBank.depositMoney(.01);
	//print the contents of myBank
	cout << "myBank has $" << myBank.countSavings() << ".\n";

	//add some money to myBank
	myBank.depositMoney(.01);
	//print the contents of myBank
	cout << "myBank has $" << myBank.countSavings() << ".\n";

	//add some money to myBank
	myBank.depositMoney(.01);
	//print the contents of myBank
	cout << "myBank has $" << myBank.countSavings() << ".\n";

	//add some money to myBank
	myBank.depositMoney(.01);
	//print the contents of myBank
	cout << "myBank has $" << myBank.countSavings() << ".\n";

	//print the contents of the banks
	cout << "myBank has $" << myBank.countSavings() << ".\n";
	cout << "yourBank has $" << yourBank.countSavings() << ".\n";

	//smash my bank
	myBank.smash();

	//print the contents of the banks
	cout << "myBank has $" << myBank.countSavings() << ".\n";
	cout << "yourBank has $" << yourBank.countSavings() << ".\n";

	//destructor should output "Nooooo!" for only the broken bank
	
	return 0;
}
