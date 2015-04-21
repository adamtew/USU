#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

	// Task 1
int CompueSumOfDigits(int);

	// Task 2
int CountWays(int);

	// Task 3
int CountSubSetSum(int[], int, int);

	// Task 4
bool  IsSolvable(int, int[], int);

	// Task 5
void startMaze(string rFileName);
void findGoal(char** aArray, int rRows, int rCols, int rRow, int rCol);



int main()
{
		// Task 1
	cout << "\n\tTask 1";
	cout << "\n1234 = " << CompueSumOfDigits(1234);
	cout << "\n5678 = " << CompueSumOfDigits(5678) << "\n\n";

		// Task 2


		// Task 3
	cout << "\n\tTask 3\n";
	const int SIZE = 5;
	int array[SIZE] = { 1, 1, 2, 3, 0 };
	int target = 3;
	cout << "There are " << CountSubSetSum(array, SIZE, target) << " ways to find " << target << " in the array";
	for (int i = 0; i < SIZE; i++)cout << " " << array[i];
	cout << "\n\n";
	int newArray[SIZE] = {-1, -2, 3, 4, 3};
	target = 2;
	cout << "There are " << CountSubSetSum(newArray, SIZE, target) << " ways to find " << target << " in the array";
	for (int i = 0; i < SIZE; i++)cout << " " << newArray[i];


		// Task 4
	cout << "\n\n\tTask 4\n";
	const int newSIZE = 10;
	int myArray[newSIZE] = { 3, 6, 4, 1, 3, 4, 2, 5, 3, 0};
	if (IsSolvable(0, myArray, newSIZE))
		cout << "\nIt is solvable";
	else
		cout << "\nIt is not solvable";

	int myNewArray[newSIZE] = { 3, 6, 4, 3, 3, 4, 2, 5, 1, 0};
	if (IsSolvable(0, myNewArray, newSIZE))
		cout << "\nIt is solvable";
	else
		cout << "\nIt is not solvable";


		// Task 5
	cout << "\n\nTask 5\n";
	startMaze("maze.txt");
	startMaze("maze1.txt");
	startMaze("maze2.txt");

	return 0;

}








	// Task 1:
// Write a recursive method to determine the sum of the digits of a positive integer.
// For example, the sum of the digits of 51624 is 5 + 1 + 6 + 2 + 4 = 18.  
int CompueSumOfDigits(int rNumbers)
{
	string sNumbers = std::to_string(rNumbers);
	if (sNumbers.length() <= 1)
	{
		return rNumbers;
	}
	else
	{
		//int newNumbers = stoi(sNumbers.substr(1, sNumbers.length()));
		return stoi(sNumbers.substr(0, 1)) + CompueSumOfDigits(stoi(sNumbers.substr(1, sNumbers.length())));
	}
}

	// Task 2:
//Write a recursive function that takes a positive value as the number of stairs and returns 
//the number of different ways to climb a staircase of that height taking strides of one or 
//two stairs at a time.The function prototype is:
int sizes[2] = { 1, 2 };
int CountWays(int ways)
{
	if (ways <= 0)
	{
		cout << "0 or less\n";
		return ways;
	}
	else
	{
		return ways;
	}
}


	// Task 3:
int CountSubSetSum(int rArray[], int rSize, int rTarget)
{
	int count = 0;
	if (rSize == -1)
		return count;
	else
		for (int i = 0; i < rSize; i++)
			if (rArray[rSize - 1] + rArray[i] == rTarget)
			{
				count += 1;
				cout << "Success: " << rArray[rSize - 1] << " + " << rArray[i] << " == " << rTarget << endl;
			}
		return count + CountSubSetSum(rArray, rSize - 1, rTarget);
}


	// Task 4
void printSolvable(int rMarker, int rArray[], int size)
{
	cout << "\nrMarker: " << rMarker << "\nSize: " << size << endl;
	for (int i = 0; i < size; i++)cout << rArray[i] << " ";
}

