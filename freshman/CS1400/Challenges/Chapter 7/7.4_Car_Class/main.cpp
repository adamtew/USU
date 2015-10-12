#include "Car_Class.h"

using namespace std;

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