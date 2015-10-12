/*The Earth's ocean levels have risen an average of 1.8 millimeters per year over 
the past century. Write a progrm that computes and displays the number of 
centimeters and number of inches the ocean rose during this time. One millimeter 
is equivalent to 0.1 centimeters. One centimeter is equivalent to 0.3937 inches*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float risen = 1.8, centimeters = risen * .1, 
	inches = centimeters * .3937;

	cout << "\nThe ocean rose " << centimeters << " centimeters per year";
	cout << "\nThe ocean rose " << inches << " inches per year.\n";

	return 0;
}