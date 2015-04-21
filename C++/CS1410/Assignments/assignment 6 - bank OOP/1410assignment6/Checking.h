#ifndef CHECKING_H
#define CHECKING_H


#include "Account.h";

using namespace std;

class Checking : public Account {
private:
	static int numberOfCheckingAccounts;
	int r_checks;

protected:
	double r_fee;
	


public:
	Checking();
	Checking(int actNumber, string user, double bal, double fee);
	Checking(const Checking& rOther); //Copy constructor

	

	bool handleTransaction(double cost);
	void handleUpdate();
	double getFees();

	friend ostream& operator<<(ostream& os, Checking& rOther);
	bool operator==(Checking rLeft);
	bool operator==(int rleft);
	bool operator==(string rleft);

	static int getNumberOfCheckingAccounts();


};

#endif