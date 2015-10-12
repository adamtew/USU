#include "Account.h"
#include "Savings.h"
#include "Checking.h"
#include "Bank.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

void mySwitch(char);
void myLoop();
void options();
void userS();
void userC();
void userTransaction();
void userUpdate();
void list();

Bank b;

int main(int argc, char** pArgv){
	
	if (argc > 1)
	{
		int accounNumber;
		int accountNumber2;
		string name;
		double balance;
		double fee;
		double interestRate;

		cout << pArgv[1];
		char x = 'q';
		ifstream fin(pArgv[1]);
		if (fin.is_open())
		{
			while (!fin.eof())
			{
				cout << "\n";
				switch (x)
				{
				case 's': 
					fin >> accounNumber;
					fin >> name;
					fin >> balance;
					fin >> fee;
					b.createSavings(accounNumber, name, balance, fee);
					cout << "new account...\n";
					cout << b.getSavings(accounNumber) << ": balance is $" << b.getSavings(accounNumber).getBalance() << endl;
					break;
				case 'c': 
					fin >> accounNumber;
					fin >> name;
					fin >> balance;
					fin >> interestRate;
					b.createChecking(accounNumber, name, balance, interestRate);
					cout << "new account...\n";
					cout << b.getChecking(accounNumber) << ": balance is $" << b.getChecking(accounNumber).getBalance() << endl;
					break;
				case 't': 
					fin >> accounNumber;
					fin >> balance;
					cout << "transaction...\n";
					if (b.transaction(accounNumber, balance))
					{
						if (b.isChecking(accounNumber))
						{
							cout << b.getChecking(accounNumber) << ": $" << balance << " applied to account\n";
							cout << b.getChecking(accounNumber) << ": balance is $" << b.getChecking(accounNumber).getBalance() << endl;
						}
						else if (b.isSavings(accounNumber))
						{
							cout << b.getSavings(accounNumber) << ": $" << balance << " applied to account\n";
							cout << b.getSavings(accounNumber) << ": balance is $" << b.getSavings(accounNumber).getBalance() << endl;
						}
					}
					else
					{
						if (b.isChecking(accounNumber))
						{
							cout << b.getChecking(accounNumber) << ": $" << balance << " rejected\n";
							cout << b.getChecking(accounNumber) << ": $" << -25 << " applied to account\n";
							cout << b.getChecking(accounNumber) << ": balance is $" << b.getChecking(accounNumber).getBalance() << endl;
						}
						else if (b.isSavings(accounNumber))
						{
							cout << b.getSavings(accounNumber) << ": $" << balance << " rejected\n";
							cout << b.getSavings(accounNumber) << ": balance is $" << b.getSavings(accounNumber).getBalance() << endl;
						}
					}
					break;
				case 'u': 
					double getInterest;
					double myFees;
					fin >> accounNumber;
					if (b.isSavings(accounNumber))
						getInterest = b.getSavings(accounNumber).getInterest();
					if (b.isChecking(accounNumber))
						myFees = b.getChecking(accounNumber).getFees();
					cout << "update...\n";
					b.update(accounNumber);
					if (b.isChecking(accounNumber))
					{
						cout << b.getChecking(accounNumber) << ": $-"  << myFees << " applied to account\n";
						cout << b.getChecking(accounNumber) << ": balance is $" << b.getChecking(accounNumber).getBalance() << endl;
					}
					else if (b.isSavings(accounNumber))
					{
						cout << b.getSavings(accounNumber) << ": $" << getInterest << " applied to account\n";
						cout << b.getSavings(accounNumber) << ": balance is $" << b.getSavings(accounNumber).getBalance() << endl;
					}
					break;
				case 'r':
					fin >> accounNumber;
					fin >> accountNumber2;
					cout << "transferring...\n";
					
					cout << b.getChecking(accounNumber) << ": $" << b.getChecking(accounNumber).getBalance() << " transferred to checking account " << accountNumber2 << endl;
					b.transfer(accounNumber, accountNumber2);
					
					if (b.isChecking(accountNumber2))
						cout << b.getChecking(accountNumber2) << ": balance is $" << b.getChecking(accountNumber2).getBalance() << endl;
					else if (b.isSavings(accountNumber2))
						cout << b.getSavings(accountNumber2) << ": balance is $" << b.getSavings(accountNumber2).getBalance() << endl;
					
					break;
				case 'd': 
					cout << b;
					break;
				default:
					break;
				}
				fin >> x;
			}
			fin.close();
		}
			

	}
	else
	{
		cout << "\nWelcome to the bank. What would you like to do?\n";
		options();
		myLoop();
	}




	return 0;
}

