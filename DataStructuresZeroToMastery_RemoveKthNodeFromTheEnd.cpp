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


	void remove_kth_node_from_end(int k)
	{
		Node* start = head;
		Node* end = head;

		while (k > 0)
		{
			end = end->next;
			--k;
		}

		if (end == NULL)					// this means we will be deleting the head node
		{
			head = start->next;
			delete start;

			return;
		}

		while (end->next)
		{
			end = end->next;
			start = start->next;
		}

		if (start->next == tail)			// reset tail pointer		
		{
			tail = start;
			tail->next = NULL;

			delete start->next;
		}
		else
		{
			// start->next points to the list that we have to delete.
			Node* temp = start->next;
			start->next = temp->next;
			delete temp;
		}
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

	list.print();
	list.remove_kth_node_from_end(5);
	list.print();

	cout << endl;
	return 0;
}