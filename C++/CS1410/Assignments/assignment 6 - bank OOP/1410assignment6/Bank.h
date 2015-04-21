#ifndef BANK_H
#define BANK_H

#include "Checking.h"
#include "Savings.h"
#include "Account.h"
#include <vector>

using namespace std;

class Bank {
private:
	int checkingAccounts;
	int savingsAccounts;
	int listOfAccounts;
	bool r_worked;
	const int count = 10;
	//Checking cAccounts[1];
	//Savings sAccounts[1];

	vector<Checking> checkingActs;
	vector<Savings> savingsActs;

	Checking findChecking(int act);
	Savings findSavings(int act);
	bool findAccountT(int act, double cost);
	void findAccountU(int act);
	bool findAccountTransfer(int act, int act2);

	


protected:

public:
	Bank();

	Checking createChecking(int actNumber, string user, double bal, double fee);
	Savings createSavings(int actNumber, string user, double bal, double interest);

	bool transaction(int act, double cost);
	void update(int act);
	bool transfer(int act1, int act2);
	bool isChecking(int act);
	bool isSavings(int act);

	friend ostream& operator<<(ostream& os, Bank& rOther);


	Savings getSavings(int act);
	Checking getChecking(int act);
	

};

#endif
