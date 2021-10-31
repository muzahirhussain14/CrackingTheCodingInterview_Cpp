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

	void print_helper(Node* root)
	{
		if (root == NULL)
			return;

		cout << root->data << "\n";

		print_helper(root->left);
		print_helper(root->right);
	}

	Node* convert_bst_to_linkedlist(Node* root)
	{
		if (root == NULL)
			return NULL;

		if (!root->left && !root->right)						// return the leave node
			return root;

		Node* head = convert_bst_to_linkedlist(root->left);
		root->right = convert_bst_to_linkedlist(root->right);

		if (head) 
		{														// insert current node at the end of the head
			Node* itr = head;
			while(itr->right)
				itr = itr->right;
			
			itr->right = root;
			return head;
		}
		else
			return root;
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

	void print_node()
	{
		print_helper(root);
	}

	Node* convert_bst_to_linkedlist()
	{
		return convert_bst_to_linkedlist(root);
	}
};


void print_linkedlist(Node* head)
{
	if (!head)
		return;

	while (head)
	{
		cout << head->data << " ";
		head = head->right;
	}
}

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
	tree.insert_node(18);


	cout << "Orignal Tree\n";
	tree.print_node();

	Node* linkedlist = tree.convert_bst_to_linkedlist();
	print_linkedlist(linkedlist);

	cout << endl;
	return 0;
}