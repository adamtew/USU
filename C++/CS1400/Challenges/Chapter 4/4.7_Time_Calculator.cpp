/*Write a program that asks the user to enter a number of seconds.
	• There are 86400 seconds in a day. If the number of seconds entered by the user
	  is greater than or equal to 86400, the program should display the number of 
	  days in that many seconds.
	• There are 3600 seconds in an hour. If the number of seconds entered by the user
	  is less than 86400, but greater than or equal to 3600, the program should
	  display the number of hours in that many seconds.
	• There are 60 seconds in a minute. If the number of seconds entered by the user
	  is less than 3600, but greater than or equl to 60, the program should display
	  the number of minutes in that many seconds.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	const int day = 86400, hour = 3600, minute = 60;
	int numDay = 0, numHou = 0, numMin = 0, seconds = 0;

	cout << "\n\n\tEnter an amount of seconds: ";
	cin >> seconds;

	if(seconds >= day){
		numDay = seconds / day;
		cout << "\n\tThere are " << numDay << " day(s) in " << seconds << " seconds.\n";
	}else if(seconds < day && seconds >= hour){
		numHou = seconds / hour;
		cout << "\n\tThere are " << numHou << " hour(s) in " << seconds << " seconds.\n";
	}else if(seconds < hour && seconds >= minute){
		numMin = seconds / minute;
		cout << "\n\tThere are " << numMin << " minute(s) in " << seconds << " seconds.\n";
	}else{
		cout << "\n\tYeah, that doesn't work.\n";
	}

	return 0;
}