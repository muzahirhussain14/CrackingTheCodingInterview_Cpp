/*
Loop Detection: Given a circular linked list, implement an algorithm that returns the node at the
beginning of the loop.

DEFINITION
Circular linked list: A (corrupt) linked list in which a node's next pointer points to an earlier node, so
as to make a loop in the linked list.

EXAMPLE
	Input: A -> B -> C - > D -> E -> C [the same C as earlier)
	Output: C
*/

#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next = NULL;

	Node(char d) {
		data = d;
		next = NULL;
	}
};

class Linkedlist {
public:
	Node* head;
	Node* tail;

	Linkedlist() {
		head = tail =  NULL;
	}

	void insert(char data) {
		if (!head)
			head = tail = new Node(data);
		else {
			tail->next = new Node(data);
			tail = tail->next;
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

	bool containsLoop(){
	
		Node* slow_ptr = head;
		Node* fast_ptr = head;
		bool loop = false;

		while (fast_ptr && fast_ptr->next) {

			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;
		
			if (fast_ptr == slow_ptr) {
				loop = true;
				break;
			}
		}
		return loop;
	}

	Node* LoopNode() {

		Node* slow_ptr = head;
		Node* fast_ptr = head;
		bool loop = false;

		while (fast_ptr && fast_ptr->next) {

			fast_ptr = fast_ptr->next->next;
			slow_ptr = slow_ptr->next;

			if (fast_ptr == slow_ptr) {
				loop = true;
				break;
			}
		}
		if (!loop)
			return NULL;


		// Now I need to find the size of the loop.
		int size = 1;
		slow_ptr = slow_ptr->next;
		while (slow_ptr != fast_ptr) {
			slow_ptr = slow_ptr->next;
			size += 1;
		}

		slow_ptr = fast_ptr = head;				// Reset both the pointer. Point one pointer to the head and point another pointer 'size' nodes forwards
		while(size > 0){
			fast_ptr = fast_ptr->next;
			--size;
		}

		// Now move both the pointers at equal speed. Where they meet would be the start of the loop.
		while (true) {
			if (fast_ptr == slow_ptr)
				return fast_ptr;
			
			fast_ptr = fast_ptr->next;
			slow_ptr = slow_ptr->next;
		}
	}
};


int main() {

	Linkedlist list;
	list.insert(5);
	list.insert(2);
	list.insert(3);
	list.insert(4);
	list.insert(5);
	list.insert(10);
	list.insert(12);
	list.insert(7);
	list.insert(15);

	list.tail->next = list.head->next->next;					// creating a loop
	
	//cout << (list.containsLoop()?"Yes\n":"No\n");
	//list.print();

	Node* result = list.LoopNode();
	cout << "Loop Node: ";
	if (result)
		cout << result->data;
	else
		cout << "NULL";

	cout << "\nDone. Press any key to continue.";
	cin.get();

	return 0;
}