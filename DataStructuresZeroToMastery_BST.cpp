#include<iostream>
#include<queue>

using namespace std;

class Node {

public:
	int data;
	Node* left;
	Node* right;

	Node(int d)
	{
		data = d;
		left = right = NULL;
	}
};


class BST
{
private:
	Node* root;

	Node* insert_helper(Node* root, int data)
	{
		if (root == NULL)
			return new Node(data);

		if (data >= root->data)
			root->right = insert_helper(root->right, data);
		else
			root->left = insert_helper(root->left, data);

		return root;
	}

	int find_min_on_right(Node* root)
	{
		if (!root->left)
			return root->data;

		return find_min_on_right(root->left);
	}

	Node* delete_helper(Node* root, int data)
	{
		if (root == NULL)
			return root;

		if (root->data == data)						// There are three cases to handle. If both childs are null, if only one child is null, if both the childs are present.
		{
			if (root->left == NULL && root->right == NULL)				// if both childs are null
			{
				delete root;
				return NULL;
			}

			else if (root->left && root->right)									// if both childs are present
			{
				int number = find_min_on_right(root->right);
				root->data = number;
				root->right = delete_helper(root->right, number);				// delete the orignal number
			}

			else if (root->left)												// if only one child is present
			{
				Node* temp = root->left;
				delete root;
				return temp;
			}

			else if (root->right)										// if only right child is present
			{
				Node* temp = root->right;
				delete root;
				return temp;
			}
		}

		if (data >= root->data)
			root->right = delete_helper(root->right, data);
		else
			root->left = delete_helper(root->left, data);
	
		return root;
	}

	void print_helper(Node* root)
	{
		if (root == NULL)
			return;

		cout << root->data << "\n";

		print_helper(root->left);
		print_helper(root->right);
	}

public:
	BST()
	{
		root = NULL;
	}

	void insert_node(int data)
	{
		root = insert_helper(root, data);
	}

	void delete_node(int data)
	{
		root = delete_helper(root, data);
	}

	void print_node()
	{
		print_helper(root);
	}
};


int main()
{
	BST tree;
	tree.insert_node(10);
	tree.insert_node(5);
	tree.insert_node(7);
	tree.insert_node(3);
	tree.insert_node(15);
	tree.insert_node(13);
	tree.insert_node(17);
	tree.insert_node(16);
	tree.insert_node(20);



	cout << "Orignal Tree\n";
	tree.print_node();

	cout << "\nAfter Deleting Leave Node 7\n";
	tree.delete_node(7);
	tree.print_node();

	cout << "\nAfter Deleting Node with one childs: 5\n";
	tree.delete_node(5);
	tree.print_node();

	cout << "After Deleting Node with both childs: 15\n";
	tree.delete_node(15);
	tree.print_node();

	cout << endl;
	return 0;
}