/*
Given a binary search tree, return all the deepest leave nodes on same level
*/

#include <iostream>
#include <queue>
#include <vector>
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

class BinaryTree {

private:
	Node* root;

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

	int get_tree_depth(Node* root)
	{
		if (root == NULL)
			return 0;

		return max(get_tree_depth(root->left), get_tree_depth(root->right)) + 1;
	}

	vector<Node*> get_deepest_nodes(Node* root, int height, int cur_level = 1)
	{
		vector<Node*> result;

		if (root == NULL)
			return result;					// empty result

		if (height == cur_level)
		{
			result.push_back(root);
		}
		else
		{
			vector<Node*> a = get_deepest_nodes(root->left, height, cur_level + 1);
			vector<Node*> b = get_deepest_nodes(root->right, height, cur_level + 1);

			if (a.size() > 0 && b.size() > 0)			// merge the two, we have multiple deep leave nodes
			{
				result = a;

				for (Node* i : b)
					result.push_back(i);
			}
			else
			{
				result = a.size() > 0 ? a : b;
			}
		}

		return result;
	}

public:
	BinaryTree()
	{
		root = NULL;
	}

	void insert(int d)
	{
		if (root == NULL)
		{
			root = new Node(d);
		}
		else
		{
			Node* itr = root;
			while (true)
			{
				if (itr->left && d < itr->data)
					itr = itr->left;

				else if (itr->right && d >= itr->data)
					itr = itr->right;

				else
					break;
			}

			if (d < itr->data)
				itr->left = new Node(d);
			else
				itr->right = new Node(d);
		}
	}

	void print_breadth_wise()
	{
		queue<Node*> my_queue;
		my_queue.push(root);

		print_breadth_wise(my_queue);
	}

	int get_tree_depth()
	{
		return get_tree_depth(root);
	}

	vector<Node*> get_deepest_nodes()
	{
		if (root == NULL)
			return vector<Node*>();

		int height_of_tree = get_tree_depth();
		return get_deepest_nodes(root, height_of_tree);
	}
};


void print_vector(vector<Node*> vec)
{
	for (Node* i : vec)
		cout << i->data << " ";

	cout << "\n";
}


int main()
{
	BinaryTree tree;

	tree.insert(16);
	tree.insert(20);
	tree.insert(19);
	tree.insert(25);
	tree.insert(10);
	tree.insert(17);
	tree.insert(19);
	tree.insert(9);
	tree.insert(8);

	//tree.print_breadth_wise();

	cout << tree.get_tree_depth() << "\n";
	vector<Node*> result = tree.get_deepest_nodes();
	cout << "Deepest Nodes: ";
	print_vector(result);

	return 0;
}