/*Write a class named Car that has the efollowing member variables:

	• year. An int that holds the car's model year.
	• make. A string object that holds the make of the car.
	• speed. An int that holds the  car's current speed.

In addition, the class should have the following member functions.

	• Constructor. The constructor should accept the  car's year and make as arguments
	  and assign these values to the object's year and make member variables. The
	  constructor should initialize the speed member variable to 0.
	• Accessors. Appropriate accessor functions should be created to allow values to
	  be retrieved from an object's year, make, and speed member variables.
	• accelerate. The accelerate function should add 5 to the speed member variable
	  each time it is called.
	• brake. The brake function should subtract 5 from the speed member variable each
	  time it is called.

Demonstrate the class in a program that creates a car object, and then calls the
accelerate function five times. After each call to the accelerate function , get the 
current speed of the car and display it. Then, call the brake function five times.
After each call to the brake function, get the current speed of the car and display 
it.*/
// Adam Tew ---- CS1400

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

//Car::Car(){}
Car::Car(int imodel, string imake){
	year = imodel;
	make = imake;
	speed = 0;
}

int Car::getYear(){
	return year;
}

string Car::getMake(){
	return make;
}

int Car::getSpeed(){
	return speed;
}

void Car::accelerate(){
	speed += 5;
}

void Car::brake(){
	speed -= 5;
}

void printTitle();

int main(){
	
	Car car(2001, "Chevy");

	printTitle();

	cout << "\n\n\t The speed is: " << car.getSpeed();

	for(int i = 0; i < 5; i++){
		car.accelerate();
	}

	cout << "\n\n\t The speed is: " << car.getSpeed();

	for(int i = 0; i < 5; i++){
		car.brake();
	}

	cout << "\n\n\t The speed is: " << car.getSpeed();

	return 0;
}

void printTitle(){

	cout << "\n*************";
	cout << "\nCar Class   |";
	cout << "\n*************";

}