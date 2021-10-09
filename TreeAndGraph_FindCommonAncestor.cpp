/*
First Common Ancestor: Design an algorithm and write code to find the first common ancestor
of two nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE: This is not
necessarily a binary search tree.
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


bool is_BST(Node* root, int min, int max)
{
	if (!root)
		return true;

	if ((min != -1 && max != -1) && (!(root->data > min && root->data <= max)))
		return false;

	if (is_BST(root->left, min, root->data))
		return is_BST(root->right, root->data, max);

	return false;
}


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

	void printBreadthwise(queue <Node*> my_queue)
	{
		Node* n = my_queue.front();
		my_queue.pop();

		cout << n->data << " ";

		if (n->left)
			my_queue.push(n->left);

		if (n->right)
			my_queue.push(n->right);

		if (my_queue.size() > 0)
			printBreadthwise(my_queue);
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

	void print_prefix()
	{
		Node* itr = root;
		printPrefix(itr);
	}

	void print_breadthwise()
	{
		queue<Node*> my_queue;
		my_queue.push(root);

		printBreadthwise(my_queue);
	}
};

BinaryTree myTree;

int level_of_node(Node* root, Node* target_node, int level = 0)
{
	if (!root || !target_node)
		return -1;

	if (root == target_node)
		return level;

	return max(level_of_node(root->left, target_node, level + 1), level_of_node(root->right, target_node, level + 1));
}

Node* get_parent_of_node(const Node* node, Node* root = myTree.root)
{
	if (!root)
		return NULL;

	if (root == node)
		return NULL;

	if (root->left == node || root->right == node)
		return root;

	Node* result = NULL;
	if (root->left)
		result = get_parent_of_node(node, root->left);

	if(root->right && result == NULL)
		result = get_parent_of_node(node, root->right);

	return result;
}

Node* go_up_by_n(Node* node, int by)
{
	if (by == 0)
		return node;

	if (!node)
		return myTree.root;

	return go_up_by_n(get_parent_of_node(node), by - 1);
}

Node* find(Node* root, const int data)
{
	if(!root)
		return NULL;

	if (root->data == data)
		return root;

	Node* result = find(root->left, data);
	if (!result)
		result = find(root->right, data);

	return result;
}

Node* commonAncestor(Node* node1, Node* node2)
{
	int node1_level = level_of_node(myTree.root, node1);
	int node2_level = level_of_node(myTree.root, node2);

	if (node1_level == -1 || node2_level == -1)								// if any of the node doesnot exist, return -1
		return NULL;

	Node* first = (node1_level < node2_level) ? node1 : node2;				// shallower node is stored in first
	Node* second = (node1_level < node2_level) ? node2 : node1;				// deeper node is stored in second

	int abs_dif = abs(node1_level - node2_level);
	if(abs_dif > 0)
		second = go_up_by_n(second, abs_dif);								// Move deeper node to the same level of the shallower node

	if (first == second)													// If both nodes were under same subtree, they would meet at this point
		return first;

	else
	{
		while (first != second)
		{
			first = get_parent_of_node(first);
			second = get_parent_of_node(second);
		}

		return first;
	}
}

int main()
{
	myTree.insert(10);
	myTree.insert(5);
	myTree.insert(15);
	myTree.insert(3);
	myTree.insert(7);
	myTree.insert(13);
	myTree.insert(17);

	myTree.print_breadthwise();
	//cout << "\nLevel of Node: " << level_of_node(myTree.root, myTree.root->right);
	//cout << "\nGo up by 2: " << go_up_by_n(myTree.root->left->right, 2)->data;
	//cout << "\nFinding a Node: " << find(myTree.root, 17)->data;
	cout << "\nCommon Ancestors: " << commonAncestor(myTree.root->left, myTree.root->right)->data;
	cout << "\nCommon Ancestors: " << commonAncestor(myTree.root->left, myTree.root->right->right)->data;
	cout << "\nCommon Ancestors: " << commonAncestor(myTree.root->left->left, myTree.root->right->right)->data;
	cout << "\nCommon Ancestors: " << commonAncestor(myTree.root->left, myTree.root->left->right)->data;
	cout << "\nCommon Ancestors: " << commonAncestor(myTree.root->left, myTree.root->left)->data;


	cout << endl;
	return 0;
}