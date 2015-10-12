#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

//Task 1 (5 points)
template<class T>
class Node
{
private:
	T m_data;
	Node* m_next;

public:
	Node(T data)
		: m_data(data),
		m_next(NULL)
	{

	}

	Node* getNext() const
	{
		//cout << "getNext(): " << m_next << endl;
		return m_next;
	}

	void setNext(Node* next)
	{
		if (next != NULL)
			m_next = next;
	}

	T getData() const
	{
		return m_data;
	}

	void setData(T data)
	{
		m_data = data;
	}

};

#endif