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

void print_breadth_wise(Node* root)
{
	queue<Node*> my_queue;
	my_queue.push(root);

	print_breadth_wise(my_queue);

}

Node* construct_bst(int arr[], int min, int max)
{
	if (min > max)
		return NULL;

	int mid = (min + max) / 2;
	Node* root = new Node(arr[mid]);
	root->left = construct_bst(arr, min, mid - 1);
	root->right = construct_bst(arr, mid + 1, max);

	return root;
}

Node* construct_bst(int arr[], int SIZE)
{
	return construct_bst(arr, 0, SIZE - 1);
}

int main()
{
	const int SIZE = 10;
	int arr[SIZE] = { 1,2,3,4,5,6,7,8,9,10 };
	Node* tree = construct_bst(arr, SIZE);


	print_breadth_wise(tree);

	cout << endl;
	return 0;
}