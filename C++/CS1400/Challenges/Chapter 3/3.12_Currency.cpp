/*Write a program that will convert U.S. dollar amounts to Japanese yen and to euros,
storing the conversion factors in the constant variables YEN_PER_DOLLAR and 
EUROS_PER_DOLLAR. To get the most up-to-date exchange rates, search the internet
using the term "currency exchange rate" or "currency converter". If you cannot find
the most recent exchange rates, use the following:

	1 Dollar = 78.18 Yen
	1 Dollar = .8235 Euros*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	const float YEN_PER_DOLLAR = 78.18, EUROS_PER_DOLLAR = .8235;
	float inputDollar = 0, yen, euro;

	cout << "\nEnter a dollar amount ";
	cin >> inputDollar;

	yen = inputDollar * YEN_PER_DOLLAR;
	euro = inputDollar * EUROS_PER_DOLLAR;

	cout << "\nThat comes out to " << yen << " yen and " << euro << " euros\n";

	return 0;
}