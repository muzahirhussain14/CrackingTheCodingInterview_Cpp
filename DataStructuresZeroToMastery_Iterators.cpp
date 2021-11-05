#include<iostream>
#include<string>
#include<unordered_map>					// no order is maintained. Complexity is Constant for all operations because it use hashtables to store data.
#include<map>							// stores data in a sorted order. Sorts on the basis of keys. Complexity of O(logn), because it uses balanced BST.

using namespace std;

int main()
{
	// Unordered map example
	cout << "\n\nUN-ORDERED MAPs\n";
	unordered_map<string, int> my_unordered_map;
	my_unordered_map["abc1"] = 1;
	my_unordered_map["xyz"] = 2;
	my_unordered_map["lmx"] = 3;
	my_unordered_map["nyx"] = 4;
	my_unordered_map["xmx"] = 5;

	// Printing with iterators
	for (unordered_map<string, int>::iterator itr = my_unordered_map.begin(); itr != my_unordered_map.end(); ++itr)
	{
		cout << "Key: " << itr->first << ", value: " << itr->second << "\n";
	}

	my_unordered_map.erase("xmx");						// erasing by key
	my_unordered_map.erase(my_unordered_map.begin());	// erasing by iterator

	// finding with iterators
	if (my_unordered_map.find("xxx") == my_unordered_map.end())
		cout << "Key not found\n";
	else
		cout << "Key found\n";
	


	my_unordered_map.erase("xmx");						// erasing by key
	my_unordered_map.erase(my_unordered_map.begin());	// erasing by iterator
	cout << "\nPrinting after erases\n";

	// Printing with iterators
	for (unordered_map<string, int>::iterator itr = my_unordered_map.begin(); itr != my_unordered_map.end(); ++itr)
	{
		cout << "Key: " << itr->first << ", value: " << itr->second << "\n";
	}


	// Ordered map example
	cout << "\n\nORDERED MAPs\n";
	map<string, int> my_map;					// sorts on the basis of keys
	my_map["abc1"] = 1;
	my_map["xyz"] = 2;
	my_map["lmx"] = 3;
	my_map["nyx"] = 4;
	my_map["xmx"] = 5;

	for (map<string, int>::iterator itr = my_map.begin(); itr != my_map.end(); ++itr)
	{
		cout << "Key: " << itr->first << ", value: " << itr->second << "\n";
	}

	map<string, int>::iterator itr = my_map.find("nyx");

	//erasing range
	my_map.erase(itr, my_map.end());

	cout << "\nPrinting after erasing range:\n";

	// Printing after erasing
	for (unordered_map<string, int>::iterator itr = my_unordered_map.begin(); itr != my_unordered_map.end(); ++itr)
	{
		cout << "Key: " << itr->first << ", value: " << itr->second << "\n";
	}


	cout << endl;
	return 0;
}