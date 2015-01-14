/*Write a program that asks the user to enter an item's wholesale cost and its 
markup percentage. It should then display the item's retail price. For example:

	• If an item's wholesale cost is 5.00 and its markup percentage is 100%, then
	the item's retail price is 10.00.
	• If an item's wholesale cost is 5.00 and its markup percentage is 50%, then the
	item's retail price is 7.50.

The program should have a function named calculateRetail that receives the wholesale
cost and the markup percentage as arguments and returns the retail price of the item.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

double calculateRetail(double, double);

int main(){
	double wholeCost, markup, price;


	cout << "\n**********";
	cout << "\nMarukp   |";
	cout << "\n**********";

	cout << "\n\n\tEnter the wholesale cost of an item and the markup percentage";

	cout << "\n\n\tWholesale cost: ";
	cin >> wholeCost;
	cout << "\tMarkup percentage: ";
	cin >> markup;
	markup /= 100;

	price = calculateRetail(wholeCost, markup);

	cout << "The retail price for this item is: " << price << endl;

	return 0;
}

double calculateRetail(double cost, double mark){

	return cost + (cost * mark);

}