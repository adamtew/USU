/*Write a program that asks for the name of a pole vaulter and the dates and vault
heights (in meters) of the athlete's three best vaults. It should then report in
height order (best first), the date on which each vault was made, and its height.

	Input Validation: Only allow the program to accept avalues between 2.0 and 5.0 for
	the heights.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <string>

using namespace std;

int main(){
	string name, firstDate, secondDate, thirdDate;
	float firstVault = 0, secondVault = 0, thirdVault = 0;
	bool valid = true;


		cout << "\nWhat is the name of the pole vaulter? ";
		getline(cin, name);
		cout << "\nWhat were the days and heights of his vaults?\n";
		cout << "\n1st Height: ";
		cin >> firstVault;
		if(firstVault < 2.0 || firstVault > 5.0){
			return 0;
		}
		cout << "1st Date: ";
		getline(cin, firstDate);

		cout << "\n2nd Height: ";
		cin >> secondVault;
		if(secondVault < 2.0 || secondVault > 5.0){
			return 0;
		}
		cout << "2nd Date: ";
		getline(cin, secondDate);

		cout << "\n3rd Height: ";
		cin >> thirdVault;
		if(thirdVault < 2.0 || thirdVault > 5.0){
			return 0;
		}
		cout << "3rd Date: ";
		getline(cin, thirdDate);

	return 0;
}