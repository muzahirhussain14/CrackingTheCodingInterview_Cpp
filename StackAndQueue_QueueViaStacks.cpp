// Queue via Stacks: Implement a MyQueue class which implements a queue using two stacks.

#include <iostream>
#include <vector>

using namespace std;


class Stack 
{
private:
	vector<int> stack;

public:
	
	void push(int element)
	{
		stack.push_back(element);
	}

	int pop()
	{
		int ret = stack[stack.size() - 1];
		stack.pop_back();

		return ret;
	}

	int peek() {
		int ret = stack[stack.size() - 1];
		return ret;
	}

	int size() {
		return stack.size();
	}

	void print()
	{
		for (int i : stack)
			cout << i << " ";
		cout << "\n";
	}
};

class Queue 
{
private:
	Stack newElements;
	Stack oldElements;

	void fill_oldStack() 
	{
		if (oldElements.size() == 0) 
		{
			while (newElements.size() > 0)
				oldElements.push(newElements.pop());
		}
	}

public:
	void enqueue(int n) {
		newElements.push(n);
	}

	int dequeue()
	{
		fill_oldStack();
		return oldElements.pop();
	}

	int peek() {
		return oldElements.peek();
	}
};

int main() {

	Queue my_queue;
	my_queue.enqueue(5);
	my_queue.enqueue(6);
	my_queue.enqueue(7);
	my_queue.enqueue(8);

	cout << my_queue.dequeue() << "\n";
	cout << my_queue.dequeue() << "\n";
	cout << my_queue.dequeue() << "\n";
	cout << my_queue.dequeue() << "\n";


	cout << endl;
	return 0;
}