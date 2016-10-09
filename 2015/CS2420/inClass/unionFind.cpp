#include <iostream>

using namespace std;


const int SIZE = 10;
int A[SIZE] = {-1, -1, -1, -3, 4, 2, 6, 7, 8, 9};

// Normal union find
int findRoot(int root)
{
	if(A[root] < 0)return root;
	return findRoot(A[root]);
}

// Union find with path compression
int findRootPathCompression(int root)
{
	if(A[root] < 0)return root;
	A[root] = findRoot(A[root]);
	return A[root];
}

// Union by height
void unionHeight(int one, int two)
{
	if(findRoot(A[one]) > findRoot(A[two]))
		A[one] = A[two];
	else
		A[two] = A[one];
}

// correct answer
void unionHeight1(int a, int b)
{
	a = findRoot(a);
	b = findRoot(b);
	if(a == b)return;
	if(A[a] < A[b])
		A[b] = a;
	else if(A[a] > A[b])
		A[a] = b;
	else
	{
		A[a]--;
		A[b] = a;
	}
}

int main()
{
	cout << "\n\n" << findRoot(5) << endl;
	unionHeight1(1, 2);

	cout << "\n\n";
	for(int i = 0; i < SIZE; i++)cout << A[i] << " ";
	cout << "\n\n";

	return 0;
}