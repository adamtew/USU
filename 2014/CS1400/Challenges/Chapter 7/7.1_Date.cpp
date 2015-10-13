/*Design a class called Date that has integer members to store month, day, and year. 
The class should have a three-parameter default constructor that allows the date to
be set at the time a new Date object is created. If the user creates a Date object
without passing any arguments, or if any of the values passed are invalid, the default
values of 1, 1, 2001 (i.e., January 1, 2001) should be used. The class should have 
member functions to print the date in the following formats:

	3/15/13
	March 15, 2013
	15 March 2013

Demonstrate the class by writing a program that uses it. Be sure your program only
accepts reasonable values for month and day. The month should be between 1 and 12. 
The day should be between 1 and the number of days in the selected month.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

class Date{

private:
	int month, day, year;

public:
	Date();

	Date(int, int, int);

	void format1();
	void format2();
	void format3();
	bool validate(int);

};

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

int main(){
	
	Date date, date1(5,24,2015);

	cout << endl;date.format1();
	cout << endl;date.format2();
	cout << endl;date.format3();
	cout << endl;date1.format1();
	cout << endl;date1.format2();
	cout << endl;date1.format3();

	return 0;
}