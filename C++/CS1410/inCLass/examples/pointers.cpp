#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;


int main()
{
	char A = 'A';
	int B = 3;
	float C = 3.3;
	int aLuckyNumbers[] =  {1, 2, 3, 4, 5, 6, 6};

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

	// printf("The pointer is %p\n", (void*)&A);


	return 0;
}