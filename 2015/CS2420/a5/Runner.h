#ifndef RUNNER_H
#define RUNNER_H

// #include "Heap.h"

class Runner
{
public:
	vector<Term>  terms;
	int newSIZE; // size of the array of terms, should be 4351

	Runner(){ play(); };

void loadWords()
{
string line;
	int weight;
	ifstream fin("/Users/at/gitSchool/usu/2015/CS2420/a5/SortedWords.txt");
	if(!fin.is_open())return;
	fin >> newSIZE;
	int count = 0;
	while(!fin.eof())
	{
		fin >> line;
		fin >> weight;
		Term term(line, weight);
		terms.push_back(term);
		count++;
	}
}

void greeting()
{
	cout << "\n\nWelcome to the substring game\n\n";
}

void options()
{
	cout << "Substring: ";	
}

Heap<Term> makeHead()
{
	Heap<Term> bob;
	return bob;
}

void choice()
{
	string substring;
	options();
	cin >> substring;
	while(substring != "x")
	{

	} 
}

Heap<Term> buildHeap(string term, int r)
{
	int start = firstIndexOf(terms, 0, newSIZE, "word", 5);
	int finish = lastIndexOf(terms, 0, newSIZE, term, r);
	Heap<Term> heap;
	for(int i = start; i < finish; i++)
		heap.insert(terms[i]);
	return heap;
}

void outputHeap(Heap<Term> heap)
{
	while(!heap.isEmpty())
		cout << heap.deleteMax() << endl;
}


void play()
{
	loadWords();
	options();
	Heap<Term> heap;
	heap = buildHeap("word", 5);
	outputHeap(heap);


}

/*
*	Binary Search Functions within the runner class
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
		 		if(mid == 0)return 0;
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

};



#endif