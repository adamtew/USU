/*Write a program that will predict the size of a population of organisms. The
program should ask the user for the starting number of organisms, their average
daily population increase (as a percentage of current population), and the number
of days they will multiply. A loop should display the size of the population for
each day.

	Input Validation: The program should not accept a number less than two for the
	starting size of the population, a negative number for average daily population
	increase, or a number less than one for the number of days they will multiply.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

int main(){
	int daysMultiplied;
	double curPop, pIncrease, organisms;

	cout << "\n**************";
	cout << "\nPopulation   |";
	cout << "\n**************";

	cout << "\n\nEnter the starting number of organisms, their average percent";
	cout << "\nincrease in population, and the number days they will multiply.";
	cout << "\n\nStarting Organisms: ";
	cin >> organisms;
	while(organisms <= 2){
		cout << "\nEnter a number greater than 2";
		cin >> organisms;
	}
	cout << "Percent Increase: ";
	cin >> pIncrease;
	while(pIncrease < 0){
		cout << "\nEnter a non-negative number";
		cin >> pIncrease;
	}
	cout << "Days Multiplied: ";
	cin >> daysMultiplied;
	while(daysMultiplied <= 0){
		cout << "\nEnter a number greater than 0";
		cin >> daysMultiplied;
	}

	
	cout << "\n\n\t------------------------";
	cout << "\n\tDays\tPopulation at " << pIncrease << "%";
	cout << "\n\t------------------------";
	pIncrease = pIncrease / 100;
	cout << fixed << setprecision(2);
	for(int i = 1; i <= daysMultiplied; i++){
		organisms = organisms + (i * organisms * pIncrease);
		cout << "\n\t " << i << "\t    " << organisms;
	}

	cout << endl;

	return 0;
}