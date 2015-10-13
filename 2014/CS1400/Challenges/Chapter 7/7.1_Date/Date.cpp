#include "Date.h"

using namespace std;

Date::Date(){
	month = day = 1;
	year = 2001;
}

Date::Date(int m, int d, int y){
	month = m;
	day = d;
	year = y;
}

void Date::format1(){

	
	cout << month << "/" << day << "/" << year;

}

void Date::format2(){
	string m;

	while(month < 1 || month > 12){
		cout << "\n\tEnter a valid month: ";
		cin >> month;
	}

	if(month == 1){m = "January";	validate(31);}
	if(month == 2){m = "February";	validate(28);}
	if(month == 3){m = "March";		validate(31);}
	if(month == 4){m = "April";		validate(30);}
	if(month == 5){m = "May";		validate(31);}
	if(month == 6){m = "June";		validate(30);}
	if(month == 7){m = "July";		validate(31);}
	if(month == 8){m = "August";	validate(31);}
	if(month == 9){m = "September";	validate(30);}
	if(month ==10){m = "October";	validate(31);}
	if(month ==11){m = "November";	validate(30);}
	if(month ==12){m = "December";	validate(31);}
	
	cout << m << " " << day << ", " << year;

}
void Date::format3(){
	string m;

	while(month < 1 || month > 12){
		cout << "\n\tEnter a valid month: ";
		cin >> month;
	}

	if(month == 1){m = "January";	validate(31);}
	if(month == 2){m = "February";	validate(28);}
	if(month == 3){m = "March";		validate(31);}
	if(month == 4){m = "April";		validate(30);}
	if(month == 5){m = "May";		validate(31);}
	if(month == 6){m = "June";		validate(30);}
	if(month == 7){m = "July";		validate(31);}
	if(month == 8){m = "August";	validate(31);}
	if(month == 9){m = "September";	validate(30);}
	if(month ==10){m = "October";	validate(31);}
	if(month ==11){m = "November";	validate(30);}
	if(month ==12){m = "December";	validate(31);}
	
	cout << day << " " << m << " " << year;
}

bool Date::validate(int max){
	while(day < 1 || day > max){
		cout << "\nYou need to give a valid day."
			<< "\nFor this month that would be between 1 and " << max;
		cin >> day;
	}
}