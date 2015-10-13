#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

using namespace std;

class Account{
private:
	static int numberOfAccounts;

protected:
	int r_accountNumber;
	string r_accountType;
	bool r_active;
	char* r_myName;
	double r_money;
	string r_name;
	bool r_applied;

public:
	Account(string accountType);

	Account(Account& rOther)
		: r_accountType(rOther.r_accountType),
		r_name(rOther.r_name),
		r_money(rOther.r_money),
		r_active(rOther.r_active)
	{

	}

	~Account();

	bool operator==(Account rLeft);
	bool operator==(int rleft);

	void setActiveState(bool set);

	bool getActiveState();
	double getBalance();
	int getAct();
	void setAct(int);
	string getName();

	static int getNumberOfAccounts();

};

#endif;	