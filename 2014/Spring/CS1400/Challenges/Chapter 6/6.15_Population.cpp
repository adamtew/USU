/*In a population, the birth rate is in the percentage increase of the population due
to births, and the death rate is in the percentage decrease of th epopulation due to
deaths. Write a program that asks for the following:

	• The starting size of a population (minimum 2)
	• The annual birth rate
	• The annual death rate
	• The number of years to display (minimum 1)

The program should then display the starting population and the projected population
at the end of each year. It should use a function that calculates and returns the
projected new size of the population after a year. The formula is

	N = P(1 + B) (1 - D)

where N is the new population size, P is the previous population size, B is the birth
rate, and D is a death rate. Annual birth rate and death rate are the typical number
number of births and deaths in a year per 1000 people, expressed as a decimal. So for
example, if there are normally about 32 births and 26 deaths per 1000 people in a
given population, the birth rate would be .032 and the death rate would be .026.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <iomanip>

using namespace std;

void printTitle();
double calcPop(int, double, double);

int main(){
	int startingSize, years;
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
	cin >> years;

	population = calcPop(startingSize, birthRate, deathRate);

	cout << fixed << setprecision(1);
	cout << "\n\t------------------";
	cout << "\n\tYears\tPopulation";
	cout << "\n\t------------------";
	for(int i = 1; i <= years; i++){
		cout << "\n\t" << i << "\t" << setw(10) << i * population;
	}

	return 0;
}

void printTitle(){

	cout << "\n**************";
	cout << "\nPopulation   |";
	cout << "\n**************";

}

double calcPop(int P, double B, double D){
	B = B / 100;
	D = D / 100;
	double N = (P * (1 + B)) * (1 - D);

	return N;
}