// Double pointers
	// Pointers that point at pointers
	// int value;
	// int* pPointer1 = &value;
	// int** pPointer2 = &pPointer1;

// Breaking up files

#include <iostream>
#include <stdlib.h>

using namespace std;


class Myclass
{
public:
	Myclass()
	: m_value(0)
	{

	}
	~Myclass()
	{
		// empty
	}

	void doSomething();
	void doSomething(int* array);

private:
	int m_value;


};


int main()
{
	// double pointers
	int value = 3;
	int value2 = 4;
	int* pValuePointer1 = &value;
	int** pValuePointer2 = &pValuePointer1;

	cout << "The value via pValuePointer1 is " << *pValuePointer2 << endl;

	cout << "The value via pValuePointer2 is " << **pValuePointer2 << endl;

	pValuePointer1 = &value2;

	cout << "Now, the vlue via pValuePointer2 is " << **pValuePointer2 << endl;


	// Array stuff
	// Non-dymanic
	
	int myArray[3][4];

	// Dynamic array
	int SIZE = 5;
	int** p2dArray = NULL;
	p2dArray =new int*[SIZE];
	for(int i = 0; i < SIZE; i++)
	{
		p2dArray = new int*[SIZE];
	}

	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			p2dArray[i][j] = 0;
		}
	}

	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			cout << p2dArray[i][j];
		}
	}

	// How do we dealocate
	for(int i = 0; i < SIZE; i++)
	{
		delete [] p2dArray[i];
		p2dArray[i] = NULL;
	}

	delete [] p2dArray; // you need to use the square brackets

	return 0;
}