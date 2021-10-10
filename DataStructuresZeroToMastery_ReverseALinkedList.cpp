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

	void reverse()
	{
		Node* back_node = NULL;
		Node* itr = head;
		
		while (itr)
		{
			Node* temp = itr->next;
			itr->next = back_node;

			back_node = itr;
			itr = temp;
		}

		// swap tail and head pointers.
		itr = tail;
		tail = head;
		head = itr;
	}
};


int main()
{
	Linkedlist list;
	list.insert(1);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(6);

	list.print();
	list.reverse();
	list.print();
	list.reverse();
	list.print();
	list.reverse();
	list.print();
	list.reverse();
	list.print();

	cout << endl;
	return 0;
}