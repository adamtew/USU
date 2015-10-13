/*A student has established the following monthly budget:

	Housing				500.00
	Utilities			150.00
	Household expenses	 65.00
	Transportation		 50.00
	Food				250.00
	Medical				 30.00
	Insurance			100.00
	Entertainment		150.00
	Clothing			 75.00
	Miscellaneous		 50.00

Write a modular program that declares a MonthlyBudget structure with member variables
to hold each of these expense vategories. The program should create two MonthlyBudget
structure variables. The first will hold the budget figures given above.
The second will hold the user-enter amounts actually spend during the past month.
Using Program 7-19 as a model, the program should create a screen form that displays
each category name and its budgeted amount, then positions the cursor next to it for
the user to enter the amount actually spend in that category. Once the user data has 
all been entered, the program should compute and display the amount over or under
budget the student's expenditures were in each category, as well as the amount over
or under for the entire month.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <windows.h>
using namespace std;

struct MonthlyBudget{
	double housing, utilities, householdExpenses, transportation, food, medical,
	insurance, entertainment, clothing, misc;

	MonthlyBudget(double h = 0, double u = 0, double hE = 0, double t = 0, 
		double f = 0, double m = 0, double i = 0, double e = 0, double c = 0, 
		double mi = 0){
		housing = h;
		utilities = u;
		householdExpenses = hE;
		transportation = t;
		food = f;
		medical = m;
		insurance = i;
		entertainment = e;
		clothing = c;
		misc = mi;
	}
};

void printCat(const MonthlyBudget&);
void printTitle();
void placeCursor(HANDLE, int, int);

int main(){
	MonthlyBudget goal(500.00, 150.00, 65.00, 50.00, 250.00, 30.00, 100.00, 
		150.00, 75.00, 50.00), actual;

	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

	printTitle();

	return 0;
}

void printCat(const MonthlyBudget& goal){

}

void printTitle(){

	cout << "\n******************************";
	cout << "\nMonthly Budget Screen Form   |";
	cout << "\n******************************";

}

void placeCursor(HANDLE screen, int row, int col){
	COORD position;
	//position.x = row;
	//position.y = col;
	SetConsoleCursorPosition(screen, position);
}