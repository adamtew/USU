/*A bank charges $10 per month plus the following check fees for a commercial
checking account:

	$.10 each for fewer than 20 checks
	$.08 each for 20-39 checks
	$.06 each for 40-59 checks
	$.04 each for 60 or more checks

Write a program that asks for the number of checks written during the past month,
then computes and displays the bank's fees for the month.

	Input Validation: Decide how the program should handle an input of less than 0*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	const int charge = 10;
	int checks = 0, switched = 0;
	float fee, cost;

	cout << "\n\tHow many checks were written during the past month? ";
	cin >> checks;

	if(checks > 0 && checks < 20)switched = 1;
	if(checks >= 20 && checks < 40)switched = 2;
	if(checks >= 40 && checks < 60)switched = 3;
	if(checks >= 60)switched = 4;

	switch(switched){
		case 1:
			fee = .10;
			cost = (checks * fee) + charge;
			cout << "\n\tYour checking account cost $" << cost << " this month\n";
			break;
		case 2:
			fee = .08;
			cost = (checks * fee) + charge;
			cout << "\n\tYour checking account cost $" << cost << " this month\n";
			break;
		case 3:
			fee = .06;
			cost = (checks * fee) + charge;
			cout << "\n\tYour checking account cost $" << cost << " this month\n";
			break;
		case 4:
			fee = .04;
			cost = (checks * fee) + charge;
			cout << "\n\tYour checking account cost $" << cost << " this month\n";
			break;
	}

	return 0;
}