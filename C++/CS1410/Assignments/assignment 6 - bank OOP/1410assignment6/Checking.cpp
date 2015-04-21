#include "Checking.h";
#include "Account.h";
#include <sstream>
#include <string>
#include <stdio.h>

using namespace std;


int Checking::numberOfCheckingAccounts = 0;

Checking::Checking() : Account("Checking")
{

}

Checking::Checking(int actNumber, string user, double bal, double fee) : Account("Checking")
{
	r_accountNumber = actNumber;
	r_name = user;
	r_money = bal;
	r_fee = fee;
	r_checks = 0;


	numberOfCheckingAccounts += 1;
}

Checking::Checking(const Checking& rOther) : Account("Checking") // Copy constructor
{
	r_accountNumber = rOther.r_accountNumber;
	r_accountType = rOther.r_accountType;
	r_active = rOther.r_active;
	r_name = rOther.r_name;
	r_money = rOther.r_money;
	r_fee = rOther.r_fee;
	r_checks = rOther.r_checks;
}

bool Checking::handleTransaction(double cost)
{

	if (cost > 0)
	{
		r_money += cost;
	}
	else if (cost < 0 && r_money >= abs(cost))
	{
		r_money += cost;
		r_checks++;
		r_applied = true;
	}
	else
	{
		r_money -= 25;
		r_checks++;
		r_applied = false;
	}
	return r_applied;
}

void Checking::handleUpdate()
{
	if (r_active)
	{

		r_money -= (r_fee * r_checks);
		r_checks = 0;
		r_applied = true;
	}
	else
		r_applied = false;
}

double Checking::getFees()
{
	return r_fee * r_checks;
}

bool Checking::operator==(Checking rLeft)
{
	bool ret = true;
	if ((Account)rLeft == (Account)*this)
		ret = true;
	else
		ret = false;

	return ret;
}

bool Checking::operator==(int rleft)
{
	bool ret = true;

	if (rleft != r_accountNumber)
		ret = false;

	return ret;
}

bool Checking::operator==(string rleft)
{
	bool ret = true;

	if (rleft != r_accountType)
		ret = false;

	return ret;
}

ostream& operator<<(ostream& os, Checking& rOther)
{

	cout << rOther.r_name << " (" + rOther.r_accountType + ")";
	
	return os;
}

int Checking::getNumberOfCheckingAccounts()
{
	return numberOfCheckingAccounts;
}
