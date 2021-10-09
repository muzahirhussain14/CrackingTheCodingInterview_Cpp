/*
Minimal Tree: Given a sorted (increasing order) array with unique integer elements, write an
algorithm to create a binary search tree with minimal height.
*/

#include<iostream>
using namespace std;

class Node
{
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


Node* generate_BST(int* arr, int start, int end)
{
	if (end < start)
		return NULL;

	Node *root;
	int mid = (start + end) / 2;

	root = new Node(arr[mid]);

	root->left = generate_BST(arr, start, mid - 1);
	root->right = generate_BST(arr, mid + 1, end);

	return root;
}

void print_tree(Node* n)
{
	cout << n->data << "\n";

	if (n->left)
		print_tree(n->left);
	if (n->right)
		print_tree(n->right);
}

int main() 
{
	int arr[7] = { 3,5,7,11,12,13,17 };
	Node* root = generate_BST(arr, 0, 6);

	print_tree(root);

	cout << endl;
	return 0;
}