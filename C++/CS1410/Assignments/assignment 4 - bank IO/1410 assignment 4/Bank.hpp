#ifndef BANK_HPP
#define BANK_HPP

#include <string>
#include <fstream>

using namespace std;

class Bank{
private:
	struct Head
	{
		char s[4];
		int accounts;
		char r[24];
	};

	struct Account
	{
		int number;
		char name[20];
		double balance;
		char reserved[96];
	};

	struct Index
	{
		int AccountNumber;
		long filePosition;
	};

		// CSV parsing
	fstream m_fileIn;
	int m_lines;
	Head m_BNKHeader;
	Index* m_pRecords;
	Account* m_pAccounts;
	string m_line;

	fstream m_fileOut;

	fstream m_file;
	Head m_header;
	Account account;
	Index* m_index;
	Index index;
	string m_oFile;
	char m_c;


public:
	Bank();
	Bank(string rFile);
	Bank(string rFileInput, string rFileOutput);

	void parseCSV();
	void getLines();
	void indexRecords();
	void sortIndex(int index, int length);
	void quickSort(Index* pArray, int start, int end);
	int partition(Index* pArray, int start, int end);

	void writeBNK();
	void writeHeader();

		// Check if the first 4 chraters are 'B' 'A' 'N' 'K'
	bool checkHeader();
	void getIndex();
	void menu();
	void choice();
	void deposit();
	void withdraw();
	void display(string rAccountNumber);
	Index binaryIndexLookup(string rAccountNumber);
	bool checkIndex(string rAccountNumber);
	void showAccount();

};

#endif