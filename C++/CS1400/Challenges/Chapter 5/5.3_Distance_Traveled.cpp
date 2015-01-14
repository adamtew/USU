/*The distance a vehicle travels can be calculated as follows:

	distance = speed * time

For example, if a train travels 40 miles per hour for 3 hours, the distance traveled is
120 miles.

Write a program that asks the user for the speed of a vehivle (in miles per hour) and
how many hours it has travel. It should then use a loop to display the total distance
traveled at the end of each hour of that time period. Here is an example of the
output:

	What is the speed of the vehicle in mph? 40
	How many hours has it traveled? 3
	Hour 		Miles Traveled
	-----------------------------------
		1 				40
		2 				80
		3 			   120*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int speed = 0, hours = 0, hour = 0;

	cout << "\n\n*********************";
	cout << "\nDistance Traveled   |";
	cout << "\n*********************";

	cout << "\n\n\tWhat's the speed of the vehicle and the hours traveled?";
	cout << "\n\nSpeed (mph): ";
	cin >> speed;
	cout << "Hours: ";
	cin >> hours;

	cout << "\n\tHour         Miles Traveled";
	cout << "\n\t----------------------------";
	while(hours > hour)
	cout << "\n\t" << ++hour << setw(20) << speed * hour;

	cout << endl;

	return 0;
}