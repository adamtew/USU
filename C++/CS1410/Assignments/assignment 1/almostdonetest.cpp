//	Adam Tew
// A01952442
// Assignment 1


/**********************************************************************
								Includes
**********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

const long SIZE = 10000;



/**********************************************************************
							Class Definitions
**********************************************************************/

class TermTable
{
public:
	TermTable();

	bool binarySearch(long rValue);
	void insert(long rValue);
	void insertionSort();

	void sortByFreq();
	long* getTerms();
	long* getFreqs();
	long getSize();
	void showArrays();

private:
	long m_aTerms[SIZE];
	long m_aFreqs[SIZE];
	long m_currentSize;
	long m_workingPosition;
};


/**********************************************************************
					Class Function Definitions
**********************************************************************/



TermTable::TermTable()
{
	for (long i = 0; i < SIZE; i++)
	{
		m_aFreqs[i] = 0;
		m_aTerms[i] = 0;
	}
	m_currentSize = 0;
	m_workingPosition = 0;
}

bool TermTable::binarySearch(long rValue)
{
	long begin = -1;
	long end = m_currentSize;
	long mid = begin + (end - begin) / 2;
	while (begin <= end && m_aTerms[mid] != rValue)
	{
		mid = begin + (end - begin) / 2;
		
		if (m_aTerms[mid] > rValue)
		{
			begin = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}

	if (m_aTerms[mid] == rValue)
	{
		m_workingPosition = mid;
		return true;
	}
	return false;
}

void TermTable::insert(long rValue)
{
		// if the search term is in the array, increase the frequency of that
		// value and move on.
	if (binarySearch(rValue))
	{
		m_aFreqs[m_workingPosition] += 1;
		m_workingPosition++;
	}
	else
	{
		m_aTerms[m_currentSize] = rValue;
		m_aFreqs[m_currentSize] = 1;
		m_currentSize++;
		insertionSort();
		//showArrays();
	}
}

void TermTable::insertionSort()
{
	long tempFreq;
	long tempTerm;
	for (long i = 1; i < m_currentSize; i++)
	{
		tempFreq = m_aFreqs[i];
		tempTerm = m_aTerms[i];
		long j;
		for (j = i - 1; j >= 0 && m_aTerms[j] < tempTerm; j--)
		{
			m_aTerms[j + 1] = m_aTerms[j];
			m_aFreqs[j + 1] = m_aFreqs[j];
		}
		m_aTerms[j + 1] = tempTerm;
		m_aFreqs[j + 1] = tempFreq;
		
	}
}

void TermTable::sortByFreq()
{
	long minPos;
	long temp;
	for (long i = 0; i < m_currentSize; i++)
	{
		minPos = i;
		for (long j = i + 1; j < m_currentSize; j++)
		{
			if (m_aFreqs[minPos] < m_aFreqs[j])
			{
				minPos = j;
			}
		}

		if (minPos != i)
		{
			temp = m_aTerms[i];
			m_aTerms[i] = m_aTerms[minPos];
			m_aTerms[minPos] = temp;

			temp = m_aFreqs[i];
			m_aFreqs[i] = m_aFreqs[minPos];
			m_aFreqs[minPos] = temp;
		}
	}
}

long* TermTable::getTerms()
{
	return m_aTerms;
}

long* TermTable::getFreqs()
{
	return m_aFreqs;
}

long TermTable::getSize()
{
	return m_currentSize;
}



/**********************************************************************
								Main
**********************************************************************/

void getVals();
void sortByTerm();
void inserTerms(TermTable& g);
void output(TermTable& g);

const long bigSIZE = 100000;
long* aSearchTerms = new long[1000000];

int main()
{
	TermTable google;

	getVals();
	//sortByTerm();
	inserTerms(google);
	output(google);

	
	return 0;
}


/**********************************************************************
							Functions
**********************************************************************/

void getVals()
{
	ifstream fin("input.txt");
	string line;
	int i = 0;
	while (getline(fin, line))
	{
		aSearchTerms[i] = atoi(line.c_str());
		i++;
	}
	fin.close();
}

void sortByTerm()
{
	long tempTerm;
	for (long i = 1; i < bigSIZE; i++)
	{
		tempTerm = aSearchTerms[i];
		long j;
		for (j = i - 1; j >= 0 && aSearchTerms[j] < tempTerm; j--)
		{
			aSearchTerms[j + 1] = aSearchTerms[j];
		}
		aSearchTerms[j + 1] = tempTerm;
		//cout << "Term: " << i << " " <<  aSearchTerms[j + 1] << endl;
	}
}

void sortByTerms()
{

	long min;
	long temp;
	for (long i = 0; i < bigSIZE; i++)
	{
		
		min = i;
		for (long j = i + 1; j < bigSIZE; j++)
		{
			if (aSearchTerms[min] < aSearchTerms[j])
			{
				min = j;
			}
			if (min != i)
			{
				temp = aSearchTerms[i];
				aSearchTerms[i] = aSearchTerms[min];
				aSearchTerms[min] = temp;
			}
		}
	}
}

void inserTerms(TermTable& g)
{
	for (long i = 0; i < bigSIZE; i++)
	{
		g.insert(aSearchTerms[i]);
		cout << "Attemp: " << i << endl;
	}
}

void output(TermTable& g)
{
	ofstream fout("output.txt");
	g.sortByFreq();
	long* frequency = g.getFreqs();
	long* terms = g.getTerms();
	long i = 0;
	while (i < g.getSize())
	{
		fout << terms[i] << " " << frequency[i] << "\n";
		i++;
	}
	fout.close();
}