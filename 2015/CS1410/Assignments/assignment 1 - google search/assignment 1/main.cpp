/*// Adam Tew a01952442
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
const int termSIZE = 9999;
const int freqSIZE = 9999;

using namespace std;

class TermTable
{
public:
	TermTable();

	void getInput();
	void binarySearch(int findVal);
	void sort();
	void makeTerms();
	void selectionSort();

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
		m_aSmallTerms[i] = 0;
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
				}
			}
		}
	}

}

void TermTable::makeTerms()
{
	int m = 0;
	for (int i = 0; i < freqSIZE; i++)
	{
		if (m_aTerms[i] != 0)
		{
			m_aSmallTerms[m] = m_aTerms[i];
			m++;
		}
	}

	for (int i = 0; i < freqSIZE; i++)
	{
		cout << m_aSmallTerms[i] << endl;
	}

}

void TermTable::selectionSort()
{
	for (int i = 0; i < freqSIZE; i++)
	{
		cout << m_aSmallTerms[i] << " " << m_aFreqs[i] << endl;
	}
}

void TermTable::binarySearch(int findVal)
{
	int begin = 0, end = termSIZE - 1, mid = (end - begin) / 2, pos = -1, retry = termSIZE;
	//while (pos !=)
}

/*int main()
{
	/*
	TermTable google;
	google.getInput();
	google.sort();
	google.makeTerms();
	//google.selectionSort();
	//google.binarySearch();
	
	return 0;
}*/