// This file houses the implementation for the BoardNode.h file. 
#include "BoardNode.h" // include the BoardNode.h file
#include "Board.h" // Include the Board.h file

// create a constructor
BoardNode::BoardNode(Board value, BoardNode* next){
	classNext = next; // initialize class variables
	classBoard = value;
}

// getters
BoardNode* BoardNode::getNext() const{
	return classNext;
}
Board BoardNode::getBoard() const{
	return classBoard;
}

// setters
void BoardNode::setNext(BoardNode* next){
	classNext = next;
}
void BoardNode::setBoard(Board board){
	classBoard = board;
}