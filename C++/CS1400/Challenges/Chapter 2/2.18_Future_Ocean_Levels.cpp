/*During the past decade ocean levels have been rising faster than in the past, 
an average of approximately 3.1 milimeters per year. Write a program that 
computes how much ocean levels are expected to rise during the next 20 years 
if they continue rising at this rate. Display the answer in both centimeters 
and inches.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float avgRise = 3.1, centimeters = avgRise * .1, inches = centimeters * .3937;

	cout <<"\nOcean levels are expected to rise " << centimeters
		<< " centimeters in then next 20 years."
		<<"\nOcean levels are expected to rise " << inches
		<< " centimeters in then next 20 years.\n";

	return 0;
}