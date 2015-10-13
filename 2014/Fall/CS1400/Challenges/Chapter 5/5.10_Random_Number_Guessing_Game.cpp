/*Write a program that generates a random number between 1 and 100 and asks the user to
guess what the number is. If the user's guess is higher than the random numbe, the
program should display "Too high. Try again." The program should use a loop that 
repeats until the user correctly guesses the random number. Then the program should
display "Congratulations. You figured out my number."*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	bool wrong = true;
	int randNumber, guess;

	srand(time(0));
	randNumber = rand() % 100;

	cout << "\n\n******************************";
	cout << "\nRandom Number Guessing Game  |";
	cout << "\n******************************";

	cout << "\n\n\tI'm thinking of a number between 1 and 100\n\tGuess what it is";
	while(wrong){
		cout << "\n\tGuess: ";
		cin >> guess;
		if(guess == randNumber){
			cout << "\n\tCongratulations! You figured out my number.\n\n";
			wrong = false;
		}else if(guess > randNumber){
			cout << "\n\tNope, you're a little too high. Try again.";
		}else if(guess < randNumber){
			cout << "\n\tNope, you're a little too low. Try again.";
		}
	}

	return 0;
}