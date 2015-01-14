//The East Coast sales division of a company generates 62 percent of total sales.
//Based on that percentage, write a program that will predict how muc East Coast 
//division will generate if the company has $4.16 million in sales this year. 
//Display the result on the screen.

#include <iostream>

using namespace std;

int main(){
	float percent = .62, sales = 4.16, prediction = percent * sales;

	cout << "\nThe company will produce " << prediction << " million from East Coast.\n";

	return 0;
}