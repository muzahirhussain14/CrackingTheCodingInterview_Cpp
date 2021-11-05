#include<iostream>
#include<string>

using namespace std;

template<typename T>
class MapNode {
public:
	string key;
	T data;
	MapNode* next;

	MapNode(string k, T d)
	{
		key = k;
		data = d;
		next = NULL;
	}

	~MapNode()
	{
		delete next;
	}
};

template <typename T>
class Hashmaps {
private:
	MapNode<T>** bucket;
	int count;
	int numBuckets;

	int generate_map_index(string key)
	{
		int map_index = 0;
		int base = 1;
		int power = 7;						// a prime number is a good value for base.
		for (int i = key.size() - 1; i >= 0; --i)
		{ 
			map_index += (int(key[i]) * base) % numBuckets;
			base = (base * power) % numBuckets;
		}

		return map_index % numBuckets;
	}

	float load_factor()
	{
		return count / (float)numBuckets;
	}

	void rehash()
	{
		MapNode<T>** old_hashtable = bucket;
		int old_bucketsize = numBuckets;
		numBuckets = numBuckets * 2;					// double the size of numBuckets
		count = 0;

		bucket = new MapNode<T>*[numBuckets];			// create new Map with updated size
		for (int i = 0; i < numBuckets; ++i)
			bucket[i] = NULL;		

		// rehash all the old values
		for (int i = 0; i < old_bucketsize; ++i)
		{
			MapNode<T>* head = old_hashtable[i];
			while (head)
			{
				insert(head->key, head->data);
				head = head->next;
			}
		}

		for (int i = 0; i < old_bucketsize; ++i)
			delete old_hashtable[i];

		delete []old_hashtable;
	}

public:
	Hashmaps(int size)
	{
		count = 0;
		numBuckets = size;
		bucket = new MapNode<T>* [numBuckets];

		for (int i = 0; i < numBuckets; ++i)
			bucket[i] = NULL;
	}

	T get(string key)
	{
		int index = generate_map_index(key);
		MapNode<T>* head = bucket[index];

		while (head)
		{
			if (head->key == key)
				return head->data;
			head = head->next;
		}
		return 0;
	}


	void insert(string key, T value)
	{
		int index = generate_map_index(key);

		if (bucket[index] == NULL)
			bucket[index] = new MapNode<T> (key, value);

		else
		{
			MapNode<T>* itr = bucket[index];

			// first search element in the list
			while (itr)
			{
				if (itr->key == key)
				{
					itr->data = value;
					return;
				}
				itr = itr->next;
			}

			// element does not already exist, therefore insert
			itr = new MapNode<T>(key, value);
			itr->next = bucket[index];
			bucket[index] = itr;
		}
		++count;

		// complete load factor check.
		if (load_factor() > 0.7)				// need to increase size and do the rehashing
		{
			rehash();
		}
	}

	T remove(string key)
	{
		int index = generate_map_index(key);
		T return_value = 0;

		if (bucket[index] == NULL)					// nothing to delete - return
			return return_value;

		MapNode<T>* prevous_node = NULL;
		MapNode<T>* head = bucket[index];

		while (head)
		{
			if (head->key == key)				// node to delete
			{
				if (prevous_node == NULL)		// first node to delete
					bucket[index] = head->next;
				else
					prevous_node->next = head->next;

				return_value = head->data;
				head->next = NULL;				// destructor is recursive therefore first need to set next to NULL, otherwise complete list will be deleted
				delete head;
				--count;
				break;
			}

			prevous_node = head;
			head = head->next;
		}

		return return_value;
	}

	int size()
	{
		return count;
	}

	~Hashmaps()
	{
		for (int i = 0; i < numBuckets; ++i)
			delete bucket[i];

		delete[] bucket;
	}
};


int main()
{
	Hashmaps<int> hashmaps(5);

	for (int i = 0; i < 10; ++i)
	{
		string key = to_string(i);
		hashmaps.insert(key, i * 2);
	}
	

	cout << "Total size after insertion: " << hashmaps.size() << "\n";
	for (int i = 0; i < 10; ++i)
	{
		string key = to_string(i);
		cout << "Key: " << key << ", value: " << hashmaps.get(key) << "\n";
	}

	hashmaps.remove("1");
	hashmaps.remove("3");
	hashmaps.remove("4");
	hashmaps.remove("9");

	cout << "\nTotal size after removal: " << hashmaps.size() << "\n";
	
	for (int i = 0; i < 10; ++i)
	{
		string key = to_string(i);
		cout << "Key: " << key << ", value: " << hashmaps.get(key) << "\n";
	}

	cout << endl;
	return 0;
}