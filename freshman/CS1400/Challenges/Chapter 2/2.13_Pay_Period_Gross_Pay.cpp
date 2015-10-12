/*A particular employee earns $32,500 annually. Write a program that determines 
and displays what the amount of his gross pay will be for each pay period if he 
is paid twice a month (24 pay checks per year) and if he is paid bi-weekly 
(26 checks per year).*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int annualGross = 32500, paidMonthly = 24, paidBiweekly = 26;

	cout << "\nEach pay check if paid monthly $" << annualGross / paidMonthly << endl;
	cout << "\nEach pay check if paid bi-weekly $" << annualGross / paidBiweekly << endl;

	return 0;
}