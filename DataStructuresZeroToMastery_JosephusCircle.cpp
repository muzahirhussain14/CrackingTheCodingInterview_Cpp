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

class CircularLinkedlist
{
private:
	Node* head;
	Node* tail;


public:
	CircularLinkedlist()
	{
		head = tail = NULL;
	}

	void insert_node(int data)
	{
		if (head == NULL)
		{
			head = new Node(data);
			head->next = head;

			tail = head;
		}
		else
		{
			tail->next = new Node(data);
			tail = tail->next;
			tail->next = head;					// make it circular
		}
	}

	void delete_node(int pos)
	{
		if (pos < 1 || pos > get_length())
			return;

		if (pos == 1)							// if head is the node to delete
		{
			Node* temp = head;
			head = head->next;
			tail->next = head;

			delete temp;
		}

		else
		{
			Node* itr = head;
			while (--pos > 1)					// need to stop one node behind the desired node thus pre decrementing
			{
				itr = itr->next;
			}
		
			if (itr->next == tail)				// if deleting tail
			{
				tail = itr;
				delete itr->next;
				tail->next = head;
			}
			else
			{
				Node* temp = itr->next->next;
				delete itr->next;
				itr->next = temp;
			}
		}
	}

	void print()
	{
		int count = get_length();
		Node* itr = head;

		while (count > 0)
		{
			cout << itr->data << "  ";
			itr = itr->next;
			--count;
		}
		cout << "\n";
	}


	int get_length()
	{
		Node* itr = head->next;
		int count = 1;

		while (itr != head)
		{
			itr = itr->next;
			++count;
		}

		return count;
	}

	Node* get_head()
	{
		return head;
	}
};


/*
	Function to find the only position left after one in every m-th node is killed in a circle of n nodes.
*/

int get_josephus_position(int m, int n)
{
	// create a circular list
	CircularLinkedlist l1;
	for (int i = 1; i <= n; ++i)
	{
		l1.insert_node(i);
	}

	Node* head = l1.get_head();
	int cur_pos = 1;

	while (l1.get_length() > 1)
	{
		int count = 1;

		while (count < m)
		{
			head = head->next;
			count += 1;
			cur_pos = (cur_pos % l1.get_length()) + 1;
		}

		head = head->next;											//move head one up from current node.
		l1.delete_node(cur_pos);
	}

	return l1.get_head()->data;
}

int main()
{
	cout << get_josephus_position(2, 4);


	cout << endl;
	return 0;
}