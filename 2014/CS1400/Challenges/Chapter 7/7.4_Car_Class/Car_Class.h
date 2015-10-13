#ifndef CAR_CLASS_H
#define CAR_CLASS_H

#include <iostream>

using namespace std;

class Car{

private:
	int year, speed;
	string make;

public:
	//	Constructors
	Car();
	Car(int, string);

	//	Accessors
	int getYear();
	string getMake();
	int getSpeed();

	void accelerate();
	void brake();

};

#endif