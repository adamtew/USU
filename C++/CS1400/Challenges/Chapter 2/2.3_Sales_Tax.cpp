//Write a program that computes the total sales tax on a $52 purchase. 
//Assume the state sales tax is 4 percent and the country sales tax is 2 percent. 
//Display the purchase price, state tax, county tax, and total tax amounts on the screen.
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float stateTax = .04, countyTax = .02, purchase = 52;

	cout << "Purchase price: " << purchase;
	cout << "\nState Tax: " << stateTax * purchase;
	cout << "\nCounty Tax: " << countyTax * purchase;
	cout << "\nTotal Tax: " << stateTax * purchase + countyTax * purchase;

	return 0;
}