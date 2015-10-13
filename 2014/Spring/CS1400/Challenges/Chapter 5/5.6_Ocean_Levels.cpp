/*Assuming the level of the Earth's oceans continues rising at about 3.1 millimeters
per year, write a program that displays a table showing the total number of 
millimeters the ocean will have risen each year for the next 25 years.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float oLevel = 3.1;

	cout << "\n\n**************";
	cout << "\nOcean Levels |";
	cout << "\n**************";

	cout << "\n\n\t--------------------------";
	cout << "\n\tYear\tOcean Levels";
	cout << "\n\t--------------------------";
	for(int i = 1; i <=25; i++){
		cout << "\n\t" << i  << "\t" << oLevel << "\tmilimeters";
		oLevel += 3.1;
	}	


	return 0;
}