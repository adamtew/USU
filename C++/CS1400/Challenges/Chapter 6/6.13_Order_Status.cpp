/*The Middletown Wholesale Copper Wire Company sells spools of copper wiring for $100
each and ships them for $10 a piece. Write a program that displays the status of an
order. It should use two function. The first function asks for the following data and
stores the input values in reference parameters.

	• The number of spools ordered.
	• The number of spools in stock.
	• Any special shipping and handling charges (above the regular $10 rate).

The second function receives as arguments any values needed to compute and display
the following information:

	• The number of sordered spools ready to ship from current stock.
	• The number of ordered spools on backorder (if the number ordered is greater
	  than what is in stock).
	• Total selling price of the portion ready to ship (the number of spools ready
	  to ship times $100).
	• Total shipping and handling charges on the portion ready to ship.
	• Total of the order ready to ship.

The shipping and handling parameter in the second function should have the default
argument of 10.00.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cstdlib>

using namespace std;

void printTitle();
void order(int&, int&, double&);
void orderStatus(int, int, double);

int main(){
	int ordered = 5, inStock = 4;
	double charges = 5;


	printTitle();
	order(ordered, inStock, charges);

	return 0;
}

void printTitle(){


	cout << "\n****************";
	cout << "\nOrder Status   |";
	cout << "\n****************";

}

void order(int& spoolsOrdered, int& spoolsInStock, double& specialCharges){

	orderStatus(spoolsOrdered, spoolsInStock, specialCharges);

}

void orderStatus(int spoolsOrdered, int spoolsInStock, double specialCharges){
	int readySpools, 
	notReadySpools = abs(spoolsInStock - spoolsOrdered);
	double readyPrice = (spoolsInStock * 100), 
	shipping = 10, 
	total = readyPrice + shipping + specialCharges;

	cout << "\n\n\tReady to ship: 			" << spoolsInStock;
	cout << "\n\tSpools on backorder: 		" << notReadySpools;
	cout << "\n\tPrice for ready spools: 	$" << readyPrice;
	cout << "\n\tShipping charges: 		$" << shipping + specialCharges;
	cout << "\n\n\tTotal Price: 			$" << total;

}