#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>

using namespace std;

class Calculator{
public:
	Calculator();

	void add(double value);
	void subtract(double value);
	void multiply(double value);
	void divide(double value);
	double getTotal();
	char menu();
	void choice();
//
//	~Calculator()
//	{
//
//	}

private:
	double total, value;

};

#endif
