#ifndef QUADRATIC_PROBING_H
#define QUADRATIC_PROBING_H

#include <vector>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include "HashTable.cpp"

using namespace std;

int nextPrime(int n);
bool isPrime(int n);

enum Status { ACTIVE, EMPTY, DELETED };

class HashNode{
public:	
	string word;
	int freq;

	string toString()
	{
		stringstream ss;
		ss << "(" << word << ", " << freq << ")";
		return ss.str();
	}

	HashNode(string newWord, int newFreq = 0)
		: word(newWord), freq(newFreq) { }

};

// We store two things.  The key itself and the record associated with the key.
// In our case, the HashKey will be the word.  The HashRecord will be a node containing the word (again) and the count.
// Note that you have to supply a toString for the HashRecord or you can't print the hash table.
template <typename HashKey, typename HashRecord>
class HashEntry
{
public:
	HashKey key;
	HashRecord * rec;
	Status info;

	string toString()
	{
		stringstream ss;	
		ss << "Key: " << key << ", Record: " << rec->toString() << endl;
		return ss.str();
	}

	HashEntry(HashRecord * hr = NULL, const HashKey & e = HashKey(), Status i = EMPTY)
		: key( e ), rec( hr ), info( i ) { }

};


template <typename HashKey, typename HashRecord>
class HashTable
{
public:
	/*
		1. The hash table should keep track of the total number finds done on the hash table AND the number of probes required in those finds.  (This will help us determine how good the hash function is.)  
		2. Number of items stored in hash table.
		3. Size of hash table.  This code changes the size of the code dynamically.
		4. Contents of entries in the hash table. This includes the word and the occurrence count.
	*/
	int totalFinds;
	int totalProbes;
	// int totalItems;
	int tableSize;


	bool remove(const HashKey & x);
	bool isEmpty() { return activeElements == 0; }
	HashRecord * insert(const HashKey x, HashRecord * h);
	HashTable(int size = 977) : hashTable(nextPrime(size))
	{
		totalFinds = 0;
		makeEmpty();
		tableSize = nextPrime(size);
	};
	HashRecord *find(const HashKey & x);
	void makeEmpty();
	string toString(int howMany = 50);

	vector<HashEntry<HashKey, HashRecord> > hashTable;
private:
	void setFinds();
	void setProbes();
	int activeElements;
	bool isActive(int currentPos) const;
	size_t myhash(const HashKey & x) const;
	int findPos(const HashKey & x);
	void rehash();
	int myStep(HashKey);
	size_t newhash(const HashKey & x) const;

};

// Convert the Hash table to a string.  Since the hashtablel is large, HowMany indicates how many entries will be displayed.  
template <typename HashKey, typename HashRecord>
string HashTable<HashKey, HashRecord>::toString(int howMany)
{
	int ct = 0; int totalItems = 0;
	stringstream ss;
for (int i = 0; i < (int) hashTable.size() && ct < howMany; i++)
		if (hashTable[i].info == ACTIVE){
		     ss << hashTable[i].rec->toString();
		     ct++;
		     totalItems++;
		}
	ss << "\nTable Data\n-----------\n";
	ss << "Total Finds: " << totalFinds << endl;
	ss << "Total Probes: " << totalProbes << endl;
	ss << "Total Items: " << totalItems << endl;
	ss << "Table Size: " << tableSize << endl;	
	return ss.str();

}

// template <typename HashKey, typename HashRecord>
// void HashTable<HashKey, HashRecord>::setFinds()
// {
// }

// template <typename HashKey, typename HashRecord>
// void HashTable<HashKey, HashRecord>::setProbes()
// {
// }

// return the subscript where x is located in the hash table.    
// Quadratic probing is used.  Can you figure out why this implements quadratic probing?
template <typename HashKey, typename HashRecord>
int HashTable<HashKey, HashRecord>::findPos(const HashKey & x)
{
	// int offset = 1;
	// int step = step(x);
	// int step = 1;
	int step = myStep(x);
	int offset = step;
	int currentPos = myhash(x);
	// totalFinds += 1;


	while (hashTable[currentPos].info != EMPTY &&
		hashTable[currentPos].key != x)
	{
		totalProbes += 1;

		currentPos += offset;  // Compute ith probe
		// offset += 2;                     
		// offset += step;                     
		if (currentPos >= (int)hashTable.size())    // Cheaper than  mod
			currentPos -= hashTable.size();
	}

	return currentPos;
};



