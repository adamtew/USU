#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <string>
using namespace std;

class PriorityNode
{
public:
    int             element;
    PriorityNode    *left;
    PriorityNode    *right;
    int             height;

    PriorityNode( const int & ele, PriorityNode * lt = nullptr, PriorityNode * rt = nullptr, int h = 0 )
      : element{ ele }, left{ lt }, right{ rt }, height{ h } { }
    
    PriorityNode( int && ele, PriorityNode * lt = nullptr, PriorityNode * rt = nullptr, int h = 0 )
      : element{ std::move( ele ) }, left{ lt }, right{ rt }, height{ h } { }
};

class PriorityQueue
{
public:

	PriorityQueue() { root = nullptr; }; // constructor
	PriorityQueue( PriorityQueue &rhs ) { root = nullptr; *this = rhs; } // copy constructor
    PriorityQueue &operator=(PriorityQueue &rhs);
    PriorityNode * clone(PriorityNode * node);
	void insert(int &element);
	int deleteMax();
	void merge(PriorityQueue &rhs);
	PriorityNode *merge(PriorityNode * nodeA, PriorityNode * nodeB);
	PriorityNode *mergeHelper(PriorityNode * nodeA, PriorityNode * nodeB);
	void swapKids(PriorityNode * node);
	int &findMin();
	void deleteMin();
	bool isEmpty();	
	void makeEmpty();
	void makeEmpty(PriorityNode * node);

	string toString();
	string toString(PriorityNode * node, string indent);


private:


    /*
    *	Variables
    */
    PriorityNode * root;
    int find(int);

};

#endif