#include "Calculator.hpp"
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

Calculator::Calculator()
{
	m_total = 0;
}

bool Calculator::firstVal()
{
	if(m_total == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Calculator::runningTotal(char rOperations, double rValue)
{
	m_leftParen << "(";
	if(firstVal())
	{
		m_rt << " " << rOperations << " " << rValue;
	}
	else
	{
		m_rt << ") " << rOperations << " " << rValue;
	}
	m_s =  m_leftParen.str() + "(0.0" + m_rt.str() + ")";
}

void Calculator::add(double rValue)
{
	m_operation = '+';
	runningTotal(m_operation, rValue);
	m_total += rValue;
	
}

void Calculator::subtract(double rValue)
{
	m_operation = '-';
	runningTotal(m_operation, rValue);
	m_total -= rValue;
}

void Calculator::multiply(double rValue)
{
	m_operation = '*';
	runningTotal(m_operation, rValue);
	m_total *= rValue;
}

void Calculator::divide(double rValue)
{
	m_operation = '/';
	runningTotal(m_operation, rValue);
	m_total /= rValue;
}

double Calculator::getTotal()
{
	return m_total;
}

char Calculator::menu()
{
	char c;

	cout << "\n\t*** Calculator ***\n";
	cout << "\n\tA: Add a rValue";
	cout << "\n\tS: Subtract a rValue";
	cout << "\n\tM: Multiple by a rValue";
	cout << "\n\tD: Divide by a rValue";
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
				cin >> m_value;	
				add(m_value);
				break;
			case 'S':
			case 's':
				cout << "\n\n\tSubtract: ";
				cin >> m_value;
				subtract(m_value);
				break;
			case 'M':
			case 'm':
				cout << "\n\n\tMultiply: ";
				cin >> m_value;
				multiply(m_value);
				break;
			case 'D':
			case 'd':
				cout << "\n\n\tDivide: ";
				cin >> m_value;
				divide(m_value);
				break;	
			case 't':
				cout << "\n\n\tTotal: " << getTotal();
				cout << "\n\t" << m_s << " = " << m_total;
				break;
			case 'Q':
			case 'q':
				break;
			default :
				cout << "\n\n\t" << c << " Is not valid. Try again.";
				break;
		}
	}
}
