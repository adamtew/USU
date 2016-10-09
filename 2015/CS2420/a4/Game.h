#ifndef GAME_H
#define GAME_H


#include <fstream>
#include "HashTable.h"
#include "data.cpp"
// #include "HashTable.cpp"

using namespace std;

class Game 
{
public:

	Game();

	void play();
private:
	int score;
	int OutputFrequency;

	int promptUser();
	void play(string);
	void loadWords(string);
	int getScore();
	void updateScore(HashNode *);
	void setFrequency();
	void checkTop();
	HashTable<string, HashEntry<string, HashNode> > table;


};

Game::Game()
{
	int bob = 5;
	score = 0;
	OutputFrequency = 2;
}

int Game::promptUser()
{
	int game;
	cout << "\n\nOptions\n";
	cout << "Games: 1, 2, 3, 4, 5\n";
	cout << "Frequency 6\n";
	cout << "Show Entries 7\n";
	cout << "exit: 0\n";
	cout << "Enter: ";
	cin >> game;
	return game;
}

void Game::play()
{
	int game = promptUser();
	while(game != 0)
	{
		switch(game)
		{
			case 0: game = 0; 			break;
			case 1: play("game0.txt"); 	break;
			case 2: play("game1.txt"); 	break;
			case 3: play("game2.txt"); 	break;
			case 4: play("game3.txt"); 	break;
			case 5: play("game4.txt"); 	break;
			case 6: setFrequency(); 	break;
			case 7: checkTop();			break;
			default: cout << "\nInvalid input\n"; break;
		}
		game = promptUser();
	}
	cout << "\nThanks for playing\n";
}

void Game::play(string game)
{
	score = 0;
	table.makeEmpty();
	loadWords(game);
	int gameScore = getScore();
	cout << table.toString();
}

void Game::loadWords(string fileName)
{
	ifstream fin(fileName);
	string line;
	int i = 0;
	while (getline(fin, line))
	{
		HashEntry<string, HashNode> * newEntry = table.find(line);
		if(newEntry != NULL)
		{
			newEntry->rec->freq++;
			table.insert(line, newEntry);
			updateScore(newEntry->rec);
		}
		else
		{
			newEntry = new HashEntry<string, HashNode>(new HashNode(line, 1), line);
			table.insert(line, new HashEntry<string, HashNode>(new HashNode(line, 1), line));
			updateScore(newEntry->rec);
		}
		if(i % OutputFrequency == 0)cout << "The new score is " << score << endl;

		i++;
	}
	fin.close();	
}

int Game::getScore()
{
	return score;
}

void Game::updateScore(HashNode * node)
{
	string line = node->word;
	int freq = node->freq;
	int newScore = 0;
	int scoreLength = 0;
	int bonus = 0;
	// score = score + 5;
	// string sNumbers = std::to_string(rNumbers);
	// score(word) = (sum of letter values) * (lengthValue)*bonus
	for(int i = 0; i < line.length(); i++)
		for(int j = 0; j < 26; j++)
			if(line[i] == VALUES[j].first)newScore += VALUES[j].second;

	for(int i = 0; i < 7; i++)
		if(line.length() == LENGTHS[i].first)scoreLength = LENGTHS[i].second;

	if(freq == 0)bonus = 5;
	else if(freq >= 1 && freq < 6)bonus = 4;
	else if(freq >= 6 && freq < 11)bonus = 3;
	else if(freq >= 11 && freq <15)bonus = 2;
	else if(freq >= 15)bonus = 1;

	score += newScore * scoreLength * bonus;

}

void Game::setFrequency()
{
	cout << "\nEnter new frequency: ";
	cin >> OutputFrequency;
}

void Game::checkTop()
{
	int count = 0;
	cout << "How many records would you like?\n";
	cout << "Record Count: ";
	cin >> count;
	cout << table.toString(count); 
}


#endif