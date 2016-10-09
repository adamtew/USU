#ifndef BOARDNODE_H
#define BOARDNODE_H

#include "Board.h"

class BoardNode{
private:
	BoardNode* classNext; // Next node
	Board classBoard; // the board object
public:
	// constructor
	BoardNode(Board value, BoardNode* next = nullptr);

	// getters
	BoardNode* getNext() const;
	Board getBoard() const;

	// setters
	void setNext(BoardNode* next);
	void setBoard(Board board);

};
#endif