// #ifndef HEAP_H
// #define HEAP_H

#include <sstream>
#include <cassert>
#include "Term.h"
using namespace std;


template <typename Comparable>
class Heap 
{
	// class Node 
public:
	struct Node
	{
	// public:
		// int element;
		Comparable element;
		Node * left;
		Node * right;
		int npl;

		Node (Comparable e, Node * lt = nullptr, Node * rt = nullptr, int npl = 0)
			:element(e), left(lt), right(rt), npl(npl) {  }

	};
public:
	Node * root;

	Heap() : root(nullptr) {  }
	Heap(Node * root) : root(root) {  }
	Heap(Heap &rhs) { root = nullptr; *this = rhs; };
	~Heap() { makeEmpty(); };

	// void insert(Comparable element);
	bool isEmpty() { return root == nullptr; }

/*
*	CORE FUNCTIONS
*/

void insert(Comparable element)
{
	root = merge(new Node(element), root);
}

Comparable deleteMax()
{
	Node * temp = root;
	root = merge(root->left, root->right);
	return temp->element;
}

// Core merge function
Node * merge(Node * a, Node * b)
{
	Node * big;
	if(a == nullptr)return b;
	if(b == nullptr)return a;
	auto x = a->element;
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
void merge(Heap &rhs)
{
	if( this == &rhs )
		return;

	root = merge(root, rhs.root);
	rhs.root = nullptr;
}

/*
* UTILITY FUNCTIONS
*/
bool notLeftist(Node * node)
{
	if(node->right == nullptr)return false;
	if(node->left == nullptr)return true;
	return(node->left->npl >= node->right->npl);
}

// npl = smallest of the left and right + 1
void setNPL( Node * node )
{
	assert( node );
	if(node->left == nullptr)node->npl = 0;
	else if(node->right == nullptr)node->npl = 0;
	else node->npl = min(node->left->npl, node->right->npl) + 1;
}

void swapKids(Node * node)
{
	Node * temp = node->left;
	node->left = node->right;
	node->right = temp;
}

string toString()
{
	if(!isEmpty())return toString(root, "\t");
	return "There is nothing for you here, \nonly death...\n\n";
}

string toString(Node * node, string indent)
{
	stringstream ss;
	if(node == nullptr)return " ";
	ss << toString(node->left, indent + "\t");
	ss << indent << node->element << endl;
	ss << toString(node->right, indent + "\t");
	return ss.str();
}

void makeEmpty()
{
	makeEmpty( root );
}

void makeEmpty(Node * node)
{
	if(node != nullptr)
	{
		makeEmpty(node->left);
		delete node;
		makeEmpty(node->right);
	}
}

};