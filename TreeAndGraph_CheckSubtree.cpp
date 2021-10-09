/*
Check Subtree: Tl and T2 are two very large binary trees, with Tl much bigger than T2. Create an
algorithm to determine if T2 is a subtree of Tl.
A tree T2 is a subtree of T1 if there exists a node n in Tl such that the subtree of n is identical to T2 .
That is, if you cut off the tree at node n, the two trees would be identical.
*/


#include<iostream>
#include<string>
using namespace std;

class Node {
public:
	Node* left;
	Node* right;

	char data;

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


// Approach 1, traverse both the trees and get the string representations. Compare the string representations.
string preOrderTreverse(Node* tree)
{
	if (!tree)
		return "";

	if (!tree->left && !tree->right)
		return string{ tree->data };				// convert character to string

	string result;
	result.push_back(tree->data);

	if (!tree->left)
		result += 'X';
	else
		result += preOrderTreverse(tree->left);


	if (!tree->right)
		result += 'X';
	else
		result += preOrderTreverse(tree->right);

	return result;
}


// Approach 2
bool compare_trees(Node* n1, Node* n2)
{
	if (!n1 && !n2)
		return true;

	if (!n1 || !n2)
		return false;

	if (n1->data != n2->data)
		return false;

	return compare_trees(n1->left, n2->left) && compare_trees(n1->right, n2->right);
}

bool is_subTree(Node* t1, Node* t2)
{
	if (!t1)
		return false;

	if (t1->data == t2->data && compare_trees(t1, t2) == true)
		return true;
	
	return is_subTree(t1->left, t2) || is_subTree(t1->right, t2);
}

int main()
{
	// Tree 1
	Node* tree1 = new Node('1');
	tree1->left = new Node('2');
	tree1->left->left = new Node('4');
	tree1->left->right = new Node('5');
	tree1->left->left->left = new Node('8');
	tree1->left->left->right = new Node('9');

	tree1->right = new Node('3');
	tree1->right->left = new Node('6');
	tree1->right->right = new Node('7');
	tree1->right->left->left = new Node('A');
	tree1->right->right->left = new Node('B');
	tree1->right->right->right = new Node('C');
	tree1->right->right->left->left = new Node('D');
	tree1->right->right->left->right = new Node('E');

	// Tree 2
	Node* tree2 = new Node('3');
	tree2->left = new Node('6');
	tree2->right = new Node('7');
	tree2->left->left = new Node('A');
	tree2->right->left = new Node('B');
	tree2->right->right = new Node('C');
	tree2->right->left->left = new Node('D');
	tree2->right->left->right = new Node('E');


	// Approach 1 (Comparing string representation of the two tree traversals) 
	string tree1_traversal = preOrderTreverse(tree1);
	string tree2_traversal = preOrderTreverse(tree2);
	cout << "\n************ APPROACH 1 ***************\n";
	cout << "Traversal Tree 1: " << tree1_traversal << "\n";
	cout << "Traversal Tree 2: " << tree2_traversal << "\n";

	if (tree1_traversal.find(tree2_traversal) != string::npos)
		cout << "Tree2 is a substring of Tree1";

	else if (tree2_traversal.find(tree1_traversal) != string::npos)
		cout << "Tree1 is a substring of Tree2";

	else
		cout << "No tree is a subtree of another tree";



	// Approach 2 (Traversing and Comparing)
	cout << "\n\n************ APPROACH 1 ***************\n";
	cout << (is_subTree(tree1, tree2) ? "Tree2 is a subtree of Tree 1" : "No tree is a subtree of another tree");

	cout << endl;
	return 0;
}