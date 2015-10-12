/*Write a program that asks the user for an angle, entered in radians.
The program should then display the sine, cosine, and tangent of an angle.
(Use the sin, cos, and tan library functions to determine these values.) The
output should be displayed in a fixed-point notation, rounded to four decimal
places of precision.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	float angle = 0, angleSin, angleCos, angleTan;

	cout << "\nEnter an angle in radians ";
	cin >> angle;

	angleSin = sin(angle);
	angleCos = cos(angle);
	angleTan = tan(angle);

	cout << "\nThe sine of this angle is " << angleSin;
	cout << "\nThe cosine of this angle is " << angleCos;
	cout << "\nThe tangent of this angle is " << angleTan << endl;

	return 0;
}