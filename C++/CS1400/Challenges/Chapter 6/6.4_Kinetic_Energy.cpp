/*In physics, an object that is in motion is said to have kinetic energy. The
following formula can be used to determine a moving object's kinetic energy:

	KE = 1/2mv^2

The variables in the formula are as follows: KE is the kinetic energy in joules, m is
the object's mass in kilograms, and v is the object's velocity in meters per second.

Write a function named kineticEnergy that accepts an object's mass (in kilograms) and
velocity (in meters per second) as arguments. The function should return the amount of
kinetic energy that the object has. Demonstrate the function by calling it in a
program that asks the user to enter values for mass and velocity.*/
// Adam Tew ---- CS1400
#include <iostream>

using namespace std;

double kineticEnergy(double,double);

int main(){
	double KE, m, v;

	cout << "\n******************";
	cout << "\nKinetic Energy   |";
	cout << "\n******************";

	cout << "\n\n\tEnter an objects mass (in kilograms) and \n\tvelocity (in "
		<< "meters per second) and I will give you \n\tthe kinetic energy of that object.";
	cout << "\n\n\tMass: ";
	cin >> m;
	cout << "\tVelocity: ";
	cin >> v;

	KE = kineticEnergy(m, v);

	cout << "\t" << KE << " joules of kinetic energy." << endl;

	return 0;
}

double kineticEnergy(double m, double v){

	double KE = .5 * (m * (v * v));

	return KE;
}