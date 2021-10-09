/*

*/


#include<iostream>
#include<stack>

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
private:
	Node* head;

public:
	Linkedlist() {
		head = NULL;
	}

	void insert(char data) {
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

	bool isPalindrome() {
		
		/*
			Push 1st half elements of linked list in to the stack.
			Compare the element of stack with the remaining elements of the second half of ;linkedlist.
			Stack is last in first out, so you will be comparing elements from the mid of linkedlist to outwards...
		*/
		stack<char> holder;
		Node* slow_ptr = head;
		Node* fast_ptr = head;

		// Push first half elements of linkedlist into the the stack 
		while (fast_ptr && fast_ptr->next) {
			holder.push(slow_ptr->data);

			slow_ptr = slow_ptr->next;
			fast_ptr = fast_ptr->next->next;
		}

		if (fast_ptr != NULL)
			slow_ptr = slow_ptr->next;

		// compare the stack with other half	
		while (slow_ptr) {

			if (holder.top() != slow_ptr->data)
				return false;

			holder.pop();
			slow_ptr = slow_ptr->next;
		}
		
		return true;
	}
};

int main() {

	Linkedlist list;
	list.insert('M');
	list.insert('A');
	list.insert('d');
	list.insert('A');
	list.insert('M');

	cout << (list.isPalindrome() ? "Yes\n" : "No\n");


	cout << "Completed. Press any key to exit";
	cin.get();
	return 0;
}