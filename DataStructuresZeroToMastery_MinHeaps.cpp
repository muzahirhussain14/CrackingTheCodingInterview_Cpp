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

class MinHeap {

private:
	Node* root;
	queue<Node*> children;

	void print_breadth_wise(queue<Node*> childrens)
	{
		Node* n = childrens.front();
		childrens.pop();

		cout << n->data << " ";

		if (n->left)
			childrens.push(n->left);
		if (n->right)
			childrens.push(n->right);

		if (childrens.size() > 0)
			print_breadth_wise(childrens);
	}

	void print_depth_wise(Node* node)
	{
		if (!node)
			return;

		if (node->left)
			print_depth_wise(node->left);

		cout << node->data << " ";

		if (node->right)
			print_depth_wise(node->right);
	}

	void swap_data(Node* left, Node* right)
	{
		int temp = left->data;
		left->data = right->data;
		right->data = temp;
	}

	void heapify(Node* root, Node* parent_node = NULL)
	{
		if (!root)
			return;

		if (parent_node && root->data < parent_node->data)				// checking going down
			swap_data(root, parent_node);

		heapify(root->left, root);
		heapify(root->right, root);

		if (parent_node && root->data < parent_node->data)				// checking again on coming up
			swap_data(root, parent_node);
	}

	Node* remove_node(Node* node, Node* target, bool& is_deleted)
	{
		if (node == NULL || target == NULL)
			return NULL;

		if (node == target)
		{
			delete node;
			is_deleted = true;
			return NULL;
		}

		node->left = remove_node(node->left, target, is_deleted);

		if (!is_deleted)
			node->right = remove_node(node->right, target, is_deleted);

		return node;
	}

public:
	MinHeap()
	{
		root = NULL;
	}

	void insert(int data)
	{
		Node* new_node = new Node(data);

		if (root == NULL)
			root = new_node;

		else
		{
			Node* next_node = children.front();
			if (next_node->left == NULL)
				next_node->left = new_node;

			else if (next_node->right == NULL)
			{
				next_node->right = new_node;
				children.pop();							// remove the parent node
			}
		}
		children.push(new_node);
		heapify(root);
	}

	void remove_min()
	{
		Node* last_child = children.back();				// get last child
		swap_data(root, last_child);					// swap it's value with root

		bool is_deleted = false;
		remove_node(root, last_child, is_deleted);		// remove this last node
		heapify(root);									// heapify

		// Remove the last element from the children
		for (int i = 0; i < children.size(); ++i) 
		{
			if (i < children.size() - 1)				// don't add the last element
				children.push(children.front());
			children.pop();
		}
	}

	int get_min()
	{
		return root->data;
	}


	void print_breadth_wise()
	{
		queue<Node*> childrens;
		childrens.push(root);

		cout << "Print Breadth Wise\n";
		print_breadth_wise(childrens);
		cout << "\n";
	}

	void print_depth_wise()
	{
		cout << "Print Depth Wise\n";
		print_depth_wise(root);
		cout << "\n";
	}
};

int main()
{
	MinHeap tree;

	tree.insert(12);
	tree.insert(6);
	tree.insert(5);
	tree.insert(100);
	tree.insert(1);
	tree.insert(9);
	tree.insert(0);
	tree.insert(14);

	tree.print_breadth_wise();

	tree.remove_min();
	tree.remove_min();
	tree.print_breadth_wise();

	tree.insert(-4);
	tree.print_breadth_wise();

	tree.remove_min();
	tree.print_breadth_wise();

	cout << endl;
	return 0;
}