/*Use the function that you wrote for Programmin Challenge 11 (Stock Profit) in a 
program that calculates the total profit or loss from the sale of multiple stock.
The program should ask the user for the number of stock sales, and the necessary
data for each stock sale. It should accumulate the profit or loss for each stock
sale and then display the total.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();
double stockProfit(int, double, double, double, double);
void stockSale(int&, double&, double&, double&, double&);

int main(){
	int NS, numberOfSales;
	double PP, PC, SP, SC, profit;

	printTitle();

	cout << "\n\n\tEnter the number of sales: ";
	cin >> numberOfSales;
	for(int i = 1; i <= numberOfSales; i++){
		cout << "\n\n\tEnter data for sale number " << i << "\n\n";
		stockSale(NS, PP, PC, SP, SC);
		profit += stockProfit(NS, PP, PC, SP, SC);
	}

	cout << "\n\n\tYour total profit was $" << profit << endl;

	return 0;
}

void printTitle(){
	
	cout << "\n************************";
	cout << "\nMultiple Stock Sales   |";
	cout << "\n************************";

}

double stockProfit(int NS, double PP, double PC, double SP, double SC){
	double profit;

	profit = ((NS * SP) - SC) - ((NS * PP) + PC);

	return profit;
}

void stockSale(int& NS, double& PP, double& PC, double& SP, double& SC){

	cout << "\tNnmber of Shared    (NS): ";
	cin >> NS;
	cout << "\tSale Price          (SP): ";
	cin >> SP;
	cout << "\tSales Commission    (SC): ";
	cin >> SC;
	cout << "\tPurchase Price      (PP): ";
	cin >> PP;
	cout << "\tPurchase Commission (PC): ";
	cin >> PC;

}