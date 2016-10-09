// This file holds the definitions for the queue
#ifndef BOARDQUEUE_H
#define BOARDQUEUE_H

#include "BoardNode.h"

class BoardQueue{
private:
	BoardNode* classHead; // head node
	BoardNode* classTail; // tail node
	int classCount;

public:
	BoardQueue(); // default constructor

	bool push(BoardNode* boardNode); // add item to the queue
	BoardNode* pop(); // remove and return node from the queue

	int getCount() const; // return how many items have been added to the queue


};
#endif 