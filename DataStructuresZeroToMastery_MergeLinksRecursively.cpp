#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

	Node(int d)
	{
		data = d;
		next = NULL;
	}
};

class Linkedlist
{
private:
	Node* head;
	Node* tail;


public:
	Linkedlist()
	{
		head = tail = NULL;
	}

	void insert(int data)
	{
		if (head == NULL)
		{
			head = new Node(data);
			tail = head;
		}
		else
		{
			tail->next = new Node(data);
			tail = tail->next;
		}
	}

	void print()
	{
		Node* itr = head;
		while (itr)
		{
			cout << itr->data << "  ";
			itr = itr->next;
		}
		cout << "\n";
	}

	Node* get_head()
	{
		return head;
	}

};

Node* merge_list(Node* l1, Node* l2)
{
	if (l1 == NULL && l2 == NULL)
		return NULL;

	if (l1 == NULL)
		return l2;

	if (l2 == NULL)
		return l1;

	Node* head = NULL;

	if (l1->data <= l2->data)
	{
		head = l1;
		head->next = merge_list(l1->next, l2);
	}
	else
	{
		head = l2;
		head->next = merge_list(l1, l2->next);
	}

	return head;
}

int main()
{
	Linkedlist n1;
	n1.insert(2);
	n1.insert(4);
	n1.insert(6);
	n1.insert(8);

	Linkedlist n2;
	n2.insert(1);
	n2.insert(3);
	n2.insert(5);
	n2.insert(7);
	n2.insert(9);
	n2.insert(10);

	Node* result = merge_list(n1.get_head(), n2.get_head());
	while (result)
	{
		cout << result->data << "  ";
		result = result->next;
	}

	cout << endl;
	return 0;
}