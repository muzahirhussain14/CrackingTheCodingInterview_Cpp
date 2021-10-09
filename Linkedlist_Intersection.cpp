/*
Intersection: Given two (singly) linked lists, determine if the two lists intersect. Return the
intersecting node. Note that the intersection is defined based on reference, not value. That is, if the
kth node of the first linked list is the exact same node (by reference) as the jth node of the second
linked list, then they are intersecting.

Example:
		3->1->5->9-\
					7->2->1
			  4->6-/

In above example the two lists intersacts at node 7. Return node 7	


Solutions:

1) Using HashMaps:
One way is to use hashmaps. Traverse through one list put all ndoes as a key in hashmap.
Now traverse through second list, search each node in hash map, if found, return that node else return NULL.


2) Another way is to traverse both the lists to end, and compare the last nodes of the two lists (Intersecting list will definately have same lase node).
If the lase node is same, we know that the list are intersecting.
Now make the two lists of same length(by iterating the longer list until it is same same length as shorter list), then traverse both the list until you find
intersecting node. Return that node.
*/


#include <iostream>

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
};


int moveToEnd(Node*& itr) {

	if (!itr)
		return 0;

	int count = 0;
	while (itr->next)
	{
		++count;
		itr = itr->next;
	}

	return count;
}

void moveToNth(Node*& itr, int n)
{
	while (n > 0) {
		itr = itr->next;
		n = n - 1;
	}
}

Node* getIntersectingNode(Node* list1, Node* list2){

	while (list1) {
		if (list1 == list2)
			return list1;

		list1 = list1->next;
		list2 = list2->next;
	}
}

Node* intersectionNode(Node* list1, Node* list2) {

	if (!list1 || !list2)
		return NULL;

	Node* itr_list1 = list1;					// move first_list to the end
	int length_list1 = moveToEnd(itr_list1);

	Node* itr_list2 = list2;					// move second_list to the end
	int length_list2 = moveToEnd(itr_list2);

	if (itr_list1 != itr_list2)					// if last nodes of both the lists don't match, return Null (no intersection)
	{
		cout << "No Intersection\n";
		return NULL;
	}

	// Now we know that our lists intersected.
	itr_list1 = list1;
	itr_list2 = list2;

	if (length_list1 > length_list2)			// Move the longer list forward until it is equal to the other list
		moveToNth(itr_list1, (length_list1 - length_list2));
	
	else if(length_list1 < length_list2)
		moveToNth(itr_list2, (length_list2 - length_list1));

	return getIntersectingNode(itr_list1, itr_list2);
}


int main() {

	Linkedlist list1;
	list1.insert(3);
	list1.insert(1);
	list1.insert(5);
	list1.insert(9);

	Node* tmp = list1.head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = new Node(7);

	list1.insert(2);
	list1.insert(1);

	//list1.print();
	
	Linkedlist list2;
	list2.insert(4);
	list2.insert(6);
	Node* tmp2 = list2.head;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp->next;

	//list2.print();


	Node* result = intersectionNode(list1.head, list2.head);
	if (result)
		cout << "\nResult: " << result->data;
	else
		cout << "\nResult: NULL";

	cout << "\nDone. Press any key to continue.";
	cin.get();
	return 0;
}