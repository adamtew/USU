#ifndef SAVINGS_H
#define SAVINGS_H

#include "Account.h";
using namespace std;

class Savings : public Account {
private:
	static int numberOfSavingsAccounts;
	double r_interest;

protected:
	

public:
	Savings();
	Savings(int actNumber, string user, double bal, double interest);
	Savings(const Savings& rLeft);

	bool handleTransaction(double cost);
	void handleUpdate();
	static int getNumberOfSavingsAccounts();
	double getInterest();

	bool operator==(Savings rLeft);
	bool operator==(int rleft);
	friend ostream& operator<<(ostream& os, Savings& rOther);

	
};

#endif