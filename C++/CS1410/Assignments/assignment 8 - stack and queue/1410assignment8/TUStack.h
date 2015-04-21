#ifndef TUSTACK_H
#define TUSTACK_H
#include <string>

using namespace std;

template<class T>
class TUStack
{
private:
	int m_capacity;
	T* m_stackArray;
	int m_top;

protected:

public:
	TUStack(int nSize)
		: m_capacity(nSize),
		m_top(0)
	{
		if (m_capacity < 0) throw string("Cannot initialize the array to a negative number\n\n");
		m_stackArray = new T[nSize];
	}

	void push(T item)
	{
		if (m_top == m_capacity) throw string("The stack is full, cannot add any more elements\n\n");

		m_stackArray[m_top] = item;
		m_top++;
	}

	bool isEmpty()
	{
		if (m_top == 0)
			return true;
		else
			return false;
	}

	T pop()
	{
		if (isEmpty()) throw string("The stack is empty, cannot remove any items\n\n");
		m_top--;
		return m_stackArray[m_top];
	}

	int size()
	{
		return m_capacity;
	}

	int position()
	{
		return m_top - 1;
	}

	T operator[](int index) const
	{
		if (index  < 0 || index > m_capacity) throw string("Illegal index, cannot access items below 0 or above the capacity\n\n");
		return m_stackArray[index];
	}





};

#endif