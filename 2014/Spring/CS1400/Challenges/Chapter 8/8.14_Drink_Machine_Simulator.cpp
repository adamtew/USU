/*Create a class that simulates and manages a soft drink machine. 
Information on each drink type should be stored in a structure that has 
data members to hold the drink name, the drink price, and the number of
drinks of that type currently in the machine.

The class should have an array of five of these structures, initialized
with the following data.

-----------------------------------------------------------------------
Drink Name 				Cost 					Number in Machine 
-----------------------------------------------------------------------
Cola 					1.00 							20
Root beer 				1.00 							20
Orange soda 			1.00 							20
Grape soda 				1.00 							20
Bottled water 			1.50 							20
-----------------------------------------------------------------------

The class should have two public member functions, displayChoices (which
displays a menu of drink names and prices) and buyDrink (which handles
a sale). The class should also have at least two private member functions,
inputMoney, which is called by buyDrink to accept, validate, and return
(to buyDrink) the amount of money input, and dailyReport, which is called
by the destructor to report how many of each drink type remain in the 
machine at the end of the day and how much money was collected. You may
want to use additional functions to make the program more modular.

The client program that uses the class should have a main processing loop
which calls the displayChoices class member function and allows the patron
to either pick a drink or quit the program. If the patron selects a drink,
the buyDrink class member function is called to handle the actual sale.
This function should be passed the patron's drink choice. Here is what
the buyDrink function should do:

	• Call the inputMoney function, passing it the patron's drink choice.
	• If the patron no longer wishes to make the purchase, return all
	  input money.
  	• If the machine is out of the requested soda, display an appropriate
  	  "sold out" message and return all input money.
	• If the machine has the soda and enough money was entered, complete
	  the sale by updating the quantity on hand and money collected
	  information, calculating any change due to be returned to the 
	  patron, and delivering the soda. This last action can be simulated
	  by printing an appropriate "here is your beverage" message.

Input Validation: Only accept valid menu choices. Do not deliver a 
beverage if the money inserted is less than the price of the selected
drink.*/

#include <iostream>
#include <iomanip>

using namespace std;

class Machine{
public:
	Machine();
	~Machine();
	void displayChoices();
	void buyDrink(char&, double&);
	char chooseDrink();

	
		//dailyReport();
	//}

private:
	void inputMoney(double&);
	void dailyReport();

	struct Drink{
		string name;
		double cost;
		int inMachine;
		Drink();
		Drink(string, double, int);/*
			name = n;
			cost = c;
			inMachine = in;
		}*/
	};

	int SIZE;
	Drink drinks[5];
};

Machine::Drink::Drink(){

}

Machine::Drink::Drink(string n, double c, int in){
	name = n;
	cost = c;
	inMachine = in;
}

Machine::Machine(){

	SIZE = 5;
	drinks[0].name = "Coca Cola"; 			drinks[0].cost = 1; drinks[0].inMachine = 20;
	drinks[1].name = "Root Beer"; 		drinks[1].cost = 1; drinks[1].inMachine = 20;
	drinks[2].name = "Orange Soda"; 	drinks[2].cost = 1; drinks[2].inMachine = 20;
	drinks[3].name = "Grape Soda"; 		drinks[3].cost = 1; drinks[3].inMachine = 20;
	drinks[4].name = "Water   "; 	drinks[4].cost = 1; drinks[4].inMachine = 20;

}

Machine::~Machine(){

	dailyReport();

}

void Machine::displayChoices(){

	cout << "\n\n\tDrink name\t\tCost\tQuantity";
	cout << "\n\t******************************************";
	for(int i = 0; i < SIZE; i++){
		cout << "\n\t" << drinks[i].name << "\t\t" << 
		drinks[i].cost << "\t\t" << drinks[i].inMachine;
	}
	cout << "\n\nOptions: (P)urchase or (q)uit: ";
}

void Machine::buyDrink(char& choice, double& money){

	inputMoney(money);
	choice = chooseDrink();

}

char Machine::chooseDrink(){
	char choice;

	cout << "\n(C)oke, (R)oot Beer, (O)range Soda ";
	cout << "(G)rape Soda, (W)ater: ";
	cin >> choice;

	return choice;
}

void Machine::inputMoney(double& change){
	double monies;

	cout << fixed << setprecision(2);
	cout << "\nEnter some change. You currently have " << change << " ";
	cin >> monies;
	while(monies < 0 || monies > change){
		"\nYeah... That's not gonna work. Try again: ";
		cin >> monies;
	}
	change -= monies;
}

void Machine::dailyReport(){

	displayChoices();

}

void printTitle();

int main(){
	Machine mac;
	bool working = true;
	char option;
	double money = 5;

	printTitle();
	while(working){
		mac.displayChoices();
		cin >> option;

		switch(option){
			case 'p':
				mac.buyDrink(option, money);
				break;
			case 'q':
				working = false;
				break;
			default:
				cout << "\nEnter another something ";
				cin >> option;
				break;
		}
	}

	return 0;
}

void printTitle(){

	cout << "\n***************************";
	cout << "\nDrink Machine Simulator   |";
	cout << "\n***************************";

}