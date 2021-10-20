/*
Given a string of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters and removing them.
*/

#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node <T>* next;

	Node(T d)
	{
		data = d;
		next = NULL;
	}
};

template <typename T>
class Stack
{
private:
	Node<T>* head;
	int size;

public:
	Stack()
	{
		size = 0;
		head = NULL;
	}

	int get_size()
	{
		return size;
	}

	bool is_empty()
	{
		return size == 0;
	}

	void push(T data)								// insert new nodes at the start of the list and move head backwards
	{
		Node<T>* new_node = new Node<T>(data);
		new_node->next = head;
		head = new_node;
		++size;
	}

	T pop()
	{
		if (is_empty())
		{
			cout << "Stack empty, returning -1";
			return NULL;
		}

		Node<T>* tmp = head;
		head = head->next;

		T data = tmp->data;
		delete tmp;

		--size;
		return data;
	}

	T top()
	{
		if (is_empty())
		{
			cout << "Stack empty, returning -1";
			return -1;
		}

		return head->data;
	}
};


string remove_adjacent_duplicates_using_stacks(string s)				// complexity -> linear time, linear space
{
	Stack<char> stack;
	Stack<char> result_stack;

	for (int i = 0; i < s.size(); ++i)
	{
		if (!stack.is_empty() && s.at(i) == stack.top())
			stack.pop();

		else
			stack.push(s.at(i));
	}

	while (!stack.is_empty())
	{
		result_stack.push(stack.pop());									// push in another stack
	}

	string final_result;
	while (!result_stack.is_empty())
	{
		final_result.push_back(result_stack.pop());						// now pop again from the new stack to get the elements in correct order
	}

	return final_result;
}

string remove_adjacent_duplicates_inplace_stack(string s1)				// complexity -> linear time, const space
{
	int stack_ptr = -1;
	for (char ch : s1)
	{
		if (stack_ptr != -1 && ch == s1[stack_ptr])						// found adjacent element
			--stack_ptr;
		else
			s1[++stack_ptr] = ch;
	}

	string result;
	for (int i = 0; i <= stack_ptr; ++i)
		result.push_back(s1[i]);

	return result;
}

int main()
{
	cout << "\nremove_adjacent_duplicates_using_stacks\n";
	cout << remove_adjacent_duplicates_using_stacks("abbc") << "\n";
	cout << remove_adjacent_duplicates_using_stacks("abbaca") << "\n";
	cout << remove_adjacent_duplicates_using_stacks("aaabccddd") << "\n";
	cout << remove_adjacent_duplicates_using_stacks("baab") << "\n";

	cout << "\nremove_adjacent_duplicates_inplace_stack\n";
	cout << remove_adjacent_duplicates_inplace_stack("abbc") << "\n";
	cout << remove_adjacent_duplicates_inplace_stack("abbaca") << "\n";
	cout << remove_adjacent_duplicates_inplace_stack("aaabccddd") << "\n";
	cout << remove_adjacent_duplicates_inplace_stack("baab") << "\n";


	cout << endl;
	return 0;
}