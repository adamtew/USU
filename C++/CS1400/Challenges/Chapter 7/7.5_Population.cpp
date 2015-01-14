/*In a population, the birth rate and death rate are calculated as follows:

	Birth Rate = Number of Births / Population
	Death Rate = Number of Deaths / Population

For example, in a population of 100,000 that has 8,000 births and 6,000 deaths per
year.

	Birth Rate = 8,000 / 100,000 = 0.08
	Death Rate = 6,000 / 100,000 = 0.06

Design a Population class that stores a current population, annual number of births,
and annual number of deaths for some geographic area. The class should allow these
three values to be set in either of two ways: by passing arguments to a 
three-parameter constructor when a new Population object is created or by calling
the setPopulation, setBirths, and setDeaths class member functions. In either case,
if a population figure less than 2 is passed to the class, use a default value of 2.
If a birth or death figure less than 0 is passed in, use a default value of 0. The 
class should also have getBirthRate and getDeathRate functions that compute and
return the birth and death rates. Write a short program that uses the Population
class and illustrats its capabilities.*/
// Adam Tew ---- CS1400
#include <iostream>
#include <iomanip>

using namespace std;

class Population{

private:
	int population, births, deaths;

public:
	Population();
	Population(int, int, int);

	void setPopulation(int);
	void setBirths(int);
	void setDeaths(int);
	double getDeathRate();
	double getBirthRate();

};

Population::Population(){

	births = 5;
	deaths = 5;
	population = 5;

}

Population::Population(int b, int d, int p){

	if(p < 2)p = 2;
	if(b < 0)b = 0;
	if(d < 0)d = 0;
	births = b;
	deaths = d;
	population = p;

}


void Population::setPopulation(int p){
	if(p < 2)p = 2;
	population = p;
}

void Population::setBirths(int b){
	if(b < 0)b = 0;
	births = b;
}

void Population::setDeaths(int d){
	if(d < 0)d = 0;
	deaths = d;
}

double Population::getDeathRate(){
	double dRate = deaths / population;
	return dRate;
}

double Population::getBirthRate(){
	double bRate = births / population;
	return bRate;
}

void printTitle();

int main(){
	double bith = 5, death = 5, population = 5, bRate, dRate;
	Population pop, ipop(bith, death, population);

	printTitle();

	cout << fixed << setprecision(5);
	cout << "\n\npop birth rate: " << pop.getBirthRate();
	cout << "\npop death rate: " << pop.getDeathRate();

	cout << "\n\nipop birth rate: " << ipop.getBirthRate();
	cout << "\nipop death rate: " << ipop.getDeathRate();

	ipop.setDeaths(800);
	ipop.setBirths(100);
	ipop.setPopulation(5);

	cout << "\n\nipop birth rate: " << ipop.getBirthRate();
	cout << "\nipop death rate: " << ipop.getDeathRate();

	return 0;
}

void printTitle(){
	
	cout << "\n**************";
	cout << "\nPopulation   |";
	cout << "\n**************";

}