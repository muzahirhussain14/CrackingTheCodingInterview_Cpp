/*
STL provides two types of Maps:
	- map	=	This is implemented using Balanced BST. Therefore, all the operations (insert, find, remove) are O(log(n)).
	- unordered_map	= This is implemented using HashTables. All the operations are constant i.e. O(1).
*/

#include<iostream>
#include <unordered_map>
using namespace std;

int main()
{
	unordered_map<string, int> hashmap;

	// insertion methods
	//1 using build-in pairs class and insert method
	pair<string, int> my_pair("aaa", 1);
	hashmap.insert(my_pair);

	//2 using square barackets
	hashmap["bbb"] = 1;

	cout << hashmap.size() << " ";


	// finding methods
	// 1) using at method
	cout << "At: " << hashmap.at("aaa") << "\n";

	// 2) using count method
	cout << "Count: " << hashmap.count("aaa") << "\n";				// returns 1 if aaa is present otherwise returns 0

	// 3) using the find method
	if (hashmap.find("bbb") != hashmap.end())
		cout << "bbb found" << "\n";

	// removing method
	// 1) using erase
	hashmap.erase("aaa");
	cout << "Count after erase: " << hashmap.count("aaa") << "\n";

	cout << "Size: " << hashmap.size() << "\n";
	cout << hashmap["ccc"] << "\n";									// if a key doesnot exist, and we still try to print it, that key will be inserted in to the map with some default value (0 in case of integer).
	cout << "Size: " << hashmap.size() << "\n";
	
	cout << endl;
	return 0;
}