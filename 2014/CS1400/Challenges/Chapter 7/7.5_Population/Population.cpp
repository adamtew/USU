#include "Population.h"

using namespace std;

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