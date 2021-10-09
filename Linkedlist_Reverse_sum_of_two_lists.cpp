/*
Sum List:
You have two numbers represented by a linkedlist, where each node contains single digit. The digits are stored in reverse order. Such that, the 1's digit 
is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Example:
Input: (7-> 1 -> 6) + (5 -> 9 -> 2) .That is,617 + 295.
Output: 2 -> 1 -> 9. That is, 912.


FOLLOW UP
Suppose the digits are stored in forward order. Repeat the above problem.
EXAMPLE
Input: (6 -> 1 -> 7) + (2 -> 9 -> 5).That is,617 + 295.
Output: 9 -> 1 -> 2. That is, 912.

*/


#include<iostream>
#include<math.h>

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
public:
	Node* head;

	Linkedlist() {
		head = NULL;
	}

	void insert_head(int data) {
		if (!head)
			head = new Node(data);
		
		else {
			Node* temp = new Node(data);
			temp->next = head;
			head = temp;
		}
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
};

int calculate_sum(Node* node) {
	int sum = 0;
	int POT = 0;			// power of ten

	Node* itr = node;

	while (itr) {
		sum += itr->data * pow(10, POT);

		++POT;
		itr = itr->next;
	}

	return sum;
}


Node* Sum_List(Node* l1, Node* l2){

	int sum = calculate_sum(l1) + calculate_sum(l2);
	Linkedlist list;

	while (sum > 10) {
		list.insert(sum % 10);
		sum /= 10;
	}
	list.insert(sum);

	return list.head;
}


int calculate_sum_followUp(Node* node) {
	int sum = 0;
	int POT = 0;			// power of ten
	
	Node* itr = node;
	while (itr) {
		POT += 1;
		itr = itr->next;
	}

	itr = node;
	POT -= 1;

	while (itr) {
		sum += itr->data * pow(10, POT);

		--POT;
		itr = itr->next;
	}

	return sum;
}


Node* Sum_List_followUp(Node* l1, Node* l2) {

	int sum = calculate_sum_followUp(l1) + calculate_sum_followUp(l2);
	Linkedlist list;

	cout << "Sum: " << sum << "\n";
	while (sum > 10) {
		list.insert_head(sum % 10);
		sum /= 10;
	}
	list.insert_head(sum);

	return list.head;

}
int main() {

	Linkedlist list;
	list.insert(6);
	list.insert(1);
	list.insert(7);

	Linkedlist list2;
	list2.insert(2);
	list2.insert(9);
	list2.insert(5);

	Linkedlist result;
	result.head = Sum_List_followUp(list.head, list2.head);
	result.print();

	/*
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
	*/
	cout << "Done. Press any key to continue";
	cin.get();
	return 0;
}