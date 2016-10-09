#ifndef HEAP_H
#define HEAP_H

#include <sstream>
#include <cassert>
using namespace std;

class Node 
{
public:
	int element;
	Node * left;
	Node * right;
	int npl;

	Node (int e, Node * lt = nullptr, Node * rt = nullptr, int npl = 0)
		:element(e), left(lt), right(rt), npl(npl) {  }

};

class Heap 
{
public:
	Node * root;

	Heap() : root(nullptr) {  }
	Heap(Node * root) : root(root) {  }
	Heap(Heap &rhs) { root = nullptr; *this = rhs; };
	~Heap() { makeEmpty(); };

	void insert(int element);
	int deleteMax();
	Node * merge(Node * a, Node * b);
	void merge(Heap &rhs);

	// implicit functions for merge
	void setNPL(Node * node);
	bool notLeftist(Node * node);
	void swapKids(Node * node);

	// utility functions
	bool isEmpty() { return root == nullptr; }
	string toString();
	string toString(Node * node, string indent);
	void makeEmpty();
	void makeEmpty(Node * node);
};
#endif

/*
*	CORE FUNCTIONS
*/

void Heap::insert(int element)
{
	root = merge(new Node(element), root);
}

int Heap::deleteMax()
{
	Node * temp = root;
	root = merge(root->left, root->right);
	return temp->element;
}

// Core merge function
Node * Heap::merge(Node * a, Node * b)
{
	Node * big;
	if(a == nullptr)return b;
	if(b == nullptr)return a;
	if(a->element > b->element)
	{
		a->right = merge(a->right, b);
		big = a;
	}
	else
	{
		b->right = merge(b->right, a);
		big = b;
	}
	if(notLeftist(big))swapKids(big);
	setNPL(big);
	return big;
}

// merge trees
void Heap::merge(Heap &rhs)
{
	root = merge(root, rhs.root);
	rhs.root = nullptr;
}

/*
* UTILITY FUNCTIONS
*/
bool Heap::notLeftist(Node * node)
{
	if(node->right == nullptr)return false;
	if(node->left == nullptr)return true;
	return(node->left->npl >= node->right->npl);
}

// npl = smallest of the left and right + 1
void Heap::setNPL( Node * node )
{
	assert( node );
	if(node->left == nullptr)node->npl = 0;
	else if(node->right == nullptr)node->npl = 0;
	else node->npl = min(node->left->npl, node->right->npl) + 1;
}

void Heap::swapKids(Node * node)
{
	Node * temp = node->left;
	node->left = node->right;
	node->right = temp;
}

string Heap::toString()
{
	if(!isEmpty())return toString(root, "\t");
	return "There is nothing for you here, \nonly death...\n\n";
}

string Heap::toString(Node * node, string indent)
{
	stringstream ss;
	if(node == nullptr)return " ";
	ss << toString(node->left, "\t");
	ss << indent << node->element << endl;
	ss << toString(node->right, "\t");
	return ss.str();
}

void Heap::makeEmpty()
{
	makeEmpty( root );
}

void Heap::makeEmpty(Node * node)
{
	if(node != nullptr)
	{
		makeEmpty(node->left);
		delete node;
		makeEmpty(node->right);
	}
}