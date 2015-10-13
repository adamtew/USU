#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

// Task 3 (10 points)
template<class T>
class Queue : public LinedList<T>
{
private:

protected:
	int pos;
	int m_size;

public:
	Queue(int size, T data)
		: LinedList(data),
		pos(0),
		m_size(size)
	{

	}


	T* pop()
	{
		if (pos == 0) throw string("The queue is empty");
		T* ret = removeBegin();
		return ret;
	}

	virtual void push(T* pItem)
	{
		insertEnd(pItem); 
		pos++;
	}

	T* top()
	{
		if (begin() == NULL) throw string("The queue is empty");
		T* ret = new T (begin()->getData());
		return ret;
	}

};

#endif