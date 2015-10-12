/*Write a program that asks the user for two positive integers between 2 and 10 to use
for the length and width of a rectangle. If the numbers are different, the larger
of the two numbers should be used for the length and the smaller for the width. The
program should then display a rectangle of this size on the screen using the character
'X'. For example, if the user enters either 2 5 or 5 2, the program should display
the following:

	XXXXX
	XXXXX*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

int main(){
	int num1, num2;

	cout << "\n\n*********************";
	cout << "\nRectangle Display   |";
	cout << "\n*********************";

	cout << "\n\n\tEnter two numbers";
	cout << "\nNumber 1: ";
	cin >> num1;
	cout << "Number 2: ";
	cin >> num2;

	if(num2 > num1){
		for(int i = 0; i < num1; i++){
			cout << "\n\t";
			for(int j = 0; j < num2; j++){
				cout << "X";
			}
		}
	}else{
		for(int i = 0; i < num2; i++){
			cout << "\n\t";
			for(int j = 0; j < num1; j++){
				cout << "X";
			}
		}

	}


	return 0;
}