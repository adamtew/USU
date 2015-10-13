/*Write a program that asks for five test scores. The program should 
calculate the average test score and display it. The number displayed 
should be formatted in fixed-point notation, with one decimal point of precision.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	float t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, tAvg = 0;

	cout << "\nWhat was the 1st test score? ";
	cin >> t1;
	cout << "What was the 2nd test score? ";
	cin >> t2;
	cout << "What was the 3rd test score? ";
	cin >> t3;
	cout << "What was the 4th test score? ";
	cin >> t4;
	cout << "What was the 5th test score? ";
	cin >> t5;

	tAvg = (t1 + t2 + t3 + t4 + t5) / 5;

	cout << fixed << setprecision(1);
	cout << "\nThe test average is " << tAvg << endl;

	return 0;
}