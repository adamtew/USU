/*Enhance the program that you wrote for Programming CHallenge 10 so it keeps a count
of the number of guesses the user makes. When the user correctly guesses the random
number, the program hsould dsiplay the number of guesses along with the message of
congratulations*/
// Adam Tew ---- CS1400

#include <iostream>
#include <cstdlib>

using namespace std;

int main(){
	bool wrong = true;
	int randNumber, guess, guesses = 0;

	srand(time(0));
	randNumber = rand() % 100;

	cout << "\n\n***************************************";
	cout << "\nRandom Number Guessing Game Enhanced  |";
	cout << "\n***************************************";

	cout << "\n\n\tI'm thinking of a number between 1 and 100\n\tGuess what it is";
	while(wrong){
		cout << "\n\tGuess: ";
		guesses++;
		cin >> guess;
		if(guess == randNumber){
			cout << "\n\tCongratulations! You figured out my number. on guess " 
				<< guesses << "\n\n";
			wrong = false;
		}else if(guess > randNumber){
			cout << "\n\tThis is guess number " << guesses;
			cout << "\n\tNope, you're a little too high. Try again.";
		}else if(guess < randNumber){
			cout << "\n\tThis is guess number " << guesses;
			cout << "\n\tNope, you're a little too low. Try again.";
		}
	}

	return 0;
}