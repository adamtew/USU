#include <iostream>
#include "Heap.h"
#include <fstream>
#include "Term.h"
#include <vector>
#include <regex>
#include <array>
// #include "Heap_int.h"
#include "Runner.h"
#include <string>

int firstIndexOf(vector<Term>  a, int bot, int top, string target, int r);
int lastIndexOf(vector<Term>  a, int bot, int top, string target, int r);

using namespace std;


// int main()
int main(int argc, char** pArgv)
{
	/*
	* PART I
	*/

	// •	inserts into two different queues,
	const int SIZE = 5;
	int one[SIZE] = {2, 1, 4, 3, 0 };
	int two[SIZE] = {5, 6, 7, 8, 9 };
	Heap<int> a;
	Heap<int> b;
	// Heap a;
	// Heap b;

	for(int i = 0; i < SIZE; i++)
	{
		a.insert(one[i]);
		b.insert(two[i]);
	}

//	 •	prints the queue prettily (so the tree structure can be seen),
	cout << "\nFirst Queue\n";
	cout << a.toString();
	cout << "\nSecond Queue\n";
	cout << b.toString();

//	 •	merges the queues,
	cout << "\nMerged Queue\n";
	a.merge(b);
	cout << a.toString();

//	 •	deletes max
	cout << "\n\nDelete Max:\n\n";
	int x = a.deleteMax();
	cout << "Popped " << x << " off the top\n";

	/*
	*	PART II
	*/


	// 1. Read in the file and store it in an array of Terms.

	// vector<Term *> terms;
	string line;
	int weight;
//	ifstream fin("SortedWords.txt");
//	ifstream fin;
	ifstream fin("/Users/at/gitSchool/usu/2015/CS2420/a5/SortedWords.txt");
//	fin.open("/Users/SortedWords.txt");
	if(!fin.is_open())return 1;
	int newSIZE; // = 4351;
	 fin >> newSIZE;
	vector<Term>  terms;
	int count = 0;
	while(!fin.eof())
	{
		fin >> line;
		fin >> weight;
		Term term(line, weight);
		// terms.push_back(term);
		terms.push_back(term);
//		cout << term << endl;
		count++;
	}

	// 2. For each target word (of length r), provide the top “count” matches using the following procedure

	// (a)  Using a binary search on the array, find all words whose first r letters match that of the target word.  
	// 		You will need to implement two binary searches, 
	// •	//find the first location of key in a[] which matches r locations of key.
	//  	int firstIndexOf(Term a[], string target, int r)
				int start = firstIndexOf(terms, 0, newSIZE, "account", 4);
	// •	//find the last location of key in a[] which matches r locations of key.
	// 		int lastIndexOf(Term a[], string target, int r)
				int finish = lastIndexOf(terms, 0, newSIZE, "account", 4);
	// (b)  Put all terms found in part (a) into a priority queue.   
	// 		Using weight as a priority, output the top “count” terms.

	cout << "\n\nStep 2\nCheck the words for 'acco':\n";

	Heap<Term> heap;
	for(int i = start; i < finish; i++)
		heap.insert(terms[i]);

	for(int i = start; i < finish; i++)
		cout << heap.deleteMax() << endl;


	 // (c) Allow merging of queues
	cout << "\nAllow for merging of queues\n";
	cout << "First, make another queue for 'doc':\n\n";

	int start1 = firstIndexOf(terms, 0, newSIZE, "doc", 3);
	int finish1 = lastIndexOf(terms, 0, newSIZE, "doc", 3);


	Heap<Term> heap2;
	for(int i = start1; i < finish1; i++)
		heap2.insert(terms[i]);

	for(int i = start1; i < finish1; i++)
		cout << heap2.deleteMax() << endl;

	cout << "\n\nNext, merge them:\n\n";

	for(int i = start1; i < finish1; i++)
		heap2.insert(terms[i]);
	
	for(int i = start; i < finish; i++)
		heap.insert(terms[i]);

	heap.merge(heap2);

	while(!heap.isEmpty())
		cout << heap.deleteMax() << endl;

	cout << endl;

	if(argc > 1)
	{
		if(argc == 3 || argc == 2)
		{

			int number = atoi(pArgv[2]);
			if(pArgv[2] == NULL)number = 100;
			string searchTerm(pArgv[1]);
			int length = (int)(searchTerm.length());

			int begin = firstIndexOf(terms, 0, newSIZE, searchTerm, length);
			int end = lastIndexOf(terms, 0, newSIZE, searchTerm, length);

			Heap<Term> theHeaps;
			for(int i = begin; i < end; i++)
				theHeaps.insert(terms[i]);

			while(!theHeaps.isEmpty())
			{
				if(number-- <= 0)return 0;
				cout << theHeaps.deleteMax() << endl;
			}
		}
		if(argc == 4)
		{
			string searchTerm(pArgv[1]);
			string searchTerm1(pArgv[2]);
			
			int number = atoi(pArgv[3]);
			int length = (int)(searchTerm.length());

			int begin = firstIndexOf(terms, 0, newSIZE, searchTerm, length);
			int end = lastIndexOf(terms, 0, newSIZE, searchTerm, length);

			Heap<Term> theHeaps;
			for(int i = begin; i < end; i++)
				theHeaps.insert(terms[i]);

			begin = firstIndexOf(terms, 0, newSIZE, searchTerm1, length);
			end = lastIndexOf(terms, 0, newSIZE, searchTerm1, length);

			Heap<Term> theOtherHeaps;
			for(int i = begin; i < end; i++)
				theHeaps.insert(terms[i]);

			theHeaps.merge(theOtherHeaps);

			while(!theHeaps.isEmpty())
			{
				if(number-- <= 0)return 0;
				cout << theHeaps.deleteMax() << endl;
			}
		}

	}
		else
	{
		cout << "\nSorry, there were no arguments.";
		cout << "\nTo use this program enter a map file as an argument";
		cout << "\n\n" << pArgv[0] << " [search term] [count]";
		cout << "\n\n" << pArgv[0] << " [first search term] [second search term] [count]";
		cout << "\n\nExample: " << pArgv[0] << "dog 5";
		cout << "\n\nExample: " << pArgv[0] << "dog cat 5";
	}


	return 0;
}


/*
*	Binary search functions
*/

int lastIndexOf(vector<Term> a, int first, int last, string target, int r)
{
	if( first <= last)
	{
		int mid = (last + first) / 2;
		string word = a[mid].word;
		int comparison = target.substr(0, r).compare(a[mid].word.substr(0, r));
		if( comparison == 0)
		{
		 	while((target.substr(0, r).compare(a[mid].word.substr(0, r))) == 0)
		 	{
		 		if(mid == last)return mid;
		 		mid++;
		 	}
			return mid;
		}
		else if(comparison < 0) // greater
			return lastIndexOf(a, first, mid, target, r);
		else // less than
			return lastIndexOf(a, mid, last, target, r);
	}
	return 0;
}

int firstIndexOf(vector<Term>  a, int first, int last, string target, int r)
{
	if( first <= last)
	{
		int mid = (last + first) / 2;
		string word = a[mid].word;
		int comparison = target.substr(0, r).compare(a[mid].word.substr(0, r));
		if( comparison == 0)
		{
		 	while((target.substr(0, r).compare(a[mid].word.substr(0, r))) == 0)
		 	{
		 		if(mid == 0)return mid;
		 		mid--;
		 	}
			return mid;
		}
		else if(comparison < 0) // greater
			return firstIndexOf(a, first, mid, target, r);
		else // less than
			return firstIndexOf(a, mid, last, target, r);
	}
	return 0;
}