/*Modify Programming Challenge 15 to also consider the effect on population caused by
people moving into or out of the geographic area. Given as input a starting populaiton
size, the annual birth rate, the annual death rate, the number of individuals that 
typically move into the area each year, and the number of individuals that typically
leave the area each year, the program should project what the population will be
numYears from now. You can either prompt the user to input a value for numYears, or
you can set it within the program*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void printTitle();
double calcPop(int, double, double);

int main(){
	int startingSize, numYears, immigrants, migrants, immigration;
	double birthRate, deathRate, population;

	printTitle();

	cout << "\n\n\tEnter the following data: ";
	cout << "\n\tStarting size: ";
	cin >> startingSize;
	cout << "\tAnnual birth rate: ";
	cin >> birthRate;
	cout << "\tAnnual death rate: ";
	cin >> deathRate;
	cout << "\tYears to display: ";
	cin >> numYears;
	cout << "\tNumber of immigrants: ";
	cin >> immigrants;
	cout << "\tNumber of migrants: ";
	cin >> migrants;

	immigration = immigrants - migrants;

	population = calcPop(startingSize, birthRate, deathRate);

	cout << fixed << setprecision(0);
	cout << "\n\t------------------";
	cout << "\n\tYears\tPopulation";
	cout << "\n\t------------------";
	for(int i = 1; i <= numYears; i++){
		cout << "\n\t" << i << "\t" << setw(10) << (i * population) + immigration;
	}

	return 0;
}

void printTitle(){

	cout << "\n************************";
	cout << "\nTransient Population   |";
	cout << "\n************************";

}

double calcPop(int P, double B, double D){
	B = B / 100;
	D = D / 100;
	double N = (P * (1 + B)) * (1 - D);

	return N;
}