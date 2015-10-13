/*Write a program that asks the user to enter their monthly costs for each 
of the following related expenses:
	• rent or mortgage payment
	• utilities
	• phones
	• cable
The program should then display the total monthly cost of these expenses, 
and the total annual cost of these expenses.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float rent = 0, utilities = 0, phone = 0, cable = 0, monthlyTotal = 0, annual = 0;

	cout << "\nEnter your monthly rent payment: ";
	cin >> rent;	
	cout << "Enter your monthly utilities payment: ";
	cin >> utilities;
	cout << "Enter your monthly phone payment: ";
	cin >> phone;
	cout << "Enter your monthly cable payment: ";
	cin >> cable;

	monthlyTotal = rent	+ utilities + phone + cable;
	annual = monthlyTotal * 12;

	cout << "\nYour total monthly bill is $" << monthlyTotal
		<< "\nYour total annual bill is $" << annual << endl;



	return 0;
}