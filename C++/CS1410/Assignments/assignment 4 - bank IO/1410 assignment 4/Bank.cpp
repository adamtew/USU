#include "Bank.hpp"
#include <string>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <typeinfo>
#include <sstream>
#include <istream>
using namespace std;

Bank::Bank()
{

}

	// Constructor for reading binary files
Bank::Bank(string rFile)
{
	m_oFile = rFile;
	m_file.open(rFile, ios::in | ios::binary);
	if (m_file.is_open())
		if (checkHeader())
		{
			getIndex();
			choice();
		}
		else
			cout << "\nThe header is broken\n";
	else
		cout << "\nUnable to open file " << rFile << ".\n";

	if (m_file.is_open())
		m_file.close();
}

	// Constructor for converting CSV to Binary
Bank::Bank(string rFileInput, string rFileOutput)
{
	m_fileIn.open(rFileInput, ios::in);
	if (m_fileIn.is_open())
		parseCSV();
	else
		cout << "\nUnable to open file " << rFileInput << ".\n";

	m_fileOut.open(rFileOutput, ios::out | ios::binary);
	if (m_fileOut.is_open())
		writeBNK();
	else
		cout << "\nUnable to open file " << rFileOutput << ".\n";
}

void Bank::parseCSV()
{
	m_BNKHeader.s[0] = 'B';
	m_BNKHeader.s[1] = 'A';
	m_BNKHeader.s[2] = 'N';
	m_BNKHeader.s[3] = 'K';
	getLines();
}

void Bank::getLines()
{
	for (m_BNKHeader.accounts = -1; std::getline(m_fileIn, m_line); ++m_BNKHeader.accounts);
}

void Bank::writeBNK()
{
	writeHeader();
	indexRecords();
	for (int i = 0; i < m_BNKHeader.accounts; i++)
		cout << m_pRecords[i].AccountNumber << " " << m_pRecords[i].filePosition << endl;
	cout << endl;

	sortIndex(0, m_BNKHeader.accounts - 1);

	for (int i = 0; i < m_BNKHeader.accounts; i++)
		cout << m_pRecords[i].AccountNumber << " " << m_pRecords[i].filePosition << endl;

	m_fileOut.write((char*)m_pRecords, sizeof(Bank::Index) * (m_BNKHeader.accounts));
}

void Bank::writeHeader()
{
	m_fileOut.write((char*)&m_BNKHeader, sizeof(Bank::Head));
}

void Bank::indexRecords()
{
	m_pAccounts = new Account[m_BNKHeader.accounts];
	m_pRecords = new Index[m_BNKHeader.accounts];
	m_fileIn.clear();
	m_fileIn.seekg(0, m_fileIn.beg);
	getline(m_fileIn, m_line);

	int i = 0, j;
	for (int index = 0; std::getline(m_fileIn, m_line); ++index)
	{
		j = m_line.find(',');
		m_pRecords[index].AccountNumber = stoi(m_line.substr(i, j - i));
		m_pAccounts[index].number = stoi(m_line.substr(i, j - i).c_str());
		i = ++j;

		j = m_line.find(',', j);
		strcpy_s(m_pAccounts[index].name, m_line.substr(i, j - i).c_str());
		i = ++j;

		j = m_line.find(',', j);
		m_pAccounts[index].balance = stod(m_line.substr(i, j - i));
		i = ++j;
		
		m_pRecords[index].filePosition = (long)m_fileOut.tellp();
		m_fileOut.write((char*)&m_pAccounts[index], sizeof(Bank::Account));
	}		
}

void Bank::sortIndex(int index, int length)
{
	int hold = 0;
	float pHold = 0;
	for (int i = index; i < length; i++){
		for (int j = 0; j < length; j++)
		{
			if (m_pRecords[j].AccountNumber > m_pRecords[j + 1].AccountNumber)
			{
				hold = m_pRecords[j].AccountNumber;
				m_pRecords[j].AccountNumber = m_pRecords[j + 1].AccountNumber;
				m_pRecords[j + 1].AccountNumber = hold;

				pHold = m_pRecords[j].filePosition;
				m_pRecords[j].filePosition = m_pRecords[j + 1].filePosition;
				m_pRecords[j + 1].filePosition = pHold;
			}
		}
	}
}

bool Bank::checkHeader()
{
	m_file.read((char*)&m_header, sizeof(Head));

	string bnk = "BANK";
	if (strcmp(m_header.s, bnk.c_str()) == 1)
		return true;
	
	return false;
}

