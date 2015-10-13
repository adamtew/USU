/*In one of the Chapter 3 Programming Challenges you were asked to write a program 
that converted a Celsius temperature to Fahrenheit. Modify that program so it uses 
a loop to display a table of Celsius temperatures from 0 to 20 and their Fahrenheit
equivalents.

	F = 9/5C + 32		*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){

	cout << "\n\n*******************************";
	cout << "\nCelsius to Fahrenheit Table   |";
	cout << "\n*******************************";

	cout << fixed << right;
	cout << "\n\n\tCelsius          Fahrenheit";
	cout << "\n\t-----------------------------";
	for(int C = 0; C <= 20; C++){
		cout << "\n\t" << C << setw(20) << setprecision(1) << (1.8 * C) + 32;
	}

	return 0;
}