/*
Each operation (pop, push, top etc) should have constant O(1) time complexity.
*/

#include<iostream>
using namespace std;

template <typename T>
class Node
{
public:
	T data;
	Node <T> *next;

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
	Node<T> *head;
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
		Node<T> *new_node = new Node<T>(data);
		new_node->next = head;
		head = new_node;
		++size;
	}

	int pop()
	{
		if (is_empty())
		{
			cout << "Stack empty, returning -1";
			return -1;
		}

		Node<T> *tmp = head;
		head = head->next;

		int data = tmp->data;
		delete tmp;

		--size;
		return data;
	}

	int top()
	{
		if (is_empty())
		{
			cout << "Stack empty, returning -1";
			return -1;
		}

		return head->data;
	}
};

int main()
{
	Stack<int> my_stack;

	my_stack.push(12);
	my_stack.push(15);
	my_stack.push(17);
	my_stack.push(11);
	my_stack.push(19);


	cout << my_stack.top() << "\n";
	my_stack.pop();

	cout << my_stack.top() << "\n";
	my_stack.pop();

	cout << my_stack.top() << "\n";
	my_stack.pop();

	cout << my_stack.top() << "\n";
	my_stack.pop();

	cout << my_stack.top() << "\n";
	my_stack.pop();

	cout << my_stack.top() << "\n";
	my_stack.pop();

	cout << endl;
	return 0;
}