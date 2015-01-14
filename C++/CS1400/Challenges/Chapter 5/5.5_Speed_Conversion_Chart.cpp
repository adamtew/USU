/*Write a program that displays a table of speeds in kilometers per hour with their
values converted to miles per hour. The table should display the speeds from 40
kilometers per hour through 120 kilometers per hour, in increments of 5 kilometers
per hour. (In other words, it should display 40 kph, 45 kph, 50 kph and so forth, up
through 120 kph.)

	MPH = KPH * 0.6214*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	

	cout << "\n\n**************************";
	cout << "\nSpeed Conversion Chart   |";
	cout << "\n**************************";

	cout << "\n\n\tMPH               KPH";
	cout << "\n\t----------------------";
	for(int KPH = 40; KPH <= 120; KPH +=5)
		cout << "\n\t" << KPH << "\t\t" << (KPH * 0.6214);

	return 0;
}