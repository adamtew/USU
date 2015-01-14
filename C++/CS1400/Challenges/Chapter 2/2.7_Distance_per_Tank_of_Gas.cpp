/*A car with a 20 gallon gas tank averages 21.5 miles per gallon when driven in 
town and 26.8 miles per gallon when driven on the highway. Write a program that 
calculates and displays the distance the car can travel on one tank of gas when 
driven in town and when driven on the highway.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float tank = 20, inTown = 21.5, onHighway = 26.8;

	cout << "\nThe car can travel " << tank * inTown << " in town.\n";
	cout << "\nThe car can travel " << tank * onHighway << " on the highway.\n";

	return 0;
}