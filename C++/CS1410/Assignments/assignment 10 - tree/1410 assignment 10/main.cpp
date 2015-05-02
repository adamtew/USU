#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class WordNode
{
private:
	

protected:

public:
	WordNode(int word, int freq = 1, WordNode* left = NULL, WordNode* right = NULL)
		: m_word(word),
		m_freq(freq),
		m_pLeft(left),
		m_pRight(right)
	{

	}
	int m_word;
	int m_freq;
	WordNode* m_pLeft;
	WordNode* m_pRight;


	int getWord()
	{
		return m_word;
	}

	int getFreq()
	{
		return m_freq;
	}

	WordNode* getLeft()
	{
		return m_pLeft;
	}

	WordNode* getRight()
	{
		return m_pRight;
	}

	void setWord(int word)
	{
		m_word = word;
	}

	void setFreq(int freq)
	{
		m_freq = freq;
	}

	void setLeft(WordNode* left)
	{
		m_pLeft = left;
	}

	void setRight(WordNode* right)
	{
		m_pRight = right;
	}
};


class WordTree
{
private:
	WordNode* m_pRoot;
	ofstream fout;

	// Helper for task 2
	void insertHelper(int word, WordNode*& pNode)
	{
		if (pNode != NULL)
		{
			if (word == pNode->getWord())
			{
				pNode->setFreq(pNode->getFreq() + 1);
			}
			else if (word < pNode->getWord())
			{
				insertHelper(word, pNode->m_pLeft);
			}
			else
			{
				insertHelper(word, pNode->m_pRight);
			}
		}
		else
		{
			pNode = new WordNode(word);
		}
	}

	// Helper for task 3 - Sorted descendingly by frequencies and increasingly by words
	void insertHelper(int word, int freq, WordNode*& pNode)
	{
		if (pNode != NULL)
		{
			if (freq == pNode->getFreq() && word == pNode->getWord())
			{
				pNode->setFreq(freq);
			}
			else if (freq > pNode->getFreq())
			{
				insertHelper(word, freq, pNode->m_pLeft);
			}
			else
			{
				insertHelper(word, freq, pNode->m_pRight);
			}
		}
		else
		{
			pNode = new WordNode(word, freq);
		}
	}

	void inorderTraversalWordHelper(WordNode* pNode)
	{
		if (pNode != NULL)
		{
			inorderTraversalWordHelper(pNode->getLeft());
			cout << pNode->getWord() << " ";
			inorderTraversalWordHelper(pNode->getRight());
		}
	}

	void inorderTraversalFreqHelper(WordNode* pNode)
	{
		if (pNode != NULL)
		{
			inorderTraversalFreqHelper(pNode->getLeft());
			cout << pNode->getFreq() << " ";
			inorderTraversalFreqHelper(pNode->getRight());
		}
	}

	void inorderTraversalBothHelper(WordNode* pNode)
	{
		if (pNode != NULL)
		{
			inorderTraversalBothHelper(pNode->getLeft());
			cout << pNode->getWord() << " " << pNode->getFreq() << endl;
			inorderTraversalBothHelper(pNode->getRight());
		}
	}

	void copyHelper(WordTree& tree, WordNode* pNode)
	{
		if (pNode != NULL)
		{
			copyHelper(tree, pNode->getRight());
			tree.insert(pNode->getWord(), pNode->getFreq());
			copyHelper(tree, pNode->getLeft());
		}
	}

	void saveHelper(WordNode* pNode)
	{
		if (pNode != NULL)
		{
			saveHelper(pNode->getLeft());
			fout << pNode->getWord() << " " << pNode->getFreq() << endl;
			saveHelper(pNode->getRight());
		}
	}

	int getSizeHelper(WordNode* pNode)
	{
		if (pNode != NULL)
		{
			return 1 + getSizeHelper(pNode->m_pRight) + getSizeHelper(pNode->m_pLeft);
		}
		else
		{
			return 0;
		}
	}

	int max(int one, int two)
	{
		if (one > two)
		{
			return one;
		}
		else
		{
			return two;
		}
	}

	int getHeightHelper(WordNode* pNode)
	{
		if (pNode != NULL)
		{
			return 1 + max(getHeightHelper(pNode->m_pRight), getHeightHelper(pNode->m_pLeft));
		}
		else
		{
			return 0;
		}
	}


protected:

public:
	WordTree(WordNode* root = NULL)
		: m_pRoot(root)
	{

	}

	// Task 4
	void copyTo(WordTree& tree)
	{
		copyHelper(tree, m_pRoot);
	}

	void inorderTraversalWord()
	{
		inorderTraversalWordHelper(m_pRoot);
		cout << endl;
	}

	void inorderTraversalFreq()
	{
		inorderTraversalFreqHelper(m_pRoot);
		cout << endl;
	}

	void inorderTraversalBoth()
	{
		inorderTraversalBothHelper(m_pRoot);
	}

	// Task 2
	void insert(int word)
	{
		insertHelper(word, m_pRoot);
	}

	// Task 3
	void insert(int word, int freq)
	{
		insertHelper(word, freq, m_pRoot);
	}

	// Task 5 Read words in an input file one-by-one and insert them into the tree
	void load(string filename)
	{
		ifstream fin(filename);
		string line;
		if (fin.is_open())
		{
			while (getline(fin, line))
			{
				insert(stoi(line));
			}
			fin.close();
		}
	}

	// Task 6 Write words and frequencies to an output file in descending order
	void save(string filename)
	{
		fout.open(filename);
		if (fout.is_open())
		{
			fout << "Word Frequency\n";
			saveHelper(m_pRoot);
			fout.close();
		}
	}

	int getSize()
	{
		return getSizeHelper(m_pRoot);
	}

	int getHeight()
	{
		return getHeightHelper(m_pRoot);
	}

};


// Task 7
int main()
{
	// a.
	WordTree treeWord;
	WordTree treeFreq;

	// b.
	treeWord.load("input.txt");

	// c.
	treeWord.copyTo(treeFreq);

	// d.
	treeFreq.save("output.txt");


	cout << "TreeWord Size: " << treeWord.getSize() << " Height: " << treeWord.getHeight() << endl;
	cout << "TreeFreq Size: " << treeFreq.getSize() << " Height: " << treeFreq.getHeight() << endl;

	return 0;
}