/*Create a change-counting game that asks the user to enter what coins to use to make
exactly one dollar. The program should ask the user to enter the number of pennies,
nickels, dimes, and quarters. If the total value of the coins entered is equal
to on dollar, the program should congratulate the user for winning the game.
Otherwise, the program should display a message indicating where the amount was
more or less than one dollar. Use constant variables to hold the coing values.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	const float penny = .01, nickel = .05, dime = .10, quarter = .25;
	int numPen = 0, numNic = 0, numDim = 0., numQua = 0;
	float total;

	cout << "\n\tHow close to a dollar can you get?";
	cout << "\n\tPennies:  ";
	cin >> numPen;
	cout << "\tNickels:  ";
	cin >> numNic;
	cout << "\tDimes:    ";
	cin >> numDim;
	cout << "\tQuarters: ";
	cin >> numQua;

	total += (numPen * penny);
	total += (numNic * nickel);
	total += (numDim * dime);
	total += (numQua * quarter);

	cout << fixed << setprecision(2);
	if(total == 1){
		cout << "\n\tPerfect score! Good job! " << total << endl;
	}else if(total < 1){
		cout << "\n\tYou came in under $1.00 with a total of " << total << endl;
	}else if(total > 1){
		cout << "\n\tYou went over with a total of " << total << endl;
	}

	return 0;
}