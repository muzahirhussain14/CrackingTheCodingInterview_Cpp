#include <iostream>
using namespace std;

template <typename T>
class Stack
{
private:
	T* stack;
	int next_index;
	int capacity;


public:
	Stack()
	{
		next_index = 0;
		capacity = 2;								// start with capacity 2
		stack = new T[capacity];
	}

	bool is_empty()
	{
		return next_index == 0;
	}

	int size()
	{
		return next_index;
	}

	T top()
	{
		if (!is_empty())
		{
			return stack[next_index - 1];
		}
		else
		{
			return -1;
		}
	}

	void push(T data)
	{
		if (next_index == capacity)					// stack is full, resize
		{
			T* new_stack = new T[capacity * 2];
			for (int i = 0; i < capacity; ++i)
				new_stack[i] = stack[i];			// copy from old stack to the new

			delete[]stack;
			stack = new_stack;
		}

		stack[next_index++] = data;
	}

	T pop()
	{
		if (!is_empty())
		{
			return stack[--next_index];
		}
		else
		{
			return -1;
		}
	}
};

int main()
{

	Stack <int> s1;
	s1.push(100);
	s1.push(101);
	s1.push(102);
	s1.push(103);
	s1.push(104);

	cout << "Integer Stack\n";
	cout << s1.top() << "\n";	s1.pop();
	cout << s1.top() << "\n";	s1.pop();
	cout << s1.top() << "\n";	s1.pop();
	cout << s1.top() << "\n";	s1.pop();
	cout << s1.top() << "\n";	s1.pop();


	Stack <char> s2;
	s2.push('A');
	s2.push('B');

	cout << "\nCharacter Stack\n";
	cout << s2.top() << "\n";	s2.pop();
	cout << s2.top() << "\n";	s2.pop();

	cout << endl;
	return 0;
}