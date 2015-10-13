/*Write a program that calculates the average monthly rainfall for 
three months. The program should ask the user to enter the name of 
each month, such as June or July, and the amount of rain (in inches) 
that fell that month. The program sohuld display a message similar to the following:

The average monthly rainfall for June, July, and August was 6.72 inches.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <string>

using namespace std;

int main(){
	float m1 = 0, m2 = 0, m3 = 0, mAvg;
	string n1, n2, n3;

	cout << "\nWhat was the 1st month? ";
	cin >> n1;
	cout << "How much rain, in inches, fell that month? ";
	cin >> m1;

	cout << "\nWhat was the 2nd month? ";
	cin >> n2;
	cout << "How much rain, in inches, fell that month? ";
	cin >> m2;

	cout << "\nWhat was the 3rd month? ";
	cin >> n3;
	cout << "How much rain, in inches, fell that month? ";
	cin >> m3;

	mAvg = (m1 + m2 + m3) / 3;

	cout << "\nThe average rainfall for " 
		<< n1 << ", " << n2 << ", and " << n3 << " was " << mAvg << " inches.\n";

	return 0;
}