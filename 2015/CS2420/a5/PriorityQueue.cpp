#include "PriorityQueue.h"
#include <sstream>

/*
*
*/
PriorityQueue &PriorityQueue::operator=(PriorityQueue & rhs)
{
	if( this != &rhs )
	{
		makeEmpty();
		root = clone(rhs.root);
	}
	return *this;
}

/*
*
*/
PriorityNode * PriorityQueue::clone(PriorityNode * node)
{
	if(node == nullptr)
		return nullptr;
	else
		return new PriorityNode(node->element, clone(node->left), clone(node->right), node->height);
}

/*
*	
*/
void PriorityQueue::merge(PriorityQueue &rhs)
{
	if(this == &rhs)
		return;
	root = merge(root, rhs.root);
	rhs.root = nullptr;
}

/*
*	
*/
PriorityNode * PriorityQueue::merge(PriorityNode * nodeA, PriorityNode * nodeB)
{
	if(nodeA == nullptr)
		return nodeB;
	if(nodeB == nullptr)
		return nodeA;
	if(nodeA->element > nodeB->element)
		return mergeHelper(nodeA, nodeB);
	else
		return mergeHelper(nodeB, nodeA);
}

/*
*
*/
PriorityNode *PriorityQueue::mergeHelper(PriorityNode * nodeA, PriorityNode * nodeB)
{
	if(nodeA->left == nullptr)
		nodeA->left = nodeB;
	else
	{
		nodeA->right = merge(nodeA->right, nodeB);
		if(nodeA->left->height > nodeA->right->height)
			swapKids(nodeA);
		nodeA->height = nodeA->right->height + 1;
	}	
	return nodeA;
}

/*
*
*/
void PriorityQueue::swapKids(PriorityNode * node)
{
	PriorityNode * temp = node->left;
	node->left = node->right;
	node->right = temp;
}

/*
*
*/
void PriorityQueue::insert(int &element){ root = merge(new PriorityNode(element), root); }

/*
*
*/
int & PriorityQueue::findMin(){	return root->element; }

/*
*
*/
void PriorityQueue::deleteMin()
{
	PriorityNode * temp = root;
	merge(root->left, root->right);
	delete temp;
}

 /*
 *
 */
 // void PriorityQueue::deleteMin(int &minItem)

 /*
 *
 */
 bool PriorityQueue::isEmpty(){ return root == nullptr; }

 /*
 *
 */
void PriorityQueue::makeEmpty()
{
	makeEmpty(root);
	root = nullptr;
}

/*
*
*/
void PriorityQueue::makeEmpty(PriorityNode * node)
{
	if(node != nullptr)
	{
		makeEmpty(node->left);
		makeEmpty(node->right);
		delete node;
	}
}

/*
*
*/
string PriorityQueue::toString()
{
	return toString(root, "\t");
}
string PriorityQueue::toString(PriorityNode * node, string indent)
{
	if(node == nullptr)return "\n";
		stringstream ss;
		ss << toString(node->left, indent);
		ss << indent << "\t" << node->element;
		ss << toString(node->left, indent);
		return ss.str();
}



