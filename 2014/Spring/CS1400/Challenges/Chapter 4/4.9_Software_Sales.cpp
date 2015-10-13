/*A software company sells a package that retails for $99. Quantity discounts are
given according to the following table.
--------------------------------------------------------------
	Quality				Discount
--------------------------------------------------------------
	10 - 19					20%
	20 - 49					30%
	50 - 99					40%
	100 or more				50%
--------------------------------------------------------------
Write a program that asks for the number of units purchased and computes the total
cost of the purchase

	Input Validation: Decide how the program should handle an input of less than 0*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	const int price = 99;
	bool valid = true;
	int units = 0;
	float discount, cost;

	cout << "\n\tHow many units were purchased? ";
	cin >> units;


	if(units >= 10 && units < 20){
		discount = .2;
		cost = (units * price) * discount;
		discount = discount * 100;
		cout << "\n\tThe total cost for " << units << " units with a "
			<< discount << "% discount comes to $" << cost << endl;
	}
	else if(units >= 20 && units < 50){
		discount = .3;
		cost = (units * price) * discount;
		discount = discount * 100;
		cout << "\n\tThe total cost for " << units << " units with a "
			<< discount << "% discount comes to $" << cost << endl;
	}
	else if(units >= 50 && units < 100){
		discount = .4;
		cost = (units * price) * discount;
		discount = discount * 100;
		cout << "\n\tThe total cost for " << units << " units with a "
			<< discount << "% discount comes to $" << cost << endl;
	}
	else if(units >= 100){
		discount = .5;
		cost = (units * price) * discount;
		discount = discount * 100;
		cout << "\n\tThe total cost for " << units << " units with a "
			<< discount << "% discount comes to $" << cost << endl;
	}else{
		cout << "\n\tYeah, that's not gonna work.\n";
	}

	return 0;
}