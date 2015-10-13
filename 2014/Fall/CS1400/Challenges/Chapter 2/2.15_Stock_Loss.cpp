/*Kathryn bought 600 shares of stock at a price of $21.77 per share. A year 
later she sold them for just $16.44 per share. Write a program that calculates 
and displays the following:
	The total amount paid for the sock.
	The total amount received from selling the stock.
	The total amount of money she lost.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float shares = 600, initPrice = 21.77, sellPrice = 16.44;

	cout << "\nPaid for stock was: $" << initPrice * shares << endl;
	cout << "\nReceived from selling the stock: $" << shares * sellPrice << endl;
	cout << "\nTotal loss: " << (initPrice * shares) - (shares * sellPrice) << endl;
	
	return 0;
}