#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP

#include <iostream>
#include <sstream>

using namespace std;

class Calculator{
public:
	Calculator();

	bool firstVal();
	void runningTotal(char rOperation, double rValue);
	void add(double rValue);
	void subtract(double rValue);
	void multiply(double rValue);
	void divide(double rValue);
	double getTotal();
	char menu();
	void choice();

	~Calculator()
	{

	}

private:
	double m_total, m_value;
	stringstream m_rt, m_leftParen;
	string m_s;
	char m_operation;

};

#endif
