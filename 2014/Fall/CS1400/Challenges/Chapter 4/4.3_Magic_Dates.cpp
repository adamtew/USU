/*The date June 10. 1960, is special because when we write it in the following
format, the month time the day equals the year.
	
	6/10/60

Write a program that asks the user to enter a month (in numeric form), a day, and two
digit year. The program should then determine whether the month times the day is 
equal to the year. If so, it should display a message saying the date is magic.
Otherwise, it should display a message saying the date is not magic.

	Input Validation: Think about what legal values the program should accept
	for month and day.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int month = 0, day = 0, year = 0;

	cout << "\nInput a numeric date to see if it's magical.";
	cout << "\n\nMonth (1 - 12) : ";
	cin >> month;
	cout << "Day (1 - 31) : ";
	cin >> day;
	cout << "Year (1 - 99) :";
	cin >> year;

	if((month <= 12 && month >= 1) && (day <= 31 && day >= 1) && (year <= 99 && year >= 1)){
		if(month * day == year){
			cout << "\n\tThe date is magical!\n";
		}
		else{
			cout << "\n\t... The date is not magical **tears**\n";
		}
	}


	return 0;
}