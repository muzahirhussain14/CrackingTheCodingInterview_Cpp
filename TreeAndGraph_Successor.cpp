/*
Successor: Write an algorithm to find the "next" node (i.e., in-order successor) of a given node in a
binary search tree. You may assume that each node has a link to its parent.
*/

#include<iostream>
#include<queue>

using namespace std;

class Node {
public:
	Node* left;
	Node* right;
	Node* parent;

	int data;

	Node(int data)
	{
		this->data = data;
		parent = left = right = NULL;
	}
};

class BinaryTree
{
public:
	Node* root;

	void insert(queue<Node*>& childrens, const int data)
	{
		Node* n = childrens.front();
		childrens.pop();

		if (n->left)
			childrens.push(n->left);
		else
		{
			n->left = new Node(data);
			n->left->parent = n;

			return;
		}

		if (n->right)
			childrens.push(n->right);
		else
		{
			n->right = new Node(data);
			n->right->parent = n;
			return;
		}
		return insert(childrens, data);
	}

	void printPrefix(Node* itr)
	{
		cout << itr->data << " ";

		if (itr->left)
			printPrefix(itr->left);

		if (itr->right)
			printPrefix(itr->right);
	}

	void printBreadthwise(queue <Node*> my_queue)
	{
		Node* n = my_queue.front();
		my_queue.pop();

		cout << n->data << " ";

		if (n->left)
			my_queue.push(n->left);

		if (n->right)
			my_queue.push(n->right);

		if (my_queue.size() > 0)
			printBreadthwise(my_queue);
	}

	void printParentBreadthwise(queue <Node*> my_queue)
	{
		Node* n = my_queue.front();
		my_queue.pop();

		cout << "Node-Parent: " << (n->parent ? n->parent->data : 0) <<  " Node-Value: " << n->data << "\n";

		if (n->left)
			my_queue.push(n->left);

		if (n->right)
			my_queue.push(n->right);

		if (my_queue.size() > 0)
			printParentBreadthwise(my_queue);
	}

	BinaryTree()
	{
		root = NULL;
	}

	void insert(int data)
	{
		if (!root)
			root = new Node(data);

		else
		{
			queue<Node*> nodes;
			nodes.push(root);

			insert(nodes, data);
		}
	}

	void print_prefix()
	{
		Node* itr = root;
		printPrefix(itr);
	}

	void print_breadthwise()
	{
		queue<Node*> my_queue;
		my_queue.push(root);

		printBreadthwise(my_queue);
	}

	void printParent_breadthwise()
	{
		queue<Node*> my_queue;
		my_queue.push(root);

		printParentBreadthwise(my_queue);
	}
};

Node* getLeftMost(Node* n)
{
	if (!n)
		return NULL;

	if (n->left == NULL)
		return n;

	getLeftMost(n->left);
}

Node* getSuccessor(Node * n)
{
	if (n->right)
		return getLeftMost(n->right);

	else
	{
		Node* parent = n->parent;
		if (parent->left == n)
		{
			return parent;
		}
		if (parent->right == n)
		{
			Node* itr = parent;
			while (itr != NULL && itr->left != parent)
				itr = itr->parent;

			parent = itr;
		}
		return parent;
	}
}

int main()
{
	BinaryTree myTree;
	myTree.insert(10);
	myTree.insert(5);
	myTree.insert(15);
	myTree.insert(3);
	myTree.insert(7);
	myTree.insert(13);
	myTree.insert(17);

	myTree.print_breadthwise();
	cout << "\nSuccessor Node (root): " << getSuccessor(myTree.root)->data;
	cout << "\nSuccessor Node (left-node): " << getSuccessor(myTree.root->left->left)->data;
	cout << "\nSuccessor Node (right-node): " << getSuccessor(myTree.root->left->right)->data;
	cout << "\nSuccessor Node (last-node): " << getSuccessor(myTree.root->right->right)->data;



	cout << endl;
	return 0;
}