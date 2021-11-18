/*
Left_child = 2i + 1;
Right_child = 2i + 2;
parent = (child_index - 1) / 2;
*/

#include<iostream>
#include<vector>

using namespace std;

class PriorityQueue {							// using min_heap
private:
	vector<int> p_queue;

public:
	PriorityQueue(){}

	void insert(int data) {
		p_queue.push_back(data);
		int c_index = p_queue.size() - 1;
		int p_index = (c_index - 1) / 2;

		// heapify
		while (c_index > 0)
		{
			if (p_queue[c_index] < p_queue[p_index])
				swap(p_queue[c_index], p_queue[p_index]);

			else
				break;

			c_index = p_index;
			p_index = (c_index - 1) / 2;
		}
	}

	int removeMin() {

		if (isEmpty() == true)
			return -1;

		int ret = p_queue[0];
		p_queue[0] = p_queue[p_queue.size() - 1];
		p_queue.pop_back();

		if (p_queue.size() == 0)
			return ret;

		// heapify
		int p_index = 0;
		while (true)
		{
			int left = (2 * p_index) + 1;
			int right = (2 * p_index) + 2;

			int min_child = p_index;
			if(left < p_queue.size() && right < p_queue.size())
				min_child = (p_queue[left] < p_queue[right]) ? left : right;
			else
			{
				if (left < p_queue.size())
					min_child = left;

				else if (right < p_queue.size())
					min_child = right;
			}

			if (min_child == p_index)					// if parent is already the minimum element.
				break;

			if (p_queue[min_child] < p_queue[p_index])
				swap(p_queue[min_child], p_queue[p_index]);

			p_index = min_child;
		}

		return ret;
	}

	int getMin() { return p_queue[0]; }
	bool isEmpty() { return p_queue.size() == 0; }
	int getSize() { return p_queue.size(); }
	void print() {
		for (int i : p_queue)
			cout << i << " ";
	}
};

int main()
{
	PriorityQueue tree;

	tree.insert(100);
	tree.insert(10);
	tree.insert(15);
	tree.insert(4);
	tree.insert(17);
	tree.insert(21);
	tree.insert(67);
	tree.insert(0);


	cout << tree.getSize() << "\n";
	cout << tree.getMin() << "\n";


	while (!tree.isEmpty())
	{
		cout << tree.removeMin() << " ";
	}

	cout << "\n" << tree.getSize() << "\n";
	cout << endl;
	return 0;
}