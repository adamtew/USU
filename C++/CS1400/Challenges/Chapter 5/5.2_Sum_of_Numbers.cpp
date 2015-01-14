/*Write a program that asks the user for a positive integer value and that uses a
loop to validate the input. The program sohuld then use a second loop to compute
the sum of all the integers from 1 up to the number entered. For example, if the user
enters 50, the loop will find the sum of 1, 2, 3, 4, ... 50.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int posInt = 0, inc = 0, val = 0;

	cout << "\n\n*******************";
	cout << "\nSum of Numbers   |";
	cout << "\n*******************\n\n";

	cout << "Enter a positive integer value and it will be summed.";
	cout << "\nInteger Value: ";
	cin >> posInt;

	while(inc <= posInt){
		val += inc++;
	}

	cout << "\n\t" << val << endl;

	return 0;
}