void Bank::getIndex()
{
	int indexSize;
	int end;
	m_file.seekg(0, m_file.end);
	end = m_file.tellp();
	m_file.seekg(sizeof(Head) + (m_header.accounts) * sizeof(Account));
	indexSize = end - m_file.tellp();

	m_index = new Index[m_header.accounts];
	for (int i = 0; i < 12; i++)
	{
		m_file.read((char*)&index, sizeof(Index));
		m_index[i] = index;
	}

}

void Bank::menu()
{

	cout << "\n\n\t\t\tAccounts";
	cout << "\n\t-----------------------------------------";
	cout << "\n\t| ";
	for (int i = 0; i < m_header.accounts; i++)
	{
		cout << m_index[i].AccountNumber << "\t";
		if ((i + 1) % 5 == 0)cout << "|\n\t|\t\t\t\t\t|\n\t| ";
	}
	
	cout << "\n\t-----------------------------------------";
	cout << "\n\n\n\n";
	cout << "\n\tDisplay Account Information\t(q to quit)";
	cout << "\n\n\tEnter Account Number: ";
}

void Bank::choice()
{
	int num;
	string actNumber = "Q";
	m_c = 'Q';
	while (m_c != 'q')
	{
		menu();
		cin >> actNumber;
		if (actNumber == "Q" || actNumber == "q")
		{
			cout << "\n\n\tThank you for your business\n\n";
			return;
		}
		while (!checkIndex(actNumber))
		{
			cout << "\n\n\tWe don't show that account on record. \n\tPlease try from the options above.";
			cout << "\n\tEnter Account Number: ";
			cin >> actNumber;
			if (actNumber == "Q" || actNumber == "q")
			{
				cout << "\n\n\tThank you for your business\n\n";
				return;
			}
		}
		display(actNumber);
	}
}

void Bank::display(string rAccountNumber)
{
	char action = 'C';
	index = binaryIndexLookup(rAccountNumber);
	m_file.seekg(index.filePosition, m_file.beg);
	m_file.read((char*)&account, sizeof(Account));

	while (action != 'c')
	{
		showAccount();
		cin >> action;
		switch (action)
		{
		case 'D':
		case 'd':deposit(); break;
		case 'w':
		case 'W':withdraw(); break;
		case 'c':
		case 'C': action = 'c'; break;
		default:cout << "\n\tSorry, that wasn't an option. Choose another";
			break;
		}
	}
}

void Bank::showAccount()
{
	cout << "\n\n\t-------------------------------";
	cout << "\n\t|  ###    | " << account.number << " ";
	cout << "\n\t| Holder  | " << account.name << " ";
	cout << "\n\t| Balance | " << account.balance << " ";
	cout << "\n\t-------------------------------";
	cout << "\n";
	cout << "\n\t(Deposit, (W)ithdraw, (C)hoose another account";
	cout << "\n\tOption: ";
}

void Bank::deposit()
{
	m_file.close();
	m_file.open(m_oFile, ios::out | ios::binary | ios::app);
	string d;
	cout << "\n\tDeposit: ";
	cin >> d;
	double dd = stod(d);
	account.balance += dd;
	m_file.seekp(index.filePosition, m_file.cur);
	m_file.write((char*)&account, sizeof(Account));
	m_file.close();
	m_file.open(m_oFile, ios::in | ios::binary);
}

void Bank::withdraw()
{
	m_file.close();
	m_file.open(m_oFile, ios::out | ios::binary | ios::app);
	string w;
	cout << "\n\tWithdraw: ";
	cin >> w;
	double dw = stod(w);
	account.balance -= dw;
	m_file.seekp(index.filePosition, m_file.cur);
	m_file.write((char*)&account, sizeof(Account));
	m_file.close();
	m_file.open(m_oFile, ios::in | ios::binary);
}

bool Bank::checkIndex(string rAccountNumber)
{
	int a = stoi(rAccountNumber);
	for (int i = 0; i < m_header.accounts; i++)
		if (m_index[i].AccountNumber == a)return true;
	return false;
}

Bank::Index Bank::binaryIndexLookup(string rAccountNumber)
{
	int a = stoi(rAccountNumber);
	int max = m_header.accounts;
	int min = 0;
	int middle = (min + max) / 2;
	while ((m_index[middle].AccountNumber != a) && (min <= max))
	{
		if (m_index[middle].AccountNumber > a)
			max = middle - 1;
		else
			min = middle + 1;
		middle = (min + max) / 2;
	}
	return m_index[middle];
}