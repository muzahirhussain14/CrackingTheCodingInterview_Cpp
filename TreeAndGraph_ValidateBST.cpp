// Validate 8ST: Implement a function to check if a binary tree is a binary search tree.

#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
	Node* left;
	Node* right;

	int data;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};


bool is_BST(Node* root, int min, int max)
{
	if (!root)
		return true;

	if ((min != -1 && max != -1) && (!(root->data > min && root->data <= max)))
		return false;

	if (is_BST(root->left, min, root->data))
		return is_BST(root->right, root->data, max);

	return false;
}


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
			return;
		}

		if (n->right)
			childrens.push(n->right);
		else
		{
			n->right = new Node(data);
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
};


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
	cout << "\nIs_BST: " << (is_BST(myTree.root, -1, -1) ? "Yes\n" : "No\n");

	cout << endl;
	return 0;
}