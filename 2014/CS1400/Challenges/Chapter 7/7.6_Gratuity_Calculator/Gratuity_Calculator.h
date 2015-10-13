#ifndef GRATUITY_CALCULATOR_H
#define GRATUITY_CALCULATOR_H

#include <iostream>

using namespace std;

class Tips{

private:
	double taxRate;

public:
	Tips();
	Tips(double);

	double computeTip(double, double);

};

#endif