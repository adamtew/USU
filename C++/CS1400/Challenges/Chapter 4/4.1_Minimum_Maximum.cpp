/*Write a program that asks the user to enter two number. The program should
use the conditional operator to determine which number is the smaller and which
is the larger.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int num1 = 0, num2 = 0, larger;

	cout << "\nThis program compares two numbers to see which one is larger.";
	cout << "\n\n\tEnter the 1st number ";
	cin >> num1;
	cout << "\tEnter the 2nd number ";
	cin >> num2;

	num1 > num2 ? larger = num1 : larger = num2;

	cout << "\n\t\t" << larger << " is larger" << endl;

	return 0;
}