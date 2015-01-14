/*When traveling through a gas, the speed of sound depends primarily on the density
of the medium. The less dense the medium, the faster the speed will be. The following
table shows the approximate speed of sound at 0 degree celsius, measured in meters per
second, when traveling through carbon dioxide, air, helium, and hydrogen.

--------------------------------------------
	medium 		Speed(meters per sec.)
--------------------------------------------
	Carbon Dioxide 		258.0
	Air 				331.5
	Helium 				972.0
	Hydrogen 			1270.0
--------------------------------------------

Write a program the displays a menu allowing the user to select one of these 4 gases.
After a valid selection has been made, the program should ask the user to enter the
number of seconds (0 to 30) it took for the sound to travel in this medium from its
source to the location at which it was detected. The program should then report how
far away (in meters) the source of the sound was from the detection location.

	Input Validation: The program should ensure that the user has selected on of the
	available menu choices and should only prompt for the number of seconds if the
	menu choice is legal.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	const float carDio = 258, air = 331.5, helium = 972, hydrogen = 1270;
	char medium;
	float seconds = 0, distance;
	string mediumName;

	cout << "\n\n\t----------------------------";
	cout << "\n\t|  Carbon Dioxide     (1  |";
	cout << "\n\t|  Air                (2  |";
	cout << "\n\t|  Helium             (3  |";
	cout << "\n\t|  Hydrogen           (4  |";
	cout << "\n\t----------------------------";
	cout << "\n\n\tChoose a gas: ";
	cin >> medium;
	if(medium != '1' && medium != '2' && medium != '3' && medium != '4')return 0;

	cout << "\n\tSeconds (0 to 30): ";
	cin >> seconds;
	if(seconds < 0 || seconds > 30)return 0;
	switch(medium){
		case '1':
			distance = seconds * carDio;
			mediumName = "cardbon dioxide";
			break;
		case '2':
			distance = seconds * air;
			mediumName = "air";
			break;
		case '3':
			distance = seconds * hydrogen;
			mediumName = "helium";
			break;
		case '4':
			distance = seconds * helium;
			mediumName = "hydrogen";
			break;
		default:
			break;
	}

	cout << fixed << setprecision(0);
	cout << "\nThe sound is " << distance 
		<< " meters away from where it was heard.\n";

	return 0;
}