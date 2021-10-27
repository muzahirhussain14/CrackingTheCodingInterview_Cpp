/*
Check of a given BST is valid or not.
*/


#include <iostream>
#include <queue>
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


void print_breadth_wise(queue<Node*> my_queue)
{

	Node* node = my_queue.front();
	my_queue.pop();

	cout << node->data << "\n";

	if (node->left)
		my_queue.push(node->left);

	if (node->right)
		my_queue.push(node->right);

	if (my_queue.size() > 0)
		print_breadth_wise(my_queue);
}


bool is_bst(Node* root, int min = INT_MIN, int max = INT_MAX)
{
	if (root == NULL)
		return true;

	if (root->data < min || root->data >= max)
		return false;

	return is_bst(root->left, min, root->data) && is_bst(root->right, root->data, max);
}

void print_breadth_wise(Node* root)
{
	queue<Node*> my_queue;
	my_queue.push(root);

	print_breadth_wise(my_queue);
}


int main()
{
	Node* root = new Node(10);
	root->left = new Node(5);
	root->left->left = new Node(3);
	root->left->left->left = new Node(1);
	root->left->left->right = new Node(4);
	root->left->right = new Node(7);
	root->left->right->left = new Node(6);
	root->left->right->right = new Node(7);

	root->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right = new Node(16);
	
	print_breadth_wise(root);
	cout << "Is BST: " << (is_bst(root) == true ? "YES\n" : "NO\n");


	cout << endl;
	return 0;
}