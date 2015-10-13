#include "ConnectNGame.hpp"
#include <iostream>

using namespace std;

int setSpaces();

int main()
{
	int spaces = setSpaces();;
	ConnectNGame game(spaces);
	game.play();

	return 0;
}

int setSpaces()
{
	int spaces;

	cout << "Welcome to Connect N Game";
	cout << "\n";
	cout << "\nHow many spaces are needed to win?";
	cout << "\n";
	cout << "\n\t---------------";
	cout << "\n\t|  3   4   5  |";
	cout << "\n\t---------------";
	cout << "\n";
	cout << "\nGame Size: ";
	cin >> spaces;
	while (spaces < 3 || spaces > 5)
	{
		cout << "\n\tThat's not a valid number. Try again.";
		cout << "\n\n\tGame Size: ";
		cin >> spaces;
	}

	return spaces;
}