bool IsSolvable(int rMarker, int rArray[], int size)
{
	printSolvable(rMarker, rArray, size);

	if (rMarker < 0 || rMarker > size)return false;
	if (rArray[rMarker] == 0)return true;
	if (IsSolvable(rMarker + rArray[rMarker], rArray, size) == true)return true;
	if (IsSolvable(rMarker - rArray[rMarker], rArray, size) == true)return true;

}


	// Task 5
void startMaze(string rFileName)
{
	string s;
	int number;
	int rows;
	int cols;
	int row;
	int col;
	//ifstream fin("maze.txt");
	ifstream fin(rFileName);
	fin >> rows;
	fin >> cols;
	fin >> row;
	fin >> col;
	cout << "\nRows: " << rows << " Cols: " << cols << "\nmyRow: " << row << " myCol: " << col << endl;

	char** newMaze;
	newMaze = new char*[20];
	for (int i = 0; i <= rows + 2; i++)
		newMaze[i] = new char[20];
	int i = 0, j = 0;
	char c;
	while (!fin.eof())
	{
		c = fin.get();
		if (c == '\n')c = fin.get();
		newMaze[i][j] = c;
		j++;
		if (j == cols)
		{
			j = 0;
			i++;
		}
	}
	findGoal(newMaze, rows, cols, row, col);
}

void printMaze(char** aArray, int rRows, int rCols, int rRow, int rCol)
{
	cout << "\n";
	for (int i = 0; i < rRows; i++)
	{
		cout << "\n";
		for (int j = 0; j < rCols; j++)
		{
			if (i == rRow && j == rCol)
				cout << "!";
				//cout << aArray[i][j];
			else
				cout << aArray[i][j];
		}
			
	}
}

bool findPath(char** aArray, int rRows, int rCols, int rRow, int rCol)
{

	//printMaze(aArray, rRows, rCols, rRow, rCol);
	if (rRow > rRows || rRow < 0)return false; // Outside North or South bounds
	if (rCol > rCols || rCol < 0)return false; // Outside East or West bounds
	if (aArray[rRow][rCol] == 't')
	{
		cout << "\nTreasure: " << rRow << ", " << rCol;
		return true; // Found the goal
	}
	//if (aArray[rRow][rCol] == '.')return true; // Found the goal
	if (aArray[rRow][rCol] == 'X' || aArray[rRow][rCol] == '+'){
		return false; 
		cout << "\nTreasure Path: " << rRow << ", " << rCol;
	}// Your position is a wall
	
	aArray[rRow][rCol] = '+'; // Mark current position as part of solution path
	if (findPath(aArray, rRows, rCols, rRow, rCol - 1) == true)
	{
		cout << "\nTreasure Path: " << rRow << ", " << rCol;
		return true; // Check west one space
		
	}
	if (findPath(aArray, rRows, rCols, rRow - 1, rCol) == true)
	{
		cout << "\nTreasure Path: " << rRow << ", " << rCol;
		return true; // Check north one space
	}
	
	if (findPath(aArray, rRows, rCols, rRow + 1, rCol) == true)
	{
		cout << "\nTreasure Path: " << rRow << ", " << rCol;
		return true; // Check south one space
	}
	
	if (findPath(aArray, rRows, rCols, rRow, rCol + 1) == true)
	{
		cout << "\nTreasure Path: " << rRow << ", " << rCol;
		return true; // Check east one space
	}
	aArray[rRow][rCol] = '-'; // Unmark position as part of solution path
	return false;
}
	
void findGoal(char** aArray, int rRows, int rCols, int rRow, int rCol)
{
	//printMaze(aArray, rRows, rCols, rRow, rCol);

	//if (findPath(aArray, rRows, rCols, rRow + 1, rCol));
	if (findPath(aArray, rRows, rCols, rRow, rCol))
		cout << "\nFOUND!";
	else
		cout << "\nNo path to treasure";
	printMaze(aArray, rRows, rCols, rRow, rCol);

}


