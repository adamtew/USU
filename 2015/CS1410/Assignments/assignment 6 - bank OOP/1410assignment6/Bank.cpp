#include "Account.h"
#include "Bank.h"
#include <vector>
#include <sstream>

Bank::Bank()
{
	checkingAccounts = 0;
	savingsAccounts = 0;

	checkingActs.reserve(1);
	savingsActs.reserve(1);

}

Checking Bank::createChecking(int actNumber, string user, double bal, double fee)
{
	Checking c = Checking( actNumber,  user,  bal,  fee);
	checkingActs.push_back(c);
	//cAccounts[actNumber] = c;
	checkingAccounts++;
	return c;
}

Savings Bank::createSavings(int actNumber, string user, double bal, double interest)
{
	Savings s = Savings( actNumber,  user,  bal,  interest);
	savingsActs.push_back(s);
	//sAccounts[actNumber] = s;
	savingsAccounts++;
	return s;
}

bool Bank::transaction(int act, double cost)
{
	if (findAccountT(act, cost))
		return true;
	else
		return false;
}

void Bank::update(int act)
{
	findAccountU(act);
}

bool Bank::transfer(int act1, int act2)
{
	return(findAccountTransfer(act1, act2));
}

bool Bank::isChecking(int act)
{
	for (int i = 0; i < checkingActs.capacity(); i++)
		if (checkingActs[i] == act)
			return true;
	return false;
}

bool Bank::isSavings(int act)
{
	for (int i = 0; i < savingsActs.capacity(); i++)
		if (savingsActs[i] == act)
			return true;
	return false;
}

ostream& operator<<(ostream& os, Bank& rOther)
{
	cout << "\nListing all accounts...\n";
	cout << "There are a total of " << Account::getNumberOfAccounts() << " accounts\n";
	cout << "There are " << Savings::getNumberOfSavingsAccounts() << " savings accounts\n";
	cout << "There are " << Checking::getNumberOfCheckingAccounts() << " checking accounts\n";

	return os;
}

bool Bank::findAccountT(int act, double cost)
{
	for (int i = 0; i < count; i++)
	{
		if (checkingActs[i] == act)
		{
			if (checkingActs[i].handleTransaction(cost))
				return true;
			else
				return false;
		}
		else if (savingsActs[i] == act)
		{
			if (savingsActs[i].handleTransaction(cost))
				return true;
			else
				return false;
		}
		//cout << "end";
	}
}

void Bank::findAccountU(int act)
{
	for (int i = 0; i < count; i++)
	{
		if (checkingActs[i] == act)
		{
			checkingActs[i].handleUpdate();
			break;
		}
		else if (savingsActs[i] == act)
		{
			savingsActs[i].handleUpdate();
			break;
		}
	}
}

bool Bank::findAccountTransfer(int act, int act2)
{
	for (int i = 0; i < count; i++)
	{
		if (checkingActs[i] == act)
		{
			Checking c = checkingActs[i];
			c.setAct(act2);
			checkingActs.push_back(c);
			checkingActs.erase(checkingActs.begin() + i);

			return true;
		}
		else if (savingsActs[i] == act)
		{
			Savings s = savingsActs[i];
			s.setAct(act2);
			savingsActs.push_back(s);
			savingsActs.erase(savingsActs.begin() + i);
			return true;
		}
	}
	return false;
}

Savings Bank::getSavings(int act)
{
	return findSavings(act);
}

Checking Bank::getChecking(int act)
{
	return findChecking(act);
}

Checking Bank::findChecking(int act)
{
	//for (int i = 0; i < count; i++)
	//	if (cAccounts[i] == act)
	//		return cAccounts[i];
	int one = 0;
	try
	{
		for (int i = 0; i < checkingActs.capacity(); i++)
		{
			if (checkingActs[i] == act)
			{
				r_worked = true;
				return checkingActs[i];
			}

		}
		r_worked = false;
	}
	catch (out_of_range o)
	{
		cout << "error: " << o.what() << endl;
	}
	Checking a;
	return a;
}

Savings Bank::findSavings(int act)
{
	for (int i = 0; i < count; i++)
		if (savingsActs[i] == act)
			return savingsActs[i];
	int one = 0;
	try
	{
		for (int i = 0; i < savingsActs.capacity(); i++)
		{
			if (savingsActs[i] == act)
			{
				r_worked = true;
				return savingsActs[i];
			}

		}
		r_worked = false;
	}
	catch (out_of_range o)
	{
		cout << "error: " << o.what() << endl;
	}
	Savings s;
	return s;
}