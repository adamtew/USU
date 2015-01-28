#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


void doSomething(int& rValue);
void doSomethingBetter(int* pValue);

int main()
{
	char A = 'A';
	int B = 3;
	float C = 3.3;
	int E = 1;
	int aLuckyNumbers[] =  {1, 2, 3, 4, 5, 6, 6};
	int F = 0;
	int* D;


	cout << "A's pointer is " << std::hex << long(&A) << endl;
	cout << "B's pointer is " << std::hex << long(&B) << endl;
	cout << "C's pointer is " << std::hex << long(&C) << endl;

	cout << "D's pointer is " << std::hex << long(&D) << endl;
	cout << "D's pointer points to " << std::hex << long(D) << endl;
	D = &B;



	cout << "D's now points to  " << std::hex << long(D) << endl;
	cout << "D's now points to  " << *D << endl;

	(*D) = 4;
	// D = (int*)4 // really bad - it means you're trying to go to memory that you're not allowed to go to
	cout << "B is  " << B << endl;
	cout << "D's now points to  " << *D << endl;

	// Pointers with arrays
	cout << "aLuckyNumbers points to " << long(aLuckyNumbers) << endl;

	D = aLuckyNumbers;
	cout << "D's now points to  " << std::hex << long(D) << endl;
	cout << "D's now points to  " << *D << endl;

	cout << "aLuckyNumbers points to " << *(aLuckyNumbers + 1) << endl;


	char* pLuckyNumbers = (char*)aLuckyNumbers;
	cout << "pLuckyNumbers points to " << hex << long(*(pLuckyNumbers + 0)) << endl;
	printf("pLuckyNumbers points to 0x%02x\n", *(pLuckyNumbers + 0));
	printf("pLuckyNumbers points to 0x%02x\n", *(pLuckyNumbers + 1));
	printf("pLuckyNumbers points to 0x%02x\n", *(pLuckyNumbers + 2));
	printf("pLuckyNumbers points to 0x%02x\n", *(pLuckyNumbers + 3));
	printf("pLuckyNumbers points to 0x%02x\n", *(pLuckyNumbers + 4));
	printf("pLuckyNumbers points to 0x%02x\n", *(pLuckyNumbers + 5));
	// printf("The pointer is %p\n", (void*)&A);


	// Good syntax
	int* pPointer = 0; // or NULL


	// 
	int* pForE = &E;
	int* pForF = &F;

	if (pForE == pForF)
	{
		cout << "They are equal\n";
	}
	else if (pForE < pForF)
	{
		cout << "F is bigger\n";
	}
	else if (pForE > pForF)
	{
		cout << "E is bigger\n";
	}


	int G = 5;
	int H = 5;

	// cout << "Before, G is " << G << endl;
	// doSomething(G);
	// cout << "After, G is " << G << endl;

	printf("Before, G is %i\n", G);
	doSomething(G);
	printf("After, G is %i\n", G);

	printf("Before, H is %i\n", H);
	// doSomethingBetter(H); Broken, not sure why.
	printf("After, H is %i\n", H);


	const int aConstArray[] = {1, 2, 3, 4, 5};
	const int* pPointer = aConstArray;


	return 0;
}

void doSomething(int& rValue)
{
	rValue = 300;
}

void doSomethingBetter(int* pValue)
{
	*pValue = 400;
}