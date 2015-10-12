/*Write a program that simulates a lottery. The program should have an
array of 5 integers named winningDigits, with a randomly generated number
in the range of 0 through 9 for each element in the array. The program
should ask the user to enter 5 digits and should store them in a second
integer array named player. The program myst compare the corresponding
elements in the two arrays and count how many digits match. For example,
the following shows the winningDigits array and the Player array with
sample numbers stored in each. There are two matching digits, elements
2 and 4.

					---------------------
	winningDigits 	| 7 | 4 | 9 | 1 | 3 |
	 				---------------------
			player 	| 4 | 2 | 9 | 7 | 3 |
					---------------------

Once the user has entered a set of numbers, the program should display
the winning digits and the player's digits and tell how many digits
matched.*/
// Adam Tew ---- CS1400

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int SIZE = 5;
int winningDigits[SIZE], player[SIZE], compared[SIZE];

void printTitle();
void randomFill(int[]);
void playerFill(int[]);
int compare(int[], int[]);
void displayDigits(int[], int[], int[], int);

int main(){
	int matches;
	printTitle();

	randomFill(winningDigits);
	playerFill(player);
	matches = compare(player, winningDigits);
	displayDigits(player, winningDigits, compared, matches);

	return 0;
}

void printTitle(){

	cout << "\n***********";
	cout << "\nLottery   |";
	cout << "\n***********";

}

void randomFill(int array[]){
	int fill;
	srand(time(0));


	for(int i = 0; i < SIZE; i++){
		array[i] = rand() % 9 + 1;
	}
}

void playerFill(int array[]){

	cout << "\n\nEnter your lottery numbers.\n";	
	for(int i = 0; i < SIZE; i++){
		cout << "Number " << i + 1 << ": ";
		cin >> array[i];
	}	
}

int compare(int playerArray[], int randArray[]){
	int same = 0;

	for(int i = 0; i < SIZE; i++){
		if(playerArray[i] == randArray[i]){
			compared[i] = randArray[i];
			same += 1;
		}else{
			compared[i] = 0;
		}
	}

	return same;
}

void displayDigits(int playerArray[], int randArray[], 
	int matched[], int same){

	cout << "\n\tWinning Digits: ";
	for(int i = 0; i < SIZE; i++){
		cout << randArray[i];
	}
	cout << "\n\tPlayer  Digits: ";
	for(int i = 0; i < SIZE; i++){
		cout << playerArray[i];
	}
	cout << "\n\tMatched Digits: ";
	for(int i = 0; i < SIZE; i++){
		cout << matched[i];
	}

	cout << "\n\nThere are " << same << " that match\n";
}


