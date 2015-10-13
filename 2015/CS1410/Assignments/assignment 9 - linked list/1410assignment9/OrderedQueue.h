#ifndef ORDEREDQUEUE_H
#define ORDEREDQUEUE_H

#include "Queue.h"
#include "Node.h"

template<class T>
class OrderedQueue : Queue < T >
{
private:

public:
	OrderedQueue(int size, T data)
		: Queue(size, data)
	{

	}

	virtual void push(T* pItem)
	{
		if (pos >= m_size) throw string("The queue is full");
		int i = 0;
		T* pIt;
		Node<T>* pTemp = begin();

		for (pIt = new T(begin()->getData()); pItem < pIt, pTemp != NULL; pTemp = pTemp->getNext())
		{
			pIt = new T(pTemp->getData());
			i++;
		}

		insert(pItem, i);
		pos++;
	}

	T* pop()
	{
		if (pos == 0) throw string("The queue is empty");
		T* ret = removeBegin();
		return ret;
	}

	T* top()
	{
		if (begin() == NULL) throw string("The queue is empty");
		T* ret = new T(begin()->getData());
		return ret;
	}


};

#endif