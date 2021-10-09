/*
Check Balanced: Implement a function to check if a binary tree is balanced. For the purposes of
this question, a balanced tree is defined to be a tree such that the heights of the two subtrees of any
node never differ by more than one
*/

#include<iostream>
#include<queue>

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

	void print()
	{
		Node* itr = root;
		printPrefix(itr);
	}
};


int height_of_tree(Node *root)
{
	if (root == NULL)
		return -1;

	return max(height_of_tree(root->left), height_of_tree(root->right)) + 1;
}

bool check_balanced(Node* root)
{
	if (!root)
		return true;

	if (std::abs(height_of_tree(root->left) - height_of_tree(root->right)) > 1)
		return false;

	bool result = check_balanced(root->left);
	if(result)
		result = check_balanced(root->right);

	return result;
}

int main()
{
	BinaryTree myTree;
	myTree.insert(3);
	myTree.insert(7);
	//myTree.insert(9);
	myTree.insert(6);
	myTree.insert(5);
	myTree.insert(4);
	myTree.insert(3);
	myTree.insert(11);
	myTree.insert(17);

	myTree.print();
	cout << "\nHeight of Sub-tree: " << height_of_tree(myTree.root) << "\n";
	cout << "\nIs-Balanced: " << (check_balanced(myTree.root) ? "YES\n" : "NO\n");

	cout << endl;
	return 0;
}