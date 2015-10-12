/*Write a program that calculates how much a person earns in a month if the salary is
one penny the first day, two pennies the second day, four pennies the third day, and
so on with the daily pay doubling each day the employee works. The program should ask the user for the number of days the employee worked during the month, validate that it is between 1 and 31, and then desiplay a table showing how much the salary was for
each day worked, as well as the total pay earned for the month. The output should be 
displayed in dollars with two decimal points, not in pennies.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float cash = .01;
	int pennies = 0, days = 0;

	cout << "\n\n********************";
	cout << "\nPennies for Pay    |";
	cout << "\n********************";

	cout << "\n\n\tDays worked?: ";
	cin >> days;

	cout << fixed << setprecision(2);
	cout << "\n\n\t----------------";
	cout << "\n\tDay\tCash";
	cout << "\n\t----------------";
	for(int i = 1; i <= days; i++){
		cout << "\n\t" << i << "\t $" << cash;
		cash += cash * 2;
	}

	return 0;
}