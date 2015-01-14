/*A local zoo wants to keep track of how many pounds of food each of its 
three monkeys eats day during a typical week. Write a program that stores
this information in a two-dimensional 3 x 7 array, where each row represents
a different monkey and each column represents a different day of the week.
The program should first have the user input the data for each monkey.
Then it should create a report that includes the following information:

	• Average amount of food eaten per day by the whole family of monkeys.
	• The least amount of food eaten during the week by any one monkey.
	• The greatest amount of food eaten during the week by any one monkey.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

const int ROW = 3, COL = 7;
int monkeys[ROW][COL];

void printTitle();
void makeMonkeys(int[][COL]);
int getAverage(int array[][COL]);
int getHighest(int array[][COL]);
int getLowest(int array[][COL]);


int main(){
	int average, highest, lowest;

	printTitle();

	cout << "\n\nHow many pounds of food did the monkeys eat on a given day? ";
	makeMonkeys(monkeys);
	average = getAverage(monkeys);
	highest = getHighest(monkeys);
	lowest = getLowest(monkeys);

	cout << "\nThe average is " << average;
	cout << "\nThe highest is " << highest;
	cout << "\nThe lowest is " << lowest;

	return 0;
}

void printTitle(){

	cout << "\n*******************";
	cout << "\nMonkey Business   |";
	cout << "\n*******************";
}

void makeMonkeys(int array[][COL]){

	for(int i = 0; i < ROW;i++){
		cout << "\nMonkey " << i + 1 << endl;
		for(int j = 0; j < COL; j++){
			cout << "Day " << j + 1 << ": ";
			cin >> monkeys[i][j];
		}
	}

}

int getAverage(int array[][COL]){
	int sum, average;

	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			sum += array[i][j];
		}
	}

	average = sum /(ROW + COL); 

	return average;
}

int getHighest(int array[][COL]){
	int highest = 0;

	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(highest < array[i][j])highest = array[i][j];
		}
	}

	return highest;
}
int getLowest(int array[][COL]){
	int lowest = array[0][0];
	for(int i = 0; i < ROW; i++){
		for(int j = 0; j < COL; j++){
			if(lowest > array[i][j])lowest = array[i][j];
		}
	}
	return lowest;
}