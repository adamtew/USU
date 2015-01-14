//Write a program that calculates how much a little league baseball team spent last
//year to purchase new baseballs. The program should prompt the user to enter the
//number of baseballs purchased and the cost of each baseball. It should then
//calculate and display the total amount spent to purchase the baseballs.
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int baseballs;
	float cost, total;

	cout << "\nHow many baseballs were purchased this year? ";
	cin >> baseballs;

	cout << "\nHow much did each baseball cost? (in dollars) ";
	cin >> cost;

	total = cost * baseballs;

	cout << "\nLooks like you spent " << total << " dollars last year on baseballs\n";
}