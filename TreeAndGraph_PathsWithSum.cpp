/*
Paths with Sum: You are given a binary tree in which each node contains an integer value (which
might be positive or negative). Design an algorithm to count the number of paths that sum to a
given value. The path does not need to start or end at the root or a leaf, but it must go downwards
(traveling only from parent nodes to child nodes).
*/


#include <iostream>
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

	void print_tree(Node* root)
	{
		if (!root)
			return;

		print_tree(root->left);
		cout << root->data << " ";
		print_tree(root->right);
	}

};

int count_paths_with_sum_helper(Node* node, const int sum, int difference)
{
	if (!node)
		return 0;

	difference -= node->data;
	int result = 0;

	if (difference < 0)
		difference = (sum - node->data < 0) ? sum : sum - node->data;

	if (difference == 0) 
	{
		result++;
		difference = sum;
	}

	result += (count_paths_with_sum_helper(node->left, sum, difference) + count_paths_with_sum_helper(node->right, sum, difference));
	
	return result;
}

int count_paths_with_sum(Node* node, const int sum)
{
	return count_paths_with_sum_helper(node, sum, sum);
}

int main()
{
	Node* root = new Node(10);
	root->left = new Node(0);
	root->left->left = new Node(7);
	root->left->right = new Node(9);
	root->left->left->left = new Node(5);
	root->left->left->right = new Node(4);
	root->left->right->left = new Node(11);

	root->right = new Node(20);
	root->right->left = new Node(26);
	root->right->right = new Node(7);
	root->right->right->left = new Node(2);
	root->right->right->right = new Node(4);
	root->right->right->left->left = new Node(3);

	cout << "Tree 1: ";
	root->print_tree(root);
	cout << "\nTotal paths with Sum(12): " << count_paths_with_sum(root, 12) << "\n";


	Node* root2 = new Node(10);
	root2->left = new Node(5);
	root2->left->left = new Node(3);
	root2->left->right = new Node(1);
	root2->left->right->right = new Node(2);
	root2->left->left->left = new Node(3);
	root2->left->left->right = new Node(-2);

	root2->right = new Node(-3);
	root2->right->right = new Node(11);
	
	cout << "Tree 2: ";
	root2->print_tree(root2);
	cout << "\nTotal paths with Sum(8): " << count_paths_with_sum(root2, 8) << "\n";



	cout << endl;
	return 0;
}