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

Node* merge_lists(Node* list1, Node* list2)
{
	if (!list1 && !list2)
		return NULL;

	if (!list1)
		return list2;

	if (!list2)
		return list1;

	Node* head = NULL;
	if (list1->data <= list2->data)
	{
		head = list1;
		list1 = list1->next;
	}
	else
	{
		head = list2;
		list2 = list2->next;
	}

	Node* itr = head;

	while (list1 && list2)
	{
		if (list1->data <= list2->data)
		{
			itr->next = list1;
			list1 = list1->next;
		}
		else
		{
			itr->next = list2;
			list2 = list2->next;
		}
		itr = itr->next;
	}

	while (list1)
	{
		itr->next = list1;

		list1 = list1->next;
		itr = itr->next;
	}

	while (list2)
	{
		itr->next = list2;

		list2 = list2->next;
		itr = itr->next;
	}

	return head;
}

Node* get_mid(Node* list)
{
	Node* start = list;
	Node* end = list->next;								// if length is even, this will return the first mid

	while (end && end->next)
	{
		start = start->next;
		end = end->next->next;
	}
	
	return start;
}

Node* merge_sort(Node* list)
{
	if (list == NULL || list->next == NULL)
		return list;


	Node* mid_node = get_mid(list);

	Node* list2 = mid_node->next;
	mid_node->next = NULL;

	Node* half_1 = merge_sort(list);
	Node* half_2 = merge_sort(list2);

	Node* merged = merge_lists(half_1, half_2);
	return merged;
}

int main()
{
	Linkedlist list;
	list.insert(4);
	list.insert(7);
	list.insert(2);
	list.insert(7);
	list.insert(9);
	list.insert(3);

	list.print();
	Node* sorted_list = merge_sort(list.get_head());

	while (sorted_list)
	{
		cout << sorted_list->data << "  ";
		sorted_list = sorted_list->next;
	}

	cout << endl;
	return 0;
}