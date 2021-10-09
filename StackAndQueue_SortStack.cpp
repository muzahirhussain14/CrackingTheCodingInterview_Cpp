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

void sort(Stack& s) 
{
	Stack temp;
	temp.push(s.pop());

	while (s.size() > 0) 
	{
		int value = s.pop();

		while (temp.size() > 0 && value < temp.peek())
			s.push(temp.pop());

		temp.push(value);
	}

	while (temp.size() > 0)
		s.push(temp.pop());
}

int main() {

	Stack s;
	s.push(4);
	s.push(2);
	s.push(7);
	s.push(1);
	s.push(17);

	sort(s);

	cout << "Sorted Array:\n";
	s.print();

	cout << endl;
	return 0;
}