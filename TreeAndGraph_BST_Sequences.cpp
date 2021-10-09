/*
BST Sequences: A binary search tree was created by traversing through an array from left to right
and inserting each element. Given a binary search tree with distinct elements, print all possible
arrays that could have led to this tree.
*/

#include <iostream>
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

	void print_tree(Node* root)
	{
		if (!root)
			return;

		print_tree(root->left);
		cout << root->data << " ";
		print_tree(root->right);
	}
};

void swap(vector<int>& arr, int left_index, int right_index)
{
	int temp = arr[left_index];
	arr[left_index] = arr[right_index];
	arr[right_index] = temp;
}

void printArray(vector<int> arr)
{
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
}

vector<vector<int>>getCombination(vector<int> arr, int left, int right)
{
	vector<vector<int>> result;

	if (left == right)
	{
		result.push_back(arr);
		return result;
	}

	for (int i = left; i <= right; ++i)
	{
		swap(arr, left, i);

		for (auto vec : getCombination(arr, left + 1, right))
			result.push_back(vec);
		
		swap(arr, left, i);
	}
	return result;
}

vector<vector<int>> generate_lists_from_tree(Node* root)
{
	if (!root) {
		vector<vector<int>> _;
		return _;
	}

	vector <vector<int>> result{ vector<int>{root->data} };

	auto left = generate_lists_from_tree(root->left);
	auto right = generate_lists_from_tree(root->right);

	if (left.size() > 0)
	{
		for (auto vec : left)
		{
			result.push_back(vec);
		}
	}

	if (right.size() > 0)
	{
		int i = 1;
		for (auto vec : right)
		{
			if (i < result.size() > 0)
			{
				for (int numb : vec)
					result[i].push_back(numb);
			}
			else
				result.push_back(vec);

			++i;
		}
	}

	return result;
}

void print_BST_Sequence_helper(vector <vector<int>> nodes_level_list, int level, vector<int> prefix)
{
	if (level == nodes_level_list.size()) {
		
		printArray(prefix);
		cout << "\n";
		return;
	}

	auto eachLevel = nodes_level_list[level];
	auto combination = getCombination(eachLevel, 0, eachLevel.size() - 1);

	for (auto eachCombination : combination)
	{
		for (int numb : eachCombination)
			prefix.push_back(numb);

		print_BST_Sequence_helper(nodes_level_list, level + 1, prefix);
		
		for (int i = 0; i < eachCombination.size(); ++i)								// remove old combination, insert new
			prefix.pop_back();
	}
}

void print_BST_Sequence(Node* root)
{
	vector <vector<int>> nodes_level_list = generate_lists_from_tree(root);
	vector<int> prefix;
	print_BST_Sequence_helper(nodes_level_list, 0, prefix);
}

int main()
{
	Node* root = new Node(10);
	root->left = new Node(5);
	root->left->left = new Node(3);

	root->right = new Node(15);
	root->right->left = new Node(13);
	root->right->right = new Node(17);

	print_BST_Sequence(root);

	/*
	Node* root = new Node(3);
	root->left = new Node(5);
	root->left->left = new Node(6);
	root->left->right = new Node(2);
	root->left->right->left = new Node(7);
	root->left->right->right = new Node(4);
	root->left->left->left = new Node(10);

	root->right = new Node(1);
	root->right->left = new Node(0);
	root->right->right = new Node(8);
	root->right->right->right = new Node(11);
	cout << "\nPrinting Tree:\n";
	root->print_tree(root);
	
	auto result = generate_lists_from_tree(root);
	//cout << "\nSize: " << result.size();

	cout << "\n";
	int i = 1;
	for (auto vec : result)
	{
		cout << "Vector: " << i << "\t";
		for (int numb : vec)
			cout << numb << " ";

		cout << "\n";
		++i;
	}
	*/
	cout << endl;
	return 0;
}

