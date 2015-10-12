/*The following formula can be used to determine the distance an object falls due to
gravity in a specific time period:

	d = (1/2)gt^2

The variables in the formula are as follows: d is the distance in meters, g is 9.8,
and t is the time in seconds that the object has been falling.

Write a function named fallingDistance that accepts an object's falling time (in
seconds) as an argument. The function should return the distance, in meters, that
the object has fallen during that time interval. Write a program that demonstrates
the function bu calling it in a loop that passes the values 1 through 10 as
arguments and displays the return value.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;
const double g = 9.8;
double fallingDistance(int);

int main(){
	
	cout << "\n********************";
	cout << "\nFalling Distance   |";
	cout << "\n********************";

	cout << "\n\n\t------------------------------";
	cout << "\n\tSeconds\tDistance (in meters)";
	cout << "\n\t------------------------------";
	cout << fixed << setprecision(2) << right;
	for(int t = 0; t <= 10; t++){
		cout << "\n\t" << t << "\t" << setw(6) << fallingDistance(t);
	}

	return 0;
}

double fallingDistance(int seconds){
	double distance = .5 * g * (seconds * seconds);

	return distance;
}