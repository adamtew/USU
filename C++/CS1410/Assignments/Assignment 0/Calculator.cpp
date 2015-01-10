#include "Calculator.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;

Calculator::Calculator()
{
	total = 0;
}

void Calculator::add(double value)
{
	total += value;
}

void Calculator::subtract(double value)
{
	total -= value;
}

void Calculator::multiply(double value)
{
	total *= value;
}

void Calculator::divide(double value)
{
	//total /= value;
	total = total / value;
}

double Calculator::getTotal()
{
	return total;
}

char Calculator::menu()
{
	char c;

	cout << "\n\t*** Calculator ***\n";
	cout << "\n\tA: Add a value";
	cout << "\n\tS: Subtract a value";
	cout << "\n\tM: Multiple by a value";
	cout << "\n\tD: Divide by a value";
	cout << "\n\tT: Get the total\n";
	cout << "\n\tQ: Quit\n";
	cout << "\n\n\tEnter Decision: ";
	cin >> c;

	return c;
}

void Calculator::choice()
{
	char c;

	while(c != 'q')
	{
		c = menu();
		switch(c)
		{
			case 'A':
			case 'a':
				cout << "\n\n\tAdd: ";
				cin >> value;	
				add(value);
				break;
			case 'S':
			case 's':
				cout << "\n\n\tSubtract: ";
				cin >> value;
				subtract(value);
				break;
			case 'M':
			case 'm':
				cout << "\n\n\tMultiply: ";
				cin >> value;
				multiply(value);
				break;
			case 'D':
			case 'd':
				cout << "\n\n\tDivide: ";
				cin >> value;
				divide(value);
				break;	
			case 't':
				cout << "\n\n\tTotal: " << getTotal();
				break;
			case 'Q':
			case 'q':
			default :
				c = 'q';
				break;
		}
	}
}
