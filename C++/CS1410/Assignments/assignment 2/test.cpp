#include <iostream>

using namespace std;

int checkNext(int row, int col, int rowInc, int colInc, char x);

const int SIZE = 10;
char board[SIZE][SIZE];
int count;

int main()
{


	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
		{
			board[i][j] = 'c';
			//if(i % 2 == 0)board[i][j] = 'c';
			//if(j % 2 == 0)board[i][j] = 'p';
			if(j == SIZE - 1)board[i][j] = 'x';
		}

	for(int i = 0; i < SIZE; i++)
	{
		cout << endl;
		for(int j = 0; j < SIZE; j++)
		{
			cout << board[i][j];
		}
	}

	for(int i = 0; i < SIZE; i++)
	{
		count = 0;
		count = checkNext(i, 0, 1, 0, 'c');
		cout << "\n\tCount: " << count;
	}

	return 0;
}

int checkNext(int row, int col,int rowInc, int colInc, char x)
{

	if(board[row + rowInc][col + colInc] != x)
	{
		count++;
		return count;
	}
	else
	{
		count++;
		return checkNext(row, col, rowInc, colInc, x);
	}

	return 0;
}