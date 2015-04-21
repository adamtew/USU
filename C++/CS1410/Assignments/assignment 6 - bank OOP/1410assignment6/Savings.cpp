#include "Account.h"
#include "Savings.h";
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>

using namespace std;

int Savings::numberOfSavingsAccounts = 0;

Savings::Savings() : Account("Savings")
{

}

Savings::Savings(int actNumber, string user, double bal, double interest) : Account("Savings")
{
	
	r_accountNumber = actNumber;
	r_money = bal;
	r_name = user;
	r_interest = interest;
	numberOfSavingsAccounts += 1;
}

Savings::Savings(const Savings& rOther) : Account("Savings")
{
	r_accountNumber = rOther.r_accountNumber;
	r_accountType = rOther.r_accountType;
	r_active = rOther.r_active;
	r_name = rOther.r_name;
	r_money = rOther.r_money;
	r_interest = rOther.r_interest;
}

bool Savings::handleTransaction(double cost)
{
	r_money += cost;
	r_applied = true;
	return r_applied;
}

void Savings::handleUpdate()
{
	if (r_active)
	{
		r_money += r_money * r_interest;
		r_applied = true;
	}
	else r_applied = false;
}

double Savings::getInterest()
{
	
	return static_cast<double>(r_money)* r_interest;
}

bool Savings::operator==(Savings rLeft)
{
	bool ret = true;

	if ((Account)rLeft == (Account)*this)
		ret = true;
	else
		ret = false;

	return ret;
}

bool Savings::operator==(int rleft)
{
	bool ret = true;
	if (rleft != r_accountNumber)
		ret = false;

	return ret;
}

ostream& operator<<(ostream& os, Savings& rLeft)
{
	cout << rLeft.r_name << " (" + rLeft.r_accountType + ")";
	return os;
}

int Savings::getNumberOfSavingsAccounts()
{
	return numberOfSavingsAccounts;
}