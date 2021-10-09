/*
Delete Middle Node: Implement an algorithm to delete a node in the middle of a singly linked list, given only access to
that node. 
Note that you have no access to the head/tail nodes, but just the node to delete.
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

	void deleteNode(Node* n) {			// assuming any middle node, won't work for the last node

		// the trick is to copy the data from next node to present node and then just delete the next node.
		if (n == NULL || n->next == NULL)
			return;

		Node* temp = n->next;
		n->data = temp->data;
		n->next = temp->next;

		delete temp;
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
	list.insert(9);

	list.print();

	cout << "\nDone. Press any key to continue";
	cin.get();
	return 0;
}