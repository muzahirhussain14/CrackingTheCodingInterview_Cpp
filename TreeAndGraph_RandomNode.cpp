/*
Random Node: You are implementing a binary search tree class from scratch, which, in addition
to insert, find, and delete, has a method getRandomNode() which returns a random node
from the tree. All nodes should be equally likely to be chosen. Design and implement an algorithm
for get RandomNode, and explain how you would implement the rest of the methods.




Approach:
We much return each node with 1/N probability. After all, we have N nodes and each node must have equal probability.
The total must be 1 (100%), therefore each must have 1\N probability.
But, with what probability should we traverse left versus right? It's not 50/50. If we have more node on left than right,
then we need to go left more often.
Since each node must have probability 1/N, the odds of picking something
from the left must have probability LEFT _SIZE * 1/N. This should therefore be the odds of going left.
Likewise, the odds of going right should be RIGHT_SIZE * 1/N
*/

#include <iostream>
using namespace std;

class BinarySearchTree
{
private:
	int data;
	int size;

	BinarySearchTree* getIthNode(int ith)
	{
		int left_size = left == NULL ? 0 : left->size;

		if (ith < left_size)				// go left
			return left->getIthNode(ith);

		else if (size == ith)
			return this;

		else								// go right		
			return right->getIthNode(abs(ith - (left_size + 1)));
	}

public:
	BinarySearchTree *left;
	BinarySearchTree *right;

	BinarySearchTree(int d)
	{
		data = d;
		left = right = NULL;
		size = 1;
	}

	int getData()
	{
		return data;
	}

	void insert(int d)
	{
		if (d < data)
		{
			if (left == NULL)
				left = new BinarySearchTree(d);

			else
				left->insert(d);
		}
		else
		{
			if (right == NULL)
				right = new BinarySearchTree(d);

			else
				right->insert(d);
		}
		
		++size;
	}

	bool find(int d)
	{
		if (data == d)
			return true;

		if (!left && !right)
			return false;

		if (d < data)
			return left->find(d);

		else
			return right->find(d);
	}

	void print()
	{		
		cout << data << " ";

		if (left)
			left->print();

		if (right)
			right->print();
	}

	BinarySearchTree* getRandomNode()
	{
		int i = 1 + (std::rand() % size);
		cout << "\n**** Rand **** : " << i << "\n";
		return getIthNode(i);
	}
};

int main()
{
	srand(time(0));

	BinarySearchTree bst(5);
	bst.insert(2);
	bst.insert(10);
	bst.insert(15);
	bst.insert(7);

	bst.print();
	cout << (bst.find(19) ? "\nFOUND" : "\nNOT FOUND");

	cout << "\nRandom: " << bst.getRandomNode()->getData();
	cout << endl;
	return 0;
}