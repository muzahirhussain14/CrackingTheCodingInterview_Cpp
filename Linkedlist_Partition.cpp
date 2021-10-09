/*
Write code to partition a linked list around a value x, such that all nodes less than x come
before all nodes greater than or equal to x. lf x is contained within the list, the values of x only need
to be after the elements less than x (see below). The partition element x can appear anywhere in the
"right partition"; it does not need to appear between the left and right partitions.

EXAMPLE
Input: 3 -> 5 -> 8 -> 5 -> 10 -> 2 -> 1 [partition = 5]
Output: 3 -> 1 -> 2 -> 10 -> 5 -> 5 -> 8

*/

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next = NULL;

	Node(int d) {
		data = d;
		next = NULL;
	}
};

class Linkedlist {
private:
	Node* head;

public:
	Linkedlist() {
		head = NULL;
	}

	void insert(int data) {
		if (!head)
			head = new Node(data);
		else {
			Node* itr = head;
			while (itr->next)
				itr = itr->next;

			itr->next = new Node(data);
		}
	}

	void print() {
		Node* itr = head;
		while (itr) {
			cout << itr->data << " ";
			itr = itr->next;
		}
		cout << "\n";
	}

	void partition(int n) {

		if (!head)
			return;

		Node* itr = head;

		while (itr->next)
		{
			if (itr->next->data < n) {
				Node* newNode = new Node(itr->next->data);
				newNode->next = head;
				head = newNode;

				Node* temp = itr->next;
				itr->next = temp->next;
				delete temp;
				continue;
			}

			itr = itr->next;
		}

	}
};


int main() {

	Linkedlist list;
	list.insert(5);
	list.insert(3);
	list.insert(6);
	list.insert(6);
	list.insert(2);
	list.insert(3);
	list.insert(1);

	list.print();

	cout << "After Partition on 5\n";
	list.partition(5);
	list.print();

	cout << "Done. Press any key to continue";
	cin.get();
	return 0;
}