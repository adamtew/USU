/*Design an Inventory class that can hold information for an item in a retail store's
inventory. The class should have the following private member variables.

	Variable Name		Description

	itemNumber			An int that holds the item's number.

	quantity			An int that holds the quantity of the item on hand.

	cost				A doule that holds the wholesale per-unit cost of the item

The class should have the following public member functions.

	Member functions 	Description

	default constructor	Sets all the member variables to 0.

	constructor #2		Accepts an item's number, quantity, and cost asa arguments.
						Calls other class funtions to copy these values into the 
						appropriate member variables. Then calls the setTotalCost
						function.

	setItemNumber		Accepts an int argument and copies it into the itemNumber
						member variable.

	setQuantity			Accepts an int argument and copies it into the quantity
						member variable.

	setCost 			Accepts a double argument and copies it into the cost member
						variable.

	getItemNumber		Returns the value in itemNumber.

	getQuantity			Returns the value in quantity.

	getCost				Returns the value in cast.

	getTotalCost		Computes and returns the totalCost.

Demonstrate the class by writing a simple program that uses it. This program should
validate the user inputs to ensure that negative values are not accepted for item 
number, quantity, or cost.*/
// Adam Tew ---- CS1400

#include "Inventory_Class.h"

using namespace std;

void printTitle();

int main(){
	int iNumber = 5, iQuan = 5;
	double iCost = 6.8;
	Inventory item1, item2(iNumber, iQuan, iCost);

	printTitle();

	cout << "\n\nitem1.getTotalCost: " << item1.getTotalCost();
	cout << "\n\nitem2.getTotalCost: " << item2.getTotalCost();

	cout << "\n\nitem2.getItemNumber: " 	<< item2.getItemNumber();
	cout << "\nitem2.getQuantity: " 	<< item2.getQuantity();
	cout << "\nitem2.getCost: " 		<< item2.getCost();

	cout << "\n\nitem2.setItemNumber(1): "; item2.setItemNumber(1);
	cout << "\nitem2.setQuantity(500): "; item2.setQuantity(500);
	cout << "\nitem2.setCost(9.32): "	; item2.setCost(9.32);

	cout << "\n\nitem2.getItemNumber: " 	<< item2.getItemNumber();
	cout << "\nitem2.getQuantity: " 	<< item2.getQuantity();
	cout << "\nitem2.getCost: " 		<< item2.getCost();

	cout << "\n\nitem2.getTotalCost: " << item2.getTotalCost();

	return 0;
}

void printTitle(){

	cout << "\n*******************";
	cout << "\nInventory Class   |";
	cout << "\n*******************";

}