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
	// printf("something %a\n","");
	return c;
}

void Calculator::choice()
{
	char c;

	while(menu() != 'q')
	{
		switch(menu())
		{
			case 'a':add(5);
				break;
			default :
				break;
		}
	}
}