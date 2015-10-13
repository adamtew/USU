/*The speed of sound varies depending on the medium through which it travels. In
general, sound traels faster in rigid media, such as steel, slow in liquid media,
such as water, and slowest of all in gases, such as air. The following table shows
the approximate speed of sound, measured in feet per second, in air, water, and steel.

--------------------------------------------------------------------------------------
	Medium 		Speed(feet per sec.)
--------------------------------------------------------------------------------------
	Air 			1,100
	Water 			4,900
	Steel 			16,400
--------------------------------------------------------------------------------------

Write a program that displays a menu of allowing the user to select air water, or 
steel. After the user has made a selection, the number of feet a sound wave will 
travel in the selected medium should be entered. The program will then display the
amount of time it will take. *Round the answer to four decimal places.)

	Input Validation: Decide how the program should handle an illegal input for the
	menu choice or a negative value for the distance.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main(){
	const int air = 1100, water = 4900, steel = 16400;
	char medium = 'c';
	float distance, travelTime;
	string mediumName = "roger";

	cout << "\n\n\t---------------";
	cout << "\n\t|  1.)\tAir   |";
	cout << "\n\t|  2.)\tWater |";
	cout << "\n\t|  3.)\tSteel |";
	cout << "\n\t---------------";
	cout << "\n\n\tChoose a medium: ";
	cin >> medium;
	if(medium != '1' && medium != '2' && medium != '3')return 0;

	cout << "\n\tFeet the sound will travel: ";
	cin >> distance;
	if(distance < 0)return 0;
	cout << fixed << setprecision(4);
	switch(medium){
		case '1': 
			travelTime = distance / air;
			mediumName = "air";
			break;
		case '2': 
			travelTime = distance / water;
			mediumName = "water";
			break;
		case '3': 
			travelTime = distance / steel;
			mediumName = "steel";
			break;
		default:
			break;
	}

	cout << "\nThe time for sound to travel " << setprecision(0)
		<< distance << " feet through\n\t" << setprecision(4)
		<< mediumName << " is " << travelTime << " seconds\n";


	return 0;
}