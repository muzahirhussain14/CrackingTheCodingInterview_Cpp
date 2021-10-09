/*
Stack Min: How would you design a stack which, in addition to push and pop, has a function min
which returns the minimum element? Push, pop and min should all operate in 0(1) time.
*/

#include<iostream>
#include<vector>
using namespace std;

class Stack {
private:
	vector<int> stack;
	vector<int> mins;

public:
	Stack() {}

	void push(int element) 
	{
		if (mins.size() == 0)
			mins.push_back(element);

		else if (element < mins[mins.size() - 1])
			mins.push_back(element);

		stack.push_back(element);
	}

	int pop() {
		int value = stack[stack.size() - 1];
		stack.pop_back();

		if (value == min())
			mins.pop_back();

		return value;
	}

	int peek() {
		return stack[stack.size() - 1];
	}

	int size() {
		return stack.size();
	}

	int min() {
		return mins[mins.size() - 1];
	}
};

int main() {

	Stack s;
	s.push(2);
	s.push(15);
	s.push(4);
	s.push(1);

	s.pop();

	cout << "Min: " << s.min() << "\n";


	cout << "Done. Press any key to continue.";
	cin.get();
	return 0;
}