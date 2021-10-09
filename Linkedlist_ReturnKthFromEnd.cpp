/*
Implement an algorithm to find the kth to the last element of a singly linkedlist.
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

	int getKthFromLast(const int k) {

		if (k < 0)
			return -99999999;

		int length = 0;
		Node* itr = head;
		Node* tail = head;

		while (itr->next) {
			++length;

			if (length > k)
				tail = tail->next;

			itr = itr->next;
		}
		return tail->data;
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
	cout << "Kth last element: " << list.getKthFromLast(6);

	cout << "\nDone. Press any key to continue";
	cin.get();
	return 0;
}