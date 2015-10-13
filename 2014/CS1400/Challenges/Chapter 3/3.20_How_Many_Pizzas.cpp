/*Modify the program you wrote in Programming Challenge 19 so that it reports the
number of pizzas you need to buy for a party if each person attending is expected
to eat an average of 4 slices. The program should ask the user for the number of 
people who will be at the party and for the diameter of the pizza to be ordered.
It should then calculate and display the number of pizzas to purchase. Because
it is impossible to buy a part of a pizza, the number of required pizzas should
be displayed as a whole number.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	const float PI = 3.14, sliceArea = 14.125;
	float pizzaArea, pizzaDiam = 0, pizzaRadius, areaReq, areaPizzaReq;
	int slicesPerPizza, pizzasReq, attending = 0, slicesReq;

	cout << "\nHow many people will be attending this party? ";
	cin >> attending;
	cout << "What is the diameter of the pizzas you're ordering? ";
	cin >> pizzaDiam;

	slicesReq = attending * 4;
	pizzaRadius = pizzaDiam / 2;
	pizzaArea = pow((PI * pizzaRadius), 2);
	slicesPerPizza = pizzaArea / sliceArea;
	areaReq = slicesReq * sliceArea;
	pizzasReq = areaReq / pizzaArea;
	areaPizzaReq = areaReq / pizzaArea;
	pizzasReq = ceil(areaPizzaReq);

	cout << fixed << setprecision(1);
	cout << "\nYou will need " << pizzasReq << " pizzas for this part.\n";
	cout << "\n\n-----Additional Information-----\n";
	cout << "\n\tPizza area: " << pizzaArea;
	cout << "\n\tSlices Required: " << slicesReq;
	cout << "\n\tSlices per pizza: " << slicesPerPizza;
	cout << "\n\tArea required: " << areaReq;
	cout << "\n\tPizzas required " << pizzasReq << endl;

	return 0;
}