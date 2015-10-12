/*Write a program that determines which of a company's four divisions (Northeast,
Southeast, Northwest, and Southwest) had the greatest sales for a quarter. It should
include the following two functions, which are called by main.

	• double getSales() is passes the name of a division. It asks the user for a 
	  division's quarterly sales figure, validates that the input is not less than 0
	  then returns it. It should be called once for each division.
	• void findHighest() is passes the four sales totals. It determines which is the
	  largest and prints the name of the high grossing division, along with its
	  sales figure.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

double getSales(string);
void findHighest(double, double, double, double);
void printTitle();

int main(){
	string ne = "Northeast",
			nw = "Northwest",
			se = "Southeast",
			sw = "Southwest";
	double NE, NW, SE, SW;

	printTitle();
	
	NE = getSales(ne);
	NW = getSales(nw);
	SE = getSales(se);
	SW = getSales(sw);

	findHighest(NE, NW, SE, SW);

	return 0;
}

double getSales(string division){
	double divisionIncome;

	cout << "\tQuartery sales for " << division << ": ";
	cin >> divisionIncome;
	while(divisionIncome < 0){
		cout << "\n\tQuartery sales for " << division << ": ";
		cin >> divisionIncome;
	}

	return divisionIncome;
}

void findHighest(double NE, double NW, double SE, double SW){

	if(NE > NW && NE > SE && NE > SW){
		cout << "\n\tThe Northeast division made the most with a profit of "
			<< NE << endl;
	}else if(NW > NE && NW > SE && NW > SW){
		cout << "\n\tThe Northwest division made the most with a profit of "
			<< NW << endl;
	}else if(SE > NW && SE > NE && SE > SW){
		cout << "\n\tThe Southeast division made the most with a profit of "
			<< SE << endl;
	}else if(SW > NW && SW > SE && SW > NE){
		cout << "\n\tThe Southwest division made the most with a profit of "
			<< SW << endl;
	}

}

void printTitle(){

	cout << "\n********************";
	cout << "\nWinning Division   |";
	cout << "\n********************\n\n";

}