template <typename HashKey, typename HashRecord>
int HashTable<HashKey, HashRecord>::myStep(HashKey key)
{
	// unsigned int step(string key)
	{
		// unsigned int stepVal=0;
		int stepVal=0;
	   	for (int i = 0; i < key.length(); i++)
	      	stepVal =  (stepVal << 7) ^ key[i] ^ stepVal;
	   	return 1 + stepVal %(hashTable.size()-2);
	}

}

// Remove all elements of the table by setting status to empty.
// Have you seen the range based loop for accessing elements of a vector?
// for (auto &entry:hashTable) says, let a reference variable "entry" iterate through all entries of the hashTable vector
// The "auto" part says to figure out the type of the element automatically (based on what is passed in).
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::makeEmpty()
{
	totalProbes = 0;
	totalFinds = 0;
	activeElements = 0;
	for (auto & entry : hashTable)
		entry.info = EMPTY;
};

// Create a new hashtable which is at least twice as large as the current size.
// Actually, rehashing can make the table smaller (if entries have been removed), but this isn't considered here.
template <typename HashKey, typename HashRecord>
void HashTable<HashKey, HashRecord>::rehash()
{
	vector<HashEntry <HashKey, HashRecord> > oldhashTable = hashTable;

	// Create new double-sized, empty table
	hashTable.resize(nextPrime(2 * oldhashTable.size()));
	for (auto & entry : hashTable)
		entry.info = EMPTY;

	// Copy table over
	activeElements = 0;
	for (auto & entry : oldhashTable)
		if (entry.info == ACTIVE)
			insert(entry.key, entry.rec);

};

// Return true if given entry is active.
template <typename HashKey, typename HashRecord>
bool HashTable<HashKey, HashRecord>::isActive(int currentPos) const
{
	return hashTable[currentPos].info == ACTIVE;
};

// use built=in hash functions to find a location.
template<typename HashKey, typename HashRecord>
size_t HashTable<HashKey, HashRecord>::myhash(const HashKey & x) const
{
	static hash<HashKey> hf;
	return hf(x) % hashTable.size();
};

template<typename HashKey, typename HashRecord>
size_t HashTable<HashKey, HashRecord>::newhash(const HashKey & x) const
{
	int hashVal=0;
   	for (int i = 0; i < x.length(); i++)
      	hashVal =  (hashVal << 5) ^ x[i]  ^ hashVal;
   	return hashVal % hashTable.size();
};


// Use lazy deletion to remove an element
// Return boolean to indicate success of operation
template <typename HashKey, typename HashRecord>
bool HashTable<HashKey, HashRecord>::remove(const HashKey & x)
{
	int currentPos = findPos(x);
	if (!isActive(currentPos))
		return false;

	hashTable[currentPos].info = DELETED;
	return true;
};

// Insert item with key x and record pointer h into the hash table.
template<typename HashKey, typename HashRecord>
HashRecord * HashTable<HashKey, HashRecord>::insert(const HashKey x, HashRecord * h)
{
	// Insert x as active
	int currentPos = findPos(x);
	if (isActive(currentPos))
		return NULL;

	hashTable[currentPos].key = x;
	hashTable[currentPos].rec = h;
	hashTable[currentPos].info = ACTIVE;

	// Rehash; see Section 5.5
	if (++activeElements > (int)(hashTable.size() / 5))
		rehash();
	// cout << activeElements << " ";

	return h;
};

// Return record for item with key x.
template<typename HashKey, typename HashRecord>
HashRecord * HashTable<HashKey, HashRecord>::find(const HashKey & x)
{
	totalFinds++;
	int pos = findPos(x);
	if (isActive(pos))
		return hashTable[pos].rec;
	return NULL;
};
#endif
