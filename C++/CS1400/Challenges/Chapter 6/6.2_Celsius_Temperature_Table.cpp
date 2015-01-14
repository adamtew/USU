/*The formula for converting a temperature from Fahrenheit to Celsius is

	C = 5/9(F - 32)

where F is the Fahrenheit temperature and C is the Celsius temperature. Write a
function named celsius that accepts a Fahrenheit temperature as an argument. The
function should return the temperature, converted to Celsius. Demonstrate the
function by calling it in a loop that displays a table of the Fahrenheit temperature 
0 through 20 and their Celsius equivalents.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;

double celsius(double);

int main(){

	cout << "\n*****************************";
	cout << "\nCelsius Temperature Table   |";
	cout << "\n*****************************";

	cout << fixed << setprecision(1);
	cout << "\n\n\t--------------------";
	cout << "\n\tCelsius\tFahrenheit";
	cout << "\n\t--------------------";
	for(double F = 0; F < 20; F++){
		cout << "\n\t" << F << "\t" << celsius(F);
	}

	return 0;
}

double celsius(double F){
	double C = .55555556 * (F - 32);

	return C;
}