/*
Stack of Plates: Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack exceeds some
threshold. Implement a data structure SetOfStacks that mimics this. SetOfStacks should be
composed of several stacks and should create a new stack once the previous one exceeds capacity.
SetOfStacks. push () and SetOfStacks. pop () should behave identically to a single stack
(that is, pop ( ) should return the same values as it would if there were just a single stack).
Followup:
Implement a function popAt (int index) which performs a pop operation on a specific substack.
*/

#include<iostream>
#include<vector>
using namespace std;


class Stack {
private:
	vector<vector<int>*> stacks;
	const int threshold;
public:
	Stack(int threshold): threshold(threshold) 
	{}

	void push(int element) 
	{
		if (stacks.size() == 0) 
		{
			vector<int>* s = new vector<int>;
			s->push_back(element);

			stacks.push_back(s);
		}
		else 
		{
			int currentStack = stacks.size() - 1;
			if (stacks[currentStack]->size() == threshold)
			{
				vector<int>* s = new vector<int>;
				s->push_back(element);
				stacks.push_back(s);
			}
			else
				stacks[currentStack]->push_back(element);
		}
	}

	int pop() 
	{
		int currentStack = stacks.size() - 1;
		int ret = -12312312;

		if (stacks[currentStack]->size() > 0) {
			ret = stacks[currentStack]->back();
			stacks[currentStack]->pop_back();
		}

		if (stacks[currentStack]->size() == 0) {
			delete stacks[currentStack];
			stacks.pop_back();
		}

		return ret;
	}

	int peek() {
		int currentStack = stacks.size() - 1;
		return stacks[currentStack]->back();
	}

	int size() {
		return (stacks.size() - 1 * threshold) + stacks[stacks.size() - 1]->size();
	}

	int popAt(int index) 
	{
		int s = index / threshold;
		return (*stacks[s])[index % threshold];
	}

	void print() 
	{
		for (int i = stacks.size() - 1; i >= 0; --i) {
			for (int j = stacks[i]->size() - 1; j >= 0; --j)
				cout << (*stacks[i])[j] << "  ";
		}
	}
};

int main() {

	Stack s(3);
	s.push(5);
	s.push(2);
	s.push(1);
	s.push(7);
	s.push(4);
	s.push(3);
	s.push(2);
	
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n";
	cout << s.pop() << "\n\n";

	/*cout << "PopAt(0): " << s.popAt(0) << "\n";
	cout << "PopAt(2): " << s.popAt(2) << "\n";
	cout << "PopAt(3): " << s.popAt(3) << "\n";
	cout << "PopAt(4): " << s.popAt(4) << "\n\n";
	*/

	s.print();


	return 0;
}