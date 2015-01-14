/*Write a program that displays the word UP on  the bottom line of the screen a couple
of inches to the left of center and displays the word DOWN on the top line of the 
screen a couple of inches to the right of center. Moving about once a second, move
the word UP up a line and the word DOWN down a line until UP disappears at the top of
the screen and DOWN disappears at the bottom of the screen.*/
// Adam Tew ---- CS1400

#include <iostream>

using namespace std;

void printTitle();

int main(){
	
	printTitle();

	return 0;
}

void printTitle(){
	
	cout << "\n*****************";
	cout << "\nUps and Downs   |";
	cout << "\n*****************";

}