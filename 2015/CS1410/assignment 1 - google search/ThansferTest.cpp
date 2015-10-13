// Adam Tew a01952442
// Assignment 1
//
//
//	Task 1 Declare a class TermTable
//	Task 2 Implement a binarySearch method

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

//const double SIZE = 999999;
const int termSIZE = 99999;
const int freqSIZE = 99999;

using namespace std;

class TermTable
{
public:
	TermTable();

	void getInput();
	void binarySearch(int findVal);
	void sort();

private:
	int m_SIZE;
	int m_index;
	int m_aTerms[termSIZE];
	int m_aFreqs[freqSIZE];
	int m_aSmallTerms[freqSIZE];
	ifstream fin;
};

TermTable::TermTable()
{
	for (int i = 0; i < freqSIZE; i++)
	{
		m_aFreqs[i] = 1;
	}

	for (int i = 0; i < termSIZE; i++)
	{
		m_aTerms[i] = 0;
	}


}

void TermTable::getInput()
{
	cout << "\nStart\n";
	int i = 0;
	string line;
	fin.open("input.txt");
	//if (fin.is_open())
	//while (!fin.eof())
	for (int i = 0; i < termSIZE; i++)
	{
		getline(fin, line);
		m_aTerms[i] = atoi(line.c_str());

	}

	fin.close();
	cout << "\nStop\n";
}

void TermTable::binarySearch(int findVal)
{
	int begin = 0, end = termSIZE - 1, mid = (end - begin) / 2, pos = -1, retry = termSIZE;
	//while (pos !=)
}

void TermTable::sort()
{
	for (int i = 0; i < termSIZE; i++)
	{
		if (m_aTerms[i] != 0)
		{
			for (int j = 0; j < termSIZE; j++)
			{
				if (i == j)continue;
				if (m_aTerms[i] == m_aTerms[j])
				{

					++m_aFreqs[i];
					m_aTerms[j] = 0;
					m_aSmallTerms[i] = m_aTerms[i];
				}
			}
		}
	}

	for (int i = 0; i < termSIZE; i++)
	{
		cout << "Terms: " << m_aSmallTerms[i] << " Freq " <<  m_aFreqs[i] << endl;
	}

	cout << "\nTerms[0] " << m_aTerms[0];
	cout << "\nTerms[10] " << m_aTerms[10];
	cout << "\nTerms[50] " << m_aTerms[50];
	cout << "\nFreqs[0] " << m_aFreqs[0];
	cout << "\nFreqs[10] " << m_aFreqs[10];
	cout << "\nFreqs[50] " << m_aFreqs[50];
}

int main()
{
	TermTable google;
	google.getInput();
	google.sort();
	return 0;
}