/*Write a program that converts Celsius temperatures to Fahrenheit temperatures.
The formula is 

					F = 9/5C + 32

Where F is the Fahrenheit temperature and C is the Celsius temperature. The program
should prompt the user to input a Celsius temperature and should display the
corresponding Fahrenheit temperature.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float celsius = 0, fahrenheit;

	cout << "\nWhat is the temperature measured in Celsius? ";
	cin >> celsius;

	fahrenheit = (9 / 5 * celsius) + 32;

	cout << "\nThat would make the temperature " << fahrenheit
		<< " measured in fahrenheit.\n";

	return 0;
}