void mySwitch(char choice)
{
	int accounNumber;
	string name;
	double balance;
	double fee;

	switch (choice)
	{
	case 's':userS();
		break;
	case 'c':userC();
		break;
	case 't':userTransaction();
		break;
	case 'u':userUpdate();
		break;
	case 'd':list();
		break;
	case 'q': 
		break;
	default:cout << "Sorry, try again.";
		break;
	}

}

void myLoop()
{
	char x = 'x';
	cin >> x;
	while (x != 'q')
	{
		mySwitch(x);
		options();
		cin >> x;
	}
}

void options()
{
	cout << "\nCreate (S)avings Account";
	cout << "\nCreate (C)hecking Account";
	cout << "\n(T)ransaction";
	cout << "\n(U)pdate Account";
	cout << "\nList accounts (D):";
	cout << "\n(Q)uit";
	cout << "\n\tOption: ";
	
}


void userC()
{
	int accounNumber;
	string name;
	double balance;
	double fee;

	cout << "Please enter some information:\n";
	cout << "Account Number: ";
	cin >> accounNumber;
	cout << "Account holders name: ";
	//getline(cin, name);
	cin >> name;
	cout << "The initial balance: ";
	cin >> balance;
	cout << "The fee for each transaction: ";
	cin >> fee;

	b.createChecking(accounNumber, name, balance, fee);

	cout << "new account...\n";
	cout << b.getChecking(accounNumber) << ": balance is $" << b.getChecking(accounNumber).getBalance() << endl;
}

void userS()
{
	int accounNumber;
	string name;
	double balance;
	double interestRate;

	cout << "Please enter some information:\n";
	cout << "Account Number: ";
	cin >> accounNumber;
	cout << "Account holders name: ";
	//getline(cin, name);
	cin >> name;
	cout << "The initial balance: ";
	cin >> balance;
	cout << "The interest rate: ";
	cin >> interestRate;
	
	b.createSavings(accounNumber, name, balance, interestRate);

	cout << "new account...\n";
	cout << b.getSavings(accounNumber) << ": balance is $" << b.getSavings(accounNumber).getBalance() << endl;
}

void userTransaction()
{
	int actNumber;
	double cost;
	cout << "\nPlease enter the account number and amount for transaction\n";
	cout << "Account Nmber: ";
	cin >> actNumber;
	cout << "Amount: ";
	cin >> cost;

	cout << "transaction...\n";
	if (b.transaction(actNumber, cost))
	{
		if (b.isChecking(actNumber))
		{
			cout << b.getChecking(actNumber) << ": $" << cost << " applied to account\n";
			cout << b.getChecking(actNumber) << ": balance is $" << b.getChecking(actNumber).getBalance() << endl;
		}
		else if (b.isSavings(actNumber))
		{
			cout << b.getSavings(actNumber) << ": $" << cost << " applied to account\n";
			cout << b.getSavings(actNumber) << ": balance is $" << b.getSavings(actNumber).getBalance() << endl;
		}
	}
	else
	{
		if (b.isChecking(actNumber))
		{
			cout << b.getChecking(actNumber) << ": $" << cost << " rejected\n";
			cout << b.getChecking(actNumber) << ": $" << -25 << " applied to account\n";
			cout << b.getChecking(actNumber) << ": balance is $" << b.getChecking(actNumber).getBalance() << endl;
		}
		else if (b.isSavings(actNumber))
		{
			cout << b.getSavings(actNumber) << ": $" << cost << " rejected\n";
			cout << b.getSavings(actNumber) << ": balance is $" << b.getSavings(actNumber).getBalance() << endl;
		}
	}
}

void userUpdate()
{
	double getInterest;
	double myFees;
	int accounNumber;
	cout << "\nPlease enter the account number you wish to update\n";
	cout << "Account: ";
	cin >> accounNumber;
	if (b.isSavings(accounNumber))
		getInterest = b.getSavings(accounNumber).getInterest();
	if (b.isChecking(accounNumber))
		myFees = b.getChecking(accounNumber).getFees();
	cout << "update...\n";
	b.update(accounNumber);
	if (b.isChecking(accounNumber))
	{
		cout << b.getChecking(accounNumber) << ": $-" << myFees << " applied to account\n";
		cout << b.getChecking(accounNumber) << ": balance is $" << b.getChecking(accounNumber).getBalance() << endl;
	}
	else if (b.isSavings(accounNumber))
	{
		cout << b.getSavings(accounNumber) << ": $" << getInterest << " applied to account\n";
		cout << b.getSavings(accounNumber) << ": balance is $" << b.getSavings(accounNumber).getBalance() << endl;
	}
}
void list()
{
	cout << b;
}