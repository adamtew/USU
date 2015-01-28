#include <iostream>

using namespace std;

class Useless
{
public:
	Useless()
	: moreUseless(0),
		pX(NULL),
		pY(NULL)
	{

	}

	~Useless()
	{
		if(pX != NULL)
		{
			delete pX;
			pX = NULL;
		}
		
		if(pY != NULL)
		{
			delete pY;
			pY = NULL;
		}
	}

	void init()
	{
		pX = new int;
		pY = new int;
	}

	int moreUseless;

	int* pX;
	int* pY;
};

// Useless::Useless()
// {
// 	moreUseless = 0;
// }

struct Position
{
	int x;
	int y;
	int z;
};

int* foo();
int* bar();
void clearClass(Useless* pTheClass);

int main()
{
	Position something;
	Position* pSomething = new Position;
	// delete pSomething; // <-- Do this at the end of a pointer
	// It's a lot better to get a segmentation fault than a dangling memory leak.

	cout << "X is " << something.x << endl;
	cout << "X is " << (*pSomething).x << endl;

	delete pSomething;
	pSomething = NULL;

	// Returning pointers from functions
	int* pReturned = foo();

	if(pReturned != NULL)
	{
		cout << "Foo returned " << *pReturned << endl;
		delete pReturned;
		pReturned = NULL;
	}

	Useless useless;
	Useless* pUseless = new Useless();
	// Useless* pUseless = NULL; // <--- This will cause a segmentation fault

	cout << "The member variables is " << useless.moreUseless << endl;
	cout << "The member variables is " << (*pUseless).moreUseless << endl;
	// Other syntax
	cout << "The member variables is " << pUseless->moreUseless << endl;

	// If you don't put the pointer deletion in the destructor than you will have memory leaks
	pUseless->init();

	clearClass(pUseless);

	delete pUseless;
	pUseless = NULL;



	return 0;
}

int* foo()
{
	int* pToReturn = new int;
	(*pToReturn) = 6;

	return pToReturn;
}

int* bar()
{
	return NULL;
}

void clearClass(Useless* pTheClass)
{
	if(pTheClass != NULL)
	pTheClass->moreUseless = 0;
}