/*The profit from the sale of a stock can be calculated as follows:

	Profit = ((NS * SP) - SC) - ((NS * PP) + PC)

Where NS is the number of shares, SP is the sale price per share, SC is the sale 
commission paid, PP is the purchase price per share, and PC is the purchase commission
paid. If the calculation yields a positive value, then the sale of the stock resulted
in a profit. If the calculation yields a negative number, then the sale resulted in a
loss.

Write a function that accepts as arguments the number of shares, the purchase price
per share, the purchase commission paid, the sale price per share, and the sale
commission paid. The function should return the profit (or loss) from the sale of 
stock.

Demonstrate the function in a program that asks the user to enter the necessary data
and displays the amount of profit or loss.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();
double stockProfit(int, double, double, double, double);

int main(){
	int NS;
	double PP, PC, SP, SC, profit;

	printTitle();

	cout << "\n\n\tEnter data";
	cout << "\n\tNnmber of Shared (NS) : ";
	cin >> NS;
	cout << "\tSale Price (SP): ";
	cin >> SP;
	cout << "\tSales Commission (SC): ";
	cin >> SC;
	cout << "\tPurchase Price (PP): ";
	cin >> PP;
	cout << "\tPurchase Commission (PC): ";
	cin >> PC;
	
	

	profit = stockProfit(NS, PP, PC, SP, SC);

	cout << "\nWith that data your stock made a " << profit << " profit.\n";

	return 0;
}

void printTitle(){

	cout << "\n****************";
	cout << "\nStock Profit   |";
	cout << "\n****************";

}

double stockProfit(int NS, double PP, double PC, double SP, double SC){
	double profit;

	profit = ((NS * SP) - SC) - ((NS * PP) + PC);

	return profit;
}