/*An electronics company sells circuit boards at a 40 percent profit. 
Write a program that calculates the selling price of a circuit board 
that costs them $12.67 to produce. Display the result on the screen.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	float percentProfit = .4, cost = 12.67, total = (percentProfit * cost) + cost;

	cout << "\nThe company will make $" << total << " total.\n";

	return 0;
}