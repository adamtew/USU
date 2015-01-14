/*Joe's Pizza Palace needs a program to calculate the numer of slices a pizza of any
size can be divided into. The program should perform the following steps:
	A)	Ask the user for the diameter of the pizza in inches.
	B)	Calculate the number of slices that may be taken from a pizza of that
		size if each slice has an area of 14.125 inches.
	C)	Display a message telling the number of slices.

The number of square inches in the total pizza can be calculated with this formula:

	Area = PIr^2

Where variable r is the radius of the pizza and PI is the Greek letter PI. In your
program make PI a named constant with the value 3.14. Display the number of slices
as a whole number (i.e., with no decimals).*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	const float PI = 3.14, sliceArea = 14.125;
	float pizzaDiam = 0, pizzaRadius, pizzaArea;
	int slices;

	cout << "\nWhat is the diameter in inches of the pizza? ";
	cin >> pizzaDiam;

	pizzaRadius = pizzaDiam / 2;
	pizzaArea = pow((PI * pizzaRadius), 2);
	slices = pizzaArea / sliceArea;

	cout << fixed << setprecision(1);
	cout << "\nYour pizza area is " << pizzaArea << " square inches.";
	cout << "\nThis gives you " << slices << " slices.\n";

	return 0;
}