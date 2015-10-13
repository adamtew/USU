/*Last month Joe purchased 100 shares of stock. Here are the details of the purchase:

	• When Joe purchased the stock, he paid $32.87 per share.
	• Joe paid his stock broker a commission that amounted to 2% of the amount
	  he paid for the stock.

Two months later Joe sold the stock. Here are the details of the sale:

	• When Joe purchased the stock, he paid $32.87 per share.
	• He paid his stock broker another commission that amounted to 2% of the amount
	  he received for the stock.

Write a program that displays the following information:

	• The amount of money Joe paid or the stock.
	• The amount of commission Joe paid his broker when he bought the stock.
	• The amount that Joe sold the stock for.
	• The amount of commission Joe paid his broker when he sold the stock.
	• The amount of profit or loss that Joe had after selling his stock and paying
	  both broker commissions.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	const int shares = 100;
	float paid = shares * 32.87,
		brokerCheck = paid * .02,
		sold = 100 * 33.92,
		brokerCheck2 = sold * .02,
		profit = (paid + brokerCheck + brokerCheck2) - sold;

	cout << "\n---------------------------------------------------------------";
	cout << "\n\tJoe paid \t\t\t\t   $" << paid;
	cout << "\n\tCheck to broker when purchased: \t  $" << brokerCheck;
	cout << "\n\tReceived when sold: \t\t\t   $" << sold;
	cout << "\n\tCheck to broker when sold: \t\t  $" << brokerCheck2;
	cout << "\n\tOverall profit from 100 shares: \t$" << profit;
	cout << "\n---------------------------------------------------------------\n\n";

	return 0;
}