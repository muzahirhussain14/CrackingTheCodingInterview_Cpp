// Circular dynamic queue with auto increase capacity

#include<iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	int front;
	int back;
	T* queue;
	int capacity;
	int size;


public:
	Queue()
	{
		front = -1;
		back = -1;
		size = 0;
		capacity = 5;					// initial capacity = 5
		queue = new T[capacity];
	}
	
	bool is_empty()
	{
		return size == 0;
	}

	bool is_full()
	{
		if (size == capacity)
			return true;
		else
			return false;
	}

	void enqueue(T data)
	{
		if (size == capacity)			// queue is full;
		{
			T* new_queue = new T[capacity * 2];

			int index = 0;
			for (int i = front + 1; i < capacity; ++i)						// first move elements from 'front' to end
				new_queue[index++] = queue[i];

			for (int i = 0; i <= front; ++i)							// next move element from start to 'front'
				new_queue[index++] = queue[i];

			delete queue;
			queue = new_queue;
			front = -1;											// point 'front' to the start
			back = capacity - 1;								// point 'back' to the end
			capacity = capacity * 2;
		}

		back = (back + 1) % capacity;
		queue[back] = data;
		++size;
	}

	T dequeue()
	{
		if (is_empty())
		{
			cout << "Empty";
			return NULL;
		}

		front = (front + 1) % capacity;
		--size;
		return queue[front];
	}

	T get_front()
	{
		if (is_empty())
		{
			cout << "Empty";
			return NULL;
		}

		return queue[(front + 1) % capacity];
	}

	int get_capacity()
	{
		return capacity;
	}

	int get_size()
	{
		return size;
	}
};

int main()
{
	/*
	// Test1
	Queue<int> myQueue;
	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	myQueue.enqueue(4);
	myQueue.enqueue(5);
	myQueue.enqueue(6);
	myQueue.enqueue(7);

	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << "Current Capacity: " << myQueue.get_capacity() << "\n";
	cout << "Current Size: " << myQueue.get_size() << "\n";
	myQueue.enqueue(1);
	myQueue.enqueue(2);
	myQueue.enqueue(3);
	myQueue.enqueue(4);
	myQueue.enqueue(5);
	myQueue.enqueue(6);
	myQueue.enqueue(7);
	myQueue.enqueue(8);
	myQueue.enqueue(9);
	myQueue.enqueue(10);

	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";	myQueue.dequeue();

	cout << "Current Capacity: " << myQueue.get_capacity() << "\n";
	cout << "Current Size: " << myQueue.get_size() << "\n";
	*/

	
	// Test2
	Queue <int> myQueue;
	myQueue.enqueue(10);
	myQueue.enqueue(20);
	myQueue.enqueue(30);
	myQueue.enqueue(40);
	myQueue.enqueue(50);
	myQueue.enqueue(60);
	myQueue.enqueue(70);
	cout << myQueue.get_front() << "\n";
	myQueue.dequeue();
	myQueue.dequeue();
	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";
	cout << myQueue.get_size() << "\n";
	cout << myQueue.is_empty() << "\n";
	myQueue.enqueue(60);
	myQueue.enqueue(70);
	myQueue.dequeue();
	myQueue.dequeue();
	cout << myQueue.get_front() << "\n";
	cout << myQueue.get_size() << "\n";
	

	cout << endl;
	return 0;
}
