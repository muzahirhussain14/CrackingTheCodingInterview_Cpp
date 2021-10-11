#include<iostream>
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

	friend Node* merge_lists(Linkedlist& l1, Linkedlist& l2);
};

Node* merge_lists(Linkedlist& l1, Linkedlist& l2)
{
	Node* n1 = l1.head;
	Node* n2 = l2.head;

	if (!n1 && !n2)
		return NULL;

	if (!n1)
		return n2;

	if (!n2)
		return n1;

	Node* merged_head = NULL;
	
	if (n1->data <= n2->data)
	{
		merged_head = n1;
		n1 = n1->next;
	}
	else
	{
		merged_head = n2;
		n2 = n2->next;
	}

	Node* tail_itr = merged_head;

	while (n1 && n2)
	{
		if (n1->data <= n2->data)
		{
			tail_itr->next = n1;
			n1 = n1->next;
		}
		else
		{
			tail_itr->next = n2;
			n2 = n2->next;
		}
		tail_itr = tail_itr->next;
	}

	while (n1)
	{
		tail_itr->next = n1;
		n1 = n1->next;
		tail_itr = tail_itr->next;
	}

	while (n2)
	{
		tail_itr->next = n2;
		n2 = n2->next;
		tail_itr = tail_itr->next;
	}

	return merged_head;
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


	Node* result = merge_lists(n1, n2);

	while (result)
	{
		cout << result->data << "  ";
		result = result->next;
	}

	cout << endl;
	return 0;
}