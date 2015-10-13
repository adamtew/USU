/*Write a program that displays the following menu:

Geometry Calculator

	1. Calculate the Area of a Circle
	2. Calculate the Area of a Rectangle
	3. Calculate the Area of a Triangle
	4. Quit

Enter you choice (1-4):

If the user enters 1, the program should ask for the radius of the circle and then
display its area. Use 3.14159 for PI. If the user enters 2, the program should ask
for the length and width of the rectangle, and then display the rectangle's area. If
the user enters 3, the program sohuld ask for the length of the triangle's base and
its height, and then display its area. If the user enters 4, the program should end.

	Input Validation: Decide how the program should handle an illegal input for the
	menu choice or a negative value for an of the other inputs.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	const float PI = 3.14159;
	float area, length = 0, width = 0, base = 0, height = 0, radius = 0;
	int switched;

	cout << "\n\nGeometry Calculator\n";
	cout << "\n\t1. Calculate the Area of a Circle";
	cout << "\n\t2. Calculate the Area of a Rectangle";
	cout << "\n\t3. Calculate the Area of a Triangle";
	cout << "\n\t4. Quit";
	cout << "\n\nEnter your choice (1-4): ";
	cin >> switched;

	switch(switched){

		case 1:
			cout << "\nWhat is the radius in inches of the circle ";
			cin >> radius;
			area = PI * pow(radius,2);
			if(radius >= 0)
				cout << "\nThe area is " << area << " inches\n";
			else
				cout << "\nThat input is not valid\n";
			break;
		case 2:
			cout << "\nWhat is the length in inches of the rectangle? ";
			cin >> length;
			cout << "\nWhat is the width in inches of the rectangle? ";
			cin >> width;
			area = length * width;
			if(length >= 0 && width >= 0)
				cout << "\nThe area is "<< area << " inches\n";
			else
				cout << "\nThat input is not valid\n";
			break;
		case 3:
			cout << "\nWhat is the length in inches of the base ";
			cin >> base;
			cout << "\nWhat is the height ";
			cin >> height;
			area = base * (height / 2);
			if(base >= 0 && height >= 0)
				cout << "\nThe area is "<< area << " inches\n";
			else
				cout << "\nThat input is not valid\n";
			break;
		case 4:
			break;
		default:
			cout << "\nThat's not one of the options.\n";
			break;
	}

	return 0;
}