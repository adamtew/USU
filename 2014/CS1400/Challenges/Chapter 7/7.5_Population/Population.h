#ifndef POPULATION_H
#define POPULATION_H

#include <iostream>

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

#endif