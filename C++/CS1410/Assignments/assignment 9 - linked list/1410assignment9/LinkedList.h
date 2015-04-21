#ifndef LINKEDLIST_H
#define LINKEDLIST_H

//Task 2 (15 points)
template<class T>
class LinedList
{
private:
	Node<T>* m_pHead;
	Node<T>* m_pTail;
	int m_count;

protected:

	int insert(T* pItem, int pos = -1)
	{
		int ret = 0;
		Node<T>* pTemp = m_pHead;
		if (pItem != NULL)
		{
			if (pos <= 0 || pos >= getSize())insertEnd(pItem);
			else
				for (int i = 0; i < pos; i++)
				{
					pTemp = pTemp->getNext();
					ret++;
				}
		}
		Node<T>* pTempSet = new Node<T>(*pItem);
		pTemp->setNext(pTempSet);
		pTempSet->setNext(NULL);
		return ret;
	}

	void insertEnd(T* pItem)
	{
		Node<T>* pTemp;
		for (pTemp = m_pHead; pTemp->getNext() != NULL; pTemp = (pTemp->getNext()));

		pTemp->setNext(new Node<T>(*pItem));
		m_pTail = pTemp->getNext();
	}

	void insertHead(T* pItem)
	{
		Node<T>* pTemp = begin();
		m_pHead = new Node<T>(*pItem);
		m_pHead->setNext(pTemp);

	}
	
	Node<T>* nodeAt(int pos)
	{
		if (pItem != NULL)
		{
			for (pItem = m_pHead; pItem != NULL; pItem->getNext())
			{
				pos--;
				if (pos == 0)
					return Node*
			}
		}

		return NULL;
		
	}

	T* removeAt(int pos)
	{
		Node<T>* pTemp = m_pHead;
		Node<T>* pPrev = m_pHead;
		//if (pos <= 0 || pos >= getSize()) return removeEnd();
		else
			for (int i = 0; i < pos; i++)
			{
			pTemp = pTemp->getNext();
			pPrev = pTemp;
			}

		pPrev->setNext(pTemp->getNext());
		pTemp->setNext(NULL);
		T ret = pTemp->getData();
		return &ret;
	}

	T* removeEnd()
	{
		Node<T>* pTemp = m_pHead;
		if (m_pHead->getNext() == NULL)
		{
			pTemp = m_pTail;

			T* ret = new T(pTemp->getData());
			pTemp->setNext(NULL);
			delete pTemp;
			return ret;
		}
		
		Node<T>* pPrev = m_pHead;

		if (pTemp != NULL)
		{
			for (pTemp = m_pHead; pTemp->getNext() != NULL; pTemp = (pTemp->getNext()))pPrev = pTemp;

			m_pTail = pPrev;
			pPrev->setNext(NULL);
			m_pTail->setNext(NULL);

			T* ret = new T( pTemp->getData());
			pTemp->setNext(NULL);
			delete pTemp;
			return ret;
		}
		
		return NULL;
	}

	T* removeBegin()
	{
		Node<T>* pTemp = m_pHead;
		m_pHead = m_pHead->getNext();
		return new T(pTemp->getData());
	}

	Node<T>* find(T* pItem)
	{
		if (pItem != NULL)
			for (Node* temp = m_pHead; temp != NULL; temp->getNext())
				if (temp->getData() == pItem->getData())return temp;

		return NULL;

	}

	void clear()
	{
		while (m_pHead != NULL)
		{
			Node<T>* temp = m_pHead->getNext();
			delete m_pHead;
			m_pHead = temp;
		}
	}

	int getSize()
	{
		return size(m_pHead);
	}

	int size(Node<T>* node)
	{
		if (node == NULL)
			return 0;
		else
			return 1 + size(node->getNext());
	}

	Node<T>* begin()
	{
		return m_pHead;
	}

	Node<T>* end()
	{
		return m_pTail;
	}

	T* at(int pos)
	{
		if (pItem != NULL)
			for (pItem = m_pHead; pItem != NULL; pItem->getNext())
			{
			pos--;
			if (pos == 0)
				return pItem;
			}
	}

	LinedList operator++ (int left)
	{
		LinedList temp(*this);
		operator++();
		return temp;
	}


public:
	LinedList(T data)
		: m_pHead(new Node<T>(data)),
		m_pTail(m_pHead)
	{

	}

};

#endif

