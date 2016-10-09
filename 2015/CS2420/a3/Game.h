// this file is for the definitions of the Game class
#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include "BoardQueue.h"
#include "avlTree.h"
// #include "Game.cpp"

class Game{
private:
	string classTitle; // title of the current board
	Board classBoard; // current board to be solved
	Board classSolvedBoard; // board with the solution
    AvlTree<Board> tree;
	BoardQueue* classQueue; // the queue of boardNodes

	bool classSolved;

public:
	Game(); // default constructor
	Game(string title, int boardArray[]); // other constructor

	string getTitle() const; // getter
	
	void play(bool); // main game loop
	bool move(Board &b, char m, char lastMove); // function to move pieces around the board
	void playGiven(string title, int newBoard[], bool); // solve a given board
	void playRandom(string title, int randValue); // solve a random board
	/*
	 * Priority Stuff
	 */
    void playPriority(bool);
    void playGivenPriority();
    void playRandomPriority();
    bool movePriority(Board &b, char m, char lastMove);
};
#endif