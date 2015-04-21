//#include "Account.h"
//#include "Savings.h"
//#include "Checking.h"
//#include "Bank.h"
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <sstream>
//
//using namespace std;
//
//int main()
//{
//	cout << "\n: " << Account::getNumberOfAccounts() << endl;
//	Bank b;
//	cout << "\n: " << Account::getNumberOfAccounts() << endl;
//	cout << b;
//
//	b.createChecking(1, "al", 501, 50);
//	cout << b.getChecking(1) << ": has a balance of " << b.getChecking(1).getBalance() << endl;
//	b.createSavings(6, "rob", 453.77, .05);
//	cout << b.getSavings(6) << ": has a balance of " << b.getSavings(6).getBalance() << endl;
//	cout << b;
//
//
//	cout << "transaction...\n";
//	cout << b.getChecking(1) << ": has a balance of " << b.getChecking(1).getBalance() << endl;
//	if (b.transaction(1, 502))
//		cout << b.getChecking(1) << ": 50 applied to account\n";
//	else
//		cout << b.getChecking(1) << ": 50 NOT applied to account\n";
//	cout << b.getChecking(1) << ": has a balance of " << b.getChecking(1).getBalance() << endl;
//
//	cout << endl;
//
//	cout << "transaction...\n";
//	cout << b.getSavings(6) << ": has a balance of " << b.getSavings(6).getBalance() << endl;
//	b.transaction(6, 50);
//	cout << b.getSavings(6) << ": has a balance of " << b.getSavings(6).getBalance() << endl;
//
//	cout << "-------------\n";
//
//
//	cout << "update...\n";
//	cout << b.getChecking(1) << ": has a balance of " << b.getChecking(1).getBalance() << endl;
//	b.update(1);
//	cout << b.getChecking(1) << ": has a balance of " << b.getChecking(1).getBalance() << endl;
//
//	cout << endl;
//
//	cout << "update...\n";
//	cout << b.getSavings(6) << ": has a balance of " << b.getSavings(6).getBalance() << endl;
//	b.update(6);
//	cout << b.getSavings(6) << ": has a balance of " << b.getSavings(6).getBalance() << endl;
//
//	cout << "\n-------------\n";
//
//	cout << b.getChecking(1) << ": has a balance of " << b.getChecking(1).getBalance() << endl;
//	b.transfer(1, 2);
//	cout << b.getChecking(2) << ": has a balance of " << b.getChecking(2).getBalance() << endl;
//	
//	cout << b.getSavings(6) << ": has a balance of " << b.getSavings(6).getBalance() << endl;
//	b.transfer(6, 7);
//	cout << b.getSavings(7) << ": has a balance of " << b.getSavings(7).getBalance() << endl;
//
//	cout << b;
//
//	return 0;
//}