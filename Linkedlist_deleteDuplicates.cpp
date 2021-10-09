/*
	Write a code to remove duplicates from an unsorted linkedlist in O(n) time complexity
*/

#include<iostream>
#include<unordered_map>

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
		else{
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

	void delete_duplicates() {									// Must be a O(n) function
		unordered_map<int, int> hashmap;		

		Node* previous = head;
		Node* next = previous->next;

		hashmap[head->data] = 1;								// insert the root value.

		while (next) {

			if (hashmap.find(next->data) != hashmap.end()) {
				previous->next = next->next;
				delete next;
				next = previous->next;
				continue;
			}
			else
				hashmap[next->data] = 1;

			next = next->next;
			previous = previous->next;
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
	list.insert(6);

	list.print();
	list.delete_duplicates();
	list.print();

	cout << "Done. Press any key to continue";
	cin.get();
	return 0;
}