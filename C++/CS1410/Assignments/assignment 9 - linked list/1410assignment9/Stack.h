#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template<class T>
class Stack : LinedList < T >
{
private:
	int pos;
	int m_size;

public:
	Stack(int size, T data)
		: LinedList(data),
		pos(0),
		m_size(size)
	{

	}

	void push(T* pItem)
	{
		if (pos >= m_size) throw string("The stack is full");
		insertEnd(pItem);
		pos++;
	}

	T* pop()
	{
		if (pos == 0) throw string("The stack is empty");
		pos--;
		return removeEnd();
	}

	T* top()
	{
		if (end() == NULL) throw string("The stack is empty");
		T* ret = new T( end()->getData());
		return ret;
	}

	void erase()
	{
		clear();
	}
};

#endif