/*
List of Depths: Given a binary tree, design an algorithm which creates a linked list of all the nodes
at each depth (e.g., if you have a tree with depth D, you 'll have D linked lists).
*/

#include<iostream>
#include<queue>
#include<list>
#include<vector>

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

class LinkedlistNode 
{
public:
	int data;
	LinkedlistNode* next;

	LinkedlistNode(int d)
	{
		this->data = d;
		next = NULL;
	}
};

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

	void print()
	{
		Node* itr = root;
		printPrefix(itr);
	}
};


void appendHeadToList(vector<LinkedlistNode*>& lists, int root)
{
	vector<LinkedlistNode*> result;

	for (LinkedlistNode* list : lists)
	{
		LinkedlistNode* n = new LinkedlistNode(root);
		n->next = list;
		result.push_back(n);
	}
	lists = result;				// update result
}

// generate list depth wise
vector<LinkedlistNode*> generateList_depthWise(Node* b_tree)
{
	vector<LinkedlistNode*> result;

	if (!b_tree->left && !b_tree->right)
	{
		LinkedlistNode* head = new LinkedlistNode(b_tree->data);
		head->next = NULL;
		result.push_back(head);
		return result;
	}


	vector<LinkedlistNode*> subLists_left;
	vector<LinkedlistNode*> subLists_right;

	if (b_tree->left) 
	{
		subLists_left = generateList_depthWise(b_tree->left);
		appendHeadToList(subLists_left, b_tree->data);
	}

	if (b_tree->right)
	{
		subLists_right = generateList_depthWise(b_tree->right);
		appendHeadToList(subLists_right, b_tree->data);
	}

	for (LinkedlistNode* head : subLists_left)
		result.push_back(head);

	for (LinkedlistNode* head : subLists_right)
		result.push_back(head);

	return result;
}

// generate list breadth wise
vector<LinkedlistNode*> generateList_breadthWise(queue<Node*> parents)
{
	vector<LinkedlistNode*> result;
	LinkedlistNode* root = NULL;
	queue<Node*> childrens;

	while (!parents.empty())
	{
		Node* node = parents.front();
		parents.pop();

		// push childrens in new lists
		if (node->left)
			childrens.push(node->left);

		if (node->right)
			childrens.push(node->right);

		// create the list of all parents nodes
		if (root == NULL)
			root = new LinkedlistNode(node->data);
		else
		{
			LinkedlistNode* itr = root;
			while (!itr->next == NULL)
				itr = itr->next;

			itr->next = new LinkedlistNode(node->data);
		}
	}

	if (childrens.size() > 0)
		result = generateList_breadthWise(childrens);

	result.insert(result.begin(), root);
	return result;
}


void printAllLists(vector<LinkedlistNode*> lists)
{
	int counter = 1;
	for (LinkedlistNode* n : lists) 
	{
		LinkedlistNode* itr = n;
		cout << "\nList No.: " << counter++ << "  -->  ";

		while (itr)
		{
			cout << itr->data << " ";
			itr = itr->next;
		}
	}
}

int main() 
{
	// setting up the tree.
	BinaryTree myTree;
	myTree.insert(3);
	myTree.insert(7);
	//myTree.insert(9);
	myTree.insert(6);
	myTree.insert(5);
	myTree.insert(4);
	myTree.insert(3);
	myTree.insert(11);
	myTree.insert(17);

	myTree.print();
	vector<LinkedlistNode*> lists_depthWise = generateList_depthWise(myTree.root);
	cout << "Depth-wise Linkedlists";
	printAllLists(lists_depthWise);


	queue<Node*> parents;
	parents.push(myTree.root);
	vector<LinkedlistNode*> lists_breadthWise = generateList_breadthWise(parents);
	
	cout << "\n\nBreadth-wise Linkedlists";
	printAllLists(lists_breadthWise);


	cout << endl;
	return 0;
}