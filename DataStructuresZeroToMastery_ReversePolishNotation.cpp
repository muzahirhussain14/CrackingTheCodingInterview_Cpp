/*
To and from Reverse Polish Notation - aka Postfix notation
*/


#include<iostream>
#include<vector>

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

// In a postfix expression, an operator is written after its operands
vector<string> to_postfix(vector<string> expression)					// assuming a valid input
{
	Stack<string> stack;
	vector<string> postfix_expression;

	for (string ch : expression)
	{
		if (ch == ")")
		{
			if (stack.is_empty())			// invalid return empty vector
			{
				postfix_expression.clear();
				return postfix_expression;
			}

			postfix_expression.push_back(stack.pop());
		}
		else if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
			stack.push(ch);

		else if (ch >= "0" && ch <= "9")
			postfix_expression.push_back(ch);				// push the digits
	}

	if (!stack.is_empty())
		postfix_expression.push_back(stack.pop());			// pop the last operator

	return postfix_expression;
}

float from_postfix(vector<string> postfix_expression)				// assuming a valid input
{
	Stack<float> expression;

	for (string ch : postfix_expression)
	{
		if (ch == "+" || ch == "-" || ch == "*" || ch == "/")			// pop the two elements and do the operation
		{
			float operand1 = expression.pop();
			float operand2 = expression.pop();

			if (ch == "+")	expression.push(operand2 + operand1);
			if (ch == "-")	expression.push(operand2 - operand1);
			if (ch == "*")	expression.push(operand2 * operand1);
			if (ch == "/")	expression.push(operand2 / operand1);
		}
		else
			expression.push(float(atoi(ch.c_str())));						// push the number
	}

	return expression.pop();
}


void print_vector(const vector<string>& vec)
{
	for (string ch : vec)
	{
		cout << ch;
	}
	cout << endl;
}

int main()
{
	cout << "************* TO POSTFIX ***************\n";
	vector<string> input1{ "5", "+", "(", "6", "/", "3", ")"};				// 5 + (6 / 3)
	vector<string> result1 = to_postfix(input1);
	print_vector(result1);

	vector<string> input2{ "(", "6", "+", "3", ")", "/", "5" };				// (6 + 3) / 5	
	vector<string> result2 = to_postfix(input2);
	print_vector(result2);

	vector<string> input3{"(", "(", "2", "+", "3", ")", "-", "3", ")", "+", "11"};		// (( 2 + 3 ) - 3 ) + 11
	vector<string> result3 = to_postfix(input3);
	print_vector(result3);

	vector<string> input4{"(", "(", "10", "+", "2", ")", "-", "3", ")", "/", "6"};			// ((10 + 2) - 3) / 6
	vector<string> result4 = to_postfix(input4);
	print_vector(result4);


	cout << "\n\n************* FROM POSTFIX ***************\n";
	cout << from_postfix(result1);
	cout << "\n" << from_postfix(result2);
	cout << "\n" << from_postfix(result3);
	cout << "\n" << from_postfix(result4);


	cout << endl;
	return 0;
}