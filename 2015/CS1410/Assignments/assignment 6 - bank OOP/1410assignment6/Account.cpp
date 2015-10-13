#include "Account.h"
#include <string>

using namespace std;

int Account::numberOfAccounts = 0;

Account::Account(string accountType)
{
	r_active = true;
	r_accountType = accountType;
	numberOfAccounts += 1;
}

Account::~Account()
{
	numberOfAccounts -= 1;
}

bool Account::operator==(Account rLeft)
{
	bool ret = true;
	if (rLeft.r_accountNumber != r_accountNumber)
		ret = false;
	if (rLeft.r_accountType != r_accountType)
		ret = false;
	if (rLeft.r_active != r_active)
		ret = false;

	return ret;
}

bool Account::operator==(int rleft)
{
	bool ret = true;
	if (rleft != r_accountNumber)
		ret = false;

	return ret;
}

int Account::getAct()
{
	return r_accountNumber;
}

void Account::setAct(int act)
{
	r_accountNumber = act;
}

string Account::getName()
{
	return r_name;
}

double Account::getBalance()
{
	return r_money;

}

void Account::setActiveState(bool set)
{
	r_active = set;
}

bool Account::getActiveState()
{
	return r_active;
}

int Account::getNumberOfAccounts()
{
	return numberOfAccounts;
}