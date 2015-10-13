/*Write a program that calculates the occupance rate of the 120 suites (20 per floor)
located on the top 6 floors of a 15-story luxury hotel. These are floors 10-12 and
14-16 because, like many hotels, there is no 13th floor. Solve the problem by using
a single loop that loops once for each floor between 10 and 16 and, on each iteration,
asks the user to input the number of suites occupied on that floor. Use a nested loop
loop to validate that the value entered is between 0 and 20. After all the iterations,
the program should display how many suites the hotel has, how many of them are
occupied, and what percentage of them are occupied.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int occupants;	
	double occupied, totalOccupants;


	cout << "\n\n**************************";
	cout << "\nHotel Suites Occupancy   |";
	cout << "\n**************************";

	cout << "\n\n";

	for(int i = 10; i <= 16; i++){
		if(i == 13)continue;
		cout << "How many suites on floor " << i << "? ";
		cin >> occupants;
		while(occupants < 0 || occupants > 20){
			cout << "\nEnter a value between 0 and 20: ";
			cin >> occupants;
		}
		totalOccupants += occupants;
	}

	occupied = (totalOccupants / 120) * 100;

	cout << "\n\tTotal     Suites: " << 120;
	cout << "\n\tOccupied  Suites: " << totalOccupants;
	cout << "\n\tPercent Occupied: " << occupied << "%";
	cout << endl;

	return 0;
}