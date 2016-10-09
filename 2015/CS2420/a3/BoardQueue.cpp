// This file is used to implement the BoardQueue.h file
#include "BoardQueue.h"
#include "BoardNode.h"

// default constructor
BoardQueue::BoardQueue(){
		classHead = nullptr;
}

// the push function adds items to the queue
bool BoardQueue::push(BoardNode* boardNode){
	if (classHead == 0){ // If the queue is null then initialize the head and tail variables
		classHead = boardNode;
		classTail = boardNode;
		classCount++; // increment the count
		return true;
	}
	else { // if the queue has something in it then add a new item on the tail.
		classTail->setNext(boardNode); 
		classTail = boardNode;
		classCount++; // increment the count
		return true;
	}
	return false;
}
// the pop function removes and return a node from the queue
BoardNode* BoardQueue::pop(){
	if (classTail == nullptr)return nullptr; // if the queue is null then return null
	else{
		BoardNode* temp = classHead; // setup a temp node to return
		classHead=classHead->getNext(); // move the head variable up the queue
		return temp; // return the front item from the queue
	}
}

// getter
int BoardQueue::getCount() const{
	return classCount;
}